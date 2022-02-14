let rs = React.string

@react.component
let make = (~postData: Data.post) => {
  let {id, url, descendants, score, title, by} = postData

  open Utils
  let externalLink = switch url {
  | Some(url) => <span className="postcard__url"> {j`(${get_host_from_url(url)})`->rs} </span>
  | None => React.null
  }

  let comments = string_of_int(descendants)
  let score = string_of_int(score)
  let timeDifference = DateTime.get_time_ago(postData.time)

  let dot = <div className="postcard__dot"> {`·`->rs} </div>

  <div className="postcard">
    <div className="postcard__score"> {score->rs} </div>
    <div className="postcard__contents">
      <div className="postcard__title">
        <a href={j`https://news.ycombinator.com/item?id=$id`} target="_blank">
          <h3 title="Open HN Thread"> {title->rs} </h3> externalLink
        </a>
      </div>
      <div className="postcard__meta">
        <div className="postcard__author"> {j`Posted by $by`->rs} </div>
        {dot}
        <div className="postcard__time"> {timeDifference->rs} </div>
        {dot}
        <div className="postcard__comments">
          {switch comments {
          | "0" => "No comments"
          | "1" => comments ++ " comment"
          | _ => comments ++ " comments"
          }->rs}
        </div>
      </div>
    </div>
  </div>
}
