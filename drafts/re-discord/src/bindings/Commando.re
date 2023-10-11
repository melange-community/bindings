/* Discord.js Commando Bindings */
type commandoClient = Discord.client;
type commandDispatcher;
type commandoRegistry;
type commandoMessage = Discord.message;
type command;
type responseObj;
type provider;
type settingProvider;
type commandGroup;
type commandResolvable;
type commandoGuild = Discord.guild;
type guildSettingsHelper;
type commandGroupResolvable;
type argument;
type friendlyError;
type permissionCheck =
  | HasPermission(bool)
  | Error(string);

type argValue =
  | Any(string)
  | AnyArray(array(string));

/* Essentially Turns This Into a JS Object */
[@bs.deriving abstract]
type clientOptions = {
  [@bs.optional]
  disableEveryone: bool,
  [@bs.optional]
  commandPrefix: string,
  [@bs.optional]
  commandEditableDuration: int,
  [@bs.optional]
  nonCommandEditable: bool,
  [@bs.optional]
  unknownCommandResponse: bool,
  [@bs.optional]
  owner: array(string),
  [@bs.optional]
  invite: string,
};

[@bs.deriving abstract]
type defaultCommandOptions = {
  [@bs.optional]
  help: bool,
  [@bs.optional]
  prefix: bool,
  [@bs.optional]
  eval: bool,
  [@bs.optional]
  ping: bool,
  [@bs.optional]
  commandState: bool,
};

type throttlingOptions = {
  usages: int,
  duration: int,
};

type argumentType;
[@bs.deriving abstract]
type argumentResult = {
  value: argValue,
  [@bs.optional]
  cancelled: string,
  prompts: array(Discord.message),
  answers: array(Discord.message),
};

[@bs.deriving abstract]
type arugmentCollectorResult = {
  [@bs.optional]
  cancelled: option(string),
  prompts: array(Discord.message),
  answers: array(Discord.message),
};

type argumentDefault;
[@bs.deriving abstract]
type argumentInfo = {
  key: string,
  [@bs.optional]
  label: string,
  prompt: string,
  [@bs.optional]
  error: string,
  [@bs.optional] [@bs.as "type"]
  argtype: string,
  [@bs.optional]
  max: int,
  [@bs.optional]
  min: int,
  [@bs.optional]
  default: argumentDefault,
  [@bs.optional]
  oneOf: array(string),
  [@bs.optional]
  infinite: bool,
  [@bs.optional]
  parse: Js.Types.function_val,
  [@bs.optional]
  validate: Js.Types.function_val,
  [@bs.optional]
  isEmpty: Js.Types.function_val,
  [@bs.optional]
  wait: int,
};

[@bs.deriving abstract]
type typeObj = {
  [@bs.optional]
  string: bool,
  [@bs.optional]
  integer: bool,
  [@bs.optional]
  float: bool,
  [@bs.optional]
  boolean: bool,
  [@bs.optional]
  user: bool,
  [@bs.optional]
  member: bool,
  [@bs.optional]
  role: bool,
  [@bs.optional]
  channel: bool,
  [@bs.optional]
  textChannel: bool,
  [@bs.optional]
  categoryChannel: bool,
  [@bs.optional]
  message: bool,
  [@bs.optional]
  customEmoji: bool,
  [@bs.optional]
  command: bool,
  [@bs.optional]
  group: bool,
};

[@bs.deriving abstract]
type commandInfo = {
  name: string,
  [@bs.optional]
  aliases: array(string),
  [@bs.optional]
  autoAliases: bool,
  group: string,
  memberName: string,
  description: string,
  [@bs.optional]
  format: string,
  [@bs.optional]
  details: string,
  [@bs.optional]
  examples: array(string),
  [@bs.optional]
  guildOnly: bool,
  [@bs.optional]
  ownerOnly: bool,
  [@bs.optional]
  nsfw: bool,
  [@bs.optional]
  throttling: throttlingOptions,
  [@bs.optional]
  defaultHandling: bool,
  [@bs.optional]
  args: array(argumentInfo),
  [@bs.optional]
  argsPromptLimit: int,
  [@bs.optional]
  argsType: string,
  [@bs.optional]
  argsCount: int,
  [@bs.optional]
  argsSingleQuotes: bool,
  [@bs.optional]
  patterns: array(Js.Re.t),
  [@bs.optional]
  guarded: bool,
  [@bs.optional]
  hidden: bool,
};

type splitOptions = {
  maxLength: option(int),
  char: option(string),
  prepend: option(string),
  append: option(string),
};

