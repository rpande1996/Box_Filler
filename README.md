## AR_Plotting
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
---
## Overview

This code fills up boxes of various sizes as per the total parts to be filled. Each box size has 
maximum of parts limit. The limit per size grows in ascending order. A box must be completely filled 
before moving to a bigger box. Filling must start from the biggest box and end on the smallest box.

## Softwares

* Recommended IDE: Visual Studio Code 1.63.2

## Programming Languages

* C++ 17

## License 

```
MIT License

Copyright (c) 2021 Rajan Pande

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
```

## Build

```
git clone https://github.com/rpande1996/Box_Filler
cd Box_Filler/src
cd "<path where you cloned the repo>\Box_Filler\src\" && g++ Box_Filler.cpp -o Box_Filler && "<path where you cloned the repo>\Box_Filler\src\"Box_Filler
```
Enter the following parameters:-
```
Enter total number parts:
Enter total number boxes of size S/M/L/XL: 
Enter total number parts per box of size S/M/L/XL: 
```
Note: Each value for 'total boxes' and 'parts per box' must be spaced
e.g. 
```
Enter total number parts: 306
Enter total number boxes of size S/M/L/XL: 5 10 5 1
Enter total number parts per box of size S/M/L/XL: 20 15 10 5
```