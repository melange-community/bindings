/* Abstract Types */
type t;
type attachment;
type channel;
type categoryChannel;
type client;
type clientUser;
type clientUserChannelOverride;
type clientUserGuildSettings;
type clientUserSettings;
type collection('k, 'v);
type snowflake;
type collector;
type dmChannel;
type emoji;
type evaluatedPermissions;
type game;
type groupdmChannel;
type guild;
type guildChannel;
type guildMember;
type buffer;
type invite;
type message;
[@bs.deriving abstract]
type messageAttachment = {
  client: string,
  filename: string,
  filesize: int,
  [@bs.optional]
  height: int,
  id: snowflake,
  message,
  proxyURL: string,
  url: string,
  [@bs.optional]
  width: int,
};
type messageEmbed;
type messageEmbedAuthor;
type messageEmbedField;
type messageEmbedFooter;
type messageEmbedImage;
type messageEmbedProvider;
type messageEmbedThumbnail;
type messageEmbedVideo;
type messageMention;
type messageReaction;
type oAuth2Application;
type permissions;
type permissionOverwrites;
type presence;
type reactionEmoji;
type richPresenceAssets;
type richEmbed;
type role;
type shard;
type shardClientUtil;
type shardingManager;
type streamDispatcher;
type textBasedChannel;
type textChannel;
type user;
type userConnection;
type userProfile;
type util;
type voiceBroadcast;
type voiceChannel;
type voiceConnection;
type voiceReciever;
type voiceRegion;
type volumeInterface;
type webhook;
type webhookClient;
type messageNotificationType;
/* Type Defs */
type author;
type channelResolvable;
type guildResolvable;
type permissionResolvable;
type channelData = {
  name: option(string),
  position: option(int),
  nsfw: option(bool),
  bitrate: option(int),
  userLimit: option(int),
};
type base64Resolvable;
type bufferResolvable;
type guildMemberResolvable;
type snowflakeOrRole =
  | Snowflake
  | Role;
type emojiEditData = {
  name: option(string),
  roles: collection(snowflake, role),
};

[@bs.deriving abstract]
type fileOptions = {
  attachment: bufferResolvable,
  [@bs.optional]
  name: string,
};

type channelType =
  | DMChannel
  | GroupDMChannel
  | TextChannel
  | VoiceChannel
  | CategoryChannel
  | NoChannel;

type presenceStatus =
  | Online
  | Idle
  | Invisible
  | DND;

type roleResolvable;
type status;
type streamOptions;
type stringResolvable;
type userResolvable;
type colorResolvable;
type voiceStatus;
type webhookMessageOptions;
type websocketOptions;
type wsEventType;
type httpOptions = {
  version: int,
  api: string,
  cdn: string,
  invite: string,
};
[@bs.deriving abstract]
type roleData = {
  [@bs.optional]
  name: string,
  [@bs.optional]
  color: colorResolvable,
  [@bs.optional]
  hoist: bool,
  [@bs.optional]
  position: int,
  [@bs.optional]
  permissions: int,
  [@bs.optional]
  mentionable: bool,
};
type splitOptions = {
  maxLength: option(int),
  char: option(string),
  prepend: option(string),
  append: option(string),
};

type clientOptions = {
  apiRequestMethod: option(string),
  shardId: option(int),
  shardCount: option(int),
  messageCacheMaxSize: option(int),
  messageCacheLifetime: option(int),
  messageSweepInterval: option(int),
  fetchAllMembers: option(bool),
  disableEveryone: option(bool),
  sync: option(bool),
  restWsBridgeTimeout: option(int),
  restTimeOffset: option(int),
  disabledEvents: array(wsEventType),
  ws: option(websocketOptions),
  http: option(httpOptions),
};

type messageOptions = {
  .
  "tts": bool,
  "nonce": Js.undefined(string),
  "embed": Js.undefined(richEmbed),
  "disableEveryone": Js.undefined(bool), /* defaults to this.client.options.disableEveryone */
  "files": array(fileOptions),
  "code": Js.undefined(string),
  "split":
    Js.undefined({
      .
      "maxLength": Js.undefined(int), /* default: 1950 */
      "char": Js.undefined(string), /* default: "\n" */
      "prepend": Js.undefined(string), /* default: "" */
      "append": Js.undefined(string),
    }), /* default: "" */
  "reply": Js.undefined(userResolvable),
};

type gameData = {
  name: option(string),
  url: option(string),
  gameType: option(string),
};

type presenceData = {
  .
  "status": option(string),
  "afk": option(bool),
  "game":
    option({
      .
      "name": option(string),
      "url": option(string),
      "type": option(string),
    }),
};

type memberOptions = {
  .
  "accessToken": string,
  "nick": Js.Undefined.t(string),
  /* collection | array(snowflake) | array(role) */
  "roles": Js.Undefined.t(collection(snowflake, role)),
  "mute": Js.Undefined.t(bool),
  "deaf": Js.Undefined.t(bool),
};

type banOptions = {
  .
  "days": int,
  "reason": Js.Undefined.t(string),
};

type permissionOverwriteOptions = {
  .
  "SEND_MESSAGES": bool,
  "CREATE_INSTANT_INVITE": bool,
  "KICK_MEMBERS": bool,
  "BAN_MEMBERS": bool,
  "EMBED_LINKS": Js.Null.t(string),
  "ATTACH_FILES": bool,
  "VIEW_CHANNEL": bool,
  "CHANGE_NICKNAME": bool,
  "MANAGE_ROLES": bool,
  "MANAGE_NICKNAME": bool,
  "MANAGE_WEBHOOKS": bool,
  "MANAGE_EMOJIS": bool,
};
[@bs.deriving abstract]
type queryOptions = {
  [@bs.optional]
  limit: int,
  [@bs.optional]
  before: snowflake,
  [@bs.optional]
  after: snowflake,
  [@bs.optional]
  around: snowflake,
};

[@bs.deriving abstract]
type permissionOptions = {
  [@bs.optional]
  checkAdmin: bool,
  [@bs.optional]
  checkOwner: bool,
};
/* Clarity Types */
type position = int;
type reason = string;
type relative = bool;
type name = string;
type content = string;
type topic = string;
type urlString = string;
type userOrRole =
  | User(string)
  | Role(string)
  | Snowflake(string);
