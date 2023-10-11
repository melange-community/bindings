open Discord;

let client = Client.createClient ();

Client.onReady client (fun _ => Js.log "Bot is ready");

let handleMessage msg =>
  switch (Message.author msg |> User.bot) {
  | false =>
    switch (Message.content msg) {
    | "ping" => Message.reply msg "pong"
    | _ => ()
    }
  | true => ()
  };

Client.onMessage client handleMessage;

Client.login client "TOKEN_HERE";