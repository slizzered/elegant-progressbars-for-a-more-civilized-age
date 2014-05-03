#pragma once

#include <string>
#include <tuple>

namespace ElegantProgressbars{
    
/**
 * Writes progress as an ascii-art progressbar
 *
 * Takes some external time reference and a percentage to express how far the
 * progressbar should be filled. There may be supplied an additional pattern,
 * which will be moving as time passes. The pattern defaults to a sine-wave
 * like pattern. If no such movement and fancyness is desired, a single element
 * may be used as a pattern (e.g. "#").
 *
 * @param tic continuously increasing value related to the real outside time
 * @param percentage the progress as a fraction of 1
 * @param pattern (optional) the pattern of the wave (defaults to a wave)
 * @param length (template, optional) parameter to change the length of the
 *               finished pattern
 */
class Label{
  public:
  inline std::tuple<std::string,unsigned> print(unsigned a, unsigned const b, float percentage){
    return std::make_tuple("Progress:\n",1);
  }
};

}

