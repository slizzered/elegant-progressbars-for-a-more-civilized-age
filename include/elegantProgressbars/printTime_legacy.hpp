#pragma once

#include <sstream>
#include <string>
#include <cassert> /*assert*/

namespace ElegantProgressbars{
    
std::string printTime(float const timeSpent, float const percentage){
  std::stringstream stream;

  assert(percentage <= 1.f);

  float const timeTotal     = timeSpent/percentage;
  float const timeRemaining = timeTotal-timeSpent;

  stream << " after " << static_cast<int>(timeSpent)      << "s";
  stream << " ("      << static_cast<int>(timeTotal)      << "s total";
  stream << ", "      << static_cast<int>(timeRemaining)  << "s remaining)";
  return stream.str();
}

}
