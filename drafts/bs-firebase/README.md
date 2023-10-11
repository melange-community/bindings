# bs-firebase

## Setup

Install module
```bash
yarn add @dck/bs-firebase
```

Add it to `bsconfig.json`
```bash
{
  "bs-dependencies": [
    ...,
    "@dck/bs-firebase"
  ]
}
```

## Initialize app

```reason
[@bs.module]
external firebaseConfig: firebaseConfig = "./config/firebase-config.json";

firebase->initializeApp(firebaseConfig);
```

## Authentication

```reason
open BsFirebase;

firebase
->auth()
->Auth.onAuthStateChanged(user => {
  switch (user->Js.Nullable.toOption) {
  | None => ()
  | Some(u) =>
    Js.log3(
      u->Auth.User.uid,
      u->Auth.User.email,
      u->Auth.User.displayName,
    )
  }
});

let signInWithGoogle = () => firebase->auth()->Auth.signInWithPopup(Auth.Provider.google());
let signInWithEmailAndPassword = (~email, ~password) => firebase->auth()->Auth.signInWithEmailAndPassword(~email, ~password);
let signOut = () => firebase->auth()->Auth.signOut();
```

## Firestore

#### Fetch all

```reason
let fetchAll = () => {
  firebase
    ->firestore()
    ->Firestore.collection("mycollection")
    ->Firestore.Collection.get()
    |> Js.Promise.then_(querySnapshot =>
        querySnapshot
        ->Firestore.QuerySnapshot.docs
        ->Belt.Array.map(snapshot => {
            let data = snapshot->Firestore.DocRef.data();
            Js.log(snapshot->Firestore.DocRef.id);
            Js.log(data##someAttribute);

            data;
          })
        |> Js.Promise.resolve
      );
};
```

#### Fetch by id

```reason
let fetchItem = (id) => {
  firebase
  ->firestore()
  ->Firestore.collection("mycollection")
  ->Firestore.Collection.doc(id)
  ->Firestore.Collection.Doc.get()
  |> Js.Promise.then_(doc => {
       let data = doc->Firestore.DocRef.data();
       Js.log(data);

       data;
     });
}
```

#### Create

```reason
let create = (title, description) =>
  firebase
  ->firestore()
  ->Firestore.collection("collection")
  ->Firestore.Collection.add({
    "title": title,
    "description": description,
  });
```

#### Update

```reason
let update = (id, title) =>
  firebase
  ->firestore()
  ->Firestore.collection("collection")
  ->Firestore.Collection.doc(id)
  ->Firestore.Collection.Doc.set({
    "title": title
  });
```

#### Remove

```reason
let remove = (id: string) =>
  firebase
  ->firestore()
  ->Firestore.collection("mycollection")
  ->Firestore.Collection.doc(id)
  ->Firestore.Collection.Doc.delete();
```
