# 0.2.0

_Released on 2020-06-23_

This is a breaking release to solve issue #1 :
- BREAKING CHANGE: `V2.Response.t` is no longer polymorphic
- BREAKING CHANGE: `statusCode` is mandatory in `V2.Response.make` (otherwise the response was not correctly 
interpreted by AWS HttpApi gateway when `body` was the only field present in the object)
- added `V2.Response.fromBody` to create a response from a JSON compliant body.


# 0.1.0

_Released on 2020-05-25_

Initial version