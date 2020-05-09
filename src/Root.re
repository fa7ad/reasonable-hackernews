[%bs.raw {|require("./styles/index.sass")|}];

module ServiceWorker = {
  [@bs.module "./serviceWorker"]
  external unregister: unit => unit = "unregister";
  [@bs.module "./serviceWorker"] external register: unit => unit = "register";
};

module StrictMode = {
  [@bs.module "react"] [@react.component]
  external make: (~children: React.element=?) => React.element = "StrictMode";
};

module ReactApp = {
  [@react.component]
  let make = () =>
    <StrictMode>
      <AppStore.Provider store=AppStore.appStore> <App /> </AppStore.Provider>
    </StrictMode>;
};

ReactDOMRe.renderToElementWithId(<ReactApp />, "root");

/*
  If you want your app to work offline and load faster, you can change
  unregister() to register() below. Note this comes with some pitfalls.
  Learn more about service workers: https://bit.ly/CRA-PWA
 */
ServiceWorker.unregister();