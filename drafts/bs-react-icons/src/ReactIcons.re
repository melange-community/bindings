[@bs.deriving abstract]
type jsIconProps = {
  [@bs.optional]
  className: string,
  [@bs.optional]
  color: string,
  [@bs.optional]
  size: string,
  [@bs.optional]
  style: ReactDOMRe.Style.t,
};

module Provider = {
  [@bs.deriving abstract]
  type iconContext = {
    [@bs.as "Provider"]
    provider: ReasonReact.reactClass,
  };

  [@bs.deriving abstract]
  type jsProps = {value: jsIconProps};

  [@bs.module "react-icons"] external iconContext: iconContext = "IconContext";
  let make = (~className=?, ~color=?, ~size=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=iconContext->providerGet,
      ~props=
        jsProps(
          ~value=jsIconProps(~className?, ~color?, ~size?, ~style?, ()),
        ),
      children,
    );
};

module type Icon = {let reactClass: ReasonReact.reactClass;};

module MakeIcon = (Icon: Icon) => {
  let make = (~className=?, ~color=?, ~size=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Icon.reactClass,
      ~props=jsIconProps(~className?, ~color?, ~size?, ~style?, ()),
      children,
    );
};
/*
 * The rest of this file has been generated
 */
module Fa500px = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "Fa500px";
});

module FaAccessibleIcon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAccessibleIcon";
});

module FaAccusoft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAccusoft";
});

module FaAdn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAdn";
});

module FaAdversal = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAdversal";
});

module FaAffiliatetheme = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAffiliatetheme";
});

module FaAlgolia = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAlgolia";
});

module FaAmazonPay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAmazonPay";
});

module FaAmazon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAmazon";
});

module FaAmilia = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAmilia";
});

module FaAndroid = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAndroid";
});

module FaAngellist = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngellist";
});

module FaAngrycreative = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngrycreative";
});

module FaAngular = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngular";
});

module FaAppStoreIos = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAppStoreIos";
});

module FaAppStore = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAppStore";
});

module FaApper = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaApper";
});

module FaApplePay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaApplePay";
});

module FaApple = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaApple";
});

module FaAsymmetrik = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAsymmetrik";
});

module FaAudible = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAudible";
});

module FaAutoprefixer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAutoprefixer";
});

module FaAvianex = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAvianex";
});

module FaAviato = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAviato";
});

module FaAws = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAws";
});

module FaBandcamp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBandcamp";
});

module FaBehanceSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBehanceSquare";
});

module FaBehance = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBehance";
});

module FaBimobject = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBimobject";
});

module FaBitbucket = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBitbucket";
});

module FaBitcoin = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBitcoin";
});

module FaBity = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBity";
});

module FaBlackTie = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBlackTie";
});

module FaBlackberry = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBlackberry";
});

module FaBloggerB = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBloggerB";
});

module FaBlogger = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBlogger";
});

module FaBluetoothB = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBluetoothB";
});

module FaBluetooth = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBluetooth";
});

module FaBtc = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBtc";
});

module FaBuromobelexperte = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBuromobelexperte";
});

module FaBuysellads = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBuysellads";
});

module FaCcAmazonPay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcAmazonPay";
});

module FaCcAmex = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcAmex";
});

module FaCcApplePay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcApplePay";
});

module FaCcDinersClub = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcDinersClub";
});

module FaCcDiscover = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcDiscover";
});

module FaCcJcb = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcJcb";
});

module FaCcMastercard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcMastercard";
});

module FaCcPaypal = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcPaypal";
});

module FaCcStripe = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcStripe";
});

module FaCcVisa = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCcVisa";
});

module FaCentercode = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCentercode";
});

module FaChrome = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChrome";
});

module FaCloudscale = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCloudscale";
});

module FaCloudsmith = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCloudsmith";
});

module FaCloudversify = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCloudversify";
});

module FaCodepen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCodepen";
});

module FaCodiepie = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCodiepie";
});

module FaConnectdevelop = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaConnectdevelop";
});

module FaContao = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaContao";
});

module FaCpanel = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCpanel";
});

module FaCreativeCommonsBy = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsBy";
});

module FaCreativeCommonsNcEu = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsNcEu";
});

module FaCreativeCommonsNcJp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsNcJp";
});

module FaCreativeCommonsNc = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsNc";
});

module FaCreativeCommonsNd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsNd";
});

module FaCreativeCommonsPdAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsPdAlt";
});

module FaCreativeCommonsPd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsPd";
});

module FaCreativeCommonsRemix = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsRemix";
});

module FaCreativeCommonsSa = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsSa";
});

module FaCreativeCommonsSamplingPlus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsSamplingPlus";
});

module FaCreativeCommonsSampling = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsSampling";
});

module FaCreativeCommonsShare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommonsShare";
});

module FaCreativeCommons = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreativeCommons";
});

module FaCss3Alt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCss3Alt";
});

module FaCss3 = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCss3";
});

module FaCuttlefish = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCuttlefish";
});

module FaDAndD = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDAndD";
});

module FaDashcube = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDashcube";
});

module FaDelicious = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDelicious";
});

module FaDeploydog = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDeploydog";
});

module FaDeskpro = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDeskpro";
});

module FaDeviantart = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDeviantart";
});

module FaDigg = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDigg";
});

module FaDigitalOcean = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDigitalOcean";
});

module FaDiscord = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiscord";
});

module FaDiscourse = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiscourse";
});

module FaDochub = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDochub";
});

module FaDocker = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDocker";
});

module FaDraft2digital = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDraft2digital";
});

module FaDribbbleSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDribbbleSquare";
});

module FaDribbble = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDribbble";
});

module FaDropbox = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDropbox";
});

module FaDrupal = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDrupal";
});

module FaDyalog = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDyalog";
});

module FaEarlybirds = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEarlybirds";
});

module FaEbay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEbay";
});

module FaEdge = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEdge";
});

module FaElementor = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaElementor";
});

module FaEmber = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEmber";
});

module FaEmpire = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEmpire";
});

module FaEnvira = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEnvira";
});

module FaErlang = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaErlang";
});

module FaEthereum = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEthereum";
});

module FaEtsy = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEtsy";
});

module FaExpeditedssl = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExpeditedssl";
});

module FaFacebookF = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFacebookF";
});

module FaFacebookMessenger = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFacebookMessenger";
});

module FaFacebookSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFacebookSquare";
});

module FaFacebook = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFacebook";
});

module FaFirefox = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFirefox";
});

module FaFirstOrderAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFirstOrderAlt";
});

module FaFirstOrder = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFirstOrder";
});

module FaFirstdraft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFirstdraft";
});

module FaFlickr = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFlickr";
});

module FaFlipboard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFlipboard";
});

module FaFly = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFly";
});

module FaFontAwesomeAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFontAwesomeAlt";
});

module FaFontAwesomeFlag = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFontAwesomeFlag";
});

module FaFontAwesomeLogoFull = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFontAwesomeLogoFull";
});

module FaFontAwesome = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFontAwesome";
});

module FaFonticonsFi = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFonticonsFi";
});

module FaFonticons = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFonticons";
});

module FaFortAwesomeAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFortAwesomeAlt";
});

module FaFortAwesome = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFortAwesome";
});

module FaForumbee = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaForumbee";
});

module FaFoursquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFoursquare";
});

module FaFreeCodeCamp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFreeCodeCamp";
});

module FaFreebsd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFreebsd";
});

module FaFulcrum = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFulcrum";
});

module FaGalacticRepublic = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGalacticRepublic";
});

module FaGalacticSenate = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGalacticSenate";
});

module FaGetPocket = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGetPocket";
});

module FaGgCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGgCircle";
});

module FaGg = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGg";
});

module FaGitSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGitSquare";
});

module FaGit = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGit";
});

module FaGithubAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGithubAlt";
});

module FaGithubSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGithubSquare";
});

module FaGithub = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGithub";
});

module FaGitkraken = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGitkraken";
});

module FaGitlab = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGitlab";
});

module FaGitter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGitter";
});

module FaGlideG = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGlideG";
});

module FaGlide = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGlide";
});

module FaGofore = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGofore";
});

module FaGoodreadsG = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGoodreadsG";
});

module FaGoodreads = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGoodreads";
});

module FaGoogleDrive = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGoogleDrive";
});

module FaGooglePlay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGooglePlay";
});

module FaGooglePlusG = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGooglePlusG";
});

module FaGooglePlusSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGooglePlusSquare";
});

module FaGooglePlus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGooglePlus";
});

module FaGoogleWallet = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGoogleWallet";
});

module FaGoogle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGoogle";
});

module FaGratipay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGratipay";
});

module FaGrav = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGrav";
});

module FaGripfire = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGripfire";
});

module FaGrunt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGrunt";
});

module FaGulp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGulp";
});

module FaHackerNewsSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHackerNewsSquare";
});

module FaHackerNews = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHackerNews";
});

module FaHips = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHips";
});

module FaHireAHelper = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHireAHelper";
});

module FaHooli = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHooli";
});

module FaHotjar = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHotjar";
});

module FaHouzz = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHouzz";
});

module FaHtml5 = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHtml5";
});

module FaHubspot = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHubspot";
});

module FaImdb = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaImdb";
});

module FaInstagram = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaInstagram";
});

module FaInternetExplorer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaInternetExplorer";
});

module FaIoxhost = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaIoxhost";
});

module FaItunesNote = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaItunesNote";
});

module FaItunes = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaItunes";
});

module FaJava = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJava";
});

module FaJediOrder = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJediOrder";
});

module FaJenkins = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJenkins";
});

module FaJoget = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJoget";
});

module FaJoomla = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJoomla";
});

module FaJsSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJsSquare";
});

module FaJs = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJs";
});

module FaJsfiddle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaJsfiddle";
});

module FaKeybase = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKeybase";
});

module FaKeycdn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKeycdn";
});

module FaKickstarterK = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKickstarterK";
});

module FaKickstarter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKickstarter";
});

module FaKorvue = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKorvue";
});

module FaLaravel = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLaravel";
});

module FaLastfmSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLastfmSquare";
});

module FaLastfm = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLastfm";
});

module FaLeanpub = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLeanpub";
});

module FaLess = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLess";
});

module FaLine = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLine";
});

module FaLinkedinIn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLinkedinIn";
});

module FaLinkedin = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLinkedin";
});

module FaLinode = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLinode";
});

module FaLinux = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLinux";
});

module FaLyft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLyft";
});

module FaMagento = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMagento";
});

module FaMandalorian = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMandalorian";
});

module FaMastodon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMastodon";
});

module FaMaxcdn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMaxcdn";
});

module FaMedapps = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMedapps";
});

module FaMediumM = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMediumM";
});

module FaMedium = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMedium";
});

module FaMedrt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMedrt";
});

module FaMeetup = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMeetup";
});

module FaMicrosoft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMicrosoft";
});

module FaMix = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMix";
});

module FaMixcloud = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMixcloud";
});

module FaMizuni = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMizuni";
});

module FaModx = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaModx";
});

module FaMonero = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMonero";
});

module FaNapster = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNapster";
});

module FaNintendoSwitch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNintendoSwitch";
});

module FaNodeJs = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNodeJs";
});

module FaNode = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNode";
});

module FaNpm = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNpm";
});

module FaNs8 = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNs8";
});

module FaNutritionix = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNutritionix";
});

module FaOdnoklassnikiSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOdnoklassnikiSquare";
});

module FaOdnoklassniki = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOdnoklassniki";
});

module FaOldRepublic = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOldRepublic";
});

module FaOpencart = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOpencart";
});

module FaOpenid = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOpenid";
});

module FaOpera = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOpera";
});

module FaOptinMonster = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOptinMonster";
});

module FaOsi = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOsi";
});

module FaPage4 = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPage4";
});

module FaPagelines = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPagelines";
});

module FaPalfed = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPalfed";
});

module FaPatreon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPatreon";
});

module FaPaypal = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPaypal";
});

module FaPeriscope = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPeriscope";
});

module FaPhabricator = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhabricator";
});

module FaPhoenixFramework = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhoenixFramework";
});

module FaPhoenixSquadron = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhoenixSquadron";
});

module FaPhp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhp";
});

module FaPiedPiperAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPiedPiperAlt";
});

module FaPiedPiperHat = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPiedPiperHat";
});

module FaPiedPiperPp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPiedPiperPp";
});

module FaPiedPiper = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPiedPiper";
});

module FaPinterestP = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPinterestP";
});

module FaPinterestSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPinterestSquare";
});

module FaPinterest = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPinterest";
});

module FaPlaystation = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlaystation";
});

module FaProductHunt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaProductHunt";
});

module FaPushed = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPushed";
});

module FaPython = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPython";
});

module FaQq = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQq";
});

module FaQuinscape = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQuinscape";
});

module FaQuora = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQuora";
});

module FaRProject = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRProject";
});

module FaR = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaR";
});

module FaRavelry = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRavelry";
});

module FaReact = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaReact";
});

module FaReadme = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaReadme";
});

module FaRebel = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRebel";
});

module FaRedRiver = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRedRiver";
});

module FaRedditAlien = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRedditAlien";
});

module FaRedditSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRedditSquare";
});

module FaReddit = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaReddit";
});

module FaRendact = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRendact";
});

module FaRenren = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRenren";
});

module FaReplyd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaReplyd";
});

module FaResearchgate = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaResearchgate";
});

module FaResolving = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaResolving";
});

module FaRocketchat = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRocketchat";
});

module FaRockrms = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRockrms";
});

module FaSafari = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSafari";
});

module FaSass = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSass";
});

module FaSchlix = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSchlix";
});

module FaScribd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaScribd";
});

module FaSearchengin = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSearchengin";
});

module FaSellcast = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSellcast";
});

module FaSellsy = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSellsy";
});

module FaServicestack = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaServicestack";
});

module FaShirtsinbulk = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShirtsinbulk";
});

module FaSimplybuilt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSimplybuilt";
});

module FaSistrix = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSistrix";
});

module FaSith = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSith";
});

module FaSkyatlas = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSkyatlas";
});

module FaSkype = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSkype";
});

module FaSlackHash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSlackHash";
});

module FaSlack = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSlack";
});

module FaSlideshare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSlideshare";
});

module FaSnapchatGhost = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSnapchatGhost";
});

module FaSnapchatSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSnapchatSquare";
});

module FaSnapchat = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSnapchat";
});

module FaSoundcloud = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSoundcloud";
});

module FaSpeakap = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSpeakap";
});

module FaSpotify = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSpotify";
});

module FaStackExchange = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStackExchange";
});

module FaStackOverflow = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStackOverflow";
});

module FaStaylinked = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStaylinked";
});

module FaSteamSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSteamSquare";
});

module FaSteamSymbol = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSteamSymbol";
});

module FaSteam = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSteam";
});

module FaStickerMule = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStickerMule";
});

module FaStrava = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStrava";
});

module FaStripeS = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStripeS";
});

module FaStripe = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStripe";
});

module FaStudiovinari = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStudiovinari";
});

module FaStumbleuponCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStumbleuponCircle";
});

module FaStumbleupon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStumbleupon";
});

module FaSuperpowers = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSuperpowers";
});

module FaSupple = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSupple";
});

module FaTeamspeak = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTeamspeak";
});

module FaTelegramPlane = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTelegramPlane";
});

module FaTelegram = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTelegram";
});

module FaTencentWeibo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTencentWeibo";
});

module FaThemeisle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThemeisle";
});

module FaTradeFederation = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTradeFederation";
});

module FaTrello = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTrello";
});

module FaTripadvisor = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTripadvisor";
});

module FaTumblrSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTumblrSquare";
});

module FaTumblr = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTumblr";
});

module FaTwitch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTwitch";
});

module FaTwitterSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTwitterSquare";
});

module FaTwitter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTwitter";
});

module FaTypo3 = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTypo3";
});

module FaUber = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUber";
});

module FaUikit = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUikit";
});

module FaUniregistry = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUniregistry";
});

module FaUntappd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUntappd";
});

module FaUsb = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUsb";
});

module FaUssunnah = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUssunnah";
});

module FaVaadin = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVaadin";
});

module FaViacoin = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaViacoin";
});

module FaViadeoSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaViadeoSquare";
});

module FaViadeo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaViadeo";
});

module FaViber = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaViber";
});

module FaVimeoSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVimeoSquare";
});

module FaVimeoV = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVimeoV";
});

module FaVimeo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVimeo";
});

module FaVine = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVine";
});

module FaVk = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVk";
});

module FaVnv = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVnv";
});

module FaVuejs = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVuejs";
});

module FaWeibo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWeibo";
});

module FaWeixin = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWeixin";
});

module FaWhatsappSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWhatsappSquare";
});

module FaWhatsapp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWhatsapp";
});

module FaWhmcs = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWhmcs";
});

module FaWikipediaW = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWikipediaW";
});

module FaWindows = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWindows";
});

module FaWolfPackBattalion = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWolfPackBattalion";
});

module FaWordpressSimple = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWordpressSimple";
});

module FaWordpress = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWordpress";
});

module FaWpbeginner = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWpbeginner";
});

module FaWpexplorer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWpexplorer";
});

module FaWpforms = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWpforms";
});

module FaXbox = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaXbox";
});

module FaXingSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaXingSquare";
});

module FaXing = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaXing";
});

module FaYCombinator = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYCombinator";
});

module FaYahoo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYahoo";
});

module FaYandexInternational = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYandexInternational";
});

module FaYandex = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYandex";
});

module FaYelp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYelp";
});

module FaYoast = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYoast";
});

module FaYoutubeSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYoutubeSquare";
});

module FaYoutube = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYoutube";
});

module FaAddressBook = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAddressBook";
});

module FaAddressCard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAddressCard";
});

module FaAdjust = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAdjust";
});

module FaAlignCenter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAlignCenter";
});

module FaAlignJustify = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAlignJustify";
});

module FaAlignLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAlignLeft";
});

module FaAlignRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAlignRight";
});

module FaAllergies = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAllergies";
});

module FaAmbulance = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAmbulance";
});

module FaAmericanSignLanguageInterpreting = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAmericanSignLanguageInterpreting";
});

module FaAnchor = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAnchor";
});

module FaAngleDoubleDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleDoubleDown";
});

module FaAngleDoubleLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleDoubleLeft";
});

module FaAngleDoubleRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleDoubleRight";
});

module FaAngleDoubleUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleDoubleUp";
});

module FaAngleDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleDown";
});

module FaAngleLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleLeft";
});

module FaAngleRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleRight";
});

module FaAngleUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAngleUp";
});

module FaArchive = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArchive";
});

module FaArrowAltCircleDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowAltCircleDown";
});

module FaArrowAltCircleLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowAltCircleLeft";
});

module FaArrowAltCircleRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowAltCircleRight";
});

module FaArrowAltCircleUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowAltCircleUp";
});

module FaArrowCircleDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowCircleDown";
});

module FaArrowCircleLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowCircleLeft";
});

module FaArrowCircleRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowCircleRight";
});

module FaArrowCircleUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowCircleUp";
});

module FaArrowDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowDown";
});

module FaArrowLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowLeft";
});

module FaArrowRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowRight";
});

module FaArrowUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowUp";
});

module FaArrowsAltH = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowsAltH";
});

module FaArrowsAltV = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowsAltV";
});

module FaArrowsAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaArrowsAlt";
});

module FaAssistiveListeningSystems = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAssistiveListeningSystems";
});

module FaAsterisk = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAsterisk";
});

module FaAt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAt";
});

module FaAudioDescription = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaAudioDescription";
});

module FaBackward = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBackward";
});

module FaBalanceScale = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBalanceScale";
});

module FaBan = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBan";
});

module FaBandAid = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBandAid";
});

module FaBarcode = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBarcode";
});

module FaBars = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBars";
});

module FaBaseballBall = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBaseballBall";
});

module FaBasketballBall = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBasketballBall";
});

module FaBath = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBath";
});

