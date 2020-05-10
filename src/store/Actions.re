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
        idInt => {
          let id = string_of_int(idInt);
          Axios.get(
            {j|https://hacker-news.firebaseio.com/v0/item/$id.json|j},
          );
        },
        Belt.List.take(postIds, 20) -> Belt.Option.getWithDefault([]),
      );

    let%Async responses = Js.Promise.all(postResponses);

    let posts =
      Array.fold_left(
        (acc, result) => {
          let post = AppData.post_decode(result##data);
          switch (post) {
          | Ok(post) => [post, ...acc]
          | Error(_) => acc
          };
        },
        [],
        responses,
      );


    dispatch(AppStore.PostAction(Post.FetchPosts(posts)));

    Js.Promise.resolve(response);
  };

  go(Reductive.Store.dispatch(store)) |> ignore;
};