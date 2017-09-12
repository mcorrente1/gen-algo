//
// Created by Matt Corrente on 9/12/17.
//

#ifndef GEN_ALGO_POPULATION_H
#define GEN_ALGO_POPULATION_H

#include <vector>
#include "Individual.h"

class Population {

private:
    std::vector<Individual> population;
    int fitnessSum;
    void initializePopulation(int popSize, int chromeLength);
    Individual selectParent();
    Individual crossover(Individual p1, Individual p2);
    void sumFitness();
    Population();
    void sortPopDescFitness();
    void addIndividual(Individual ind);
    Individual giveBirth(float crossoverRate, float mutationRate);

public:
    Population(int popSize, int chromeLength);
    Population generateNewPop(float crossoverRate, float mutationRate);
    Individual getIndividual(int index);
    Individual getFittest();
    ~Population();

};


#endif //GEN_ALGO_POPULATION_H
