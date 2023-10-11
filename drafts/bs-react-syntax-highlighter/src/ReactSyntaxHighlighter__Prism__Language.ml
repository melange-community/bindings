type t = [
  | `Abap
  | `ActionScript
  | `Ada
  | `Apacheconf
  | `Apl
  | `AppleScript
  | `Arduino
  | `Arff
  | `Asciidoc
  | `Asm6502
  | `Aspnet
  | `Autohotkey
  | `Autoit
  | `Bash
  | `Basic
  | `Batch
  | `Bison
  | `Brainfuck
  | `Bro
  | `C
  | `Clike
  | `Clojure
  | `CoffeeScript
  | `Cpp
  | `Crystal
  | `Csharp
  | `Csp
  | `CssExtras
  | `Css
  | `D
  | `Dart
  | `Diff
  | `Django
  | `Docker
  | `Eiffel
  | `Elixir
  | `Elm
  | `Erb
  | `Erlang
  | `Flow
  | `Fortran
  | `Fsharp
  | `Gedcom
  | `Gherkin
  | `Git
  | `Glsl
  | `Go
  | `Graphql
  | `Groovy
  | `Haml
  | `Handlebars
  | `Haskell
  | `Haxe
  | `Hpkp
  | `Hsts
  | `Http
  | `Ichigojam
  | `Icon
  | `Inform7
  | `Ini
  | `Io
  | `J
  | `Java
  | `JavaScript
  | `Jolie
  | `Json
  | `Jsx
  | `Julia
  | `Keyman
  | `Kotlin
  | `Latex
  | `Less
  | `Liquid
  | `Lisp
  | `LiveScript
  | `Lolcode
  | `Lua
  | `Makefile
  | `Markdown
  | `MarkupTemplating
  | `Markup
  | `Matlab
  | `Mel
  | `Mizar
  | `Monkey
  | `N4js
  | `Nasm
  | `Nginx
  | `Nim
  | `Nix
  | `Nsis
  | `Objectivec
  | `Ocaml
  | `Opencl
  | `Oz
  | `Parigp
  | `Parser
  | `Pascal
  | `Perl
  | `PhpExtras
  | `Php
  | `Plsql
  | `Powershell
  | `Processing
  | `Prolog
  | `Properties
  | `Protobuf
  | `Pug
  | `Puppet
  | `Pure
  | `Python
  | `Q
  | `Qore
  | `R
  | `Reason
  | `Renpy
  | `Rest
  | `Rip
  | `Roboconf
  | `Ruby
  | `Rust
  | `Sas
  | `Sass
  | `Scala
  | `Scheme
  | `Scss
  | `Smalltalk
  | `Smarty
  | `Soy
  | `Sql
  | `Stylus
  | `Swift
  | `Tap
  | `Tcl
  | `Text
  | `Textile
  | `Tsx
  | `Tt2
  | `Twig
  | `TypeScript
  | `Vbnet
  | `Velocity
  | `Verilog
  | `Vhdl
  | `Vim
  | `VisualBasic
  | `Wasm
  | `Wiki
  | `Xeora
  | `Xojo
  | `Xquery
  | `Yaml
];;

