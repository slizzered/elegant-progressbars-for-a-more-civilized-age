#pragma once

#include <sstream>
#include <string>
#include <sys/time.h>

#include "printPattern.hpp"
#include "printPercentage.hpp"
#include "printTime_legacy.hpp"

namespace ElegantProgressbars{
    
float timevalDiff(timeval const end, timeval const start){
  return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) * 1e-6;
}

std::string fancyProgressBarLegacy(
    unsigned const nTotal, 
    unsigned const current = 0
    ){

  static unsigned maxNTotal = 0;
  static unsigned part = 0;
  static unsigned tic  = 0;
  static timeval startTime;
  if(part==0){ gettimeofday(&startTime,NULL); } // get the starting time on the very first call

  int const length = 50;
  std::stringstream ss;
  timeval now;
  gettimeofday(&now,NULL);

  maxNTotal = std::max(maxNTotal, nTotal);
  part = current ? current : ++part;

  //limit the update intervall (not faster than every 35ms. This would be madness.)
  float const timeSpent = timevalDiff(now, startTime);  
  if(timeSpent > 0.035f*tic || part == maxNTotal){
    ++tic;
    float const percentage  = static_cast<float>(part) / static_cast<float>(maxNTotal);

    ss << "\rProgress: [";
    ss << printPattern(tic, percentage, length);
    ss << "] ";
    ss << printPercentage(part, maxNTotal, percentage);
    ss << printTime(timeSpent, percentage);
    ss << std::flush;
  }

  return ss.str();
}

}
