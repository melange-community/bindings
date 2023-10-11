open Jest
open Expect

test("phonenumber link", () =>
  expect(Telefonnummer.Link.make("070-123.45x67")) |> toEqual("tel:0701234567")
)

testAll("voicemail number", list{"888", "333", "222", "147"}, phoneNumber =>
  expect(Telefonnummer.parse(phoneNumber)) |> toBe(`Röstbrevlåda`)
)

testAll(
  "mobile number",
  list{
    ("072- 12 34 5 67", "072-123 45 67"),
    ("0721234567", "072-123 45 67"),
    ("0701234567", "070-123 45 67"),
    ("46701234567", "070-123 45 67"),
    ("+46701234567", "070-123 45 67"),
    ("0046701234567", "070-123 45 67"),
    ("+46(0)701234567", "070-123 45 67"),
    ("+46 0700123456", "070-012 34 56"),
  },
  ((phoneNumber, expected)) => expect(Telefonnummer.parse(phoneNumber)) |> toBe(expected),
)

testAll(
  "landline number",
  list{
    ("0 8 1 2 34 56", "08-12 34 56"),
    ("08123456", "08-12 34 56"),
    ("4608123456", "08-12 34 56"),
    ("081234567", "08-123 45 67"),
    ("46081234567", "08-123 45 67"),
    ("0812345678", "08-123 456 78"),
    ("460812345678", "08-123 456 78"),
    ("03112345", "031-123 45"),
    ("031123456", "031-12 34 56"),
    ("004631123456", "031-12 34 56"),
    ("0311234567", "031-123 45 67"),
    ("+460311234567", "031-123 45 67"),
    ("0500123456", "0500-12 34 56"),
    ("460500123456", "0500-12 34 56"),
    ("05001234567", "05001234567"),
  },
  ((phoneNumber, expected)) => expect(Telefonnummer.parse(phoneNumber)) |> toBe(expected),
)

testAll(
  "phone number validation",
  list{
    ("072- 12 34 5 67", true),
    ("0721234567", true),
    ("08123456", true),
    ("0500123456", true),
    ("+460311234567", true),
    ("05001234567", false),
    ("a08123456", false),
  },
  ((phoneNumber, expected)) =>
    expect(Telefonnummer.Validate.isValid(phoneNumber)) |> toBe(expected),
)
