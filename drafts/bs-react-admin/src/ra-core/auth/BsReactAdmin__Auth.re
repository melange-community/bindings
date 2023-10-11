[@bs.deriving jsConverter]
type actionType = [
  | [@bs.as "AUTH_LOGIN"] `AuthLogin
  | [@bs.as "AUTH_CHECK"] `AuthCheck
  | [@bs.as "AUTH_ERROR"] `AuthError
  | [@bs.as "AUTH_LOGOUT"] `AuthLogout
  | [@bs.as "AUTH_GET_PERMISSIONS"] `AuthGetPermissions
];
