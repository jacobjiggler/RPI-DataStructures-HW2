//  File: teams.cpp
// Purpose: Implementation of the class teams.h
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "teams.h"

using namespace std;
//team class definition without paramaters
Team::Team(){
Name = "null";
Wins = -1;
Losses = -1;
}
//team class definition with variables
Team::Team(string name){
Name = name;
Wins = 0;
Losses = 0;
}
//team function definitions
string Team::getName() const{
return Name;
}

int Team::getWins() const{
return Wins;
}
int Team::getLosses() const{
return Losses;
}
double Team::getWinsLosses() const{
return WinsLosses;
}

void Team::setName(string name){
Name = name;
}
void Team::setWins(int wins){
Wins = wins;
setWinsLosses();
}
void Team::setLosses(int losses){
Losses = losses;
setWinsLosses();
}
void Team::setWinsLosses(){
WinsLosses = (1.0 * Wins / (1.0 * Wins + 1.0 * Losses));
}