type memberOrRole =
  | Role(string)
  | Member(guildMemberResolvable);
/* Utility Functions */
[@bs.module "discord.js"]
external escapeMarkdown: (string, bool, bool) => bool = "escapeMarkdown";
[@bs.module "discord.js"]
external splitMessage: string => string = "splitMessage";
[@bs.module "discord.js"]
external splitMessagei: (string, splitOptions) => array(string) =
  "splitMessage";

module UserResolvable = (U: {type t;}) => {
  external userResolvable: U.t => userResolvable = "%identity";
};

module ClientUserResolvable = {
  external ofClientUserToUser: clientUser => user = "%identity";
  external ofUserToClientUser: user => clientUser = "%identity";
  external ofUserToUserResolvable: user => userResolvable = "%identity";
  include UserResolvable({
    type nonrec t = clientUser;
  });
};

module RoleResolvable = (R: {type t;}) => {
  external roleResolvable: R.t => roleResolvable = "%identity";
};

module BufferResolvable = {
  type t = bufferResolvable;
  external ofString: string => t = "%identity";
  external ofBuffer: Node.buffer => t = "%identity";
};

module PermissionResolvable = {
  type t = permissionResolvable;
  external ofString: string => t = "%identity";
  external ofArray: array(t) => t = "%identity";
  external ofNumber: int => t = "%identity";
  external ofPermission: permissions => t = "%identity";
};

module GuildMemberResolvable = {
  type t = guildMemberResolvable;
  external ofUser: user => t = "%identity";
  external ofUserTo: user => guildMember = "%identity";
  external ofGuildMember: guildMember => t = "%identity";
  external ofGuildMemberTo: guildMember => guildMember = "%identity";
};

module ColorResolvable = {
  type t = colorResolvable;
  external ofString: string => t = "%identity";
  external ofFloat: float => t = "%identity";
  external ofInt: int => t = "%identity";
  external rgb: array(int) => t = "%identity";
  let rgb = (r, g, b) => [|r, g, b|] |> rgb;
};

module StringResolvable = {
  type t = stringResolvable;
  external ofString: string => t = "%identity";
  external ofArray: array(string) => t = "%identity";
  external ofStringToRole: string => role = "%identity";
  external ofAny: 'a => t = "%identity";
};

module ChannelResolvable = {
  type t = channelResolvable;
  external ofSnowflake: snowflake => t = "%identity";
  external ofGuild: guild => t = "%identity";
  external ofMessage: message => t = "%identity";
  external ofChannel: channel => t = "%identity";
  external ofGuildChannel: guildChannel => t = "%identity";
  external ofGuildChannelToTextChannel: guildChannel => textChannel =
    "%identity";
  external ofGuildChannelToTextBasedChannel: guildChannel => textBasedChannel =
    "%identity";

  external ofTextBasedToTextChannel: textBasedChannel => textChannel =
    "%identity";
};

module GuildResolvable = {
  type t = guildResolvable;
  external ofGuild: guild => t = "%identity";
  external ofSnowflake: snowflake => t = "%identity";
  external ofSnowflakeTo: snowflake => guild = "%identity";
};

