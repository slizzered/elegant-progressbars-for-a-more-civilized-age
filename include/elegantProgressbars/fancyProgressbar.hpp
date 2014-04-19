#pragma once

#include <sstream>
#include <string>
#include <chrono>

#include "printPattern.hpp"
#include "printPercentage.hpp"
#include "printTime.hpp"

namespace ElegantProgressbars{
    

template<bool highPrecision = false>
std::string fancyProgressBar(
    unsigned const nTotal, 
    unsigned const current = 0
    ){

  using namespace std::chrono;
  typedef duration<long long int, std::milli> milliseconds;

  static unsigned maxNTotal = 0;
  static unsigned part = 0;
  static unsigned tic  = 0;
  static time_point<steady_clock> startTime;
  if(part==0){ startTime = steady_clock::now(); } // get the starting time on the very first call

  int const length = 50;
  std::stringstream ss;
  time_point<steady_clock> const now = steady_clock::now();

  maxNTotal = std::max(maxNTotal, nTotal);
  part = current ? current : ++part;

  //limit the update intervall (not faster than every 35ms. This would be madness.)
  duration<float> const timeSpent = now - startTime;
  if(timeSpent.count() > 0.035f*tic || part == maxNTotal){
    ++tic;
    float const percentage  = static_cast<float>(part) / static_cast<float>(maxNTotal);

    ss << "\rProgress: [";
    ss << printPattern(tic, percentage, length);
    ss << "] ";
    ss << printPercentage(part, maxNTotal, percentage);
    ss << printTime<highPrecision>(timeSpent, percentage);
    ss << std::flush;
  }

  return ss.str();
}

}
