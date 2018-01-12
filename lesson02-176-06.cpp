//File Name: lesson02-176-06.cpp
//Author: Christopher Abelein
//Email Address: crabelein@gmail.com
//Assignment: 2
//Description: Use the Fibonacci algorithm to model growth of green crud
//Last Modified: Januaruy 25, 2017

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {
  /*
    The totpop variable represents the total amount of green crud. The days
    variable is the input variable for the amount of time the user wishes
    to calculate with. rcyc is the number of reproduction cycles the days
    input allows for. ccyc is used to loop the calculation for the correct
    number of cycles. newpop is all the new green crud created in a
    particular cycle. grwpop is the population that is still maturing
    and cannot reproduce. reppop is the population that has reached
    maturity and can reproduce. rerun is the control variable to loop the
    entire program.

    The ans variable is used by the user indirectly to stop the program.
    ansbuffer accepts input directly from the user and filters it. For
    The numeric entries, it ensures that the user inputs a usable interger.
    For the choice to rerun the program, it makes sure only one character
    is allowed to be used as input.
    
    The constant valrerun is used to check to see is the user has entered
    a valid response to rerun the program. The valstop constant is used
    to check if the user has entered a valid response to end the program.

    The stringstream buffercheck is used to check if user input is a valid
    interger for totpop and days. It accepts this first interger it finds if
    the input start with an number, and rejects the input if the first 
    character is not a number.
  */
  int totpop, days, rcyc, ccyc, newpop, grwpop, reppop, rerun;
  string ans, buffer;
  const string valrerun = "yY";
  const string valstop = "nN";
  
  rerun = 1;
  
  cout << "Hello. This program is designed to calculate the population growth\n";
  cout << "of green crud via the Fibonacci algorithm. To do this,\n";
  cout << "you will need the initial population of green crud in pounds and\n";
  cout << "the amount of time the green crud has to reproduce in days.\n\n\n";



  //Loop to allow program to be rerun
  while (rerun == 1) {
    cout << "Please keep in mind that the reproduction time period of\n";
    cout << "green crud is 5 days, and that this algorithm treats\n";
    cout << "the population growth as 0 until the 5th day.\n\n\n";
    
    cout << "Please input the initial population in pounds.\n";
    cout << "Non-Interger input will either be thrown out or\n";
    cout << "considered invalid.\n";
    cout << "lbs: ";

    //Checks input to ensure valid interger for totpop
    while (true) {
      std::stringstream buffercheck;
      totpop = 0;
      buffer = "";
      
      getline (cin, buffer);
      buffercheck << buffer;
      
      if (buffercheck >> totpop) {
	break; }

      else {
	cout << "\nInvalid response. Please try again.\n";
	cout << "lbs: "; } }
    
    cout << "\nNow the reproduction time period in days.\n";
    cout << "Non-Interger input will either be thrown out or\n";
    cout << "considered invalid.\n";
    cout << "days: ";
    
    //Same check for days.
    while (true) {
      std::stringstream buffercheck;
      days = 0;
      buffer = "";
     
      getline (cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> days) {
	break; }

      else {
	cout << "\nInvalid response. Please try again.\n";
	cout << "days: "; } }
	
	

    //Setting inital values for calculation.
    newpop = totpop;
    grwpop = 0;
    reppop = 0;
    rcyc = days / 5;
    ccyc = 1;
    
    cout << "\nPopulation day 0: " << totpop;

    /*
      Looping calculation that moves the population
      through three variables, keeping seperate the
      new population that cannot reproduce, the
      growing population that also cannot reproduce,
      and the reproducing population. Loops until
      the number of cycles calculated from the player's
      day input is met.
    */
    while (ccyc <= rcyc) {
      reppop = reppop + grwpop;
      grwpop = newpop;
      newpop = reppop;
      totpop = reppop + grwpop + newpop;
      
      cout << "\nPopulation day " << (ccyc * 5) << ": " << totpop;
      
      ccyc++; }
    
    
    
    
    cout << "\n\nThe final population of green crud according to the values\n";
    cout << "you entered is " << totpop << " pounds.\n";
    
    
    
    
    cout << "\nWould you like to rerun this calculation? y/n: ";
    ans = 'q';

    //Allows the player to choose to rerun the program or quit,
    //without any answer fallthrough.
    while (valrerun.find(ans) == string::npos) {
      buffer = "";
      getline (cin, buffer);
      
      if (buffer.length() > 0) {
	ans = buffer[0]; }
      
      if (valrerun.find(ans) != string::npos) {
	cout << "\nOkay, restarting...\n\n\n\n";
	break; }
      
      if (valstop.find(ans) != string::npos) {
	cout << "\nGoodbye.\n";
	rerun = 0;
	break; }
      
      else {
	cout << "\nInvalid responce. Please try again.\n";
	cout << "Would you like to rerun this calculation? y/n: "; } } }
  
  
  
  return 0; }
