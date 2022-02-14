%%raw(`import "./styles/index.sass"`)

module ServiceWorker = {
  @module("./serviceWorker")
  external unregister: unit => unit = "unregister"
  @module("./serviceWorker") external register: unit => unit = "register"
}

module StrictMode = {
  @module("react") @react.component
  external make: (~children: React.element=?) => React.element = "StrictMode"
}

module ReactApp = {
  @react.component
  let make = () => {
    let (state, dispatch) = React.useReducer(AppStore.reducer, AppStore.initialState)

    <StrictMode>
      <Store.DispatchProvider value={dispatch}>
        <Store.StateProvider value={state}> <App /> </Store.StateProvider>
      </Store.DispatchProvider>
    </StrictMode>
  }
}

switch ReactDOM.querySelector("#root") {
| Some(root) => ReactDOM.render(<ReactApp />, root)
| None => ()
}

/*
  If you want your app to work offline and load faster, you can change
  unregister() to register() below. Note this comes with some pitfalls.
  Learn more about service workers: https://bit.ly/CRA-PWA
 */
ServiceWorker.unregister()
