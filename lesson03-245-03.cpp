//File Name: lesson03-245-03.cpp
//Author: Christopher Abelein
//Email Address: crabelein@gmail.com
//Assignment: 3
//Description: Program must calculate user's stock using number of stocks, whole dollar portion, and fraction portion.
//Last Modified: 02/02/17

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Declaration of function
double calc(int dolprcf, int numerf, int denomf);

int main() {
  double indvalue, totvalue;
  int stkcnt, dolprc, numer, denom, repeat;
  char recalc;
  string buffer;
  const string valrecalc = "yY";
  const string valstop = "nN";

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  repeat = 1;

  cout << "\nHello. This program is designed to tell you the value of your stock.\n"
            "You will need to input the number of stocks you own, the whole dollar\n"
            "price of your stocks, and the fractional value of your stocks with\n"
            "seperate entries for the numerator and denominator of the fraction.\n";

  
  
  while (repeat == 1) {
    //Accepts only int values
    cout << "\n\nPlease enter the number of stocks you own: ";
    while (true) {
      std::stringstream buffercheck;
      stkcnt = 0;
      buffer = "";

      getline (cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> stkcnt) {
	break; }

      else {
	cout << "Invalid input, please use an interger: "; } }



    //Int values
    cout << "\nPlease enter the whole dollar price of your stocks: $";
    while (true) {
      std::stringstream buffercheck;
      dolprc = 0;
      buffer = "";

      getline (cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> dolprc) {
	break; }

      else {
	cout << "Invalid input, please use an interger: $"; } }
    


    //Also int
    cout << "\nPlease enter the numerator of the fractional price\n"
                "of your stocks: ";
    while (true) {
      std::stringstream buffercheck;
      numer = 0;
      buffer = "";

      getline (cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> numer) {
	break; }

      else {
	cout << "Invalid input, please use an interger: "; } }
    
    

    //Int as well
    cout << "\nFinally, please enter the denominator of the\n"
            "fractional price of your stocks: ";
    while (true) {
      std::stringstream buffercheck;
      denom = 0;
      buffer = "";

      getline (cin, buffer);
      buffercheck << buffer;

      if (buffercheck >> denom) {
	break; }

      else {
	cout << "Invalid input, please use an interger: "; } }

    

    //Calls function to get the value of each stock as a double
    //then muliplies by total number for total value
    cout << "\n\n\nCalculating the value of " << stkcnt << " stocks at the price of\n"
            "$" << dolprc << " " << numer << "/" << denom << "\n";
    indvalue = calc(dolprc, numer, denom);
    //Precondition: Have values input by user for whole dollar price, numerator of fractional
    //price, and denominator of fractional price.
    //Postcondition: Value of individual stocks returned
    totvalue = stkcnt * indvalue;
    cout << "\nThe value of your stocks is: $" << totvalue;



    //Repeat loop accepts only yY to continue or nN to quit
    cout << "\n\n\nWould you like to perform another calculation? y/n: ";

    while (true) {
      recalc = 'x';
      buffer = "";

      getline (cin, buffer);

      if (buffer.length() > 0) {
	recalc = buffer[0]; }

      if (valrecalc.find(recalc) != string::npos) {
	cout << "\n\nRestarting...\n\n\n\n";
	break; }

      if (valstop.find(recalc) !=string::npos) {
	cout << "\n\nGoodbye.\n";
	repeat = 0;
	break; }

      else {
	cout << "Invalid response. Please try again.\n"
                "Would you like to perform another calculation? y/n: "; } } }



  return 0; }






double calc (int dolprcf, int numerf, int denomf) {
  return dolprcf + numerf /(double) denomf; }
