/**
 * @jest-environment ./__tests__/support/browser-environment.js
 */

describe('Service Worker', () => {
  beforeAll(async () => {
    await page.goto('http://localhost:8080', { waitUntil: 'networkidle0' });
  });

  afterEach(async () => {
    await page.evaluate(async () => bsmsw.worker.resetHandlers());
  });

  test('runtime request handler', async () => {
    const actual = await page.evaluate(async () => {
      const { worker, rest } = bsmsw;

      worker.use(
        rest.get(
          'https://api.github.com/starred/jihchi/res-msw',
          (_req, res, ctx) => res(ctx.text('starred: jihchi/res-msw'))
        )
      );

      const res = await fetch('https://api.github.com/starred/jihchi/res-msw');
      const body = await res.text();
      return { status: res.status, body };
    });

    expect(actual).toEqual({ status: 200, body: 'starred: jihchi/res-msw' });
  });

  test('permanent override', async () => {
    const actual = await page.evaluate(async () => {
      const { worker, rest } = bsmsw;

      worker.use(
        rest.get(
          'https://api.github.com/starred/jihchi/res-msw',
          (_req, res, ctx) => res.once(ctx.text('starred: jihchi/res-msw'))
        )
      );

      const res = await fetch('https://api.github.com/starred/jihchi/res-msw');
      const body = await res.text();
      return { status: res.status, body };
    });

    expect(actual).toEqual({ status: 200, body: 'starred: jihchi/res-msw' });
  });

  test('restore handlers', async () => {
    const actual = await page.evaluate(async () => {
      const { worker, rest } = bsmsw;

      worker.use(
        rest.get(
          'https://api.github.com/repos/jihchi/res-msw',
          (_req, res, ctx) =>
            res.once(ctx.status(500), ctx.text('Internal server error'))
        )
      );
      worker.restoreHandlers();

      await fetch('https://api.github.com/repos/jihchi/res-msw');
      const res = await fetch('https://api.github.com/repos/jihchi/res-msw');
      const body = await res.text();
      return { status: res.status, body };
    });

    expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
  });

  describe('Rest', () => {
    test('get works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('https://api.github.com/repos/jihchi/res-msw');
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
    });

    test('post with request body works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('https://api.github.com/repos/jihchi/res-msw', {
          method: 'POST',
          body: JSON.stringify({ owner: "jihchi", repo: "res-msw" })
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
    })

    test('post works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('https://api.github.com/repos/jihchi/res-msw', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
    });

    test('put works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('https://api.github.com/repos/jihchi/res-msw', {
          method: 'PUT',
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
    });

    test('patch works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('https://api.github.com/repos/jihchi/res-msw', {
          method: 'PATCH',
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
    });

    test('delete works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('https://api.github.com/repos/jihchi/res-msw', {
          method: 'DELETE',
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
    });

    test('options works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('https://api.github.com/repos/jihchi/res-msw', {
          method: 'DELETE',
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({ status: 200, body: 'jihchi/res-msw' });
    });
  });

  describe('GraphQL', () => {
    test('query works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('http://localhost:8080/graphql', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            query: `
              query GetUserDetail {
                user {
                  name
                }
              }`,
            variables: {
              name: 'jihchi/res-msw',
            },
          }),
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({
        status: 200,
        body: '{"data":{"name":"jihchi/res-msw"}}',
      });
    });

    test('query error works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('http://localhost:8080/graphql', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            query: `
              query GetUserDetailError {
                user {
                  name
                }
              }`,
            variables: {
              name: 'jihchi/res-msw',
            },
          }),
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({
        status: 200,
        body:
          '{"errors":[{"message":"This is a mocked error: jihchi/res-msw","locations":[{"line":1,"column":2}]}]}',
      });
    });

    test('mutation works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('http://localhost:8080/graphql', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            query: `
              mutation Logout {
                logout {
                  session
                }
              }`,
            variables: {
              referrer: 'jihchi/res-msw',
            },
          }),
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({
        status: 200,
        body: '{"data":{"referrer":"jihchi/res-msw"}}',
      });
    });

    test('mutation error works', async () => {
      const actual = await page.evaluate(async () => {
        const res = await fetch('http://localhost:8080/graphql', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            query: `
              mutation LogoutError {
                logout {
                  session
                }
              }`,
            variables: {
              referrer: 'jihchi/res-msw',
            },
          }),
        });
        const body = await res.text();
        return { status: res.status, body };
      });

      expect(actual).toEqual({
        status: 200,
        body:
          '{"errors":[{"message":"This is a mocked error: jihchi/res-msw","locations":[{"line":1,"column":2}]}]}',
      });
    });
  });
});
