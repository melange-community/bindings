open Jest
open Expect

open RescriptJestDateMock

afterEach(() => clear())

describe("functions for just dealing with crontab syntax", () => {
  test("sendAt with cron syntax at minute 10", () => {
    let aDate = Js.Date.fromString("2018-05-27T12:00:00Z")
    advanceTo(aDate)

    let aMomentTenMinutesLater =
      Js.Date.setMinutes(aDate, 10.0) |> Js.Date.fromFloat |> MomentRe.momentWithDate

    // At minute 10
    let nextSchedule = RescriptCron.sendAt(#CronString("* 10 * * * *"))

    expect(MomentRe.Moment.isSame(nextSchedule, aMomentTenMinutesLater)) -> toBe(true)
  })

  test("sendAt with cron syntax at hour 10", () => {
    let aDate = Js.Date.fromString("2018-05-27T12:00:00Z")
    advanceTo(aDate)

    // Every 10 hours
    let nextSchedule = RescriptCron.sendAt(#CronString("* */10 * * *"))

    let aMomentWithNext10Hour = MomentRe.momentWithDate(aDate) |> MomentRe.Moment.setHour(20)

    expect(MomentRe.Moment.isSame(nextSchedule, aMomentWithNext10Hour)) -> toBe(true)
  })

  test("sendAt with Js.date instead of cron syntax", () => {
    let aDate = Js.Date.fromString("2010-01-27T12:12:00Z")
    advanceTo(aDate)

    let futureDate = "2040-05-27T12:00:00.000Z"

    // Future Js.Date
    let nextSchedule = RescriptCron.sendAt(#JsDate(Js.Date.fromString(futureDate)))

    expect(nextSchedule |> MomentRe.Moment.toDate |> Js.Date.toISOString) -> toBe(futureDate)
  })

  test("timeout", () => {
    let aDate = Js.Date.fromString("2018-05-27T12:00:00Z")
    advanceTo(aDate)

    // Every 10 hours
    let msToNextFire = RescriptCron.timeout(#CronString("* */10 * * *"))

    let aMomentWithNext10Hour = MomentRe.momentWithDate(aDate) |> MomentRe.Moment.setHour(20)

    let msDiff = MomentRe.diff(aMomentWithNext10Hour, MomentRe.momentNow(), #milliseconds)

    expect(msToNextFire) -> toEqual(msDiff)
  })
})