module FaBatteryEmpty = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBatteryEmpty";
});

module FaBatteryFull = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBatteryFull";
});

module FaBatteryHalf = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBatteryHalf";
});

module FaBatteryQuarter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBatteryQuarter";
});

module FaBatteryThreeQuarters = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBatteryThreeQuarters";
});

module FaBed = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBed";
});

module FaBeer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBeer";
});

module FaBellSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBellSlash";
});

module FaBell = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBell";
});

module FaBicycle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBicycle";
});

module FaBinoculars = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBinoculars";
});

module FaBirthdayCake = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBirthdayCake";
});

module FaBlender = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBlender";
});

module FaBlind = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBlind";
});

module FaBold = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBold";
});

module FaBolt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBolt";
});

module FaBomb = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBomb";
});

module FaBookOpen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBookOpen";
});

module FaBook = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBook";
});

module FaBookmark = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBookmark";
});

module FaBowlingBall = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBowlingBall";
});

module FaBoxOpen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBoxOpen";
});

module FaBox = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBox";
});

module FaBoxes = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBoxes";
});

module FaBraille = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBraille";
});

module FaBriefcaseMedical = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBriefcaseMedical";
});

module FaBriefcase = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBriefcase";
});

module FaBroadcastTower = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBroadcastTower";
});

module FaBroom = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBroom";
});

module FaBug = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBug";
});

module FaBuilding = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBuilding";
});

module FaBullhorn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBullhorn";
});

module FaBullseye = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBullseye";
});

module FaBurn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBurn";
});

module FaBus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaBus";
});

module FaCalculator = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCalculator";
});

module FaCalendarAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCalendarAlt";
});

module FaCalendarCheck = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCalendarCheck";
});

module FaCalendarMinus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCalendarMinus";
});

module FaCalendarPlus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCalendarPlus";
});

module FaCalendarTimes = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCalendarTimes";
});

module FaCalendar = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCalendar";
});

module FaCameraRetro = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCameraRetro";
});

module FaCamera = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCamera";
});

module FaCapsules = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCapsules";
});

module FaCar = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCar";
});

module FaCaretDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretDown";
});

module FaCaretLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretLeft";
});

module FaCaretRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretRight";
});

module FaCaretSquareDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretSquareDown";
});

module FaCaretSquareLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretSquareLeft";
});

module FaCaretSquareRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretSquareRight";
});

module FaCaretSquareUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretSquareUp";
});

module FaCaretUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCaretUp";
});

module FaCartArrowDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCartArrowDown";
});

module FaCartPlus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCartPlus";
});

module FaCertificate = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCertificate";
});

module FaChalkboardTeacher = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChalkboardTeacher";
});

module FaChalkboard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChalkboard";
});

module FaChartArea = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChartArea";
});

module FaChartBar = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChartBar";
});

module FaChartLine = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChartLine";
});

module FaChartPie = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChartPie";
});

module FaCheckCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCheckCircle";
});

module FaCheckSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCheckSquare";
});

module FaCheck = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCheck";
});

module FaChessBishop = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChessBishop";
});

module FaChessBoard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChessBoard";
});

module FaChessKing = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChessKing";
});

module FaChessKnight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChessKnight";
});

module FaChessPawn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChessPawn";
});

module FaChessQueen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChessQueen";
});

module FaChessRook = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChessRook";
});

module FaChess = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChess";
});

module FaChevronCircleDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronCircleDown";
});

module FaChevronCircleLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronCircleLeft";
});

module FaChevronCircleRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronCircleRight";
});

module FaChevronCircleUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronCircleUp";
});

module FaChevronDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronDown";
});

module FaChevronLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronLeft";
});

module FaChevronRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronRight";
});

module FaChevronUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChevronUp";
});

module FaChild = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChild";
});

module FaChurch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaChurch";
});

module FaCircleNotch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCircleNotch";
});

module FaCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCircle";
});

module FaClipboardCheck = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaClipboardCheck";
});

module FaClipboardList = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaClipboardList";
});

module FaClipboard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaClipboard";
});

module FaClock = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaClock";
});

module FaClone = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaClone";
});

module FaClosedCaptioning = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaClosedCaptioning";
});

module FaCloudDownloadAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCloudDownloadAlt";
});

module FaCloudUploadAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCloudUploadAlt";
});

module FaCloud = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCloud";
});

module FaCodeBranch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCodeBranch";
});

module FaCode = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCode";
});

module FaCoffee = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCoffee";
});

module FaCog = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCog";
});

module FaCogs = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCogs";
});

module FaCoins = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCoins";
});

module FaColumns = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaColumns";
});

module FaCommentAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCommentAlt";
});

module FaCommentDots = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCommentDots";
});

module FaCommentSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCommentSlash";
});

module FaComment = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaComment";
});

module FaComments = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaComments";
});

module FaCompactDisc = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCompactDisc";
});

module FaCompass = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCompass";
});

module FaCompress = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCompress";
});

module FaCopy = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCopy";
});

module FaCopyright = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCopyright";
});

module FaCouch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCouch";
});

module FaCreditCard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCreditCard";
});

module FaCrop = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCrop";
});

module FaCrosshairs = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCrosshairs";
});

module FaCrow = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCrow";
});

module FaCrown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCrown";
});

module FaCube = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCube";
});

module FaCubes = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCubes";
});

module FaCut = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaCut";
});

module FaDatabase = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDatabase";
});

module FaDeaf = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDeaf";
});

module FaDesktop = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDesktop";
});

module FaDiagnoses = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiagnoses";
});

module FaDiceFive = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiceFive";
});

module FaDiceFour = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiceFour";
});

module FaDiceOne = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiceOne";
});

module FaDiceSix = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiceSix";
});

module FaDiceThree = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiceThree";
});

module FaDiceTwo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDiceTwo";
});

module FaDice = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDice";
});

module FaDivide = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDivide";
});

module FaDna = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDna";
});

module FaDollarSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDollarSign";
});

module FaDollyFlatbed = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDollyFlatbed";
});

module FaDolly = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDolly";
});

module FaDonate = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDonate";
});

module FaDoorClosed = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDoorClosed";
});

module FaDoorOpen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDoorOpen";
});

module FaDotCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDotCircle";
});

module FaDove = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDove";
});

module FaDownload = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDownload";
});

module FaDumbbell = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaDumbbell";
});

module FaEdit = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEdit";
});

module FaEject = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEject";
});

module FaEllipsisH = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEllipsisH";
});

module FaEllipsisV = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEllipsisV";
});

module FaEnvelopeOpen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEnvelopeOpen";
});

module FaEnvelopeSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEnvelopeSquare";
});

module FaEnvelope = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEnvelope";
});

module FaEquals = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEquals";
});

module FaEraser = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEraser";
});

module FaEuroSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEuroSign";
});

module FaExchangeAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExchangeAlt";
});

module FaExclamationCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExclamationCircle";
});

module FaExclamationTriangle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExclamationTriangle";
});

module FaExclamation = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExclamation";
});

module FaExpandArrowsAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExpandArrowsAlt";
});

module FaExpand = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExpand";
});

module FaExternalLinkAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExternalLinkAlt";
});

module FaExternalLinkSquareAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaExternalLinkSquareAlt";
});

module FaEyeDropper = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEyeDropper";
});

module FaEyeSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEyeSlash";
});

module FaEye = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaEye";
});

module FaFastBackward = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFastBackward";
});

module FaFastForward = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFastForward";
});

module FaFax = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFax";
});

module FaFeather = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFeather";
});

module FaFemale = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFemale";
});

module FaFighterJet = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFighterJet";
});

module FaFileAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileAlt";
});

module FaFileArchive = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileArchive";
});

module FaFileAudio = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileAudio";
});

module FaFileCode = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileCode";
});

module FaFileExcel = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileExcel";
});

module FaFileImage = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileImage";
});

module FaFileMedicalAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileMedicalAlt";
});

module FaFileMedical = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileMedical";
});

module FaFilePdf = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFilePdf";
});

module FaFilePowerpoint = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFilePowerpoint";
});

module FaFileVideo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileVideo";
});

module FaFileWord = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFileWord";
});

module FaFile = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFile";
});

module FaFilm = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFilm";
});

module FaFilter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFilter";
});

module FaFireExtinguisher = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFireExtinguisher";
});

module FaFire = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFire";
});

module FaFirstAid = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFirstAid";
});

module FaFlagCheckered = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFlagCheckered";
});

module FaFlag = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFlag";
});

module FaFlask = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFlask";
});

module FaFolderOpen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFolderOpen";
});

module FaFolder = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFolder";
});

module FaFont = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFont";
});

module FaFootballBall = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFootballBall";
});

module FaForward = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaForward";
});

module FaFrog = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFrog";
});

module FaFrown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFrown";
});

module FaFutbol = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaFutbol";
});

module FaGamepad = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGamepad";
});

module FaGasPump = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGasPump";
});

module FaGavel = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGavel";
});

module FaGem = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGem";
});

module FaGenderless = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGenderless";
});

module FaGift = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGift";
});

module FaGlassMartini = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGlassMartini";
});

module FaGlasses = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGlasses";
});

module FaGlobe = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGlobe";
});

module FaGolfBall = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGolfBall";
});

module FaGraduationCap = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGraduationCap";
});

module FaGreaterThanEqual = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGreaterThanEqual";
});

module FaGreaterThan = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaGreaterThan";
});

module FaHSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHSquare";
});

module FaHandHoldingHeart = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandHoldingHeart";
});

module FaHandHoldingUsd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandHoldingUsd";
});

module FaHandHolding = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandHolding";
});

module FaHandLizard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandLizard";
});

module FaHandPaper = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandPaper";
});

module FaHandPeace = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandPeace";
});

module FaHandPointDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandPointDown";
});

module FaHandPointLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandPointLeft";
});

module FaHandPointRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandPointRight";
});

module FaHandPointUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandPointUp";
});

module FaHandPointer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandPointer";
});

module FaHandRock = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandRock";
});

module FaHandScissors = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandScissors";
});

module FaHandSpock = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandSpock";
});

module FaHandsHelping = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandsHelping";
});

module FaHands = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHands";
});

module FaHandshake = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHandshake";
});

module FaHashtag = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHashtag";
});

module FaHdd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHdd";
});

module FaHeading = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHeading";
});

module FaHeadphones = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHeadphones";
});

module FaHeart = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHeart";
});

module FaHeartbeat = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHeartbeat";
});

module FaHelicopter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHelicopter";
});

module FaHistory = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHistory";
});

module FaHockeyPuck = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHockeyPuck";
});

module FaHome = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHome";
});

module FaHospitalAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHospitalAlt";
});

module FaHospitalSymbol = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHospitalSymbol";
});

module FaHospital = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHospital";
});

module FaHourglassEnd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHourglassEnd";
});

module FaHourglassHalf = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHourglassHalf";
});

module FaHourglassStart = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHourglassStart";
});

module FaHourglass = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaHourglass";
});

module FaICursor = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaICursor";
});

module FaIdBadge = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaIdBadge";
});

module FaIdCardAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaIdCardAlt";
});

module FaIdCard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaIdCard";
});

module FaImage = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaImage";
});

module FaImages = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaImages";
});

module FaInbox = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaInbox";
});

module FaIndent = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaIndent";
});

module FaIndustry = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaIndustry";
});

module FaInfinity = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaInfinity";
});

module FaInfoCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaInfoCircle";
});

module FaInfo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaInfo";
});

module FaItalic = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaItalic";
});

module FaKey = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKey";
});

module FaKeyboard = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKeyboard";
});

module FaKiwiBird = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaKiwiBird";
});

module FaLanguage = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLanguage";
});

module FaLaptop = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLaptop";
});

module FaLeaf = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLeaf";
});

module FaLemon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLemon";
});

module FaLessThanEqual = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLessThanEqual";
});

module FaLessThan = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLessThan";
});

module FaLevelDownAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLevelDownAlt";
});

module FaLevelUpAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLevelUpAlt";
});

module FaLifeRing = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLifeRing";
});

module FaLightbulb = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLightbulb";
});

module FaLink = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLink";
});

module FaLiraSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLiraSign";
});

module FaListAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaListAlt";
});

module FaListOl = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaListOl";
});

module FaListUl = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaListUl";
});

module FaList = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaList";
});

module FaLocationArrow = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLocationArrow";
});

module FaLockOpen = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLockOpen";
});

module FaLock = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLock";
});

module FaLongArrowAltDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLongArrowAltDown";
});

module FaLongArrowAltLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLongArrowAltLeft";
});

module FaLongArrowAltRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLongArrowAltRight";
});

module FaLongArrowAltUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLongArrowAltUp";
});

module FaLowVision = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaLowVision";
});

module FaMagic = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMagic";
});

module FaMagnet = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMagnet";
});

module FaMale = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMale";
});

module FaMapMarkerAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMapMarkerAlt";
});

module FaMapMarker = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMapMarker";
});

module FaMapPin = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMapPin";
});

module FaMapSigns = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMapSigns";
});

module FaMap = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMap";
});

module FaMarsDouble = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMarsDouble";
});

module FaMarsStrokeH = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMarsStrokeH";
});

module FaMarsStrokeV = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMarsStrokeV";
});

module FaMarsStroke = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMarsStroke";
});

module FaMars = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMars";
});

module FaMedkit = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMedkit";
});

module FaMeh = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMeh";
});

module FaMemory = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMemory";
});

module FaMercury = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMercury";
});

module FaMicrochip = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMicrochip";
});

module FaMicrophoneAltSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMicrophoneAltSlash";
});

module FaMicrophoneAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMicrophoneAlt";
});

module FaMicrophoneSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMicrophoneSlash";
});

module FaMicrophone = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMicrophone";
});

module FaMinusCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMinusCircle";
});

module FaMinusSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMinusSquare";
});

module FaMinus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMinus";
});

module FaMobileAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMobileAlt";
});

module FaMobile = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMobile";
});

module FaMoneyBillAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMoneyBillAlt";
});

module FaMoneyBillWaveAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMoneyBillWaveAlt";
});

module FaMoneyBillWave = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMoneyBillWave";
});

module FaMoneyBill = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMoneyBill";
});

module FaMoneyCheckAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMoneyCheckAlt";
});

module FaMoneyCheck = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMoneyCheck";
});

module FaMoon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMoon";
});

module FaMotorcycle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMotorcycle";
});

module FaMousePointer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMousePointer";
});

module FaMusic = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaMusic";
});

module FaNeuter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNeuter";
});

module FaNewspaper = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNewspaper";
});

module FaNotEqual = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNotEqual";
});

module FaNotesMedical = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaNotesMedical";
});

module FaObjectGroup = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaObjectGroup";
});

module FaObjectUngroup = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaObjectUngroup";
});

module FaOutdent = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaOutdent";
});

module FaPaintBrush = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPaintBrush";
});

module FaPalette = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPalette";
});

module FaPallet = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPallet";
});

module FaPaperPlane = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPaperPlane";
});

module FaPaperclip = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPaperclip";
});

module FaParachuteBox = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaParachuteBox";
});

module FaParagraph = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaParagraph";
});

module FaParking = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaParking";
});

module FaPaste = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPaste";
});

module FaPauseCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPauseCircle";
});

module FaPause = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPause";
});

module FaPaw = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPaw";
});

module FaPenSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPenSquare";
});

module FaPencilAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPencilAlt";
});

module FaPeopleCarry = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPeopleCarry";
});

module FaPercent = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPercent";
});

module FaPercentage = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPercentage";
});

module FaPhoneSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhoneSlash";
});

module FaPhoneSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhoneSquare";
});

module FaPhoneVolume = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhoneVolume";
});

module FaPhone = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPhone";
});

module FaPiggyBank = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPiggyBank";
});

module FaPills = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPills";
});

module FaPlane = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlane";
});

module FaPlayCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlayCircle";
});

module FaPlay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlay";
});

module FaPlug = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlug";
});

module FaPlusCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlusCircle";
});

module FaPlusSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlusSquare";
});

module FaPlus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPlus";
});

module FaPodcast = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPodcast";
});

module FaPoo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPoo";
});

module FaPortrait = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPortrait";
});

module FaPoundSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPoundSign";
});

module FaPowerOff = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPowerOff";
});

module FaPrescriptionBottleAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPrescriptionBottleAlt";
});

module FaPrescriptionBottle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPrescriptionBottle";
});

module FaPrint = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPrint";
});

module FaProcedures = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaProcedures";
});

module FaProjectDiagram = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaProjectDiagram";
});

module FaPuzzlePiece = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaPuzzlePiece";
});

module FaQrcode = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQrcode";
});

module FaQuestionCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQuestionCircle";
});

module FaQuestion = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQuestion";
});

module FaQuidditch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQuidditch";
});

module FaQuoteLeft = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQuoteLeft";
});

module FaQuoteRight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaQuoteRight";
});

module FaRandom = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRandom";
});

module FaReceipt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaReceipt";
});

module FaRecycle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRecycle";
});

module FaRedoAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRedoAlt";
});

module FaRedo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRedo";
});

module FaRegistered = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRegistered";
});

module FaReplyAll = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaReplyAll";
});

module FaReply = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaReply";
});

module FaRetweet = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRetweet";
});

module FaRibbon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRibbon";
});

module FaRoad = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRoad";
});

module FaRobot = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRobot";
});

module FaRocket = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRocket";
});

module FaRssSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRssSquare";
});

module FaRss = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRss";
});

module FaRubleSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRubleSign";
});

module FaRulerCombined = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRulerCombined";
});

module FaRulerHorizontal = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRulerHorizontal";
});

module FaRulerVertical = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRulerVertical";
});

module FaRuler = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRuler";
});

module FaRupeeSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaRupeeSign";
});

module FaSave = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSave";
});

module FaSchool = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSchool";
});

module FaScrewdriver = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaScrewdriver";
});

module FaSearchMinus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSearchMinus";
});

module FaSearchPlus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSearchPlus";
});

module FaSearch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSearch";
});

module FaSeedling = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSeedling";
});

module FaServer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaServer";
});

module FaShareAltSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShareAltSquare";
});

module FaShareAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShareAlt";
});

module FaShareSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShareSquare";
});

module FaShare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShare";
});

module FaShekelSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShekelSign";
});

module FaShieldAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShieldAlt";
});

module FaShip = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShip";
});

module FaShippingFast = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShippingFast";
});

module FaShoePrints = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShoePrints";
});

module FaShoppingBag = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShoppingBag";
});

module FaShoppingBasket = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShoppingBasket";
});

module FaShoppingCart = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShoppingCart";
});

module FaShower = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaShower";
});

module FaSignInAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSignInAlt";
});

module FaSignLanguage = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSignLanguage";
});

module FaSignOutAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSignOutAlt";
});

module FaSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSign";
});

module FaSignal = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSignal";
});

module FaSitemap = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSitemap";
});

module FaSkull = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSkull";
});

module FaSlidersH = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSlidersH";
});

module FaSmile = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSmile";
});

module FaSmokingBan = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSmokingBan";
});

module FaSmoking = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSmoking";
});

module FaSnowflake = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSnowflake";
});

module FaSortAlphaDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortAlphaDown";
});

module FaSortAlphaUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortAlphaUp";
});

module FaSortAmountDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortAmountDown";
});

module FaSortAmountUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortAmountUp";
});

module FaSortDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortDown";
});

module FaSortNumericDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortNumericDown";
});

module FaSortNumericUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortNumericUp";
});

module FaSortUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSortUp";
});

module FaSort = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSort";
});

module FaSpaceShuttle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSpaceShuttle";
});

module FaSpinner = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSpinner";
});

module FaSquareFull = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSquareFull";
});

module FaSquare = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSquare";
});

module FaStarHalf = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStarHalf";
});

module FaStar = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStar";
});

module FaStepBackward = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStepBackward";
});

module FaStepForward = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStepForward";
});

module FaStethoscope = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStethoscope";
});

module FaStickyNote = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStickyNote";
});

module FaStopCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStopCircle";
});

module FaStop = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStop";
});

module FaStopwatch = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStopwatch";
});

module FaStoreAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStoreAlt";
});

module FaStore = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStore";
});

module FaStream = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStream";
});

module FaStreetView = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStreetView";
});

module FaStrikethrough = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStrikethrough";
});

module FaStroopwafel = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaStroopwafel";
});

module FaSubscript = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSubscript";
});

module FaSubway = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSubway";
});

module FaSuitcase = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSuitcase";
});

module FaSun = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSun";
});

module FaSuperscript = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSuperscript";
});

module FaSyncAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSyncAlt";
});

module FaSync = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSync";
});

module FaSyringe = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaSyringe";
});

module FaTableTennis = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTableTennis";
});

module FaTable = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTable";
});

module FaTabletAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTabletAlt";
});

module FaTablet = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTablet";
});

module FaTablets = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTablets";
});

module FaTachometerAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTachometerAlt";
});

module FaTag = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTag";
});

module FaTags = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTags";
});

module FaTape = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTape";
});

module FaTasks = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTasks";
});

module FaTaxi = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTaxi";
});

module FaTerminal = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTerminal";
});

module FaTextHeight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTextHeight";
});

module FaTextWidth = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTextWidth";
});

module FaThLarge = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThLarge";
});

module FaThList = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThList";
});

module FaTh = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTh";
});

module FaThermometerEmpty = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThermometerEmpty";
});

module FaThermometerFull = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThermometerFull";
});

module FaThermometerHalf = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThermometerHalf";
});

module FaThermometerQuarter = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThermometerQuarter";
});

module FaThermometerThreeQuarters = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThermometerThreeQuarters";
});

module FaThermometer = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThermometer";
});

module FaThumbsDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThumbsDown";
});

module FaThumbsUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThumbsUp";
});

module FaThumbtack = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaThumbtack";
});

module FaTicketAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTicketAlt";
});

module FaTimesCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTimesCircle";
});

module FaTimes = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTimes";
});

module FaTint = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTint";
});

module FaToggleOff = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaToggleOff";
});

module FaToggleOn = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaToggleOn";
});

module FaToolbox = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaToolbox";
});

module FaTrademark = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTrademark";
});

module FaTrain = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTrain";
});

module FaTransgenderAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTransgenderAlt";
});

module FaTransgender = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTransgender";
});

module FaTrashAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTrashAlt";
});

module FaTrash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTrash";
});

module FaTree = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTree";
});

module FaTrophy = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTrophy";
});

module FaTruckLoading = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTruckLoading";
});

module FaTruckMoving = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTruckMoving";
});

module FaTruck = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTruck";
});

module FaTshirt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTshirt";
});

module FaTty = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTty";
});

module FaTv = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaTv";
});

module FaUmbrella = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUmbrella";
});

module FaUnderline = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUnderline";
});

module FaUndoAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUndoAlt";
});

module FaUndo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUndo";
});

module FaUniversalAccess = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUniversalAccess";
});

module FaUniversity = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUniversity";
});

module FaUnlink = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUnlink";
});

module FaUnlockAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUnlockAlt";
});

module FaUnlock = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUnlock";
});

module FaUpload = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUpload";
});

module FaUserAltSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserAltSlash";
});

module FaUserAlt = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserAlt";
});

module FaUserAstronaut = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserAstronaut";
});

module FaUserCheck = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserCheck";
});

module FaUserCircle = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserCircle";
});

module FaUserClock = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserClock";
});

module FaUserCog = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserCog";
});

module FaUserEdit = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserEdit";
});

module FaUserFriends = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserFriends";
});

module FaUserGraduate = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserGraduate";
});

module FaUserLock = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserLock";
});

module FaUserMd = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserMd";
});

module FaUserMinus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserMinus";
});

module FaUserNinja = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserNinja";
});

module FaUserPlus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserPlus";
});

module FaUserSecret = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserSecret";
});

module FaUserShield = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserShield";
});

module FaUserSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserSlash";
});

module FaUserTag = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserTag";
});

module FaUserTie = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserTie";
});

module FaUserTimes = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUserTimes";
});

module FaUser = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUser";
});

module FaUsersCog = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUsersCog";
});

module FaUsers = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUsers";
});

module FaUtensilSpoon = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUtensilSpoon";
});

module FaUtensils = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaUtensils";
});

module FaVenusDouble = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVenusDouble";
});

module FaVenusMars = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVenusMars";
});

module FaVenus = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVenus";
});

module FaVial = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVial";
});

module FaVials = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVials";
});

module FaVideoSlash = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVideoSlash";
});

module FaVideo = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVideo";
});

module FaVolleyballBall = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVolleyballBall";
});

module FaVolumeDown = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVolumeDown";
});

module FaVolumeOff = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVolumeOff";
});

module FaVolumeUp = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaVolumeUp";
});

module FaWalking = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWalking";
});

module FaWallet = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWallet";
});

module FaWarehouse = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWarehouse";
});

module FaWeight = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWeight";
});

module FaWheelchair = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWheelchair";
});

module FaWifi = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWifi";
});

module FaWindowClose = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWindowClose";
});

module FaWindowMaximize = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWindowMaximize";
});

module FaWindowMinimize = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWindowMinimize";
});

module FaWindowRestore = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWindowRestore";
});

module FaWineGlass = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWineGlass";
});

module FaWonSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWonSign";
});

module FaWrench = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaWrench";
});

module FaXRay = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaXRay";
});

module FaYenSign = MakeIcon({
  [@bs.module "react-icons/fa"] 
  external reactClass : ReasonReact.reactClass = "FaYenSign";
});

module IoIosAddCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAddCircleOutline";
});

module IoIosAddCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAddCircle";
});

module IoIosAdd = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAdd";
});

module IoIosAirplane = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAirplane";
});

module IoIosAlarm = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAlarm";
});

module IoIosAlbums = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAlbums";
});

module IoIosAlert = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAlert";
});

module IoIosAmericanFootball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAmericanFootball";
});

module IoIosAnalytics = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAnalytics";
});

module IoIosAperture = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAperture";
});

module IoIosApps = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosApps";
});

module IoIosAppstore = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAppstore";
});

module IoIosArchive = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArchive";
});

module IoIosArrowBack = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowBack";
});

module IoIosArrowDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDown";
});

module IoIosArrowDropdownCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDropdownCircle";
});

module IoIosArrowDropdown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDropdown";
});

module IoIosArrowDropleftCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDropleftCircle";
});

module IoIosArrowDropleft = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDropleft";
});

module IoIosArrowDroprightCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDroprightCircle";
});

module IoIosArrowDropright = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDropright";
});

module IoIosArrowDropupCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDropupCircle";
});

module IoIosArrowDropup = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowDropup";
});

module IoIosArrowForward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowForward";
});

module IoIosArrowRoundBack = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowRoundBack";
});

module IoIosArrowRoundDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowRoundDown";
});

module IoIosArrowRoundForward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowRoundForward";
});

module IoIosArrowRoundUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowRoundUp";
});

module IoIosArrowUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosArrowUp";
});

module IoIosAt = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAt";
});

module IoIosAttach = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosAttach";
});

module IoIosBackspace = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBackspace";
});

module IoIosBarcode = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBarcode";
});

module IoIosBaseball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBaseball";
});

module IoIosBasket = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBasket";
});

module IoIosBasketball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBasketball";
});

module IoIosBatteryCharging = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBatteryCharging";
});

module IoIosBatteryDead = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBatteryDead";
});

module IoIosBatteryFull = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBatteryFull";
});

module IoIosBeaker = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBeaker";
});

module IoIosBed = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBed";
});

module IoIosBeer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBeer";
});

module IoIosBicycle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBicycle";
});

module IoIosBluetooth = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBluetooth";
});

module IoIosBoat = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBoat";
});

module IoIosBody = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBody";
});

module IoIosBonfire = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBonfire";
});

module IoIosBook = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBook";
});

module IoIosBookmark = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBookmark";
});

module IoIosBookmarks = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBookmarks";
});

module IoIosBowtie = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBowtie";
});

module IoIosBriefcase = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBriefcase";
});

module IoIosBrowsers = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBrowsers";
});

module IoIosBrush = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBrush";
});

module IoIosBug = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBug";
});

module IoIosBuild = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBuild";
});

module IoIosBulb = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBulb";
});

module IoIosBus = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBus";
});

module IoIosBusiness = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosBusiness";
});

module IoIosCafe = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCafe";
});

module IoIosCalculator = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCalculator";
});

module IoIosCalendar = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCalendar";
});

module IoIosCall = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCall";
});

module IoIosCamera = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCamera";
});

module IoIosCar = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCar";
});

module IoIosCard = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCard";
});

module IoIosCart = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCart";
});

module IoIosCash = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCash";
});

module IoIosCellular = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCellular";
});

module IoIosChatboxes = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosChatboxes";
});

module IoIosChatbubbles = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosChatbubbles";
});

module IoIosCheckboxOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCheckboxOutline";
});

module IoIosCheckbox = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCheckbox";
});

module IoIosCheckmarkCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCheckmarkCircleOutline";
});

module IoIosCheckmarkCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCheckmarkCircle";
});

module IoIosCheckmark = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCheckmark";
});

module IoIosClipboard = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosClipboard";
});

module IoIosClock = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosClock";
});

module IoIosCloseCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloseCircleOutline";
});

module IoIosCloseCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloseCircle";
});

module IoIosClose = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosClose";
});

module IoIosCloudCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloudCircle";
});

module IoIosCloudDone = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloudDone";
});

module IoIosCloudDownload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloudDownload";
});

module IoIosCloudOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloudOutline";
});

module IoIosCloudUpload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloudUpload";
});

module IoIosCloud = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloud";
});

module IoIosCloudyNight = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloudyNight";
});

module IoIosCloudy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCloudy";
});

module IoIosCodeDownload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCodeDownload";
});

module IoIosCodeWorking = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCodeWorking";
});

module IoIosCode = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCode";
});

module IoIosCog = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCog";
});

module IoIosColorFill = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosColorFill";
});

module IoIosColorFilter = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosColorFilter";
});

module IoIosColorPalette = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosColorPalette";
});

module IoIosColorWand = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosColorWand";
});

module IoIosCompass = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCompass";
});

module IoIosConstruct = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosConstruct";
});

module IoIosContact = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosContact";
});

module IoIosContacts = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosContacts";
});

module IoIosContract = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosContract";
});

module IoIosContrast = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosContrast";
});

module IoIosCopy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCopy";
});

module IoIosCreate = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCreate";
});

module IoIosCrop = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCrop";
});

module IoIosCube = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCube";
});

module IoIosCut = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosCut";
});

module IoIosDesktop = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosDesktop";
});

module IoIosDisc = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosDisc";
});

module IoIosDocument = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosDocument";
});

module IoIosDoneAll = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosDoneAll";
});

module IoIosDownload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosDownload";
});

module IoIosEasel = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosEasel";
});

module IoIosEgg = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosEgg";
});

module IoIosExit = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosExit";
});

module IoIosExpand = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosExpand";
});

module IoIosEyeOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosEyeOff";
});

module IoIosEye = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosEye";
});

module IoIosFastforward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFastforward";
});

module IoIosFemale = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFemale";
});

module IoIosFiling = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFiling";
});

module IoIosFilm = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFilm";
});

module IoIosFingerPrint = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFingerPrint";
});

module IoIosFitness = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFitness";
});

module IoIosFlag = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFlag";
});

module IoIosFlame = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFlame";
});

module IoIosFlashOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFlashOff";
});

module IoIosFlash = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFlash";
});

module IoIosFlashlight = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFlashlight";
});

module IoIosFlask = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFlask";
});

module IoIosFlower = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFlower";
});

module IoIosFolderOpen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFolderOpen";
});

module IoIosFolder = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFolder";
});

module IoIosFootball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFootball";
});

module IoIosFunnel = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosFunnel";
});

module IoIosGift = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGift";
});

module IoIosGitBranch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGitBranch";
});

module IoIosGitCommit = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGitCommit";
});

module IoIosGitCompare = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGitCompare";
});

module IoIosGitMerge = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGitMerge";
});

module IoIosGitNetwork = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGitNetwork";
});

module IoIosGitPullRequest = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGitPullRequest";
});

module IoIosGlasses = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGlasses";
});

module IoIosGlobe = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGlobe";
});

module IoIosGrid = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosGrid";
});

module IoIosHammer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHammer";
});

module IoIosHand = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHand";
});

module IoIosHappy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHappy";
});

module IoIosHeadset = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHeadset";
});

module IoIosHeartDislike = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHeartDislike";
});

module IoIosHeartEmpty = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHeartEmpty";
});

module IoIosHeartHalf = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHeartHalf";
});

module IoIosHeart = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHeart";
});

module IoIosHelpBuoy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHelpBuoy";
});

module IoIosHelpCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHelpCircleOutline";
});

module IoIosHelpCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHelpCircle";
});

module IoIosHelp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHelp";
});

module IoIosHome = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHome";
});

module IoIosHourglass = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosHourglass";
});

module IoIosIceCream = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosIceCream";
});

module IoIosImage = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosImage";
});

module IoIosImages = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosImages";
});

module IoIosInfinite = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosInfinite";
});

module IoIosInformationCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosInformationCircleOutline";
});

module IoIosInformationCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosInformationCircle";
});

module IoIosInformation = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosInformation";
});

module IoIosJet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosJet";
});

module IoIosJournal = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosJournal";
});

module IoIosKey = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosKey";
});

module IoIosKeypad = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosKeypad";
});

module IoIosLaptop = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosLaptop";
});

module IoIosLeaf = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosLeaf";
});

module IoIosLink = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosLink";
});

module IoIosListBox = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosListBox";
});

module IoIosList = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosList";
});

module IoIosLocate = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosLocate";
});

module IoIosLock = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosLock";
});

module IoIosLogIn = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosLogIn";
});

module IoIosLogOut = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosLogOut";
});

module IoIosMagnet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMagnet";
});

module IoIosMailOpen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMailOpen";
});

module IoIosMailUnread = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMailUnread";
});

module IoIosMail = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMail";
});

module IoIosMale = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMale";
});

module IoIosMan = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMan";
});

module IoIosMap = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMap";
});

module IoIosMedal = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMedal";
});

module IoIosMedical = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMedical";
});

module IoIosMedkit = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMedkit";
});

module IoIosMegaphone = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMegaphone";
});

module IoIosMenu = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMenu";
});

module IoIosMicOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMicOff";
});

module IoIosMic = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMic";
});

module IoIosMicrophone = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMicrophone";
});

module IoIosMoon = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMoon";
});

module IoIosMore = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMore";
});

module IoIosMove = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMove";
});

module IoIosMusicalNote = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMusicalNote";
});

module IoIosMusicalNotes = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosMusicalNotes";
});

module IoIosNavigate = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosNavigate";
});

module IoIosNotificationsOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosNotificationsOff";
});

module IoIosNotificationsOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosNotificationsOutline";
});

module IoIosNotifications = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosNotifications";
});

module IoIosNuclear = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosNuclear";
});

module IoIosNutrition = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosNutrition";
});

module IoIosOpen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosOpen";
});

module IoIosOptions = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosOptions";
});

module IoIosOutlet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosOutlet";
});

module IoIosPaperPlane = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPaperPlane";
});

module IoIosPaper = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPaper";
});

module IoIosPartlySunny = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPartlySunny";
});

module IoIosPause = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPause";
});

module IoIosPaw = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPaw";
});

module IoIosPeople = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPeople";
});

module IoIosPersonAdd = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPersonAdd";
});

module IoIosPerson = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPerson";
});

module IoIosPhoneLandscape = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPhoneLandscape";
});

module IoIosPhonePortrait = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPhonePortrait";
});

module IoIosPhotos = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPhotos";
});

module IoIosPie = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPie";
});

module IoIosPin = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPin";
});

module IoIosPint = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPint";
});

module IoIosPizza = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPizza";
});

module IoIosPlanet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPlanet";
});

module IoIosPlayCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPlayCircle";
});

module IoIosPlay = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPlay";
});

module IoIosPodium = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPodium";
});

module IoIosPower = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPower";
});

module IoIosPricetag = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPricetag";
});

module IoIosPricetags = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPricetags";
});

module IoIosPrint = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPrint";
});

module IoIosPulse = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosPulse";
});

module IoIosQrScanner = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosQrScanner";
});

module IoIosQuote = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosQuote";
});

module IoIosRadioButtonOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRadioButtonOff";
});

module IoIosRadioButtonOn = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRadioButtonOn";
});

module IoIosRadio = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRadio";
});

module IoIosRainy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRainy";
});

module IoIosRecording = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRecording";
});

module IoIosRedo = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRedo";
});

module IoIosRefreshCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRefreshCircle";
});

module IoIosRefresh = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRefresh";
});

module IoIosRemoveCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRemoveCircleOutline";
});

module IoIosRemoveCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRemoveCircle";
});

module IoIosRemove = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRemove";
});

module IoIosReorder = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosReorder";
});

module IoIosRepeat = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRepeat";
});

module IoIosResize = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosResize";
});

module IoIosRestaurant = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRestaurant";
});

module IoIosReturnLeft = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosReturnLeft";
});

module IoIosReturnRight = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosReturnRight";
});

module IoIosReverseCamera = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosReverseCamera";
});

module IoIosRewind = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRewind";
});

module IoIosRibbon = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRibbon";
});

module IoIosRocket = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRocket";
});

module IoIosRose = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosRose";
});

module IoIosSad = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSad";
});

module IoIosSave = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSave";
});

module IoIosSchool = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSchool";
});

module IoIosSearch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSearch";
});

module IoIosSend = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSend";
});

module IoIosSettings = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSettings";
});

module IoIosShareAlt = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosShareAlt";
});

module IoIosShare = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosShare";
});

module IoIosShirt = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosShirt";
});

module IoIosShuffle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosShuffle";
});

module IoIosSkipBackward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSkipBackward";
});

module IoIosSkipForward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSkipForward";
});

module IoIosSnow = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSnow";
});

module IoIosSpeedometer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSpeedometer";
});

module IoIosSquareOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSquareOutline";
});

module IoIosSquare = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSquare";
});

module IoIosStarHalf = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosStarHalf";
});

module IoIosStarOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosStarOutline";
});

module IoIosStar = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosStar";
});

module IoIosStats = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosStats";
});

module IoIosStopwatch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosStopwatch";
});

module IoIosSubway = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSubway";
});

module IoIosSunny = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSunny";
});

module IoIosSwap = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSwap";
});

module IoIosSwitch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSwitch";
});

module IoIosSync = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosSync";
});

module IoIosTabletLandscape = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTabletLandscape";
});

module IoIosTabletPortrait = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTabletPortrait";
});

module IoIosTennisball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTennisball";
});

module IoIosText = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosText";
});

module IoIosThermometer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosThermometer";
});

module IoIosThumbsDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosThumbsDown";
});

module IoIosThumbsUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosThumbsUp";
});

module IoIosThunderstorm = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosThunderstorm";
});

module IoIosTime = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTime";
});

module IoIosTimer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTimer";
});

module IoIosToday = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosToday";
});

module IoIosTrain = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTrain";
});

module IoIosTransgender = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTransgender";
});

module IoIosTrash = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTrash";
});

module IoIosTrendingDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTrendingDown";
});

module IoIosTrendingUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTrendingUp";
});

module IoIosTrophy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTrophy";
});

module IoIosTv = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosTv";
});

module IoIosUmbrella = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosUmbrella";
});

module IoIosUndo = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosUndo";
});

module IoIosUnlock = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosUnlock";
});

module IoIosVideocam = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosVideocam";
});

module IoIosVolumeHigh = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosVolumeHigh";
});

module IoIosVolumeLow = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosVolumeLow";
});

module IoIosVolumeMute = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosVolumeMute";
});

module IoIosVolumeOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosVolumeOff";
});

module IoIosWalk = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWalk";
});

