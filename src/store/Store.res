open AppStore
let state_context = React.createContext(initialState)
let dispatch_context = React.createContext((_action: appAction) => ())

let useAppDispatch = () => React.useContext(dispatch_context)
let useAppState = () => React.useContext(state_context)
let useAppSelector = selector => {
  let state = useAppState()
  React.useMemo1(() => selector(state), [state])
}

module StateProvider = {
  let provider = React.Context.provider(state_context)
  @react.component
  let make = (~value, ~children) => {
    React.createElement(provider, {"value": value, "children": children})
  }
}

module DispatchProvider = {
  let provider = React.Context.provider(dispatch_context)
  @react.component
  let make = (~value, ~children) => {
    React.createElement(provider, {"value": value, "children": children})
  }
}
