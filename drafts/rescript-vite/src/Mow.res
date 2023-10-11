module Dom = {
  @set external setInnerHTML: (Dom.element, string) => unit = "innerHTML"
  @get external getInnerHTML: Dom.element => string = "innerHTML"
  @val external element: Dom.element = "document"
  @send @return(nullable)
  external querySelector: (Dom.element, string) => option<Dom.element> = "querySelector"
  @scope("document") @val external createElement: string => Dom.element = "createElement"
  @send external appendChild: (Dom.element, Dom.element) => unit = "appendChild"
  @send
  external addEventListener: (Dom.element, string, unit => unit) => unit = "addEventListener"
  @send
  external removeEventListener: (Dom.element, string, unit => unit) => unit = "removeEventListener"
  @module("./Main.module.scss") @val external style: {..} = "default"
  @set external setClass: (Dom.element, string) => unit = "className"
}
