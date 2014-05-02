#pragma once

#include <chrono>
#include <sstream>
#include <string>
#include <cassert> /*assert*/

namespace ElegantProgressbars{
    
/**
 * Writes the time in a human-friendly way
 *
 * The returned string will be formatted to display the time in terms of hours,
 * minutes and seconds. If the duration is small enough, some of those will be
 * omitted. A template argument allows to include also milliseconds
 * Example: 5000s -> 1h 23m 20s
 *          1000s -> 16m 40s
 *          (highPrecision) 1.1s   -> 1s 100ms
 *
 * @param highPrecision (template, optional) if set to true, the time will also
 *                      be displayed in terms of milliseconds
 * @param time the duration to write
 */
template<bool highPrecision = false>
inline std::string humanRepresentation(
    std::chrono::duration<float> const time){

  using std::chrono::duration;
  using std::chrono::duration_cast;

  typedef duration<int, std::milli> milliseconds;
  typedef duration<int, std::ratio<1,1>> seconds;
  typedef duration<int, std::ratio<60,1>> minutes;
  typedef duration<int, std::ratio<3600,1>> hours;
  
  auto const tMsec = duration_cast<milliseconds>(time).count() % 1000;
  auto const tSec  = duration_cast<seconds>(time).count()      % 60;
  auto const tMin  = duration_cast<minutes>(time).count()      % 60;
  auto const tHour = duration_cast<hours>(time).count();

  std::stringstream ss;

  if(tHour)                  ss << tHour << "h ";
  if(tMin)                   ss << tMin  << "m "; 
  if(tSec || !highPrecision) ss << tSec  << "s";

  if(highPrecision)   ss << " " << tMsec << "ms";

  return ss.str();
}



/**
 * Writes progress expressed as time passed
 *
 * Takes the time that was already spent on a task and the percentage of
 * completion of said task. These parameters are used to calculate remaining
 * time and overall time to completion and writes it in a nice, human-friendly
 * fashion.
 *
 * @param tSpent the time that was spent at the current task
 * @param percentage the percentage the current task is at (as a fraction of 1)
 * @param highPrecision (template, optional) if set to true, the time will also
 *                      be displayed in terms of milliseconds
 */
template<bool highPrecision = false>
inline std::string printTime(std::chrono::duration<float> const tSpent, float const percentage){
  using std::chrono::duration;
  typedef duration<int, std::ratio<60,1>> minutes;
  typedef duration<int, std::ratio<3600,1>> hours;
  std::stringstream stream;

  assert(percentage <= 1.f);

  auto const tTotal = tSpent / percentage;
  auto const tRemaining = tTotal - tSpent;

  stream << " after " << humanRepresentation<highPrecision>(tSpent);
  stream << " ("      << humanRepresentation<highPrecision>(tTotal)     <<" total";
  stream << ", "      << humanRepresentation<highPrecision>(tRemaining) << " remaining)";
  return stream.str();
}

}
