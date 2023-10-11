open Tape;

test("ok and notOk", t => {
  t.plan(2);
  t.ok(true);
  t.notOk(false, ~message="should be falsey");
});

test("equalStr, equalInt, and equalFloat", t => {
  t.plan(3);
  t.equalStr("foo", "foo");
  t.equalInt(12, 12, ~message="numbers are identical");
  t.equalFloat(3.14, 3.14, ~message="pi is pi");
});

test("notEqualStr, notEqualInt, and notEqualFloat", t => {
  t.plan(3);
  t.notEqualStr("foo", "bar");
  t.notEqualInt(12, 13, ~message="numbers are not the same");
  t.notEqualFloat(3.14, 3.141, ~message="precision matters!");
});

exception MyEx(string);

test("throws, throwsAndMatches, doesNotThrow, and doesNotThrowAndMatch", t => {
  t.plan(4);
  let f = () => raise(MyEx("simulated error"));
  t.throws(f);
  t.throwsAndMatches(
    f,
    "simulated",
    ~message="should throw a simulated exception",
  );
  let g = () => ();
  t.doesNotThrow(g);
  t.doesNotThrowAndMatch(
    g,
    "simulated",
    ~message="should not throw a simulated exception",
  );
});

testSkip("testSkip", t => {
  t.plan(1);
  t.skip("you won't see this");
});

test("comment, skip and endTest", t => {
  t.comment("----- this is a comment -----");
  t.skip("skipping");
  t.endTest();
});

test("timeoutAfter and endTestIfNoErr", t => {
  t.timeoutAfter(123);
  t.endTestIfNoErr(false);
});

test("pass and error", t => {
  t.plan(2);
  t.pass("workie");
  t.error(Js.Nullable.null, ~message="ok if error is null");
});

test("test with a subtest", t => {
  t.plan(1);
  t.test("here is the subtest", st => {
    st.plan(1);
    st.skip("subtest worked");
  });
});
/* comment this back in to see .fail() work */
/*
 test("THIS SHOULD FAIL: fail", t => {
   t.plan(1);
   t.fail("no workie");
 });
 */
/* comment this back in to see testOnly() work */
/*
 testOnly("ONLY RUN THIS", t => {
   t.plan(1);
   t.skip("only");
 });
 */