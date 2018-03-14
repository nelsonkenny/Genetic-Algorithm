#include <iostream>
#ifndef _genome_h
#define _genome_h

struct Pixel {
 int red;
 int green;
 int blue;
 };

class genome {
    public:
    int nGenes;
    Pixel *genes;
    double mRate;
    genome();
    ~genome();
    void allocate (int numGenes ); // take as input an integer for the number of these Pixels,
//allocates space for them, and initialize all the RGB values to zero.
// must make sure that if the array already exists (i.e. genes is not NULL) you must free
//up that space before allocating new space.
//This function can call deallocate() to do the first part if you want.
    void deallocate();//will free up the space that is pointed to by genes and sets nGenes to zero.
//Note that if genes is already NULL, there is no space to delete and you can return
//right away without doing anything.  
    void randomize(); //sets random values between 0 and 256 for each of the red, green, and blue variables
//for each Pixel in the genes array.
    void set_red(int index, int value);//finds the Pixel at index and sets red to their new values, respectively.
//This function must make sure that it checks for valid index values (so that index is greater than or equal to 0
//and less than nGenes)! You can either use the assert() function or simply check for the validity and return without
//changing anything on any illegal values.
    void set_green(int index,int value);//finds the Pixel at index and sets green to their new values, respectively.
//This function must make sure that it checks for valid index values (so that index is greater than or equal to 0
//and less than nGenes)! You can either use the assert() function or simply check for the validity and return without
//changing anything on any illegal values.
    void set_blue(int index,int value);//finds the Pixel at index and sets blue to their new values, respectively.
//This function must make sure that it checks for valid index values (so that index is greater than or equal to 0
//and less than nGenes)! You can either use the assert() function or simply check for the validity and return without
//changing anything on any illegal values.
    int get_red(int index);//returns the red values of the Pixel at index, respectively. This function must make sure that it 
    //checks for valid index values (so that index is greater than or equal to 0 and less than nGenes) and return -1 if the index is invalid.
    int get_green(int index);//returns the green values of the Pixel at index, respectively. This function must make sure 
    //that it checks for valid index values (so that index is greater than or equal to 0 and less than nGenes) and return -1 if the index is invalid.
    int get_blue(int index); 
    //returns the blue values of the Pixel at index, respectively. This function must make sure that 
    //it checks for valid index values (so that index is greater than or equal to 0 and less than nGenes) and return -1 if the index is invalid.
  void print();
//output the genes in a readable way to the console. 
  void set_mrate(double val);     
};
#endif
