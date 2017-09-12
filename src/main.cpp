#include "Header.h"


//fills an array with rand
    void cross_over(){

    }


    int main() {

        const int POPULATION_SIZE = 100;
        const int CHROMOSOME_LENGTH = 50;
        const float CROSSOVER_RATE = 0.7;
        const float BITWISE_MUTATION_RATE = 0.01;

        const std::string GOAL_STRING = "11111111111111111111111111111111111111111111111111";

        srand(44);


        Population pop(POPULATION_SIZE, CHROMOSOME_LENGTH);

//        //this loop is for testing; it outputs the the entire population in descending fitness order
//        for(int i = 0; i < POPULATION_SIZE; i++){
//            std::cout << pop.getIndividual(i).getChromosomeString() << "\tFitness: " << pop.getIndividual(i).getFitness() << std::endl;
//        }
//
//        //this loop is for testing; it selects 100 parents using a type of roulette selection then prints the selected fitnesses in ascending order
//        std::vector<int> tempVect;
//        for(int i = 0; i < POPULATION_SIZE; i++){
//            tempVect.push_back(pop.selectParent().getFitness());
//        }
//        std::sort(tempVect.begin(), tempVect.end());
//        for(int i = 0; i < POPULATION_SIZE; i++){
//            std::cout << tempVect.at(i) << std::endl;
//        }

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
