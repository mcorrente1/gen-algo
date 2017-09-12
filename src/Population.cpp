//
// Created by Matt Corrente on 9/12/17.
//

#include <cstdlib>
#include <iostream>
#include "Population.h"

//this is a private constructor as it is only used when creating a new population
Population::Population() {

}

Population::Population(int popSize, int chromeLength) {
    initializePopulation(popSize, chromeLength);
}

Population::~Population() {
    population.clear();
}

void Population::initializePopulation(int popSize, int chromeLength) {

    Individual *ind;
    fitnessSum = 0;

    for(int i = 0; i < popSize; i++){
        ind = new Individual(chromeLength);
        fitnessSum += ind->getFitness();
        population.push_back(*ind);
    }

    ind = nullptr;

    sortPopDescFitness();
}

Individual Population::getIndividual(int index){
    return population.at(index);
}

//uses roullette wheel selection
Individual Population::selectParent() {

    int random = std::rand() % fitnessSum-1;
    int temp = 0;
    int i = 0;

    temp += population.at(i).getFitness();

    while(temp < random){
        i++;
        temp += population.at(i).getFitness();
    }

    return population.at(i);
}

// one child single point crossover
Individual Population::crossover(Individual p1, Individual p2) {

    int length = p1.getChromosomeLength();
    int random = std::rand() % length;
    int i = 0;
    std::vector<char> v;

    while(i < random){
        v.push_back((p1.getChromosomeString()).at(i));
        i++;
    }

    while(i < length){
        v.push_back((p2.getChromosomeString()).at(i));
        i++;
    }

    Individual child(length, v);

    return child;
}

void Population::sumFitness() {
    fitnessSum = 0;
    for(int i = 0; i < population.size(); i++){
        fitnessSum += population.at(i).getFitness();
    }
}

Individual Population::giveBirth(float crossoverRate, float mutationRate) {

    Individual parent1 = selectParent();

    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    Individual child;

    if(r <= crossoverRate){
        Individual parent2 = selectParent();
        child = crossover(parent1, parent2);
    }
    else{
        child = parent1;
    }

    r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    if(r < mutationRate){
        child.mutate();
        return child;
    }
    else{
        return child;
    }
}

void Population::addIndividual(Individual ind) {
    population.push_back(ind);
}

void Population::sortPopDescFitness() {
    std::sort(population.begin(), population.end(), std::greater<Individual>());
}

Population Population::generateNewPop(float crossoverRate, float mutationRate) {
    Population newPop;

    for(int i = 0; i < population.size();i++){
        Individual ind = this->giveBirth(crossoverRate, mutationRate);
        newPop.addIndividual(ind);
    }


    newPop.sumFitness();
    newPop.sortPopDescFitness();

    return newPop;
}

Individual Population::getFittest(){
    return population.at(0);
}