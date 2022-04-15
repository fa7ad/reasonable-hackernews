module Intervals = {
  let millis = 1000.
  let seconds = millis *. 60.
  let minutes = seconds *. 60.
  let hours = minutes *. 60.
  let days = hours *. 24.
  let weeks = days *. 7.
  let months = days *. 30.
}

let epochToJsEpoch = epoch => epoch *. 1000.

let differenceToNow = time => Js.Date.now() -. time

let pluralizedAgo = (singular, n) => {
  let plural = singular ++ "s"
  n == 1. ? `1 ${singular} ago` : `${n->int_of_float->string_of_int} ${plural} ago`
}

let get_time_ago = time => {
  open Intervals
  let diff = time |> epochToJsEpoch |> differenceToNow
  if diff < minutes {
    "just now"
  } else {
    let (diff, unit) = if diff < hours {
      (diff /. minutes, "minute")
    } else if diff < days {
      (diff /. hours, "hour")
    } else if diff < weeks {
      (diff /. days, "day")
    } else if diff < months {
      (diff /. weeks, "week")
    } else {
      (diff /. months, "month")
    }
    pluralizedAgo(unit, diff)
  }
}