type messageOptions = {
  .
  "tts": bool,
  "nonce": Js.undefined(string),
  "embed": Js.undefined(Discord.richEmbed),
  "disableEveryone": Js.undefined(bool), /* defaults to this.client.options.disableEveryone */
  "files": array(Discord.fileOptions),
  "code": Js.undefined(string),
  "split":
    Js.undefined({
      .
      "maxLength": Js.undefined(int), /* default: 1950 */
      "char": Js.undefined(string), /* default: "\n" */
      "prepend": Js.undefined(string), /* default: "" */
      "append": Js.undefined(string),
    }), /* default: "" */
  "reply": Js.undefined(Discord.userResolvable),
};

module FriendlyError = {
  type t = friendlyError;
  [@bs.module "discord.js-commando"] [@bs.new]
  external make: string => t = "FriendlyError";
};

module Command = {
  type t = command;
  [@bs.module "discord.js-commando"] [@bs.new]
  external make: (commandoClient, commandInfo) => t = "Command";
  /* [@bs.module "discord.js-commando"] [@bs.val] external usage: (string, string) => string = "Command.usage"; */
  [@bs.get] external aliases: t => array(string) = "aliases";
  [@bs.get] external argsCount: t => int = "argsCount";
  [@bs.get] external argsSingleQuotes: t => bool = "argsSignleQuotes";
  [@bs.get] external argsType: t => string = "argsType";
  [@bs.get] external client: t => commandoClient = "client";
  [@bs.get] external defaultHandling: t => bool = "defaultHandling";
  [@bs.get] external description: t => string = "description";
  [@bs.get] external examples: t => array(string) = "examples";
  [@bs.get] external format: t => string = "format";
  [@bs.get] external group: t => string = "group";
  [@bs.get] external groupID: t => string = "groupID";
  [@bs.get] external guarded: t => bool = "guarded";
  [@bs.get] external guildOnly: t => bool = "guildOnly";
  [@bs.get] external hidden: t => bool = "hidden";
  [@bs.get] external memberName: t => string = "memberName";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external nsfw: t => bool = "nsfw";
  [@bs.get] external ownerOnly: t => bool = "ownerOnly";
  [@bs.get] external patterns: t => array(Js.Re.t) = "patterns";
  [@bs.get] external throttling: t => throttlingOptions = "throttling";
  [@bs.send]
  external hasPermissions: (t, commandoMessage) => permissionCheck =
    "hasPermissions";
  [@bs.send] external isUsable: (t, commandoMessage) => bool = "isUsable";
  [@bs.send] external reload: t => unit = "reload";
  [@bs.set] external run: (t, (commandoMessage, string) => 'a) => unit = "run";
  [@bs.set]
  external runWithObj: (t, (commandoMessage, Js.t({..})) => 'a) => unit =
    "run";
  [@bs.set]
  external hasPermission: (t, commandoMessage => 'a) => unit = "hasPermission";
};

module ArgumentType = {
  type t = argumentType;
  [@bs.get] external client: t => commandoClient = "client";
  [@bs.get] external id: t => string = "id";
  [@bs.send]
  external isEmpty: (t, string, commandoMessage, argument) => bool = "isEmpty";
  [@bs.send]
  external parse:
    (t, string, commandoMessage, argument) => Js.Promise.t(argValue) =
    "parse";
  [@bs.send]
  external validate: (t, string, commandoMessage, argument) => argValue =
    "validate";
};

module CommandoMessage = {
  type m = commandoMessage;
  [@bs.get] external argString: m => option(string) = "argString";
  [@bs.get] external command: m => option(command) = "command";
  [@bs.get] external isCommand: m => bool = "isCommand";
  [@bs.get]
  external patternMatches: m => option(array(string)) = "patternMatches";
  [@bs.get]
  external responsePositions: m => Js.Dict.t(responseObj) =
    "responsePositions";
  [@bs.send] external anyUsage: (m, string) => string = "anyUsage";
  [@bs.send]
  external code:
    (m, string, Discord.stringResolvable) =>
    Js.Promise.t(array(Discord.message)) =
    "code";
  [@bs.send]
  external direct:
    (m, Discord.stringResolvable) => Js.Promise.t(array(Discord.message)) =
    "direct";
  [@bs.send]
  external directWithOptions:
    (m, Discord.stringResolvable, messageOptions) =>
    Js.Promise.t(array(Discord.message)) =
    "direct";
  [@bs.send]
  external embed:
    (m, Discord.richEmbed) => Js.Promise.t(array(Discord.message)) =
    "embed";
  [@bs.send]
  external embedWithContent:
    (m, Discord.richEmbed, Discord.stringResolvable) =>
    Js.Promise.t(array(Discord.message)) =
    "embed";
  [@bs.send] external run: m => Js.Promise.t(array(Discord.message)) = "run";
  [@bs.send]
  external say:
    (m, Discord.stringResolvable) => Js.Promise.t(array(Discord.message)) =
    "say";
  [@bs.send]
  external sayWithOptions:
    (m, Discord.stringResolvable, Discord.messageOptions) =>
    Js.Promise.t(array(Discord.message)) =
    "say";
  [@bs.send] external usage: (m, string) => string = "usage";
  [@bs.send] external usageWithPrefix: (m, string, string) => string = "usage";
  [@bs.send] external parseArgs: (m, string) => array(string) = "parseArgs";
  [@bs.send]
  external parseArgsWithCount: (m, string, int) => array(string) =
    "parseArgs";
  external ofCommandoMessage: m => Discord.message = "%identity";
  include Discord.Message;
  let directWithOptions =
      (
        ~tts=false,
        ~nonce=?,
        ~embed=?,
        ~disableEveryone=?,
        ~files=[||],
        ~code=?,
        ~split=?,
        ~reply=?,
        content,
        m,
      ) =>
    directWithOptions(
      m,
      content,
      {
        "tts": tts,
        "nonce": nonce |> Js.Undefined.fromOption,
        "embed": embed |> Js.Undefined.fromOption,
        "disableEveryone": disableEveryone |> Js.Undefined.fromOption,
        "files": files,
        "code": code |> Js.Undefined.fromOption,
        "split":
          split
          |> Belt.Option.map(_, splitOptions =>
               {
                 "maxLength": splitOptions.maxLength |> Js.Undefined.fromOption,
                 "char": splitOptions.char |> Js.Undefined.fromOption,
                 "prepend": splitOptions.prepend |> Js.Undefined.fromOption,
                 "append": splitOptions.append |> Js.Undefined.fromOption,
               }
             )
          |> Js.Undefined.fromOption,
        "reply": reply |> Js.Undefined.fromOption,
      },
    )
    |> Utils.promiseMap(Utils.magicAsArray);
};

module CommandoClient = {
  type c = commandoClient;
  [@bs.module "discord.js-commando"] [@bs.new]
  external makeCommando: unit => commandoClient = "CommandoClient";
  [@bs.module "discord.js-commando"] [@bs.new]
  external makeWithOptions: clientOptions => commandoClient = "CommandoClient";
  [@bs.get] external registry: c => commandoRegistry = "registry";
  [@bs.get] external commandPrefix: c => string = "commandPrefix";
  [@bs.get] external dispatcher: c => commandDispatcher = "dispatcher";
  [@bs.get] external owners: c => option(array(Discord.user)) = "owners";
  [@bs.send] external isOwner: (c, Discord.userResolvable) => bool = "isOwner";
  [@bs.send]
  external setProvider: (c, provider) => Js.Promise.t(Js.Undefined.t(string)) =
    "setProvider";
  [@bs.send]
  external onCommandRun:
    (
      c,
      [@bs.as "commandRun"] _,
      (command, Js.Promise.t(string), commandoMessage) => unit
    ) =>
    unit =
    "on";
  [@bs.send]
  external onCommandRegister:
    (c, [@bs.as "commandRegister"] _, (command, commandoRegistry) => unit) =>
    unit =
    "on";
  external ofCommandoClient: c => Discord.client = "%identity";
  include Discord.Client;
};

module CommandoGuild = {
  type g = commandoGuild;
  [@bs.get] external commandPrefix: g => string = "commandPrefix";
  [@bs.get] external settings: g => guildSettingsHelper = "settings";
  [@bs.send]
  external isCommandEnabled: (g, commandResolvable) => bool =
    "isCommandEnabled";
  [@bs.send]
  external isGroupEnabled: (g, commandGroupResolvable) => bool =
    "isGroupEnabled";
  [@bs.send]
  external setCommandEnabled: (g, command, bool) => Js.undefined(string) =
    "setCommandEnabled";
  [@bs.send]
  external setGroupEnabled:
    (g, commandGroupResolvable, bool) => Js.undefined(string) =
    "setGroupEnabled";
  [@bs.send] external commandUsage: (g, string) => string = "commandUsage";
  [@bs.send]
  external commandUsageWithUser: (g, string, Discord.user) => string =
    "commandUsage";

  include Discord.Guild;
};

module GuildSettingsHelper = {
  type t = guildSettingsHelper;
  [@bs.get] external client: t => commandoClient = "client";
  [@bs.get] external guild: t => option(commandoGuild) = "guild";
  [@bs.send]
  external clear: t => Js.Promise.t(Js.undefined(string)) = "clear";
  [@bs.send] external get: (t, string) => argValue = "get";
  [@bs.send]
  external remove: (t, string) => Js.Promise.t(argValue) = "remove";
  [@bs.send]
  external set: (t, string, string) => Js.Promise.t(argValue) = "set";
};

module CommandDispatcher = {
  type t = commandDispatcher;
  [@bs.module "discord.js-commando"] [@bs.new]
  external make: (commandoClient, commandoRegistry) => commandDispatcher =
    "CommandDispatcher";
  [@bs.get] external client: t => commandoClient = "client";
  [@bs.get] external inhibitors: t => array('a => 'v) = "inhibitors";
  [@bs.get] external registry: t => commandoRegistry = "registry";
  [@bs.send] external addInhibitor: (t, 'a => 'v) => bool = "addInhibitor";
  [@bs.send]
  external removeInhibitor: (t, 'a => 'v) => bool = "removeInhibitor";
};

module SettingProvider = {
  type t = settingProvider;
  [@bs.send] external getGuildID: t => string = "getGuildID";
};

module CommandoRegistry = {
  type t = commandoRegistry;
  [@bs.module "discord.js-commando"] [@bs.new]
  external make: commandoClient => t = "CommandoRegistry";
  [@bs.get] external client: t => commandoClient = "client";
  [@bs.get]
  external commands: t => Discord.collection(string, command) = "commands";
  [@bs.get] external commandsPath: t => option(string) = "commandsPath";
  [@bs.get] external evalObjects: t => unit = "evalObjects";
  [@bs.get]
  external groups: t => Discord.collection(string, commandGroup) = "groups";
  [@bs.get]
  external argTypes: t => Discord.collection(string, argumentType) = "types";
  [@bs.send] external registerCommand: (t, command) => t = "registerCommand";
  [@bs.send]
  external registerCommands: (t, array(command)) => t = "registerCommands";
  [@bs.send]
  external registerDefaultCommands: (t, defaultCommandOptions) => t =
    "registerDefaultCommands";
  [@bs.send]
  external registerCommandsIn: (t, string) => t = "registerCommandsIn";
  [@bs.send] external registerDefaultGroups: t => t = "registerDefaultGroups";
  [@bs.send] external registerDefaults: t => t = "registerDefaults";
  [@bs.send]
  external registerDefaultTypes: (t, typeObj) => t = "registerDefaultTypes";
  [@bs.send]
  external registerEvalObject: (t, string) => t = "registerEvalObject";
  [@bs.send]
  external registerGroup: (t, string, string) => t = "registerGroup";
  [@bs.send]
  external registerGroups: (t, array(array(string))) => t = "registerGroups";
  [@bs.send] external registerType: (t, argumentType) => t = "registerType";
  [@bs.send] external registerTypesIn: (t, string) => t = "registerTypesIn";
};

module CommandResolvable = {
  type t = commandResolvable;
  external ofCommand: command => t = "%identity";
  external ofString: string => t = "%identity";
};

module CommandGroupResolvable = {
  type t = commandGroupResolvable;
  external ofCommandGroup: commandGroup => t = "%identity";
  external ofString: string => t = "%identity";
};

let createInterCommand = (~command, ~run, ~hasPermission=?, client) => {
  let interCommand = client->command;
  switch (hasPermission) {
  | Some(permission) =>
    interCommand->Command.hasPermission(permission) |> ignore
  | None => ()
  };
  interCommand->Command.run(run);
  interCommand;
};

let createInterCommandObj = (~command, ~run, ~hasPermission=?, client) => {
  let interCommand = client->command;
  switch (hasPermission) {
  | Some(permission) =>
    interCommand->Command.hasPermission(permission) |> ignore
  | None => ()
  };
  interCommand->Command.runWithObj(run);
  interCommand;
};

let createFinalCommand = (client, command) => {
  client->command;
};

let addCommands = (client, commands) => {
  commands |> List.map(createFinalCommand(client)) |> Array.of_list;
};

let commandoClientUserFromMsg = msg => {
  msg
  ->CommandoMessage.command
  ->Belt.Option.getExn
  ->Command.client
  ->CommandoClient.user
  ->Belt.Option.getExn;
};