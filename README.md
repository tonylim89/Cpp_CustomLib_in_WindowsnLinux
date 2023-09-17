# Custom Library Creation and Usage with `g++` (MinGW) for C++ Codes

This project demonstrates the creation and use of custom libraries in both Windows and Linux environments using `g++` from MinGW.

- [Source Codes](#source-codes)
- [Dynamic Linking](#dynamic-linking)
  - [Windows with `g++`](#windows-with-g)
  - [Linux (WSL) with `g++`](#linux-wsl-with-g)
- [Static Linking](#static-linking)
  - [Windows with `g++`](#windows-with-g-1)
  - [Linux (WSL) with `g++`](#linux-wsl-with-g-1)

## Source Codes

### **math_functions.cpp**

```
#include "math_functions.h"

double Add(double a, double b) {
    return a + b;
}
```

### **math_functions.h**
```
#pragma once

#if defined(_MSC_VER) // MSVC compiler
    #ifdef MATHLIBRARY_EXPORTS
        #define MATHLIBRARY_API __declspec(dllexport)
    #else
        #define MATHLIBRARY_API __declspec(dllimport)
    #endif
#elif defined(__GNUC__) // GCC compiler
    #ifdef MATHLIBRARY_EXPORTS
        #define MATHLIBRARY_API __attribute__((visibility("default")))
    #else
        #define MATHLIBRARY_API
    #endif
#else
    #define MATHLIBRARY_API
#endif

// The function to export
extern "C" MATHLIBRARY_API double Add(double a, double b);
```
### **main.cpp**
```
#include "math_functions.h"
#include <iostream>

int main() {
    double result = Add(2.5, 3.5);
    std::cout << "The result of adding 2.5 and 3.5 is: " << result << std::endl;
    return 0;
}
```
## Dynamic Linking

### Windows with g++:

1. Compile the library:
  ```
  g++ -shared -o math_functions.dll math_functions.cpp -DMATHLIBRARY_EXPORTS
  ```
   
2. Compile the main application:
```
g++ main.cpp -o myApp -L. -lmath_functions
```
   
3. Run the application:
```
./myApp
```

### Linux (WSL) with g++:
1. Compile the library:
```
g++ -shared -o libmath_functions.so math_functions.cpp -fPIC -DMATHLIBRARY_EXPORTS
```

2. Compile the main application:
```
g++ main.cpp -o myApp -L. -lmath_functions
```

3. Run the application:
```
./myApp
```

## Static Linking

### Windows with g++:

1. Compile the static library:
  ```
g++ -c math_functions.cpp -o math_functions.o
ar rcs libmath_functions.a math_functions.o
  ```
   
2. Compile and link the main application:
```
g++ main.cpp -o myApp -L. -lmath_functions -static
```
   
3. Run the application:
```
./myApp
```

### Linux (WSL) with g++:
1. Compile the static library:
```
g++ -c math_functions.cpp -o math_functions.o
ar rcs libmath_functions.a math_functions.o
```

2. Compile and link the main application:
```
g++ main.cpp -o myApp -L. -lmath_functions -static
```

3. Run the application:
```
./myApp
```





















