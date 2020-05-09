open AppData;

module Logo = {
  [@bs.module "@svgr/webpack?-svgo!../../assets/logo.svg"] [@react.component]
  external make: (~role: string=?, ~className: string=?) => React.element =
    "ReactComponent";
};

let rs = React.string;

[@react.component]
let make = () => {
  let sortOrder = AppStore.useSelector(store => store.sort.order);
  let sortField = AppStore.useSelector(store => store.sort.field);

  let label_and_icon = name => {
    let label = label_of_field(name);
    switch (sortOrder, sortField == name, sortField == NoField) {
    | (_, true, true) => label->rs
    | (Descending, true, false) => {j|$label ▲|j}->rs
    | _ => {j|$label ▼|j}->rs
    };
  };

  let sortFields = [Title, Date, Votes, NoField];
  let changeSort = (_field, _) => ();

  <section className="navbar">
    <div className="brand"> <Logo className="brand-logo" role="logo" /> </div>
    <nav className="navbar-menu">
      {ReactUtils.map_list(
         field => {
           let label = label_and_icon(field);
           <a href="#" onClick={changeSort(field)}> label </a>;
         },
         sortFields,
       )}
      <a href="https://github.com/fa7ad"> "My GitHub"->rs </a>
    </nav>
  </section>;
};