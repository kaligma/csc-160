//File Name: lesson06-695-02.cpp
//Author: Christopher Abelein
//Email: crabelein@gmail.com
//Assignemnt: 6
//Description: Create a class for rational numbers with fractions represented by two private variables.
//Include a constructor that can initialize values, a constructor that can define the fraction as a whole number,
//and a standard 0/1 constructor. Overload input and output operators >> and <<. Allow negative inputs.
//Overload comparators ==, <, <=, >, >=, +, -, *, and / to work with rationals. Test program to test class.
//Last Modified: 03/02/17



#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <sstream>
#include <istream>
#include <ostream>

class rational {
public:
  rational(); //Constructor that initialzes rational as numer = 0 and denom = 1

  rational(int cnumer); //Constructor that initializes rational as a whole number numer = whole and denom = 1

  rational(int cnumer, int cdenom); //Constructor that initializes rational as a defined value numer = cnumer and denom = cdenom


  //I can't get my friend functions to not produce errors about using rational private things. I'm fairly certain these declarations
  //and the actual function definitions are written correctly, but it still doesn't work.

  //I don't understand why this function doesn't recognize the rational variable. Even if I use a global std namespace and make
  //this line exactly like it is in the book, it doesn't work.
  //My compiler is also telling me that istream and ostream have private copy constructors
  //I don't know why that's a problem now, since I've written these before.
  friend std::istream& operator >>(std::istream& ins, rational& frat); //Overloaded input function for rational class

  friend std::ostream& operator <<(std::ostream ots, const rational& frat); //Overloaded output function for rational class

  friend rational operator =(rational& frat1, const rational& frat2); //Overloaded equals function for rational class

  friend rational operator +(const rational& frat1,const rational& frat2); //Overloaded addition function for rational class

  friend rational operator -(const rational& frat1, const rational& frat2); //Overloaded subtraction function for rational class

  friend rational operator *(const rational& frat1, const rational& frat2); //Overloaded multiplication function for rational class

  friend rational operator /(const rational& frat1,const rational& frat2); //Overloaded division function for rational class

  friend bool operator ==(const rational& frat1,const rational& frat2); //Overloaded equal comaparator for rational class

  friend bool operator !=(const rational& frat1,const rational& frat2); //Overloaded not equal comparator for rational class

  friend bool operator >(const rational& frat1,const rational& frat2); //Overloaded greater than comparator for rational class

  friend bool operator >=(const rational& frat1,const rational& frat2); //Overloaded greater or equal comparator for rational class

  friend bool operator <(const rational& frat1,const rational& frat2); //Overloaded less than comparator for rational class

  friend bool operator <=(const rational& frat1,const rational& frat2); //Overloaded less than or equal comparator for rational class

  rational equ(const rational& frat1);

  rational add(const rational& frat1);

  rational sub(const rational& frat1);

  rational mul(const rational& frat1);

  rational div(const rational& frat1);

  bool ieq(const rational& frat1);

  bool neq(const rational& frat1);

  bool grt(const rational& frat1);

  bool gre(const rational& frat1);

  bool les(const rational& frat1);

  bool lee(const rational& frat1);
  
  bool display(int number); 
  
private:
  void buildreturn(int& anumer, int& adenom); //Builds a rational for the return value of a member function
    
  int callnumer(); //Returns numer of a rational

  int calldenom(); //Returns denom of a rational

  void ones(rational& frat); //Sets fractions to same denominator for addition/subtraction if a fraction denominator is a 1

  void reduce(); //Reduces a single fraction

  void reduce(rational& frat); //Reduces a pair of fractions for addition/subtraction
  
  int numer;
  int denom;
};

