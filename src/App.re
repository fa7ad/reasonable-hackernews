[@react.component]
let make = () => {
  let dispatch = AppStore.useDispatch();
  React.useEffect1(
    () => {
      dispatch(ReduxThunk.Thunk(Actions.fetchPosts));
      Some(() => ());
    },
    [|dispatch|],
  );
  <>
    <Navbar />
    <div className="grid__container grid__container--root">
      <div> "learn reason"->React.string </div>
      <div className="grid__row">
        <div className="grid__col grid__col--sm"> "A"->React.string </div>
        <div className="grid__col grid__col--sm"> "B"->React.string </div>
        <div className="grid__col grid__col--sm"> "C"->React.string </div>
      </div>
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