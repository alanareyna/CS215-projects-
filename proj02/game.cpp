// Alana Reyna: proj02                                                                                                                                                                                      
#include <vector>
#include <fstream>
#include <iostream>
#include "game.hpp"
using namespace std;

//default constructor: initialize private variables                                                                                                                                                         
Game::Game(){
  player1 = player2 = NULL;
  nextTurn.clear();
  p1total = 0;
  p2total = 0;
}


Game::Game(string p1_strategy, string p2_strategy) {
  player1 = new Player(p1_strategy);
  player2 = new Player(p2_strategy);
}

// copy constructor                                                                                                                                                                                         
Game::Game(const Game& p) {
  player1 = new Player(p.player1->GetStrategy());
  player2 = new Player(p.player2->GetStrategy());
}

Game::~Game() {
  delete player1;
  delete player2;
}

Game& Game::operator=(const Game& p) {
  if (this == &p) return *this;
  delete player1;
  delete player2;
  player1 = new Player(*p.player1);
  player2 = new Player(*p.player2);
  return *this;
}

void Game::PlayTurn() {
  Turn newTurn;

  // Decision p1_past = SILENT;                                                                                                                                                                             
  // Decision p2_past = SILENT                                                                                                                                                                              

  Decision p1_decision = SILENT;
  Decision p2_decision = SILENT;

  if (nextTurn.size() != 0 ) {
    // reach in and set p1_past && p2_past correctly                                                                                                                                                        
    p1_decision = player1->MakeNextDecision(nextTurn.back().p1_decision, nextTurn.back().p2_decision, "player1");
    p2_decision = player2->MakeNextDecision(nextTurn.back().p1_decision, nextTurn.back().p2_decision, "player2");
  }


  newTurn.p1_decision = p1_decision;
  newTurn.p2_decision = p2_decision;
  
  if (p1_decision == SNITCH && p2_decision == SNITCH) {
    newTurn.p1sentence = 5;
    p1total = p1total + 5;
    newTurn.p2sentence = 5;
    p2total = p2total + 5;
  }
  else if (p1_decision == SILENT && p2_decision == SILENT) {
    newTurn.p1sentence = 0.5;
    p1total = p1total + 0.5;
    newTurn.p2sentence = 0.5;
    p2total = p2total + 0.5;
  }
  else if (p1_decision == SILENT && p2_decision == SNITCH) {
    newTurn.p1sentence = 10;
    p1total = p1total + 10;
    newTurn.p2sentence = 0;
  }
  else if (p1_decision == SNITCH && p2_decision == SILENT) {
    newTurn.p1sentence = 0;
    newTurn.p2sentence = 10;
    p2total = p2total + 10;
  }

  // Logic for sentencing                                                                                                                                                                                   
  // nextTurn.p1sentence = 5;                                                                                                                                                                               


  // {0 & 10, 0 & 10, .5 & .5}                                                                                                                                                                              

  nextTurn.push_back(newTurn);
  
}

// nextTurn.player1                                                                                                                                                                                         

void Game::TurnReport(ostream& outs, int round_num) const {
  outs <<"*************** " << "TURN " << round_num << " ******************" << endl;
  outs << "Player 1: " << nextTurn.back().p1_decision << endl;
  outs << "Player 2: " << nextTurn.back().p2_decision << endl;
  outs << endl;
  outs << "Player 1 sentence: " << nextTurn.back().p1sentence << endl;
  outs << "Player 2 sentence: " << nextTurn.back().p2sentence << endl;
}

void Game::Reset() {
  player1 = player2 = NULL;
  nextTurn.clear();
  /*  p1sentence = 0;                                                                                                                                                                                       
      p2sentence = 0;*/
}
void Game::Reset(string p1_strategy, string p2_strategy) {
  player1 = new Player(p1_strategy);
  player2 = new Player(p2_strategy);
  cout <<"*****************************************"<< endl;
  cout <<"GAME REPORT"<< endl;
  cout <<"Player 1 strategy: " << p1_strategy << endl;
  cout << "Player 2 strategy:  " << p2_strategy << endl;

  // Turn turn;                                                                                                                                                                                             
  // Some if statements that would assign Decision to each player                                                                                                                                           
}


ostream& operator << (ostream& outs, const Game& g) {
    outs <<"*****************************************"<< endl;
    outs <<"Player 1's total sentence: " << g.p1total << endl;
    outs <<"Player 2's total sentence: " << g.p2total << endl;
}