module IoIosWallet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWallet";
});

module IoIosWarning = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWarning";
});

module IoIosWatch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWatch";
});

module IoIosWater = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWater";
});

module IoIosWifi = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWifi";
});

module IoIosWine = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWine";
});

module IoIosWoman = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoIosWoman";
});

module IoLogoAndroid = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoAndroid";
});

module IoLogoAngular = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoAngular";
});

module IoLogoApple = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoApple";
});

module IoLogoBitbucket = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoBitbucket";
});

module IoLogoBitcoin = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoBitcoin";
});

module IoLogoBuffer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoBuffer";
});

module IoLogoChrome = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoChrome";
});

module IoLogoClosedCaptioning = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoClosedCaptioning";
});

module IoLogoCodepen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoCodepen";
});

module IoLogoCss3 = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoCss3";
});

module IoLogoDesignernews = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoDesignernews";
});

module IoLogoDribbble = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoDribbble";
});

module IoLogoDropbox = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoDropbox";
});

module IoLogoEuro = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoEuro";
});

module IoLogoFacebook = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoFacebook";
});

module IoLogoFlickr = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoFlickr";
});

module IoLogoFoursquare = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoFoursquare";
});

module IoLogoFreebsdDevil = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoFreebsdDevil";
});

module IoLogoGameControllerA = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoGameControllerA";
});

module IoLogoGameControllerB = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoGameControllerB";
});

module IoLogoGithub = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoGithub";
});

module IoLogoGoogle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoGoogle";
});

module IoLogoGoogleplus = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoGoogleplus";
});

module IoLogoHackernews = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoHackernews";
});

module IoLogoHtml5 = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoHtml5";
});

module IoLogoInstagram = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoInstagram";
});

module IoLogoIonic = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoIonic";
});

module IoLogoIonitron = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoIonitron";
});

module IoLogoJavascript = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoJavascript";
});

module IoLogoLinkedin = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoLinkedin";
});

module IoLogoMarkdown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoMarkdown";
});

module IoLogoModelS = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoModelS";
});

module IoLogoNoSmoking = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoNoSmoking";
});

module IoLogoNodejs = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoNodejs";
});

module IoLogoNpm = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoNpm";
});

module IoLogoOctocat = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoOctocat";
});

module IoLogoPinterest = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoPinterest";
});

module IoLogoPlaystation = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoPlaystation";
});

module IoLogoPolymer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoPolymer";
});

module IoLogoPython = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoPython";
});

module IoLogoReddit = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoReddit";
});

module IoLogoRss = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoRss";
});

module IoLogoSass = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoSass";
});

module IoLogoSkype = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoSkype";
});

module IoLogoSlack = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoSlack";
});

module IoLogoSnapchat = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoSnapchat";
});

module IoLogoSteam = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoSteam";
});

module IoLogoTumblr = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoTumblr";
});

module IoLogoTux = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoTux";
});

module IoLogoTwitch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoTwitch";
});

module IoLogoTwitter = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoTwitter";
});

module IoLogoUsd = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoUsd";
});

module IoLogoVimeo = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoVimeo";
});

module IoLogoVk = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoVk";
});

module IoLogoWhatsapp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoWhatsapp";
});

module IoLogoWindows = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoWindows";
});

module IoLogoWordpress = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoWordpress";
});

module IoLogoXbox = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoXbox";
});

module IoLogoXing = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoXing";
});

module IoLogoYahoo = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoYahoo";
});

module IoLogoYen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoYen";
});

module IoLogoYoutube = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoLogoYoutube";
});

module IoMdAddCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAddCircleOutline";
});

module IoMdAddCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAddCircle";
});

module IoMdAdd = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAdd";
});

module IoMdAirplane = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAirplane";
});

module IoMdAlarm = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAlarm";
});

module IoMdAlbums = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAlbums";
});

module IoMdAlert = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAlert";
});

module IoMdAmericanFootball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAmericanFootball";
});

module IoMdAnalytics = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAnalytics";
});

module IoMdAperture = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAperture";
});

module IoMdApps = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdApps";
});

module IoMdAppstore = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAppstore";
});

module IoMdArchive = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArchive";
});

module IoMdArrowBack = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowBack";
});

module IoMdArrowDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDown";
});

module IoMdArrowDropdownCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDropdownCircle";
});

module IoMdArrowDropdown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDropdown";
});

module IoMdArrowDropleftCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDropleftCircle";
});

module IoMdArrowDropleft = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDropleft";
});

module IoMdArrowDroprightCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDroprightCircle";
});

module IoMdArrowDropright = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDropright";
});

module IoMdArrowDropupCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDropupCircle";
});

module IoMdArrowDropup = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowDropup";
});

module IoMdArrowForward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowForward";
});

module IoMdArrowRoundBack = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowRoundBack";
});

module IoMdArrowRoundDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowRoundDown";
});

module IoMdArrowRoundForward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowRoundForward";
});

module IoMdArrowRoundUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowRoundUp";
});

module IoMdArrowUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdArrowUp";
});

module IoMdAt = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAt";
});

module IoMdAttach = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdAttach";
});

module IoMdBackspace = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBackspace";
});

module IoMdBarcode = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBarcode";
});

module IoMdBaseball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBaseball";
});

module IoMdBasket = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBasket";
});

module IoMdBasketball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBasketball";
});

module IoMdBatteryCharging = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBatteryCharging";
});

module IoMdBatteryDead = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBatteryDead";
});

module IoMdBatteryFull = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBatteryFull";
});

module IoMdBeaker = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBeaker";
});

module IoMdBed = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBed";
});

module IoMdBeer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBeer";
});

module IoMdBicycle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBicycle";
});

module IoMdBluetooth = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBluetooth";
});

module IoMdBoat = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBoat";
});

module IoMdBody = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBody";
});

module IoMdBonfire = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBonfire";
});

module IoMdBook = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBook";
});

module IoMdBookmark = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBookmark";
});

module IoMdBookmarks = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBookmarks";
});

module IoMdBowtie = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBowtie";
});

module IoMdBriefcase = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBriefcase";
});

module IoMdBrowsers = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBrowsers";
});

module IoMdBrush = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBrush";
});

module IoMdBug = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBug";
});

module IoMdBuild = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBuild";
});

module IoMdBulb = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBulb";
});

module IoMdBus = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBus";
});

module IoMdBusiness = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdBusiness";
});

module IoMdCafe = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCafe";
});

module IoMdCalculator = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCalculator";
});

module IoMdCalendar = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCalendar";
});

module IoMdCall = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCall";
});

module IoMdCamera = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCamera";
});

module IoMdCar = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCar";
});

module IoMdCard = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCard";
});

module IoMdCart = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCart";
});

module IoMdCash = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCash";
});

module IoMdCellular = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCellular";
});

module IoMdChatboxes = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdChatboxes";
});

module IoMdChatbubbles = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdChatbubbles";
});

module IoMdCheckboxOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCheckboxOutline";
});

module IoMdCheckbox = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCheckbox";
});

module IoMdCheckmarkCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCheckmarkCircleOutline";
});

module IoMdCheckmarkCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCheckmarkCircle";
});

module IoMdCheckmark = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCheckmark";
});

module IoMdClipboard = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdClipboard";
});

module IoMdClock = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdClock";
});

module IoMdCloseCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloseCircleOutline";
});

module IoMdCloseCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloseCircle";
});

module IoMdClose = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdClose";
});

module IoMdCloudCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloudCircle";
});

module IoMdCloudDone = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloudDone";
});

module IoMdCloudDownload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloudDownload";
});

module IoMdCloudOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloudOutline";
});

module IoMdCloudUpload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloudUpload";
});

module IoMdCloud = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloud";
});

module IoMdCloudyNight = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloudyNight";
});

module IoMdCloudy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCloudy";
});

module IoMdCodeDownload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCodeDownload";
});

module IoMdCodeWorking = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCodeWorking";
});

module IoMdCode = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCode";
});

module IoMdCog = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCog";
});

module IoMdColorFill = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdColorFill";
});

module IoMdColorFilter = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdColorFilter";
});

module IoMdColorPalette = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdColorPalette";
});

module IoMdColorWand = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdColorWand";
});

module IoMdCompass = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCompass";
});

module IoMdConstruct = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdConstruct";
});

module IoMdContact = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdContact";
});

module IoMdContacts = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdContacts";
});

module IoMdContract = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdContract";
});

module IoMdContrast = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdContrast";
});

module IoMdCopy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCopy";
});

module IoMdCreate = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCreate";
});

module IoMdCrop = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCrop";
});

module IoMdCube = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCube";
});

module IoMdCut = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdCut";
});

module IoMdDesktop = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdDesktop";
});

module IoMdDisc = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdDisc";
});

module IoMdDocument = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdDocument";
});

module IoMdDoneAll = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdDoneAll";
});

module IoMdDownload = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdDownload";
});

module IoMdEasel = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdEasel";
});

module IoMdEgg = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdEgg";
});

module IoMdExit = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdExit";
});

module IoMdExpand = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdExpand";
});

module IoMdEyeOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdEyeOff";
});

module IoMdEye = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdEye";
});

module IoMdFastforward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFastforward";
});

module IoMdFemale = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFemale";
});

module IoMdFiling = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFiling";
});

module IoMdFilm = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFilm";
});

module IoMdFingerPrint = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFingerPrint";
});

module IoMdFitness = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFitness";
});

module IoMdFlag = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFlag";
});

module IoMdFlame = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFlame";
});

module IoMdFlashOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFlashOff";
});

module IoMdFlash = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFlash";
});

module IoMdFlashlight = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFlashlight";
});

module IoMdFlask = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFlask";
});

module IoMdFlower = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFlower";
});

module IoMdFolderOpen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFolderOpen";
});

module IoMdFolder = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFolder";
});

module IoMdFootball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFootball";
});

module IoMdFunnel = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdFunnel";
});

module IoMdGift = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGift";
});

module IoMdGitBranch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGitBranch";
});

module IoMdGitCommit = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGitCommit";
});

module IoMdGitCompare = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGitCompare";
});

module IoMdGitMerge = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGitMerge";
});

module IoMdGitNetwork = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGitNetwork";
});

module IoMdGitPullRequest = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGitPullRequest";
});

module IoMdGlasses = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGlasses";
});

module IoMdGlobe = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGlobe";
});

module IoMdGrid = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdGrid";
});

module IoMdHammer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHammer";
});

module IoMdHand = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHand";
});

module IoMdHappy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHappy";
});

module IoMdHeadset = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHeadset";
});

module IoMdHeartDislike = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHeartDislike";
});

module IoMdHeartEmpty = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHeartEmpty";
});

module IoMdHeartHalf = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHeartHalf";
});

module IoMdHeart = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHeart";
});

module IoMdHelpBuoy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHelpBuoy";
});

module IoMdHelpCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHelpCircleOutline";
});

module IoMdHelpCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHelpCircle";
});

module IoMdHelp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHelp";
});

module IoMdHome = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHome";
});

module IoMdHourglass = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdHourglass";
});

module IoMdIceCream = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdIceCream";
});

module IoMdImage = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdImage";
});

module IoMdImages = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdImages";
});

module IoMdInfinite = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdInfinite";
});

module IoMdInformationCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdInformationCircleOutline";
});

module IoMdInformationCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdInformationCircle";
});

module IoMdInformation = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdInformation";
});

module IoMdJet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdJet";
});

module IoMdJournal = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdJournal";
});

module IoMdKey = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdKey";
});

module IoMdKeypad = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdKeypad";
});

module IoMdLaptop = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdLaptop";
});

module IoMdLeaf = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdLeaf";
});

module IoMdLink = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdLink";
});

module IoMdListBox = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdListBox";
});

module IoMdList = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdList";
});

module IoMdLocate = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdLocate";
});

module IoMdLock = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdLock";
});

module IoMdLogIn = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdLogIn";
});

module IoMdLogOut = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdLogOut";
});

module IoMdMagnet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMagnet";
});

module IoMdMailOpen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMailOpen";
});

module IoMdMailUnread = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMailUnread";
});

module IoMdMail = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMail";
});

module IoMdMale = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMale";
});

module IoMdMan = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMan";
});

module IoMdMap = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMap";
});

module IoMdMedal = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMedal";
});

module IoMdMedical = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMedical";
});

module IoMdMedkit = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMedkit";
});

module IoMdMegaphone = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMegaphone";
});

module IoMdMenu = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMenu";
});

module IoMdMicOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMicOff";
});

module IoMdMic = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMic";
});

module IoMdMicrophone = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMicrophone";
});

module IoMdMoon = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMoon";
});

module IoMdMore = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMore";
});

module IoMdMove = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMove";
});

module IoMdMusicalNote = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMusicalNote";
});

module IoMdMusicalNotes = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdMusicalNotes";
});

module IoMdNavigate = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdNavigate";
});

module IoMdNotificationsOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdNotificationsOff";
});

module IoMdNotificationsOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdNotificationsOutline";
});

module IoMdNotifications = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdNotifications";
});

module IoMdNuclear = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdNuclear";
});

module IoMdNutrition = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdNutrition";
});

module IoMdOpen = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdOpen";
});

module IoMdOptions = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdOptions";
});

module IoMdOutlet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdOutlet";
});

module IoMdPaperPlane = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPaperPlane";
});

module IoMdPaper = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPaper";
});

module IoMdPartlySunny = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPartlySunny";
});

module IoMdPause = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPause";
});

module IoMdPaw = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPaw";
});

module IoMdPeople = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPeople";
});

module IoMdPersonAdd = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPersonAdd";
});

module IoMdPerson = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPerson";
});

module IoMdPhoneLandscape = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPhoneLandscape";
});

module IoMdPhonePortrait = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPhonePortrait";
});

module IoMdPhotos = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPhotos";
});

module IoMdPie = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPie";
});

module IoMdPin = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPin";
});

module IoMdPint = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPint";
});

module IoMdPizza = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPizza";
});

module IoMdPlanet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPlanet";
});

module IoMdPlayCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPlayCircle";
});

module IoMdPlay = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPlay";
});

module IoMdPodium = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPodium";
});

module IoMdPower = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPower";
});

module IoMdPricetag = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPricetag";
});

module IoMdPricetags = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPricetags";
});

module IoMdPrint = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPrint";
});

module IoMdPulse = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdPulse";
});

module IoMdQrScanner = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdQrScanner";
});

module IoMdQuote = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdQuote";
});

module IoMdRadioButtonOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRadioButtonOff";
});

module IoMdRadioButtonOn = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRadioButtonOn";
});

module IoMdRadio = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRadio";
});

module IoMdRainy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRainy";
});

module IoMdRecording = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRecording";
});

module IoMdRedo = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRedo";
});

module IoMdRefreshCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRefreshCircle";
});

module IoMdRefresh = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRefresh";
});

module IoMdRemoveCircleOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRemoveCircleOutline";
});

module IoMdRemoveCircle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRemoveCircle";
});

module IoMdRemove = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRemove";
});

module IoMdReorder = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdReorder";
});

module IoMdRepeat = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRepeat";
});

module IoMdResize = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdResize";
});

module IoMdRestaurant = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRestaurant";
});

module IoMdReturnLeft = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdReturnLeft";
});

module IoMdReturnRight = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdReturnRight";
});

module IoMdReverseCamera = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdReverseCamera";
});

module IoMdRewind = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRewind";
});

module IoMdRibbon = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRibbon";
});

module IoMdRocket = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRocket";
});

module IoMdRose = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdRose";
});

module IoMdSad = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSad";
});

module IoMdSave = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSave";
});

module IoMdSchool = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSchool";
});

module IoMdSearch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSearch";
});

module IoMdSend = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSend";
});

module IoMdSettings = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSettings";
});

module IoMdShareAlt = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdShareAlt";
});

module IoMdShare = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdShare";
});

module IoMdShirt = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdShirt";
});

module IoMdShuffle = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdShuffle";
});

module IoMdSkipBackward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSkipBackward";
});

module IoMdSkipForward = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSkipForward";
});

module IoMdSnow = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSnow";
});

module IoMdSpeedometer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSpeedometer";
});

module IoMdSquareOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSquareOutline";
});

module IoMdSquare = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSquare";
});

module IoMdStarHalf = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdStarHalf";
});

module IoMdStarOutline = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdStarOutline";
});

module IoMdStar = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdStar";
});

module IoMdStats = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdStats";
});

module IoMdStopwatch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdStopwatch";
});

module IoMdSubway = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSubway";
});

module IoMdSunny = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSunny";
});

module IoMdSwap = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSwap";
});

module IoMdSwitch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSwitch";
});

module IoMdSync = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdSync";
});

module IoMdTabletLandscape = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTabletLandscape";
});

module IoMdTabletPortrait = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTabletPortrait";
});

module IoMdTennisball = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTennisball";
});

module IoMdText = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdText";
});

module IoMdThermometer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdThermometer";
});

module IoMdThumbsDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdThumbsDown";
});

module IoMdThumbsUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdThumbsUp";
});

module IoMdThunderstorm = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdThunderstorm";
});

module IoMdTime = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTime";
});

module IoMdTimer = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTimer";
});

module IoMdToday = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdToday";
});

module IoMdTrain = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTrain";
});

module IoMdTransgender = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTransgender";
});

module IoMdTrash = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTrash";
});

module IoMdTrendingDown = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTrendingDown";
});

module IoMdTrendingUp = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTrendingUp";
});

module IoMdTrophy = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTrophy";
});

module IoMdTv = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdTv";
});

module IoMdUmbrella = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdUmbrella";
});

module IoMdUndo = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdUndo";
});

module IoMdUnlock = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdUnlock";
});

module IoMdVideocam = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdVideocam";
});

module IoMdVolumeHigh = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdVolumeHigh";
});

module IoMdVolumeLow = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdVolumeLow";
});

module IoMdVolumeMute = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdVolumeMute";
});

module IoMdVolumeOff = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdVolumeOff";
});

module IoMdWalk = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWalk";
});

module IoMdWallet = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWallet";
});

module IoMdWarning = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWarning";
});

module IoMdWatch = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWatch";
});

module IoMdWater = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWater";
});

module IoMdWifi = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWifi";
});

module IoMdWine = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWine";
});

module IoMdWoman = MakeIcon({
  [@bs.module "react-icons/io"] 
  external reactClass : ReasonReact.reactClass = "IoMdWoman";
});

module Md3dRotation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "Md3dRotation";
});

module MdAccessibility = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccessibility";
});

module MdAccessible = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccessible";
});

module MdAccountBalance = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccountBalance";
});

module MdAccountBalanceWallet = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccountBalanceWallet";
});

module MdAccountBox = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccountBox";
});

module MdAccountCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccountCircle";
});

module MdAddShoppingCart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddShoppingCart";
});

module MdAlarm = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAlarm";
});

module MdAlarmAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAlarmAdd";
});

module MdAlarmOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAlarmOff";
});

module MdAlarmOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAlarmOn";
});

module MdAllOut = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAllOut";
});

module MdAndroid = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAndroid";
});

module MdAnnouncement = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAnnouncement";
});

module MdAspectRatio = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAspectRatio";
});

module MdAssessment = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssessment";
});

module MdAssignment = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssignment";
});

module MdAssignmentInd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssignmentInd";
});

module MdAssignmentLate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssignmentLate";
});

module MdAssignmentReturn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssignmentReturn";
});

module MdAssignmentReturned = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssignmentReturned";
});

module MdAssignmentTurnedIn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssignmentTurnedIn";
});

module MdAutorenew = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAutorenew";
});

module MdBackup = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBackup";
});

module MdBook = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBook";
});

module MdBookmark = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBookmark";
});

module MdBookmarkBorder = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBookmarkBorder";
});

module MdBugReport = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBugReport";
});

module MdBuild = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBuild";
});

module MdCached = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCached";
});

module MdCameraEnhance = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCameraEnhance";
});

module MdCardGiftcard = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCardGiftcard";
});

module MdCardMembership = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCardMembership";
});

module MdCardTravel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCardTravel";
});

