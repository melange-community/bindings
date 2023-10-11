/*
 following from https://blog.bitsrc.io/implementing-react-life-cycles-using-reason-react-hooks-3c1d25de534c

 React lifecycle methods fall into the following categories:
    Initialization
    Mounting
    Updating
    Unmounting
  */

// initialising
module Constructor = {
  /*
        This life cycle method is called before render and is used for initializing the state
        or to create some of the bindings for the event listener that the component will use.
   */
  type state = {counter: int};

  let initState = () => {counter: 0};

  [@react.component]
  let make = () => {
    let (state, _setState) = React.useState(initState);

    <div>
      {("init state using hooks: " ++ state.counter->string_of_int)
       ->React.string}
    </div>;
  };
};

// mounting component
module Render = {
  /*
     render — This lifecycle method is used for creating the HTML content for the following component.
     This function will return the React elements which will be converted into the DOM elements.
     These should be a pure function and should not change the state while returning the elements.
   */
  [@react.component]
  let make = (~name: string) => {
    <div> <p> name->React.string </p> </div>;
  };
};

module ComponentDidMount = {
  /*
        This lifecycle method is called mostly for fetching some data
        or manipulating the DOM after the component is rendered,
        you can update the state based on the computations which
        you have performed in this method.
        This is only called after the first render of the component,
        for successive render check other lifecycle methods.
   */
  [@react.component]
  let make = () => {
    let (counter, setCounter) = React.useState(() => 0);

    // Enter anything you want to be in componentDidMount
    React.useEffect1(
      () => {
        setCounter(_ => counter + 1);
        None;
      },
      [||] // this is the key and means the effect is independent of any change in props
    );
    ("counter is rendered only one time: " ++ counter->string_of_int)
    ->React.string;
  };
};

// updating the component
// test these more
module ShouldComponentUpdate = {
  /*
      This lifecycle method is called to determine whether the component will re-render
      when there is a change in the props or the state of the components by returning the boolean flag.
      By default, the component will be re-render on every state or prop change
   */
  module Always = {
    [@react.component]
    let make = (~name) => name->React.string;
  };

  module ShallowCompare = {
    [@react.component]
    let make = (~name) => name->React.string;

    let make = React.memo(make);
    /*
        Note: You can also use React.useMemo to create memoized functions
        so that the component will not render after
        if a complex computation returns the same result.
     */
  };

  module DeepCompare = {
    [@react.component]
    let make = (~name) => name->React.string;

    let deepCompare = (nextProps, currentProps) => nextProps === currentProps;

    let make =
      React.memoCustomCompareProps(
        Always.make,
        (nextProps, currentProps) => {
          let result = deepCompare(nextProps, currentProps);
          result;
        },
      );
  };
};

module ComponentDidUpdate = {
  /*
        This lifecycle method is called after every re-render except for the first one.
        This lifecycle is generally used for doing any computation like network requests,
        event listener on the basis of change in props.
        Make sure to compare the props while updating the state,
        otherwise it will be stuck in infinite re-render.
   */
  [@react.component]
  let make = (~name) => {
    let (counter, setCounter) = React.useState(() => 0);

    // This will allow the change of the state/props only if certain props are passed or changed to.
    React.useEffect1(
      () =>
        if (name === "componentDidUpdate") {
          setCounter(_ => counter + 1);
          Js.log(counter);
          None;
        } else {
          Js.log("no update");
          None;
        },
      [|name|] // the dependency on which the component will re-render
    );
    <p>
      {(name ++ " is called " ++ counter->string_of_int ++ " times.")
       ->React.string}
    </p>;
  };
};

// unmounting component
module ComponentWillUnmount = {
  /*
      This lifecycle method is called to do all the cleanup like
      removing the subscriptions or event listeners on the component.
      This lifecycle method is just called before the component is unmounted.
   */
  [@react.component]
  let make = () => {
    let (counter, setCounter) = React.useState(() => 0);
    React.useEffect(() => {
      let timeoutId =
        Js.Global.setTimeout(() => setCounter(_ => counter + 1), 500);
      Some(() => Js.Global.clearTimeout(timeoutId)); // This will be called when the component will be un-mounted
    });
    ("Counter is updated " ++ counter->string_of_int ++ " times")
    ->React.string;
  };
};

[@react.component]
let make = () => {
  let (name, setName) = React.useState(() => "boo");
  <div>
    <button
      onClick={_ =>
        setName(n =>
          if (n === "boo") {
            "componentDidUpdate";
          } else {
            "boo";
          }
        )
      }>
      <ComponentDidUpdate name />
    </button>
  </div>;
  /* <ComponentWillUnmount /> </div>; */
};
