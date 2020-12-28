#pragma once
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

#ifdef EDUCATIONALPRACTICEDLL_EXPORTS
#define EDUCATIONALPRACTICEDLL_API __declspec(dllexport)
#else
#define EDUCATIONALPRACTICEDLL_API __declspec(dllimport)
#endif

extern "C" EDUCATIONALPRACTICEDLL_API void writeToSortFile(const std::vector<char> &vector);

