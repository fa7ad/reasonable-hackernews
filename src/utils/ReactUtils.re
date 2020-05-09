let (@<) = (f, g, a) => f(g(a));

let map_list = fn => React.array @< Array.map(fn) @< Array.of_list;
