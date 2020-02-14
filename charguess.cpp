 /* Personal Project 1, Summer 2019
 * Contributor: Timothy White, II
 * Date: 06/ 11/ 2019 
 */ 
#include <iostream>

using namespace std;

#include "charguess.h"

        Charguess::Charguess(){
                wrongGuesses = 0;
                charToGuess = new string[13];
                workingArray = new string[13];
                for (int k = 0; k < NUMNETS; k++){
                        N.name = "";
                        for (int i = 0; i < NUMSHOWS; i++){
                                S.name = "";
                                for (int j = 0; j < NUMCHAR; i++){
                                        S.characters.push_back("");
                                }
                                N.shows.push_back(S);
                        }
                        networks.push_back(N);
                }
        }
        Charguess::~Charguess(){

        }
        void Charguess::fillNetworks(ifstream &charList){
                string line;
                charList.open("characterlist.txt");
                if (not charList.is_open()){
                        cout << "File can't be opened. ";
                        return;
                }
                while (!charlist.eof()){
                        getline(charList, line);
                        if (line == "Network"){
                                getline(charList, line);
                                networks.insert(i)
                        }
                }


        }
        void Charguess::chooseChar(){

        }
        void Charguess::printWorkArray(){

        }
        bool Charguess::checkCharacter(char guessee){
                (void) guessee;
                return true;
        }
