let map2 = (a, b, m) =>
  switch (a, b) {
  | (Some(a), Some(b)) => Some(m(a, b))
  | _ => None
  }

let map3 = (a, b, c, m) =>
  switch (a, b, c) {
  | (Some(a), Some(b), Some(c)) => Some(m(a, b, c))
  | _ => None
  }

let map4 = (a, b, c, d, m) =>
  switch (a, b, c, d) {
  | (Some(a), Some(b), Some(c), Some(d)) => Some(m(a, b, c, d))
  | _ => None
  }

let map5 = (a, b, c, d, e, m) =>
  switch (a, b, c, d, e) {
  | (Some(a), Some(b), Some(c), Some(d), Some(e)) => Some(m(a, b, c, d, e))
  | _ => None
  }
