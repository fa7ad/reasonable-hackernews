open Data

type sort =
  | NoSort
  | SortByTitle
  | SortByTitleDesc
  | SortByScore
  | SortByScoreDesc

type appState = {
  posts: array<post>,
  unsorted_posts: array<post>,
  loading: bool,
  sort: sort,
}

type appAction =
  | StartFetch
  | FetchSuccess(array<post>)
  | FetchFailure
  | Sort(sort)

let initialState = {
  posts: [],
  unsorted_posts: [],
  loading: false,
  sort: NoSort,
}

let sortBy = Belt.SortArray.stableSortBy
let compareStrings = (string_a, string_b) =>
  Js.String.localeCompare(string_a, string_b)->int_of_float

let reducer = (appState, appAction) => {
  switch appAction {
  | StartFetch => {...initialState, loading: true}
  | FetchSuccess(posts) => {
      posts: posts,
      unsorted_posts: posts,
      loading: false,
      sort: NoSort,
    }
  | FetchFailure => initialState
  | Sort(sort) =>
    switch sort {
    | SortByTitle => {
        ...appState,
        sort: sort,
        posts: sortBy(appState.unsorted_posts, (post_a, post_b) =>
          compareStrings(post_b.title, post_a.title)
        ),
      }
    | SortByTitleDesc => {
        ...appState,
        sort: sort,
        posts: sortBy(appState.unsorted_posts, (post_a, post_b) =>
          compareStrings(post_a.title, post_b.title)
        ),
      }
    | SortByScore => {
        ...appState,
        sort: sort,
        posts: sortBy(appState.unsorted_posts, (post_a, post_b) =>
          post_a.score - post_b.score
        ),
      }
    | SortByScoreDesc => {
        ...appState,
        sort: sort,
        posts: sortBy(appState.unsorted_posts, (post_a, post_b) =>
          post_b.score - post_a.score
        ),
      }
    | NoSort => {...appState, posts: appState.unsorted_posts, sort: NoSort}
    }
  }
}
