open AppData;

type postAction =
  | FetchPosts(list(post));

let postReducer = (_, action) => {
  switch (action) {
  | FetchPosts(posts) => posts
  };
};