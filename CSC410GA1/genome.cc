#include <stdlib.h>
#include <iostream>
#include "genome.h"
using namespace std;

// Default Constructor
   genome::genome(){
        //Initialize the object so that genes is set to NULL and nGenes to 0
        nGenes = 0;
        genes = NULL;
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
        genes = new Pixel[numGenes];
        genes = 0;
        nGenes = numGenes;
    }
}

void genome::deallocate(){ //  to delete space assigned to the genes
    if (nGenes != 0){
        delete[] genes;
        ngenes = 0;
    }
}

void genome::randomize(){
    int init;
    for (init ; init < nGenes; init ++){
         genes[init].red= 0 + rand() % 256;
         genes[init].green= 0 + rand() % 256;
         genes[init].blue= 0 + rand() % 256;
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
    if (index > 0){
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
    cout << "GENOME";
    cout << nGenes;
    int init = 0;
    for (init; nGenes-1; init++){
       cout << "(";
       cout << genes[init].red;
       cout << genes[init].green;
       cout << genes[init].blue;
       cout << ")";
    }

}

void genome::set_mRate(double val){
    if (0<= val <=1){
        mRate = val;
    }
}

double get_mRate(){
}
