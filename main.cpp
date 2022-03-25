#include <iostream>
#include "funcs.h"

int main()
{
    invert("image1.pgm");
    invertHalf("image1.pgm");
    whiteBox("image1.pgm");
    whiteBoxOutline("image1.pgm");
    scale("image1.pgm");
    pixelate("image1.pgm");

    return 0;

}