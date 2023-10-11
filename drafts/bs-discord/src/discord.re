module Channel = {
  type t;
  external channelType : t => string = "type" [@@bs.get];
};

module User = {
  type t;
  external bot : t => bool = "bot" [@@bs.get];
};

module Message = {
  type t;
  external content : t => string = "" [@@bs.get];
  external channel : t => Channel.t = "" [@@bs.get];
  external reply : t => string => unit = "" [@@bs.send];
  external author : t => User.t = "" [@@bs.get];
};

module Client = {
  type t;
  external createClient : unit => t = "Client" [@@bs.module "discord.js"] [@@bs.new];
  external login : t => string => unit = "" [@@bs.send];
  external onReady : t => _ [@bs.as "ready"] => (unit => unit) => unit = "on" [@@bs.send];
  external onMessage : t => _ [@bs.as "message"] => (Message.t => unit) => unit = "on" [@@bs.send];
};