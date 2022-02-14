type post = {
  id: int,
  title: string,
  by: string,
  time: int,
  score: int,
  descendants: int,
  url: option<string>,
}

module Codecs = {
  let post = Jzon.object7(
    ({id, title, by, time, score, descendants, url}) => (
      id,
      title,
      by,
      time,
      score,
      descendants,
      url,
    ),
    ((id, title, by, time, score, descendants, url)) =>
      {
        id: id,
        title: title,
        by: by,
        time: time,
        score: score,
        descendants: descendants,
        url: url,
      }->Ok,
    Jzon.field("id", Jzon.int),
    Jzon.field("title", Jzon.string),
    Jzon.field("by", Jzon.string),
    Jzon.field("time", Jzon.int),
    Jzon.field("score", Jzon.int),
    Jzon.field("descendants", Jzon.int),
    Jzon.field("url", Jzon.string)->Jzon.optional,
  )

  let postIds = Jzon.array(Jzon.int)
}

let topstories_url = "https://hacker-news.firebaseio.com/v0/topstories.json"
let single_story_url = (id: int) =>
  "https://hacker-news.firebaseio.com/v0/item/" ++ string_of_int(id) ++ ".json"

let fetchJson = (url: string) => Fetch.fetch(url)->Promise.then(Fetch.Response.json)
