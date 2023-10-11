# bs-react-dropzone

[![Build Status](https://travis-ci.com/erykpiast/bs-react-dropzone.svg?branch=master)](https://travis-ci.com/erykpiast/bs-react-dropzone)
[![dependencies Status](https://david-dm.org/erykpiast/bs-react-dropzone/status.svg)](https://david-dm.org/erykpiast/bs-react-dropzone)
[![devDependencies Status](https://david-dm.org/erykpiast/bs-react-dropzone/dev-status.svg)](https://david-dm.org/erykpiast/bs-react-dropzone?type=dev)
[![peerDependencies Status](https://david-dm.org/erykpiast/bs-react-dropzone/peer-status.svg)](https://david-dm.org/erykpiast/bs-react-dropzone?type=peer)
[![Greenkeeper badge](https://badges.greenkeeper.io/erykpiast/bs-react-dropzone.svg)](https://greenkeeper.io/)

ReasonML bindings for [react-dropzone](https://github.com/react-dropzone/react-dropzone) library.

## Installation

```
npm i --save bs-react-dropzone react-dropzone
```

Then add `bs-react-dropzone` as a dependency to `bsconfig.json`.

## Usage

```reasonml
[@react.component]
let make = () => {
  <ReactDropzone
    accept={ReactDropzone.Single("application/json")}
    multiple=true
    onDrop={(acceptedFiles, _) =>
      Js.log(("these files were dropped", acceptedFiles))
    }>
    {({getInputProps, getRootProps}) => {
      let inputProps = getInputProps();
      let rootProps = getRootProps();

      <div
        onBlur={rootProps.onBlur}
        onDragEnter={rootProps.onDragEnter}
        onDragLeave={rootProps.onDragLeave}
        onDragOver={rootProps.onDragOver}
        onDragStart={rootProps.onDragStart}
        onDrop={rootProps.onDrop}
        onFocus={rootProps.onFocus}
        onKeyDown={rootProps.onKeyDown}
        ref={ReactDOMRe.Ref.callbackDomRef(rootProps.ref)}
        tabIndex={rootProps.tabIndex}>
        <div> {"Drop files here" |> React.string} </div>
        <input
          autoComplete={inputProps.autoComplete}
          onChange={inputProps.onChange}
          onClick={inputProps.onClick}
          ref={ReactDOMRe.Ref.callbackDomRef(inputProps.ref)}
          style={inputProps.style}
          tabIndex={inputProps.tabIndex}
          type_={inputProps.type_}
          multiple={inputProps.multiple}
        />
      </div>;
    }}
  </ReactDropzone>;
};
```

### JSX 2

The package provides fallback for projects using older version of JSX syntax.

```reasonml
let component = ReasonReact.statelessComponent("Demo");

let make = () => {
  ...component,
  render: (_self) => {
    <ReactDropzone.Jsx2
      accept={ReactDropzone.Single("application/json")}
      multiple=true
      onDrop={(acceptedFiles, _) =>
        Js.log(("these files were dropped", acceptedFiles))
      }>
      ...{({getInputProps, getRootProps}) => {
        let inputProps = getInputProps();
        let rootProps = getRootProps();

        <div
          onBlur={rootProps.onBlur}
          onDragEnter={rootProps.onDragEnter}
          onDragLeave={rootProps.onDragLeave}
          onDragOver={rootProps.onDragOver}
          onDragStart={rootProps.onDragStart}
          onDrop={rootProps.onDrop}
          onFocus={rootProps.onFocus}
          onKeyDown={rootProps.onKeyDown}
          ref={rootProps.ref}
          tabIndex={rootProps.tabIndex}>
          <div> {"Drop files here" |> React.string} </div>
          <input
            autoComplete={inputProps.autoComplete}
            onChange={inputProps.onChange}
            onClick={inputProps.onClick}
            ref={inputProps.ref}
            style={inputProps.style}
            tabIndex={inputProps.tabIndex}
            type_={inputProps.type_}
            multiple={inputProps.multiple}
          />
        </div>;
      }}
    </ReactDropzone.Jsx2>;
  }
};
```

### Hooks

Hooks are not supported right now. There is [an issue open for that](https://github.com/erykpiast/bs-react-dropzone/issues/3). PRs are welcome!
