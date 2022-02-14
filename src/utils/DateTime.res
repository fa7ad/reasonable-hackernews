let differenceToNow = time => int_of_float(Js.Date.now() /. 1000.) - time

let get_time_ago = time => {
  let diff = differenceToNow(time)
  if diff < 60 {
    "just now"
  } else if diff < 3600 {
    let interval = diff / 60
    switch interval {
    | 1 => "1 minute ago"
    | _ => interval->string_of_int ++ " minutes ago"
    }
  } else if diff < 86400 {
    let interval = diff / 3600
    switch interval {
    | 1 => "1 hour ago"
    | _ => interval->string_of_int ++ " hours ago"
    }
  } else if diff < 604800 {
    let interval = diff / 86400
    switch interval {
    | 1 => "1 day ago"
    | _ => interval->string_of_int ++ " days ago"
    }
  } else if diff < 2419200 {
    let interval = diff / 604800
    switch interval {
    | 1 => "1 week ago"
    | _ => interval->string_of_int ++ " weeks ago"
    }
  } else {
    let interval = diff / 2419200
    switch interval {
    | 1 => "1 month ago"
    | _ => interval->string_of_int ++ " months ago"
    }
  }
}
