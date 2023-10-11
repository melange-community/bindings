// export { default as Observable } from 'zen-observable';
module Observable = ApolloClient__ZenObservable.Observable
// export { isReference, makeReference } from './utilities/graphql/storeUtils.js';
// export { ApolloLink } from './link/core/ApolloLink.js';
module ApolloLink = ApolloClient__Link_Core_ApolloLink
// export { execute } from './link/core/execute.js';
let execute = ApolloClient__Link_Core_ApolloLink.Static.execute
// export { ApolloError, isApolloError } from './errors/ApolloError.js';
module ApolloError = ApolloClient__Errors_ApolloError
// export { NetworkStatus } from './core/networkStatus.js';
module NetworkStatus = ApolloClient__Core_NetworkStatus.NetworkStatus
// export { ObservableQuery } from './core/ObservableQuery.js';
// export { serializeFetchParameter } from './link/http/serializeFetchParameter.js';
// export { selectURI } from './link/http/selectURI.js';
// export { throwServerError } from './link/utils/throwServerError.js';
// export { parseAndCheckHttpResponse } from './link/http/parseAndCheckHttpResponse.js';
// export { checkFetcher } from './link/http/checkFetcher.js';
// export { fallbackHttpConfig, selectHttpOptionsAndBody } from './link/http/selectHttpOptionsAndBody.js';
// export { createSignalIfSupported } from './link/http/createSignalIfSupported.js';
// export { fromError } from './link/utils/fromError.js';
// export { createHttpLink } from './link/http/createHttpLink.js';
let createHttpLink = ApolloClient__Link_Http_CreateHttpLink.createHttpLink
// export { HttpLink } from './link/http/HttpLink.js';
module HttpLink = ApolloClient__Link_Http_HttpLink
// export { ApolloClient } from './ApolloClient.js';
module ApolloClient = ApolloClient__Core_ApolloClient
// export { ApolloCache } from './cache/core/cache.js';
module ApolloCache = ApolloClient__Cache_Core_Cache.ApolloCache
// export { Cache } from './cache/core/types/Cache.js';
// export { MissingFieldError } from './cache/core/types/common.js';
// export { defaultDataIdFromObject } from './cache/inmemory/policies.js';
let defaultDataIdFromObject = ApolloClient__Cache_InMemory_Policies.defaultDataIdFromObject
// export { InMemoryCache } from './cache/inmemory/inMemoryCache.js';
module InMemoryCache = ApolloClient__Cache_InMemory_InMemoryCache
// export { empty } from './link/core/empty.js';
let empty = ApolloClient__Link_Core_ApolloLink.Static.empty
// export { from } from './link/core/from.js';
let from = ApolloClient__Link_Core_ApolloLink.Static.from
// export { split } from './link/core/split.js';
let split = ApolloClient__Link_Core_ApolloLink.Static.split
// export { concat } from './link/core/concat.js';
let concat = ApolloClient__Link_Core_ApolloLink.Static.concat
// export { toPromise } from './link/utils/toPromise.js';
// export { fromPromise } from './link/utils/fromPromise.js';
// export { default as gql } from 'graphql-tag';
let gql = ApolloClient__GraphqlTag.gql
// export { disableExperimentalFragmentVariables, disableFragmentWarnings, enableExperimentalFragmentVariables, resetCaches } from './core/index.js';
// export { getApolloContext, resetApolloContext } from './react/context/ApolloContext.js';
// export { ApolloProvider } from './react/context/ApolloProvider.js';
module ApolloProvider = ApolloClient__React_Context_ApolloProvider
// export { ApolloConsumer } from './react/context/ApolloConsumer.js';
// export { DocumentType, operationName, parser } from './react/parser/parser.js';
// export { useQuery } from './react/hooks/useQuery.js';
let useQuery = ApolloClient__React_Hooks_UseQuery.useQuery
// export { useLazyQuery } from './react/hooks/useLazyQuery.js';
// export { useMutation } from './react/hooks/useMutation.js';
let useMutation = ApolloClient__React_Hooks_UseMutation.useMutation
// export { useSubscription } from './react/hooks/useSubscription.js';
let useSubscription = ApolloClient__React_Hooks_UseSubscription.useSubscription
// export { useApolloClient } from './react/hooks/useApolloClient.js';
// export { RenderPromises } from './react/ssr/RenderPromises.js';

module Core = ApolloClient__Core
module Cache = ApolloClient__Cache
module Errors = ApolloClient__Errors
module Link = ApolloClient__Link
module React = ApolloClient__React
module Utilities = ApolloClient__Utilities
module Testing = ApolloClient__Testing
