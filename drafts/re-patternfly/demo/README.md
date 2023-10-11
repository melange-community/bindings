# re-patternfly demo

Start your project by copying this example directory and change the location
of the `@softwarefactory-project/re-patternfly` dependency in the `package.json`.

This project uses:

- `parcel` to serve and bundle the code.
- `jest` to run ReactTestUtils.

Using pnpm:

```
pnpm install --shamefully-hoist
pnpm build
pnpm test
pnpm start & pnpm serve
```

Then open browser on `http://localhost:1234`

Distribute with:

```
pnpm run dist
# Open browser in dist/
```
