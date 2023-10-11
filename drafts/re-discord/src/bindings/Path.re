/* Path Module Bindings*/
type path;
[@bs.val] external dirname: string = "__dirname";
[@bs.module "path"] [@bs.variadic]
external join: array(string) => string = "join";