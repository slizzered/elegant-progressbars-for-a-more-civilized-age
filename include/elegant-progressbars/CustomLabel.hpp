#pragma once

#include <string>
#include <tuple>
#include <boost/mpl/string.hpp>

namespace ElegantProgressbars{

/** Writes a simple label, ignores all input
 */
template<typename T_Label = boost::mpl::string<'Prog','res','s: '> >
class CustomLabel{
  public:
  inline static std::tuple<std::string,unsigned> print(...){
    std::string s = boost::mpl::c_str<T_Label>::value;
    return std::make_tuple(s,0);
  }
};

}

