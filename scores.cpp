//  File: scores.cpp
// Purpose: Implementation of the class scores.h
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include "scores.h"
#include "teams.h"

using namespace std;
//score class  definition without variable
score::score(){
Home = Team();
Visitor = Team();
t1Q1 = -1;
t1Q2 = -1;
t1Q3 = -1;
t1Q4 = -1;
t1Q5 = -1;
t1Total = -1;
t2Q1 = -1;
t2Q2 = -1;
t2Q3 = -1;
t2Q4 = -1;
t2Q5 = -1;
t2Total = -1;
Winner = Team();
stringWinner = "";
}
//score class definition with variable
score::score(Team home, Team visitor, int t1q1, int t1q2, int t1q3, int t1q4, int t1q5, int t1total, int t2q1, int t2q2, int t2q3, int t2q4, int t2q5, int t2total){
//declaring variables
Home = home;
Visitor = visitor;
t1Q1 = t1q1;
t1Q2 = t1q2;
t1Q3 = t1q3;
t1Q4 = t1q4;
t1Q5 = t1q5;
t1Total = t1total;
t2Q1 = t2q1;
t2Q2 = t2q2;
t2Q3 = t2q3;
t2Q4 = t2q4;
t2Q5 = t2q5;
//declaring winner and point totals
t2Total = t2total;
if (t1Total > t2total){
Winner = Visitor;
stringWinner = "defeated";

}
else{
if (t1Total < t2Total){
Winner = Home;
stringWinner = "lost to ";

}
else {
Winner = Team();
stringWinner = "Tied";
}
}

}
// defining functions
Team score::getHome() const{
return Home;
}
Team score::getVisitor() const{
return Visitor;
}
int score::gett1Q1() const{
return t1Q1;
}
int score::gett1Q2() const{
return t1Q2;
}
int score::gett1Q3() const{
return t1Q3;
}
int score::gett1Q4() const{
return t1Q4;
}
int score::gett1Q5() const{
return t1Q5;
}
int score::gett2Q1() const{
return t2Q1;
}
int score::gett2Q2() const{
return t2Q2;
}
int score::gett2Q3() const{
return t2Q3;
}
int score::gett2Q4() const{
return t2Q4;
}
int score::gett2Q5() const{
return t2Q5;
}
int score::gett1Total() const{
return t1Total;
}
int score::gett2Total() const{
return t2Total;
}
Team score::getWinner() const{
return Winner;
}
string score::getStringWinner() const{
return stringWinner;
}
void score::setHome(Team a){
Home = a;
}
void score::setVisitor(Team b){
Visitor = b;
}
void score::sett1Q1(int c){
t1Q1 = c;
}
void score::sett1Q2(int c){
t1Q2 = c;
}
void score::sett1Q3(int c){
t1Q3 = c;
}
void score::sett1Q4(int c){
t1Q4 = c;
}
void score::sett1Q5(int c){
t1Q5 = c;
}
void score::sett2Q1(int c){
t2Q1 = c;
}
void score::sett2Q2(int c){
t2Q2 = c;
}
void score::sett2Q3(int c){
t2Q3 = c;
}
void score::sett2Q4(int c){
t2Q4 = c;
}
void score::sett2Q5(int c){
t2Q5 = c;
}
void score::sett1Total(int total){
t1Total = total;
}
void score::sett2Total(int total){
t2Total = total;
}
void score::setWinner(Team winner){
Winner = winner;
}