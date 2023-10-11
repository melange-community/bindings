open Belt
open Mow

switch Dom.element->Dom.querySelector("#app") {
| Some(app) => {
    let countor = ref(1)
    app->Dom.setInnerHTML("Hello World")
    let h1 = Dom.createElement("h1")
    h1->Dom.setInnerHTML("append Head 1")
    let button = Dom.createElement("button")
    let div = Dom.createElement("div")
    div->Dom.setClass(Dom.style["counterButton"])
    div->Dom.setInnerHTML(`counter: ${countor.contents->Int.toString}`)
    button->Dom.setInnerHTML("click")
    button->Dom.addEventListener("click", () => {
      countor.contents = countor.contents + 1
      div->Dom.setInnerHTML(`counter: ${countor.contents->Int.toString}`)
    })
    app->Dom.appendChild(h1)
    app->Dom.appendChild(button)
    app->Dom.appendChild(div)
  }
| _ => Js.log("not find #app")
}
