open Data

type sort =
  | NoSort
  | SortByTitle
  | SortByTitleDesc
  | SortByScore
  | SortByScoreDesc

type appState = {posts: array<post>, loading: bool, sort: sort}

type appAction =
  | StartFetch
  | FetchSuccess(array<post>)
  | FetchFailure
  | Sort(sort)

let reducer = (appState, appAction) => {
  switch appAction {
  | StartFetch => {posts: [], loading: true, sort: NoSort}
  | FetchSuccess(posts) => {posts: posts, loading: false, sort: NoSort}
  | FetchFailure => {posts: [], loading: false, sort: NoSort}
  | Sort(sort) =>
    switch sort {
    | SortByTitle => {
        ...appState,
        sort: sort,
        posts: Belt.SortArray.stableSortBy(appState.posts, (post_a, post_b) =>
          Js.String.localeCompare(post_b.title, post_a.title)->int_of_float
        ),
      }
    | SortByTitleDesc => {
        ...appState,
        sort: sort,
        posts: Belt.SortArray.stableSortBy(appState.posts, (post_a, post_b) =>
          Js.String.localeCompare(post_a.title, post_b.title)->int_of_float
        ),
      }
    | SortByScore => {
        ...appState,
        sort: sort,
        posts: Belt.SortArray.stableSortBy(appState.posts, (posta, postb) =>
          posta.score - postb.score
        ),
      }
    | SortByScoreDesc => {
        ...appState,
        sort: sort,
        posts: Belt.SortArray.stableSortBy(appState.posts, (posta, postb) =>
          postb.score - posta.score
        ),
      }
    | NoSort => {...appState, sort: NoSort}
    }
  }
}

let initialState = {
  posts: [],
  loading: false,
  sort: NoSort,
}
