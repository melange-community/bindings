type t;

module User = {
  type t;

  [@bs.get] external displayName: t => string = "displayName";
  [@bs.get] external email: t => string = "email";
  [@bs.get] external emailVerified: t => bool = "emailVerified";
  [@bs.get] external isAnonymous: t => bool = "isAnonymous";
  [@bs.get] external photoURL: t => string = "photoURL";
  [@bs.get] external refreshToken: t => string = "refreshToken";
  [@bs.get] external uid: t => string = "uid";
  [@bs.get] external phoneNumber: t => Js.Nullable.t(string) = "phoneNumber";
};

module Result = {
  type t;

  module Credentials = {
    type t;

    [@bs.get] external accessToken: t => string = "accessToken";
    [@bs.get] external idToken: t => string = "idToken";
    [@bs.get] external providerId: t => string = "providerId";
    [@bs.get] external signInMethod: t => string = "signInMethod";
  };

  module AdditionalUserInfo = {
    type t;

    module Profile = {
      type t;

      [@bs.get] external email: t => string = "email";
      [@bs.get] external familyName: t => string = "family_name";
      [@bs.get] external givenName: t => string = "given_name";
      [@bs.get] external grantedScopes: t => string = "granted_scopes";
      [@bs.get] external id: t => string = "id";
      [@bs.get] external locale: t => string = "locale";
      [@bs.get] external name: t => string = "name";
      [@bs.get] external picture: t => string = "picture";
      [@bs.get] external verifiedEmail: t => bool = "verified_email";
    };

    [@bs.get] external isNewUser: t => bool = "isNewUser";
    [@bs.get] external providerId: t => string = "providerId";
    [@bs.get] external profile: t => Profile.t = "profile";
  };

  [@bs.get] external user: t => User.t = "user";
  [@bs.get] external credentials: t => Credentials.t = "user";
  [@bs.get] external operationType: t => string = "operationType";
  [@bs.get]
  external additionalUserInfo: t => AdditionalUserInfo.t =
    "additionalUserInfo";
};

module Provider = {
  type t;

  [@bs.new] [@bs.module "firebase"] [@bs.scope "auth"]
  external google: unit => t = "GoogleAuthProvider";

  [@bs.new] [@bs.module "firebase"] [@bs.scope "auth"]
  external twitter: unit => t = "TwitterAuthProvider";
};

[@bs.send]
external signInWithEmailAndPassword:
  (t, ~email: string, ~password: string) => Js.Promise.t(Result.t) =
  "signInWithEmailAndPassword";

[@bs.send]
external signInWithPopup: (t, Provider.t) => Js.Promise.t(Result.t) =
  "signInWithPopup";

[@bs.send]
external onAuthStateChanged: (t, Js.Nullable.t(User.t) => unit) => unit =
  "onAuthStateChanged";

[@bs.send] external signOut: (t, unit) => unit = "signOut";