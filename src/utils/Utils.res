let \"@<" = (f, g, a) => f(g(a))

let compose = (fns, arg) => Js.Array2.reduceRight(fns, (a, f) => f(a), arg)

let urlRegex = %re("/(([^:\/?#]+):)?((?:\/\/)?([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?/")

let flip = (f, a, b) => f(b, a)

let tap = (f: 'a => unit, a) => {
  f(a)
  a
}

let mapAll = (xs, f) => Js.Array2.map(xs, f)->Promise.all

let get_host_from_url = link => {
  open Js
  String2.match_(link, urlRegex)
  |> Option.getWithDefault([])
  |> (Belt_Array.get->flip)(4)
  |> Option.getWithDefault(String.slice(~from=0, ~to_=30, link) ++ "...")
  |> String.replaceByRe(%re(`/^www\\./i`), "")
}
