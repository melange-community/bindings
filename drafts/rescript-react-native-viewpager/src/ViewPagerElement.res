type element
type ref = React.ref<Js.nullable<element>>

include ViewPagerMethods.Make({
  type t = element
})
