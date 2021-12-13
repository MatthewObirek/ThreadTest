#pragma once
#include <iostream>
#include <stdlib.h>

#define DEBUG true

#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl 
#else
#define LOG(x)
#endif
 
#define ASSERT(x) if (!(x)) __debugbreak();
#define ptr_call(ptr, name) if (ptr == nullptr) LOG("ptr_ERROR: \'" << #ptr << "\' in " << name << std::endl << "File: " << __FILE__ << std::endl << "Line: " << __LINE__ );

