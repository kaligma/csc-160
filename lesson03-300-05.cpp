//File Name: lesson03-300-05.cpp
//Author: Christopher Abelein
//Email Address: crabelein@gmail.com
//Assignment: 3
//Description: Write a program with a function that calculates wind chill seperately.
//equation: W = 13.12 +0.6215 * t - 11.37 * p^0.16 +0.3965 * t * t^0.016
//w = winchill index in C, t = tempreature in C, p = wind speed in m/sec
//Last Modified: 02/02/17

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

//I was writing the temperature input, and I thought I might as well add the ability to
//input and output in Fahrenheit. Then I got to the wind speed input, and I thought it
//would be weird to not have an option to use MPH as well since Fahrenheit was fair game.
//Thus, a function for each combination.
double calculatecm(double tempf, double wdspdf);
double calculateci(double tempf, double wdspdf);
double calculatefm(double tempf, double wdspdf);
double calculatefi(double tempf, double wdspdf);

int main () {
  double wdspd, temp, wdchl;
  int repeat;
  char tchoice, wchoice, recalc;
  string buffer;
  const string choicec = "cC";
  const string choicef = "fF";
  const string choicem = "mM";
  const string choicei = "iI";
  const string valrecalc = "yY";
  const string valstop = "nN";

  repeat = 1;


  
  cout << "\nHello. This program is designed to calculate wind chill index based on"
          "\nuser input temperature and wind speed.";

  

  while (repeat == 1) {
    cout << "\n\n\nFirst, please choose whether you want to use Fahrenheit"
                "\nor Celsius. Both input and answer will be in whichever"
                "\nscale you choose. c/f: ";
    while (true) {
      tchoice = 'x';
      buffer = "";

      getline(cin, buffer);

      if (buffer.length() > 0) {
	tchoice = buffer[0]; }

      if (choicec.find(tchoice) != string::npos) {
	cout << "You have chosen Celsius.";
	break; }

      if (choicef.find(tchoice) != string::npos) {
	cout << "You have chosen Fahrenheit.";
	break; }

      else {
	cout << "Invalid input. Please try again."
              "\nPlease choose Celsius or Fahrenheit. c/f: "; } }

    if (tchoice == 'c' || tchoice == 'C') {
      cout << "\nPlease enter temperature in degrees Celsius. C: ";
      while (true) {
	temp = 0;
	buffer = "";
	std::stringstream buffercheck;

	getline(cin, buffer);
	buffercheck << buffer;

	if (buffercheck >> temp) {
	  break; }

	else {
	  cout << "Invalid input. Please try again."
                "\nPlease enter temperature in degrees Celsius. C: "; } } }

    if (tchoice == 'f' || tchoice == 'F') {
      cout << "\nPlease enter temperature in degrees Fahrenheit. F: ";
      while (true) {
	temp = 0;
	buffer = "";
	std::stringstream buffercheck;

	getline(cin, buffer);
	buffercheck << buffer;

	if (buffercheck >> temp) {
	  break; }

	else {
	  cout << "Invalid input. Please try again."
                "\nPlease enter temperature in degrees Fahrenheit. F: "; } } }
    
    
    
    //I felt weird only accepting M/S when I allowed Celsius or Fahrenheit for
    //temperature, so I just put in the ability to input and convert MPH
    cout << "\n\n\nNext, please choose whether you want to input wind speed as meters"
                "\nper second or miles per hour. meters per second is indicated by m"
                "\nfor metric, miles per hour is indicated by i for imperial."
                "\nm/i: ";
    while (true) {
      wchoice = 'x';
      buffer = "";

      getline(cin, buffer);

      if (buffer.length() > 0) {
	wchoice = buffer[0]; }

      if (choicem.find(wchoice) != string::npos) {
	cout << "You have chosen meters per second.";
	break; }

      if (choicei.find(wchoice) != string::npos) {
	cout << "You have chosen miles per hour.";
	break; }

      else {
	cout << "Invalid input. Please try again."
              "\nPlease choose meters per second or miles per hour. m/i: "; } }



    if (wchoice == 'm' || wchoice == 'M') {
      cout << "\nPlease enter wind speed in meters per second. M/S: ";
      while (true) {
	wdspd = 0;
	buffer = "";
	std::stringstream buffercheck;

	getline(cin, buffer);
	buffercheck << buffer;

	if (buffercheck >> wdspd) {
	  break; }

	else {
	  cout << "Invalid input. Please try again."
                "\nPlease enter wind speed in meter per second. M/S: "; } } }
    
    
    
    if (wchoice == 'i' || wchoice == 'I') {
      cout << "\nPlease enter wind speed in miles per hour. MPH: ";
      while (true) {
	wdspd = 0;
	buffer = "";
	std::stringstream buffercheck;

	getline(cin, buffer);
	buffercheck << buffer;

	if (buffercheck >> wdspd) {
	  break; }

	else {
	  cout << "Invalid input. Please try again."
                "\nPlease enter wind speed in miles per hour. MPH: "; } } }



    //Functions for each combination of Celsius, Farenheit, M/S, and MPH. They all work well
    //except the Fahrenheit MPH combination
    if ((choicec.find(tchoice) != string::npos) && (choicem.find(wchoice) != string::npos)) {
      cout << "Calculating wind chill with " << temp << " degrees Celsius and " << wdspd << " meters per second...";
      wdchl = calculatecm(temp, wdspd);
      cout << "\n\nWind chill is " << wdchl << " degrees Celsius."; }
    //Precondition: Temperature input in Celsius and wind speed in M/S
    //Postcondition: Wind chill returned in Celsius
    
    if ((choicec.find(tchoice) != string::npos) && (choicei.find(wchoice) != string::npos)) {
      cout << "Calculating wind chill with " << temp << " degrees Celsius and " << wdspd << " miles per hour...";
      wdchl = calculateci(temp, wdspd);
      cout << "\n\nWind chill is " << wdchl << " degrees Celsius."; }
    //Precondition: Temperature input in Celsius and wind speed in MPH
    //Postcondition: Wind chill returned in Celsius
    
    if ((choicef.find(tchoice) != string::npos) && (choicem.find(wchoice) != string::npos)) {
      cout << "Calculating wind chill with " << temp << " degrees Fahrenheit and " << wdspd << " meters per second...";
      wdchl = calculatefm(temp, wdspd);
      cout << "\n\nWind chill is " << wdchl << " degrees Fahrenheit."; }
    //Precondition: Temperature input in Fahrenheit and wing speed in M/S
    //Postcondition: Wind chill returned in Fahrenheit
    
    if ((choicef.find(tchoice) != string::npos) && (choicei.find(wchoice) != string::npos)) {
      cout << "Calculating wind chill with " << temp << " degrees Fahrenheit and " << wdspd << " miles per hour...";
      wdchl = calculatefi(temp, wdspd);
      cout << "\n\nWind chill is " << wdchl << " degrees Fahrenheit."; }
    //Precondition: Temperature input in Fahrenheit and wind speed in MPH
    //Postcondition: Wind chill returned in Fahrenheit


    cout << "\n\n";
    while (true) {
      recalc = 'x';
      buffer = "";

      cout << "\nWould you like to run another calculation? y/n: ";
      
      getline(cin, buffer);

      if (buffer.length() > 0) {
	recalc = buffer[0]; }

      if (valrecalc.find(recalc) != string::npos) {
	cout << "\nRestarting...\n\n\n\n";
	break; }
      if (valstop.find(recalc) != string::npos) {
	cout << "\nGoodbye\n";
	repeat = 0;
	break; }

      else {
	cout << "Invalid response. Please try again."; } } }



  return 0; }





