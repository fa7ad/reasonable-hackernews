module Logo = {
  [@bs.module "@svgr/webpack?-svgo!../../assets/logo.svg"] [@react.component]
  external make: (~role: string=?, ~className: string=?) => React.element =
    "ReactComponent";
};

[@react.component]
let make = () => {
  <section className="navbar">
    <div className="brand"> <Logo className="brand-logo" role="logo" /> </div>
    <nav className="navbar-menu">
      <a href="https://github.com/fa7ad"> "My GitHub"->React.string </a>
    </nav>
  </section>;
};