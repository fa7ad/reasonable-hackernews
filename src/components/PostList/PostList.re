open AppData;
open AppStore;

let getPosts = state => state.posts;
let getSortOrder = state => state.sort.order;
let getSortField = state => state.sort.field;

let sortPostList = (order, field) => {
  let comp = (a, b) => order == Descending ? compare(b, a) : compare(a, b);

  List.sort((px, py) => {
    switch (field) {
    | Title => comp(px.title, py.title)
    | Date => comp(py.time, px.time)
    | Votes => comp(px.score, py.score)
    | _ => comp(px.id, py.id)
    }
  });
};

[@react.component]
let make = (~className="") => {
  let postsList = useSelector(getPosts);
  let sortOrder = useSelector(getSortOrder);
  let sortField = useSelector(getSortField);

  let postView =
    switch (postsList) {
    | [] => <Loading />
    | list =>
      list
      |> sortPostList(sortOrder, sortField)
      |> Utils.React.map_list(post =>
           <PostCard postData=post key={post.id->string_of_int} />
         )
    };
  <div className> postView </div>;
};