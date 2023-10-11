// Describe your socket params type
type example = {username: string};

let socket =
  Socket.make(
    "/socket",
    Some(Socket.options(~transport=`longpoll, ~params={username: "test"}, ())),
  );

let _ = Socket.onOpen(socket, () => {Js.log("Socket connection open.")});

let _ = Socket.onClose(socket, () => {Js.log("Socket was closed.")});

let _ = Socket.connect(socket);

let channel = socket -> Channel.make("test", Js.Obj.empty());

let _ =
  channel
  ->Channel.join(~timeout=1000, ())
  ->Push.receive(~status="ok", ~callback=params => {Js.log(params)})
  ->Push.receive(~status="error", ~callback=params => {Js.log(params)});

let _ = channel->Channel.push(~event="test", ~payload=Js.Obj.empty(), ());

/**
Create a module with a type t
This should describe your presence payload, as it is in your server
Plus a phx_ref that is sent by default by Phoenix

i.e., if you have this in your server;
Presence.track(socket, socket.assigns.user.id, %{
  id: socket.assigns.user.id, => integer
  name: socket.assigns.user.name => string
})

You use the following module:
*/
module PresenceObject = {
  type t = {
    phx_ref: string,
    id: int,
    name: string,
  };
};

// Create a Presence module that expects to receive your record as its payload
module PresenceMod = Presence.MakeModule(PresenceObject);

let presence = PresenceMod.make(channel, None);

open PresenceMod;

presence->onJoin((~id, ~currentPresence, ~newPresence) => {
  Js.log(id);
  switch (unwrap(currentPresence), unwrap(newPresence)) {
  | (None, None) => Js.log("No presences!")
  | (None, Some({id: userId, phx_ref: _})) =>
    Js.log({j|New user: $userId|j})
  | (Some({id: userId, phx_ref}), Some(_)) =>
    Js.log({j| User $userId logged from a new device: $phx_ref"|j})
  | _ => Js.log("Something ins very, very wrong around here.")
  };
});
