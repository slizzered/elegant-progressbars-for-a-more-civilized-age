#pragma once

#include <string>
#include <sstream>
#include <cassert> /*assert*/
#include <tuple>
#include <vector>

#define HTOP   "############# "
#define HE1    "#           # "
#define HE2    " #         # "
#define HE3    "   #     # "
#define HE4    "     # # "
#define H5     "      # "
#define HE6    "     # # "
#define HE7    "   #     # "
#define HE8    " #         # "
#define HE9    "#           # "
#define HBOT   "############# "

#define HF1    "############# "
#define HF2    " ########### "
#define HF3    "   ####### "
#define HF4    "     ### "

#define HF6    "     ### "
#define HF7    "   ####### "
#define HF8    " ########### "
#define HF9    "############# "


    

namespace ElegantProgressbars{
    
inline std::tuple<std::string, unsigned> printHourglass(
    float const percentage
    ){
  static std::vector<std::string> hglass1 =  {HTOP, HF1, HF2, HF3, HF4, H5, HE6, HE7, HE8, HE9, HBOT};
  static std::vector<std::string> hglass2 =  {HTOP, HE1, HF2, HF3, HF4, H5, HE6, HE7, HE8, HF9, HBOT};
  static std::vector<std::string> hglass3 =  {HTOP, HE1, HE2, HF3, HF4, H5, HE6, HE7, HF8, HF9, HBOT};
  static std::vector<std::string> hglass4 =  {HTOP, HE1, HE2, HE3, HF4, H5, HE6, HF7, HF8, HF9, HBOT};
  static std::vector<std::string> hglass5 =  {HTOP, HE1, HE2, HE3, HE4, H5, HF6, HF7, HF8, HF9, HBOT};
  static std::vector<std::vector<std::string> > hglass = { hglass1, hglass2, hglass3, hglass4, hglass5};

  std::stringstream stream;
  assert(percentage <= 1.f);
  unsigned framecount = hglass.size();
  unsigned progress = static_cast<unsigned>(percentage*framecount);
  progress = progress >= framecount ? framecount-1 : progress;

  auto frame = hglass[progress];
  for(unsigned i=0 ; i< frame.size() ; ++i){
    stream << frame.at(i) << std::endl;
  }
  return std::tuple<std::string, unsigned>(stream.str(), hglass1.size());
}

}
