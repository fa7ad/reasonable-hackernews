open Promise
open Js.Array2

@react.component
let make = () => {
  let dispatch = Store.useAppDispatch()

  React.useEffect0(() => {
    open Data
    open Utils

    dispatch(AppStore.StartFetch)
    ->resolve
    ->then(() => fetchJson(topstories_url))
    ->then(data => decodeWithPromise(data, Codecs.postIds))
    ->thenResolve(slice(~start=0, ~end_=20))
    ->then(post_ids => post_ids->mapPromiseAll(\"."(fetchJson, single_story_url)))
    ->then(posts => posts->mapPromiseAll(post => decodeWithPromise(post, Codecs.post)))
    ->thenResolve(posts => dispatch(posts->AppStore.FetchSuccess))
    ->catch(err => {
      Js.log(err)
      dispatch(AppStore.FetchFailure)->resolve
    })
    ->ignore

    None
  })

  <>
    <Navbar />
    <div className="grid__container grid__container--root">
      <div className="page__title"> {"Reasonable HackerNews"->React.string} </div>
      <div className="sort__container">
        <div className="sort__caption"> {"Sort: "->React.string} </div>
        <SortControls className="sort__item" />
      </div>
      <PostList className="postlist__container" />
    </div>
  </>
}
