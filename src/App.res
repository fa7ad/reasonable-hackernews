open Promise
open Js.Array2

exception MyError(string)

@react.component
let make = () => {
  let dispatch = Store.useAppDispatch()

  React.useEffect0(() => {
    dispatch(AppStore.StartFetch)

    Data.fetchJson(Data.topstories_url)
    ->then(data =>
      switch Jzon.decodeWith(data, Data.Codecs.postIds) {
      | Ok(post_ids) =>
        post_ids
        ->slice(~start=0, ~end_=20)
        ->Utils.mapAll(id => Data.single_story_url(id)->Data.fetchJson)
      | _ => reject(MyError("Failed to decode top stories"))
      }
    )
    ->thenResolve(posts => posts->reduce((list_of_posts, single_post) =>
        switch Jzon.decodeWith(single_post, Data.Codecs.post) {
        | Ok(post) => concat(list_of_posts, [post])
        | err =>
          Js.log2("err", err)
          list_of_posts
        }
      , []))
    ->thenResolve(posts => dispatch(posts->AppStore.FetchSuccess))
    ->catch(err => {
      Js.log(err)
      dispatch(AppStore.FetchFailure)
      resolve()
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
