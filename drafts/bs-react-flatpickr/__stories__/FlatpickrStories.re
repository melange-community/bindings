open BsStorybook;
open ReasonDateFns;
open Story;

[%bs.raw {| require("flatpickr/dist/flatpickr.css") |}];
let _module = [%bs.raw "module"];

storiesOf("Flatpickr", _module)
->addDecorator(Knobs.withKnobs)
->add("Simple Render", () => <Flatpickr />)
->add("With initial  value", () =>
    <Flatpickr value={`date(Js.Date.make())} />
  )
->add("With Options", () => {
    let dateFormat =
      Knobs.text(~label="defaultFormat", ~defaultValue="F j, Y", ());

    let daysFromNow =
      Knobs.number(
        ~label="maxDate",
        ~defaultValue=3.0,
        ~rangeConfiguration={min: 0.0, max: 7.0, step: 1.0},
        (),
      );

    let daysAgo =
      Knobs.number(
        ~label="minDate",
        ~defaultValue=3.0,
        ~rangeConfiguration={min: 0.0, max: 7.0, step: 1.0},
        (),
      );

    let maxDate =
      `date(Js.Date.make() |> DateFns.addDays(daysFromNow->int_of_float));
    let minDate =
      `date(Js.Date.make() |> DateFns.subDays(daysAgo->int_of_float));

    <Flatpickr
      options={FlatpickrOptions.make(~dateFormat, ~maxDate, ~minDate, ())}
    />;
  });
