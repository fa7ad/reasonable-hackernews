# *Reason*able HackerNews

[![Status](https://badgen.net/github/status/fa7ad/reasonable-hackernews/master?icon=zeit&label=%20)](https://github.com/fa7ad/reasonable-hackernews/deployments) [![No Maintenance Intended](https://unmaintained.tech/badge.svg)](https://unmaintained.tech/)

This is a very small project to try and make a full-fledged\* React app using ReasonML et al.

This is completely for the purpose of me learning ReasonML and trying to integrate the ReasonML/ReasonReact ecosystem with my prior knowledge of the React ecosystem.

This application pulls a few top stories from the HackerNews API and displays them in a very simple, responsive UI. I added a very basic sorting functionality as well.

The state management is done through *reductive* (a rewrite of Redux in ReasonML) and ReduxThunk.

## Tooling
This project uses [create-react-app](https://create-react-app.dev/) along with my [ReasonML template](https://github.com/fa7ad/cra-template-reason).
Initally I wrote some tests using Jest, but I decided not to continue with testing on a project of this tiny scale.

## License
See [**LICENSE.md**](https://github.com/fa7ad/reasonable-hackernews/blob/master/LICENSE.md)
