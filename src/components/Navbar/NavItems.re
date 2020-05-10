[@react.component]
let make = (~items, ~getLabelAndIcon, ~getLabel, ~onItemClick) => {
  <nav className="navbar-menu">
    {Utils.React.map_list(
       field => {
         let label = getLabelAndIcon(field);
         <a href="#" onClick={onItemClick(field)} key=getLabel(field)> label </a>;
       },
       items,
     )}
    <a
      className="github-link"
      href="https://github.com/fa7ad"
      title="My GitHub"
      target="_blank">
      "@fa7ad"->React.string
    </a>
  </nav>;
};