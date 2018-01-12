//File Name: lesson05-617-11.cpp
//Author: Christopher Abelein
//Email: crabelein@gmail.com
//Assignment: 6
//Description: Implement class Movie that can hold and format movie data.
//Seven private member variables. Output movie name, MPAA rating, and average
//rating. Public accessors and mutators getname(), setname(), setrating(),
//getrating(), addrating(), and getaverage().
//Last Modified: 02/23/17

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class movie {
public:
  movie();
  //Precondition: movie variable undeclared.
  //Postcondition: movie variable declared and initialized with
  //name = Empty, rating = None, terrible = 0, bad = 0, ok = 0,
  //good = 0, great = 0

  movie(string& newname, string& newmrat);
  //Precondition: movie variable undeclared.
  //Postcondition: movie variavle declared and initialized
  //with name = newname, rating = newmrat, terrible = 0, bad = 0,
  //ok = 0, good = 0, great = 0;
  
  void getinfo();
  //Precondition: movie variable initialized
  //Postcondition: displays movie variables name, rating,
  //terrible, bad, ok, good, and great in the terminal.

  void setname();
  //Precondition: movie variable declared
  //Postcondition: movie variable name set to user input(any)

  void setrating();
  //Precondition: movie variable declared
  //Postcondition: movie variable rating set to user input(G, PG, PG-13, R)

  void getrating();
  //Precondition: movie variable rating initialized
  //Postcondition: movie variable rating displayed in terminal
  
  void addrating();
  //Precondition: movie variable declared
  //Postcondition: movie variables terrible, bad, ok, good, or great
  //incremented by user input (integer)
  
  void clearrating();
  //Precondition: movie variable declared
  //Postcondition: movie varaibles terrible, bad, ok, good, and great
  //set to 0

  void getaverage();
  //Precondition: movie varaibles terrible, bad, ok, good,
  //and great initialized
  //Postcondition: average score displayed in terminal

  void getname();
  //Precondition: movie variable initialized
  //Postcondition: movie variable name displayed in terminal

  void autoinfo1();
  //Precondition: movie variable declared
  //Postcondition: movie variables terrible = 5,
  //bad = 4, ok = 7, good = 9, great = 8

  void autoinfo2();
  //Precondition: movie variable declared
  //Postcondition: movie varriables initialized with
  //name = Groundhog Day, rating = PG-13, terrible = 1
  //bad = 3, ok = 7, good = 21, great = 42
  
private:
  string name, rating;

  int terrible, bad, ok, good, great; };

void submenu(movie& slot);
//Precondition: movie variable initialized
//Postcondition: movie variable variables changed according to user
//selections in function



int main() {
  cout << "\nHello. This program is designed to allow the user to"
       << "\nstore information about movies in a programmer-created"
       << "\nclass. The class stores the movie's name, MPAA rating,"
       << "\nand viewer ratings on a 1-5 scale where 1 is terrible"
       << "\nand 5 is great. This program can store information for"
       << "\nup to 5 movies. Two will automatically be generated.";

  char stop;
  string buffer, newname = "John Dies at the End", newmrat = "R";
  int newrat, main = 1, slot;
  const string validslot = "123456";
  movie mov1, mov2, mov3, mov4(newname, newmrat), mov5;
			       
  mov4.autoinfo1();
  mov5.autoinfo2();

  mov4.getname();
  mov4.getrating();
  mov4.getaverage();

  mov5.getname();
  mov5.getrating();
  mov5.getaverage();

  cout << "\n\nPress any key then return to continue.";
  cin >> stop;



  cin.ignore();
  
  while (main == 1) {
    cout << "\n\nStored Movies:"
	 << "\n1. ";
    mov1.getinfo();
    cout << "\n"
	 << "\n2. ";
    mov2.getinfo();
    cout << "\n"
	 << "\n3. ";
    mov3.getinfo();
    cout << "\n"
	 << "\n4. ";
    mov4.getinfo();
    cout << "\n"
	 << "\n5. ";
    mov5.getinfo();
    cout << "\n"
	 << "\n6. Quit"
	 << "\n\nWhich movie information would you like to alter: ";

    getline(cin, buffer);

    if (buffer.length() > 0) {
      buffer = buffer[0]; }
    
    std::stringstream buffercheck;

    buffercheck << buffer;

    if (buffercheck >> slot) {
      if (slot >= 1 && slot <= 6) {
	if (slot >=1 && slot <=5) {
	  cout << "\nMovie " << slot << " selected."; }

	switch (slot) {
	case 1:
	  submenu(mov1);

	  break;

	case 2:
	  submenu(mov2);

	  break;

	case 3:
	  submenu(mov3);

	  break;

	case 4:
	  submenu(mov4);

	  break;

	case 5:
	  submenu(mov5);

	  break;

	case 6:
	  cout << "\n\n\nGoodbye.\n";

	  return 0;  } }

      else {
	cout << "\nInvalid selection. Please try again."; } }

    else {
      cout << "\nInvalid selection. Please try again."; } }
  
  return 0; }





