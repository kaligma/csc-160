//File Name: lesson04-373-10.cpp
//Author: Christopher Abelein
//Email: crabelein@gmail.com
//Assignment: 4
//Description: Program accepts name input from user and
//searches babynames2012.txt to report ranking for male
//and female babies.
//Last Modified: 02/10/17

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

void partsearch (string namefind);
void exactsearch (string namefind);

int main () {
  int repeat;
  char searchtype, name[21], reread;
  string buffer, namefind;
  const string valpartsearch = "pP";
  const string valexactsearch = "eE";
  const string valreread = "yY";
  const string valstop = "nN";

  repeat = 1;



  cout << "\nHello. This program is designed to search a list of the"
       << "\nmost popular baby names in 2012 and see if a name that you"
       << "\nenter is ranked amongst the 1000 most popular for boys and"
       << "\ngirls for that year.";



  while (repeat == 1) {
    cout << "\n\n\nYou have the choice of searching by part or exactly."
	 << "\nA part search will find anything that starts with what you"
	 << "\nhave typed. An exact search will find only what you have typed."
	 << "\nIndicate your choice by either p for part or e for exact.";
    
    while (true) {
      searchtype = 'x';
      cout << "\np/e: ";
      getline(cin, buffer);
      
      if (buffer.length() > 0) {
	searchtype = buffer[0]; }
      
      if (valpartsearch.find(searchtype) != string::npos) {
	cout << "\n\nYou have chosen to search by part.";
	break; }
      
      if (valexactsearch.find(searchtype) != string::npos) {
	cout << "\n\nYou have chosen to search for your exact entry.";
	break; }
      
      else {
	cout << "Invalid input. Please try again."; } }


    
    cout << "\n\n\nPlease enter a name. First letter capitalization is not required.";
    
    if (valpartsearch.find(searchtype) != string::npos) {  
      cout << "\nEntering part of a name will find all names that begin with those characters."
	   << "\nHowever, there is a minimum of 1 character.";

      while (true) {
	buffer = "";
	
	cout << "\nName: ";
	getline(cin, buffer);
	if (buffer.length() > 0) {
	  break; }
	cout << "\nPlease enter at least one character."; } }

    if (valexactsearch.find(searchtype) != string::npos) {
      while (true) {
	buffer = "";
	
	cout << "\nName: ";
	getline(cin, buffer);
	if (buffer.length() > 0) {
	    break; }
	cout << "\nPlease enter at least one character."; } }

    std::stringstream buffercheck;
    buffercheck << buffer;
    
    if (buffercheck >> name) {
      if (islower(name[0])) {
	name[0] = toupper(name[0]); }

      std::stringstream buffercheck;
      buffercheck << name;
      buffercheck >> namefind;
      

      
  if (valpartsearch.find(searchtype) != string::npos) {
    cout << "\n\n\nChecking the list for names that start with " << namefind << "...\n";
    partsearch(namefind); }
  //Precondition: User has entered the name part they wish to search for.
  //Postcondition: All names starting with the user's input printed on screen,
  //or a notification that the name part was not found.
  
  if (valexactsearch.find(searchtype) != string::npos) {
    cout << "\n\n\nChecking the list for the name " << namefind << "...\n";
    exactsearch(namefind); }
  //Precondition: User has entered the exact name they want.
  //Postcondition: All exact matches are printed on screen, or a notification
  //that the name is not on the list.
  
  cout << "\n\nThat is all.";
  
  
  
  while (true) {
    reread = ' ';
    buffer = "";
    
    cout << "\n\n\nWould you like to look for another name? y/n: ";
    getline(cin, buffer);
    
    if (buffer.length() > 0) {
      reread = buffer[0]; }
    
    if (valreread.find(reread) != string::npos) {
      cout << "\nRestarting...";
      break; }
    
    if (valstop.find(reread) != string::npos) {
      cout << "\nGoodbye.\n";
      repeat = 0;
      break; }
    
    else {
      cout << "\nInvalid response. Please try again."; } } } }



return 0; }




