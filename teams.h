//  File: teams.h
// Purpose: Header for declaration of teams class and associated functions.
#ifndef __teams_h_
#define __teams_h_

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Team{

private:

string Name;


public:
Team();
Team(string name);
int Losses;
int Wins;
double WinsLosses;
string getName() const;
int getWins() const;
int getLosses() const;
double getWinsLosses() const;

void setName(string name);
void setWins(int wins);
void setLosses(int losses);
void setWinsLosses();



};
#endif