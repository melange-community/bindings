# Bs-intersection-observer

this package make the bindings for the IntersectionObserver api.

## How to install ?

```
npm install bs-intersection-observer --save
```

```bash
yarn add bs-intersection-observer
```

Then add the dependency to you `bsconfig.json`

```json
"bs-dependencies": [
	"bs-intersection-observer"
],
```

## How to use it ?

### What the package contains ?

Under the module `BsIntersectionObserver`, you'll find 2 sub module:

#### Types

`Types` is pretty obvious, it contains all the types related to the `IntersectionObserver`. You'll notice that under type there's:

-   `JsT` : Javascript types
-   `T` : Reason types

#### Create

Probably the one you're looking for. `Create` contains two functions:

-   `newIntersectionObserver` : the direct binding from Js
-   `intersectionObserver` : the IntersectionObserver adapted to Reason with some nice completion (the one you want to call)

### Example with reason-react

```reason
[@bs.val] [@bs.scope "document"]
external querySelector: string => Dom.element = "querySelector";

[@react.component]
let make = () => {
  let observer =
    BsIntersectionObserver.Create.intersectionObserver(
      ~cb=
        (entries, _) => {
          Belt.Array.map(entries, entry =>
            if (entry.intersectionRatio > 0.) {
              Js.log("Visible element");
            } else {
              Js.log("Not visible element");
            }
          )
          ->ignore;
          ();
        },
      ~options=None,
    );
  React.useEffect1(
    () => {
      let el = querySelector(".hello");
      observer.observe(el);
      Some(() => observer.unobserve(el));
    },
    [||],
  );

  <div className="hello"> "Hello world"->ReasonReact.string </div>;
};
```
