type options = {
  includeSeconds: bool,
  addSuffix: bool,
};

[@bs.module "date-fns/formatDistanceToNow"]
external formatDistanceToNow : ([@bs.unwrap] [
  | `Str(string)
  | `Int(int)
  | `Date(Js.Date.t)
], options) => string = "default";

// vim: set ft=reason
