[@bs.deriving abstract]
type t = {
  host: string,
  hash: string,
  hostname: string,
  href: string,
  origin: string,
  pathname: string,
  port: string,
  protocol: string,
  search: string,
  searchParams: URLSearchParams.t,
};

[@bs.new] external make: string => t = "URL";
[@bs.new] external makeWithBase: (string, string) => t = "URL";
