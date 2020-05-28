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
      <div className="page__title">
        "Reasonable HackerNews"->React.string
      </div>
      <div className="sort__container">
        <div className="sort__caption"> "Sort: "->React.string </div>
        <SortControls className="sort__item" />
      </div>
      <PostList className="postlist__container" />
    </div>
  </>;
};