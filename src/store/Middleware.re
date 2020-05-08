/***
 * logs the action before dispatching and the new state after.
 */
let logger = (store, next, action) => {
  Js.log(action);
  let returnValue = next(action);
  Js.log(Reductive.Store.getState(store));
  returnValue
};


/***
 * middleware that listens for a specific action and calls that function.
 * Allows for async actions.
 */
let thunk = (store, next, action) =>
  switch action {
  | ReduxThunk.Thunk(func) => func(store)
  | _ => next(action)
  };