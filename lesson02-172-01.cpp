//File Name: lesson02-172-01.cpp
//Author: Christopher Abelein
//Email Address: crabelein@gmail.com
//Assignment Number: 2
//Description: Create a repeatable two player rock-paper-scissors game.
//Last Changed: January 24, 2017

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
  string player1, player2, playbuffer, replaybuffer;
  char p1choice, p2choice, replay;
  int repeat, p1w, p2w, draw;
  const string valplay = "rRsSpP";
  const string valreplay = "yY";
  const string valstop = "nN";

  //Setting initial game state
  repeat = 1;
  p1w = 0;
  p2w = 0;
  draw = 0;
  
  cout << "\nHello. This is a game of Rock-Paper-Scissors designed for two players.\n";
  cout << "\nPlayer one, please enter your name: ";
  //Allows players to input names with spaces if they want, without
  //falling through.
  getline (cin, player1);
  cout << "\nPlayer two, please enter your name: ";
  getline (cin, player2);
  
  cout << "\nAlright " << player1 << " and " << player2 << ", here are the rules.\n";
  cout << player1 << " will be prompted to pick first and then " << player2 << ", no peaking.\n";
  cout << "You pick with r, p, and s representing rock, paper, and scissors respectively.\n";
  cout << "Rock beats scissors, scissors beats paper, paper beats rock.\n";
  cout << "If you pick the same thing, it's a draw.\n";
  cout << "Lets get started.\n\n\n\n";


  
  /*
  Player 1 chooses. I had a hard time figuring out how to stop
  player responses from falling through to the next input. This
  setup filters the input through a string variable and takes
  the first letter of the string and compares it to a constant
  string containing valid player choices, so only the first letter
  input gets considered, the rest are essentially tossed out.
  */
  while (repeat == 1) {
    //Reseting player choice variables to avoid infinite loop
    p1choice = 'x';
    p2choice = 'x';
    replay = 'x';
    
    cout << player1 << ", make your choice: ";
      
    while (valplay.find(p1choice) == string::npos) {
      playbuffer = 'x';
      cin >> playbuffer;
      
      cout << "\n";
      
      if (playbuffer.length() > 0) {
	p1choice = playbuffer[0]; }
      
      if (valplay.find(p1choice) != string::npos) {
	break; }
      
      else {
	cout << "Invalid play. Please try again: "; } }
    

    //Player 2 chooses. Same filtering setup.
    cout << player2 << ", make your choice: ";
    
    while (valplay.find(p2choice) == string::npos) {
      playbuffer = 'x';
      cin >> playbuffer;
      
      cout << "\n";
      
      if (playbuffer.length() > 0) {
	p2choice = playbuffer[0]; }
      
      if (valplay.find(p2choice) != string::npos) {
	break; }
      
      else {
	cout << "Invalid play. Please try again: "; } }


    
    //If player 1 wins, increment their win variable and display current score.    
    if (((p1choice == 'r' || p1choice == 'R') && (p2choice == 's' || p2choice == 'S'))
     || ((p1choice == 's' || p1choice == 'S') && (p2choice == 'p' || p2choice == 'P'))
     || ((p1choice == 'p' || p1choice == 'P') && (p2choice == 'r' || p2choice == 'R'))) {
      p1w++;
      cout << "\nThe winner is....\n";
      cout << player1 << "!!!!!\n";
      cout << "The current score\n";
      cout << player1 << ": " << p1w << "\n";
      cout << player2 << ": " << p2w << "\n";
      cout << "draws: " << draw << "\n\n";
      
      cout << "Would you like to play again? y/n: ";

      //Similar string filtering setup so responses here don't bleed through
      //to the player choices if the players choose to play again.
      while ((valreplay.find(replay) == string::npos) && (valstop.find(replay) == string::npos)) {
	cin >> replaybuffer;
	
	if (replaybuffer.length() > 0)
	  replay = replaybuffer[0];
	
	if (valreplay.find(replay) != string::npos) {
	  cout << "\nAnother Round then.\n\n";
	  break; }
	
	if (valstop.find(replay) != string::npos) {
	  repeat = 0;
	  cout << "\nGoodbye.\n";
	  break; }
	
	else
	  cout << "\n";
	  cout << "Invalid response. Please try again. y/n:"; } }


    
    //If player 2 wins, increment their win variable and display score.
    if (((p2choice == 'r' || p2choice == 'R') && (p1choice == 's' || p1choice == 'S'))
     || ((p2choice == 's' || p2choice == 'S') && (p1choice == 'p' || p1choice == 'P'))
     || ((p2choice == 'p' || p2choice == 'P') && (p1choice == 'r' || p1choice == 'R'))) {
      p2w++;
      cout << "\nThe winner is....\n";
      cout << player2 << "!!!!!\n";
      cout << "The current score\n";
      cout << player1 << ": " << p1w << "\n";
      cout << player2 << ": " << p2w << "\n";
      cout << "draws: " << draw << "\n\n";

      cout << "Would you like to play again? y/n: ";
      
      while ((valreplay.find(replay) == string::npos) && (valstop.find(replay) == string::npos)) {
	cin >> replaybuffer;
	
	if (replaybuffer.length() > 0)
	  replay = replaybuffer[0];
	
	if (valreplay.find(replay) != string::npos) {
	  cout << "\nAnother round then.\n\n";
	  break; }
	
	if (valstop.find(replay) != string::npos) {
	  repeat = 0;
	  break; }
	
	else {
	  cout << "\n";
	  cout << "Invalid response. Please try again. y/n: "; } } }
    

    
    //If there is a draw, increment draw count and display score.
    if (((p1choice == 'r' || p1choice == 'R') && (p2choice == 'r' || p2choice == 'R'))
     || ((p1choice == 's' || p1choice == 'S') && (p2choice == 's' || p2choice == 'S'))
     || ((p1choice == 'p' || p1choice == 'P') && (p2choice == 'p' || p2choice == 'P'))) {
      draw++;
      cout << "\nThe winner is....\n";
      cout << "Nobody!!!!!\n";
      cout << "The current score\n";
      cout << player1 << ": " << p1w << "\n";
      cout << player2 << ": " << p2w << "\n";
      cout << "draws: " << draw << "\n\n";
      
      cout << "Would you like to play again? y/n: ";
      
      while ((valreplay.find(replay) == string::npos) && (valstop.find(replay) == string::npos)) {
	cin >> replaybuffer;
	
	if (replaybuffer.length() > 0) {
	  replay = replaybuffer[0]; }
	
	if (valreplay.find(replay) != string::npos) {
	  cout << "\nAnother round then.\n\n";
	  break; }
	
	if (valstop.find(replay) != string::npos) {
	  repeat = 0;
	  cout << "\nGoodbye.\n";
	  break; }
	
	else {
	  cout << "\n";
	  cout << "Invalid response. Please try again. y/n: "; } } } } }

/*
This assignment took me the longest, because it was important to ne to fix
the multi-character input fall through. I spent about 4 hours trying to
figure it out, experimenting with cin.get, cin.ignore, and getch, but
none of that functioned exactly the way I wanted it too. I ended up asking
my cousin what he would use, and he pointed me to the string filtering
commands. I changed how I set up conditions and their arguments, I think
this is a lot nicer to look at and work with than spacing out everything
so much, since it gets hard to fit an entire condition on one page. I
put three new lines between larger scale conditions that are very different, and a single
new line between each smaller argument and to break up different input/output sets
that are refering to different things.
*/