int main() {
  using namespace std;

  int cnumer, cdenom;
  char exit;
  string buffer;


  
  cout << "\nHello. This program is designed to test a programmer created class"
       << "\nwith overloaded operators and comparators using user input values.";

  cout << "\nPlease input two whole numbers separate by a space."
       << "\nnumbers: ";

  while (true) {
    cnumer = 0, cdenom = 0;
    
    getline(cin, buffer);
    
    std::stringstream check;
    
    check << buffer;

    if (check >> cnumer && check >> cdenom) {
      break; }

    else {
      cout << "\nInvalid response. Please try again."
	   << "\nnumbers: "; } }
  
  rational rat1(cnumer, cdenom), rat2(cnumer), rat3, arat;

  cout << "\nPlease input a rational numer in the format (numerator,denominator)"
       << "(numerator,denominator): ";

  cin >> rat3;
  
  
  
  rat1.display(1);

  rat2.display(2);

  rat3.display(3);

  arat = rat1 * rat2;

  cout << "\nFraction 1 * Fraction 2 = ";
  cout << arat;

  arat = rat1 / rat3;

  cout << "\nFraction 1 / Fraction 3 = ";
  cout << arat;

  arat = rat2 + rat3;

  cout << "\nFraction 2 + Fractions 3 = ";
  cout << arat;

  arat = rat3 - rat1;

  cout << "\nFraction 3 - Fraction 1 = ";
  cout << arat;

  if (rat1 < rat2) {
    cout << "\nFraction 1 is less than Fraction 2"; }
  if (rat1 >= rat2) {
    cout << "\nFraction 1 is greater than or equal to Fraction 2"; }

  if (rat2 > rat3) {
    cout << "\nFraction 2 is greater than Fraction 3"; }
  if (rat2 <= rat3) {
    cout << "\nFraction 2 if less than or equal to Fraction 3"; }

  if (rat1 == rat3) {
    cout << "\nFraction 1 is equal to Fraction 3"; }
  if (rat1 != rat3) {
    cout << "\nFraction 1 is not equal to Fraction 3"; }

  cout << "\n\nTests complete. Please press return to exit.";

  while (exit != '\n') {
    cin >> exit; }
  
  return 0; }




//Member constructors
rational::rational() {
  using namespace std;
  
  numer = 0;
  denom = 0; }

rational::rational(int cnumer) {
  using namespace std;
  
  numer = cnumer;
  denom = 1; }

rational::rational(int cnumer, int cdenom) {
  using namespace std;
  
  numer = cnumer;
  denom = cdenom; }

//Friend functions
//These just return errors about not being able to use rational private stuff

//Same problem here, the rational is not interpreted as a class
std::istream& operator >>(std::istream& ins, rational& frat) {
  using namespace std;

  string buffer;
  char check;
  int inumer[21], idenom[21], rnumer, rdenom, number = 0, x, r = 0;

  

  getline(ins, buffer);

  while (true) {
    for (x = 0;x < 55; x++) {
      check = buffer[x];
      
      if (check == '(') {
	number = 1; }

      if (isdigit(check) && number == 1) {
	idenom[r] = check;
	r++; }

      if (check == '/') {
	std::stringstream numercheck;
	numercheck << inumer;
	numercheck >> rnumer;
	number = 2; }

      if (check == ')') {
	std::stringstream denomcheck;
	denomcheck << idenom;
	denomcheck >> rdenom;

	frat.buildreturn(rnumer, rdenom);

	break; }
      
    else {
      cout << "\nInvalid response. Please try again."
	   << "\n(numerator,denominator): "; } } }


  frat.reduce();

  return ins; }

std::ostream& operator <<(std::ostream& ots, const rational& frat) {
  using namespace std;

  rational mrat(frat.numer, frat.denom);
  
  ots << "(" << mrat.numer << "/" << mrat.denom << ")";

  return ots; }


rational operator =(rational& frat1, const rational& frat2) {
  rational answer;


  frat1.equ(frat2);

  return frat1; }



rational operator +(const rational& frat1,const rational& frat2) {
  using namespace std;

  rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);
  
  
  answer = mrat1.add(mrat2);
  
  return answer; }

