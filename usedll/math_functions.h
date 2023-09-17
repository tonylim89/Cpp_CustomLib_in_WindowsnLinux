#pragma once

// Depending on the compiler, select the correct import/export mechanism
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

// The function we want to export
extern "C" MATHLIBRARY_API double Add(double a, double b);
