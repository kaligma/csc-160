//File Name: lesson04-369-05.cpp
//Author: Christopher Abelein
//Email: crabelein@gmail.com
//Assignment: 4
//Description: Program must read current text of hw4pr02input.txt, then
//prompt user for text. Prompt must allow for multiple lines and not ignore
//white space.
//Last Modified: 02/10/17

#include <iostream>
#include <fstream>
#include <string>

int main () {
  using namespace std;

  int filenameok, repeat;
  char filename[16], next, lastnext, writecheck, reread;
  ifstream read;
  ofstream write;
  string buffer;
  const string valreread = "yY";
  const string valstop = "nN";

  repeat = 1;



  cout << "\nHello. This program is designed to read a file, and"
       << "\nthen allow you to write over that file.";


    
  while (repeat == 1) {
    cout << "\n\n\nPlease input a file name. The maximum number"
	 << "\nof characters in the name is 15.";
    //Loop to make sure file name entered is valid. Runs at least once.
    do {
      filenameok = 1;
      
      cout << "\nFile Name: ";
      cin >> filename;
      cout << "\nReading from " << filename << "...";
      read.open(filename);
      
      if (read.fail()) {
	filenameok = 0;
	cout << "\nFailed to open target file. Please try again."; }
    } while (filenameok == 0);


    //Reads and prints file contents character by character until EOF is detected.
    cout << "\n\nFile Contents:\n\n";
    while (true) {
      read.get(next);

      if (read.eof()) {
	cout << "\n\nEnd of File.";
	read.close();
	break; }

      cout << next; }


    
    write.open(filename);
    cout << "\n\n\nPlease type what you would like to replace the text"
	 << "\nin the file. Pressing return twice or once before entering"
	 << "\nother text will close the file.\n\n";
    writecheck = '\n';
    lastnext = '\n';
    cin.ignore();
    //Writes file character by character, unless a newline
    //character is the first entered or until two newline characters
    //are entered in succession.
    while (true) {
      cin.get(next);

      if ((next == lastnext) && (next == writecheck)) {
	cout << "\n\n\nWriting to " << filename << "...";
	write.close();
	cout << "\nFinished.";
	break; }

      write << next;
      lastnext = next; }



    cout << "\n\n";
    while (true) {
      reread = ' ';
      buffer = "";
      
      cout << "\nWould you like to read and write another file? y/n: ";
      getline(cin, buffer);
      if (buffer.length() > 0) {
	reread = buffer[0]; }

      if (valreread.find(reread) != string::npos) {
	cout << "\n\n\nRestarting...";
	break; }

      if (valstop.find(reread) != string::npos) {
	cout << "\n\n\nGoodbye.\n";
	repeat = 0;
	break; }

      else {
	cout << "\nInvalid response. Please try again."; } } }



  return 0; }
