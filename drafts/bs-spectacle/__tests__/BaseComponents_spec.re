let s = ReasonReact.string;

module BlockQuote =
  TestHelpers.MakeBasePropsTest({
    let name = "BlockQuote";
    let element = <BlockQuote />;
  });

module Cite =
  TestHelpers.MakeBasePropsTest({
    let name = "Cite";
    let element = <Cite />;
  });

module Code =
  TestHelpers.MakeBasePropsTest({
    let name = "Code";
    let element = <Code> {s("test")} </Code>;
  });

module CodePane =
  TestHelpers.MakeBasePropsTest({
    let name = "CodePane";
    let element = <CodePane lang="js" source="console.log('Hi');" />;
  });

module GoToAction =
  TestHelpers.MakeBasePropsTest({
    let name = "GoToAction";
    let element = <GoToAction slide=1 render={_slide => <div />} />;
  });

module Heading =
  TestHelpers.MakeBasePropsTest({
    let name = "Heading";
    let element = <Heading size=1 fit=false lineHeight=1.5 />;
  });

module Image =
  TestHelpers.MakeBasePropsTest({
    let name = "Image";
    let element = <Image src="path" alt="alt" display="block" width="100px" />;
  });

module Link = {
  include TestHelpers.MakeBasePropsTest({
    let name = "Link";
    let element = <Link href="link" />;
  });
  include TestHelpers.MakeBasePropsTest({
    let name = "Link with target";
    let element = <Link href="link" target="_blank" />;
  });
};

module List =
  TestHelpers.MakeBasePropsTest({
    let name = "List";
    let element = <List ordered=true reversed=true start=2 type_="A" />;
  });

module ListItem =
  TestHelpers.MakeBasePropsTest({
    let name = "ListItem";
    let element = <ListItem />;
  });

module Markdown = {
  include TestHelpers.MakeBasePropsTest({
    let name = "Markdown with source";
    let element = <Markdown source="# Hello" />;
  });
  include TestHelpers.MakeBasePropsTest({
    let name = "Markdown with children";
    let element =
      <Markdown> {|
# Hello there

## General Kenobi
          |} </Markdown>;
  });
};

module Quote =
  TestHelpers.MakeBasePropsTest({
    let name = "Quote";
    let element = <Quote />;
  });

module S = {
  open Jest;
  include TestHelpers.MakeBasePropsTest({
    let name = "S";
    let element = <S />;
  });
  include TestHelpers.MakeBasePropsTest({
    let name = "S with type";
    let element = <S type_=`strikethrough />;
  });
  describe(
    "S types",
    ExpectJs.(
      () => {
        test("strikethrough", () =>
          expect(S.sTypeFromJs("strikethrough"))
          |> toEqual(Some(`strikethrough))
        );
        test("underline", () =>
          expect(S.sTypeFromJs("underline")) |> toEqual(Some(`underline))
        );
        test("bold", () =>
          expect(S.sTypeFromJs("bold")) |> toEqual(Some(`bold))
        );
        test("italc", () =>
          expect(S.sTypeFromJs("italic")) |> toEqual(Some(`italic))
        );
        test("should not match", () =>
          expect(S.sTypeFromJs("sdaf")) |> toEqual(None)
        );
      }
    ),
  );
};

module Table =
  TestHelpers.MakeBasePropsTest({
    let name = "Table";
    let element = <Table />;
  });

module TableBody =
  TestHelpers.MakeBasePropsTest({
    let name = "TableBody";
    let element = <TableBody />;
  });

module TableHeader =
  TestHelpers.MakeBasePropsTest({
    let name = "TableHeader";
    let element = <TableHeader />;
  });

module TableHeaderItem =
  TestHelpers.MakeBasePropsTest({
    let name = "TableHeaderItem";
    let element = <TableHeaderItem />;
  });

module TableItem =
  TestHelpers.MakeBasePropsTest({
    let name = "TableItem";
    let element = <TableItem />;
  });

module TableRow =
  TestHelpers.MakeBasePropsTest({
    let name = "TableRow";
    let element = <TableRow />;
  });

/* module Slide =
   TestHelpers.MakeBasePropsTest(
     {
       let name = "Slide";
       let element = <Slide />;
     }
   ); */
module Text =
  TestHelpers.MakeBasePropsTest({
    let name = "Text";
    let element = <Text fit=false lineHeight=1.5 />;
  });