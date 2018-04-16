#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "population.h"
using namespace std;
#include <string>

int go(Pixel*target, int nIndividuals, int nGenes, double mRate, int nCrossover, int nGenerations, int nRows, int nCols){
// This function initializes the first population, runs fitness test, pick best individuals and reiterate to create new generations."
    ofstream outFile; // file object to be used to write the output text
    double fitness; // the overall fitness of the population
    int fittest; // the index of the fittest individual
    population myPopulation; // population class object
    genome* ideal; // genome class object to represent the fittest individual
    myPopulation.generate_population(nIndividuals,nGenes); //Initialize the first population
   // myPopulation.print_population();
    myPopulation.set_mutation(mRate); 
    myPopulation.set_target(target,4);
    myPopulation.find_roulette_top_individuals(target);
    myPopulation.set_nCrossover(nCrossover);
    for (int i = 0; i < nGenerations; i++){
       myPopulation.generate_new_population();
       myPopulation.find_top_two_individuals(target); 
    }  
    fitness = myPopulation.calculate_pop_overall_fitness();
    fittest = myPopulation.fittest;
   
    //myPopulation.print_population();
    
    //The following lines are to write the ouptut to the text file
    
    outFile.open("output.txt");
    outFile <<"fitness: "<< fitness <<"\n";
    outFile <<"nRows: "<< nRows <<"\n";
    outFile <<"nCols: "<< nCols <<"\n";
    ideal = &myPopulation.individuals[fittest];
     for (int j = 0; j < nRows ; j++){
          
          for (int i = 0 ; i < nCols; i++){
             outFile<<"("<<ideal[j].genes[i].red<<" "<<ideal[j].genes[i].green<<" "<<ideal[j].genes[i].blue<<")";     
          }
          outFile <<"\n";          
      }
}
int main(){
  ifstream inFile;
  
  
  int nRows=0, nCols=0;
  
  std::string trash;
  
  int nGenerations = 0;
  
  int nIndividuals = 0; 
  
  int nGenes = 0; 
  
  double mRate = 0.0; 
  
  int nCrossover;
  
  int redValue;
  int greenValue;
  int blueValue;
 
  char*filename;
  cout<<"Please type the input filename:"<<endl;
  cin>>filename;
  inFile.open(filename);
  
  if (!inFile) {
      cout << "Unable to open file";  
    }
  else{  
    inFile >> trash>> nGenerations>> trash >> nIndividuals >> trash >> nGenes >> trash >> mRate >> trash >>nCrossover>>trash>> nRows >> trash >> nCols; 
    }

      
  Pixel*target;
  target = new Pixel[nGenes];
  for (int i = 0; i < nGenes; i++ ){
      inFile >> trash >> redValue;
      target[i].red = redValue;
      inFile>>greenValue;
      target[i].green = greenValue;
      inFile>>blueValue;
      target[i].blue = blueValue;
      inFile >> trash;
  } 
  
  inFile.close();
  
  //The go function launches the genetic algorithm 
  go(target, nIndividuals, nGenes, mRate, nCrossover, nGenerations, nRows, nCols);
 


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
