//File Name: lesson05-614-07.cpp
//Author: Christopher Abelein
//Email: crabelein@gmail.com
//Assignment: 6
//Description: Implement class "Rational" to represent fractions. Class can
//hold integers >= 0. Private members variables for numerator and denominator,
//default constructor, overloaded constructor that establishes private variables,
//member functions add(), sub(), mul(), div(), less(), eq(), and neq(). Member function that returns current private variable values.
//Member function that accepts ostream argument and writes fraction.
//Last Modified: 02/23/17



#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <math.h>
#include <cctype>

using namespace std;

class rational {
public:
  rational(); //Constructor that initializes rational as numer = 0 and denom = 1

  rational(bool& ask); //Constructor that asks user for input with prompts

  rational(rational& frat1, rational& frat2); //Constructor that automatically initializes a rational
  
  rational add(rational& frat3); //Adds two rationals

  rational sub(rational& frat1); //Subrtracts a rational from another

  rational mul(rational& frat2); //Multiplies two rationals 

  rational div(rational& frat3); //Divides one rational with another

  bool les(rational& frat3); //Reports if a rational is less than another rational or not

  bool grt(rational& frat3); //Reports if a rational is greater than another rational or not

  bool equ(rational& frat2); //Reports if two rationals are equal or not

  void neg(); //Reports negative value of a rational

  void dis(int number); //Display value of a rational

  void input(istream& rinp); //Accepts input into a rational variable

  void output(ostream& rout); //Outputs a rational variable

private:
  void buildreturn(double& cnumer, double& cdenom); //Initializes rational variables in public member functions for creating return values
  
  int callnumer(); //Returns the numerator of a rational variable
  
  int calldenom(); //Returns the denominator of a rational variable

  void ones(double& fval1, double& fval2, double& fval3, double& fval4); //Sets rational fractions to same denominators if a denominator is equal to 1
  
  void reduce(double& fval1, double& fval2, double& fval3, double& fval4, bool& denoms); //Reduces rational fractions to least common multiple

  int numer; //Numerator value for rational
  int denom; //Denominator value for rational
};





