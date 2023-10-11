# Revision history for bs-zarith

## 3.2.0 -- 2022-12-01
* Drop print functions so it builds with the latest Rescript. These were likely seldomed used.

## 3.1.0 -- 2020-10-25

* Drop support for Nativeint. It is not supported by bs-platform 8.3.0 and above.

## 3.0.0 -- 2020-06-12

* New module Bigfloat. Experimental status.
* New module Natural.

## 2.0.0 -- 2020-06-04

* Support unsigned integers.

## 1.1.0 -- 2020-02-20

* Fix Bigint multiplication bug.

## 1.0.1 -- 2018-04-23

* Add warnings "+A-44" to bsconfig.json.

## 1.0.0 -- 2018-06-21

* Add Bigint module for arbitrary length integers.
* Add Z module for combining the operators of all integer types (int, Int32.t, Nativeint.t, Int64.t and Bigint.t).
* Add Q module for rational integers.
