open AppData;

type sortAction =
  | Clear
  | SortAscending(field)
  | SortDescending(field);

let sortReducer = (_, action) => {
  switch (action) {
  | Clear => {order: NoSort, field: NoField}
  | SortAscending(field) => {order: Ascending, field}
  | SortDescending(field) => {order: Descending, field}
  };
};