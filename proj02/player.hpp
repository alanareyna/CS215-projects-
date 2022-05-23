#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "constants.hpp"
using namespace std;
// Definition of player class                                                                                                                                                                               
// You may add any other private member variables or functions you need                                                                                                                                     
class Player {

public:

        // --- You MUST implement the following functions ---                                                                                                                                               
        Player();
        Player(string desired_strategy); // initialize strategy                                                                                                                                             
        Player(const Player& p);
        ~Player();
        Player& operator = (const Player& p);
  string GetStrategy() const;  // accessor function for strategy                                                                                                                                            

        // A player's decision for a given round MUST be made by the Player,                                                                                                                                
        // not the Game                                                                                                                                                                                     
        // The Game should call this function to get the Player's decision                                                                                                                                  
        // You can pass it whatever arguments it needs                                                                                                                                                      
  Decision MakeNextDecision(Decision, Decision, string);

private:
        string strategy;// should be one of the possible_strategies from constants.hpp                                                                                                                      
};

#endif