module MdChangeHistory = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChangeHistory";
});

module MdCheckCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCheckCircle";
});

module MdChromeReaderMode = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChromeReaderMode";
});

module MdClass = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdClass";
});

module MdCode = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCode";
});

module MdCompareArrows = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCompareArrows";
});

module MdCopyright = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCopyright";
});

module MdCreditCard = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCreditCard";
});

module MdDashboard = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDashboard";
});

module MdDateRange = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDateRange";
});

module MdDelete = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDelete";
});

module MdDeleteForever = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDeleteForever";
});

module MdDescription = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDescription";
});

module MdDns = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDns";
});

module MdDone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDone";
});

module MdDoneAll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDoneAll";
});

module MdDonutLarge = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDonutLarge";
});

module MdDonutSmall = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDonutSmall";
});

module MdEject = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEject";
});

module MdEuroSymbol = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEuroSymbol";
});

module MdEvent = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEvent";
});

module MdEventSeat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEventSeat";
});

module MdExitToApp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExitToApp";
});

module MdExplore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExplore";
});

module MdExtension = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExtension";
});

module MdFace = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFace";
});

module MdFavorite = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFavorite";
});

module MdFavoriteBorder = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFavoriteBorder";
});

module MdFeedback = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFeedback";
});

module MdFindInPage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFindInPage";
});

module MdFindReplace = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFindReplace";
});

module MdFingerprint = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFingerprint";
});

module MdFlightLand = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlightLand";
});

module MdFlightTakeoff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlightTakeoff";
});

module MdFlipToBack = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlipToBack";
});

module MdFlipToFront = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlipToFront";
});

module MdGTranslate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGTranslate";
});

module MdGavel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGavel";
});

module MdGetApp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGetApp";
});

module MdGif = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGif";
});

module MdGrade = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGrade";
});

module MdGroupWork = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGroupWork";
});

module MdHelp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHelp";
});

module MdHelpOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHelpOutline";
});

module MdHighlightOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHighlightOff";
});

module MdHistory = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHistory";
});

module MdHome = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHome";
});

module MdHourglassEmpty = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHourglassEmpty";
});

module MdHourglassFull = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHourglassFull";
});

module MdHttp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHttp";
});

module MdHttps = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHttps";
});

module MdImportantDevices = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdImportantDevices";
});

module MdInfo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInfo";
});

module MdInfoOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInfoOutline";
});

module MdInput = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInput";
});

module MdInvertColors = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInvertColors";
});

module MdLabel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLabel";
});

module MdLabelOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLabelOutline";
});

module MdLanguage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLanguage";
});

module MdLaunch = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLaunch";
});

module MdLightbulbOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLightbulbOutline";
});

module MdLineStyle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLineStyle";
});

module MdLineWeight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLineWeight";
});

module MdList = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdList";
});

module MdLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLock";
});

module MdLockOpen = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLockOpen";
});

module MdLockOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLockOutline";
});

module MdLoyalty = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLoyalty";
});

module MdMarkunreadMailbox = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMarkunreadMailbox";
});

module MdMotorcycle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMotorcycle";
});

module MdNoteAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNoteAdd";
});

module MdOfflinePin = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdOfflinePin";
});

module MdOpacity = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdOpacity";
});

module MdOpenInBrowser = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdOpenInBrowser";
});

module MdOpenInNew = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdOpenInNew";
});

module MdOpenWith = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdOpenWith";
});

module MdPageview = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPageview";
});

module MdPanTool = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPanTool";
});

module MdPayment = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPayment";
});

module MdPermCameraMic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermCameraMic";
});

module MdPermContactCalendar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermContactCalendar";
});

module MdPermDataSetting = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermDataSetting";
});

module MdPermDeviceInformation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermDeviceInformation";
});

module MdPermIdentity = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermIdentity";
});

module MdPermMedia = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermMedia";
});

module MdPermPhoneMsg = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermPhoneMsg";
});

module MdPermScanWifi = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPermScanWifi";
});

module MdPets = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPets";
});

module MdPictureInPicture = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPictureInPicture";
});

module MdPictureInPictureAlt = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPictureInPictureAlt";
});

module MdPlayForWork = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlayForWork";
});

module MdPolymer = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPolymer";
});

module MdPowerSettingsNew = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPowerSettingsNew";
});

module MdPregnantWoman = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPregnantWoman";
});

module MdPrint = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPrint";
});

module MdQueryBuilder = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdQueryBuilder";
});

module MdQuestionAnswer = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdQuestionAnswer";
});

module MdReceipt = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReceipt";
});

module MdRecordVoiceOver = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRecordVoiceOver";
});

module MdRedeem = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRedeem";
});

module MdRemoveShoppingCart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRemoveShoppingCart";
});

module MdReorder = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReorder";
});

module MdReportProblem = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReportProblem";
});

module MdRestore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRestore";
});

module MdRestorePage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRestorePage";
});

module MdRoom = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRoom";
});

module MdRoundedCorner = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRoundedCorner";
});

module MdRowing = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRowing";
});

module MdSchedule = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSchedule";
});

module MdSearch = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSearch";
});

module MdSettings = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettings";
});

module MdSettingsApplications = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsApplications";
});

module MdSettingsBackupRestore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsBackupRestore";
});

module MdSettingsBluetooth = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsBluetooth";
});

module MdSettingsBrightness = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsBrightness";
});

module MdSettingsCell = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsCell";
});

module MdSettingsEthernet = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsEthernet";
});

module MdSettingsInputAntenna = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsInputAntenna";
});

module MdSettingsInputComponent = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsInputComponent";
});

module MdSettingsInputComposite = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsInputComposite";
});

module MdSettingsInputHdmi = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsInputHdmi";
});

module MdSettingsInputSvideo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsInputSvideo";
});

module MdSettingsOverscan = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsOverscan";
});

module MdSettingsPhone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsPhone";
});

module MdSettingsPower = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsPower";
});

module MdSettingsRemote = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsRemote";
});

module MdSettingsVoice = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsVoice";
});

module MdShop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShop";
});

module MdShopTwo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShopTwo";
});

module MdShoppingBasket = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShoppingBasket";
});

module MdShoppingCart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShoppingCart";
});

module MdSpeakerNotes = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpeakerNotes";
});

module MdSpeakerNotesOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpeakerNotesOff";
});

module MdSpellcheck = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpellcheck";
});

module MdStars = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStars";
});

module MdStore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStore";
});

module MdSubject = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSubject";
});

module MdSupervisorAccount = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSupervisorAccount";
});

module MdSwapHoriz = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSwapHoriz";
});

module MdSwapVert = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSwapVert";
});

module MdSwapVerticalCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSwapVerticalCircle";
});

module MdSystemUpdateAlt = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSystemUpdateAlt";
});

module MdTab = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTab";
});

module MdTabUnselected = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTabUnselected";
});

module MdTheaters = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTheaters";
});

module MdThumbDown = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdThumbDown";
});

module MdThumbUp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdThumbUp";
});

module MdThumbsUpDown = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdThumbsUpDown";
});

module MdTimeline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTimeline";
});

module MdToc = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdToc";
});

module MdToday = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdToday";
});

module MdToll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdToll";
});

module MdTouchApp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTouchApp";
});

module MdTrackChanges = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTrackChanges";
});

module MdTranslate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTranslate";
});

module MdTrendingDown = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTrendingDown";
});

module MdTrendingFlat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTrendingFlat";
});

module MdTrendingUp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTrendingUp";
});

module MdTurnedIn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTurnedIn";
});

module MdTurnedInNot = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTurnedInNot";
});

module MdUpdate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdUpdate";
});

module MdVerifiedUser = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVerifiedUser";
});

module MdViewAgenda = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewAgenda";
});

module MdViewArray = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewArray";
});

module MdViewCarousel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewCarousel";
});

module MdViewColumn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewColumn";
});

module MdViewDay = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewDay";
});

module MdViewHeadline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewHeadline";
});

module MdViewList = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewList";
});

module MdViewModule = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewModule";
});

module MdViewQuilt = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewQuilt";
});

module MdViewStream = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewStream";
});

module MdViewWeek = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewWeek";
});

module MdVisibility = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVisibility";
});

module MdVisibilityOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVisibilityOff";
});

module MdWatchLater = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWatchLater";
});

module MdWork = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWork";
});

module MdYoutubeSearchedFor = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdYoutubeSearchedFor";
});

module MdZoomIn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdZoomIn";
});

module MdZoomOut = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdZoomOut";
});

module MdAddAlert = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddAlert";
});

module MdError = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdError";
});

module MdErrorOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdErrorOutline";
});

module MdWarning = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWarning";
});

module MdAddToQueue = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddToQueue";
});

module MdAirplay = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirplay";
});

module MdAlbum = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAlbum";
});

module MdArtTrack = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArtTrack";
});

module MdAvTimer = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAvTimer";
});

module MdBrandingWatermark = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrandingWatermark";
});

module MdCallToAction = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallToAction";
});

module MdClosedCaption = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdClosedCaption";
});

module MdEqualizer = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEqualizer";
});

module MdExplicit = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExplicit";
});

module MdFastForward = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFastForward";
});

module MdFastRewind = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFastRewind";
});

module MdFeaturedPlayList = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFeaturedPlayList";
});

module MdFeaturedVideo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFeaturedVideo";
});

module MdFiberDvr = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFiberDvr";
});

module MdFiberManualRecord = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFiberManualRecord";
});

module MdFiberNew = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFiberNew";
});

module MdFiberPin = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFiberPin";
});

module MdFiberSmartRecord = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFiberSmartRecord";
});

module MdForward10 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdForward10";
});

module MdForward30 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdForward30";
});

module MdForward5 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdForward5";
});

module MdGames = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGames";
});

module MdHd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHd";
});

module MdHearing = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHearing";
});

module MdHighQuality = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHighQuality";
});

module MdLibraryAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLibraryAdd";
});

module MdLibraryBooks = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLibraryBooks";
});

module MdLibraryMusic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLibraryMusic";
});

module MdLoop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLoop";
});

module MdMic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMic";
});

module MdMicNone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMicNone";
});

module MdMicOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMicOff";
});

module MdMovie = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMovie";
});

module MdMusicVideo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMusicVideo";
});

module MdNewReleases = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNewReleases";
});

module MdNotInterested = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNotInterested";
});

module MdNote = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNote";
});

module MdPause = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPause";
});

module MdPauseCircleFilled = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPauseCircleFilled";
});

module MdPauseCircleOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPauseCircleOutline";
});

module MdPlayArrow = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlayArrow";
});

module MdPlayCircleFilled = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlayCircleFilled";
});

module MdPlayCircleOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlayCircleOutline";
});

module MdPlaylistAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlaylistAdd";
});

module MdPlaylistAddCheck = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlaylistAddCheck";
});

module MdPlaylistPlay = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlaylistPlay";
});

module MdQueue = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdQueue";
});

module MdQueueMusic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdQueueMusic";
});

module MdQueuePlayNext = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdQueuePlayNext";
});

module MdRadio = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRadio";
});

module MdRecentActors = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRecentActors";
});

module MdRemoveFromQueue = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRemoveFromQueue";
});

module MdRepeat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRepeat";
});

module MdRepeatOne = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRepeatOne";
});

module MdReplay10 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReplay10";
});

module MdReplay = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReplay";
});

module MdReplay30 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReplay30";
});

module MdReplay5 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReplay5";
});

module MdShuffle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShuffle";
});

module MdSkipNext = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSkipNext";
});

module MdSkipPrevious = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSkipPrevious";
});

module MdSlowMotionVideo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSlowMotionVideo";
});

module MdSnooze = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSnooze";
});

module MdSortByAlpha = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSortByAlpha";
});

module MdStop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStop";
});

module MdSubscriptions = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSubscriptions";
});

module MdSubtitles = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSubtitles";
});

module MdSurroundSound = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSurroundSound";
});

module MdVideoCall = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVideoCall";
});

module MdVideoLabel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVideoLabel";
});

module MdVideoLibrary = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVideoLibrary";
});

module MdVideocam = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVideocam";
});

module MdVideocamOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVideocamOff";
});

module MdVolumeDown = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVolumeDown";
});

module MdVolumeMute = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVolumeMute";
});

module MdVolumeOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVolumeOff";
});

module MdVolumeUp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVolumeUp";
});

module MdWeb = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWeb";
});

module MdWebAsset = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWebAsset";
});

module MdBusiness = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBusiness";
});

module MdCall = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCall";
});

module MdCallEnd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallEnd";
});

module MdCallMade = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallMade";
});

module MdCallMerge = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallMerge";
});

module MdCallMissed = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallMissed";
});

module MdCallMissedOutgoing = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallMissedOutgoing";
});

module MdCallReceived = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallReceived";
});

module MdCallSplit = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCallSplit";
});

module MdChat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChat";
});

module MdChatBubble = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChatBubble";
});

module MdChatBubbleOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChatBubbleOutline";
});

module MdClearAll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdClearAll";
});

module MdComment = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdComment";
});

module MdContactMail = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdContactMail";
});

module MdContactPhone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdContactPhone";
});

module MdContacts = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdContacts";
});

module MdDialerSip = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDialerSip";
});

module MdDialpad = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDialpad";
});

module MdEmail = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEmail";
});

module MdForum = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdForum";
});

module MdImportContacts = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdImportContacts";
});

module MdImportExport = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdImportExport";
});

module MdInvertColorsOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInvertColorsOff";
});

module MdLiveHelp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLiveHelp";
});

module MdLocationOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocationOff";
});

module MdLocationOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocationOn";
});

module MdMailOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMailOutline";
});

module MdMessage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMessage";
});

module MdNoSim = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNoSim";
});

module MdPhone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhone";
});

module MdPhonelinkErase = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhonelinkErase";
});

module MdPhonelinkLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhonelinkLock";
});

module MdPhonelinkRing = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhonelinkRing";
});

module MdPhonelinkSetup = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhonelinkSetup";
});

module MdPortableWifiOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPortableWifiOff";
});

module MdPresentToAll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPresentToAll";
});

module MdRingVolume = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRingVolume";
});

module MdRssFeed = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRssFeed";
});

module MdScreenShare = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdScreenShare";
});

module MdSpeakerPhone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpeakerPhone";
});

module MdStayCurrentLandscape = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStayCurrentLandscape";
});

module MdStayCurrentPortrait = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStayCurrentPortrait";
});

module MdStayPrimaryLandscape = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStayPrimaryLandscape";
});

module MdStayPrimaryPortrait = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStayPrimaryPortrait";
});

module MdStopScreenShare = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStopScreenShare";
});

module MdSwapCalls = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSwapCalls";
});

module MdTextsms = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTextsms";
});

module MdVoicemail = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVoicemail";
});

module MdVpnKey = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVpnKey";
});

module MdAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAdd";
});

module MdAddBox = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddBox";
});

module MdAddCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddCircle";
});

module MdAddCircleOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddCircleOutline";
});

module MdArchive = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArchive";
});

module MdBackspace = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBackspace";
});

module MdBlock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBlock";
});

module MdClear = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdClear";
});

module MdContentCopy = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdContentCopy";
});

module MdContentCut = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdContentCut";
});

module MdContentPaste = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdContentPaste";
});

module MdCreate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCreate";
});

module MdDeleteSweep = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDeleteSweep";
});

module MdDrafts = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDrafts";
});

module MdFilterList = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterList";
});

module MdFlag = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlag";
});

module MdFontDownload = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFontDownload";
});

module MdForward = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdForward";
});

module MdGesture = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGesture";
});

module MdInbox = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInbox";
});

module MdLink = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLink";
});

module MdLowPriority = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLowPriority";
});

module MdMail = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMail";
});

module MdMarkunread = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMarkunread";
});

module MdMoveToInbox = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMoveToInbox";
});

module MdNextWeek = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNextWeek";
});

module MdRedo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRedo";
});

module MdRemove = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRemove";
});

module MdRemoveCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRemoveCircle";
});

module MdRemoveCircleOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRemoveCircleOutline";
});

module MdReply = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReply";
});

module MdReplyAll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReplyAll";
});

module MdReport = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdReport";
});

module MdSave = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSave";
});

module MdSelectAll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSelectAll";
});

module MdSend = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSend";
});

module MdSort = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSort";
});

module MdTextFormat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTextFormat";
});

module MdUnarchive = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdUnarchive";
});

module MdUndo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdUndo";
});

module MdWeekend = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWeekend";
});

module MdAccessAlarm = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccessAlarm";
});

module MdAccessAlarms = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccessAlarms";
});

module MdAccessTime = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAccessTime";
});

module MdAddAlarm = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddAlarm";
});

module MdAirplanemodeActive = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirplanemodeActive";
});

module MdAirplanemodeInactive = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirplanemodeInactive";
});

module MdBattery20 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBattery20";
});

module MdBattery30 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBattery30";
});

module MdBattery50 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBattery50";
});

module MdBattery60 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBattery60";
});

module MdBattery80 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBattery80";
});

module MdBattery90 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBattery90";
});

module MdBatteryAlert = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryAlert";
});

module MdBatteryCharging20 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryCharging20";
});

module MdBatteryCharging30 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryCharging30";
});

module MdBatteryCharging50 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryCharging50";
});

module MdBatteryCharging60 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryCharging60";
});

module MdBatteryCharging80 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryCharging80";
});

module MdBatteryCharging90 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryCharging90";
});

module MdBatteryChargingFull = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryChargingFull";
});

module MdBatteryFull = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryFull";
});

module MdBatteryStd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryStd";
});

module MdBatteryUnknown = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBatteryUnknown";
});

module MdBluetooth = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBluetooth";
});

module MdBluetoothConnected = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBluetoothConnected";
});

module MdBluetoothDisabled = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBluetoothDisabled";
});

module MdBluetoothSearching = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBluetoothSearching";
});

module MdBrightnessAuto = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightnessAuto";
});

module MdBrightnessHigh = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightnessHigh";
});

module MdBrightnessLow = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightnessLow";
});

module MdBrightnessMedium = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightnessMedium";
});

module MdDataUsage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDataUsage";
});

module MdDeveloperMode = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDeveloperMode";
});

module MdDevices = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDevices";
});

module MdDvr = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDvr";
});

module MdGpsFixed = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGpsFixed";
});

module MdGpsNotFixed = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGpsNotFixed";
});

module MdGpsOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGpsOff";
});

module MdGraphicEq = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGraphicEq";
});

module MdLocationDisabled = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocationDisabled";
});

module MdLocationSearching = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocationSearching";
});

module MdNetworkCell = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNetworkCell";
});

module MdNetworkWifi = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNetworkWifi";
});

module MdNfc = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNfc";
});

module MdScreenLockLandscape = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdScreenLockLandscape";
});

module MdScreenLockPortrait = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdScreenLockPortrait";
});

module MdScreenLockRotation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdScreenLockRotation";
});

module MdScreenRotation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdScreenRotation";
});

module MdSdStorage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSdStorage";
});

module MdSettingsSystemDaydream = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSettingsSystemDaydream";
});

module MdSignalCellular0Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellular0Bar";
});

module MdSignalCellular1Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellular1Bar";
});

module MdSignalCellular2Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellular2Bar";
});

module MdSignalCellular3Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellular3Bar";
});

module MdSignalCellular4Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellular4Bar";
});

module MdSignalCellularConnectedNoInternet0Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularConnectedNoInternet0Bar";
});

module MdSignalCellularConnectedNoInternet1Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularConnectedNoInternet1Bar";
});

module MdSignalCellularConnectedNoInternet2Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularConnectedNoInternet2Bar";
});

module MdSignalCellularConnectedNoInternet3Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularConnectedNoInternet3Bar";
});

module MdSignalCellularConnectedNoInternet4Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularConnectedNoInternet4Bar";
});

module MdSignalCellularNoSim = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularNoSim";
});

module MdSignalCellularNull = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularNull";
});

module MdSignalCellularOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalCellularOff";
});

module MdSignalWifi0Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi0Bar";
});

module MdSignalWifi1Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi1Bar";
});