rational operator -(const rational& frat1, const rational& frat2) {
  using namespace std;

  rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);


  answer = mrat1.sub(mrat2);
  
  return answer; }

rational operator *(const rational& frat1, const rational& frat2) {
  using namespace std;

  rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);

  
  answer = mrat1.mul(mrat2);
  
  return answer; }

rational operator /(const rational& frat1,const rational& frat2) {
  using namespace std;

  rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);
  

  answer = mrat1.div(mrat2);
  
  return answer; }

bool operator ==(const rational& frat1,const rational& frat2) {
  using namespace std;

  rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);

  
  return mrat1.ieq(mrat2); }

bool operator !=(const rational& frat1,const rational& frat2) {
  using namespace std;

  rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);

  return mrat1.neq(mrat2); }

bool operator >(const rational& frat1,const rational& frat2) {
  using namespace std;

  rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);

  return mrat1.grt(mrat2); }



bool operator >=(const rational& frat1,const rational& frat2) {
  using namespace std;

    rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);

    return mrat1.gre(mrat2); }



bool operator <(const rational& frat1,const rational& frat2) {
  using namespace std;

    rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);

    return mrat1.les(mrat2); }

bool operator <=(const rational& frat1,const rational& frat2) {
  using namespace std;

    rational answer, mrat1(frat1.numer, frat1.denom), mrat2(frat2.numer, frat2.denom);

    return mrat1.lee(mrat2); }





//Public member functions
rational rational::equ(const rational& frat1) {
  using namespace std;

  rational answer;
  
  numer = frat1.callnumer();
  denom = frat1.calldenom();

  answer.buildreturn(numer, denom);

  return answer; }


rational rational::add(const rational& frat1) {
  using namespace std;

  rational answer, mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);
  int anumer, adenom;


  
  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

  //TEST
  if (mrat1.callnumer() == mrat2.callnumer()) {
    //TEST
    anumer = mrat1.callnumer() + mrat2.callnumer();
    
    adenom = mrat1.calldenom(); }

  //TEST
  else {
    cout << "\nERROR: Denominators not equal for addition :ERROR"; }
  //TEST

  answer.buildreturn(anumer, adenom);

  answer.reduce();

  return answer; }

rational rational::sub(const rational& frat1) {
  using namespace std;

  rational answer, mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);
  int anumer, adenom;
  
  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

  //TEST
  if (mrat1.calldenom() == mrat2.calldenom()) {
    //TEST
    anumer = mrat1.callnumer() - mrat2.callnumer();
    
    adenom = mrat1.calldenom(); }

  else {
    cout << "\nERROR: Denominators not equal for subtraction :ERROR"; }

  answer.buildreturn(anumer, adenom);

  answer.reduce();

  return answer; }

rational rational::mul(const rational& frat1) {
  using namespace std;
  
  rational answer, mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);
  int anumer, adenom;


  anumer = mrat1.callnumer() * mrat2.callnumer();
  adenom = mrat1.calldenom() * mrat2.calldenom();

  answer.buildreturn(anumer, adenom);

  answer.reduce();

  return answer; }

rational rational::div(const rational& frat1) {
  using namespace std;
  
  rational answer, mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);
  int anumer, adenom;


  anumer = mrat1.callnumer() * mrat2.calldenom();
  adenom = mrat1.calldenom() * mrat2.callnumer();

  answer.buildreturn(anumer, adenom);

  answer.reduce();

  return answer; }

bool rational::ieq(const rational& frat1) {
  using namespace std;
  
  rational mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);


  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

    //TEST
  if (mrat1.calldenom() == mrat2.calldenom()) {
    //TEST
    if (mrat1.callnumer() == mrat2.callnumer()) {
      return true; }
    if (mrat1.callnumer() != mrat2.callnumer()) {
      return false; }
    //TEST
    else {
      cout << "\nERROR: Numerators not comparing for == :ERROR"; }
  }
  //TEST
  else {
    cout << "\nERROR: Denominators not equal for == :ERROR"; }
  //TEST
}

