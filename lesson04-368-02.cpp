//File Name: lesson04-368-02.cpp
//Author: Christopher Abelein
//Email: crabelein@gmail.com
//Assignment: 4
//Description: Program must report arithmetic mean and number of values
//from a file
//Last Modified: 02/10/17

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main () {
  ifstream instrm;
  int filenameok, count, repeat;
  char filename[16], rerun;
  double sum, next, average;
  string buffer;
  const string valrerun = "yY";
  const string valstop = "nN";
  
  repeat = 1;
  
  
  
  cout << "\nHello. This program is designed to take a list of numbers"
       << "\nfrom a file, then count them and calculate their arithmetic mean"
       << "\nfor you.";
  
  
  
  while (repeat == 1) {
    cout << "\n\n\nPlease input the file name. There is a 15 character maximum."
	 << "\nFile Name: ";
    
    do {
      filenameok = 1;
      
      cin >> filename;
      
      cout << "\n\nReading from file " << filename << "...";
      
      instrm.open(filename);
      if (instrm.fail()) {
	cout << "\nInput file opening failed."
	     << "\nPlease try again: ";
	filenameok = 0; }
    } while (filenameok == 0);
    
    
    
    sum = 0;
    count = 0;
    //I tried to write this as different loops with != instrm.eof() as the
    //condition, but it always iterated once too many times because it would
    //take one iteration to find the eof marker.
    while (true) {
      next = 0;
      instrm >> next;
      
      if (instrm.eof()) {
	break; }
      
      sum = sum + next;
      count ++; }
    
    average = sum / count;
    
    instrm.close();
    
    cout << "\n\n\nThere were " << count << " numbers in " << filename
	 << "\nand their arithmetic average is " << average;


    cin.ignore();
    while (true) {
      buffer = "";
      
      cout << "\n\n\nWould you like to run this program on a different file? y/n: ";
      getline(cin, buffer);

      if (buffer.length() > 0) {
	rerun = buffer[0]; }

      if (valrerun.find(rerun) != string::npos) {
	cout << "\n\n\nRestarting...";
	break; }

      if (valstop.find(rerun) != string::npos) {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }

      else {
	cout << "\nInvalid response, please try again."; } } }



  return 0; }
