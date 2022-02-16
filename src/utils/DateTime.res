module Intervals = {
  let millis = 1000.
  let seconds = millis *. 60.
  let minutes = seconds *. 60.
  let hours = minutes *. 60.
  let days = hours *. 24.
  let weeks = days *. 7.
  let months = days *. 30.
}

let differenceToNow = time => Js.Date.now() -. time

let pluralizedAgo = (singular, plural, n) =>
  n == 1. ? `1 ${singular} ago` : `${n -> int_of_float -> string_of_int} ${plural} ago`

let get_time_ago = time => {
  open Intervals
  let diff = differenceToNow(time)
  if diff < minutes {
    "just now"
  } else if diff < hours {
    diff /. minutes |> pluralizedAgo("minute", "minutes")
  } else if diff < days {
    diff /. hours |> pluralizedAgo("hour", "hours")
  } else if diff < weeks {
    diff /. days |> pluralizedAgo("day", "days")
  } else if diff < months {
    diff /. weeks |> pluralizedAgo("week", "weeks")
  } else {
    diff /. months |> pluralizedAgo("month", "months")
  }
}
