/** [ConsoleMessage] sent by [Page] through the "console" event. */
type t;

/** The message arguments. */
[@bs.send]
external args: t => array(JSHandle.t('a)) = "args";

/** The text of the console message. */
[@bs.send]
external text: t => string = "text";

[@bs.deriving jsConverter]
type messageType = [
  | `log
  | `debug
  | `info
  | `error
  | `warning
  | `dir
  | `dirxml
  | `table
  | `trace
  | `clear
  | `startGroup
  | `startGroupCollapsed
  | `endGroup
  | [@bs.as "assert"] `assert_
  | `profile
  | `profileEnd
  | `count
  | `timeEnd
];

/** The type of console message as a string. */
[@bs.send]
external typeString: t => string = "type";

/** The console message's [messageType]. */
let type_ = t => messageTypeFromJs(typeString(t));
