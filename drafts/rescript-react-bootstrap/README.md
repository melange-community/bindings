
<p align="center">
  <img src="./assets/logo.svg" /> 
  <br/> <br/>
  <a href="#installation">Installation</a> • 
  <a target="_blank" href="#examples">Examples</a>
</p>

<br/><br/>

## Installation

First you need to install `react-bootstrap` as their [documentation](https://react-bootstrap.github.io/getting-started/introduction).

Basically you'll need to run these commands:

```sh
# with npm
npm add react-bootstrap@next bootstrap@5.1.0

# with yarn
yarn add react-bootstrap@next bootstrap@5.1.0
```

Then, you'll need to import `bootstrap` styles into your app:

```js
// App.js

import "bootstrap/dist/css/bootstrap.min.css";
```

Finally you can install this package running these commands:

```sh
# with npm
npm add -D @rescriptbr/react-bootstrap

# with yarn
yarn add -D @rescriptbr/react-bootstrap
```

## Examples

### Basic Form

```rescript
module Form = ReactBootstrap.Form
module Button = ReactBootstrap.Button
module Container = ReactBootstrap.Container

@react.component
let make = () => {
  <Container>
    <Form>
      <Form.Group>
        <Form.Label> {`Email`->React.string} </Form.Label>
        <Form.Control _type="email" />
      </Form.Group>

      <Form.Group>
        <Form.Label> {`Senha`->React.string} </Form.Label>
        <Form.Control _type="password" />
      </Form.Group>

      <Button size=#lg _type=#submit>
        {`Acessar`->React.string}
      </Button>
    </Form>
  </Container>
}
```
