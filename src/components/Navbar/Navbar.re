module Logo = {
  [@bs.module "@svgr/webpack?-svgo!../../assets/logo.svg"] [@react.component]
  external make: (~role: string=?, ~className: string=?) => React.element =
    "ReactComponent";
};

module GitHubIcon = {
  [@bs.module "@svgr/webpack?-svgo!../../assets/github.svg"] [@react.component]
  external make: (~role: string=?, ~className: string=?) => React.element =
    "ReactComponent";
};

let rs = React.string;

[@react.component]
let make = () => {
  <section className="navbar">
    <div className="empty" />
    <a href="/" className="brand">
      <Logo className="brand-logo" role="logo" />
    </a>
    <nav className="navbar-menu">
      <a
        className="github-link"
        href="https://github.com/fa7ad"
        title="My GitHub"
        target="_blank">
        <GitHubIcon className="icon github" />
        "@fa7ad"->rs
      </a>
    </nav>
  </section>;
};