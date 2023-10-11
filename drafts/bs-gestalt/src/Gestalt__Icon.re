[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~accessibilityLabel: string,
    ~icon: [@bs.string] [
             | `add
             | [@bs.as "add-circle"] `addCircle
             | [@bs.as "add-pin"] `addPin
             | `alert
             | [@bs.as "align-bottom-center"] `alignBottomCenter
             | [@bs.as "align-bottom-left"] `alignBottomLeft
             | [@bs.as "align-bottom-right"] `alignBottomRight
             | [@bs.as "align-bottom"] `alignBottom
             | [@bs.as "align-middle"] `alignMiddle
             | [@bs.as "align-top-center"] `alignTopCenter
             | [@bs.as "align-top-left"] `alignTopLeft
             | [@bs.as "align-top-right"] `alignTopRight
             | [@bs.as "align-top"] `alignTop
             | [@bs.as "angled-pin"] `angledPin
             | `apps
             | [@bs.as "arrow-back"] `arrowBack
             | [@bs.as "arrow-circle-down"] `arrowCircleDown
             | [@bs.as "arrow-circle-forward"] `arrowCircleForward
             | [@bs.as "arrow-circle-up"] `arrowCircleUp
             | [@bs.as "arrow-down"] `arrowDown
             | [@bs.as "arrow-forward"] `arrowForward
             | [@bs.as "arrow-up"] `arrowUp
             | [@bs.as "arrop-right"] `arrowUpRight
             | `bell
             | `camera
             | [@bs.as "camera-roll"] `cameraRoll
             | `cancel
             | [@bs.as "canonical-pin"] `canonicalPin
             | [@bs.as "color-picker"] `colorPicker
             | `check
             | [@bs.as "check-circle"] `checkCircle
             | [@bs.as "circle-outline"] `circleOutline
             | `clear
             | `clock
             | `cog
             | `compass
             | `compose
             | `crop
             | `dash
             | `download
             | `edit
             | `ellipsis
             | [@bs.as "ellipsis-circle-outline"] `ellipsisCircleOutline
             | `envelope
             | `eye
             | `facebook
             | [@bs.as "face-happy"] `faceHappy
             | [@bs.as "face-sad"] `faceSad
             | [@bs.as "face-smiley"] `faceSmiley
             | [@bs.as "fill-opaque"] `fillOpaque
             | [@bs.as "fill-transparent"] `fillTransparent
             | `filter
             | `flag
             | `flashlight
             | [@bs.as "flip-horizontal"] `flipHorizontal
             | [@bs.as "flip-vertical"] `flipVertical
             | `gif
             | `globe
             | [@bs.as "globe-checked"] `globeChecked
             | `gmail
             | [@bs.as "google-plus"] `googlePlus
             | [@bs.as "graph-bar"] `graphBar
             | `handle
             | [@bs.as "hand-pointing"] `handPointing
             | `heart
             | [@bs.as "heart-broken"] `heartBroken
             | `impressum
             | `knoop
             | `lightbulb
             | `link
             | `location
             | `lock
             | [@bs.as "logo-large"] `logoLarge
             | [@bs.as "logo-small"] `logoSmall
             | `logout
             | [@bs.as "margins-large"] `marginsLarge
             | [@bs.as "margins-medium"] `marginsMedium
             | [@bs.as "margins-small"] `marginsSmall
             | `maximize
             | `megaphone
             | `menu
             | `minimize
             | `move
             | `mute
             | [@bs.as "overlay-text"] `overlayText
             | `pause
             | `people
             | `person
             | [@bs.as "person-add"] `personAdd
             | `pin
             | [@bs.as "pin-hide"] `pinHide
             | `pinterest
             | `play
             | [@bs.as "question-mark"] `questionMark
             | `remove
             | [@bs.as "reorder-images"] `reorderImages
             | `report
             | `rotate
             | `search
             | `security
             | [@bs.as "shopping-bag"] `shoppingBag
             | `smiley
             | [@bs.as "smiley-outline"] `smileyOutline
             | `send
             | `share
             | `sound
             | `speech
             | [@bs.as "speech-ellipsis"] `speechEllipsis
             | `star
             | [@bs.as "switch-account"] `switchAccount
             | `tag
             | `terms
             | [@bs.as "text-align-left"] `textAlignLeft
             | [@bs.as "text-align-center"] `textAlignCenter
             | [@bs.as "text-align-right"] `textAlignRight
             | [@bs.as "text-all-caps"] `textAllCaps
             | [@bs.as "text-extra-small"] `textExtraSmall
             | [@bs.as "text-large"] `textLarge
             | [@bs.as "text-line-height"] `textLineHeight
             | [@bs.as "text-medium"] `textMedium
             | [@bs.as "text-sentence-case"] `textSentenceCase
             | [@bs.as "text-size"] `textSize
             | [@bs.as "text-small"] `textSmall
             | [@bs.as "text-spacing"] `textSpacing
             | [@bs.as "trash-can"] `trashCan
             | `twitter
             | [@bs.as "video-camera"] `videoCamera
             | [@bs.as "view-type-default"] `viewTypeDefault
             | [@bs.as "view-type-dense"] `viewTypeDense
             | [@bs.as "view-type-list"] `viewTypeList
           ],
    ~color: [@bs.string] [
              | `blue
              | `darkGray
              | `darkWash
              | `eggplant
              | `gray
              | `green
              | `lightGray
              | `lightWash
              | `maroon
              | `midnight
              | `navy
              | `olive
              | `orange
              | `orchid
              | `pine
              | `purple
              | `red
              | `transparent
              | `transparentDarkGray
              | `watermelon
              | `white
            ]
              =?,
    ~inline: bool=?,
    ~size: string=?,
    unit
  ) =>
  React.element =
  "Icon";