let toString = function
  | `Abap -> "abap"
  | `ActionScript -> "actionscript"
  | `Ada -> "ada"
  | `Apacheconf -> "apacheconf"
  | `Apl -> "apl"
  | `AppleScript -> "applescript"
  | `Arduino -> "arduino"
  | `Arff -> "arff"
  | `Asciidoc -> "asciidoc"
  | `Asm6502 -> "asm6502"
  | `Aspnet -> "aspnet"
  | `Autohotkey -> "autohotkey"
  | `Autoit -> "autoit"
  | `Bash -> "bash"
  | `Basic -> "basic"
  | `Batch -> "batch"
  | `Bison -> "bison"
  | `Brainfuck -> "brainfuck"
  | `Bro -> "bro"
  | `C -> "c"
  | `Clike -> "clike"
  | `Clojure -> "clojure"
  | `CoffeeScript -> "coffeescript"
  | `Cpp -> "cpp"
  | `Crystal -> "crystal"
  | `Csharp -> "csharp"
  | `Csp -> "csp"
  | `CssExtras -> "css-extras"
  | `Css -> "css"
  | `D -> "d"
  | `Dart -> "dart"
  | `Diff -> "diff"
  | `Django -> "django"
  | `Docker -> "docker"
  | `Eiffel -> "eiffel"
  | `Elixir -> "elixir"
  | `Elm -> "elm"
  | `Erb -> "erb"
  | `Erlang -> "erlang"
  | `Flow -> "flow"
  | `Fortran -> "fortran"
  | `Fsharp -> "fsharp"
  | `Gedcom -> "gedcom"
  | `Gherkin -> "gherkin"
  | `Git -> "git"
  | `Glsl -> "glsl"
  | `Go -> "go"
  | `Graphql -> "graphql"
  | `Groovy -> "groovy"
  | `Haml -> "haml"
  | `Handlebars -> "handlebars"
  | `Haskell -> "haskell"
  | `Haxe -> "haxe"
  | `Hpkp -> "hpkp"
  | `Hsts -> "hsts"
  | `Http -> "http"
  | `Ichigojam -> "ichigojam"
  | `Icon -> "icon"
  | `Inform7 -> "inform7"
  | `Ini -> "ini"
  | `Io -> "io"
  | `J -> "j"
  | `Java -> "java"
  | `JavaScript -> "javascript"
  | `Jolie -> "jolie"
  | `Json -> "json"
  | `Jsx -> "jsx"
  | `Julia -> "julia"
  | `Keyman -> "keyman"
  | `Kotlin -> "kotlin"
  | `Latex -> "latex"
  | `Less -> "less"
  | `Liquid -> "liquid"
  | `Lisp -> "lisp"
  | `LiveScript -> "livescript"
  | `Lolcode -> "lolcode"
  | `Lua -> "lua"
  | `Makefile -> "makefile"
  | `Markdown -> "markdown"
  | `MarkupTemplating -> "markup-templating"
  | `Markup -> "markup"
  | `Matlab -> "matlab"
  | `Mel -> "mel"
  | `Mizar -> "mizar"
  | `Monkey -> "monkey"
  | `N4js -> "n4js"
  | `Nasm -> "nasm"
  | `Nginx -> "nginx"
  | `Nim -> "nim"
  | `Nix -> "nix"
  | `Nsis -> "nsis"
  | `Objectivec -> "objectivec"
  | `Ocaml -> "ocaml"
  | `Opencl -> "opencl"
  | `Oz -> "oz"
  | `Parigp -> "parigp"
  | `Parser -> "parser"
  | `Pascal -> "pascal"
  | `Perl -> "perl"
  | `PhpExtras -> "php-extras"
  | `Php -> "php"
  | `Plsql -> "plsql"
  | `Powershell -> "powershell"
  | `Processing -> "processing"
  | `Prolog -> "prolog"
  | `Properties -> "properties"
  | `Protobuf -> "protobuf"
  | `Pug -> "pug"
  | `Puppet -> "puppet"
  | `Pure -> "pure"
  | `Python -> "python"
  | `Q -> "q"
  | `Qore -> "qore"
  | `R -> "r"
  | `Reason -> "reason"
  | `Renpy -> "renpy"
  | `Rest -> "rest"
  | `Rip -> "rip"
  | `Roboconf -> "roboconf"
  | `Ruby -> "ruby"
  | `Rust -> "rust"
  | `Sas -> "sas"
  | `Sass -> "sass"
  | `Scala -> "scala"
  | `Scheme -> "scheme"
  | `Scss -> "scss"
  | `Smalltalk -> "smalltalk"
  | `Smarty -> "smarty"
  | `Soy -> "soy"
  | `Sql -> "sql"
  | `Stylus -> "stylus"
  | `Swift -> "swift"
  | `Tap -> "tap"
  | `Tcl -> "tcl"
  | `Text -> "text"
  | `Textile -> "textile"
  | `Tsx -> "tsx"
  | `Tt2 -> "tt2"
  | `Twig -> "twig"
  | `TypeScript -> "typescript"
  | `Vbnet -> "vbnet"
  | `Velocity -> "velocity"
  | `Verilog -> "verilog"
  | `Vhdl -> "vhdl"
  | `Vim -> "vim"
  | `VisualBasic -> "visual-basic"
  | `Wasm -> "wasm"
  | `Wiki -> "wiki"
  | `Xeora -> "xeora"
  | `Xojo -> "xojo"
  | `Xquery -> "xquery"
  | `Yaml -> "yaml"
;;
