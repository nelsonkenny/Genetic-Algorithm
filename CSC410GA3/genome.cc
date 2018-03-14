#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "genome.h"
#include <time.h>       /* time */

using namespace std;

// Default Constructor
   genome::genome(){
        //Initialize the object so that genes is set to NULL and nGenes to 0
        nGenes = 0;
        genes = NULL;
        mRate = 0;
        srand(time(0));
    }
    // Destructor
   genome::~genome(){
        deallocate();
    }

void genome::allocate (int numGenes){
// take as input an integer for the number of these Pixels,
//allocates space for them, and initialize all the RGB values to zero.
// must make sure that if the array already exists (i.e. genes is not NULL) you must free
//up that space before allocating new space.
//This function can call deallocate() to do the first part if you want.
    if (numGenes > 0){
        if (genes != NULL){
            deallocate();
        }
        else{


        genes = new Pixel[numGenes];
        for (int i = 0; i < numGenes; i++){
            genes[i].red = 0;
            genes[i].green = 0;
            genes[i].blue = 0;
        }
        nGenes = numGenes;
        }
    }
}

void genome::deallocate(){ //  to delete space assigned to the genes
    if (nGenes != 0){
        delete[] genes;
        nGenes = 0;
    }
}

void genome::randomize(){

    for ( int init = 0 ; init < nGenes; init ++){
         genes[init].red= 0+ rand() % 256;
         genes[init].green= 0+rand() % 256;
         genes[init].blue= 0+rand() % 256;
    }

}

void genome::set_red(int index, int value){
    if (index > 0){
        if (index < nGenes){
            genes[index].red = value;
        }
    }
}


void genome::set_green(int index, int value){
    if (index > 0){
            if (index < nGenes){
                genes[index].green = value;
            }
        }
}

void genome::set_blue(int index, int value) {
    if (index >= 0){
        if (index < nGenes){
            genes[index].blue = value;
        }
    }
}

int genome::get_red(int index){
    if (index < 0){
        return -1;
    }
    else{
        if (index > nGenes){
            return -1;
        }
        else{
            return genes[index].red;
        }
    }

}

int genome::get_green(int index){
    if (index < 0){
        return -1;
    }
    else{
        if (index > nGenes){
            return -1;
        }
        else{
            return genes[index].green;
        }
    }
}

int genome::get_blue(int index){
    if (index < 0){
        return -1;
    }
    else{
        if (index > nGenes){
            return -1;
        }
        else{
            return genes[index].blue;
        }
    }
}

void genome::print(){

    if (nGenes > 0){
              cout << "GENOME :"<< nGenes<<" genes"<<endl;
             for (int init = 0; init< nGenes; init++){
       cout<< "("<< genes[init].red<<","<< genes[init].green<<","<< genes[init].blue<< ")"<<endl;
    }

    }
    else{
        cout <<"Merede!";
    }


}

void genome::set_mrate(double val){
    if (0<= val <=1){
        mRate = val;
    }
}

double genome::get_mrate(){
    return mRate;
}

void genome::mutate_gene(int index){
    set_mrate(0.9);
    int rand_number = 0 + rand() % 1;
    if (rand_number < mRate){
            genes[index].red = 0 + rand() % 256;
            genes[index].green = 0 + rand() % 256;
            genes[index].blue = 0 + rand() % 256;
    }
}

void genome::mutate(){
    for (int init = 0; init <nGenes; init++){
        mutate_gene(init);
    }
}

double genome::calculate_gene_fitness(int index, Pixel targetPixel){
    double fitness;
    fitness = (abs(targetPixel.red - genes[index].red)+ abs(targetPixel.green - genes[index].green)+abs(targetPixel.blue - genes[index].blue)/3)/255;
    return fitness;
}

double genome::calculate_overall_fitness(Pixel*target, int nPixels){

    double fit = 0;
    if (nPixels = nGenes){
            for (int init=0; init < nPixels;init++){
                fit = fit + calculate_gene_fitness(init, target[init]);
            }
            return fit/nPixels;
    }
}
void genome::set_pixel(int index, Pixel newPixel){
    if (0<= index <= nGenes){
            if ((0<= newPixel.red <=255) && (0<= newPixel.blue <=255)&& (0<= newPixel.green <=255)){
                     genes[index] = newPixel;
        }
    }

}

