#include "elegantProgressbars/fancyProgressbar.hpp"
#include "elegantProgressbars/fancyProgressbar_legacy.hpp"
#include <iostream>

int main(){

  static int const nElements = 1000;

  for(int i=0; i<nElements; ++i){
    std::cerr << ElegantProgressbars::fancyProgressBarLegacy(nElements);
    for(int j=0; j<2000000; ++j){
        int g = i*j;
        if (g)
          ;
    }
  }

  std::cerr << "\n";
  for(int i=0; i<nElements; ++i){
    std::cerr << ElegantProgressbars::fancyProgressBar<true>(nElements);
    for(int j=0; j<2000000; ++j){
        int g = i*j;
        if (g)
          ;
    }
  }

  return 0;
}
