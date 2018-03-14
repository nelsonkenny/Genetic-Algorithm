#include <iostream>
#include "genome.h"

using namespace std;

int main()
{
    genome myGenome;// This line will declare a variable called myGenome that is of type genome. The default constructor will be called.
    myGenome.print();// This function will output nothing because genes is null and nGenes is set to zero
    myGenome.allocate(4); // This line will allocate an array of 4 pixels in myGenome. All the RGB values will be zeroed
    myGenome.print(); // This line would output to the console something like: GENOME: 4 genes (0,0,0) (0,0,0) (0,0,0) (0,0,0)
    myGenome.randomize();//This line will assign random values to the Pixels in myGenome
    myGenome.print(); // This line would output to the console genes with random values: GENOME: 4 genes (10,56,23) (67,190,3) (156,203,244) (0,6,152)
    myGenome.set_blue(0,226);//This line will assign 226 to the blue value of pixels in myGenome at position 0
    myGenome.print();//This function would output to the console the RGB values, and assuming you decided to output the values in RGB, it would be: GENOME: 4 genes (10,56,226) (67,190,3)(156,203,244)(0,6,152)
    return 0;
}



