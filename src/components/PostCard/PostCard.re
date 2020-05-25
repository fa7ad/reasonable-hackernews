open AppData;
let rst = React.string;

let get_host = link => {
  let matches = Js.String.match(Utils.urlRegex, link);
  let hostname = Belt.Array.get(matches->Belt.Option.getWithDefault([||]), 4);
  switch (hostname) {
  | Some(host) => host
  | _ => Js.String.slice(~from=0, ~to_=30, link) ++ "..."
  };
};

[@react.component]
let make = (~postData: post) => {
  let {url, descendants, score, title} = postData;

  let externalLink =
    switch (url) {
    | Some(url) =>
      <span className="postcard__url">
        "("->rst
        <a href=url target="_blank"> {get_host(url)->rst} </a>
        ")"->rst
      </span>
    | None => React.null
    };

  let gotoLink = _ =>
    switch (url) {
    | Some(url) => Utils.Window.open_blank(url)
    | None => ()
    };

  let comments = string_of_int(descendants);
  let score = string_of_int(score);

  <div className="postcard">
    <div className="postcard__score"> score->rst </div>
    <div className="postcard__contents">
      <div className="postcard__title">
        <h3 onClick=gotoLink> title->rst </h3>
        externalLink
      </div>
      <div className="postcard__meta">
        <div className="postcard__comments">
          {j|$comments comments|j}->rst
        </div>
      </div>
    </div>
  </div>;
};