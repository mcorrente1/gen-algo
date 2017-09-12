//
// Created by Matt Corrente on 9/12/17.
//

#ifndef GEN_ALGO_INDIVIDUAL_H
#define GEN_ALGO_INDIVIDUAL_H

#include <vector>
#include <string>

class Individual {

private:
    int chromosomeLength;
    int fitness;
    std::vector<char> chromosome;
    void initializeChromosome();
    void setFitness();

public:
    Individual();
    Individual(int cLength);
    Individual(int cLength, std::vector<char> chromeString);
    int getChromosomeLength();
    int getFitness() const;
    std::string getChromosomeString();
    bool operator <(const Individual& d) const;
    bool operator >(const Individual& d) const;
    void mutate();
    ~Individual();
};


#endif //GEN_ALGO_INDIVIDUAL_H
