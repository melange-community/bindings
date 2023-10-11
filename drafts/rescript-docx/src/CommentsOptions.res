type commentOptions = {
  id: float,
  children: array<FileChild.t>,
  initials?: string,
  author?: string,
  date?: Js.Date.t,
}

type t = {children: array<commentOptions>}
