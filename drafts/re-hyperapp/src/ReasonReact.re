/** This module implements capitalized JSX elements (i.e. custom
    components) for [re-hyperapp]. See [ReactDOMRe] for more details. */

/** [element(~key, ~ref, children)] is purely a hack for capitalized
    elements (i.e. custom components) to pass on the [children] elements
    to Hyperapp for rendering. Notably, don't actually set the [key] or
    [ref] attributes on capitalized elements in the JSX; they'll be
    ignored. To set a key, pass it using another attribute name, like
    [key'] and use that to set [key] in an {i uncapitalized} element. */
let element(~key as _=?, ~ref as _=?, children) = children;
