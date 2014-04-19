elegant progressbars for a more civilized age
=============================================
Because yay progress!

Offers progressbars to be used in command-line applications, to give a little
bit of eye-candy to the waiting user.

This is a header-only library that will use C++11 features (some progressbars
offer a legacy-variant, which is very nice of them).

Installation
------------
Just put the folder ./lib/elegantProgressbars in a place where your compiler
will find it when searching for libraries to include.

You can use ```doxygen``` to get a nice documentation:  
```bash
doxygen Doxyfile
firefox doc/html/index.html
```

Example
-------
There is an example which can be compiled and tested:

###Dependencies
 - ```cmake``` >= 2.8.5
 - ```clang``` >= 3.4
   - (```g++``` >= 4.8.2 might also work, use ```cmake -DUSE_CLANG=OFF```)

###Build:
```bash
git clone https://github.com/slizzered/elegant-progressbars-for-a-more-civilized-age.git
cd elegant-progressbars-for-a-more-civilized-age
cmake .
make
./ProgressbarExample
```

Usage
-----
```c++
using namespace ElegantProgressbars;

// call one of those in a loop that iterates until maxElement
std::cout << fancyProgressBar(maxElement);
std::cout << fancyProgressBar<true>(maxElement);
std::cout << fancyProgressBar(maxElement, currentElement);
```

License
-------
Copyright (c) 2014 Carlchristian Eckert  
Licensed under the MIT license.  
Free as in beer.