module Collection = {
  type t('k, 'v) = collection('k, 'v);
  [@bs.get] external size: t('k, 'v) => int = "size";
  [@bs.send] external clear: t('k, 'v) => unit = "clear";
  [@bs.send.pipe: t('k, 'v)] external delete: 'k => bool = "delete";
  [@bs.send.pipe: t('k, 'v)]
  external deleteAll: t('k, 'v) => Js.Promise.t(array('a)) = "deleteAll";
  [@bs.send.pipe: t('k, 'v)]
  external forEach: ('v => unit) => unit = "forEach";
  [@bs.send.pipe: t('k, 'v)]
  external forEachi: ((. 'v, 'k) => unit) => unit = "forEach";
  [@bs.send] external equals: (t('k, 'v), t('k, 'v)) => bool = "equals";
  [@bs.send] external array: t('k, 'v) => array('v) = "array";
  [@bs.send] external clone: t('k, 'v) => t('k, 'v) = "clone";
  [@bs.send]
  external concat: (t('k, 'v), t('k, 'v)) => t('k, 'v) = "concat";
  [@bs.send.pipe: t('k, 'v)] external every: ('v => bool) => bool = "every";
  [@bs.send.pipe: t('k, 'v)]
  external everyi: ((. 'v, 'k) => bool) => bool = "every";
  [@bs.send] external keyArray: t('k, 'v) => array('k) = "keyArray";
  [@bs.send.pipe: t('k, 'v)]
  external reduce: ((. 'a, 'v) => 'a, 'a) => 'a = "reduce";
  [@bs.send.pipe: t('k, 'v)]
  external reducei: ((. 'a, 'v, 'k) => 'a, 'a) => 'a = "reduce";
  [@bs.send.pipe: t('k, 'v)] external map: ('v => 'a) => array('a) = "map";
  [@bs.send.pipe: t('k, 'v)] external find: (string, string) => 'a = "find";
  [@bs.send.pipe: t('k, 'v)]
  external findFn: ('v => bool) => option('a) = "find";
  [@bs.send]
  external values: t('k, 'v) => Js.Array.array_like('v) = "values";
};

module Client = {
  type t = client;
  type interval;
  type timeout;
  [@bs.module "discord.js"] [@bs.new] external make: unit => t = "Client";
  [@bs.get] external broadcasts: t => array(voiceBroadcast) = "broadcasts";
  [@bs.get] external browser: t => bool = "browser";
  [@bs.get]
  external channels: t => collection(snowflake, channel) = "channels";
  [@bs.get] external emojis: t => collection(snowflake, emoji) = "emojis";
  [@bs.get] external guilds: t => collection(snowflake, guild) = "guilds";
  [@bs.get] external options: t => clientOptions = "options";
  [@bs.get] external ping: t => float = "ping";
  [@bs.get] external pings: t => array(float) = "pings";
  [@bs.get]
  external presences: t => collection(snowflake, presence) = "presences";
  [@bs.get] [@bs.return nullable]
  external readyAt: t => option(Js.Date.t) = "readyAt";
  [@bs.get] [@bs.return nullable]
  external readyTimestamp: t => option(int) = "readyTimestamp";
  [@bs.get] [@bs.return nullable]
  external shard: t => option(shardClientUtil) = "shard";
  [@bs.get] [@bs.return nullable]
  external status: t => option(int) = "status";
  [@bs.get] [@bs.return nullable]
  external token: t => option(string) = "token";
  [@bs.get] [@bs.return nullable]
  external uptime: t => option(int) = "uptime";
  [@bs.get] [@bs.return nullable]
  external user: t => option(clientUser) = "user";
  [@bs.get] external userNonOption: t => clientUser = "user";
  [@bs.get] external users: t => collection(snowflake, user) = "users";
  [@bs.get]
  external voiceConnections: t => collection(snowflake, voiceConnection) =
    "voiceConnections";
  [@bs.send]
  external setTimeout: (t, unit => unit, int) => timeout = "setTimeout";
  [@bs.send]
  external setInterval: (t, unit => unit, int) => interval = "setInterval";
  [@bs.send] external clearInterval: (t, interval) => unit = "clearInterval";
  [@bs.send] external clearTimeout: (t, timeout) => unit = "clearTimeout";
  [@bs.send]
  external createVoiceBroadcast: t => voiceBroadcast = "createVoiceBroadcast";
  [@bs.send] external destroy: t => Js.Promise.t('a) = "destroy";
  [@bs.send.pipe: t]
  external fetchApplication: snowflake => Js.Promise.t(oAuth2Application) =
    "fetchApplication";
  [@bs.send]
  external fetchMyApplication: t => Js.Promise.t(oAuth2Application) =
    "fetchMyApplication";
  [@bs.send.pipe: t]
  external fetchInvite: string => Js.Promise.t(invite) = "fetchInvite";
  [@bs.send.pipe: t]
  external fetchUser: snowflake => Js.Promise.t(user) = "fetchUser";
  /* This is only available when using a bot account. */
  [@bs.send.pipe: t]
  external fetchUserUncached:
    (snowflake, [@bs.as {json|false|json}] _) => Js.Promise.t(user) =
    "fetchUser";
  [@bs.send]
  external fetchVoiceRegions:
    t => Js.Promise.t(collection(string, voiceRegion)) =
    "fetchVoiceRegions";
  [@bs.send.pipe: t]
  external fetchWebhook: snowflake => Js.Promise.t(webhook) = "fetchWebhook";
  [@bs.send.pipe: t]
  external fetchWebhookWithToken: (snowflake, string) => Js.Promise.t(webhook) =
    "fetchWebhook";
  /* May need to edit this to take a permission instead */
  [@bs.send.pipe: t]
  external generateInvite: permissions => Js.Promise.t(string) =
    "generateInvite";
  [@bs.send.pipe: t] external login: string => Js.Promise.t(string) = "login";
  [@bs.send] external sweepMessages: t => int = "sweepMessages";
  [@bs.send.pipe: t]
  external sweepMessagesOlderThan: int => int = "sweepMessagesOlderThan";
  [@bs.send.pipe: t]
  external syncGuilds: collection(snowflake, guild) => unit = "syncGuilds";

  /* Events */
  [@bs.send.pipe: t]
  external onChannelCreate:
    ([@bs.as "channelCreate"] _, channel => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onChannelDelete:
    ([@bs.as "channelDelete"] _, channel => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onChannnelUpdate:
    ([@bs.as "channelUpdate"] _, channel => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onChannelPinsUpdate:
    ([@bs.as "channelPinsUpdate"] _, channel => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onClientUserSettingsUpdate:
    ([@bs.as "clientUserSettingsUpdate"] _, channel => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onDebug: ([@bs.as "debug"] _, string => unit) => unit = "on";
  /* NOTE: onDisconnect callback actually takes CloseEvent, not unit */
  [@bs.send.pipe: t]
  external onDisconnect: ([@bs.as "disconnect"] _, unit => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onEmojiCreate: ([@bs.as "emojiCreate"] _, emoji => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onEmojiDelete: ([@bs.as "emojiDelete"] _, emoji => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onEmojiUpdate:
    ([@bs.as "emojiUpdate"] _, (emoji, emoji) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onError: ([@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
  [@bs.send.pipe: t]
  external onGuildBanAdd:
    ([@bs.as "guildBanAdd"] _, (guild, user) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildBanRemove:
    ([@bs.as "guildBanRemove"] _, (guild, user) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildCreate: ([@bs.as "guildCreate"] _, guild => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildDelete: ([@bs.as "guildDelete"] _, guild => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildMemberAdd:
    ([@bs.as "guildMemberAdd"] _, guildMember => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildMemberAvailable:
    ([@bs.as "guildMemberAvailable"] _, guildMember => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildMemberRemove:
    ([@bs.as "guildMemberRemove"] _, guildMember => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildMembersChunk:
    ([@bs.as "guildMembersChunk"] _, (array(guildMember), guild) => unit) =>
    unit =
    "on";
  [@bs.send.pipe: t]
  external onGuildMemberSpeaking:
    ([@bs.as "guildMemberSpeaking"] _, (guildMember, bool) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onMessage: ([@bs.as "message"] _, message => unit) => unit = "on";
  [@bs.send.pipe: t]
  external onMessageDelete:
    ([@bs.as "messageDelete"] _, message => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onMessageDeleteBulk:
    (
      [@bs.as "messageDeleteBulk"] _,
      collection(snowflake, message) => unit
    ) =>
    unit =
    "on";
  [@bs.send.pipe: t]
  external onMessageReactionAdd:
    ([@bs.as "messageReactionAdd"] _, (messageReaction, user) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onMessageReactionRemove:
    ([@bs.as "messageReactionRemove"] _, (messageReaction, user) => unit) =>
    unit =
    "on";
  [@bs.send.pipe: t]
  external onMessageReactionRemoveAll:
    ([@bs.as "messageReactionRemoveAll"] _, messageReaction => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onMessageUpdate:
    ([@bs.as "messageUpdate"] _, (message, message) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onPresenceUpdate:
    ([@bs.as "presenceUpdate"] _, (guildMember, guildMember) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onReady: ([@bs.as "ready"] _, unit => unit) => unit = "on";
  [@bs.send.pipe: t]
  external onReconnecting: ([@bs.as "reconnecting"] _, unit => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onResume: ([@bs.as "resume"] _, int => unit) => unit = "on";
  [@bs.send.pipe: t]
  external onRoleCreate: ([@bs.as "roleCreate"] _, role => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onRoleDelete: ([@bs.as "roleDelete"] _, role => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onRoleUpdate:
    ([@bs.as "roleUpdate"] _, (role, role) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onTypingStart:
    ([@bs.as "typingStart"] _, (channel, user) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onTypingStop:
    ([@bs.as "typingStop"] _, (channel, user) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onUserNoteUpdate:
    ([@bs.as "userNoteUpdate"] _, (user, string, string) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onUserUpdate:
    ([@bs.as "userUpdate"] _, (user, user) => unit) => unit =
    "on";
  [@bs.send.pipe: t]
  external onVoiceStatusUpdate:
    ([@bs.as "voiceStatusUpdate"] _, (guildMember, guildMember) => unit) =>
    unit =
    "on";
  [@bs.send.pipe: t]
  external onWarn: ([@bs.as "warn"] _, string => unit) => unit = "on";
};

module Guild = {
  type t = guild;
  [@bs.get] [@bs.return nullable]
  external afkChannel: t => option(voiceChannel) = "afkChannel";
  [@bs.get] [@bs.return nullable]
  external afkChannelId: t => option(string) = "afkChannelId";
  [@bs.get] [@bs.return nullable]
  external afkTimeout: t => option(float) = "afkTimeout";
  [@bs.get] [@bs.return nullable]
  external applicationID: t => option(snowflake) = "applicationID";
  [@bs.get] external available: t => bool = "available";
  [@bs.get]
  external channels: t => collection(snowflake, guildChannel) = "channels";
  [@bs.get] external client: t => client = "client";
  [@bs.get] external createdAt: t => Js.Date.t = "createdAt";
  [@bs.get] external createdTimestamp: t => float = "createdTimestamp";
  [@bs.get] external defaultChannel: t => textChannel = "defaultChannel";
  [@bs.get] external defaultRole: t => role = "defaultRole";
  [@bs.get] external embedEnabled: t => bool = "embedEnabled";
  [@bs.get] external emojis: t => collection(snowflake, emoji) = "emojis";
  [@bs.get] external explicitContentFilter: t => int = "explicitContentFilter";
  /* features: Array<Object> */
  [@bs.get] [@bs.return nullable] external icon: t => option(string) = "icon";
  [@bs.get] [@bs.return nullable]
  external iconURL: t => option(string) = "iconURL";
  [@bs.get] external id: t => snowflake = "id";
  [@bs.get] external joinedAt: t => Js.Date.t = "joinedAt";
  [@bs.get] external joinedTimestamp: t => float = "joinedTimestamp";
  [@bs.get] external large: t => bool = "large";
  [@bs.get] [@bs.return nullable]
  external me: t => option(guildMember) = "me";
  [@bs.get] external memberCount: t => int = "memberCount";
  [@bs.get]
  external members: t => collection(snowflake, guildMember) = "members";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external nameAcronym: t => string = "nameAcronym";
  [@bs.get] external owner: t => guildMember = "owner";
  [@bs.get] external ownerID: t => snowflake = "ownerID";
  [@bs.get]
  external presences: t => collection(snowflake, presence) = "presences";
  [@bs.get] external region: t => string = "region";
  [@bs.get] external roles: t => collection(snowflake, role) = "roles";
  [@bs.get] [@bs.return nullable]
  external splash: t => option(string) = "splash";
  [@bs.get] [@bs.return nullable]
  external splashURL: t => option(string) = "splashURL";
  [@bs.get] [@bs.return nullable]
  external systemChannel: t => option(guildChannel) = "systemChannel";
  [@bs.get] [@bs.return nullable]
  external systemChannelID: t => option(snowflake) = "systemChannelID";
  [@bs.get] external verificationLevel: t => int = "verificationLevel";
  [@bs.get] [@bs.return nullable]
  external voiceConnection: t => option(voiceConnection) = "voiceConnection";
  [@bs.send] external acknowledge: t => Js.Promise.t(guild) = "acknowledge";
  [@bs.send.pipe: t]
  external addMember:
    (userResolvable, memberOptions) => Js.Promise.t(guildMember) =
    "addMember";
  [@bs.send.pipe: t]
  external allowDMs: bool => Js.Promise.t(guild) = "allowDMS";
  [@bs.send.pipe: t]
  external ban: (userResolvable, banOptions) => Js.Promise.t(guildMember) =
    "ban";
  [@bs.send.pipe: t]
  external createRole: roleData => Js.Promise.t(role) = "createRole";
  [@bs.send.pipe: t]
  external unban:
    (userResolvable, ~reason: string=?, unit) => Js.Promise.t(guildMember) =
    "unban";
  [@bs.send.pipe: t]
  external createChannel: (name, channelType) => Js.Promise.t(guildChannel) =
    "createChannel";
  [@bs.send.pipe: t]
  external member: userResolvable => option(guildMember) = "member";
  include UserResolvable({
    type nonrec t = t;
  });
};

module Role = {
  type t = role;
  [@bs.get] external name: t => string = "name";
  [@bs.get] external guild: t => guild = "guild";
  [@bs.get] external client: t => client = "client";
  [@bs.get] external color: t => int = "color";
  [@bs.get] external deleted: t => bool = "deleted";
  [@bs.get] external editable: t => bool = "editable";
  [@bs.get] external hexColor: t => string = "hexColor";
  [@bs.get] external hoist: t => bool = "hoist";
  [@bs.get] external id: t => snowflake = "id";
  [@bs.get]
  external members: t => collection(snowflake, guildMember) = "members";
  [@bs.get] external managed: t => bool = "managed";
  [@bs.get] external mentionable: t => bool = "mentionable";
  [@bs.get] external position: t => int = "position";
  [@bs.get] external permissions: t => int = "permissions";
  [@bs.send.pipe: t] external delete: reason => Js.Promise.t(t) = "delete";
  [@bs.send.pipe: t] external edit: roleData => Js.Promise.t(t) = "edit";
  [@bs.send.pipe: t]
  external editWithReason: (roleData, reason) => Js.Promise.t(t) =
    "editWithReason";
  [@bs.send.pipe: t]
  external setColor: colorResolvable => Js.Promise.t(t) = "setColor";
  [@bs.send.pipe: t]
  external setColorWithReason: (colorResolvable, reason) => Js.Promise.t(t) =
    "setColor";
};

module Channel = {
  type t = channel;
  type classifiedChannel =
    | DM(dmChannel)
    | Group(groupdmChannel)
    | Text(textChannel)
    | Voice(voiceChannel);
  module Impl = (C: {type t;}) => {
    [@bs.get] external client: C.t => client = "client";
    [@bs.get] external createdAt: C.t => Js.Date.t = "createdAtj";
    [@bs.get] external createdTimestamp: C.t => int = "createdTimestamp";
    [@bs.get] external deleted: C.t => bool = "deleted";
    [@bs.get] external id: C.t => snowflake = "id";
    /* dm | group | text | voice | category */
    [@bs.get] external channelType: C.t => string = "type";
    [@bs.send] external delete: C.t => Js.Promise.t(C.t) = "delete";
  };
  let getChannelType = string =>
    switch (string) {
    | "dm" => DMChannel
    | "group" => GroupDMChannel
    | "text" => TextChannel
    | "voice" => VoiceChannel
    | "category" => CategoryChannel
    | _ => NoChannel
    };
};

module GuildChannel = {
  type t = channel;
  module Impl = (C: {type t;}) => {
    [@bs.get] external calculatedPosition: C.t => int = "calculatedPosition";
    [@bs.get] external manageable: C.t => bool = "manageable";
    [@bs.get] [@bs.return nullable]
    external messageNotifications: C.t => option(messageNotificationType) =
      "messageNotifications";
    [@bs.get] [@bs.return nullable]
    external muted: C.t => option(bool) = "muted";
    [@bs.get] external name: C.t => string = "name";
    [@bs.get] [@bs.return nullable]
    external parent: C.t => option(categoryChannel) = "parent";
    [@bs.get] [@bs.return nullable]
    external parentID: C.t => option(snowflake) = "parentID";
    [@bs.get]
    external permissionOverwrites:
      C.t => collection(snowflake, permissionOverwrites) =
      "permissionOverwrites";
    [@bs.get] external position: C.t => int = "position";
    [@bs.send.pipe: C.t]
    external edit: channelData => Js.Promise.t(guildChannel) = "edit";
    [@bs.send.pipe: C.t]
    external editi: (channelData, string) => Js.Promise.t(guildChannel) =
      "edit";
    [@bs.send]
    external equals: (guildChannel, guildChannel) => bool = "equals";
    [@bs.send]
    external fetchInvites: C.t => Js.Promise.t(collection(string, invite)) =
      "fetchInvites";
    [@bs.send]
    external lockPermissions: C.t => Js.Promise.t(guildChannel) =
      "lockPermission";
    [@bs.send.pipe: guildMemberResolvable] [@bs.return nullable]
    external memberPermissions: C.t => option(permissions) =
      "memberPermissions";
    [@bs.send.pipe: C.t]
    external overwritePermissions:
      (userOrRole, permissionOverwriteOptions) => Js.Promise.t(guildChannel) =
      "overwritePermissions";
    [@bs.send.pipe: C.t]
    external overwritePermissionsi:
      (userOrRole, permissionOverwriteOptions, reason) =>
      Js.Promise.t(guildChannel) =
      "overwritePermissions";
    [@bs.send.pipe: C.t]
    external setName: name => Js.Promise.t(guildChannel) = "setName";
    [@bs.send.pipe: C.t]
    external setNamei: (name, reason) => Js.Promise.t(guildChannel) =
      "setName";
    /* Takes snowflake or categoryChannel */
    [@bs.send.pipe: C.t]
    external setParent: snowflake => Js.Promise.t(guildChannel) = "setParent";
    [@bs.send.pipe: C.t]
    external setParenti: (snowflake, reason) => Js.Promise.t(guildChannel) =
      "setParent";
    [@bs.send.pipe: C.t]
    external setPosition: (position, reason) => Js.Promise.t(guildChannel) =
      "setPosition";
    [@bs.send.pipe: C.t]
    external setPositioni: (position, relative) => Js.Promise.t(guildChannel) =
      "setPosition";
    [@bs.send.pipe: C.t]
    external setTopic: topic => Js.Promise.t(guildChannel) = "setTopic";
    [@bs.send.pipe: C.t]
    external setTopici: (topic, reason) => Js.Promise.t(guildChannel) =
      "setTopic";
    [@bs.send] external toString: C.t => string = "toString";
    include Channel.Impl({
      type nonrec t = C.t;
    });
  };
};

module TextBasedChannel = (C: {type t;}) => {
  [@bs.get] [@bs.return nullable]
  external lastMessageID: C.t => option(snowflake) = "lastMessageID";
  [@bs.get] [@bs.return nullable]
  external lastMessage: C.t => option(message) = "lastMessage";
  /* Could be message | array(message) */
  /* Move typing & typing count to other modules */
  [@bs.get] external typing: C.t => bool = "typing";
  [@bs.get] external typingCount: C.t => int = "typingCount";
  [@bs.send.pipe: C.t]
  external fetchMessages: snowflake => Js.Promise.t(message) = "fetchMessage";
  [@bs.send.pipe: C.t]
  external fetchMessagesWithOptions:
    queryOptions => Js.Promise.t(collection(snowflake, message)) =
    "fetchMessages";
  [@bs.send]
  external fetchPinnedMessages:
    C.t => Js.Promise.t(collection(snowflake, message)) =
    "fetchPinnedMessage";
  [@bs.send.pipe: C.t]
  external send: (content, messageOptions) => Js.Promise.t(message) = "send";
  let send =
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
        t,
      ) =>
    send(
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
      t,
    )
    |> Utils.promiseMap(Utils.magicAsArray);
};

module DMChannel = {
  type t = dmChannel;
  include Channel.Impl({
    type nonrec t = t;
  });
  include TextBasedChannel({
    type nonrec t = textBasedChannel;
  });
};

module GroupDMChannel = {
  type t = groupdmChannel;
  include Channel.Impl({
    type nonrec t = t;
  });
  include TextBasedChannel({
    type nonrec t = textBasedChannel;
  });
};

module VoiceChannel = {
  type t = voiceChannel;
  [@bs.get] external bitrate: t => int = "bitrate";
  [@bs.get] external speakable: t => bool = "speakable";
  [@bs.get] external userLimit: t => int = "userLimit";
  [@bs.get] external full: t => bool = "full";
  [@bs.get] external guild: t => guild = "guild";
  [@bs.get] external joinable: t => bool = "joinable";
  [@bs.send] external join: t => Js.Promise.t(voiceConnection) = "join";
  [@bs.send] external leave: t => unit = "leave";
  include GuildChannel.Impl({
    type nonrec t = t;
  });
};

module TextChannel = {
  type t = textChannel;
  [@bs.get] external topic: t => option(string) = "topic";
  include GuildChannel.Impl({
    type nonrec t = t;
  });
  include TextBasedChannel({
    type nonrec t = textBasedChannel;
  });
};

module CategoryChannel = {
  type t = categoryChannel;
  include GuildChannel.Impl({
    type nonrec t = t;
  });
};

module User = {
  type t = user;
  module Impl = (U: {type t;}) => {
    [@bs.get] external avatar: t => string = "avatar";
    [@bs.get] external avatarURL: t => string = "avatarURL";
    [@bs.get] external bot: t => bool = "bot";
    [@bs.get] external client: t => client = "client";
    [@Bs.get] external discriminator: t => string = "discriminator";
    [@bs.get] external createdAt: U.t => Js.Date.t = "createdAt";
    [@bs.get] external createdAtTimestamp: U.t => int = "createdAtTimestamp";
    [@bs.get] external deleted: U.t => bool = "deleted";
    [@bs.get] external id: U.t => snowflake = "id";
    [@bs.get] external note: U.t => string = "note";
    [@bs.get] external presence: U.t => presence = "presence";
    [@bs.get] external tag: U.t => string = "tag";
    [@bs.get] external username: U.t => string = "username";
    [@bs.send] external createDM: U.t => Js.Promise.t(dmChannel) = "createDM";
    [@bs.send] external deleteDM: U.t => Js.Promise.t(dmChannel) = "deleteDM";
  };

  include Impl({
    type nonrec t = t;
  });

  include TextBasedChannel({
    type nonrec t = t;
  });

  include UserResolvable({
    type nonrec t = t;
  });
};

module UserConnection = {
  type t = userConnection;
  [@bs.get] external id: t => string = "id";
  [@bs.get] external integrations: t => array('a) = "integrations";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external revoke: t => bool = "revoke";
  [@bs.get] external connectionType: t => string = "type";
  [@bs.get] external user: t => user = "user";
};

module UserProfile = {
  type t = userProfile;
  [@bs.get] external client: t => client = "client";
  [@bs.get]
  external connections: t => collection(snowflake, userConnection) =
    "connections";
  [@bs.get]
  external mutualGuilds: t => collection(snowflake, guild) = "mutualGuilds";
  [@bs.get] external premium: t => bool = "premium";
  [@bs.get] [@bs.return nullable]
  external premiumSince: t => option(bool) = "premiumSince";
  [@bs.get] external user: t => user = "user";
};

module ClientUser = {
  type t = clientUser;
  [@bs.send.pipe: t]
  external setPresence: presenceData => Js.Promise.t(t) = "setPresence";
  [@bs.send.pipe: t]
  external setUsername: string => Js.Promise.t(t) = "setUsername";
  [@bs.send.pipe: t]
  external setAvatar: bufferResolvable => Js.Promise.t(t) = "setAvatar";
  let setPresence = (~status=?, ~afk=?, ~game=?, t) =>
    setPresence(
      {
        "afk": afk,
        "status": status,
        "game":
          game
          |> Belt.Option.map(_, gameOptions =>
               {
                 "name": gameOptions.name,
                 "type": gameOptions.gameType,
                 "url": gameOptions.url,
               }
             ),
      },
      t,
    );
  [@bs.send.pipe: t]
  external setStatus: string => Js.Promise.t(t) = "setStatus";
  include User.Impl({
    type nonrec t = t;
  });
};

module Snowflake = {
  type t = snowflake;
  external ofString: string => t = "%identity";
  external toString: t => string = "%identity";
  include UserResolvable({
    type nonrec t = t;
  });
};

module GuildMember = {
  type t = guildMember;
  [@bs.get] external displayColor: t => int = "displayColor";
  [@bs.get] external displayHexColor: t => string = "displayHexColor";
  [@bs.get] external guild: t => guild = "guild";
  [@bs.get] external displayName: t => string = "displayName";
  [@bs.get] external highestRole: t => role = "highestRole";
  [@bs.get] external hoistRole: t => option(role) = "hoistRole";
  [@bs.get] external roles: t => collection(snowflake, role) = "roles";
  [@bs.get] external mute: t => bool = "mute";
  [@bs.get] external presence: t => presence = "presence";
  [@bs.get] external user: t => user = "user";
  [@bs.get] external speaking: t => bool = "speaking";
  [@bs.get] external selfMute: t => bool = "selfMute";
  [@bs.get] external serverMute: t => bool = "serverMute";
  [@bs.get] external voiceChannel: t => option(voiceChannel) = "voiceChannel";
  [@bs.get]
  external voiceChannelID: t => option(snowflake) = "voiceChannelID";
  [@bs.get]
  external voiceSessionID: t => option(snowflake) = "voiceSessionID";
  [@bs.send.pipe: t]
  external setVoiceChannel: channelResolvable => Js.Promise.t(guildMember) =
    "setVoiceChannel";
  [@bs.send.pipe: t]
  external addRole: roleResolvable => Js.Promise.t(t) = "addRole";
  [@bs.send.pipe: t]
  external addRoleWithReason: (roleResolvable, reason) => Js.Promise.t(t) =
    "addRole";
  [@bs.send.pipe: t]
  external addRoles: array(roleResolvable) => Js.Promise.t(t) = "addRoles";
  [@bs.send.pipe: t]
  external removeRole: roleResolvable => Js.Promise.t(t) = "removeRole";
  [@bs.send.pipe: t]
  external removeRoles: array(roleResolvable) => Js.Promise.t(t) =
    "removeRoles";
  [@bs.send.pipe: t]
  external setNickname: string => Js.Promise.t(t) = "setNickname";
  [@bs.send.pipe: t] external setMute: bool => Js.Promise.t(t) = "setMute";
  [@bs.send.pipe: t]
  external setMuteWithReason: (bool, reason) => Js.Promise.t(t) = "setMute";
  [@bs.send.pipe: t]
  external setNicknameWithReason: (string, reason) => Js.Promise.t(t) =
    "setNickname";
  [@bs.send.pipe: t]
  external hasPermission: permissionResolvable => bool = "hasPermission";
  [@bs.send.pipe: t]
  external hasPermissionWithOptions:
    (permissionResolvable, permissionOptions) => bool =
    "hasPermission";
  [@bs.send.pipe: t] external kick: unit => Js.Promise.t(t) = "kick";
  [@bs.send.pipe: t] external ban: unit => Js.Promise.t(t) = "ban";
  [@bs.send.pipe: t]
  external banWithOptions: banOptions => Js.Promise.t(t) = "ban";
  [@bs.send.pipe: t]
  external kickWithReason: reason => Js.Promise.t(t) = "kick";

  include TextBasedChannel({
    type nonrec t = textBasedChannel;
  });
};

module Message = {
  type t = message;
  [@bs.get]
  external attachments: t => collection(snowflake, messageAttachment) =
    "attachments";
  [@bs.get] external author: t => user = "author";
  /* channel: TextChannel | DMChannel | GroupDMChannel, */
  [@bs.get] external channel: t => textBasedChannel = "channel";
  [@bs.get] external cleanContent: t => string = "cleanContent";
  [@bs.get] external client: t => client = "client";
  [@bs.get] external content: t => string = "content";
  [@bs.get] external createdAt: t => Js.Date.t = "createdAt";
  [@bs.get] external createdTimestamp: t => int = "createdTimestamp";
  [@bs.get] external deletable: t => bool = "deletable";
  [@bs.get] external editable: t => bool = "editable";
  [@bs.get] [@bs.return nullable]
  external editedAt: t => option(Js.Date.t) = "editedAt";
  [@bs.get] [@bs.return nullable]
  external editedTimestamp: t => option(int) = "editedTimestamp";
  [@bs.get] external edits: t => array(t) = "edits";
  [@bs.get] external embeds: t => array(messageEmbed) = "embeds";
  [@bs.get] [@bs.return nullable]
  external guild: t => option(guild) = "guild";
  [@bs.get] [@bs.return nullable] external hit: t => option(bool) = "hit";
  [@bs.get] external id: t => snowflake = "id";
  [@bs.get] [@bs.return nullable]
  external member: t => option(guildMember) = "member";
  [@bs.get] external mentions: t => messageMention = "mentions";
  [@bs.get] external nonce: t => string = "nonce";
  [@bs.get] external pinnable: t => bool = "pinnable";
  [@bs.get] external pinned: t => bool = "pinned";
  [@bs.get]
  external reactions: t => collection(snowflake, messageReaction) =
    "reactions";
  [@bs.get] external system: t => bool = "system";
  [@bs.get] external tts: t => bool = "tts";
  [@bs.get] external messageType: t => string = "messageType";
  [@bs.get] [@bs.return nullable]
  external webhookID: t => option(snowflake) = "webhookID";
  /* This is only available when using a user account. */
  [@bs.send] external acknowledge: t => Js.Promise.t(t) = "acknowledge";
  /* awaitReactions(
       filter: CollectorFilter,
       options?: AwaitReactionsOptions,
     ): Promise<Collection<Snowflake, MessageReaction>>, */
  [@bs.send] external clearReactions: t => Js.Promise.t(t) = "clearReactions";
  /* createReactionCollector(
       filter: CollectorFilter,
       options?: ReactionCollectorOptions,
     ): ReactionCollector, */
  /* delete(timeout?: number): Promise<Message>, */
  [@bs.send] external delete: t => Js.Promise.t(t) = "delete";
  [@bs.send.pipe: t]
  external deleteWithTimeout: float => Js.Promise.t(t) = "delete";
  /* edit(
       content: StringResolvable,
       options?: MessageEditOptions,
     ): Promise<Message>, */
  [@bs.send] external equals: (t, t, 'a) => bool = "equals";
  [@bs.send]
  external fetchWebhook: t => Js.Promise.t(Js.nullable(webhook)) =
    "fetchWebhook";
  /* isMemberMentioned(member: GuildMember | User): boolean, */
  [@bs.send.pipe: t]
  external isMemberMentioned: user => Js.Promise.t(t) = "isMemberMentioned";
  [@bs.send.pipe: t]
  external isGuildMemberMentioned: guildMember => Js.Promise.t(t) =
    "isMemberMentioned";
  /* isMentioned(data: GuildChannel | User | Role | Snowflake): boolean, */
  [@bs.send.pipe: t]
  external isGuildChannelMentioned: guildChannel => Js.Promise.t(t) =
    "isMentioned";
  [@bs.send.pipe: t]
  external isUserMentioned: user => Js.Promise.t(t) = "isMentioned";
  [@bs.send.pipe: t]
  external isRoleMentioned: role => Js.Promise.t(t) = "isMentioned";
  [@bs.send.pipe: t]
  external isMentioned: snowflake => Js.Promise.t(bool) = "isMentioned";
  [@bs.send] external pin: t => Js.Promise.t(t) = "pin";
  [@bs.send.pipe: t]
  external react: emoji => Js.Promise.t(messageReaction) = "react";
  [@bs.send.pipe: t]
  external reactWithString: string => Js.Promise.t(messageReaction) = "react";
  [@bs.send.pipe: t]
  external reactWithReactionEmoji:
    reactionEmoji => Js.Promise.t(messageReaction) =
    "react";
  [@bs.send] external unpin: t => Js.Promise.t(t) = "unpin";
  /* note: this return type is a lie, it could be message | array(message) */
  [@bs.send.pipe: t]
  external reply: (string, messageOptions) => Js.Promise.t(message) = "reply";
  let reply =
      (
        ~tts=false,
        ~nonce=?,
        ~embed=?,
        ~disableEveryone=?,
        ~files=[||],
        ~code=?,
        ~split=?,
        ~content,
        t,
      ) =>
    reply(
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
        "reply": Js.Undefined.empty,
      },
      t,
    )
    |> Utils.promiseMap(Utils.magicAsArray);
  include UserResolvable({
    type nonrec t = t;
  });
};

module Game = {
  type t = game;
  type party = {
    id: option(string),
    size: array(int),
  };
  type timestamps = {
    start: option(Js.Date.t),
    _end: option(Js.Date.t),
  };
  [@bs.get] external applicationId: t => option(snowflake) = "applicationId";
  [@bs.get] external assets: t => option(richPresenceAssets) = "assets";
  [@bs.get] external details: t => option(string) = "details";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external party: t => party = "party";
  [@bs.get] external state: t => option(string) = "state";
  [@bs.get] external streaming: t => bool = "streaming";
  [@bs.get] external timestamps: t => timestamps = "timestamps";
  [@bs.get] external gameType: t => int = "type";
  [@bs.get] external url: t => option(string) = "url";
  [@bs.send] external equals: (game, game) => bool = "equals";
  [@bs.send] external toString: t => string = "toString";
};

module Invite = {
  type t = invite;
  [@bs.get] external channel: t => guildChannel = "channel";
  [@bs.get] external client: t => client = "client";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external createdAt: t => Js.Date.t = "createdAt";
  [@bs.get] external createdTimestamp: t => int = "createdTimestamp";
  [@bs.get] external expiresAt: t => Js.Date.t = "expiresAt";
  [@bs.get] external expiresTimestamp: t => int = "expiresTimestamp";
  [@bs.get] external guild: t => guild = "guild";
  [@bs.get] [@bs.return nullable]
  external inviter: t => option(user) = "inviter";
  [@bs.get] [@bs.return nullable]
  external maxAge: t => option(int) = "maxAge";
  [@bs.get] external maxUses: t => int = "maxUses";
  [@bs.get] external memberCount: t => int = "memberCount";
  [@bs.get] external presenceCount: t => int = "presenceCount";
  [@bs.get] external temporary: t => bool = "temporary";
  [@bs.get] external textChannelCount: t => int = "textChannelCount";
  [@bs.get] external url: t => string = "url";
  [@bs.get] external uses: t => int = "uses";
  [@bs.get] external voiceChannelCount: t => int = "voiceChannelCountj";
  [@bs.send] external delete: t => Js.Promise.t(invite) = "delete";
  [@bs.send.pipe: t]
  external deletei: reason => Js.Promise.t(invite) = "delete";
  [@bs.send] external toString: t => string = "toString";
};

module Presence = {
  type t = presence;
  [@bs.get] external game: t => Js.Nullable.t(game) = "game";
  [@bs.get] external status: t => string = "status";
  [@bs.send.pipe: t] external equals: presence => bool = "equals";
};

module Attachment = {
  type t = attachment;
  type q = messageAttachment;
  [@bs.module "discord.js"] [@bs.new]
  external make: (bufferResolvable, string) => t = "Attachment";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external attachment: t => q = "attachment";
};

module MessageEmbed = {
  type t = messageEmbed;
};

module RichEmbed = {
  type t = richEmbed;
  [@bs.module "discord.js"] [@bs.new] external make: unit => t = "RichEmbed";
  [@bs.get] external author: t => author = "author";
  [@bs.get] external description: t => string = "description";
  [@bs.get] external fields: t => array('a) = "fields";
  [@bs.get] external file: t => string = "file";
  [@bs.get] external image: t => 'a = "image";
  [@bs.get] external thumbnail: t => 'a = "thumbnail";
  [@bs.get] external timestamp: t => Js.Date.t = "timestamp";
  [@bs.get] external url: t => string = "url";
  [@bs.get] external title: t => string = "title";
  [@bs.get] external footer: t => string = "footer";
  [@bs.get] external files: t => array(string) = "files";
  [@bs.get] external color: t => int = "color";
  [@bs.send.pipe: t]
  external addField: (stringResolvable, stringResolvable) => t = "addField";
  [@bs.send.pipe: t]
  external addFieldInline:
    (stringResolvable, stringResolvable, [@bs.as {json|true|json}] _) => t =
    "addField";
  [@bs.send.pipe: t] external addBlankField: t => t = "addBlankField";
  [@bs.send.pipe: t] external attachFile: string => t = "attachFile";
  [@bs.send.pipe: t] external attachFiles: array(string) => t = "attachFiles";
  [@bs.send.pipe: t] external setAuthor: stringResolvable => t = "setAuthor";
  [@bs.send.pipe: t]
  external setAuthorWithIcon: (stringResolvable, urlString) => t = "setAuthor";
  [@bs.send.pipe: t]
  external setAuthorWithIconAndUrl: (stringResolvable, urlString, string) => t =
    "setAuthor";
  [@bs.send.pipe: t] external setColor: colorResolvable => t = "setColor";
  [@bs.send.pipe: t]
  external setDescription: stringResolvable => t = "setDescription";
  [@bs.send.pipe: t] external setFooter: stringResolvable => t = "setFooter";
  [@bs.send.pipe: t]
  external setFooterWithIcon: (stringResolvable, urlString) => t = "setFooter";
  [@bs.send.pipe: t] external setImage: urlString => t = "setImage";
  [@bs.send.pipe: t] external setTimestamp: Js.Date.t => t = "setTimestamp";
  [@bs.send.pipe: t] external setThumbnail: urlString => t = "setThumbnail";
  [@bs.send.pipe: t] external setTitle: string => t = "setTitle";
  [@bs.send.pipe: t] external setURL: urlString => t = "setURL";
};