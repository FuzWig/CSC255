/*
Andrew Chiang
03/12/2023
This program implements heap class and test the heap inserts and deletes
Input: txt file
Output: txt file 
Given: inX.txt in which X is 1,2,3,4
*/

#include <iostream>
#include "driver.h"

using namespace std;

int main()
{
  string suffix;                            //temp storage of file name
  
  for( int i=1; i<5; i++ )
    {
      Driver execute;                             //object to access the driver class, which resets after each for loop cycle
      suffix = to_string(i)+".txt";
      execute.process( "in"+suffix, "out"+suffix );
    }
    return 0;
}


