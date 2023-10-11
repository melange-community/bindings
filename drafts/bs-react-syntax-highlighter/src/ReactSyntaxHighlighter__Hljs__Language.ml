type t = [
  | `OneC
  | `Abnf
  | `Accesslog
  | `ActionScript
  | `Ada
  | `AngelScript
  | `Apache
  | `AppleScript
  | `Arcade
  | `Arduino
  | `Armasm
  | `Asciidoc
  | `Aspectj
  | `Autohotkey
  | `Autoit
  | `Avrasm
  | `Awk
  | `Axapta
  | `Bash
  | `Basic
  | `Bnf
  | `Brainfuck
  | `Cal
  | `Capnproto
  | `Ceylon
  | `Clean
  | `ClojureRepl
  | `Clojure
  | `Cmake
  | `CoffeeScript
  | `Coq
  | `Cos
  | `Cpp
  | `Crmsh
  | `Crystal
  | `Cs
  | `Csp
  | `Css
  | `D
  | `Dart
  | `Delphi
  | `Diff
  | `Django
  | `Dns
  | `Dockerfile
  | `Dos
  | `Dsconfig
  | `Dts
  | `Dust
  | `Ebnf
  | `Elixir
  | `Elm
  | `Erb
  | `ErlangRepl
  | `Erlang
  | `Excel
  | `Fix
  | `Flix
  | `Fortran
  | `Fsharp
  | `Gams
  | `Gauss
  | `Gcode
  | `Gherkin
  | `Glsl
  | `Gml
  | `Go
  | `Golo
  | `Gradle
  | `Groovy
  | `Haml
  | `Handlebars
  | `Haskell
  | `Haxe
  | `Hsp
  | `Htmlbars
  | `Http
  | `Hy
  | `Inform7
  | `Ini
  | `Irpf90
  | `Isbl
  | `Java
  | `JavaScript
  | `JbossCli
  | `Json
  | `JuliaRepl
  | `Julia
  | `Kotlin
  | `Lasso
  | `Ldif
  | `Leaf
  | `Less
  | `Lisp
  | `Livecodeserver
  | `LiveScript
  | `Llvm
  | `Lsl
  | `Lua
  | `Makefile
  | `Markdown
  | `Mathematica
  | `Matlab
  | `Maxima
  | `Mel
  | `Mercury
  | `Mipsasm
  | `Mizar
  | `Mojolicious
  | `Monkey
  | `MoonScript
  | `N1ql
  | `Nginx
  | `Nimrod
  | `Nix
  | `Nsis
  | `Objectivec
  | `Ocaml
  | `Openscad
  | `Oxygene
  | `Parser3
  | `Perl
  | `Pf
  | `Pgsql
  | `Php
  | `Plaintext
  | `Pony
  | `Powershell
  | `Processing
  | `Profile
  | `Prolog
  | `Properties
  | `Protobuf
  | `Puppet
  | `Purebasic
  | `Python
  | `Q
  | `Qml
  | `R
  | `Reasonml
  | `Rib
  | `Roboconf
  | `Routeros
  | `Rsl
  | `Ruby
  | `Ruleslanguage
  | `Rust
  | `Sas
  | `Scala
  | `Scheme
  | `Scilab
  | `Scss
  | `Shell
  | `Smali
  | `Smalltalk
  | `Sml
  | `Sqf
  | `Sql
  | `Stan
  | `Stata
  | `Step21
  | `Stylus
  | `Subunit
  | `Swift
  | `TaggerScript
  | `Tap
  | `Tcl
  | `Tex
  | `Thrift
  | `Tp
  | `Twig
  | `TypeScript
  | `Vala
  | `Vbnet
  | `VbscriptHtml
  | `VbScript
  | `Verilog
  | `Vhdl
  | `Vim
  | `X86asm
  | `Xl
  | `Xml
  | `Xquery
  | `Yaml
  | `Zephir
  ];;

let toString = function
  | `OneC -> "1c"
  | `Abnf -> "abnf"
  | `Accesslog -> "accesslog"
  | `ActionScript -> "actionscript"
  | `Ada -> "ada"
  | `AngelScript -> "angelscript"
  | `Apache -> "apache"
  | `AppleScript -> "applescript"
  | `Arcade -> "arcade"
  | `Arduino -> "arduino"
  | `Armasm -> "armasm"
  | `Asciidoc -> "asciidoc"
  | `Aspectj -> "aspectj"
  | `Autohotkey -> "autohotkey"
  | `Autoit -> "autoit"
  | `Avrasm -> "avrasm"
  | `Awk -> "awk"
  | `Axapta -> "axapta"
  | `Bash -> "bash"
  | `Basic -> "basic"
  | `Bnf -> "bnf"
  | `Brainfuck -> "brainfuck"
  | `Cal -> "cal"
  | `Capnproto -> "capnproto"
  | `Ceylon -> "ceylon"
  | `Clean -> "clean"
  | `ClojureRepl -> "clojure-repl"
  | `Clojure -> "clojure"
  | `Cmake -> "cmake"
  | `CoffeeScript -> "coffeescript"
  | `Coq -> "coq"
  | `Cos -> "cos"
  | `Cpp -> "cpp"
  | `Crmsh -> "crmsh"
  | `Crystal -> "crystal"
  | `Cs -> "cs"
  | `Csp -> "csp"
  | `Css -> "css"
  | `D -> "d"
  | `Dart -> "dart"
  | `Delphi -> "delphi"
  | `Diff -> "diff"
  | `Django -> "django"
  | `Dns -> "dns"
  | `Dockerfile -> "dockerfile"
  | `Dos -> "dos"
  | `Dsconfig -> "dsconfig"
  | `Dts -> "dts"
  | `Dust -> "dust"
  | `Ebnf -> "ebnf"
  | `Elixir -> "elixir"
  | `Elm -> "elm"
  | `Erb -> "erb"
  | `ErlangRepl -> "erlang-repl"
  | `Erlang -> "erlang"
  | `Excel -> "excel"
  | `Fix -> "fix"
  | `Flix -> "flix"
  | `Fortran -> "fortran"
  | `Fsharp -> "fsharp"
  | `Gams -> "gams"
  | `Gauss -> "gauss"
  | `Gcode -> "gcode"
  | `Gherkin -> "gherkin"
  | `Glsl -> "glsl"
  | `Gml -> "gml"
  | `Go -> "go"
  | `Golo -> "golo"
  | `Gradle -> "gradle"
  | `Groovy -> "groovy"
  | `Haml -> "haml"
  | `Handlebars -> "handlebars"
  | `Haskell -> "haskell"
  | `Haxe -> "haxe"
  | `Hsp -> "hsp"
  | `Htmlbars -> "htmlbars"
  | `Http -> "http"
  | `Hy -> "hy"
  | `Inform7 -> "inform7"
  | `Ini -> "ini"
  | `Irpf90 -> "irpf90"
  | `Isbl -> "isbl"
  | `Java -> "java"
  | `JavaScript -> "javascript"
  | `JbossCli -> "jboss-cli"
  | `Json -> "json"
  | `JuliaRepl -> "julia-repl"
  | `Julia -> "julia"
  | `Kotlin -> "kotlin"
  | `Lasso -> "lasso"
  | `Ldif -> "ldif"
  | `Leaf -> "leaf"
  | `Less -> "less"
  | `Lisp -> "lisp"
  | `Livecodeserver -> "livecodeserver"
  | `LiveScript -> "livescript"
  | `Llvm -> "llvm"
  | `Lsl -> "lsl"
  | `Lua -> "lua"
  | `Makefile -> "makefile"
  | `Markdown -> "markdown"
  | `Mathematica -> "mathematica"
  | `Matlab -> "matlab"
  | `Maxima -> "maxima"
  | `Mel -> "mel"
  | `Mercury -> "mercury"
  | `Mipsasm -> "mipsasm"
  | `Mizar -> "mizar"
  | `Mojolicious -> "mojolicious"
  | `Monkey -> "monkey"
  | `MoonScript -> "moonscript"
  | `N1ql -> "n1ql"
  | `Nginx -> "nginx"
  | `Nimrod -> "nimrod"
  | `Nix -> "nix"
  | `Nsis -> "nsis"
  | `Objectivec -> "objectivec"
  | `Ocaml -> "ocaml"
  | `Openscad -> "openscad"
  | `Oxygene -> "oxygene"
  | `Parser3 -> "parser3"
  | `Perl -> "perl"
  | `Pf -> "pf"
  | `Pgsql -> "pgsql"
  | `Php -> "php"
  | `Plaintext -> "plaintext"
  | `Pony -> "pony"
  | `Powershell -> "powershell"
  | `Processing -> "processing"
  | `Profile -> "profile"
  | `Prolog -> "prolog"
  | `Properties -> "properties"
  | `Protobuf -> "protobuf"
  | `Puppet -> "puppet"
  | `Purebasic -> "purebasic"
  | `Python -> "python"
  | `Q -> "q"
  | `Qml -> "qml"
  | `R -> "r"
  | `Reasonml -> "reasonml"
  | `Rib -> "rib"
  | `Roboconf -> "roboconf"
  | `Routeros -> "routeros"
  | `Rsl -> "rsl"
  | `Ruby -> "ruby"
  | `Ruleslanguage -> "ruleslanguage"
  | `Rust -> "rust"
  | `Sas -> "sas"
  | `Scala -> "scala"
  | `Scheme -> "scheme"
  | `Scilab -> "scilab"
  | `Scss -> "scss"
  | `Shell -> "shell"
  | `Smali -> "smali"
  | `Smalltalk -> "smalltalk"
  | `Sml -> "sml"
  | `Sqf -> "sqf"
  | `Sql -> "sql"
  | `Stan -> "stan"
  | `Stata -> "stata"
  | `Step21 -> "step21"
  | `Stylus -> "stylus"
  | `Subunit -> "subunit"
  | `Swift -> "swift"
  | `TaggerScript -> "taggerscript"
  | `Tap -> "tap"
  | `Tcl -> "tcl"
  | `Tex -> "tex"
  | `Thrift -> "thrift"
  | `Tp -> "tp"
  | `Twig -> "twig"
  | `TypeScript -> "typescript"
  | `Vala -> "vala"
  | `Vbnet -> "vbnet"
  | `VbscriptHtml -> "vbscript-html"
  | `VbScript -> "vbscript"
  | `Verilog -> "verilog"
  | `Vhdl -> "vhdl"
  | `Vim -> "vim"
  | `X86asm -> "x86asm"
  | `Xl -> "xl"
  | `Xml -> "xml"
  | `Xquery -> "xquery"
  | `Yaml -> "yaml"
  | `Zephir -> "zephir"
;;
