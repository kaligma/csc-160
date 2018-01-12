//File Name: lesson02-173-05.cpp
//Author: Christopher Abelein
//Email Address: crabelein@gmail.com
//Assignment: 2
//Description: Write a program that prints all prime numbers from 3 to 100
//Last Modified: January 25, 2017

#include <iostream>
#include <math.h>
using namespace std;

int main () {
  /*
    The count variable increments from 3 to 100 for both the counting
    loop and the number being checked. The divide variable is what
    checks the divisibility of count. It resets to 2 every time a
    number is done being checked and increments up to (count - 1).
    The check variable stores the remainders of (count / divide).
    The prime number is a true/false check that determines if a
    number is going to be output. prntn is a variable that keeps
    the numbers output from the program in a more easily read
    format.
  */
  int count, divide, check, prime, prntn;
  
  //Setting initial conditions
  count = 3;
  prntn = 0;
  
  cout << "\nHello. This program will now tell you all of the prime numbers from 3 to 100.\n";
  
  
  
  //Counting loop
  while (count <= 100) {
    prime = 1;
    divide = 2;

    //Dividing loop
    while (divide < count) {
      /*
      Returns remainders, if remainder is zero then
      it's an even division. This sets prime to not
      true and ends the loop. If no even division
      is detected, the loop completes with the
      prime variable still being true.
      */
      check = count % divide;

      if (check == 0) {
	prime = 0;
	break; }	 		  
      
      else {
	divide++; } }

    

    /*
    The outputs, I set up a variable to break up the
    information into 5 numbers per line.
    */
    if ((prime == 1) && (prntn < 5)) {
      cout << count << ", ";
      prntn ++;
      count ++; }
    
    else if ((prime == 1) && (prntn = 5)) {
      cout << "\n" << count << ", ";
      prntn = 1;
      count ++; }
    
    else if (prime == 0) {
      count++; } }
  
  cout << "\nThat is all.\n";
  return 0; }