module MdSignalWifi1BarLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi1BarLock";
});

module MdSignalWifi2Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi2Bar";
});

module MdSignalWifi2BarLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi2BarLock";
});

module MdSignalWifi3Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi3Bar";
});

module MdSignalWifi3BarLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi3BarLock";
});

module MdSignalWifi4Bar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi4Bar";
});

module MdSignalWifi4BarLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifi4BarLock";
});

module MdSignalWifiOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSignalWifiOff";
});

module MdStorage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStorage";
});

module MdUsb = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdUsb";
});

module MdWallpaper = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWallpaper";
});

module MdWidgets = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWidgets";
});

module MdWifiLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWifiLock";
});

module MdWifiTethering = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWifiTethering";
});

module MdAttachFile = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAttachFile";
});

module MdAttachMoney = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAttachMoney";
});

module MdBorderAll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderAll";
});

module MdBorderBottom = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderBottom";
});

module MdBorderClear = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderClear";
});

module MdBorderColor = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderColor";
});

module MdBorderHorizontal = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderHorizontal";
});

module MdBorderInner = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderInner";
});

module MdBorderLeft = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderLeft";
});

module MdBorderOuter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderOuter";
});

module MdBorderRight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderRight";
});

module MdBorderStyle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderStyle";
});

module MdBorderTop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderTop";
});

module MdBorderVertical = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBorderVertical";
});

module MdBubbleChart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBubbleChart";
});

module MdDragHandle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDragHandle";
});

module MdFormatAlignCenter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatAlignCenter";
});

module MdFormatAlignJustify = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatAlignJustify";
});

module MdFormatAlignLeft = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatAlignLeft";
});

module MdFormatAlignRight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatAlignRight";
});

module MdFormatBold = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatBold";
});

module MdFormatClear = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatClear";
});

module MdFormatColorFill = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatColorFill";
});

module MdFormatColorReset = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatColorReset";
});

module MdFormatColorText = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatColorText";
});

module MdFormatIndentDecrease = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatIndentDecrease";
});

module MdFormatIndentIncrease = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatIndentIncrease";
});

module MdFormatItalic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatItalic";
});

module MdFormatLineSpacing = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatLineSpacing";
});

module MdFormatListBulleted = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatListBulleted";
});

module MdFormatListNumbered = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatListNumbered";
});

module MdFormatPaint = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatPaint";
});

module MdFormatQuote = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatQuote";
});

module MdFormatShapes = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatShapes";
});

module MdFormatSize = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatSize";
});

module MdFormatStrikethrough = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatStrikethrough";
});

module MdFormatTextdirectionLToR = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatTextdirectionLToR";
});

module MdFormatTextdirectionRToL = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatTextdirectionRToL";
});

module MdFormatUnderlined = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFormatUnderlined";
});

module MdFunctions = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFunctions";
});

module MdHighlight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHighlight";
});

module MdInsertChart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInsertChart";
});

module MdInsertComment = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInsertComment";
});

module MdInsertDriveFile = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInsertDriveFile";
});

module MdInsertEmoticon = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInsertEmoticon";
});

module MdInsertInvitation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInsertInvitation";
});

module MdInsertLink = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInsertLink";
});

module MdInsertPhoto = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdInsertPhoto";
});

module MdLinearScale = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLinearScale";
});

module MdMergeType = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMergeType";
});

module MdModeComment = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdModeComment";
});

module MdModeEdit = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdModeEdit";
});

module MdMonetizationOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMonetizationOn";
});

module MdMoneyOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMoneyOff";
});

module MdMultilineChart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMultilineChart";
});

module MdPieChart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPieChart";
});

module MdPieChartOutlined = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPieChartOutlined";
});

module MdPublish = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPublish";
});

module MdShortText = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShortText";
});

module MdShowChart = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShowChart";
});

module MdSpaceBar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpaceBar";
});

module MdStrikethroughS = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStrikethroughS";
});

module MdTextFields = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTextFields";
});

module MdTitle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTitle";
});

module MdVerticalAlignBottom = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVerticalAlignBottom";
});

module MdVerticalAlignCenter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVerticalAlignCenter";
});

module MdVerticalAlignTop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVerticalAlignTop";
});

module MdWrapText = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWrapText";
});

module MdAttachment = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAttachment";
});

module MdCloud = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCloud";
});

module MdCloudCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCloudCircle";
});

module MdCloudDone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCloudDone";
});

module MdCloudDownload = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCloudDownload";
});

module MdCloudOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCloudOff";
});

module MdCloudQueue = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCloudQueue";
});

module MdCloudUpload = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCloudUpload";
});

module MdCreateNewFolder = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCreateNewFolder";
});

module MdFileDownload = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFileDownload";
});

module MdFileUpload = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFileUpload";
});

module MdFolder = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFolder";
});

module MdFolderOpen = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFolderOpen";
});

module MdFolderShared = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFolderShared";
});

module MdCast = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCast";
});

module MdCastConnected = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCastConnected";
});

module MdComputer = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdComputer";
});

module MdDesktopMac = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDesktopMac";
});

module MdDesktopWindows = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDesktopWindows";
});

module MdDeveloperBoard = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDeveloperBoard";
});

module MdDeviceHub = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDeviceHub";
});

module MdDevicesOther = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDevicesOther";
});

module MdDock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDock";
});

module MdGamepad = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGamepad";
});

module MdHeadset = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHeadset";
});

module MdHeadsetMic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHeadsetMic";
});

module MdKeyboard = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboard";
});

module MdKeyboardArrowDown = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardArrowDown";
});

module MdKeyboardArrowLeft = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardArrowLeft";
});

module MdKeyboardArrowRight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardArrowRight";
});

module MdKeyboardArrowUp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardArrowUp";
});

module MdKeyboardBackspace = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardBackspace";
});

module MdKeyboardCapslock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardCapslock";
});

module MdKeyboardHide = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardHide";
});

module MdKeyboardReturn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardReturn";
});

module MdKeyboardTab = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardTab";
});

module MdKeyboardVoice = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKeyboardVoice";
});

module MdLaptop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLaptop";
});

module MdLaptopChromebook = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLaptopChromebook";
});

module MdLaptopMac = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLaptopMac";
});

module MdLaptopWindows = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLaptopWindows";
});

module MdMemory = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMemory";
});

module MdMouse = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMouse";
});

module MdPhoneAndroid = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoneAndroid";
});

module MdPhoneIphone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoneIphone";
});

module MdPhonelink = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhonelink";
});

module MdPhonelinkOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhonelinkOff";
});

module MdPowerInput = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPowerInput";
});

module MdRouter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRouter";
});

module MdScanner = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdScanner";
});

module MdSecurity = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSecurity";
});

module MdSimCard = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSimCard";
});

module MdSmartphone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSmartphone";
});

module MdSpeaker = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpeaker";
});

module MdSpeakerGroup = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpeakerGroup";
});

module MdTablet = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTablet";
});

module MdTabletAndroid = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTabletAndroid";
});

module MdTabletMac = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTabletMac";
});

module MdToys = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdToys";
});

module MdTv = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTv";
});

module MdVideogameAsset = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVideogameAsset";
});

module MdWatch = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWatch";
});

module MdAddAPhoto = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddAPhoto";
});

module MdAddToPhotos = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddToPhotos";
});

module MdAdjust = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAdjust";
});

module MdAssistant = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssistant";
});

module MdAssistantPhoto = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAssistantPhoto";
});

module MdAudiotrack = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAudiotrack";
});

module MdBlurCircular = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBlurCircular";
});

module MdBlurLinear = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBlurLinear";
});

module MdBlurOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBlurOff";
});

module MdBlurOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBlurOn";
});

module MdBrightness1 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightness1";
});

module MdBrightness2 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightness2";
});

module MdBrightness3 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightness3";
});

module MdBrightness4 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightness4";
});

module MdBrightness5 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightness5";
});

module MdBrightness6 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightness6";
});

module MdBrightness7 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrightness7";
});

module MdBrokenImage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrokenImage";
});

module MdBrush = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBrush";
});

module MdBurstMode = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBurstMode";
});

module MdCamera = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCamera";
});

module MdCameraAlt = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCameraAlt";
});

module MdCameraFront = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCameraFront";
});

module MdCameraRear = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCameraRear";
});

module MdCameraRoll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCameraRoll";
});

module MdCenterFocusStrong = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCenterFocusStrong";
});

module MdCenterFocusWeak = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCenterFocusWeak";
});

module MdCollections = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCollections";
});

module MdCollectionsBookmark = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCollectionsBookmark";
});

module MdColorLens = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdColorLens";
});

module MdColorize = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdColorize";
});

module MdCompare = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCompare";
});

module MdControlPoint = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdControlPoint";
});

module MdControlPointDuplicate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdControlPointDuplicate";
});

module MdCrop169 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCrop169";
});

module MdCrop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCrop";
});

module MdCrop32 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCrop32";
});

module MdCrop54 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCrop54";
});

module MdCrop75 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCrop75";
});

module MdCropDin = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCropDin";
});

module MdCropFree = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCropFree";
});

module MdCropLandscape = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCropLandscape";
});

module MdCropOriginal = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCropOriginal";
});

module MdCropPortrait = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCropPortrait";
});

module MdCropRotate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCropRotate";
});

module MdCropSquare = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCropSquare";
});

module MdDehaze = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDehaze";
});

module MdDetails = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDetails";
});

module MdEdit = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEdit";
});

module MdExposure = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExposure";
});

module MdExposureNeg1 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExposureNeg1";
});

module MdExposureNeg2 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExposureNeg2";
});

module MdExposurePlus1 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExposurePlus1";
});

module MdExposurePlus2 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExposurePlus2";
});

module MdExposureZero = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExposureZero";
});

module MdFilter1 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter1";
});

module MdFilter2 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter2";
});

module MdFilter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter";
});

module MdFilter3 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter3";
});

module MdFilter4 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter4";
});

module MdFilter5 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter5";
});

module MdFilter6 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter6";
});

module MdFilter7 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter7";
});

module MdFilter8 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter8";
});

module MdFilter9 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter9";
});

module MdFilter9Plus = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilter9Plus";
});

module MdFilterBAndW = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterBAndW";
});

module MdFilterCenterFocus = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterCenterFocus";
});

module MdFilterDrama = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterDrama";
});

module MdFilterFrames = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterFrames";
});

module MdFilterHdr = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterHdr";
});

module MdFilterNone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterNone";
});

module MdFilterTiltShift = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterTiltShift";
});

module MdFilterVintage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFilterVintage";
});

module MdFlare = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlare";
});

module MdFlashAuto = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlashAuto";
});

module MdFlashOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlashOff";
});

module MdFlashOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlashOn";
});

module MdFlip = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlip";
});

module MdGradient = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGradient";
});

module MdGrain = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGrain";
});

module MdGridOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGridOff";
});

module MdGridOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGridOn";
});

module MdHdrOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHdrOff";
});

module MdHdrOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHdrOn";
});

module MdHdrStrong = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHdrStrong";
});

module MdHdrWeak = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHdrWeak";
});

module MdHealing = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHealing";
});

module MdImage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdImage";
});

module MdImageAspectRatio = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdImageAspectRatio";
});

module MdIso = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdIso";
});

module MdLandscape = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLandscape";
});

module MdLeakAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLeakAdd";
});

module MdLeakRemove = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLeakRemove";
});

module MdLens = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLens";
});

module MdLinkedCamera = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLinkedCamera";
});

module MdLooks = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLooks";
});

module MdLooks3 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLooks3";
});

module MdLooks4 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLooks4";
});

module MdLooks5 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLooks5";
});

module MdLooks6 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLooks6";
});

module MdLooksOne = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLooksOne";
});

module MdLooksTwo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLooksTwo";
});

module MdLoupe = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLoupe";
});

module MdMonochromePhotos = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMonochromePhotos";
});

module MdMovieCreation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMovieCreation";
});

module MdMovieFilter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMovieFilter";
});

module MdMusicNote = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMusicNote";
});

module MdNature = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNature";
});

module MdNaturePeople = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNaturePeople";
});

module MdNavigateBefore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNavigateBefore";
});

module MdNavigateNext = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNavigateNext";
});

module MdPalette = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPalette";
});

module MdPanorama = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPanorama";
});

module MdPanoramaFishEye = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPanoramaFishEye";
});

module MdPanoramaHorizontal = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPanoramaHorizontal";
});

module MdPanoramaVertical = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPanoramaVertical";
});

module MdPanoramaWideAngle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPanoramaWideAngle";
});

module MdPhoto = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoto";
});

module MdPhotoAlbum = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhotoAlbum";
});

module MdPhotoCamera = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhotoCamera";
});

module MdPhotoFilter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhotoFilter";
});

module MdPhotoLibrary = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhotoLibrary";
});

module MdPhotoSizeSelectActual = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhotoSizeSelectActual";
});

module MdPhotoSizeSelectLarge = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhotoSizeSelectLarge";
});

module MdPhotoSizeSelectSmall = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhotoSizeSelectSmall";
});

module MdPictureAsPdf = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPictureAsPdf";
});

module MdPortrait = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPortrait";
});

module MdRemoveRedEye = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRemoveRedEye";
});

module MdRotate90DegreesCcw = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRotate90DegreesCcw";
});

module MdRotateLeft = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRotateLeft";
});

module MdRotateRight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRotateRight";
});

module MdSlideshow = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSlideshow";
});

module MdStraighten = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStraighten";
});

module MdStyle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStyle";
});

module MdSwitchCamera = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSwitchCamera";
});

module MdSwitchVideo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSwitchVideo";
});

module MdTagFaces = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTagFaces";
});

module MdTexture = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTexture";
});

module MdTimelapse = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTimelapse";
});

module MdTimer10 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTimer10";
});

module MdTimer = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTimer";
});

module MdTimer3 = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTimer3";
});

module MdTimerOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTimerOff";
});

module MdTonality = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTonality";
});

module MdTransform = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTransform";
});

module MdTune = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTune";
});

module MdViewComfy = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewComfy";
});

module MdViewCompact = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdViewCompact";
});

module MdVignette = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVignette";
});

module MdWbAuto = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWbAuto";
});

module MdWbCloudy = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWbCloudy";
});

module MdWbIncandescent = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWbIncandescent";
});

module MdWbIridescent = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWbIridescent";
});

module MdWbSunny = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWbSunny";
});

module MdAddLocation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAddLocation";
});

module MdBeenhere = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBeenhere";
});

module MdDirections = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirections";
});

module MdDirectionsBike = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsBike";
});

module MdDirectionsBoat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsBoat";
});

module MdDirectionsBus = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsBus";
});

module MdDirectionsCar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsCar";
});

module MdDirectionsRailway = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsRailway";
});

module MdDirectionsRun = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsRun";
});

module MdDirectionsSubway = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsSubway";
});

module MdDirectionsTransit = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsTransit";
});

module MdDirectionsWalk = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDirectionsWalk";
});

module MdEditLocation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEditLocation";
});

module MdEvStation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEvStation";
});

module MdFlight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFlight";
});

module MdHotel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHotel";
});

module MdLayers = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLayers";
});

module MdLayersClear = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLayersClear";
});

module MdLocalActivity = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalActivity";
});

module MdLocalAirport = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalAirport";
});

module MdLocalAtm = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalAtm";
});

module MdLocalBar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalBar";
});

module MdLocalCafe = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalCafe";
});

module MdLocalCarWash = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalCarWash";
});

module MdLocalConvenienceStore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalConvenienceStore";
});

module MdLocalDining = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalDining";
});

module MdLocalDrink = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalDrink";
});

module MdLocalFlorist = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalFlorist";
});

module MdLocalGasStation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalGasStation";
});

module MdLocalGroceryStore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalGroceryStore";
});

module MdLocalHospital = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalHospital";
});

module MdLocalHotel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalHotel";
});

module MdLocalLaundryService = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalLaundryService";
});

module MdLocalLibrary = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalLibrary";
});

module MdLocalMall = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalMall";
});

module MdLocalMovies = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalMovies";
});

module MdLocalOffer = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalOffer";
});

module MdLocalParking = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalParking";
});

module MdLocalPharmacy = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalPharmacy";
});

module MdLocalPhone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalPhone";
});

module MdLocalPizza = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalPizza";
});

module MdLocalPlay = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalPlay";
});

module MdLocalPostOffice = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalPostOffice";
});

module MdLocalPrintshop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalPrintshop";
});

module MdLocalSee = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalSee";
});

module MdLocalShipping = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalShipping";
});

module MdLocalTaxi = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocalTaxi";
});

module MdMap = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMap";
});

module MdMyLocation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMyLocation";
});

module MdNavigation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNavigation";
});

module MdNearMe = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNearMe";
});

module MdPersonPin = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPersonPin";
});

module MdPersonPinCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPersonPinCircle";
});

module MdPinDrop = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPinDrop";
});

module MdPlace = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlace";
});

module MdRateReview = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRateReview";
});

module MdRestaurant = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRestaurant";
});

module MdRestaurantMenu = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRestaurantMenu";
});

module MdSatellite = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSatellite";
});

module MdStoreMallDirectory = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStoreMallDirectory";
});

module MdStreetview = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStreetview";
});

module MdSubway = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSubway";
});

module MdTerrain = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTerrain";
});

module MdTraffic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTraffic";
});

module MdTrain = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTrain";
});

module MdTram = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTram";
});

module MdTransferWithinAStation = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTransferWithinAStation";
});

module MdZoomOutMap = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdZoomOutMap";
});

module MdApps = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdApps";
});

module MdArrowBack = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArrowBack";
});

module MdArrowDownward = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArrowDownward";
});

module MdArrowDropDown = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArrowDropDown";
});

module MdArrowDropDownCircle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArrowDropDownCircle";
});

module MdArrowDropUp = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArrowDropUp";
});

module MdArrowForward = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArrowForward";
});

module MdArrowUpward = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdArrowUpward";
});

module MdCancel = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCancel";
});

module MdCheck = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCheck";
});

module MdChevronLeft = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChevronLeft";
});

module MdChevronRight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChevronRight";
});

module MdClose = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdClose";
});

module MdExpandLess = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExpandLess";
});

module MdExpandMore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdExpandMore";
});

module MdFirstPage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFirstPage";
});

module MdFullscreen = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFullscreen";
});

module MdFullscreenExit = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFullscreenExit";
});

module MdLastPage = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLastPage";
});

module MdMenu = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMenu";
});

module MdMoreHoriz = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMoreHoriz";
});

module MdMoreVert = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMoreVert";
});

module MdRefresh = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRefresh";
});

module MdSubdirectoryArrowLeft = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSubdirectoryArrowLeft";
});

module MdSubdirectoryArrowRight = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSubdirectoryArrowRight";
});

module MdUnfoldLess = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdUnfoldLess";
});

module MdUnfoldMore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdUnfoldMore";
});

module MdAdb = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAdb";
});

module MdAirlineSeatFlat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatFlat";
});

module MdAirlineSeatFlatAngled = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatFlatAngled";
});

module MdAirlineSeatIndividualSuite = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatIndividualSuite";
});

module MdAirlineSeatLegroomExtra = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatLegroomExtra";
});

module MdAirlineSeatLegroomNormal = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatLegroomNormal";
});

module MdAirlineSeatLegroomReduced = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatLegroomReduced";
});

module MdAirlineSeatReclineExtra = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatReclineExtra";
});

module MdAirlineSeatReclineNormal = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirlineSeatReclineNormal";
});

module MdBluetoothAudio = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBluetoothAudio";
});

module MdConfirmationNumber = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdConfirmationNumber";
});

module MdDiscFull = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDiscFull";
});

module MdDoNotDisturb = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDoNotDisturb";
});

module MdDoNotDisturbAlt = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDoNotDisturbAlt";
});

module MdDoNotDisturbOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDoNotDisturbOff";
});

module MdDoNotDisturbOn = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDoNotDisturbOn";
});

module MdDriveEta = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDriveEta";
});

