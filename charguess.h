 /* Personal Project 1, Summer 2019
 * Contributor: Timothy White, II
 * Date: 06/ 11/ 2019 
 */ 

#ifndef _CHARGUESS_H_
#define _CHARGUESS_H_

#include <vector>
#include <fstream>

using namespace std;

struct Node {
        char letter;
        Node *next;
};

struct Show{
        string name;
        vector<string>characters;
};
struct Network{
        string name;
        vector<Show>shows;
};

class Charguess{
public:
        Charguess();
        ~Charguess();
        void fillNetworks(ifstream &charList);
        void chooseChar();
        void printWorkArray();
        bool checkCharacter(char guessee);


private:
        const int NUMNETS = 6;
        const int NUMCHAR = 4;
        const int NUMSHOWS = 13;
        string *charToGuess;
        string *workingArray;
        Network N;
        Show S;
        vector<Network>networks;
        int wrongGuesses;
        
};

#endif
