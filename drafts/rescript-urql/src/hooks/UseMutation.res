type executeMutationJs<'dataJs> = (
  Js.Json.t,
  Types.partialOperationContext,
) => Js.Promise.t<Types.operationResultJs<'dataJs>>

type executeMutation<'variables, 'data> = (
  ~additionalTypenames: array<string>=?,
  ~fetchOptions: Fetch.requestInit=?,
  ~fetch: (string, Fetch.requestInit) => Js.Promise.t<Fetch.response>=?,
  ~requestPolicy: Types.requestPolicy=?,
  ~url: string=?,
  ~meta: Types.operationDebugMeta=?,
  ~suspense: bool=?,
  ~preferGetMethod: bool=?,
  'variables,
) => Js.Promise.t<Types.operationResult<'data>>

type useMutationResponseJs<'dataJs> = (
  Types.Hooks.hookResponseJs<'dataJs>,
  executeMutationJs<'dataJs>,
)

type useMutationResponse<'variables, 'data> = (
  Types.Hooks.hookResponse<'data>,
  executeMutation<'variables, 'data>,
)

@module("urql")
external useMutationJs: string => useMutationResponseJs<'dataJs> = "useMutation"

// The useMutation hook.
let useMutation:
  type data variables. (
    ~mutation: module(Types.Operation with type t = data and type t_variables = variables),
  ) => useMutationResponse<variables, data> =
  (~mutation as module(Mutation)) => {
    let query = Mutation.query
    let parse = Mutation.parse

    let (stateJs, executeMutationJs) = useMutationJs(query)

    let state = React.useMemo2(
      () => Types.Hooks.hookResponseToReScript(~response=stateJs, ~parse),
      (stateJs, parse),
    )

    let executeMutation = React.useMemo1(
      (
        (),
        ~additionalTypenames=?,
        ~fetchOptions=?,
        ~fetch=?,
        ~requestPolicy=?,
        ~url=?,
        ~meta=?,
        ~suspense=?,
        ~preferGetMethod=?,
        variables,
      ) => {
        let ctx = Types.partialOperationContext(
          ~additionalTypenames?,
          ~fetchOptions?,
          ~fetch?,
          ~url?,
          ~requestPolicy=?requestPolicy->Belt.Option.map(Types.requestPolicyToJs),
          ~meta?,
          ~suspense?,
          ~preferGetMethod?,
          (),
        )

        executeMutationJs(
          {
            open Mutation
            variables->serializeVariables->variablesToJson
          },
          ctx,
        )->{
          open Js.Promise
          then_(response => Types.operationResultToReScript(~response, ~parse)->resolve, _)
        }
      },
      [executeMutationJs],
    )

    (state, executeMutation)
  }
