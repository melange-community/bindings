#!/usr/bin/env bash

# Unit test to run again an Express server defined in examples/Index.re
#
# This test uses 'curl' to query the web server and output the
# HTTP response in 'test.data'.
#
# It then makes a diff with the expected data stored in 'reference.data'

TEST_DATA=test.data

clean_previous_test() {
  rm -f $TEST_DATA
}

function print_test_title() {
  echo >> $TEST_DATA
  echo "-- $1--" >> $TEST_DATA
}

clean_previous_test;

run_cookie_test() {
  print_test_title "$1"
  curl -X "$2" --cookie "$3" http://localhost:3000$4 2>&1 >> $TEST_DATA
}

run_cookie_test 'NullCookies' 'GET' 'key=value' '/nullCookies'
run_cookie_test 'Cookies' 'GET' 'key=value' '/cookies'
run_cookie_test 'NullSignedCookies' 'GET' 'key=value' '/nullSignedCookies'

# compare test output to reference data

REFERENCE_DATA=reference.data
diff $TEST_DATA $REFERENCE_DATA
