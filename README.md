# App47 iOS PhoneGap example

## Installation

This is a sample PhoneGap project for iOS; consequently, you can clone this repo and open it in XCode. This App makes use of the App47 SDK (via the [App47 PhoneGap plugin](https://github.com/App47/phonegap-plugins)) for mobile analytics including sessions, timed events, generic events, and logging. What's more, this project uses App configurations, which allow for runtime updates of desired variables, etc. 

Files to pay attention to:

* `AppDelegate.m` -- the App47 Agent is initialized: `[EmbeddedAgent configureAgent];`
* `gravy.js` -- included via `index.html` and is where App47 PhoneGap plug is utilized

# License

The MIT License

Copyright (c) 2011 App47, Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE