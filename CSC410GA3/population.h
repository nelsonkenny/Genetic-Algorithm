#include <iostream>
#include "genome.h"
#ifndef _population_h
#define _population_h

class population{
  public:
    int nIndividuals;
    int nGenes;
    int nCrossOver;
    Pixel *targetImage; 
    int targetSize;
    int fittest;
    int second_fittest;


    population();
    ~population();
    genome *individuals;
 

    
    
    void generate_population(int nGenomes, int nGenes);//create a randomly generated population of nGenomes individuals. You can assume that nGenomes is an even number
    
   
    void set_nCrossover(int numCrossOver); //A void function called set_nCrossover() that sets the number of crossover points .
    void set_mutation(double mRate);
    // A void function called set_mutation(double nRate) that sets the mutation rate of each individual genome to vmRate.
    void set_target(Pixel*target, int imageSize); //A void function called set_target(Pixel* target, int imageSize) that sets the target fitness image in
    //the class to be used to calculate the relative fitnesses of all the individual genomes. How you do this is up to you, but I recommend you also save
    // the value in imageSize somewhere too.
    void find_top_two_individuals(Pixel*);// Determine the two overall best individuals in the current population based on their relative fitness. It then records    that information in appropriately named variables. You can set the two parent indices to 0 and 1 if the user has not yet set the target image in this
    // class
     void find_roulette_top_individuals(Pixel*); //A void function called find_roulette_top_individuals() that sets the individuals’ fitnesses on a
     //roulette wheel and selects two using random chance on that wheel. Note that if an individual has a bigger fitness, it should occupy a larger part of that wheel.   
    void generate_new_population(int useRoulette);
    //A void function called generate_new_population( int useRoulette ) that generates the next population using the parents selected using the roulette
    // strategy if useRoulette is true and the simple top two otherwise. 
    

    double calculate_pop_overall_fitness();//A double function called calculate_overall_fitness() that returns the average fitness of this population.
    void print_population(); //A void function called print_population() that prints out the screen the population is a readable manner.
};
#endif
