[@decco]
type post = {
  by: string,
  descendants: int,
  id: int,
  kids: list(int),
  score: int,
  time: int,
  title: string,
  type_: string,
  url: string,
};

type order =
  | NoSort
  | Ascending
  | Descending;

type field =
  | Title
  | Date
  | Votes
  | NoField;

type sort = {
  order,
  field,
};

let label_of_field = field =>
  switch (field) {
  | Title => "Title"
  | Date => "Date"
  | Votes => "Votes"
  | NoField => "None"
  };