int main() {
  cout << "\nThis program is designed to test a programmer-written"
       << "\nclass that stores and manipulates fractions."
       << "\nThree fractions will be needed for this test, the first"
       << "\ntwo will be input by you, the last one will be"
       << "\nautomatically generated.";

  ifstream rinput;
  ofstream routput;
  int x;
  bool ask = true;
  char filename[21], answer;
  string buffer;
  const string validno = "nN";
  const string validyes = "yY";

  cout << "\n\nPlease enter two positive numbers for the first fraction separated by a space."
       << "\nThe first number will be used as a numerator, the second as a denominator."
       << "\nnumbers: ";

  rational rat1(ask);

  cout << "\n\nPlease enter two positive numbers for the second fraction separated by a space."
       << "\nThe first number will be used as a numerator, the second as a denominator."
       << "\nnumbers: ";

  rational rat2(ask);

  rational rat3(rat1, rat2);

  
  
  rat1.dis(1);

  rat2.dis(2);

  rat3.dis(3);
  
  rat2.add(rat3);

  rat3.sub(rat1);

  rat1.mul(rat2);

  rat1.div(rat3);

  rat2.les(rat3);

  rat1.grt(rat2);

  rat1.equ(rat2);

  rat1.neg();

  

  
  cout << "\n\nWould you like to read values for the user-input"
       << "\nfraction from a file? The fraction must be written"
       << "\n(numerator) (denominator) in order to be used here."
       << "\ny/n: ";

  while (true) {
    buffer = "";
    answer = ' ';  

    while (buffer.length() == 0) {
      getline(cin, buffer); }

    if (buffer.length() > 0) {
      answer = buffer[0]; }

    if (validno.find(answer) != string::npos) {
      cout << "\n\nNo file will be read.";
      
      break; }

    if (validyes.find(answer) != string::npos) {
      cout << "\n\nPlease enter file name. File name must be 20 characters or less."
	   << "\nFile Name: ";
      
      while (true) {
	buffer = "";

	for (x = 0;x < 20;x++) {
	  filename[x] = ' '; }
      
	getline(cin, buffer);

	std::stringstream buffercheck;

	buffercheck << buffer;

	if (buffercheck >> filename) {
	  rinput.open(filename);

	  if (!rinput.fail()) {
	    rat1.input(rinput);
	  	  
	    break; } }
      
	else {
	  cout << "\nInvalid file name. Please try again."
	       << "\nFile Name: ";} }
      
      break ; }

    else {
      cout << "\nInvalid response. Please use y for yes or n for no."
	   << "\ny/n: " ; } }


  
  cout << "\n\nWould you like to write values for Fraction 1"
       << "\nto a file?  y/n: ";

  while (true) {
    buffer = "";
    answer = ' ';
      
    while (buffer.length() == 0) {
      getline(cin, buffer); }
      
    if (buffer.length() > 0) {
      answer = buffer[0]; }
      
    if (validno.find(answer) != string::npos) {
      cout << "\n\nNo file will be written."; 
	
      break; }
      
    if (validyes.find(answer) != string::npos) {
      cout << "\n\nPlease enter file name."
	   << "\nFile Name: ";
      
      while (true) {
	buffer = "";
	for (x = 0;x < 20;x++) {
	  filename[x] = ' '; }
	  
	getline(cin, buffer);
	  
	std::stringstream buffercheck;
	  
	buffercheck << buffer;
	  
	if (buffercheck >> filename) {
	  routput.open(filename);
	    
	  if (!routput.fail()) {
	    rat1.output(routput);
	      
	    break; } }
	  
	else {
	  cout << "\nInvalid file name. Please try again."
	       << "\nFile Name: "; } }
	
      break; }
    
    else {
      cout << "\nInvalid response. Please use y for yes or n for no."
	   << "\ny/n: "; } }



  cout << "\n\nFinished. Please press return to exit.";

  while (answer != '\n') {
    cin.get(answer); }

  return 0; }




//Member constructors
rational::rational() {
  numer = 0;
  denom = 1; }



rational::rational(bool& ask) {
  string buffer;


  
  while (ask == true) {
    numer = 0;
    denom = 0;

    getline(cin, buffer);

    std::stringstream buffercheck;

    buffercheck << buffer;
    
    buffercheck >> numer;
    buffercheck >> denom;


    
    if (numer > 0 && denom > 0) {
      break; }
    
    else {
      cout << "\nInvalid input. Please try again."
	   << "\nnumbers: "; } } }



rational::rational(rational& frat1, rational& frat2) {
  numer = frat1.callnumer();
  denom = frat2.callnumer(); }



//Public member functions
rational rational::add(rational& frat3) {
  double rnumer = numer, rdenom = denom, anumer = frat3.callnumer(), adenom = frat3.calldenom();
  bool denoms;
  rational answer;

  
  
  cout << "\n\nFraction 2 + Fraction 3 = ";
  
  if (rdenom == 1 || adenom == 1) {
    answer.ones(rdenom, adenom, rnumer, anumer); }
  
  if (rdenom != adenom) {
    denoms = true;
    
    answer.reduce(rdenom, adenom, rnumer, anumer, denoms); }
  
  rnumer = rnumer + anumer;
  denoms = false;
  answer.reduce(rdenom, rnumer, adenom, anumer, denoms);


  
  answer.buildreturn(rnumer, rdenom);
  
  cout << rnumer << "/" << rdenom;

  return answer; }



rational rational::sub(rational& frat1) {
  double gcd = 1, rnumer = numer, rdenom = denom, anumer = frat1.callnumer(), adenom = frat1.calldenom();
  bool denoms;
  rational answer;
  


  cout << "\n\nFraction 3 - Fraction 1 = ";

  if (rdenom == 1 || adenom == 1) {
    answer.ones(rdenom, adenom, rnumer, anumer); }

  if (rdenom != adenom) {
    denoms = true;
    
    answer.reduce(rdenom, adenom, rnumer, anumer, denoms); }

  rnumer = rnumer - anumer;
  denoms = false;
  answer.reduce(rdenom, rnumer, adenom, anumer, denoms);
  


  answer.buildreturn(rnumer, rdenom);
  
  cout << rnumer << "/" << rdenom;

  return answer; }



