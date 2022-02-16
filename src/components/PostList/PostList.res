open Js.Array2

@react.component
let make = (~className) => {
  let posts = Store.useAppSelector(state => state.posts)
  let loading = Store.useAppSelector(state => state.loading)

  <section className>
    {if loading {
      <Loading />
    } else {
      posts->map(post => <PostCard postData={post} key={post.id->string_of_int} />)->React.array
    }}
  </section>
}
