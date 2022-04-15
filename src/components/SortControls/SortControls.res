open AppStore
let rs = React.string

let getClassName = (sort: sort, activeSort: sort, className: string) =>
  sort == activeSort ? `${className} ${className}--active` : className

@react.component
let make = (~className) => {
  let sort = Store.useAppSelector(state => state.sort)
  let dispatch = Store.useAppDispatch()

  let handleClick = (sort: sort, _e) => {
    dispatch(Sort(sort))
  }

  let sp = `\u00A0`
  <>
    <div onClick={handleClick(NoSort)} className={getClassName(sort, NoSort, className)}>
      {`❌${sp}`->rs}
    </div>
    <div onClick={handleClick(SortByDate)} className={getClassName(sort, SortByDate, className)}>
      {`🕒${sp}⬆️`->rs}
    </div>
    <div
      onClick={handleClick(SortByDateDesc)}
      className={getClassName(sort, SortByDateDesc, className)}>
      {`🕒${sp}⬇️`->rs}
    </div>
    <div onClick={handleClick(SortByTitle)} className={getClassName(sort, SortByTitle, className)}>
      {`⌨️${sp}⬆️`->rs}
    </div>
    <div
      onClick={handleClick(SortByTitleDesc)}
      className={getClassName(sort, SortByTitleDesc, className)}>
      {`⌨️${sp}⬇️`->rs}
    </div>
    <div onClick={handleClick(SortByScore)} className={getClassName(sort, SortByScore, className)}>
      {`🔢${sp}⬆️`->rs}
    </div>
    <div
      onClick={handleClick(SortByScoreDesc)}
      className={getClassName(sort, SortByScoreDesc, className)}>
      {`🔢${sp}⬇️`->rs}
    </div>
  </>
}
