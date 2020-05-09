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

let initialState = {
  posts: [],
  sort: {
    order: NoSort,
    field: NoField,
  },
};

let appReducer = (state, action) => {
  switch (action) {
  | SortAction(action) => {...state, sort: sortReducer(state.sort, action)}
  | PostAction(action) => {
      ...state,
      posts: postReducer(state.posts, action),
    }
  | _ => state
  };
};

let thunkedLogger = (store, next) =>
  Middleware.thunk(store) @@ Middleware.logger(store) @@ next;

let appStore =
  Reductive.Store.create(
    ~reducer=appReducer,
    ~preloadedState=initialState,
    ~enhancer=thunkedLogger,
    (),
  );

include ReductiveContext.Make({
  type action = ReduxThunk.thunk(appState);
  type state = appState;
});