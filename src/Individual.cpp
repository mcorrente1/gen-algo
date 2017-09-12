//
// Created by Matt Corrente on 9/12/17.
//

#include <cstdlib>
#include <iostream>
#include "Individual.h"

Individual::Individual(){

}

Individual::Individual(int cLength){
    chromosomeLength = cLength;
    initializeChromosome();
    setFitness();
}

Individual::Individual(int cLength, std::vector<char> chromeString) {
    chromosomeLength = cLength;
    chromosome = chromeString;
    setFitness();
}

Individual::~Individual() {
    chromosome.clear();
}

//generates a random sequence of 1's and 0's of size n
void Individual::initializeChromosome() {
    for (int i = 0; i < chromosomeLength; i++) {
        if (std::rand() % 2) {
            chromosome.push_back('1');
        }
        else {
            chromosome.push_back('0');
        }
    }
}

//in this case the fitness function returns the number of 1's in a given string
void Individual::setFitness(){
    fitness = 0;
    for(int i = 0; i < chromosomeLength; i++){
        if(chromosome.at(i) == '1'){
            fitness += 1;
        }
    }

}

int Individual::getChromosomeLength(){
    return chromosomeLength;
}


int Individual::getFitness() const {
    return fitness;
}

std::string Individual::getChromosomeString(){
    return std::string(chromosome.begin(), chromosome.end());
}

bool Individual::operator <(const Individual& rhs) const {
    return fitness < rhs.getFitness();
}

bool Individual::operator >(const Individual& rhs) const {
    return fitness > rhs.getFitness();
}

//bit flip mutation
void Individual::mutate() {
    int rand = std::rand()%chromosomeLength;
    if(chromosome.at(rand) == '1')
        chromosome[rand] = '0';
    else
        chromosome[rand] = '1';
}
