open Js

let \"." = (f, g, a) => f(g(a))

let urlRegex = %re("/(([^:\/?#]+):)?((?:\/\/)?([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?/")

let mapPromiseAll = (xs, f) => Array2.map(xs, f)->Promise.all

type exn += Error({message: string}) | ErrorWithStack({message: string, stack: string})

let get_host_from_url = link => {
  link
  |> String.match_(urlRegex)
  |> Option.getWithDefault([])
  |> Belt_Array.get(_, 4)
  |> Option.getWithDefault(String.slice(~from=0, ~to_=30, link) ++ "...")
  |> String.replaceByRe(%re(`/^www\\./i`), "")
}

let decodeWithPromise = (data, codec) => {
  switch Jzon.decodeWith(data, codec) {
  | Ok(decoded) => decoded->Promise.resolve
  | Error(err) =>
    switch err {
    | #SyntaxError(message) => Error({message: message})
    | #MissingField(location, message) =>
      ErrorWithStack({message: message, stack: location->Array.toString})
    | #UnexpectedJsonType(location, message, _) =>
      ErrorWithStack({message: message, stack: location->Array.toString})
    | #UnexpectedJsonValue(location, message) =>
      ErrorWithStack({message: message, stack: location->Array.toString})
    }->Promise.reject
  }
}
