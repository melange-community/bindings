open MSW
open ServiceWorker

let worker = setup([
  Mocks.Rest.get,
  Mocks.Rest.post,
  Mocks.Rest.postWithBody,
  Mocks.Rest.put,
  Mocks.Rest.patch,
  Mocks.Rest.delete,
  Mocks.Rest.options,
  Mocks.GraphQL.queryOk,
  Mocks.GraphQL.queryError,
  Mocks.GraphQL.mutationOk,
  Mocks.GraphQL.mutationError,
])

worker->start()

let injectToWindow = %bs.raw(`(worker, rest) => {
  window.bsmsw = {
    worker,
    rest,
  }
}`)

injectToWindow(worker, rest)