movie::movie() {
  name = "Empty";
  rating = "None";
  terrible = 0;
  bad = 0;
  ok = 0;
  good = 0;
  great = 0; }



movie::movie(string& newname, string& newmrat) {
  name = newname;
  rating = newmrat;
  terrible = 0;
  bad = 0;
  ok = 0;
  good = 0;
  great = 0; }



void movie::getinfo() {
  cout << "Movie Name: " << name << " | MPAA Rating: " << rating
       << "\nTerrible: " << terrible << " | Bad: " << bad << " | Ok: " << ok << " | Good: " << good << " | Great: " << great; }



void movie::setname() {
  cout << "\nPlease set the movie's name: ";
  getline(cin, name);

  cout << "\nMovie name set to: " << name; }



void movie::setrating() {
  string buffer;


  
  cout << "\nPlease set the movie's MPAA Rating."
       << "\n(G, PG, PG-13, R): ";
  
  while (true) {
    buffer = "";
    getline(cin, buffer);

    if (buffer == "G" || buffer == "PG" || buffer == "PG-13" || buffer == "R") {
      rating = buffer;

      cout << "\nMPAA rating set to " << rating;
      
      break; }

    else {
      cout << "Invalid response. Please enter a MPAA Rating."
	   << "\n(G, PG, PG-13, R): "; } } }
    


void movie::getrating() {
  cout << "\nMovie rating is " << rating; }

void movie::addrating() {
  int choice, add;
  string buffer;
  const string valchoice;


  
  cout << "\nMovie " << name << " currently has the following ratings."
       << "\n1. Terrible: " << terrible
       << "\n2. Bad: " << bad
       << "\n3. Ok: " << ok
       << "\n4. Good: " << good
       << "\n5. Great: " << great
       << "\nWhich rating would you like to add to: ";

  getline(cin, buffer);

  if (buffer.length() > 0) {
    buffer = buffer[0]; }

  std::stringstream buffercheck;

  buffercheck << buffer;

  if (buffercheck >> choice) {
    switch (choice) {
    case 1:
      cout << "\nHow many would you like to add to the Terrible rating: ";
      cin >> add;
      terrible = terrible + add;

      break;

    case 2:
      cout << "\nHow many would you like to add to the Bad rating: ";
      cin >> add;
      bad = bad + add;

      break;

    case 3:
      cout << "\nHow many would you like to add to the Ok rating: ";
      cin >> add;
      ok = ok + add;

      break;

    case 4:
      cout << "\nHow many would you like to add to the Good rating: ";
      cin >> add;
      good = good + add;

      break;

    case 5:
      cout << "\nHow many would you like to add to the Great rating: ";
      cin >> add;
      great = great + add;

      break;

    default:
      break; } }

  else {
    cout << "\nInvalid response. Returning to submenu."; } }


void movie::clearrating() {
  terrible = 0;
  bad = 0;
  ok = 0;
  good = 0;
  great = 0;

  cout << "\nViewer ratings reset."; }



void movie::getaverage() {
  double sum, average;

  sum = (1 * terrible) + (2 * bad) + (3 * ok) + (4 * good) + (5 * great);
  average = sum / (terrible + bad + ok + good + great);

  cout << "\nThe average viewer rating of " << name << " is " << average; }

void movie::getname() {
  cout << "\n\nMovie name is " << name; }



void movie::autoinfo1() {
  terrible = 5;
  bad = 4;
  ok = 7;
  good = 9;
  great = 8; }



void movie::autoinfo2() {
  name = "Groundhog Day";
  rating = "PG-13";
  terrible = 1;
  bad = 3;
  ok = 7;
  good = 21;
  great = 42; }



void submenu(movie& slot) {
  int sub = 1, choice;
  string buffer, newname, newmrat;


  
  while (sub == 1) {
    cout << "\n\nWhat would you like to alter about this movie?"
	 << "\n";
    slot.getinfo();

    cout << "\n1. Change the name"
	 << "\n2. Change the MPAA rating"
	 << "\n3. Add viewer ratings"
	 << "\n4. Clear viewer ratings"
	 << "\n5. Compute the average viewer rating"
	 << "\n6. Return to the main menu"
	 << "\nSelection: ";
    
    getline(cin, buffer);

    if (buffer.length() > 0) {
      buffer = buffer[0]; }

    std::stringstream buffercheck;

    buffercheck << buffer;

    if (buffercheck >> choice) {
      switch (choice) {
      case 1:
	slot.setname();
	
	break;

      case 2:
	slot.setrating();

	break;

      case 3:
	slot.addrating();

	break;

      case 4:
	slot.clearrating();

	break;

      case 5:
	slot.getaverage();

	break;

      case 6:
	cout << "\nReturning to main menu.";

	sub = 0;

	return void(); } }

    else {
      cout << "\nInvalid response. Please try again."; } } }
