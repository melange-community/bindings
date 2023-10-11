# bs-react-admin
[BuckleScript](https://bucklescript.github.io/) bindings for [react-admin](https://github.com/marmelab/react-admin).

## Status

🚧 This is a WIP, not everything is supported yet. 🚧

Feel free to create an issue or PR if you find anything missing.

Also, many of the types are overly permissive in an attempt to just get
react-admin to work with ReasonML projects. Hopefully, these types will be much
stricter in future releases.

## Installation


```
npm install --save @ctbucha/bs-react-admin
```

Then add `@ctbucha/bs-react-admin` to `bs-dependencies` in your `bsconfig.json`:

```
{
  ...
  "bs-dependencies": ["@ctbucha/bs-react-admin"]
}
```

## Usage

```reason
/* App.re */
let component = ReasonReact.statelessComponent("App");

let myHttpClient = (url, _params) => {
  let headersDict = Js.Dict.empty();
  Js.Dict.set(headersDict, "Accept", "application/json");

  let headers = 
    headersDict |> Fetch.HeadersInit.makeWithDict |> Fetch.Headers.makeWithInit;

  BsReactAdmin.FetchUtils.headersSet(params, headers);

  BsReactAdmin.FetchUtils.fetchJson(url, params);
};

let dataProvider = 
  BsRaDataJsonServer.getRaDataJsonServer(
    ~apiUrl="http://jsonplaceholder.typicode.com",
    ~httpClient=myHttpClient,
    (),
  );

let make = _children => { 
  ...component,
  render: _self => 
    BsReactAdmin.(
      <div>
        <Admin dataProvider>
          <Resource name="posts" list=PostList.toReactJs />
        </Admin>
      </div>
    ),  
    };
```

```reason
/* PostList.re */
let component = ReasonReact.statelessComponent("PostList");

let make = (props, _children) => { 
  ...component,
  render: _self => 
    BsReactAdmin.(
      <div>
        <List props>
          <Datagrid>
            <TextField source="id" />
            <TextField source="title" />
            <TextField source="body" />
          </Datagrid>
        </List>
      </div>
    ),
};

/* Need to pass this to Resource as a ReactJS component instead of a ReasonReact
 * component since react-admin handles this as a ReactJS component.
 */
let toReactJs = 
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps, [||]));
```