bool rational::neq(const rational& frat1) {
  using namespace std;
  
  rational mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);


  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

  if (mrat1.callnumer() != mrat2.callnumer()) {
    return true; }
  if (mrat1.callnumer() == mrat2.callnumer()) {
    return false; } }



bool rational::grt(const rational& frat1) {
  using namespace std;
  
  rational mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);


  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

  if (mrat1.callnumer() > mrat2.callnumer()) {
    return true; }
  if (mrat1.callnumer() <= mrat2.callnumer()) {
    return false; } }

bool rational::gre(const rational& frat1) {
  using namespace std;

 rational mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);
  

  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

  if (mrat1.callnumer() >= mrat2.callnumer()) {
    return true; }
  if (mrat1.callnumer() < mrat2.callnumer()) {
    return false;  } }

bool rational::les(const rational& frat1) {
  using namespace std;

  rational mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);
  

  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

  if (mrat1.callnumer() < mrat2.callnumer()) {
    return true; }
  if (mrat1.callnumer() >= mrat2.callnumer()) {
    return false; } }

 

bool rational::lee(const rational& frat1) {
  using namespace std;

  rational mrat1(numer, denom), mrat2(frat1.numer, frat1.denom);
  

  mrat1.ones(mrat2);
  mrat1.reduce(mrat2);

  if (mrat1.callnumer() <= mrat2.callnumer()) {
    return true; }
  if (mrat1.callnumer() > mrat2.callnumer()) {
    return false; } }

void rational::display() {
  using namespace std;

  cout << "\nFraction " << number << " is " << frat; }



//Private member functions
void rational::buildreturn(int& anumer, int& adenom) {
  using namespace std;

  numer = anumer;
  denom = adenom; }

int callnumer() {
  using namespace std;
  
  return numer; }

int calldenom() {
  using namespace std;
  
  return denom; }

void rational::ones(rational& frat) {
  using namespace std;
  
  int comp[3], transfer, x, r;

  for (x = 0;x < 3;x++) {
    comp[x] = 0; }
  
  transfer = denom;
  comp[0] = transfer;
  transfer = frat.denom;
  comp[1] = transfer;

  

  if (comp[0] == 1) {
    r = 1; }

  if (comp[1] == 1) {
    r = 2; }

  switch (r) {
  case 1:
    numer = numer * frat.denom;
    denom = frat.denom;

    break;
      
  case 2:
    frat.numer = frat.numer * denom;
    frat.denom = denom;

    break; } }



void rational::reduce() {
  using namespace std;
  
  int comp[3], transfer, x, r, result[3];
  double gcd = 0;
  bool neg1 = false, neg2 = false;
  
  for (x = 0;x < 3;x++) {
    comp[x] = 0; }

  if (numer < 0) {
    transfer = abs(numer);
    neg1 = true; }
  else {
    transfer = numer; }
  
  comp[0] = transfer;

  if (denom < 0) {
    transfer = abs(denom);
    neg2 = true; }
  
  else {
    transfer = denom; }
  comp[1] = transfer;



  if (comp[0] < comp[1]) {
    r = 1; }

  if (comp[1] < comp[0]) {
    r = 2; }
    
  switch (r) {
  case 1:
    for (x = numer;x > 1;x--) {
      for (r = 0;r < 2;r++) {
	result[r] = comp[r] % x; }
	
      if (result[0] == 0 && result[1] == 0 && x > 1) {
	gcd = x;
	if (gcd != 1 && numer != denom) {
	  numer = numer / gcd;
	  denom = denom / gcd; }

	if (neg1 == true) {
	  numer = -numer; }

	if (neg2 == true) {
	  denom = -denom; }

	break; } }

    if (x <= 1) {
      break; }
    
    break;

  case 2:
    for (x = denom;x > 1;x--) {
      for (r = 0;r < 2;r++) {
	result[r] = comp[r] % x; }
      
      if (result[0] == 0 && result[1] == 0 &&) {
	gcd = x;
	if (gcd != 1 && denom != numer) {
	  denom = denom / gcd;
	  numer = numer / gcd;

	  if (neg1 == true) {
	    numer = -numer; }

	  if (neg2 == true) {
	    denom = -denom; }
	  
	  break; } }

      if (x == 1) {

	break; } }
    
    break; }
    
  return void(); }

