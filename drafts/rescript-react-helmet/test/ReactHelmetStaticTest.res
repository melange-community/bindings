let helmet = ReactHelmet.renderStatic()

let title: string = helmet.title->ReactHelmet.toString

@react.component
let make = () => helmet.meta->ReactHelmet.toComponent
