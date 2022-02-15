# *Reason*able HackerNews

[![Status](https://badgen.net/github/status/fa7ad/reasonable-hackernews/master?icon=zeit&label=&cache=60)](https://github.com/fa7ad/reasonable-hackernews/deployments) [![No Maintenance Intended](https://unmaintained.tech/badge.svg)](https://unmaintained.tech/)

This is a very small project to try and make a full-fledged\* React app using [ReScript](https://rescript-lang.org/) et al.

This is completely for the purpose of me learning ReScript and trying to integrate the ReScript ecosystem with my prior knowledge of the React ecosystem.

This application pulls a few top stories from the HackerNews API and displays them in a very simple, responsive UI. I added a very basic sorting functionality as well.

~~The state management is done through *reductive* (a rewrite of Redux in ReasonML) and ReduxThunk.~~

The state management this time around is completely done through `React.useReducer` and the Context API.

## Tooling
This project uses [create-react-app](https://create-react-app.dev/) along with the ReScript compiler, and `npm-run-all` to facilitate running both simultaneously.

## License
See [**LICENSE.md**](https://github.com/fa7ad/reasonable-hackernews/blob/master/LICENSE.md)
