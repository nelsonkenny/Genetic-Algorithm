#include <iostream>
#include <fstream>
#include "population.h"
using namespace std;

int main(){
Pixel*target;
target = new Pixel[4];
for (int i = 0; i < 4; i++ ){
    target[i].red = 110;
    target[i].blue = 180;
    target[i].green = 50;

}



/* Testing GA2:
    genome myGenome;
    myGenome.print();// This function will output nothing because genes is null and nGenes is set to zero
    myGenome.allocate(4); // This line will allocate an array of 4 pixels in myGenome. All the RGB values will be zeroed
    myGenome.print(); // This line would output to the console something like: GENOME: 4 genes (0,0,0) (0,0,0) (0,0,0) (0,0,0)
    myGenome.randomize();//This line will assign random values to the Pixels in myGenome
    myGenome.print(); // This line would output to the console genes with random values: GENOME: 4 genes (10,56,23) (67,190,3) (156,203,244) (0,6,152)
    myGenome.set_blue(0,226);//This line will assign 226 to the blue value of pixels in myGenome at position 0
    myGenome.print();//
    myGenome.randomize();
    myGenome.print();
    myGenome.mutate_gene(0);
    myGenome.print();
    myGenome.mutate();
    myGenome.print();
    myGenome.calculate_overall_fitness(target,4);
    myGenome.set_pixel(0, *target);
    myGenome.print();
*/
/* Testing GA3:
    population myPopulation;
    myPopulation.generate_population(6,4);
    myPopulation.print_population();
    myPopulation.set_mutation(0.6);
    myPopulation.find_top_two_individuals(target);
    myPopulation.find_roulette_top_individuals(target);
    myPopulation.set_nCrossover(6);
    myPopulation.generate_new_population(0.3);
    myPopulation.set_target(target,4);
    myPopulation.calculate_pop_overall_fitness();
*/
return 0;


}
