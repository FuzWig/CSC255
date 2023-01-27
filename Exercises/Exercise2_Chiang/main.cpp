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

void algo(vector<int> ,int, ofstream& );     
void bubble(vector<int> , ofstream& );     


int main()
{
    for(int m = 10 ; m <=100 ; m+=90 )         //for loops that reads 2 input files and print the results to corresponding 2 output file per
    {
        int k;
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

        q1 >> k;                 //read 1st line from file and stores it

        while(!q1.eof())             //keeps running until end of file and cycling through the numbers
        {
            q1 >> numbers;            //stores each number
            numArray.push_back(numbers);  //appends each number to vector
        }     

        q1.close();                     //close the file

        q2.open("out" + to_string(m) + "a.txt"); //open file based output

        algo(numArray, k, q2);  //sorts vector in O(n) and accepts max k
 
        q2.close();   //close the file

        q3.open("out" + to_string(m) + "b.txt"); //open file based output
        
        bubble(numArray, q3);  //sorts vector in other sorting algo
        
        q3.close();   //close the file

    }

    return 0;
}


void algo(vector<int> x, int k, ofstream& q)
{
    vector<int> temparray(k);  //creates a temp array with k length

    for(int i:x)         //runs through vector 
    {
        temparray[i] =  temparray[i]+1; //add 1 to the array element at the appropriate index with O(n) complexity
    }

    for(int j = 0; j <= k; j++)         //looping the temp array giving O(K^2) where k is a constant
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
}


void bubble(vector<int> x, ofstream& q)    //bubble sort with O(n^2) time complexity
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
}


