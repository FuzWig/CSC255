/*
Andrew Chiang
2/05/2023
This program will sort numbers in two different algorithms
complexity
Input: txt file
Output: txt file 
Given: inX.txt in which X is 10 and 100
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int maxm;

void algo1(vector<int> , ofstream& );     
void algo2(vector<int> , ofstream& );     


int main()
{
    for(int m = 10 ; m <=100 ; m+=90 )              //for loops that reads 5 input files and print the results to corresponding 5 output file
    {
        int numbers;                        //stores the numbers read from input
        vector<int> numArray;               //appends numbers in a vector to be analyzed
        ifstream q1;                       //create object to read file
        ofstream q2;                       //create object to write on first file
        ofstream q3;                       //create object to write on second file

        q1.open("in" + to_string(m) + ".txt");             //open a file based on filename

        if (!q1) {                             //if file cant open for some reason return warning
        cerr << "Error opening File ";
        exit(EXIT_FAILURE);
        }

        q1 >> maxm;                 //read 1st line from file and stores it

        while(!q1.eof())             //keeps running until end of file and cycling through the numbers
        {
            q1 >> numbers;            //stores each number
            numArray.push_back(numbers);  //appends each number to vector
        }     

        q1.close();                     //close the file

        q2.open("out" + to_string(m) + "a.txt"); //open file based output

        algo1(numArray, q2);  //sorts vector in O(n)
 
        q2.close();   //close the file

        q3.open("out" + to_string(m) + "b.txt"); //open file based output
        
        algo2(numArray, q3);  //sorts vector in other sorting algo
        
        q3.close();   //close the file

    }

    return 0;
}


void algo1(vector<int> x, ofstream& q)
{
    int temparray[maxm] = { };  //creates a temp array to sort the vector with length of max value giving O(n)

    for(int i:x)         //runs through vector 
    {
        temparray[i] =  temparray[i]+1; //add 1 to the array element at the appropriate index. 
    }

    for(int j = 0; j < maxm; j++)         //looping the temp array giving O(K^2) where k is a constant
    {
        if(temparray[j]>0)               //only printing indexes that have values greater than 0
        {
            while(temparray[j] !=0)     //printing multiples of the same index position
            {
                q << j << " ";
                temparray[j] -= 1;
            }
        }
    }

    return;
}


void algo2(vector<int> x, ofstream& q)    //bubble sort with O(n^2) time complexity
{
    int size = x.size();                   //specify vector size
    
    for (int i = 0; i < size; i++)      //loop the bubble sort by the vector length
    {
        for (int j = 0; j < size - 1; j++)   //iterate through each element without going out of bounds
        {
            if (x[j] > x[j+1])           //if statement to swap elements if not in order
            {
                swap(x[j],x[j+1]);
            }
        }
    }

    for(int j :x)
    {
        q << j << " ";   //print the correctly ordered element
    }
    
    return;
}


