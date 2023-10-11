---
id: api-stack-navigator
title: Stack Navigator
sidebar_label: Stack Navigator
---

## Props

* `~initialState`: Array with initial route `array(Config.Route name)`, see [Config](get-started.html#usage)
* `~onStateChange?`: Function of type: [persistedState](api-stack-navigator.html#persistedstate)`=> unit`
* `~headerComponent?`: [Header](api-stack-navigator.html#header)
* `~headerMode?`: One of variants: `Screen | Floating`

## Screen

### ScreenProps

* `~navigation`: Navigation instance
* `~style?`: `Rebolt.Style`
* `~headerTitle?`: `string`
* `~headerStyle?`: `Rebolt.Style`
* `~headerLeft?`: [Header.props](api-stack-navigator.html#header) `=>` [returnsComponent](api-stack-navigator.html#returnscomponent)
* `~headerCenter?`: [Header.props](api-stack-navigator.html#header) `=>` [returnsComponent](api-stack-navigator.html#returnscomponent)
* `~headerRight?`: [Header.props](api-stack-navigator.html#header) `=>` [returnsComponent](api-stack-navigator.html#returnscomponent)
* `~animation?`: `Animation`

## Header

### Props

* `~headerProps`: [props](api-stack-navigator.html#headerprops)

### HeaderProps

* `screens`: array([screen](api-stack-navigator.html#screen))
* `activeScreen`: `int`
* `animatedValue`: `Animated`
* `pop`: `string => unit`

## Types

### persistedState

* `array(Config.route)` see [Config](get-started.html#usage)

### screen

* `header`: [config](api-stack-navigator.html#config)
* `animation`: `Animation`
* `key`: `string`

### config

* `style`: option(`Rebolt.Style`)
* `title`: option(`string`)
* `center`: option([returnsComponent](api-stack-navigator.html#returnscomponent))
* `left`: option([returnsComponent](api-stack-navigator.html#returnscomponent))
* `right`: option([returnsComponent](api-stack-navigator.html#returnscomponent))

### returnsComponent

* `props => ReasonReact.reactElement`
