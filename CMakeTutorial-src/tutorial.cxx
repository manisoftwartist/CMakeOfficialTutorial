// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Include from the CMake project "Tutorial" currently being built
// This file is configured and added by CMake command 'configure_file'
#include "TutorialConfig.h"	

#ifdef USE_MYMATHFUNCTIONS
	#include "MathFunctions.h"
#endif

int main (int argc, char *argv[])
{
  if (argc < 2)
    {
      // Print variables from the CMake configured header file
      fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
  
  
  /*
   *  sqrt from MATHFUNCTIONS library or from default C
   */
#ifdef USE_MYMATHFUNCTIONS
  double outputValue = mysqrt(inputValue);  
#else
  double outputValue = sqrt(inputValue);
#endif
  
  
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}
