/**
 * @license
 * MIT License
 *
 * Copyright (c) 2020 Alexis Munsayac
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 * @author Alexis Munsayac <alexis.munsayac@gmail.com>
 * @copyright Alexis Munsayac 2020
 */
type t;

[@bs.get]
external bubbles: t => bool = "bubbles";

[@bs.get]
external cancelBubble: t => bool = "cancelBubble";

[@bs.get]
external cancelable: t => bool = "cancelable";

[@bs.get]
external composed: t => bool = "composed";

[@bs.get]
external data: t => 'a = "data";

[@bs.get]
external defaultPrevented: t => bool = "defaultPrevented";

[@bs.get]
external eventPhase: t => int = "eventPhase";

[@bs.get]
external explicitOriginalTarget: t => 'a = "explicitOriginalTarget";

[@bs.get]
external isTrusted: t => bool = "isTrusted";

[@bs.get]
external lastEventId: t => string = "lastEventId";

[@bs.get]
external origin: t => string = "origin";

[@bs.get]
external originalTarget: t => 'a = "originalTarget";

[@bs.get]
external returnValue: t => bool = "returnValue";

[@bs.get]
external source: t => 'a = "source";

[@bs.get]
external srcElement: t => 'a = "srcElement";

[@bs.get]
external target: t => 'a = "target";

[@bs.get]
external type_: t => string = "type";
