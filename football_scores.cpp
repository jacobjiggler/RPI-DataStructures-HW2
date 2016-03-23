//  File: football_scores.cpp
// Purpose: parse football games by their scores and output them in an organized format.



#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include "scores.h"
#include "teams.h"

using namespace std;

// pre defining items
bool commandError(int values, char* a, char* b);
void parceFile(char* input);
void outputFile(char* output);
bool HigherPointDifferential(const score& t1, const score& t2);
bool HigherWinLoss(const Team& t1, const Team& t2);
bool largerTotalPointGame(const score& t1, const score& t2);
vector <score> scores;
vector <Team> teams;

int main(int argc, char* argv[]){
//checking for incorrect comand line input
if (commandError(argc, argv[1], argv[2])){
return 1;
}
//Recording input
char* input = argv[1];
char* output = argv[2];


parceFile(input);

outputFile(output);
return 0;
}

void parceFile(char* input){
//initiating values for grabbing
string stringgarbage;
int intgarbage;
string home;
string visitor;
int t1q1;
int t1q2;
int t1q3;
int t1q4;
int t1q5;
int t1total;
int t2q1;
int t2q2;
int t2q3;
int t2q4;
int t2q5;
int t2total;
//initiating input
ifstream in_str(input);

//recording read files to the scores and teams vector
// If we don't find the useless dates, we've reached the end of the file & silently return false.
while((in_str >> stringgarbage)){
if (!(in_str >> stringgarbage)) cerr << "Failed reading of garbage";
if (!(in_str >> intgarbage)) cerr << "Failed reading of garbage";
if (!(in_str >> intgarbage)) cerr << "Failed reading of garbage";
if (!(in_str >> visitor)) {
cerr << "Failed reading name for visitor " << visitor << endl;
exit(1);
}
if (!(in_str >> t1q1 >> t1q2 >> t1q3 >> t1q4 >> t1q5 >> t1total)) {
cerr << "Failed reading name for visitor scores" << endl;
exit(1);
}
if (!(in_str >> home)) {
cerr << "Failed reading name for home " << home << endl;
exit(1);
}
if (!(in_str >> t2q1 >> t2q2 >> t2q3 >> t2q4 >> t2q5 >> t2total)) {
cerr << "Failed reading name for home scores" << endl;
exit(1);
}
//error checking

//checking if team is already declared
int temp1 = teams.size();
for (int i = 0; i < teams.size(); i++){
if (visitor == teams[i].getName()){
temp1 = i;
break;
}
}
if (temp1 == teams.size()){
teams.push_back(Team(visitor));
}


int temp2 = teams.size();
for (int i = 0; i < teams.size(); i++){
if (home == teams[i].getName()){
temp2 = i;
break;
}
}
if (temp2 == teams.size()){
teams.push_back(Team(home));
}
//recording in a class in a vector
scores.push_back(score(teams[temp2],teams[temp1],t1q1,t1q2,t1q3,t1q4,t1q5,t1total,t2q1,t2q2,t2q3,t2q4,t2q5,t2total));
//Incrementing wins / losses for teams vector
if (t1total > t2total){
teams[temp1].setWins(teams[temp1].getWins() + 1);
teams[temp2].setLosses(teams[temp2].getLosses() + 1);
}
else{
if (t1total < t2total){
teams[temp2].setWins(teams[temp2].getWins() + 1);
teams[temp1].setLosses(teams[temp1].getLosses() + 1);
}
}
}
}



void outputFile(char* output){
//output of values into text files sorted
//finding max team name length for arrangement
int maxlength = 0;
for (int g = 0; g < teams.size(); g++){
if (maxlength < teams[g].getName().length())
maxlength = teams[g].getName().length();
}
//initial sorting
sort(scores.begin(), scores.end(), HigherPointDifferential);
sort(teams.begin(), teams.end(), HigherWinLoss);
//beginning output
ofstream out_str(output);
if (!out_str) {
    cerr << "Can't open " << output << " to write." << endl;
    exit(1);
	}
	
out_str << "ALL GAMES, SORTED BY POINT DIFFERENTIAL:" << endl;


//white space organization
for (int i = 0; i < scores.size(); i++){
int a = 2;
int j = 0;
string firstWhitespace(maxlength + 2 - scores[i].getVisitor().getName().length(), ' ');
string secondWhitespace(2, ' ');
if (scores[i].gett1Total() < 10){
a = 3;
}
if (scores[i].gett2Total() < 10){
j = 1;
}
string thirdWhitespace(maxlength + a - scores[i].getHome().getName().length(), ' ');
string fourthWhitespace(j, ' ');
//actual recording
out_str << scores[i].getVisitor().getName() << firstWhitespace << scores[i].getStringWinner() << secondWhitespace << scores[i].getHome().getName() << thirdWhitespace << scores[i].gett1Total() << " - " << fourthWhitespace << scores[i].gett2Total() << endl;

}
out_str << endl;
//done
//new output
out_str << "ALL TEAMS, SORTED BY WIN PERCENTAGE:" << endl;
for (int i = 0; i < teams.size(); i++){
int a = 3;
int b = 2;
if (teams[i].getWins() > 9){
a = 2;
}
//white space organization
string firstWhitespace(maxlength + a - teams[i].getName().length(), ' ');
if (teams[i].getLosses() > 10){
b = 1;
}
string secondWhitespace(b, ' ');
string thirdWhitespace(2, ' ');
out_str << teams[i].getName() << firstWhitespace << teams[i].getWins() << " win(s) -" << secondWhitespace << teams[i].getLosses() << " loss(es)" << thirdWhitespace; 
out_str << fixed << setprecision(2) << teams[i].getWinsLosses() << fixed << setprecision(2) << endl;

}
out_str << endl;
sort(scores.begin(), scores.end(), largerTotalPointGame);
out_str << "ALL GAMES, SORTED BY Total Points" << endl;



for (int i = 0; i < scores.size(); i++){
int a = 2;
int j = 0;
string firstWhitespace(maxlength + 2 - scores[i].getVisitor().getName().length(), ' ');
string secondWhitespace(2, ' ');

if (scores[i].gett2Total() < 10){
j = 1;
}
string thirdWhitespace(maxlength + a - scores[i].getHome().getName().length(), ' ');

out_str << scores[i].getVisitor().getName() << firstWhitespace << "and" << secondWhitespace << scores[i].getHome().getName() << thirdWhitespace << scores[i].gett1Total() + scores[i].gett2Total() << endl;

}


}


