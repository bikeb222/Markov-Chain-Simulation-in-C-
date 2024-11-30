#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MarkovChain {
public:
    MarkovChain(double transitionMatrix[][3], int numStates)
        : numStates(numStates) {
        for (int i = 0; i < numStates; ++i) {
            for (int j = 0; j < numStates; ++j) {
                this->transitionMatrix[i][j] = transitionMatrix[i][j];
            }
        }
        srand(time(0));
    }
    void randomWalk(int startState, int steps) {
        int currentState = startState;
        double pathProbability = 1.0;
       cout << "Starting state: " << currentState << endl;
        for (int i = 0; i < steps; ++i) {
            int nextState = getNextState(currentState);
            double transitionProb = transitionMatrix[currentState][nextState];
            pathProbability *= transitionProb;  
            cout << "Step " << i + 1 << ": " << nextState
                << "   |   P(x)=" << transitionProb << endl;
            currentState = nextState;
        }
        cout << "Total path probability: " << pathProbability << endl;
    }

private:
    double transitionMatrix[3][3];
    int numStates;
    int getNextState(int currentState) {
        double randProb = static_cast<double>(rand()) / RAND_MAX;
        double cumulativeProb = 0.0;
        for (int nextState = 0; nextState < numStates; ++nextState) {
            cumulativeProb += transitionMatrix[currentState][nextState];
            if (randProb < cumulativeProb) {
                return nextState;
            }
        }
        return numStates - 1; 
    }
};

int main() {
    double transitionMatrix[3][3] = {
        {0.2, 0.6, 0.2},
        {0.3, 0.0, 0.7},
        {0.5, 0.0, 0.5}
    };
    MarkovChain mc(transitionMatrix, 3);
    int startState = 2;
    int steps = 8;
    mc.randomWalk(startState, steps);
    return 0;
}
