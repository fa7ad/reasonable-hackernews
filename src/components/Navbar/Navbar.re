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
    switch (sortOrder, sortField == name) {
    | (Descending, true) => {j|$label ▲|j}->rs
    | _ => {j|$label ▼|j}->rs
    };
  };

  let sortFields = [Title, Date, Votes];
  let changeSort = (_field, _) => ();

  <section className="navbar">
    <div className="brand"> <Logo className="brand-logo" role="logo" /> </div>
    <NavItems
      items=sortFields
      getLabelAndIcon=label_and_icon
      getLabel=label_of_field
      onItemClick=changeSort
    />
  </section>;
};