//checks to see if the command lines input passed in is acceptable
bool commandError(int values, char* a, char* b){
if (values != 3){
cerr << "command line error" << " Usage:   ./a.out input output ";
return true;
}

ifstream in_str(a);
if (!in_str) {
cerr << "Could not open " << a << " to read\n";
exit(1);
return true;
}
ofstream out_str(b);
if (!out_str) {
cerr << "Could not open " << b << " to write\n";
exit(1);
return true;
}
return false;

}
//sorts by point difference
bool HigherPointDifferential(const score& t1, const score& t2){
int ta;
int tb;
if (t1.gett1Total() > t1.gett2Total()){
ta = t1.gett1Total();
}
else {
ta = t1.gett2Total();
}
if (t2.gett1Total() > t2.gett2Total()){
tb = t2.gett1Total();
}
else {
tb = t2.gett2Total();
}
//sort games by the absolute difference in scores
if(fabs(t1.gett1Total() - t1.gett2Total()) < fabs(t2.gett1Total() - t2.gett2Total())){
return true;
}
else{
if(fabs(t1.gett1Total() - t1.gett2Total()) > fabs(t2.gett1Total() - t2.gett2Total())){
return false;
}
else{
//total points

if(ta > tb) {
return true;
}
else {
if(tb > ta) {
return false;
}
else {

if(t1.gett1Total() > t2.gett1Total()){
return true;
}
else{
if(t1.gett1Total() < t2.gett1Total()){
return false;
}
else {
if(t1.gett2Total() > t2.gett2Total()) {
return true;
}
else {
if(t1.gett2Total() < t2.gett2Total()) {
return false;
}

else{
//alphabetically visitor name
if(t1.getVisitor().getName() > t2.getVisitor().getName()){
return true;
}
else{
if(t1.getVisitor().getName() < t2.getVisitor().getName()){
return false;
}

else{

//alphabetically home name
if(t1.getHome().getName() > t2.getHome().getName()){
return true;
}
else{
if(t1.getHome().getName() < t2.getHome().getName()){
return false;
}

else{
cerr << "This isn't possible in sports";
exit(1);
}
}
}
}
}
}
}
}
}
}
}
}
}

bool HigherWinLoss(const Team& t1, const Team& t2){
//sort teams by games won divided by losses
//ties higher number of games then alphabetical
if(t1.getWinsLosses() > t2.getWinsLosses()){
return true;
}
else {
if(t1.getWinsLosses() < t2.getWinsLosses()){
return false;
}
else {
if(t1.getWins() + t1.getLosses() > t2.getWins() + t2.getLosses()){
return true;
}
else {
if(t1.getWins() + t1.getLosses() < t2.getWins() + t2.getLosses()){
return false;
}
else {
//alphabetical name
if(t1.getName() < t2.getName()){
return true;
}
else{
if(t1.getName() > t2.getName()){
return false;
}

else{

cerr << "this shouldn't be possible unless you are doing something very wrong" << endl;
exit(1);
}
}
}
}
}
}
}

bool largerTotalPointGame(const score& t1, const score& t2){
//sorts by total points then highest scoring teams points and then alphabetical
int ta;
int tb;
if (t1.gett1Total() > t1.gett2Total()){
ta = t1.gett1Total();
}
else {
ta = t1.gett2Total();
}
if (t2.gett1Total() > t2.gett2Total()){
tb = t2.gett1Total();
}
else {
tb = t2.gett2Total();
}

//combined point comparison
int team1total = t1.gett1Total() + t1.gett2Total();
int team2total = t2.gett1Total() + t2.gett2Total();
if (team1total > team2total){
return true;
}
else {
if (team2total > team1total){
return false;
}
//individual team point comparison
else{
if(ta > tb) {
return true;
}
else {
if(tb > ta) {
return false;
}
else {

if(t1.gett1Total() > t2.gett1Total()){
return true;
}
else{
if(t1.gett1Total() < t2.gett1Total()){
return false;
}
else {
if(t1.gett2Total() > t2.gett2Total()) {
return true;
}
else {
if(t1.gett2Total() < t2.gett2Total()) {
return false;
}

else{
//alphabetically visitor name
if(t1.getVisitor().getName() > t2.getVisitor().getName()){
return true;
}
else{
if(t1.getVisitor().getName() < t2.getVisitor().getName()){
return false;
}

else{

//alphabetically home name
if(t1.getHome().getName() > t2.getHome().getName()){
return true;
}
else{
if(t1.getHome().getName() < t2.getHome().getName()){
return false;
}

else{
cerr << "This isn't possible in sports";
exit(1);
}
}
}
}
}
}
}
}
}
}
}
}
}



