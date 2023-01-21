/*
Andrew Chiang
1/22/2023
This program will determine if there are two numbers whose sum equals the given “target” number K
Input: txt file
Output: txt file 
Given: inX.txt in which X is 1,2,3,4,5
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string text;                                //global variables that store the text and target number
int target;

void sumofK(vector<int> , int, ofstream& );     

int main()
{
    for(int m = 1 ; m <=5 ; m++ )              //for loops that reads 5 input files and print the results to corresponding 5 output file
    {
        string filename = "in";             //stores the name of the input file
        string output = "out";              //stores the name of output file
        int numbers;                        //stores the numbers read from input
        vector<int> numArray;               //appends numbers in a vector to be analyzed
        ifstream q1;                       //create object to read file
        ofstream q2;                       //create object to write on file

        filename += to_string(m);
        filename += ".txt";
        q1.open(filename);             //open a file based on filename

        if (!q1) {                             //if file cant open for some reason return warning
        cerr << "Error opening File ";
        exit(EXIT_FAILURE);
        }

        q1 >> text;                   //read 1st line from file and stores it
        q1 >> target;                 //read 2nd line from file and stores it

        while(!q1.eof())             //keeps running until end of file and cycling through the numbers
        {
            q1 >> numbers;            //stores each number
            numArray.push_back(numbers);  //appends each number to vector
        }     

        q1.close();                     //close the file

        output += to_string(m);
        output += ".txt";

        q2.open(output); //open file based output

        sumofK(numArray,target, q2);  //this find whether or not there is 2 numbers that equal target
 
        q2.close();   //close the file

    }

    return 0;
}


void sumofK(vector<int> x, int y, ofstream& q)
{
    q << target<< endl;                 //writes text and target value into output file
    q << text << endl;

    for(int p = 0; p< x.size(); p++)    //writes the numbers from the input file
    {
        q << x[p] << " ";
    }

    for(int i = 0 ; i < x.size()-1; i++)  //outer for loop starts at the first element in the vector
    {
        for(int j = i; j < x.size(); j++) //inner for loop also starts at the first element in the vector to check if duplicate equal target
        {
            if(x[j]*2 == y) //check if last element can be duplicated
            {
                q << "\nExercise1 calculation complexity O(n^2)" << endl;
                q << "Yes, there are two numbers that add up to target" << endl;
                q << x[j] << " + " << x[j] << " = " << x[j]+x[j] << endl;
                return;
            }
            if(x[i] + x[j] == y) //if two numbers euqal target then we return and print out the given text below
            {
                q << "\nExercise1 calculation complexity O(n^2)" << endl;
                q << "Yes, there are two numbers that add up to target" << endl;
                q << x[i] << " + " << x[j] << " = " << x[i]+x[j] << endl;
                return;
            }
        }
    }
    q << "\nExercise1 calculation complexity O(n^2)" << endl;              //if no numbers are found then we output the text below here
    q << "No, there are no two numbers that add up to target" << endl;
    return;
}
