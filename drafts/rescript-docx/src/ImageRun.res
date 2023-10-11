type docPropertiesOptions = {
  name: string,
  dscription: string,
  title: string,
}

type options<'a> = {
  /**
   * FIXME: should be equivalent to: string  | Buffer | Uint8Array | ArrayBuffer
   * 
   * @see https://docx.js.org/api/interfaces/IImageOptions.html#data
   */
  data: 'a,
  transformation: MediaTransformation.t,
  altText?: docPropertiesOptions,
  floating?: Floating.t,
}

@module("docx") @new
external make: options<'a> => ParagraphChild.t = "ImageRun"
