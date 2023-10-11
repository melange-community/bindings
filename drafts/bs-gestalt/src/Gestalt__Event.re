[@bs.deriving abstract]
type t('a) = {
  event: 'a,
  [@bs.optional]
  value: string,
  [@bs.optional]
  activeTabIndex: int,
  [@bs.optional]
  activeIndex: int,
};
