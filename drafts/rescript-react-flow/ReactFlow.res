module Types = {
  type rawElement

  type rawElements = array<rawElement>

  type elementId = string

  type transform = (int, int, int)

  type position = [#left | #top | #right | #bottom]

  type arrowHeadType = [#Arrow | #ArrowClosed]

  type xyPosition = {x: int, y: int}

  type dimensions = {
    width: int,
    height: int,
  }

  type rect = {
    x: int,
    y: int,
    width: int,
    height: int,
  }

  module Node = {
    type data

    external toData: 'anything => data = "%identity"

    @deriving(abstract)
    type t = {
      id: elementId,
      position: xyPosition,
      @optional @as("type") type_: string,
      @optional
      data: data,
      @optional
      style: ReactDOM.Style.t,
      @optional
      className: string,
      @optional
      targetPosition: position,
      @optional
      sourcePosition: position,
      @optional
      isHidden: bool,
      @optional
      draggable: bool,
      @optional
      selectable: bool,
      @optional
      connectable: bool,
    }

    let makeNode = t
  }

  module Edge = {
    type data

    external toData: 'anything => data = "%identity"

    @deriving(abstract)
    type t = {
      id: elementId,
      source: elementId,
      target: elementId,
      @optional @as("type") type_: string,
      @optional
      sourceHandle: elementId,
      @optional
      targetHandle: elementId,
      @optional
      label: string,
      @optional
      labelStyle: ReactDOM.Style.t,
      @optional
      labelShowBg: bool,
      @optional
      labelBgStyle: ReactDOM.Style.t,
      @optional
      labelBdPadding: (int, int),
      @optional
      labelBgBorderRadius: int,
      @optional
      style: ReactDOM.Style.t,
      @optional
      animated: bool,
      @optional
      arrowHeadType: arrowHeadType,
      @optional
      isHidden: bool,
      @optional
      data: data,
      @optional
      className: string,
    }

    let makeEdge = t
  }

  type connection = {
    source: option<elementId>,
    target: option<elementId>,
    sourceHandle: option<elementId>,
    targetHandle: option<elementId>,
  }

  type connectionLineType = [#default | #straight | #step | #smoothstep]

  type connectionLineComponentProps = {
    sourceX: int,
    sourceY: int,
    sourcePosition: option<position>,
    targetX: int,
    targetY: int,
    targetPosition: option<position>,
    connectionLineStyle: option<ReactDOM.Style.t>,
    connectionLineType: connectionLineType,
  }

  type connectionLineComponent = React.componentLike<connectionLineComponentProps, React.element>

  type edgeOrConnection = Connection(connection) | Edge(Edge.t)

  type flowElement = Node(Node.t) | Edge(Edge.t)

  type elements = array<flowElement>

  type fitViewParams = {
    padding: option<int>,
    includeHiddenNodes: option<bool>,
  }

  type flowTransform = {
    x: int,
    y: int,
    zoom: int,
  }

  type fitViewFunc = fitViewParams => unit

  type projectFunc = (~position: xyPosition) => xyPosition

  type flowExportObj = {
    elements: elements,
    position: (int, int),
    zoom: int,
  }

  type toObjFunc = unit => flowExportObj

  type onLoadParams = {
    zoomIn: unit => unit,
    zoomOut: unit => unit,
    zoomTo: (~zoomLevel: int) => unit,
    fitView: fitViewFunc,
    project: projectFunc,
    getElements: unit => elements,
    setTransform: (~transform: flowTransform) => unit,
    toObject: toObjFunc,
  }

  type onConnectStartParams = {
    nodeId: option<elementId>,
    handleId: option<elementId>,
    handleType: [#source | #target],
  }

  type translateExtent = ((int, int), (int, int))

  type connectionMode = [#strict | #loose]

  type selectionRect = {
    x: int,
    y: int,
    width: int,
    height: int,
    startX: int,
    startY: int,
    draw: bool,
  }

  type onConnectFunc = connection => unit
  type onConnectStartFunc = (ReactEvent.Mouse.t, onConnectStartParams) => unit
  type onConnectStopFunc = ReactEvent.Mouse.t => unit
  type onConnectEndFunc = ReactEvent.Mouse.t => unit

  module Handle = {
    type handleType = [#source | #target]

    type onConnectFunc = connection => unit

    type isValidConnectionFunc = connection => bool
  }

  type reactFlowState = {
    width: int,
    height: int,
    transform: transform,
    nodes: array<Node.t>,
    edges: array<Edge.t>,
    selectedElements: Js.nullable<elements>,
    selectedNodesBox: rect,
    minZoom: int,
    maxZoom: int,
    translateExtent: translateExtent,
    nodeExtent: translateExtent,
    nodesSelectionActive: bool,
    selectionActive: bool,
    userSelectionRect: selectionRect,
    connectionNodeId: Js.nullable<elementId>,
    connectionHandleId: Js.nullable<elementId>,
    connectionHandleType: Js.nullable<Handle.handleType>,
    connectionPosition: xyPosition,
    connectionMode: connectionMode,
    snapToGrid: bool,
    snapGrid: (int, int),
    nodesDraggable: bool,
    nodesConnectable: bool,
    elementsSelectable: bool,
    multiSelectionActive: bool,
    reactFlowVersion: string,
    onConnect: option<onConnectFunc>,
    onConnectStart: option<onConnectStartFunc>,
    onConnectStop: option<onConnectStopFunc>,
    onConnectEnd: option<onConnectEndFunc>,
  }

  type updateNodeInternals = elementId => unit

  type nodePosUpdate = {
    id: elementId,
    pos: xyPosition,
  }

  type nodeDiffUpdate = {
    id: option<elementId>,
    diff: option<xyPosition>,
    isDragging: option<bool>,
  }

  type setConnectionId = {
    connectionNodeId: Js.nullable<elementId>,
    connectionHandleid: Js.nullable<elementId>,
    connectionHandleType: Js.nullable<Handle.handleType>,
  }

  type zoomPanHelperFunctions = {
    zoomIn: unit => unit,
    zoomOut: unit => unit,
    zoomTo: int => unit,
    transform: flowTransform => unit,
    fitView: fitViewFunc,
    setCenter: (~x: int, ~y: int, ~zoom: int=?) => unit,
    fitBounds: (~bounds: rect, ~padding: int=?) => unit,
    project: xyPosition => xyPosition,
    initialized: bool,
  }

  module MiniMap = {
    type stringFunc = Node.t => string
  }

  module Action = {
    type setOnConnect = onConnectFunc => unit

    type setOnConnectStart = onConnectStartFunc => unit

    type setOnConnectStop = onConnectStopFunc => unit

    type setOnConnectEnd = onConnectEndFunc => unit

    type setElements = rawElements => unit

    type updateNodePos = nodePosUpdate => unit

    type updateNodePosDiff = nodeDiffUpdate => unit

    type setUserSelection = xyPosition => unit

    type updateUserSelection = xyPosition => unit

    type unsetUserSelection = unit => unit

    type setSelection = bool => unit

    type unsetNodesSelection = unit => unit

    type resetSelectedElements = unit => unit

    type setSelectedElements = rawElements => unit

    type addSelectedElements = rawElements => unit

    type updateTransform = transform => unit

    type updateSize = dimensions => unit

    type setMinZoom = int => unit

    type setMaxZoom = int => unit

    type setTranslateExtent = translateExtent => unit

    type setConnectionPosition = xyPosition => unit

    type setConnectionNodeId = setConnectionId => unit

    type setSnapToGrid = bool => unit

    type setSnapGrid = (int, int) => unit

    type setInteractive = bool => unit

    type setNodesDraggable = bool => unit

    type setNodesConnectable = bool => unit

    type setElementsSelectable = bool => unit

    type setMultiSelectionActive = bool => unit

    type setConnectionMode = connectionMode => unit

    type setNodeExtent = translateExtent => unit

    type t = {
      setOnConnect: setOnConnect,
      setOnConnectStart: setOnConnectStart,
      setOnConnectStop: setOnConnectStop,
      setOnConnectEnd: setOnConnectEnd,
      setElements: setElements,
      updateNodePos: updateNodePos,
      updateNodePosDiff: updateNodePosDiff,
      setuserSelection: setUserSelection,
      updateUserSelection: updateUserSelection,
      unsetUserSelection: unsetUserSelection,
      setSelection: setSelection,
      unsetNodesSelection: unsetNodesSelection,
      resetSelectedElements: resetSelectedElements,
      setSelectedElements: setSelectedElements,
      addSelectedElements: addSelectedElements,
      updateTransform: updateTransform,
      updateSize: updateSize,
      setMinZoom: setMinZoom,
      setMaxZoom: setMaxZoom,
      setTranslateExtent: setTranslateExtent,
      setConnectionPosition: setConnectionPosition,
      setConnectionNodeId: setConnectionNodeId,
      setSnapToGrid: setSnapToGrid,
      setSnapGrid: setSnapGrid,
      setInteractive: setInteractive,
      setNodesDraggable: setNodesDraggable,
      setNodesConnectable: setNodesConnectable,
      setElementsSelectable: setElementsSelectable,
      setMultiSelectionActive: setMultiSelectionActive,
      setConnectionMode: setConnectionMode,
      setNodeExtent: setNodeExtent,
    }
  }

}
module Node = Types.Node
module Edge = Types.Edge

module Utils = {
  open Types

  @module("react-flow-renderer")
  external isEdge: rawElement => bool = "isEdge"

  @module("react-flow-renderer")
  external isNode: rawElement => bool = "isNode"

  @module("react-flow-renderer")
  external jsRemoveElements: (rawElements, rawElements) => rawElements = "removeElements"

  @module("react-flow-renderer")
  external jsAddEdge: (rawElement, rawElements) => rawElements = "addEdge"

  @module("react-flow-renderer")
  external jsUpdateEdge: (rawElement, rawElement, rawElements) => rawElements = "updateEdge"

  @module("react-flow-renderer")
  external jsGetOutgoers: (rawElement, rawElements) => rawElements = "getOutgoers"

  @module("react-flow-renderer")
  external jsGetIncomers: (rawElement, rawElements) => rawElements = "getIncomers"

  @module("react-flow-renderer")
  external jsGetConnectedEdges: (rawElements, rawElements) => rawElements = "getConnectedEdges"

  @module("react-flow-renderer")
  external getTransformForBounds: (
    ~bounds: rect,
    ~width: float,
    ~height: float,
    ~minZoom: float,
    ~maxZoom: float,
    ~padding: float=?,
  ) => transform = "getTransformForBounds"

  external rawToNode: rawElement => Node.t = "%identity"

  external rawToEdge: rawElement => Edge.t = "%identity"

  external elemToRaw: 'a => rawElement = "%identity"

  let unwrapElem = elem => {
    switch elem {
    | Node(elem) => elemToRaw(elem)
    | Edge(elem) => elemToRaw(elem)
    }
  }

  let elementsToRaw = (elems): rawElements => {
    elems->Belt.Array.map(unwrapElem)
  }

  let rawToElements = rawElements => {
    rawElements->Belt.Array.map(elem => {
      if isNode(elem) {
        Node(rawToNode(elem))
      } else {
        Edge(rawToEdge(elem))
      }
    })
  }

  let addEdge = (rawElement, elements) => {
    rawToElements(jsAddEdge(rawElement, elementsToRaw(elements)))
  }

  let removeElements = (rawElements, elements) => {
    rawToElements(jsRemoveElements(rawElements, elementsToRaw(elements)))
  }

  let updateEdge = (~oldEdge: Edge.t, ~newConnection: connection, ~elems: elements) => {
    rawToElements(jsUpdateEdge(elemToRaw(oldEdge), elemToRaw(newConnection), elementsToRaw(elems)))
  }

  let getOutgoers = (~node: Node.t, ~elems: elements): array<Node.t> => {
    jsGetOutgoers(elemToRaw(node), elementsToRaw(elems))->Belt.Array.map(rawToNode)
  }

  let getIncomers = (~node: Node.t, ~elems: elements): array<Node.t> => {
    jsGetIncomers(elemToRaw(node), elementsToRaw(elems))->Belt.Array.map(rawToNode)
  }

  let getConnectedEdges = (~nodes: array<Node.t>, ~edges: array<Edge.t>): array<Edge.t> => {
    jsGetConnectedEdges(
      elementsToRaw(nodes->Belt.Array.map(n => Node(n))),
      elementsToRaw(edges->Belt.Array.map(e => Edge(e))),
    )->Belt.Array.map(rawToEdge)
  }
}

@module("react-flow-renderer") @react.component
external make: (
  ~elements: Types.rawElements,
  ~children: React.element=?,
  ~onElementsClick: (~event: Dom.mouseEvent=?, ~element: Types.rawElement=?) => unit=?,
  ~snapToGrid: bool=?,
  ~onConnect: Types.rawElement => unit=?,
  ~onElementsRemove: Types.rawElements => unit=?,
  ~onLoad: Types.onLoadParams => unit=?,
  ~snapGrid: (int, int)=?,
  ~nodeTypes: 'weakNodeType=?,
  ~edgeTypes: 'weakEdgeType=?,
  ~connectionLineComponent: Types.connectionLineComponent=?,
  ~selectNodesOnDrag: bool=?,
  ~className: string=?,
  ~onConnectStart: Types.onConnectStartFunc=?,
  ~onConnectStop: Types.onConnectStopFunc=?,
  ~onConnectEnd: Types.onConnectEndFunc=?,
) => React.element = "default"

module Handle = {
  @module("react-flow-renderer") @react.component
  external make: (
    @as("type") ~_type: Types.Handle.handleType,
    ~position: Types.position,
    ~isConnectable: bool=?,
    ~onConnect: Types.Handle.onConnectFunc=?,
    ~isValidConnection: Types.connection => bool=?,
    ~id: Types.elementId=?,
    ~className: string=?,
    ~style: ReactDOM.Style.t=?,
    ~children: React.element=?,
  ) => React.element = "Handle"
}

module MiniMap = {
  @module("react-flow-renderer") @react.component
  external make: (
    ~nodeColor: Types.MiniMap.stringFunc=?,
    ~nodeStrokeColor: Types.MiniMap.stringFunc=?,
    ~nodeClassName: Types.MiniMap.stringFunc=?,
    ~nodeBorderRadius: int=?,
    ~nodeStrokeWidth: int=?,
    ~maskColor: string=?,
  ) => React.element = "MiniMap"
}

module Controls = {
  @module("react-flow-renderer") @react.component
  external make: (
    ~showZoom: bool=?,
    ~showFitView: bool=?,
    ~showInteractive: bool=?,
    ~fitViewParams: Types.fitViewParams=?,
    ~onZoomIn: unit => unit=?,
    ~onZoomOut: unit => unit=?,
    ~onFitView: unit => unit=?,
    ~onInteractiveChange: (~interactiveStatus: bool) => unit=?,
  ) => React.element = "Controls"
}

module Background = {
  type backgroundVariant = [#lines | #dots]

  @module("react-flow-renderer") @react.component
  external make: (
    ~variant: backgroundVariant=?,
    ~gap: int=?,
    ~color: string=?,
    ~size: int=?,
  ) => React.element = "Background"
}

module Provider = {
  @module("react-flow-renderer") @react.component
  external make: (~children: React.element) => React.element = "ReactFlowProvider"
}

module EdgeText = {
  @module("react-flow-renderer") @react.component
  external make: (
    ~x: int,
    ~y: int,
    ~label: React.element=?,
    ~labelStyle: ReactDOM.Style.t=?,
    ~labelShowBg: bool=?,
    ~labelBgStyle: ReactDOM.Style.t=?,
    ~labelBgPadding: (int, int)=?,
    ~labelBgBorderRadius: int=?,
  ) => React.element = "EdgeText"
}

@module("react-flow-renderer")
external useStoredAction: unit => Types.Action.t = "useStoredAction"

@module("react-flow-renderer")
external useStoreState: unit => Types.reactFlowState = "useStoreState"

@module("react-flow-renderer")
external useZoomPanHelper: unit => Types.zoomPanHelperFunctions = "useZoomPanHelper"

@module("react-flow-renderer")
external useUpdateNodeInternals: unit => Types.updateNodeInternals = "useUpdatenodeInternals"

@module("react-flow-renderer")
external getBezierPath: (
  ~sourceX: int,
  ~sourceY: int,
  ~sourcePosition: Types.position=?,
  ~targetX: int,
  ~targetY: int,
  ~targetPosition: Types.position=?,
  ~centerX: int=?,
  ~centerY: int=?,
) => React.element = "getBezierPath"

@module("react-flow-renderer")
external getSmoothStepPath: (
  ~sourceX: int,
  ~sourceY: int,
  ~sourcePosition: Types.position=?,
  ~targetX: int,
  ~targetY: int,
  ~targetPosition: Types.position=?,
  ~borderRadius: int=?,
  ~centerX: int=?,
  ~centerY: int=?,
) => string = "getSmoothStepPath"

@module("react-flow-renderer")
external getMarkerEnd: (~arrowHeadType: Types.arrowHeadType=?, ~markerEndId: string=?) => string =
  "getMarkerEnd"

@module("react-flow-renderer")
external getCenter: (
  ~sourceX: int,
  ~sourceY: int,
  ~targetX: int,
  ~targetY: int,
  ~sourcePosition: Types.position=?,
  ~targetPosition: Types.position=?,
) => (int, int, int, int) = "getCenter"
