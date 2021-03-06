open Utils;

let fetchPosts = store => {
  let go = dispatch => {
    let%Async response =
      Axios.get("https://hacker-news.firebaseio.com/v0/topstories.json");

    let postList = AppData.postList_decode(response##data);
    let postIds =
      switch (postList) {
      | Ok(postList) => postList
      | Error(_) => []
      };

    let postResponses =
      map_list_to_array(
        id => {
          Axios.get({j|https://hacker-news.firebaseio.com/v0/item/$id.json|j})
        },
        Belt.List.take(postIds, 30)->Belt.Option.getWithDefault([]),
      );

    let%Async responses = Js.Promise.all(postResponses);

    let posts =
      Array.fold_right(
        (result, acc) => {
          let post = AppData.post_decode(result##data);
          switch (post) {
          | Ok(post) => [post, ...acc]
          | Error(_) => acc
          };
        },
        responses,
        [],
      );

    dispatch(
      AppStore.PostAction(Post.FetchPosts(posts))
      ->(ReductiveDevTools.Utilities.tagVariant("PostAction(FetchPost)")),
    );

    Js.Promise.resolve(response);
  };

  go(Reductive.Store.dispatch(store)) |> ignore;
};