rational rational::mul(rational& frat2) {
  double gcd = 1, rnumer = numer, rdenom = denom, anumer = frat2.callnumer(), adenom = frat2.calldenom();
  bool denoms = false;
  rational answer;


  
  cout << "\n\nFraction 1 * Fraction 2 = ";

  rnumer = numer * anumer;
  rdenom = denom * adenom;

  if (rnumer == rdenom) {
    rnumer = 1;
    rdenom = 1; }
  
  if (rnumer != rdenom && rnumer != 1 && rdenom != 1) {
    answer.reduce(rdenom, rnumer, adenom, anumer, denoms); }
  


  answer.buildreturn(rnumer, rdenom);
  
  cout << rnumer << "/" << rdenom;
  
  return answer; }



rational rational::div(rational& frat3) {
  double gcd = 1, rnumer = numer, rdenom = denom, anumer = frat3.callnumer(), adenom = frat3.calldenom();
  bool denoms = false;
  rational answer;


  
  cout << "\n\nFraction 1 / Fraction 3 = ";

  rnumer = rnumer * adenom;
  rdenom = rdenom * anumer;
  
  if (rnumer == rdenom) {
    rnumer = 1;
    rdenom = 1; }

  if (rnumer != rdenom && rnumer != 1 && rdenom != 1) {
    answer.reduce(rdenom, rnumer, adenom, anumer, denoms); }



  answer.buildreturn(rnumer, rdenom);
  
  cout << rnumer << "/" << rdenom;
  
  return answer; }



bool rational::grt(rational& frat2) {
  if ((numer/denom) > (frat2.callnumer()/frat2.calldenom())) {
    cout << "\n\nFraction 1 is greater than Fraction 2";

    return true; }

  else {
    cout << "\n\nFraction 2 is greater than Fraction 1";

    return false;} }



bool rational::les(rational& frat3) {
  if ((numer/denom) < (frat3.callnumer()/frat3.calldenom())) {
    cout << "\n\nFraction 2 is less than Fraction 3";

    return true; }

  else {
    cout << "\n\nFraction 3 is less than Fraction 2";
    
    return false; } }



bool rational::equ(rational& frat2) {
  if ((numer/denom) == (frat2.callnumer()/frat2.calldenom())) {
    cout << "\n\nFraction 1 is equal to Fraction 2";

    return true; }

  else {
    cout << "\n\nFraction 1 is not equal to Fraction 2" ;

    return false; } }



void rational::neg() {
  cout << "\n\nThe negative value of Fraction 1 is " << -numer << "/" << denom; }



void rational::dis(int number) {
  cout << "\n\nFraction " << number << " numerator is " << numer << " and denominator is " << denom; }



void rational::input(istream& rinp) {
  rinp >> numer;
  rinp >> denom;
  
  cout << "\n\nFunction one is now " << denom << "/" << numer;  }



void rational::output(ostream& rout) {
  rout << numer << "/" << denom;

  cout << "\n\n" << numer << "/" << denom << " has been written to the selected file."; }



//Private member functions
void rational::buildreturn(double& cnumer, double& cdenom) {
  std::stringstream check;

  check << cnumer;
  check >> numer;

  check << cdenom;
  check >> denom; }



int rational::callnumer() {
  return numer; }



int rational::calldenom() {
  return denom; }



