[@react.component]
let make = () => {
  let dispatch = AppStore.useDispatch();
  React.useEffect1(
    () => {
      dispatch(ReduxThunk.Thunk(Actions.fetchPosts))
      |> Utils.React.ignoreEffect
    },
    [|dispatch|],
  );
  <>
    <Navbar />
    <div className="grid__container grid__container--root">
      <div> "Reasonable HackerNews"->React.string </div>
      <PostCard
        postData={
          by: "fa7ad",
          descendants: 123,
          id: 1,
          score: 20,
          time: 1588806219,
          title: "Hello World",
          type_: "post",
          url: Some({|http://google.com|}),
        }
      />
      <PostCard
        postData={
          by: "fa7ad",
          descendants: 123,
          id: 1,
          score: 20,
          time: 1588806219,
          title: "Hello World",
          type_: "post",
          url: Some({|http://google.com|}),
        }
      />
    </div>
  </>;
};