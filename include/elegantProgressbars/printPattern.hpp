#pragma once

#include <string>
#include <sstream>
#include <cassert> /*assert*/

namespace ElegantProgressbars{
    
/**
 * @brief returns a string of ascii-art in the style of a sine-wave
 *
 * @param tic continuously increasing value related to the real outside time
 * @param percentage the progress as a fraction of 1 (0-1)
 * @param length the length of the finished wave.
 * @param pattern the pattern of the wave (defaults to a wave)
 */
std::string printPattern(
    unsigned const tic,
    float const percentage,
    unsigned const length,
    std::wstring pattern = L"ø¤º°`°º¤ø,¸,"
    ){

  std::stringstream stream;
  assert(percentage <= 1.f);
  unsigned const progress = static_cast<unsigned>(percentage*length);
  unsigned const plength = pattern.length();
  std::wstring::iterator const bg = pattern.begin();

  for(unsigned i=0 ; i<progress ; ++i){
    unsigned const pos = (tic+i) % plength;
    stream << std::string(bg + pos, bg + pos+1);
  }
  for(unsigned i=0; i < length-progress ; ++i){
    stream << " ";
  }
  return stream.str();
}

}
