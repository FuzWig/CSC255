/*
Andrew Chiang
02/26/2022
This program will read numbers from an input file, creates hash tables, inserts the numbers into
and retrieves them from the hash tables, and outputs counts of collisions for linear probing, quadratic
probing, and double hashing probing under several scenarios
Input: txt file
Output: txt file 
Given: inX.txt in which X is 150,160,170
*/

#include <iostream>
#include "Driver.h"

int main()
{
    Driver execute;       //object to access the driver class

    for(int i = 150; i <=180; i+=10)   //test all files
    {
        execute.testFile("in" + to_string(i) + ".txt", "out" + to_string(i) + "_collisions.txt","out" + to_string(i) + "_tables.txt" );
    }

    return 0;
}