//Matches input and anything that starts with the input
void partsearch (string namefind) {
  string namereport, buffer;
  ifstream check;  
  char next, name[21];
  int line, namefeed, x, namefound;
  const char list[18] = "babynames2012.txt";  
  
  namefound = 0;
  check.open(list);
  
  if (check.fail()) {
    cout << "\nERROR: Failed to open babynames2012.txt for comparison."
	 << "\nPlease check that you have it, that it's name has not"
	 << "\nbeen altered, and that is is located in the same folder"
	 << "\nor directory as this program, then restart the program."
	 << "\n\n\nGoobye.\n";
    return void(); }
  
  
  
  while (!(check.eof())) {
    for (x = 0;x < 21;x++) {
      name[x] = ' '; }
    
    //Reads file line by line into a string
    getline(check, buffer);

    //If the string contains the user input
    if (buffer.find(namefind) != string::npos) {
      //Detects if the first four characters are digits. Reports ranking and sets where name is read from
      //accordingly for 1000th place, places 100-999, places 10-99, and places 1-9 respectively.
      if ((isdigit(buffer[0])) && (isdigit(buffer[1])) && (isdigit(buffer[2])) && (isdigit(buffer[3]))) {
	std::stringstream linecheck;
	linecheck << buffer[0] << buffer[1] << buffer[2] << buffer[3];
	linecheck >> line;
	namefeed = 5; }

      if ((isdigit(buffer[0])) && (isdigit(buffer[1])) && (isdigit(buffer[2])) && !(isdigit(buffer[3]))) {
	std::stringstream linecheck;
	linecheck << buffer[0] << buffer[1] << buffer[2];
	linecheck >> line;
	namefeed = 4; }

      if ((isdigit(buffer[0])) && (isdigit(buffer[1])) && !(isdigit(buffer[2])) && !(isdigit(buffer[3]))) {
	std::stringstream linecheck;
	linecheck << buffer[0] << buffer[1];
	linecheck >> line;
	namefeed = 3; }

      if ((isdigit(buffer[0])) && !(isdigit(buffer[1])) && !(isdigit(buffer[2])) && !(isdigit(buffer[3]))) {
	std::stringstream linecheck;
	linecheck << buffer[0];
	linecheck >> line;
        namefeed = 2; }

	//Feeds the male name into the name array to check for a match
	for (x = 0;x < 21;x++) {
	  next = buffer[namefeed];
	  namefeed++;
	    if (!(isalpha(next))) {
	      break; }
	  name[x] = next; }

	//Reports name if user input is detected in male name
	std::stringstream namecheck;
	namecheck << name;
	namecheck >> namereport;
	if (namereport.find(namefind) != string::npos) {
	  cout << "\n" << namereport << " is ranked " << line << " among boys.";
	  namefound = 1; }

	//Feeds the female name into the name array to check for a match
	for (x = 0;x < 21;x++) {
	  next = buffer[namefeed];
	  namefeed++;
	    if (!(isalpha(next))) {
	      break; }
	  name[x] = next; }

	//Reports name if user input is detected in female name
	namecheck << name;
	namecheck >> namereport;
	if (namereport.find(namefind) != string::npos) {
	  cout << "\n" << namereport << " is ranked " << line << " among girls.";
	  namefound = 1; } } }
      

  
  //Reports if user entry is not found on the list
  if (namefound == 0) {
    cout << "\n" << namefind << " was not found on the list of 1000 favorite"
	 << "\nbaby names of 2012."; }
  


  check.close();
  return void(); }




//Matches user's input exactly as entered
void exactsearch (string namefind) {
  ifstream check;  
  char next, name[21], line[5], namecheck[21];
  int namelength, nlc, l, spacecount, namefeed, x, nameappears;
  const char list[18] = "babynames2012.txt";

  check.open(list);
  
  if (check.fail()) {
    cout << "\nERROR: Failed to open babynames2012.txt for comparison."
	 << "\nPlease check that you have it, that it's name has not"
	 << "\nbeen altered, and that is is located in the same folder"
	 << "\nor directory as this program, then restart the program."
	 << "\n\n\nGoobye.\n";
    return void(); }

  //Variable initiation
  for (x = 0;x < 21;x++) {
    next = namefind[x];
    if (!(isalpha(next))) {
      break; }
    namecheck[x] = next; }
  
  namelength = 0;
  
  for (x = 0;x < 21;x++) {
    if (isalpha(namecheck[x])) {
      namelength++; }
    else {
      break; } }
  
  nameappears = 0;
  
  namefeed = 0;


  
  while (!(check.eof())) {
    //Clears name and line arrays for each line
    for (x = 0;x < 21;x++) {
      name[x] = ' '; }

    for (x = 0;x < 4;x++) {
      line[x] = ' '; }
    
    l = 0;
    spacecount = 0;
    namefeed = 0;
    
    do {
      //Reads file one character at a time
      check.get(next);

      //Loop exit at eof, also makes a final check to see if 1000th
      //placed female name matches input since other checks are tied
      //to detecting characters following names.
      if (check.eof()) {
	if (nlc == namelength) {
	  for (x = 0;x < namelength;) {
	    if (name[x] == namecheck[x]) {
	      x++; }
	    else {
	      break; } }
	  
	  if (x == namelength) {
	    cout << "\n" << namefind << " is ranked " << line << " among girls.";
	    nameappears = 1; } }

	for (x = 0;x < 21;x++) {
	  name[x] = ' '; }
	nlc = 0;
	namefeed = 0;
	break; }

      //Detects digits and feeds them into line array for report if a match is found
      if (isdigit(next)) {
	line[l] = next;
	l++; }

      //Feeds name from file into name array.
      if (isalpha(next)) {
	name[namefeed] = next;
	namefeed++; 
	nlc++; }

      //Count for spaces to determine if the name is male or female and
      //initializes check to see if the name array is a match to the
      //user entry.
      if (isspace(next)) {
	spacecount++;

	//Checks length of the name array against length of input,
	//if it matches it checks both arrays to see if they match
	if (nlc == namelength) {
	  for (x = 0;x < namelength;) {
	    if (name[x] == namecheck[x]) {
	      x++; }
	    else {
	      break; } }
	    
	    if ((x == namelength) && (spacecount == 2)) {
	      cout << "\n" << namefind << " is ranked " << line << " among boys.";
	      nameappears = 1; }
	    
	    if ((x == namelength) && (spacecount == 3)) {
	      cout << "\n" << namefind << " is ranked " << line << " among girls.";
	      nameappears = 1; } }

	  for (x = 0;x < 21;x++) {
	    name[x] = ' '; }
	  nlc = 0;
	  namefeed = 0; }
      
    } while (next != '\n'); }

  //If user input is not found in the list
  if (nameappears == 0) {
    cout << "\n" << namefind << " does not appear in the top 1000 most popular baby names of 2012 list."; }



  return void(); }