void rational::reduce(rational& frat1) {
  using namespace std;
  
  int comp[5], transfer, x, r, result[5];
  double gcd = 0;
  bool neg1 = false, neg2 = false, neg3 = false, neg4 = false;
  
  for (x = 0;x < 5;x++) {
    comp[x] = 0; }

  if (denom < 0) {
    transfer = abs(denom);
    neg1 = true; }

  else {
    transfer = denom; }
  
  comp[0] = transfer;

  if (frat.denom < 0) {
    transfer = abs(frat.denom);
    neg2 = true; }

  else {
    transfer = fval2; }
  
  comp[1] = transfer;
  
  if (numer < 0) {
    transfer = abs(numer);
    neg3 = true; }

  else {
    transfer = fval3; }
      
  comp[2] = transfer;
    
  if (frat.numer < 0) {
    transfer = abs(frat.numer);
    neg4 = true; }
  
  else {
    transfer = frat.numer; }
  
  comp[3] = transfer;


  
  if (comp[0] < comp[1]) {
    r = 1; }

  if (comp[1] < comp[0]) {
    r = 2; }
    
  switch (r) {
  case 1:
    for (x = denom;x > 1;x--) {
      for (r = 0;r < 4;r++) {
	result[r] = comp[r] % x; }
	
      if (result[0] == 0 && result[1] == 0 && result[2] == 0 && result[3] == 0 && x != 0) {
	gcd = x;

	if (gcd != 1 && fval1 != fval2) {
	  frat.numer = frat.numer / gcd;
	  frat.denom = frat.denom / gcd;
		
	  if (denom != frat.denom) {
	    numer = numer / (denom / frat.denom);
	    denom = denom / (denom / frat.denom); } }

	if (neg1 == true) {
	  denom = -denom; }

	if (neg4 == true) {
	  frat.denom = -frat.denom; }
	  
	if (neg3 == true) {
	  numer = -numer; }

	if (neg4 == true) {
	  frat.numer = -frat.numer; }

	break; } }

    if (x <= 1) {

      break; }
    
  break;

  case 2:
    for (x = frat.denoms;x > 1;x--) {
      for (r = 0;r < 4;r++) {
	result[r] = comp[r] % x; }
      
      if (result[0] == 0 && result[1] == 0 && result[2] == 0 && result[3] == 0 && x != 0) {
	gcd = x;
	    
	if (gcd != 1 && frat.denom != denom) {
	  numer = numer / gcd;
	  denom = denom / gcd;
		
	  if (frat.denom != denom) {
	    frat.numer = frat.numer / (frat.denom / denom);
	    frat.denom = frat.denom / (frat.denom / denom); } }
		
	if (neg1 == true) {
	  fval1 = -fval1; }

	if (neg2 == true) {
	  fval2 = -fval2; }
	  
	if (neg3 == true) {
	  fval3 = -fval3; }

	if (neg4 == true) {
	  fval4 = -fval4; }
	  
	break; }

      if (x == 1) {

	break; } }
    
    break; }

  if (gcd == 0 && fval1 != fval2) {
    gcd = fval1;
    fval1 = fval1 * fval2;
    fval3 = fval3 * fval2;
    fval2 = fval2 * gcd;
    fval4 = fval4 * gcd; }

  if (numer < 0 && denom < 0) {
    numer = abs(numer);
    denom = abs(denom); }

  if (frat.numer < 0 && frat.denom < 0) {
    frat.numer = abs(frat.numer);
    frat.denom = abs(frat.numer); }

  return void(); }
