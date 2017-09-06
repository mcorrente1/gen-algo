#include <iostream>
#include <string>

using namespace std;

//print array sequence
void print_ar(char ar[], int size){
    for(int i = 0; i < size; i++){
        cout << ar[i];
    }
}

//generates a random sequence of 1's and 0's of size n
void initialize_parent(char ar[], int size) {
    for (int i = 0; i < size; i++) {
        if (rand() % 2) {
            ar[i] = '1';
        }
        else {
            ar[i] = '0';
        }
    }
}

//in this case the fitness function returns the number of 1's in a given string
    int fitness(char ar[], int size){
        int count = 0;
        for(int i = 0; i < size; i++){
            if(ar[i] == '1'){
                count++;
            }
        }
        return count;
    }

//selects parents for reproduction
    void select_parents(){

    }

//fills an array with rand
    void cross_over(){

    }


    int main() {

        const float POPULATION_SIZE = 100;
        const float CROSSOVER_RATE = 0.7;
        const float BITWISE_MUTATION_RATE = 0.001;
        const int CHROMOSOME_LENGTH = 20;
        const string GOAL_STRING = "11111111111111111111";

        char parent1[CHROMOSOME_LENGTH];
        char parent2[CHROMOSOME_LENGTH];

        initialize_parent(parent1, CHROMOSOME_LENGTH);
        initialize_parent(parent2, CHROMOSOME_LENGTH);

        print_ar(parent1, CHROMOSOME_LENGTH);
        cout << "\tFitness: " << fitness(parent1, CHROMOSOME_LENGTH) << endl;
        print_ar(parent2, CHROMOSOME_LENGTH);
        cout << "\tFitness: " << fitness(parent2, CHROMOSOME_LENGTH) << endl;

        return 0;
    }
