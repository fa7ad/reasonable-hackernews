open AppStore;

let getPosts = state => state.posts;

[@react.component]
let make = () => {
  let dispatch = AppStore.useDispatch();
  let postsList = AppStore.useSelector(getPosts);
  React.useEffect1(
    () => {
      dispatch(ReduxThunk.Thunk(Actions.fetchPosts))
      |> Utils.React.ignoreEffect
    },
    [|dispatch|],
  );

  let postView =
    switch (postsList) {
    | [] => <Loading />
    | list =>
      Utils.React.map_list(
        post => {<PostCard postData=post key={post.id->string_of_int} />},
        list,
      )
    };

  <>
    <Navbar />
    <div className="grid__container grid__container--root">
      <div> "Reasonable HackerNews"->React.string </div>
      <div className="postlist__container">
        postView
      </div>
    </div>
  </>;
};