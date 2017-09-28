#include "Header.h"

    int main() {

        const int POPULATION_SIZE = 100;
        const float CROSSOVER_RATE = 0.7;
        const float BITWISE_MUTATION_RATE = 0.01;
        
        const std::string GOAL_STRING = "11111111111111111111111111111111111111111111111111";
        const int CHROMOSOME_LENGTH = GOAL_STRING.size();

        srand(44);

        Population pop(POPULATION_SIZE, CHROMOSOME_LENGTH);

        std::cout << "Most fit chromosome: " << pop.getFittest().getChromosomeString() << " Fitness:" << pop.getFittest().getFitness() << std::endl;

        Population newPop = pop.generateNewPop(CROSSOVER_RATE, BITWISE_MUTATION_RATE);
        int generation = 2;

        while(newPop.getFittest().getChromosomeString() != GOAL_STRING) {

            std::cout << "\nGeneration: " << generation;
            std::cout << "\tMost fit chromosome: " << newPop.getFittest().getChromosomeString() << " Fitness:" <<
            newPop.getFittest().getFitness() << std::endl;
            generation++;

            newPop = newPop.generateNewPop(CROSSOVER_RATE, BITWISE_MUTATION_RATE);
        }

        std::cout << "\nSolution found at generation: " << generation;
        std::cout << "\tMost fit chromosome: " << newPop.getFittest().getChromosomeString() << " Fitness:" <<
        newPop.getFittest().getFitness() << std::endl;

        return 0;
    }
