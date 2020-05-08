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


type sort =
  | NoSort
  | Ascending
  | Descending;
