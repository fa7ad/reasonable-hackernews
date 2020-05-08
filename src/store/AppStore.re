open Sort;
open Post;
open AppData;

type ReduxThunk.thunk(_) +=
  | SortAction(sortAction)
  | PostAction(postAction);

type appState = {
  posts: list(post),
  sort,
};

let appReducer = (state, action) => {
  switch (action) {
  | SortAction(action) => {...state, sort: sortReducer(state.sort, action)}
  | PostAction(action) => {...state, posts: postReducer(state.posts, action)}
  | _ => state
  };
};

let thunkedLogger = (store, next) =>
  Middleware.thunk(store) @@ Middleware.logger(store) @@ next;

let appStore =
  Reductive.Store.create(
    ~reducer=appReducer,
    ~preloadedState={posts: [], sort: NoSort},
    ~enhancer=thunkedLogger,
    (),
  );

include ReductiveContext.Make({
  type action = ReduxThunk.thunk(appState);
  type state = appState;
});