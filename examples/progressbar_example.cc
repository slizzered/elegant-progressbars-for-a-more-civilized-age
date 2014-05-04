#include "elegantProgressbars/fancyProgressbar.hpp"
#include "elegantProgressbars/fancyProgressbar_legacy.hpp"
#include "elegantProgressbars/fancyHostClass.hpp"
#include "elegantProgressbars/Label.hpp"
#include "elegantProgressbars/Percentage.hpp"
#include "elegantProgressbars/Time.hpp"
#include "elegantProgressbars/Hourglass.hpp"
#include "elegantProgressbars/Newline.hpp"
#include "elegantProgressbars/Pattern.hpp"
#include <iostream>


//just some workload -> don't use optimizations, if you want that to work
void workload(){
  for(int j=0; j<2000000; ++j){
    int g = j;
    if (g)
      ;
  }
}

using namespace ElegantProgressbars;
int main(){
  static int const nElements = 1000;


  for(int i=0; i<nElements; ++i){
    workload();
    std::cerr << fancyHostClass<Hourglass,Label,Pattern<>,Percentage,Time<> >(nElements);
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
    std::cerr << ElegantProgressbars::fancyProgressBar<false,30>(nElements);
  }

  return 0;
}
