#pragma once

#include <iomanip>  /*setw, setfill*/
#include <sstream>  /*stringstream*/
#include <cmath>    /*log10*/
#include <string>   /*return value string*/
#include <cassert>  /*assert*/

namespace ElegantProgressbars{
    
std::string printPercentage(unsigned part, unsigned const maxPart, float const percentage){
    std::stringstream stream;

    assert(percentage <= 1.f);
    assert(maxPart > 0);

    static const unsigned fillwidthPart = static_cast<unsigned>(1+std::log10(maxPart));
    stream << std::setfill(' ') << std::setw(3) << static_cast<int>(percentage*100) << "%";
    stream << " (" << std::setfill(' ') << std::setw(fillwidthPart) << part;
    stream << "/" << maxPart << ")";
    return stream.str();
}

}
