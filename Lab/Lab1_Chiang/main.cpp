/*
Andrew Chiang
1/29/2022
This program will contain an O(N*log(N)) algorithm to sort number and search for numbers in O(N) and repeat same task as EX1.
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

void sumofK(vector<int> ,vector<int>, int, ofstream& );     
void heapify(vector<int>& , int, int );
void sort(vector<int>&);

int main()
{
    for(int m = 1 ; m <=5 ; m++ )              //for loops that reads 5 input files and print the results to corresponding 5 output file
    {
        string filename = "in";             //stores the name of the input file
        string output = "out";              //stores the name of output file
        int numbers;                        //stores the numbers read from input
        vector<int> numArray;               //appends numbers in a vector to be analyzed
        vector<int> copyArray;
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
            q1 >> numbers;                 //stores each number
            numArray.push_back(numbers);  //appends each number to vector
        }     

        q1.close();                     //close the file

        for(int x:numArray)
        {
            copyArray.push_back(x);
        }

        output += to_string(m);
        output += ".txt";


        sort(numArray);                //sort with O(nlog(n)) time complexity


        q2.open(output); //open file based output

        sumofK(numArray,copyArray,target, q2);  //this find whether or not there is 2 numbers that equal target
 
        q2.close();   //close the file

    }

    return 0;
}


void sumofK(vector<int> x,vector<int> copy, int y, ofstream& q)
{
    q << target << endl;                 //writes text and target value into output file
    q << "Before Sorting" <<endl;
    q << text << endl;

    for(int p:copy)    //writes the numbers from the input file
    {
        q << p << " ";
    }

    q << "\nAfter Sorting" <<endl;
    q << text << endl;

    for(int o:x)    //writes the numbers from the input file
    {
        q << o << " ";
    }

    int num1 = 0;
    int num2 = x.size()-1;

    while(num2 >=0 && num1<= (x.size()-1))          //while loop with O(n) time complexity that ensures both num variable are with the vector
    {
        if(x[num1]*2 == y)                        //check if number can be duplicated
        {
            q << "\nCalculation O(N) in Lab1 after sorting" << endl;
            q << "Yes, there are two numbers that add up to target" << endl;
            q << x[num1] << " + " << x[num1] << " = " << x[num1]+x[num1] << endl;
            return;
        }
        if(x[num2]*2 == y)                      //check if number can be duplicated
        {
            q << "\nCalculation O(N) in Lab1 after sorting" << endl;
            q << "Yes, there are two numbers that add up to target" << endl;
            q << x[num2] << " + " << x[num2] << " = " << x[num2]+x[num2] << endl;
            return;
        }
        if(x[num1] + x[num2] == y )                 //check first if both numbers equal to target
        {
            q << "\nCalculation O(N) in Lab1 after sorting" << endl;
            q << "Yes, there are two numbers that add up to target" << endl;
            q << x[num1] << " + " << x[num2] << " = " << x[num1]+x[num2] << endl;
            return;
        }
        if(x[num1] + x[num2] > y){   //check if both numbers are greater than target, so shift num2 left
        num2--;
        }
        if(x[num1] + x[num2] < y){    //check if both numbers are greater than target, so shift num1 right
        num1++; 
        }
    }

    q << "\nCalculation O(N) in Lab1 after sorting" << endl;              //if no numbers are found then we output the text below here
    q << "No, there are no two numbers that add up to target" << endl;
    return;
}


void heapify(vector<int> &vec, int len, int i) 
{
    int max = i;           //store the max value
    int left = (2*i) + 1;   //this is the left child
    int right = (2*i) + 2;   //this is the right child

    if (left<len && vec[left] > vec[max])      //if left child is larger than max and within the vector size, we swap indexes
    {
        max = left;
    }

    if (right<len && vec[right] > vec[max]) //if right child is larger than max and within the vector size, we swap indexes
    {
        max = right;
    }
    if (max != i)                 //if max doesn't equal root we make the following changes
    {
        int temp = vec[i];    //store the parent node value
        vec[i] = vec[max];    //swap the values between parent and child node
        vec[max] = temp;      
        heapify(vec, len, max);  //recursive 
    }
}


void sort(vector<int> &vec)
{
    int len = vec.size();             //store the length of the vector

    for (int i = (len/2)-1; i >= 0; i--)        //building the max heap by starting and looking at each parent and child node
    {
        heapify(vec, len, i);
    }

    for (int i = len-1; i >= 0; i--){            //we decrement the heap size and leave the sorted numbers alone

        int temp = vec[0];    //store the root or max value
        vec[0] = vec[i];      //replace the root with the last value from the heap
        vec[i] = temp;       //place the max value at h

        heapify(vec, i, 0);     
    }
}