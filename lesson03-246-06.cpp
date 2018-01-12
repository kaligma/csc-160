//File Name: lesson03-246-06.cpp
//Author: Christopher Abelein
//Email Address: crabelein@gmail.com
//Assignment: 3
//Description: Write a program with a function that returns credit card interest
//based on initial balance, monthly interest rate, and number of months for payment.
//function must compound interest. use a while loop similar to D2.14(dowhile) . repeatable.
//Last Modified: 02/02/17

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Initial declaration of function
double compound(double inbalf, double mninrtf, int monthsf);

int main () {
  double inbal, mninrt, intdue;
  int months, repeat;
  char recalc;
  string buffer;
  const string valrecalc = "yY";
  const string valstop = "nN";

  repeat = 1;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  
  
  cout << "\nHello. This program is designed to calculate compound interest\n"
            "due on a credit card. You will need to input the initial balance\n"
            "of your card in dollars, the monthly interest as a percent, and\n"
            "the number of months you will be making payments over.\n";
  
  while (repeat == 1) {
    //Accepts entry of doubles only
    cout << "\n\nFirst input your account balance in dollars: $";
    while (true) {
      std::stringstream buffercheck;
      inbal = 0;
      buffer = "";
      
      getline(cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> inbal) {
	break; }

      else {
	cout << "Invalid input. Please try again: $"; } }
    
    

    //Also only accepts doubles
    cout << "\nNow input the interest rate as a percent: %";
    while (true) {
      std::stringstream buffercheck;
      mninrt = 0;
      buffer = "";

      getline(cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> mninrt) {
	break; }

      else {
	cout << "invalid input. Please use an interger: %"; } }



    //int values only
    cout << "\nFinally, input the number of months you\n"
            "will be repaying the balance over: ";
    while (true) {
      std::stringstream buffercheck;
      months = 0;
      buffer = "";

      getline(cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> months) {
	break; }

      else {
	cout << "Invalid input. Please use an interger: "; } }
    
    

    //The function calculates the total repayment due without any math in
    //the main program
    cout << "\n\nCalculating compound interest due on a credit card with a balance\n"
                "of $" << inbal << " and a monthly interest of %" << mninrt << " over " << months << " months.\n";
    intdue = compound(inbal, mninrt, months);
    //Precondition: Have user input for initial credit card balance, monthly interest rate, and month duration
    //Postcondition: Total interest due on credit card returned.
    cout << "\nThe interest due on your credit card will be $" << intdue;



    //Repeat control accepts yY for repeat nN for quit
    cout << "\n\n\nWould you like to run another calculation? y/n: ";
    while (true) {
      recalc = 'x';
      buffer = "";

      getline(cin, buffer);

      if (buffer.length() > 0) {
	recalc = buffer[0]; }

      if (valrecalc.find(recalc) != string::npos) {
	cout << "\nRestarting....\n\n\n\n";
	break; }

      if (valstop.find(recalc) != string::npos) {
	cout << "\nGoodbye.\n";
	repeat = 0;
	break; }

      else {
	cout << "Invalid input, please try again.\n"
	  "Would you like to run another calculation? y/n: "; } } } }





//Compound interest function declared at the start, calculates
//running total of repayment amount
double compound(double inbalf, double mninrtf, int monthsf) {
  int repeatf;
  double runtotf;

  repeatf = 0;
  runtotf = inbalf;
  
  //Iterates calculation at least once up to the number of months
  //entered by the user in the main function
  do {
    runtotf = runtotf + runtotf * (mninrtf / 100);
    repeatf++;
  } while (repeatf < monthsf);
  runtotf = runtotf - inbalf;
  return runtotf; }
