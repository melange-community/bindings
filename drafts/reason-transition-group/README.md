# reason-transition-group

This is [Bucklescript](https://bucklescript.github.io/) bindings for [react-transition-group](https://github.com/reactjs/react-transition-group).

versions @2.x.x are written for jsx3
versions @1.x.x are written for jsx2

# Install, [npm](https://www.npmjs.com/package/reason-transition-group)

```
yarn add reason-transition-group
```

# Setup

Add reason-transition-group to `bs-depenencies` in your `bsconfig.json`!

```js
{
  /* ... */
  "bs-dependencies": [
    "reason-transition-group"
  ],
  /* ... */
}
```

# Usage

Folow official docs of [React Transition Group](https://reactcommunity.org/react-transition-group/).

jsx2

```reason
open ReasonTransitionGroup

/* ... */
<Transition _in={inState} timeout=`int(500)>
...{state => <div>{state |> ReasonReact.string}</div>}
</Transiton>
/* ... */

/* ... */
<CSSTransition _in={inState} timeout=`obj(CSSTransition.timeoutFull(~enter: 500, ~exit:0, ())) classNames=`string(myClassName)>
...{state => <div>{state |> ReasonReact.string}</div>}
</CSSTransiton>
/* ... */


/* ... */
<CSSTransition _in={inState} timeout=`obj(CSSTransition.timeoutFull(~enter: int, ~exit:int, ())) classNames=`obj(CSSTransition.classFull(~appear: str, ~exit: str, ()))>
...{state => <div>{state |> ReasonReact.string}</div>}
</CSSTransiton>
/* ... */

```

jsx3

```reason
open ReasonTransitionGroup

/* ... */
<Transition _in={inState} timeout=`int(500)>
{state => <div>{state |> ReasonReact.string}</div>}
</Transiton>
/* ... */

/* ... */
<CSSTransition _in={inState} timeout=`obj(CSSTransition.timeoutFull(~enter: 500, ~exit:0, ())) classNames=`string(myClassName)>
{state => <div>{state |> ReasonReact.string}</div>}
</CSSTransiton>
/* ... */


/* ... */
<CSSTransition _in={inState} timeout=`obj(CSSTransition.timeoutFull(~enter: int, ~exit:int, ())) classNames=`obj(CSSTransition.classFull(~appear: str, ~exit: str, ()))>
{state => <div>{state |> ReasonReact.string}</div>}
</CSSTransiton>
/* ... */

```

Also check react-transition-group examples translated to reason-react [here for jsx2](./EXAMPLE.md), [here for jsx3](./EXAMPLEJSX3.md)

Feel free to post issues.