/*
The first three functions output values very close to what online
wind chill calculators do with the same input. Obviously, the Celsius
and M/S input work the best, the output is usually within less than
1 degree of online calculators. The middle two return somewhat less
accurate values, usually within 2 or 3 degrees of online calculators.
The last function, which uses Fahrenheit and MPh input, is the least
accurate.
*/
double calculatecm(double tempf, double wdspdf) {
  double ans;

  ans = 13.12 + 0.6215 * tempf - 11.37 * pow(wdspdf, 0.16) + 0.3965 * tempf * pow(wdspdf, 0.016);

  return ans; }



double calculateci(double tempf, double wdspdf) {
  double ans;

  wdspdf = wdspdf * 0.44704;
  cout << "\nTEST " << wdspdf;
  ans = 13.12 + 0.6215 * tempf - 11.37 * pow(wdspdf, 0.16) + 0.3965 * tempf * pow(wdspdf, 0.016);

  return ans; }



double calculatefm(double tempf, double wdspdf) {
  double ans;

  tempf = (tempf-32)*5/9;
  cout << "\nTEST " << tempf;
  ans = 13.12 + 0.6215 * tempf - 11.37 * pow(wdspdf, 0.16) + 0.3965 * tempf * pow(wdspdf, 0.016);
  ans = ans*9/5+32;
  
  return ans; }


/*
  I couldn't get this function to spit out anything super close to what
  online wind chill factor calculators said. I checked all the conversions,
  both of the conversions before the formula output correct values for
  the equation to use, but the result prior to converting back to Farenheit
  is not correct. The equation itself is identical to the equations in the
  other functions, all of which produce fairly accurate values.
*/
double calculatefi(double tempf, double wdspdf) {
  double ans;

  wdspdf = wdspdf * 0.44704;
  tempf = (tempf-32)*5/9;
  cout << "\nTEST " << tempf << " ALSO " << wdspdf;
  ans = 13.12 + 0.6215 * tempf - 11.37 * pow(wdspdf, 0.16) + 0.3965 * tempf * pow(wdspdf, 0.016);
  cout << "\nTEST " << ans;
  ans = ans*9/5+32;
  
  return ans; }
