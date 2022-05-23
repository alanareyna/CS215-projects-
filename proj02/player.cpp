// Alana Reyna: proj02 player.cpp                                                                                                                                                                           
#include <vector>
#include <fstream>
#include <iostream>
#include "player.hpp"
using namespace std;

// default constructor                                                                                                                                                                                      
Player::Player(){
  strategy = "";
}

// initialize player class strategy to the desired strategy                                                                                                                                                 
Player::Player(string desired_strategy) {
  strategy = desired_strategy;
}

// copy constructor                                                                                                                                                                                         
Player::Player(const Player& p) {
  strategy = p.strategy;

}

// destructor                                                                                                                                                                                               
Player::~Player() {}

// assignment operator                                                                                                                                                                                      
Player& Player::operator=(const Player& p) {
  if (this == &p) return *this;
  strategy = p.strategy;
  return *this;
}

// returns strategy                                                                                                                                                                                         
string Player::GetStrategy() const {
  return strategy;
}

// uses both player's previous decisions. String which is used to determine what player we are using.                                                                                                       
Decision Player::MakeNextDecision(Decision p1_decision, Decision p2_decision, string which) {
  // if statements to figure out what strategy the user is using to determine what decision the player will make next                                                                                       
  if (which == "player1") {
    if (strategy == "ALWAYS_SNITCH") {
      p1_decision = SILENT;
    }
    if (strategy == "ALWAYS_SILENT") {
      p1_decision = SNITCH;
    }
    if (strategy == "TIT_FOR_TAT") {
      p1_decision = p2_decision;
    }
    if (strategy == "SPECIAL") {
      p1_decision = SNITCH;
    }
  }
  // same as above for player 2                                                                                                                                                                             
  else if (which == "player2") {
    if (strategy == "ALWAYS_SNITCH") {
      p2_decision = SNITCH;
    }
    if (strategy == "ALWAYS_SILENT") {
      p2_decision = SILENT;
    }
    if (strategy == "TIT_FOR_TAT") {
      p2_decision = p1_decision;
    }
    if (strategy == "SPECIAL") {
      p2_decision = SNITCH;
    }
  }
}
