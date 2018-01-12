//File Name: lesson05-611-01.cpp
//Author: Christopher Abelein
//Email: crabelein@gmail.com
//Assignement: 5
//Description: Implement book's CDAccount structure as a class.
//Three private member variables, a default constructor, a constructor
//that accepts 3 initial values for the private variables, member
//functions to return private values, a member function that calculates
//and returns account value at maturity, a member function that accepts
//and istream and reads for the private variables, and a member function
//that accepts an ostream and writes private variables.
//Last Modified: 02/20/17

#include<iostream>
#include<fstream>

class cdaccount {
public:
  cdaccount();
  //Precondition: cdaccount not initialized
  //Postcondition: cdaccount initialized

  cdaccount(double cbalance, double cintrate, int cterm);
  //Precondition: cdaccount not initialized
  //Postcondition: cdaccount initialized and assigned values
  
  void reportbalance();
  //Precondition: balance variable has a value stored privately
  //Postcondition: balance variable reported to user

  void reportintrate();
  //Precondition: intrate variable has a value stored privately
  //Postcondition: intrate variable reported to user

  void reportterm();
  //Precondition: term variable has a value stored privately
  //Postcondition: term variable reported to user

  void reportmature();
  //Precondition: cdaccount assigned values for all three private variables
  //Postcondition: reports value of cdaccount at maturity

  void instream();
  //Precondition: file with acceptable values for cdaccount variables
  //Postcondition: cdaccount variables assigned

  void outstream();
  //Precondition: file where cdaccount variables values can be written
  //and values for all three private variables for cdaccount
  //Postcondition: values for private variables of cdaccount written
  //to file

private:
  double balance;
  double intrate;
  int term; };





int main() {
  using namespace std;

  cout << "\nHello. This program is designed to hold information"
       << "\nabout Certified Deposit Accounts. You will need to"
       << "\ninput the initial balance of the account in dollars, the interest"
       << "\nrate on the accountas a percent, and the term of the account"
       << "\nin months. You will then be able to retrieve information about"
       << "\nthe account.";

  //Contructor called when cdaccount act is declared for initialization.
  cdaccount act;
  double pbalance, pintrate;
  int pterm, choice, repeat = 1;
  char cont;
  
  
  
  while (repeat == 1) {
    choice = 0;
    
    cout << "\n\n\nPlease select a function by typing in the appropriate number."
	 << "\n1. Report value of mature account."
	 << "\n2. Report current account balance."
	 << "\n3. Report current account interest rate."
	 << "\n4. Report current account term."
	 << "\n5. Read new account balance, interest rate, and term from a file."
	 << "\n6. Write account balance, interest rate, and term to a file."
	 << "\n7. Input new account balance, interest rate, and term manually with prompts."
	 << "\n8. Input new account balance as a list of three numbers with no prompts."
	 << "\n9. Exit program."
	 << "\n\nEnter selection: ";

    cin.ignore();
    cin >> choice;
    
    
    
    switch (choice) {
    case 1:
      act.reportmature();


      
      cout << "\n\nWould you like to continue? n exits, other continues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }

      else {
	break; }
      
    case 2:
      act.reportbalance();


      
      cout << "\n\nWould you like to continue? n exits, other contnues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }
	
      else {
	break; }
      
    case 3:
      act.reportintrate();


      
      cout << "\n\nWould you like to continue? n exits, other continues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }
	
      else {
	break; }
      
    case 4:
      act.reportterm();


      
      cout << "\n\nWould you like to continue? n exits, other continues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }
	
      else {      
	break; }
      
    case 5:
      act.instream();

      
      
      cout << "\n\nWould you like to continue? n exits, other continues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }
	
      else {      
	break; }
      
    case 6:
      act.outstream();


      
      cout << "\n\nWould you like to continue? n exits, other continues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }
	
      else {      
	break; }
      
    case 7:
      act = cdaccount();
      
      cout << "\n\nWould you like to continue? n exits, other continues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }
	
      else {      
	break; }

    case 8:
      cout << "\n\nValues (bal int term): ";
      cin.ignore();
      cin >> pbalance;
      cin >> pintrate;
      cin >> pterm;
      
      act = cdaccount(pbalance, pintrate, pterm);


      
      cout << "\n\nWould you like to continue? n exits, other continues:";

      cin >> cont;

      if (cont == 'n' || cont == 'N') {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }
	
      else {      
	break; }
      
    case 9:
      cout << "\n\n\nGoodbye.\n";
      repeat = 0;
      break;

    default:
      cout << "\nInvalid response. Please try again."; } } }





cdaccount::cdaccount() {
  using namespace std;
  
  cout << "\n\n\nPlease input the balance of the CDA in dollars: $";
  
  cin >> balance;
  
  cout << "\nPlease input the interest rate of the CDA as a percent: %";
  
  cin >> intrate;
  
  cout << "\nPlease input the term of the CDA in months: ";
  
  cin >> term; }



cdaccount::cdaccount(double cbalance, double cintrate, int cterm) {
  using namespace std;
  
  balance = cbalance;
  intrate = cintrate;
  term = cterm;
  
  cout << "\n\nNew account parameters are: $" << balance << ", %" << intrate
       << ", and months " << term; }



void cdaccount::reportmature() {
  using namespace std;
  
  cout << "\n\nWhen your account matures in " << term << " months, it will"
       << "\nbe worth $"
       << (balance + (balance * (intrate/100) * (term / 12.0))); }



void cdaccount::reportbalance() {
  using namespace std;
  
  cout << "\n\nThe current balance in your CDA is: $" << balance; }



void cdaccount::reportintrate() {
  using namespace std;
  
  cout << "\n\nThe current interest rate on your CDA is: %" << intrate; }



void cdaccount::reportterm() {
  using namespace std;
  
  cout << "\n\nThe current term on your CDA is: " << term << " months"; }



void cdaccount::instream() {
  using namespace std;
  
  ifstream cdainp;
  char filename[21];
  int irepeat = 1;
  
  while (irepeat == 1) {
    cout << "\n\nPlease input file name, with a maximum size of 20 characters."
	 << "\nAlso, please ensure that the file contains readable data"
	 << "\n(three consecutive numbers for balance, interest rate, and term)"
	 << "\nFile Name: ";

    cin >> filename;



    cdainp.open(filename);

    if (cdainp.fail()) {
 cout << "\nInvalid file name. Please try again."; }

    else {
      cdainp >> balance;
      cdainp >> intrate;
      cdainp >> term;

      cout << "Finished. New account parameters are: $" << balance << ", %" << intrate
	   << ", months " << term;

      cdainp.close();
      
      irepeat = 0; } } }


    
void cdaccount::outstream() {
  using namespace std;
  
  ofstream cdaout;
  char filename[21];
  int orepeat = 1;

  while (orepeat == 1) {
    cout << "\n\nPlease input file name, with a maximum size of 20 characters."
	 << "\nPlease keep in mind that any other data in the target file will"
	 << "\nbe erased."
	 << "\nFile Name: ";

    cin >> filename;



    cdaout.open(filename);

    if (cdaout.fail()) {
      cout << "\nInvalid file name. Please try again."; }

    else {
      cdaout << "$"
	     << balance
	     << " %"
	     << intrate
	     << " months "
	     << term;

      cout << "\n\nFinished. File has been written to." ;

      cdaout.close();

      orepeat = 0; } } }
