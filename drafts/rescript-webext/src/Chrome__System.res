module Cpu = {
  type processorUsage = {
    user: int,
    kernel: int,
    idle: int,
    total: int,
  }

  type processorInfo = {usage: processorUsage}

  type info = {
    numOfProcessors: int,
    archName: string,
    modelName: string,
    features: array<string>,
    processors: array<processorInfo>,
  }

  external getInfo: unit => promise<info> = "chrome.system.cpu.getInfo"
  external getInfoWithCallback: (info => unit) => unit = "chrome.system.cpu.getInfo"
}

module Memory = {
  type info = {
    capacity: int,
    availableCapacity: int,
  }

  external getInfo: unit => promise<info> = "chrome.system.memory.getInfo"
  external getInfoWithCallback: (info => unit) => unit = "chrome.system.memory.getInfo"
}

module Storage = {
  type unitInfo = {
    id: string,
    name: string,
    @as("type") type_: string,
    capacity: int,
  }

  external getInfo: unit => promise<array<unitInfo>> = "chrome.system.storage.getInfo"
  external getInfoWithCallback: (array<unitInfo> => unit) => unit = "chrome.system.storage.getInfo"
}
