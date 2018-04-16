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
  void set_mrate(double val);//This function sets the member variable mRate equal to val. Checks to make sure that val is valid. 
  double get_mrate();//This function returns the current mRate value.
  void mutate_gene(int index);//This function takes the index of a particular Pixel and for every color, if a randomly generated number is less than mRate
  //It assigns a random value between 0 and 255 to it. 
  void mutate(); //This function goes through the entire genes array and calls the mutate_gene(int index) function on every element
  double calculate_gene_fitness(int index, Pixel targetPixel);//This function goes the Pixel at position index and calculates the average percent
  // difference of the RGB values between targetPixel and genes[index]
  double calculate_overall_fitness(Pixel*target, int nPixels); // This function takes an array of Pixels and the size of the image(nPixels) and compares    // the target with its own genes. It should check to make sure that the input size nPixels matches nGenes. It returns -1 if failure. Otherwise,it
  //calculates the average difference between the two and returns that value. 
  void set_pixel(int index, Pixel newPixel);//This function takes the newPixel and set the Pixel at position index to be equal to it. 
  //The function should check to make sure that index is valid (between 0 and nGenes) and that the rgb values in newPixel (between 0 and 255 inclusive).    
};
#endif
