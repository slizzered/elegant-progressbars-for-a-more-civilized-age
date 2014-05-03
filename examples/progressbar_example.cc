#include "elegantProgressbars/fancyProgressbar.hpp"
#include "elegantProgressbars/fancyHourglass.hpp"
#include "elegantProgressbars/fancyProgressbar_legacy.hpp"
#include "elegantProgressbars/fancyHostClass.hpp"
#include "elegantProgressbars/Label.hpp"
#include "elegantProgressbars/Percentage.hpp"
#include <iostream>


//just some workload -> don' use optimizations, if you want that to work
void workload(){
  for(int j=0; j<2000000; ++j){
    int g = j;
    if (g)
      ;
  }
}

int main(){
  static int const nElements = 1000;


  ElegantProgressbars::Label l;
  ElegantProgressbars::Percentage p;
  for(int i=0; i<nElements; ++i){
    workload();
    std::cerr << ElegantProgressbars::fancyHostClass(nElements, l, p);
  }


  for(int i=0; i<nElements; ++i){
    workload();
    std::cerr << ElegantProgressbars::fancyHourglass<false>(nElements);
  }

  std::cerr << "\n";

  //this one is the progressbar without C++11 features (std::chrono, most notably)
  for(int i=0; i<nElements; ++i){
    workload();
    std::cerr << ElegantProgressbars::fancyProgressBarLegacy(nElements);
  }

  std::cerr << "\n";

  //the template argument is for displaying milliseconds and can be omitted (defaults to false)
  for(int i=0; i<nElements; ++i){
    workload();
    std::cerr << ElegantProgressbars::fancyProgressBar<true>(nElements);
  }

  std::cerr << "\n";

  //the template argument is for displaying milliseconds and can be omitted (defaults to false)
  for(int i=0; i<nElements; ++i){
    workload();
    std::cerr << ElegantProgressbars::fancyProgressBar<false,30>(nElements);
  }

  return 0;
}
