#include <stdlib.h>
#include <iostream>
#include "population.h"

using namespace std;
// Default Constructor
   population::population(){
       individuals = NULL;
       nIndividuals = 0;
       nGenes = 0;
       nCrossOver = 1;
    }
    // Destructor
   population::~population(){
       if (individuals != NULL){
            delete[] individuals;

            nIndividuals = 0;
       }
    }

   void population::generate_population(int nGenomes,int numGenes){
       /*This method is to generate a population*/

       individuals = new genome[nGenomes]; //create an array of genomes

       nIndividuals = nGenomes; //number of individuals in the population

       nGenes = numGenes;

       for (int i = 0; i < nIndividuals; i++){
            individuals[i].allocate(nGenes); //add pixel values to the genes
            individuals[i].randomize();//randomize the pixel values
       }
    }
   void population::find_top_two_individuals(Pixel*target){
    /*A void function called find_top_two_individuals() that determines the two overall best individuals in the
    current population based on their relative fitness. It then records that information in appropriately named
     variables. You can set the two parent indices to 0 and 1 if the user has not yet set the target image in
     this class.*/
     double fitnessArray[nIndividuals];
     double temp_1 = 0.0;
     double temp_2 = 0.0;
     targetImage = target;

     for (int i = 0; i < nIndividuals; i++){
            fitnessArray[i] = individuals[i].calculate_overall_fitness(target, nGenes);
     }
     for (int i = 0; i < nIndividuals; i++){
        if (fitnessArray[i] > temp_1){
                temp_1 = fitnessArray[i];
                fittest = i;
        }
     }
     for (int i = 0; i <nIndividuals; i++){
        if (fitnessArray[i] > temp_2){
            if (i != fittest){
                temp_2 = fitnessArray[i];
                second_fittest = i;

            }
        }
     }
   }

   void population::find_roulette_top_individuals(Pixel*target){
       double sumFitness =0.0; // sum of all the fitness values

       double fitnessArray[nIndividuals+1]; //This array will hold the fitness value of each individual.
       //This array is slightly bigger than the number of individuals to ease the calculation of relative fitness

       double relativeFitnessArray[nIndividuals+1]; //This array will hold the relative fitness value of each individual.

       double rouletteArray[nIndividuals]; //This array will hold the roulette value of each individual by summing relative fitness values

       targetImage = target; //This is a pixel object that is used to compare the population with

       fitnessArray[0] = 0.0;//The first index is given the value 0 to help with the construction of the wheel to create
       // the interval

       for (int i = 1; i < nIndividuals+1; i++){
             //calculate the overall fitness of each individual and add it to the fitness array
            fitnessArray[i] = individuals[i-1].calculate_overall_fitness(target, nGenes);


            sumFitness = sumFitness + fitnessArray[i];
       }
       for (int i = 0; i < nIndividuals+1; i++){
            // Calculate the relative fitness of each individual
            relativeFitnessArray[i] = fitnessArray[i]/sumFitness;
       }
       for (int i = 0; i < nIndividuals + 1; i++){
            //Calculate the values that will be in the roulette array
            rouletteArray[i] = fitnessArray[i]+fitnessArray[i++];
       }
       double randNumOne = 0 + rand() % 1; //first random number
       double randNumTwo = 0 + rand() % 1; // second random number

       for (int i = 0; i < nIndividuals; i++){
        // Iterate through the rouletteArray to find the fittest individuals
        if (rouletteArray[i] <randNumOne <rouletteArray[i++]){
            fittest = i;
        }
        if (rouletteArray[i] <randNumTwo <rouletteArray[i++]){
            second_fittest = i;
        }
       }
   }

   void population::set_nCrossover(int numCrossOver ){
        nCrossOver = numCrossOver;
   }

   void population::set_mutation(double mRate){
       for (int i = 0; i < nIndividuals; i++){
        individuals[i].mRate = mRate;
       }
   }
   void population::set_target(Pixel*target, int imageSize){
       targetImage = target;
       targetSize = imageSize;
   }

   void population::generate_new_population(int useRoulette){
       if ( 0 < useRoulette < 0.5){
            //Use find top two individuals
            find_top_two_individuals(targetImage);
       }
       else {
        // Use roulette selection
          find_roulette_top_individuals(targetImage);
       }
       //Create the genomes to hold the two parents
       genome parentOne;
       genome parentTwo;
       parentOne.allocate(nGenes);
       parentTwo.allocate(nGenes);

       //Copying the genes of the top two fittest individuals from the old generation into the genomes for the new parents for the
       //dynamic array that hold the individuals will be deleted.
       for (int i = 0; i < nGenes; i++){
            parentOne.genes[i].red = individuals[fittest].genes[i].red;
            parentOne.genes[i].green = individuals[fittest].genes[i].green;
            parentOne.genes[i].blue = individuals[fittest].genes[i].blue;

            parentTwo.genes[i].red = individuals[second_fittest].genes[i].red;
            parentTwo.genes[i].green = individuals[second_fittest].genes[i].green;
            parentTwo.genes[i].blue = individuals[second_fittest].genes[i].blue;
       }
       // Delete the individuals of the old population
       for (int i = 0; i < nIndividuals; i++){
            individuals[i].deallocate();
       }
       // Create another dynamic array to hold the new population
        individuals = new genome[nIndividuals];
         for (int i = 0; i < nIndividuals; i++){
            individuals[i].allocate(nGenes); //add pixel values to the genes
       }

       // Randomly choosing the crossover points
       int swapArray[nCrossOver];
        for (int i = 0; i < nCrossOver; i++){
            int index =  0 + rand() % + (nGenes-1);
            swapArray[i] = index ;

        }
        // Order the crossover indices from the smallest to the highest
        for (int i = 0; i < nCrossOver; i++){
            for (int j = 0; j < nCrossOver; j++){
                if (swapArray[j]>swapArray[j+1]){
                    int temp = swapArray[j];
                    swapArray[j] = swapArray[j+1];
                    swapArray[j+1] = temp;
                }
            }
        }

        // Adding the parents to the new population
        for (int i = 0; i < nGenes; i++){
            individuals[0].genes[i].red = parentOne.genes[i].red;
            individuals[0].genes[i].green = parentOne.genes[i].green;
            individuals[0].genes[i].blue = parentOne.genes[i].blue;

            individuals[1].genes[i].red = parentTwo.genes[i].red;
            individuals[1].genes[i].green = parentTwo.genes[i].green;
            individuals[1].genes[i].blue = parentTwo.genes[i].blue;

        }
        individuals[0].mutate();
        individuals[1].mutate();

        for (int i = 2; i < nIndividuals; i++){
            for (int j = 0; j < nGenes; j++){
                if (j == swapArray[i]){
                        //Swap True
                    individuals[i].genes[j].red = parentTwo.genes[j].red;
                    individuals[i].genes[j].green = parentTwo.genes[j].green;
                    individuals[i].genes[j].blue = parentTwo.genes[j].blue;
                }
                else{
                    //Swap False
                    individuals[i].genes[j].red = parentOne.genes[j].red;
                    individuals[i].genes[j].green = parentOne.genes[j].green;
                    individuals[i].genes[j].blue = parentOne.genes[j].blue;
            individuals[i].mutate();
                }

            }
   }
         cout<<"Here"<<endl;
       print_population();
   }
   double population::calculate_pop_overall_fitness(){
       double sumFitness = 0;
       for (int i = 0; i < nIndividuals ; i++){
        sumFitness = sumFitness + individuals[i].calculate_overall_fitness(targetImage, targetSize);

       }
       cout <<sumFitness/nIndividuals<<endl;
       return sumFitness/nIndividuals;

   }


   void population::print_population(){
      for (int i = 0; i < nIndividuals; i++){
        individuals[i].print();
        cout<<" "<<endl;
       }

   }
