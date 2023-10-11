open ReSpectacle;

let rs = React.string;

let colorConfig = Theme.colors(~primary="white", ~quaternary="black", ());
let fontConfig = Theme.fonts();
let theme = Theme.create(colorConfig, fontConfig);
let textSize = "30";
let size = 4;
let style = tableStyle(~border="1px solid black", ());
let customStyle = SyntaxHighlighter.textStyle(~fontSize="1em", ~lineHeight="0.75", ());
let textStyle = SyntaxHighlighter.textStyle(~fontSize="inherit", ~lineHeight="inherit", ());
let codeTagProps = SyntaxHighlighter.codeStyle(~style=textStyle);

let whatIsReason: string = [%raw {| require('./images/whatIsReason1.png')|}];
let whyReason3: string = [%raw {| require('./images/whyReason3.png')|}];
let whyReason1: string = [%raw {| require('./images/wilsonCurve.jpg')|}];
let whyReason2: string = [%raw {| require('./images/whyReason2.png')|}];

[@react.component]
let make = (_) => {
    <Deck theme>
        <Slide>
            <Heading size>{rs("Type Inference and ReasonML")}</Heading>
            <List>
                <ListItem textSize>{rs("What is Type Inference?")}</ListItem>
                <ListItem textSize>{rs("Type inference programming language examples")}</ListItem>
                <ListItem textSize>{rs("What is ReasonML?")}</ListItem>
                <ListItem textSize>{rs("A Taste of ReasonML")}</ListItem>
            </List>
        </Slide>
        <Slide>
            <Heading size>{rs("Static, Dynamic, Gradual Typing")}</Heading>
            <Table style>
                <Thead style><Th style>{rs("Typing Strategy")}</Th><Th style>{rs("Description")}</Th><Th style>{rs("Languages")}</Th></Thead>
                <Tr style><Td style>{rs("Static")}</Td><Td style>{rs("detect type constraints violations before runtime")}</Td><Td style>{rs("C, C++, Java, GO, Haskell, Reasonml")}</Td></Tr>
                <Tr style><Td style>{rs("Dynamic")}</Td><Td style>{rs("detect type errors during runtime")}</Td><Td style>{rs("Javascript, Python, Ruby")}</Td></Tr>
                <Tr style><Td style>{rs("Gradual")}</Td><Td style>{rs("optional type constraints that will caught before runtime")}</Td><Td style>{rs("Typescript, Python MyPy, Php hack")}</Td></Tr>
            </Table>
        </Slide>
        <Slide>
            <Heading size>{rs("Gradual Typing and Soft Typing")}</Heading>
            <Text textSize>{rs(
{js|Mixing type annotations with any is called Gradual Typing,
defaulting/prefering type any is called Soft Typing|js}
            )}</Text>
        </Slide>
        <Slide>
            <Heading size>{rs("Strong vs Weak Typing")}</Heading>
            <Text textSize>{rs(
{js|I have seen many people confuse Static Typing with Strong Typing,
but they are independant C is statically typed but has weak typing, Python is Dynamically typed but is strongly type.|js}
            )}</Text>
        </Slide>
        <Slide>
            <Heading size>{rs("C Example of Weak Typing")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="c">
{rs({js|#include <stdio.h>

int main() {
    /* treat int as char */
    char c = 8 + '0';
    /* treat char as int */
    printf("%d\\n", c);
    /* an array, string and pointer */
    char label[] = "foo";
    /* should be a type error */
    printf("%s\\n", label + 1);
    return 0;
}|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Javascript Example of Weak Typing")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="javascript">
{rs({js|var cost = 2;
var total = cost + 'USD';
var weird1 = [] + [] === ''; // true
var w2 = [] + {} === '[object Object]'; // true
var weird3 = {} + [] === 0; // true
var weird4 = isNaN({} + {}); // true|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Type Inference or Type Reconstruction")}</Heading>
            <Text textSize>{rs(
{js|Type inference is automatic deduction of types for unannoted code for the purposes of type checking.
Applicalbe to static and gradual typing.|js})}
            </Text>
        </Slide>
        <Slide>
            <Heading size>{rs("Type Inference Scopes")}</Heading>
            <Table style>
                <Thead style><Th style>{rs("Typing Inference Scope")}</Th><Th style>{rs("Description")}</Th><Th style>{rs("Languages")}</Th></Thead>
                <Tr style><Td style>{rs("Local/Unidirectional")}</Td><Td style>{rs("deduce variable declaration, and return type")}</Td><Td style>{rs("C++(11), Typescript, Java(10), Go")}</Td></Tr>
                <Tr style><Td style>{rs("Global/Non Local/Bidirectional")}</Td><Td style>{rs("as above, plus argument types and recursive functions")}</Td><Td style>{rs("SML, F#, Ocaml, ReasonML, Haskell")}</Td></Tr>
            </Table>
        </Slide>
        <Slide>
            <Heading size>{rs("Typescript Local Inference")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="typescript">{rs(
{js|// simple inference
let x = 5;

// local type inference of
// function return type
let foo = () => {
    return 42;
}

// infer type from destructuring
let [c, d, ...rest] = [1, 2, 3];|js}
            )}</SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Typescript Local Inference Limitations")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="typescript">{rs(
{js|// local type inference
// cannot infer parameters
let bar = (x: number, y: number) => {
    return x + y;
}

// local type inference cannot
// infer return type of recursive
// functions
function fac(n: number): number {
    return n >= 1 ? 1 : n * fac(n - 1);
}|js}
            )}</SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Haskell Mostly Unannoted")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="haskell">
{rs({js|module Main where

import System.IO (isEOF)
import Text.Printf

squaredDist mean num = (num - mean)**2

stddev len mean nums =
    let sq = squaredDist mean in
        sqrt(sum(map sq nums) / (fromIntegral len))

nonOutlier mean sd num =
    (num < mean + sd) && (num > mean - sd)

readFloats nums = do
    done <- isEOF
    if done
        then return nums
    else do
        num <- readLn :: IO Float
        readFloats (num:nums)

main = do
    nums <- readFloats([])
    let len = length nums
    let total = sum nums
    let avg = total / (fromIntegral len)
    let sd = stddev len avg nums
    let fno = nonOutlier avg sd
    let no = filter fno nums
    putStrLn . unlines $ printf "%.2f" <$> no|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("ReasonML Mostly Unannoted")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|
module Tc = Tablecloth;

let readFloats: unit => array(float) = [%bs.raw {|
    () => {
        let {readFileSync} = require('fs');
        let lines = readFileSync(0).toString().split('\\n');
        return lines.map(line => parseFloat(line))
                    .filter(n => !isNaN(n));
    }
|}];

let stats = (nums) => {
    let sum = Tc.Array.floatSum(nums);
    let len = Array.length(nums);
    let avg = sum /. float_of_int(len);
    let ss = Array.map((e) => (e -. avg)**2.0, nums);
    (avg, sqrt(Tc.Array.floatSum(ss) /. float_of_int(len)));
};

let main = () => {
    let nums = readFloats();
    let (mean, stddev) = stats(nums);
    let nonOutlier = (num) => {
        num < mean +. stddev && num > mean -. stddev;
    }
    let nonOutliers = Tc.Array.filter(~f=nonOutlier, nums);
    Array.map(Printf.printf("%f\\n"), nonOutliers);
};

main();|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Structural, Nominal and Duck Typing")}</Heading>
            <Table style>
                <Thead style><Th style>{rs("Typing Strategy")}</Th><Th style>{rs("Description")}</Th><Th style>{rs("Languages")}</Th></Thead>
                <Tr style><Td style>{rs("Nominal")}</Td><Td style>{rs("Typing based on name not data shape, better error messages")}</Td><Td style>{rs("Java")}</Td></Tr>
                <Tr style><Td style>{rs("Structural")}</Td><Td style>{rs("Typing based on shape of data, more powerful and flexible, bad error messages")}</Td><Td style>{rs("C++ Templates, GO Interfaces, Typescript, Haskell, ReasonML")}</Td></Tr>
                <Tr style><Td style>{rs("Duck")}</Td><Td style>{rs("Flexible like Structural typing but no compile time safety doesn't suffer from bad error messages")}</Td><Td style>{rs("Python, Javascript")}</Td></Tr>
            </Table>
        </Slide>
        <Slide>
            <Heading size>{rs("Typescript Structural Typing")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="typescript">
{rs({js|interface Named {
    firstName: string
}

class Person {
    firstName: string
    constructor(firstName: string) {
        this.firstName = firstName;
    }
}

// structural type shapes match
let p1: Named = new Person("Troy");
let p2: Named = { firstName: "Travis" };

// infer type from destructuring
let {firstName} = p1;|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("What is Reason/ReasonML?")}</Heading>
            <List>
              <ListItem textSize>(rs("Tries to make Ocaml more like Javascript/Typescript also provides interop with javascript echo system"))</ListItem>
              <ListItem textSize>(rs("Similar to Elixir which tries to make Erlang more like Ruby"))</ListItem>
            </List>
            <Image width="75%" src=whatIsReason/>
        </Slide>
        <Slide>
          <Heading size>
              (rs("Reasonml History"))
          </Heading>
          <List>
              <ListItem textSize>(rs("Started at facebook 2016 by Jordan Walke"))</ListItem>
              <ListItem textSize>(rs("Jordan Walke also created React"))</ListItem>
              <ListItem textSize>(rs("Original React prototype was done in SML a close relative of OCaml"))</ListItem>
              <ListItem textSize>(rs("Reasonml has very close ties to react supporting inline JSX"))</ListItem>
              <ListItem textSize>(rs("[Reason] is the best way to take React to the next level --Jordan Walke"))</ListItem>
          </List>
        </Slide>
        <Slide>
            <Heading size>{rs("Reasons for Reason")}</Heading>
            <Image width="100%" src=whyReason1/>
        </Slide>
        <Slide>
            <Heading size>{rs("More Reasons for Reason")}</Heading>
            <Image width="75%" src=whyReason2/>
        </Slide>
        <Slide>
            <Heading size>{rs("Reasons for Reason")}</Heading>
            <Image width="75%" src=whyReason3/>
        </Slide>
        <Slide>
            <Heading size>{rs("A taste of Reason")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|let listSrc = {js|/* lists are generic types also key in fp */
let favNums : list(int) = [31, 37, 42];
/* destructure we use underscore to say we don't care */
let [first, ..._] = favNums;
switch(favNums) {
    | [] => print_string("empty\\n")
    | [x] => print_string("one\\n")
    | [head, ...rest] => print_string("many\\n")
};
/* modules List, ListLabels, Belt.List Tablecloth.List */|js})}
            </SyntaxHighlighter>
        </Slide>
         <Slide>
            <Heading size>{rs("Reason powerful Variant Sum types")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|type option('a) = Some('a) | None;
type result('a, 'b) = Ok('a) | Error('b);

let ndiv = (x, y) => {
    switch(y) {
    | 0 => None
    | _ => Some(x/y)
    }
};

let ediv = (x, y) => {
    switch(y) {
    | 0 => Error("Can not divide by zero")
    | _ => Ok(x/y)
    }
};

let e = ediv(1, 0);

switch(e) {
| Error(err) => print_endline(err)
| Ok(quotient) => {
        print_int(quotient);
        print_newline();
    }
}|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Compose Results Variants")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|let map = (r, f) => {
    switch(r) {
    | Error(err) => Error(err)
    | Ok(a) => Ok(f(a))
    }
};

let flatMap = (r, f) => {
    switch(r) {
    | Error(err) => Error(err)
    | Ok(a) => f(a)
    }
};

let lift1 = (f) => {
    (a) => {
        switch(a) {
        | Error(err) => Error(err)
        | Ok(b) => Ok(f(b))
        }
    }
};

let r1 = map(Ok(41), a => a + 1);
let r2 = flatMap(Ok(41), a => Ok(string_of_int(a)));
let f1: result(int, string) => result(int, string) = lift1(a => a + 1);
let r3 = f1(Ok(1));|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Reason Arrays")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|/* arrays are also generic */
/* fast random access but fixed size */
let brothers : array(string) =
    [| "Troy", "Chris", "Travis" |];
/* destructure exact size */
let [| b1, b2, b3 |] = brothers;
/* access mutate cell */
a[2] = ""; /* replace Travis with empty string */
/* modules Array, ArrayLabels, Belt.Array Js.Array
Tablecloth.Array */|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Reason records and structural typing")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|/* must create record types to use them*/
type person = {
    name: string,
    age: int
};
let olivia = { name: "Olivia", age: 1 };
/* destructure */
let {name, age} = olivia;
let { name: n, age: a } = olivia; /* n = "Olivia", a = 1 */
/* punning */
let oli = { name, age }; /* - : person = {name: "Olivia", age: 1} */|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>{rs("Reason Tuples")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|/* keyword type lets you create types or type aliases */
type intPair = (int, int);
let favPrimes : intPair = (31, 37);
/* destructure */
let (first, second) = favPrimes;
/* Tablecloth.Tuple2, Tablecloth.Tuple3 */|js})}
            </SyntaxHighlighter>
        </Slide>
         <Slide>
            <Heading size>{rs("Reason Opt in Mutability")}</Heading>
            <SyntaxHighlighter codeTagProps customStyle language="reason">
{rs({js|// mutable values
let count = ref(0);
count := 1; // mutate cell update
// use suffix ^ operator to get value of ref
print_string(string_of_int(count^) ++ "\\n");
// mutable records
type person = {
    name: string,
    mutable age: int
};
let troy = {name: "Troy", "age": 45};
let isBirthday = true;
troy.age = isBirthday ? troy.age + 1 : troy.age;
|js})}
            </SyntaxHighlighter>
        </Slide>
        <Slide>
            <Heading size>
                (rs("Summary"))
            </Heading>
            <List>
                <ListItem textSize>(rs("Reasonml occupies a sweet spot in terms of language features"))</ListItem>
                <ListItem textSize>(rs("Global Type Inference eliminates lot of verbosity"))</ListItem>
                <ListItem textSize>(rs("React development is better in Reasonml"))</ListItem>
                <ListItem textSize>(rs("Transpilation speed Reasonml >> Typescript >> Babel(Flow)"))</ListItem>
                <ListItem textSize>(rs("Reasonml will scale to larger code bases"))</ListItem>
                <ListItem textSize>(rs("Typescript >> Reasonml in terms of javascript interop"))</ListItem>
                <ListItem textSize>(rs("Reason javascript interop is still good which solves the lack of library problem"))</ListItem>
                <ListItem textSize>(rs("Reasonml does optimizations on the javascript code, Typescript cannot because it is unsound"))</ListItem>
                <ListItem textSize>(rs("Reasonml can target native, mobile, web and nodejs"))</ListItem>
            </List>
        </Slide>
    </Deck>
};