# ReScript binding to [Heroicons](https://heroicons.com/)

With this binding, heroicons can be used as ReScript-React Components.

```OCaml
open Heroicons

@react.component
let make = () => {
  <div>
    <Solid.PaperAirplaneIcon className="w-8 h-8" />
    <Outline.PaperAirplaneIcon className="w-8 h-8" />
  </div>
}
(* w-8, h-8 are tailwind css classes.*)
```
### Demo
Please visit the following link to check out the demo.<br>
[ReScript-Heroicons Demo](https://rescript-heroicons-demo.vercel.app)

### Installation

`yarn add rescript-heroicons` <br> or <br> `npm install rescript-heroicons` <br> <br>
In bsconfig.json

```json 
"bs-dependencies": ["rescript-heroicons"]
```

The binding has the following dependencies, and they have to be installed.
- [@rescript/react](https://www.npmjs.com/package/@rescript/react)
- [@heroicons/react](https://www.npmjs.com/package/@heroicons/react)

### <br>Author


Nyi Nyi Than (Jazz)
- LinkedIn: [@nyinyithann](https://www.linkedin.com/in/nyinyithan/)
- Twitter: [@JazzTuyat](https://twitter.com/JazzTuyat)

### License

MIT