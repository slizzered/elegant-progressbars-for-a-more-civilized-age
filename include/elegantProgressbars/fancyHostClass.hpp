#pragma once

#include <sstream>
#include <string>
#include <chrono>
#include <tuple>

namespace ElegantProgressbars{
    
/**
 * Writes a fancy progressbar with minimal input
 *
 * Takes the total number of elements to process and creates a nice progressbar
 * from that. This is intended to be called in a loop / recursion / MPI thread
 * / pthread / etc. It should be called each time one of the nTotal elements is
 * done processing.
 * Operation can be fine-tuned to write time with high precision and different
 * length of the progressbar through template arguments.
 *
 * @param nTotal the total number of elements to process. If multiple values
 *               are supplied in different calls, the function will try to use
 *               the highest of those values.
 * @param current (optional) the element you are currently at. This can be used
 *               to overwrite the default behaviour (which is to assume that an
 *               element was successfully processed each time this function is
 *               called)
 * @param highPrecision (template, optional) if set to true, time will be 
 *               displayed with additional milliseconds
 * @param length (template, optional) used to change the length of the printed
 *               progressbar
 *
 *
 */



template<typename Head>
std::tuple<std::string, unsigned> iteratePolicies(unsigned part, unsigned const maxPart){
  return Head::print(part, maxPart);
}

template<typename Head, typename Head2, typename... Tail>
std::tuple<std::string, unsigned> iteratePolicies(unsigned part, unsigned const maxPart){
  std::stringstream ss;
  std::string s;
  unsigned pheight;
  unsigned height = 0;

  std::tie(s,pheight) = iteratePolicies<Head>(part, maxPart);
  height += pheight;
  ss << s;

  std::tie(s,pheight) = iteratePolicies<Head2, Tail...>(part, maxPart);
  height += pheight;
  ss << s;

  return std::make_tuple(ss.str(),height);
}


template<typename... PolicyList>
inline std::string fancyHostClass(
    unsigned const nTotal
    ){

  using namespace std::chrono;
  typedef duration<long long int, std::milli> milliseconds;

  unsigned current = 0;
  static unsigned maxNTotal = 0;
  static unsigned part = 0;
  static unsigned tic  = 0;
  static time_point<steady_clock> startTime;
  if(part==0){ startTime = steady_clock::now(); } // get the starting time on the very first call

  std::stringstream ss;
  auto const now = steady_clock::now();

  maxNTotal = std::max(maxNTotal, nTotal);
  part = current ? current : ++part;

  //limit the update intervall (not faster than every 35ms. This would be madness.)
  duration<float> const timeSpent = now - startTime;
  if(timeSpent.count() > 0.035f*tic || part == maxNTotal){
    ++tic;

    std::string frame;
    unsigned height;
    std::tie(frame, height) = iteratePolicies<PolicyList...>(part, maxNTotal);
    ss << frame;
    ss << std::flush;
    if(part!=maxNTotal) ss << "\033[" << height << "A\r"; //move the cursor back to the beginning
    else ss << "\n";
  }

  return ss.str();
}

}
