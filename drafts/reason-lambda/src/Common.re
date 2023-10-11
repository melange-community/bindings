module Context = {
  type t = {
    callbackWaitsForEmptyEventLoop: bool,
    functionVersion: string,
    functionName: string,
    memoryLimitInMB: string,
    logGroupName: string,
    logStreamName: string,
    invokedFunctionArn: string,
    awsRequestId: string,
  };
};