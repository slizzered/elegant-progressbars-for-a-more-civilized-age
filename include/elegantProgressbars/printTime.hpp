#pragma once

#include <chrono>
#include <sstream>
#include <string>
#include <cassert> /*assert*/

namespace ElegantProgressbars{
    
template<bool highPrecision = false>
std::string humanRepresentation(
    std::chrono::duration<float> const time){

  using std::chrono::duration;
  using std::chrono::duration_cast;

  typedef duration<int, std::milli> milliseconds;
  typedef duration<int, std::ratio<1,1>> seconds;
  typedef duration<int, std::ratio<60,1>> minutes;
  typedef duration<int, std::ratio<3600,1>> hours;
  
  int const tMsec   = duration_cast<milliseconds>(time).count()%1000;
  int const tSec   = duration_cast<seconds>(time).count()%60;
  int const tMin  = duration_cast<minutes>(time).count()%60;
  int const tHour = duration_cast<hours>(time).count();

  std::stringstream ss;

  if(tHour) ss << tHour << "h ";
  if(tMin)  ss << tMin << "m "; 
  if(tSec || !highPrecision) ss << tSec << "s";

  if(highPrecision){
    ss << " " << tMsec << "ms";
  }

  return ss.str();
}

template<bool highPrecision = false>
std::string printTime(std::chrono::duration<float> const tSpent, float const percentage){
  using std::chrono::duration;
  typedef duration<int, std::ratio<60,1>> minutes;
  typedef duration<int, std::ratio<3600,1>> hours;
  std::stringstream stream;

  assert(percentage <= 1.f);

  duration<float> const tTotal = tSpent / percentage;
  duration<float> const tRemaining = tTotal - tSpent;

  stream << " after " << humanRepresentation<highPrecision>(tSpent);
  stream << " ("      << humanRepresentation<highPrecision>(tTotal)     <<" total";
  stream << ", "      << humanRepresentation<highPrecision>(tRemaining) << " remaining)";
  return stream.str();
}

}
