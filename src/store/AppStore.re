open Sort;
open Post;
open AppData;


type appState = {
  posts: list(post),
  sort,
};

type ReduxThunk.thunk(_) +=
  | SortAction(sortAction)
  | PostAction(postAction)
  | DevToolsUpdate(appState);


let initialState = {
  posts: [],
  sort: {
    order: NoSort,
    field: NoField,
  },
};

let appReducer = (state: appState, action) => {
  switch (action) {
  | SortAction(action) => {...state, sort: sortReducer(state.sort, action)}
  | PostAction(action) => {
      ...state,
      posts: postReducer(state.posts, action),
    }
  | DevToolsUpdate(_) => state
  | _ => state
  };
};

let thunkedLogger = (store, next) =>
  Middleware.thunk(store) @@ Middleware.logger(store) @@ next;

let storeCreator =
  ReductiveDevTools.Connectors.enhancer(
    ~options=
      ReductiveDevTools.Extension.enhancerOptions(~name=__MODULE__, ()),
    ~devToolsUpdateActionCreator=
      devToolsState => DevToolsUpdate(devToolsState),
    ~stateSerializer={
      serialize: ReductiveDevTools.Utilities.Serializer.serializeObject,
      deserialize: ReductiveDevTools.Utilities.Serializer.deserializeObject,
    },
    (),
  ) @@
  Reductive.Store.create;

let appStore =
  storeCreator(
    ~reducer=appReducer,
    ~preloadedState=initialState,
    ~enhancer=thunkedLogger,
    (),
  );

include ReductiveContext.Make({
  type action = ReduxThunk.thunk(appState);
  type state = appState;
});