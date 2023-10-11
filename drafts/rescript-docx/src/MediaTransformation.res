/** @see https://docx.js.org/api/interfaces/IMediaTransformation.html */
type rec t = {
  height: float,
  width: float,
  flip?: flip,
  rotation?: float,
}
and flip = {
  horizontal?: bool,
  vertical?: bool,
}
