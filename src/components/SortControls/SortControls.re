open AppData;

let getSort = (state: AppStore.appState) => state.sort;
let sortFields = [Title, Date, Votes];

[@react.component]
let make = () => {
  let dispatch = AppStore.useDispatch();
  let {order, field} = AppStore.useSelector(getSort);

  let changeSort = (clicked, _) => {
    let action =
      switch (clicked, order, clicked == field) {
      | (NoField, _, _) => Sort.Clear
      | (_, Ascending, true) => Sort.SortDescending(clicked)
      | _ => Sort.SortAscending(clicked)
      };
    dispatch(AppStore.SortAction(action)) |> ignore;
  };

  let getLabelAndIcon =
    React.useCallback2(
      name => {
        let label = label_of_field(name);
        switch (order, field == name, name == NoField) {
        | (_, _, true) => label->React.string
        | (Ascending, true, _) => {j|$label ⭣|j}->React.string
        | (Descending, true, _) => {j|$label ⭡|j}->React.string
        | _ => {j|$label ⭥|j}->React.string
        };
      },
      (order, field),
    );

  let nav_items =
    Utils.React.map_list(
      field => {
        <span onClick={changeSort(field)} key={label_of_field(field)}>
          {getLabelAndIcon(field)}
        </span>
      },
      order == NoSort ? sortFields : [NoField, ...sortFields],
    );
  ();

  <> nav_items </>;
};