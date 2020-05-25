let (@<) = (f, g, a) => f(g(a));

let compose = (fns, arg) => List.fold_right((f, a) => f(a), fns, arg);

let map_list_to_array = fn => Array.map(fn) @< Array.of_list;

let urlRegex = [%re
  "/(([^:\/?#]+):)?((?:\/\/)?([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?/"
];

module Window = {
  let _open = (name, url) =>
    Webapi.Dom.(Window.open_(~url, ~name, window)) |> ignore;
  let open_blank = _open("_blank");
  let open_self = _open("_self");
};

module React = {
  let map_list = fn => React.array @< map_list_to_array(fn);
};