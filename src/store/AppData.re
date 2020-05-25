[@decco]
type post = {
  by: string,
  [@decco.default 0]
  descendants: int,
  id: int,
  // [@decco.default []]
  // kids: list(int),
  score: int,
  time: int,
  title: string,
  [@decco.key "type"]
  type_: string,
  url: option(string),
};

[@decco]
type postList = list(int);

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
  | NoField => {j|×|j}
  };