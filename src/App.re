[@react.component]
let make = () => {
  let dispatch = AppStore.useDispatch();
  React.useEffect1(() => {
    dispatch(ReduxThunk.Thunk(Actions.fetchPosts));
    Some(() => ());
  }, [|dispatch|]);
  <>
    <Navbar />
    <div className="container">
      <div> "learn reason"->React.string </div>
      <div className="row">
        <div className="col"> "A"->React.string </div>
        <div className="col"> "B"->React.string </div>
        <div className="col"> "C"->React.string </div>
      </div>
    </div>
  </>;
};