module MdEnhancedEncryption = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEnhancedEncryption";
});

module MdEventAvailable = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEventAvailable";
});

module MdEventBusy = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEventBusy";
});

module MdEventNote = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdEventNote";
});

module MdFolderSpecial = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFolderSpecial";
});

module MdLiveTv = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLiveTv";
});

module MdMms = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMms";
});

module MdMore = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMore";
});

module MdNetworkCheck = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNetworkCheck";
});

module MdNetworkLocked = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNetworkLocked";
});

module MdNoEncryption = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNoEncryption";
});

module MdOndemandVideo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdOndemandVideo";
});

module MdPersonalVideo = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPersonalVideo";
});

module MdPhoneBluetoothSpeaker = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoneBluetoothSpeaker";
});

module MdPhoneForwarded = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoneForwarded";
});

module MdPhoneInTalk = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoneInTalk";
});

module MdPhoneLocked = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoneLocked";
});

module MdPhoneMissed = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhoneMissed";
});

module MdPhonePaused = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPhonePaused";
});

module MdPower = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPower";
});

module MdPriorityHigh = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPriorityHigh";
});

module MdRvHookup = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRvHookup";
});

module MdSdCard = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSdCard";
});

module MdSimCardAlert = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSimCardAlert";
});

module MdSms = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSms";
});

module MdSmsFailed = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSmsFailed";
});

module MdSync = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSync";
});

module MdSyncDisabled = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSyncDisabled";
});

module MdSyncProblem = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSyncProblem";
});

module MdSystemUpdate = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSystemUpdate";
});

module MdTapAndPlay = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTapAndPlay";
});

module MdTimeToLeave = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdTimeToLeave";
});

module MdVibration = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVibration";
});

module MdVoiceChat = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVoiceChat";
});

module MdVpnLock = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdVpnLock";
});

module MdWc = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWc";
});

module MdWifi = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWifi";
});

module MdAcUnit = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAcUnit";
});

module MdAirportShuttle = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAirportShuttle";
});

module MdAllInclusive = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdAllInclusive";
});

module MdBeachAccess = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBeachAccess";
});

module MdBusinessCenter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdBusinessCenter";
});

module MdCasino = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCasino";
});

module MdChildCare = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChildCare";
});

module MdChildFriendly = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdChildFriendly";
});

module MdFitnessCenter = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFitnessCenter";
});

module MdFreeBreakfast = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdFreeBreakfast";
});

module MdGolfCourse = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGolfCourse";
});

module MdHotTub = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdHotTub";
});

module MdKitchen = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdKitchen";
});

module MdPool = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPool";
});

module MdRoomService = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRoomService";
});

module MdSmokeFree = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSmokeFree";
});

module MdSmokingRooms = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSmokingRooms";
});

module MdSpa = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSpa";
});

module MdCake = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCake";
});

module MdDomain = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdDomain";
});

module MdGroup = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGroup";
});

module MdGroupAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdGroupAdd";
});

module MdLocationCity = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdLocationCity";
});

module MdMood = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMood";
});

module MdMoodBad = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdMoodBad";
});

module MdNotifications = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNotifications";
});

module MdNotificationsActive = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNotificationsActive";
});

module MdNotificationsNone = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNotificationsNone";
});

module MdNotificationsOff = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNotificationsOff";
});

module MdNotificationsPaused = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdNotificationsPaused";
});

module MdPages = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPages";
});

module MdPartyMode = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPartyMode";
});

module MdPeople = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPeople";
});

module MdPeopleOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPeopleOutline";
});

module MdPerson = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPerson";
});

module MdPersonAdd = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPersonAdd";
});

module MdPersonOutline = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPersonOutline";
});

module MdPlusOne = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPlusOne";
});

module MdPoll = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPoll";
});

module MdPublic = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdPublic";
});

module MdSchool = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSchool";
});

module MdSentimentDissatisfied = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSentimentDissatisfied";
});

module MdSentimentNeutral = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSentimentNeutral";
});

module MdSentimentSatisfied = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSentimentSatisfied";
});

module MdSentimentVeryDissatisfied = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSentimentVeryDissatisfied";
});

module MdSentimentVerySatisfied = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdSentimentVerySatisfied";
});

module MdShare = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdShare";
});

module MdWhatshot = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdWhatshot";
});

module MdCheckBox = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCheckBox";
});

module MdCheckBoxOutlineBlank = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdCheckBoxOutlineBlank";
});

module MdIndeterminateCheckBox = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdIndeterminateCheckBox";
});

module MdRadioButtonChecked = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRadioButtonChecked";
});

module MdRadioButtonUnchecked = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdRadioButtonUnchecked";
});

module MdStar = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStar";
});

module MdStarBorder = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStarBorder";
});

module MdStarHalf = MakeIcon({
  [@bs.module "react-icons/md"] 
  external reactClass : ReasonReact.reactClass = "MdStarHalf";
});

module TiAdjustBrightness = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiAdjustBrightness";
});

module TiAdjustContrast = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiAdjustContrast";
});

module TiAnchorOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiAnchorOutline";
});

module TiAnchor = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiAnchor";
});

module TiArchive = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArchive";
});

module TiArrowBackOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowBackOutline";
});

module TiArrowBack = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowBack";
});

module TiArrowDownOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowDownOutline";
});

module TiArrowDownThick = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowDownThick";
});

module TiArrowDown = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowDown";
});

module TiArrowForwardOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowForwardOutline";
});

module TiArrowForward = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowForward";
});

module TiArrowLeftOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowLeftOutline";
});

module TiArrowLeftThick = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowLeftThick";
});

module TiArrowLeft = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowLeft";
});

module TiArrowLoopOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowLoopOutline";
});

module TiArrowLoop = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowLoop";
});

module TiArrowMaximiseOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowMaximiseOutline";
});

module TiArrowMaximise = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowMaximise";
});

module TiArrowMinimiseOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowMinimiseOutline";
});

module TiArrowMinimise = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowMinimise";
});

module TiArrowMoveOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowMoveOutline";
});

module TiArrowMove = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowMove";
});

module TiArrowRepeatOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowRepeatOutline";
});

module TiArrowRepeat = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowRepeat";
});

module TiArrowRightOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowRightOutline";
});

module TiArrowRightThick = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowRightThick";
});

module TiArrowRight = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowRight";
});

module TiArrowShuffle = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowShuffle";
});

module TiArrowSortedDown = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowSortedDown";
});

module TiArrowSortedUp = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowSortedUp";
});

module TiArrowSyncOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowSyncOutline";
});

module TiArrowSync = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowSync";
});

module TiArrowUnsorted = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowUnsorted";
});

module TiArrowUpOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowUpOutline";
});

module TiArrowUpThick = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowUpThick";
});

module TiArrowUp = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiArrowUp";
});

module TiAt = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiAt";
});

module TiAttachmentOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiAttachmentOutline";
});

module TiAttachment = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiAttachment";
});

module TiBackspaceOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBackspaceOutline";
});

module TiBackspace = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBackspace";
});

module TiBatteryCharge = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBatteryCharge";
});

module TiBatteryFull = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBatteryFull";
});

module TiBatteryHigh = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBatteryHigh";
});

module TiBatteryLow = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBatteryLow";
});

module TiBatteryMid = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBatteryMid";
});

module TiBeaker = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBeaker";
});

module TiBeer = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBeer";
});

module TiBell = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBell";
});

module TiBook = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBook";
});

module TiBookmark = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBookmark";
});

module TiBriefcase = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBriefcase";
});

module TiBrush = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBrush";
});

module TiBusinessCard = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiBusinessCard";
});

module TiCalculator = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCalculator";
});

module TiCalendarOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCalendarOutline";
});

module TiCalendar = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCalendar";
});

module TiCameraOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCameraOutline";
});

module TiCamera = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCamera";
});

module TiCancelOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCancelOutline";
});

module TiCancel = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCancel";
});

module TiChartAreaOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartAreaOutline";
});

module TiChartArea = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartArea";
});

module TiChartBarOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartBarOutline";
});

module TiChartBar = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartBar";
});

module TiChartLineOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartLineOutline";
});

module TiChartLine = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartLine";
});

module TiChartPieOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartPieOutline";
});

module TiChartPie = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChartPie";
});

module TiChevronLeftOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChevronLeftOutline";
});

module TiChevronLeft = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChevronLeft";
});

module TiChevronRightOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChevronRightOutline";
});

module TiChevronRight = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiChevronRight";
});

module TiClipboard = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiClipboard";
});

module TiCloudStorageOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCloudStorageOutline";
});

module TiCloudStorage = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCloudStorage";
});

module TiCodeOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCodeOutline";
});

module TiCode = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCode";
});

module TiCoffee = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCoffee";
});

module TiCogOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCogOutline";
});

module TiCog = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCog";
});

module TiCompass = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCompass";
});

module TiContacts = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiContacts";
});

module TiCreditCard = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCreditCard";
});

module TiCss3 = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiCss3";
});

module TiDatabase = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDatabase";
});

module TiDeleteOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDeleteOutline";
});

module TiDelete = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDelete";
});

module TiDeviceDesktop = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDeviceDesktop";
});

module TiDeviceLaptop = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDeviceLaptop";
});

module TiDevicePhone = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDevicePhone";
});

module TiDeviceTablet = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDeviceTablet";
});

module TiDirections = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDirections";
});

module TiDivideOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDivideOutline";
});

module TiDivide = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDivide";
});

module TiDocumentAdd = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDocumentAdd";
});

module TiDocumentDelete = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDocumentDelete";
});

module TiDocumentText = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDocumentText";
});

module TiDocument = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDocument";
});

module TiDownloadOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDownloadOutline";
});

module TiDownload = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDownload";
});

module TiDropbox = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiDropbox";
});

module TiEdit = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiEdit";
});

module TiEjectOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiEjectOutline";
});

module TiEject = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiEject";
});

module TiEqualsOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiEqualsOutline";
});

module TiEquals = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiEquals";
});

module TiExportOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiExportOutline";
});

module TiExport = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiExport";
});

module TiEyeOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiEyeOutline";
});

module TiEye = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiEye";
});

module TiFeather = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFeather";
});

module TiFilm = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFilm";
});

module TiFilter = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFilter";
});

module TiFlagOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlagOutline";
});

module TiFlag = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlag";
});

module TiFlashOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlashOutline";
});

module TiFlash = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlash";
});

module TiFlowChildren = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlowChildren";
});

module TiFlowMerge = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlowMerge";
});

module TiFlowParallel = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlowParallel";
});

module TiFlowSwitch = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFlowSwitch";
});

module TiFolderAdd = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFolderAdd";
});

module TiFolderDelete = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFolderDelete";
});

module TiFolderOpen = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFolderOpen";
});

module TiFolder = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiFolder";
});

module TiGift = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiGift";
});

module TiGlobeOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiGlobeOutline";
});

module TiGlobe = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiGlobe";
});

module TiGroupOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiGroupOutline";
});

module TiGroup = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiGroup";
});

module TiHeadphones = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHeadphones";
});

module TiHeartFullOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHeartFullOutline";
});

module TiHeartHalfOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHeartHalfOutline";
});

module TiHeartOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHeartOutline";
});

module TiHeart = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHeart";
});

module TiHomeOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHomeOutline";
});

module TiHome = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHome";
});

module TiHtml5 = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiHtml5";
});

module TiImageOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiImageOutline";
});

module TiImage = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiImage";
});

module TiInfinityOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInfinityOutline";
});

module TiInfinity = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInfinity";
});

module TiInfoLargeOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInfoLargeOutline";
});

module TiInfoLarge = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInfoLarge";
});

module TiInfoOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInfoOutline";
});

module TiInfo = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInfo";
});

module TiInputCheckedOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInputCheckedOutline";
});

module TiInputChecked = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiInputChecked";
});

module TiKeyOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiKeyOutline";
});

module TiKey = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiKey";
});

module TiKeyboard = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiKeyboard";
});

module TiLeaf = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLeaf";
});

module TiLightbulb = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLightbulb";
});

module TiLinkOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLinkOutline";
});

module TiLink = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLink";
});

module TiLocationArrowOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLocationArrowOutline";
});

module TiLocationArrow = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLocationArrow";
});

module TiLocationOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLocationOutline";
});

module TiLocation = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLocation";
});

module TiLockClosedOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLockClosedOutline";
});

module TiLockClosed = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLockClosed";
});

module TiLockOpenOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLockOpenOutline";
});

module TiLockOpen = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiLockOpen";
});

module TiMail = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMail";
});

module TiMap = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMap";
});

module TiMediaEjectOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaEjectOutline";
});

module TiMediaEject = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaEject";
});

module TiMediaFastForwardOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaFastForwardOutline";
});

module TiMediaFastForward = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaFastForward";
});

module TiMediaPauseOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaPauseOutline";
});

module TiMediaPause = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaPause";
});

module TiMediaPlayOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaPlayOutline";
});

module TiMediaPlayReverseOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaPlayReverseOutline";
});

module TiMediaPlayReverse = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaPlayReverse";
});

module TiMediaPlay = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaPlay";
});

module TiMediaRecordOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaRecordOutline";
});

module TiMediaRecord = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaRecord";
});

module TiMediaRewindOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaRewindOutline";
});

module TiMediaRewind = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaRewind";
});

module TiMediaStopOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaStopOutline";
});

module TiMediaStop = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMediaStop";
});

module TiMessageTyping = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMessageTyping";
});

module TiMessage = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMessage";
});

module TiMessages = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMessages";
});

module TiMicrophoneOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMicrophoneOutline";
});

module TiMicrophone = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMicrophone";
});

module TiMinusOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMinusOutline";
});

module TiMinus = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMinus";
});

module TiMortarBoard = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiMortarBoard";
});

module TiNews = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiNews";
});

module TiNotesOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiNotesOutline";
});

module TiNotes = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiNotes";
});

module TiPen = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPen";
});

module TiPencil = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPencil";
});

module TiPhoneOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPhoneOutline";
});

module TiPhone = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPhone";
});

module TiPiOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPiOutline";
});

module TiPi = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPi";
});

module TiPinOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPinOutline";
});

module TiPin = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPin";
});

module TiPipette = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPipette";
});

module TiPlaneOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPlaneOutline";
});

module TiPlane = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPlane";
});

module TiPlug = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPlug";
});

module TiPlusOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPlusOutline";
});

module TiPlus = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPlus";
});

module TiPointOfInterestOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPointOfInterestOutline";
});

module TiPointOfInterest = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPointOfInterest";
});

module TiPowerOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPowerOutline";
});

module TiPower = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPower";
});

module TiPrinter = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPrinter";
});

module TiPuzzleOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPuzzleOutline";
});

module TiPuzzle = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiPuzzle";
});

module TiRadarOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiRadarOutline";
});

module TiRadar = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiRadar";
});

module TiRefreshOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiRefreshOutline";
});

module TiRefresh = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiRefresh";
});

module TiRssOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiRssOutline";
});

module TiRss = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiRss";
});

module TiScissorsOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiScissorsOutline";
});

module TiScissors = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiScissors";
});

module TiShoppingBag = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiShoppingBag";
});

module TiShoppingCart = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiShoppingCart";
});

module TiSocialAtCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialAtCircular";
});

module TiSocialDribbbleCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialDribbbleCircular";
});

module TiSocialDribbble = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialDribbble";
});

module TiSocialFacebookCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialFacebookCircular";
});

module TiSocialFacebook = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialFacebook";
});

module TiSocialFlickrCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialFlickrCircular";
});

module TiSocialFlickr = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialFlickr";
});

module TiSocialGithubCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialGithubCircular";
});

module TiSocialGithub = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialGithub";
});

module TiSocialGooglePlusCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialGooglePlusCircular";
});

module TiSocialGooglePlus = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialGooglePlus";
});

module TiSocialInstagramCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialInstagramCircular";
});

module TiSocialInstagram = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialInstagram";
});

module TiSocialLastFmCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialLastFmCircular";
});

module TiSocialLastFm = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialLastFm";
});

module TiSocialLinkedinCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialLinkedinCircular";
});

module TiSocialLinkedin = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialLinkedin";
});

module TiSocialPinterestCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialPinterestCircular";
});

module TiSocialPinterest = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialPinterest";
});

module TiSocialSkypeOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialSkypeOutline";
});

module TiSocialSkype = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialSkype";
});

module TiSocialTumblerCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialTumblerCircular";
});

module TiSocialTumbler = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialTumbler";
});

module TiSocialTwitterCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialTwitterCircular";
});

module TiSocialTwitter = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialTwitter";
});

module TiSocialVimeoCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialVimeoCircular";
});

module TiSocialVimeo = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialVimeo";
});

module TiSocialYoutubeCircular = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialYoutubeCircular";
});

module TiSocialYoutube = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSocialYoutube";
});

module TiSortAlphabeticallyOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSortAlphabeticallyOutline";
});

module TiSortAlphabetically = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSortAlphabetically";
});

module TiSortNumericallyOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSortNumericallyOutline";
});

module TiSortNumerically = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSortNumerically";
});

module TiSpannerOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSpannerOutline";
});

module TiSpanner = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSpanner";
});

module TiSpiral = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSpiral";
});

module TiStarFullOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStarFullOutline";
});

module TiStarHalfOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStarHalfOutline";
});

module TiStarHalf = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStarHalf";
});

module TiStarOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStarOutline";
});

module TiStar = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStar";
});

module TiStarburstOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStarburstOutline";
});

module TiStarburst = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStarburst";
});

module TiStopwatch = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiStopwatch";
});

module TiSupport = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiSupport";
});

module TiTabsOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTabsOutline";
});

module TiTag = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTag";
});

module TiTags = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTags";
});

module TiThLargeOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThLargeOutline";
});

module TiThLarge = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThLarge";
});

module TiThListOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThListOutline";
});

module TiThList = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThList";
});

module TiThMenuOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThMenuOutline";
});

module TiThMenu = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThMenu";
});

module TiThSmallOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThSmallOutline";
});

module TiThSmall = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThSmall";
});

module TiThermometer = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThermometer";
});

module TiThumbsDown = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThumbsDown";
});

module TiThumbsOk = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThumbsOk";
});

module TiThumbsUp = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiThumbsUp";
});

module TiTickOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTickOutline";
});

module TiTick = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTick";
});

module TiTicket = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTicket";
});

module TiTime = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTime";
});

module TiTimesOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTimesOutline";
});

module TiTimes = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTimes";
});

module TiTrash = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTrash";
});

module TiTree = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiTree";
});

module TiUploadOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUploadOutline";
});

module TiUpload = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUpload";
});

module TiUserAddOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUserAddOutline";
});

module TiUserAdd = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUserAdd";
});

module TiUserDeleteOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUserDeleteOutline";
});

module TiUserDelete = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUserDelete";
});

module TiUserOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUserOutline";
});

module TiUser = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiUser";
});

module TiVendorAndroid = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVendorAndroid";
});

module TiVendorApple = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVendorApple";
});

module TiVendorMicrosoft = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVendorMicrosoft";
});

module TiVideoOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVideoOutline";
});

module TiVideo = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVideo";
});

module TiVolumeDown = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVolumeDown";
});

module TiVolumeMute = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVolumeMute";
});

module TiVolumeUp = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVolumeUp";
});

module TiVolume = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiVolume";
});

module TiWarningOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWarningOutline";
});

module TiWarning = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWarning";
});

module TiWatch = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWatch";
});

module TiWavesOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWavesOutline";
});

module TiWaves = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWaves";
});

module TiWeatherCloudy = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherCloudy";
});

module TiWeatherDownpour = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherDownpour";
});

module TiWeatherNight = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherNight";
});

module TiWeatherPartlySunny = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherPartlySunny";
});

module TiWeatherShower = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherShower";
});

module TiWeatherSnow = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherSnow";
});

module TiWeatherStormy = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherStormy";
});

module TiWeatherSunny = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherSunny";
});

module TiWeatherWindyCloudy = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherWindyCloudy";
});

