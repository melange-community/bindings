open Reanimated
open ReactNative.Style

module Styles = {
  let container = viewStyle(~flex=1., ~backgroundColor="black", ())
  let flex = viewStyle(~flex=1., ())
  let blue = viewStyle(~backgroundColor="blue", ())
  let content = viewStyle(~backgroundColor="white", ~height=dp(1000.), ())
}

@react.component
let make = () => {
  let translationY = useSharedValue(0.)

  let scrollHandler = useAnimatedScrollHandler({
    onScroll: event => {
      translationY.value = event.contentOffset.y
    },
  })

  let animatedStyles = useAnimatedStyle(() =>
    viewStyle(~transform=[translateY(~translateY=translationY.value)], ())
  )

  <View style=Styles.container>
    <Reanimated.View style={array([animatedStyles, Styles.flex, Styles.blue])} />
    <Reanimated.ScrollView style={Styles.flex} scrollEventThrottle=16 onScroll=scrollHandler>
      <View style={Styles.content}>
        <Text> {"really cool content here!"->React.string} </Text>
      </View>
    </Reanimated.ScrollView>
  </View>
}
let default = make
