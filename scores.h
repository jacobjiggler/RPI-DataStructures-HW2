//  File: scores.h
// Purpose: Header for declaration of scores class and associated functions.
#ifndef __scores_h_
#define __scores_h_

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include "teams.h"

class score{

private:
Team Home;
Team Visitor;
int t1Q1;
int t1Q2;
int t1Q3;
int t1Q4;
int t1Q5;
int t2Q1;
int t2Q2;
int t2Q3;
int t2Q4;
int t2Q5;
int t1Total;
int t2Total;
Team Winner;
string stringWinner;

public:
score();
score(Team home, Team visitor, int t1q1, int t1q2, int t1q3, int t1q4, int t1Q5, int t1total, int t2q1, int t2q2, int t2q3, int t2q4, int t2Q5, int t2total);

Team getHome() const;
Team getVisitor() const;
int gett1Q1() const;
int gett1Q2() const;
int gett1Q3() const;
int gett1Q4() const;
int gett1Q5() const;
int gett2Q1() const;
int gett2Q2() const;
int gett2Q3() const;
int gett2Q4() const;
int gett2Q5() const;
int gett1Total() const;
int gett2Total() const;
Team getWinner() const;
string getStringWinner() const;
void setHome(Team a);
void setVisitor(Team b);
void sett1Q1(int c);
void sett1Q2(int c);
void sett1Q3(int c);
void sett1Q4(int c);
void sett1Q5(int c);
void sett2Q1(int c);
void sett2Q2(int c);
void sett2Q3(int c);
void sett2Q4(int c);
void sett2Q5(int c);
void sett1Total(int total);
void sett2Total(int total);
void setWinner(Team winner);

};
#endif