module TiWeatherWindy = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWeatherWindy";
});

module TiWiFiOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWiFiOutline";
});

module TiWiFi = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWiFi";
});

module TiWine = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWine";
});

module TiWorldOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWorldOutline";
});

module TiWorld = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiWorld";
});

module TiZoomInOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiZoomInOutline";
});

module TiZoomIn = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiZoomIn";
});

module TiZoomOutOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiZoomOutOutline";
});

module TiZoomOut = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiZoomOut";
});

module TiZoomOutline = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiZoomOutline";
});

module TiZoom = MakeIcon({
  [@bs.module "react-icons/ti"] 
  external reactClass : ReasonReact.reactClass = "TiZoom";
});

module GoAlert = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoAlert";
});

module GoArchive = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArchive";
});

module GoArrowDown = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowDown";
});

module GoArrowLeft = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowLeft";
});

module GoArrowRight = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowRight";
});

module GoArrowSmallDown = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowSmallDown";
});

module GoArrowSmallLeft = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowSmallLeft";
});

module GoArrowSmallRight = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowSmallRight";
});

module GoArrowSmallUp = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowSmallUp";
});

module GoArrowUp = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoArrowUp";
});

module GoBeaker = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBeaker";
});

module GoBell = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBell";
});

module GoBold = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBold";
});

module GoBook = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBook";
});

module GoBookmark = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBookmark";
});

module GoBriefcase = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBriefcase";
});

module GoBroadcast = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBroadcast";
});

module GoBrowser = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBrowser";
});

module GoBug = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoBug";
});

module GoCalendar = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCalendar";
});

module GoCheck = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCheck";
});

module GoChecklist = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoChecklist";
});

module GoChevronDown = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoChevronDown";
});

module GoChevronLeft = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoChevronLeft";
});

module GoChevronRight = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoChevronRight";
});

module GoChevronUp = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoChevronUp";
});

module GoCircleSlash = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCircleSlash";
});

module GoCircuitBoard = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCircuitBoard";
});

module GoClippy = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoClippy";
});

module GoClock = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoClock";
});

module GoCloudDownload = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCloudDownload";
});

module GoCloudUpload = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCloudUpload";
});

module GoCode = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCode";
});

module GoCommentDiscussion = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCommentDiscussion";
});

module GoComment = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoComment";
});

module GoCreditCard = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoCreditCard";
});

module GoDash = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDash";
});

module GoDashboard = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDashboard";
});

module GoDatabase = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDatabase";
});

module GoDesktopDownload = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDesktopDownload";
});

module GoDeviceCameraVideo = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDeviceCameraVideo";
});

module GoDeviceCamera = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDeviceCamera";
});

module GoDeviceDesktop = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDeviceDesktop";
});

module GoDeviceMobile = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDeviceMobile";
});

module GoDiffAdded = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDiffAdded";
});

module GoDiffIgnored = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDiffIgnored";
});

module GoDiffModified = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDiffModified";
});

module GoDiffRemoved = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDiffRemoved";
});

module GoDiffRenamed = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDiffRenamed";
});

module GoDiff = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoDiff";
});

module GoEllipsis = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoEllipsis";
});

module GoEye = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoEye";
});

module GoFileBinary = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileBinary";
});

module GoFileCode = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileCode";
});

module GoFileDirectory = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileDirectory";
});

module GoFileMedia = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileMedia";
});

module GoFilePdf = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFilePdf";
});

module GoFileSubmodule = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileSubmodule";
});

module GoFileSymlinkDirectory = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileSymlinkDirectory";
});

module GoFileSymlinkFile = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileSymlinkFile";
});

module GoFileZip = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFileZip";
});

module GoFile = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFile";
});

module GoFlame = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFlame";
});

module GoFold = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoFold";
});

module GoGear = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGear";
});

module GoGift = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGift";
});

module GoGistSecret = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGistSecret";
});

module GoGist = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGist";
});

module GoGitBranch = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGitBranch";
});

module GoGitCommit = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGitCommit";
});

module GoGitCompare = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGitCompare";
});

module GoGitMerge = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGitMerge";
});

module GoGitPullRequest = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGitPullRequest";
});

module GoGlobe = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGlobe";
});

module GoGrabber = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGrabber";
});

module GoGraph = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoGraph";
});

module GoHeart = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoHeart";
});

module GoHistory = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoHistory";
});

module GoHome = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoHome";
});

module GoHorizontalRule = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoHorizontalRule";
});

module GoHubot = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoHubot";
});

module GoInbox = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoInbox";
});

module GoInfo = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoInfo";
});

module GoIssueClosed = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoIssueClosed";
});

module GoIssueOpened = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoIssueOpened";
});

module GoIssueReopened = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoIssueReopened";
});

module GoItalic = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoItalic";
});

module GoJersey = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoJersey";
});

module GoKebabHorizontal = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoKebabHorizontal";
});

module GoKebabVertical = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoKebabVertical";
});

module GoKey = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoKey";
});

module GoKeyboard = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoKeyboard";
});

module GoLaw = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLaw";
});

module GoLightBulb = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLightBulb";
});

module GoLinkExternal = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLinkExternal";
});

module GoLink = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLink";
});

module GoListOrdered = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoListOrdered";
});

module GoListUnordered = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoListUnordered";
});

module GoLocation = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLocation";
});

module GoLock = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLock";
});

module GoLogoGist = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLogoGist";
});

module GoLogoGithub = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoLogoGithub";
});

module GoMailRead = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMailRead";
});

module GoMail = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMail";
});

module GoMarkGithub = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMarkGithub";
});

module GoMarkdown = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMarkdown";
});

module GoMegaphone = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMegaphone";
});

module GoMention = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMention";
});

module GoMilestone = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMilestone";
});

module GoMirror = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMirror";
});

module GoMortarBoard = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMortarBoard";
});

module GoMute = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoMute";
});

module GoNoNewline = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoNoNewline";
});

module GoNote = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoNote";
});

module GoOctoface = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoOctoface";
});

module GoOrganization = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoOrganization";
});

module GoPackage = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPackage";
});

module GoPaintcan = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPaintcan";
});

module GoPencil = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPencil";
});

module GoPerson = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPerson";
});

module GoPin = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPin";
});

module GoPlug = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPlug";
});

module GoPlusSmall = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPlusSmall";
});

module GoPlus = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPlus";
});

module GoPrimitiveDot = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPrimitiveDot";
});

module GoPrimitiveSquare = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPrimitiveSquare";
});

module GoProject = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoProject";
});

module GoPulse = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoPulse";
});

module GoQuestion = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoQuestion";
});

module GoQuote = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoQuote";
});

module GoRadioTower = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRadioTower";
});

module GoReply = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoReply";
});

module GoRepoClone = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRepoClone";
});

module GoRepoForcePush = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRepoForcePush";
});

module GoRepoForked = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRepoForked";
});

module GoRepoPull = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRepoPull";
});

module GoRepoPush = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRepoPush";
});

module GoRepo = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRepo";
});

module GoReport = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoReport";
});

module GoRocket = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRocket";
});

module GoRss = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRss";
});

module GoRuby = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoRuby";
});

module GoScreenFull = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoScreenFull";
});

module GoScreenNormal = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoScreenNormal";
});

module GoSearch = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoSearch";
});

module GoServer = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoServer";
});

module GoSettings = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoSettings";
});

module GoShield = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoShield";
});

module GoSignIn = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoSignIn";
});

module GoSignOut = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoSignOut";
});

module GoSmiley = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoSmiley";
});

module GoSquirrel = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoSquirrel";
});

module GoStar = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoStar";
});

module GoStop = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoStop";
});

module GoSync = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoSync";
});

module GoTag = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTag";
});

module GoTasklist = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTasklist";
});

module GoTelescope = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTelescope";
});

module GoTerminal = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTerminal";
});

module GoTextSize = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTextSize";
});

module GoThreeBars = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoThreeBars";
});

module GoThumbsdown = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoThumbsdown";
});

module GoThumbsup = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoThumbsup";
});

module GoTools = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTools";
});

module GoTrashcan = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTrashcan";
});

module GoTriangleDown = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTriangleDown";
});

module GoTriangleLeft = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTriangleLeft";
});

module GoTriangleRight = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTriangleRight";
});

module GoTriangleUp = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoTriangleUp";
});

module GoUnfold = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoUnfold";
});

module GoUnmute = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoUnmute";
});

module GoUnverified = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoUnverified";
});

module GoVerified = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoVerified";
});

module GoVersions = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoVersions";
});

module GoWatch = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoWatch";
});

module GoX = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoX";
});

module GoZap = MakeIcon({
  [@bs.module "react-icons/go"] 
  external reactClass : ReasonReact.reactClass = "GoZap";
});

module FiActivity = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiActivity";
});

module FiAirplay = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAirplay";
});

module FiAlertCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAlertCircle";
});

module FiAlertOctagon = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAlertOctagon";
});

module FiAlertTriangle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAlertTriangle";
});

module FiAlignCenter = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAlignCenter";
});

module FiAlignJustify = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAlignJustify";
});

module FiAlignLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAlignLeft";
});

module FiAlignRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAlignRight";
});

module FiAnchor = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAnchor";
});

module FiAperture = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAperture";
});

module FiArchive = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArchive";
});

module FiArrowDownCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowDownCircle";
});

module FiArrowDownLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowDownLeft";
});

module FiArrowDownRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowDownRight";
});

module FiArrowDown = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowDown";
});

module FiArrowLeftCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowLeftCircle";
});

module FiArrowLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowLeft";
});

module FiArrowRightCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowRightCircle";
});

module FiArrowRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowRight";
});

module FiArrowUpCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowUpCircle";
});

module FiArrowUpLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowUpLeft";
});

module FiArrowUpRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowUpRight";
});

module FiArrowUp = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiArrowUp";
});

module FiAtSign = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAtSign";
});

module FiAward = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiAward";
});

module FiBarChart2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBarChart2";
});

module FiBarChart = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBarChart";
});

module FiBatteryCharging = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBatteryCharging";
});

module FiBattery = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBattery";
});

module FiBellOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBellOff";
});

module FiBell = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBell";
});

module FiBluetooth = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBluetooth";
});

module FiBold = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBold";
});

module FiBookOpen = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBookOpen";
});

module FiBook = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBook";
});

module FiBookmark = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBookmark";
});

module FiBox = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBox";
});

module FiBriefcase = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiBriefcase";
});

module FiCalendar = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCalendar";
});

module FiCameraOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCameraOff";
});

module FiCamera = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCamera";
});

module FiCast = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCast";
});

module FiCheckCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCheckCircle";
});

module FiCheckSquare = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCheckSquare";
});

module FiCheck = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCheck";
});

module FiChevronDown = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronDown";
});

module FiChevronLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronLeft";
});

module FiChevronRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronRight";
});

module FiChevronUp = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronUp";
});

module FiChevronsDown = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronsDown";
});

module FiChevronsLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronsLeft";
});

module FiChevronsRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronsRight";
});

module FiChevronsUp = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChevronsUp";
});

module FiChrome = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiChrome";
});

module FiCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCircle";
});

module FiClipboard = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiClipboard";
});

module FiClock = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiClock";
});

module FiCloudDrizzle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCloudDrizzle";
});

module FiCloudLightning = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCloudLightning";
});

module FiCloudOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCloudOff";
});

module FiCloudRain = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCloudRain";
});

module FiCloudSnow = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCloudSnow";
});

module FiCloud = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCloud";
});

module FiCode = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCode";
});

module FiCodepen = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCodepen";
});

module FiCommand = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCommand";
});

module FiCompass = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCompass";
});

module FiCopy = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCopy";
});

module FiCornerDownLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerDownLeft";
});

module FiCornerDownRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerDownRight";
});

module FiCornerLeftDown = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerLeftDown";
});

module FiCornerLeftUp = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerLeftUp";
});

module FiCornerRightDown = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerRightDown";
});

module FiCornerRightUp = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerRightUp";
});

module FiCornerUpLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerUpLeft";
});

module FiCornerUpRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCornerUpRight";
});

module FiCpu = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCpu";
});

module FiCreditCard = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCreditCard";
});

module FiCrop = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCrop";
});

module FiCrosshair = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiCrosshair";
});

module FiDatabase = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiDatabase";
});

module FiDelete = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiDelete";
});

module FiDisc = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiDisc";
});

module FiDollarSign = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiDollarSign";
});

module FiDownloadCloud = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiDownloadCloud";
});

module FiDownload = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiDownload";
});

module FiDroplet = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiDroplet";
});

module FiEdit2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiEdit2";
});

module FiEdit3 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiEdit3";
});

module FiEdit = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiEdit";
});

module FiExternalLink = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiExternalLink";
});

module FiEyeOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiEyeOff";
});

module FiEye = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiEye";
});

module FiFacebook = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFacebook";
});

module FiFastForward = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFastForward";
});

module FiFeather = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFeather";
});

module FiFileMinus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFileMinus";
});

module FiFilePlus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFilePlus";
});

module FiFileText = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFileText";
});

module FiFile = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFile";
});

module FiFilm = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFilm";
});

module FiFilter = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFilter";
});

module FiFlag = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFlag";
});

module FiFolderMinus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFolderMinus";
});

module FiFolderPlus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFolderPlus";
});

module FiFolder = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiFolder";
});

module FiGift = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGift";
});

module FiGitBranch = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGitBranch";
});

module FiGitCommit = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGitCommit";
});

module FiGitMerge = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGitMerge";
});

module FiGitPullRequest = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGitPullRequest";
});

module FiGithub = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGithub";
});

module FiGitlab = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGitlab";
});

module FiGlobe = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGlobe";
});

module FiGrid = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiGrid";
});

module FiHardDrive = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiHardDrive";
});

module FiHash = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiHash";
});

module FiHeadphones = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiHeadphones";
});

module FiHeart = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiHeart";
});

module FiHelpCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiHelpCircle";
});

module FiHome = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiHome";
});

module FiImage = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiImage";
});

module FiInbox = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiInbox";
});

module FiInfo = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiInfo";
});

module FiInstagram = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiInstagram";
});

module FiItalic = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiItalic";
});

module FiLayers = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLayers";
});

module FiLayout = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLayout";
});

module FiLifeBuoy = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLifeBuoy";
});

module FiLink2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLink2";
});

module FiLink = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLink";
});

module FiLinkedin = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLinkedin";
});

module FiList = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiList";
});

module FiLoader = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLoader";
});

module FiLock = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLock";
});

module FiLogIn = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLogIn";
});

module FiLogOut = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiLogOut";
});

module FiMail = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMail";
});

module FiMapPin = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMapPin";
});

module FiMap = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMap";
});

module FiMaximize2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMaximize2";
});

module FiMaximize = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMaximize";
});

module FiMenu = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMenu";
});

module FiMessageCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMessageCircle";
});

module FiMessageSquare = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMessageSquare";
});

module FiMicOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMicOff";
});

module FiMic = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMic";
});

module FiMinimize2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMinimize2";
});

module FiMinimize = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMinimize";
});

module FiMinusCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMinusCircle";
});

module FiMinusSquare = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMinusSquare";
});

module FiMinus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMinus";
});

module FiMonitor = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMonitor";
});

module FiMoon = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMoon";
});

module FiMoreHorizontal = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMoreHorizontal";
});

module FiMoreVertical = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMoreVertical";
});

module FiMove = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMove";
});

module FiMusic = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiMusic";
});

module FiNavigation2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiNavigation2";
});

module FiNavigation = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiNavigation";
});

module FiOctagon = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiOctagon";
});

module FiPackage = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPackage";
});

module FiPaperclip = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPaperclip";
});

module FiPauseCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPauseCircle";
});

module FiPause = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPause";
});

module FiPercent = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPercent";
});

module FiPhoneCall = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPhoneCall";
});

module FiPhoneForwarded = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPhoneForwarded";
});

module FiPhoneIncoming = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPhoneIncoming";
});

module FiPhoneMissed = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPhoneMissed";
});

module FiPhoneOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPhoneOff";
});

module FiPhoneOutgoing = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPhoneOutgoing";
});

module FiPhone = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPhone";
});

module FiPieChart = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPieChart";
});

module FiPlayCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPlayCircle";
});

module FiPlay = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPlay";
});

module FiPlusCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPlusCircle";
});

module FiPlusSquare = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPlusSquare";
});

module FiPlus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPlus";
});

module FiPocket = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPocket";
});

module FiPower = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPower";
});

module FiPrinter = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiPrinter";
});

module FiRadio = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRadio";
});

module FiRefreshCcw = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRefreshCcw";
});

module FiRefreshCw = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRefreshCw";
});

module FiRepeat = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRepeat";
});

module FiRewind = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRewind";
});

module FiRotateCcw = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRotateCcw";
});

module FiRotateCw = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRotateCw";
});

module FiRss = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiRss";
});

module FiSave = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSave";
});

module FiScissors = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiScissors";
});

module FiSearch = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSearch";
});

module FiSend = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSend";
});

module FiServer = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiServer";
});

module FiSettings = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSettings";
});

module FiShare2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiShare2";
});

module FiShare = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiShare";
});

module FiShieldOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiShieldOff";
});

module FiShield = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiShield";
});

module FiShoppingBag = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiShoppingBag";
});

module FiShoppingCart = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiShoppingCart";
});

module FiShuffle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiShuffle";
});

module FiSidebar = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSidebar";
});

module FiSkipBack = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSkipBack";
});

module FiSkipForward = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSkipForward";
});

module FiSlack = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSlack";
});

module FiSlash = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSlash";
});

module FiSliders = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSliders";
});

module FiSmartphone = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSmartphone";
});

module FiSpeaker = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSpeaker";
});

module FiSquare = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSquare";
});

module FiStar = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiStar";
});

module FiStopCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiStopCircle";
});

module FiSun = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSun";
});

module FiSunrise = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSunrise";
});

module FiSunset = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiSunset";
});

module FiTablet = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTablet";
});

module FiTag = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTag";
});

module FiTarget = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTarget";
});

module FiTerminal = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTerminal";
});

module FiThermometer = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiThermometer";
});

module FiThumbsDown = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiThumbsDown";
});

module FiThumbsUp = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiThumbsUp";
});

module FiToggleLeft = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiToggleLeft";
});

module FiToggleRight = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiToggleRight";
});

module FiTrash2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTrash2";
});

module FiTrash = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTrash";
});

module FiTrendingDown = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTrendingDown";
});

module FiTrendingUp = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTrendingUp";
});

module FiTriangle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTriangle";
});

module FiTruck = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTruck";
});

module FiTv = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTv";
});

module FiTwitter = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiTwitter";
});

module FiType = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiType";
});

module FiUmbrella = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUmbrella";
});

module FiUnderline = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUnderline";
});

module FiUnlock = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUnlock";
});

module FiUploadCloud = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUploadCloud";
});

module FiUpload = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUpload";
});

module FiUserCheck = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUserCheck";
});

module FiUserMinus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUserMinus";
});

module FiUserPlus = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUserPlus";
});

module FiUserX = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUserX";
});

module FiUser = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUser";
});

module FiUsers = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiUsers";
});

module FiVideoOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiVideoOff";
});

module FiVideo = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiVideo";
});

module FiVoicemail = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiVoicemail";
});

module FiVolume1 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiVolume1";
});

module FiVolume2 = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiVolume2";
});

module FiVolumeX = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiVolumeX";
});

module FiVolume = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiVolume";
});

module FiWatch = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiWatch";
});

module FiWifiOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiWifiOff";
});

module FiWifi = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiWifi";
});

module FiWind = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiWind";
});

module FiXCircle = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiXCircle";
});

module FiXSquare = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiXSquare";
});

module FiX = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiX";
});

module FiYoutube = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiYoutube";
});

module FiZapOff = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiZapOff";
});

module FiZap = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiZap";
});

module FiZoomIn = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiZoomIn";
});

module FiZoomOut = MakeIcon({
  [@bs.module "react-icons/fi"] 
  external reactClass : ReasonReact.reactClass = "FiZoomOut";
});