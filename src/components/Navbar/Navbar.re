module Logo = {
  [@bs.module "@svgr/webpack?-svgo!../../assets/logo.svg"] [@react.component]
  external make: (~role: string=?, ~className: string=?) => React.element =
    "ReactComponent";
};

let rs = React.string;

[@react.component]
let make = () => {
  <section className="navbar">
    <div className="brand"> <Logo className="brand-logo" role="logo" /> </div>
    <nav className="navbar-menu">
      <a
        className="github-link"
        href="https://github.com/fa7ad"
        title="My GitHub"
        target="_blank">
        "@fa7ad"->React.string
      </a>
    </nav>
  </section>;
};