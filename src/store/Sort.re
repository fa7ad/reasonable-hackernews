open AppData;

type sortAction =
  | Clear
  | SortAscending
  | SortDescending;

let sortReducer = (_, action) => {
  switch (action) {
  | Clear => NoSort
  | SortAscending => Ascending
  | SortDescending => Descending
  };
};