let (@<) = (f, g, a) => f(g(a));

let compose = (fns, arg) => List.fold_right((f, a) => f(a), fns, arg);

let map_list_to_array = fn => Array.map(fn) @< Array.of_list;

module React = {
  let map_list = fn => React.array @< map_list_to_array(fn);
};