void rational::ones(double& fval1, double& fval2, double& fval3, double& fval4) {
  int comp[3], transfer, x, r;

  for (x = 0;x < 3;x++) {
    comp[x] = 0; }
  
  transfer = fval1;
  comp[0] = transfer;
  transfer = fval2;
  comp[1] = transfer;

  

  if (comp[0] == 1) {
    r = 1; }

  if (comp[1] == 1) {
    r = 2; }

  switch (r) {
  case 1:
    fval3 = fval3 * fval2;
    fval1 = fval2;

    break;
      
  case 2:
    fval4 = fval4 * fval1;
    fval2 = fval1;

    break; } }



void rational::reduce(double& fval1, double& fval2, double& fval3, double& fval4, bool& denoms) {
  int comp[5], transfer, x, r, result[5];
  double gcd = 0;
  bool neg2 = false, neg3 = false, neg4 = false;
  
  for (x = 0;x < 5;x++) {
    comp[x] = 0; }

  transfer = fval1;
  comp[0] = transfer;
  transfer = fval2;
  comp[1] = transfer;
  if (denoms == true) {
    transfer = fval3;
    comp[2] = transfer;
    transfer = fval4;
    comp[3] = transfer; }
  
  else {
    comp[2] = comp[0];
    comp[3] = comp[1]; }

  if (comp[1] < 0) {
    comp[1] = abs(comp[1]);
    neg2 = true; }
  
  if (comp[2] < 0) {
    comp[2] = abs(comp[2]);
    neg3 = true; }

  if (comp[3] < 0) {
    comp[3] = abs(comp[3]);
    neg4 = true; }


  
  if (comp[0] < comp[1]) {
    r = 1; }

  if (comp[1] < comp[0]) {
    r = 2; }
    
  switch (r) {
  case 1:
    for (x = fval1;x > 1;x--) {
      for (r = 0;r < 4;r++) {
	result[r] = comp[r] % x; }
	
      if (result[0] == 0 && result[1] == 0 && result[2] == 0 && result[3] == 0 && x != 0) {
	gcd = x;

	if (denoms == true) {
	  if (gcd != 1 && fval1 != fval2) {
	    fval4 = fval4 / gcd;
	    fval2 = fval2 / gcd;
		
	    if (fval1 != gcd) {
	      fval3 = fval3 / (fval1 / fval2);
	      fval1 = fval1 / (fval1 / fval2); } }

	  if (neg3 == true) {
	    fval3 = -fval3; }

	  if (neg4 == true) {
	    fval4 = -fval4; }

	  break; }

	if (denoms == false) {
	  if (gcd != 1 && fval1 != fval2) {
	    fval2 = fval2 / gcd;
	    fval1 = fval1 / gcd; }

	  if (neg2 == true) {
	    fval2 = -fval2; }
	  
	  break; } }

      if (x <= 1) {

	break; } }
    
    break;

  case 2:
    for (x = fval2;x > 1;x--) {
      for (r = 0;r < 4;r++) {
	result[r] = comp[r] % x; }
      
      if (result[0] == 0 && result[1] == 0 && result[2] == 0 && result[3] == 0 && x != 0) {
	gcd = x;
	    
	if (denoms == true) {
	  if (gcd != 1 && fval1 != fval2) {
	    fval3 = fval3 / gcd;
	    fval1 = fval1 / gcd;
		
	    if (fval2 != gcd) {
	      fval4 = fval4 / (fval2 / fval1);
	      fval2 = fval2 / (fval2 / fval1); } }
		
	  if (neg3 == true) {
	    fval3 = -fval3; }

	  if (neg4 == true) {
	    fval4 = -fval4; }
	  
	  break; }

	if (denoms == false) {
	  if (gcd != 1 && fval1 != fval2) {
	    fval1 = fval1 / gcd;
	    fval2 = fval2 / gcd; }

	  if (neg2 == true) {
	    fval2 = -fval2; }
	  
	  break; } }

      if (x == 1) {

	break; } }
    
    break; }

  if (gcd == 0 && fval1 != fval2 && denoms == true) {
    gcd = fval1;
    fval1 = fval1 * fval2;
    fval3 = fval3 * fval2;
    fval2 = fval2 * gcd;
    fval4 = fval4 * gcd; }

  return void(); }
