/*
Andrew Chiang
2/12/2023
This program will sorts words in O(n) complexity, where n is the number of words in the input file (not counting the first word that has special meaning described below)
Input: txt file
Output: txt file 
Given: inX.txt in which X is 10 and 100
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int converter(string);
void algo(vector<int>, vector<string>, int, ofstream& );     
void bubble(vector<int>, vector<string>, ofstream& );     


int main()
{
    for(int m = 10 ; m <=100 ; m+=90 )              //for loops that reads 5 input files and print the results to corresponding 5 output file
    {
        string word;                        //stores the numbers read from input
        string maxer;
        int  k;

        vector<string> strArray;               //appends words to vector to be analyzed
        vector<int> intArray;               //appends encoded words to a vector to be analyzed

        ifstream q1;                       //create object to read file
        ofstream q2;                       //create object to write on first file
        ofstream q3;                       //create object to write on second file

        q1.open("in_abc" + to_string(m) + ".txt");             //open a file based on filename

        if (!q1) {                             //if file cant open for some reason return warning
        cerr << "Error opening File ";
        exit(EXIT_FAILURE);
        }

        q1.ignore(9999,' ');                 //ignores maxValue=

        q1 >> maxer;                      //records the maxword

        k = converter(maxer);       //converts word to number

        vector<string> diction(k+1);  //creates a "dictionary" to store the words with corresponding index/key.

        while(!q1.eof())             //keeps running until end of file and cycling through the numbers
        {
            q1 >> word;            //stores each word

            for(int d = 0; d<word.length(); d++)   //coverts words to lowercase
            {
                word[d] = tolower(word[d]);
            }
            
            strArray.push_back(word);            //inserts the lowercase words into vector
            intArray.push_back(converter(word)); //inserts the encoded words into vector
        }
    
        for(string i:strArray)         //runs through vector 
        {
            diction[converter(i)] =  i; //this acts as a dictionary to correspond index to word with O(n) complexity
        }

        q1.close();                     //close the file

        q2.open("out_abc" + to_string(m) + "a.txt"); //open file based output

        algo(intArray, diction, k, q2);  //sorts vector in O(n) by passing the unsorted arry and the dictionary
 
        q2.close();   //close the file

        // q3.open("out_abc" + to_string(m) + "b.txt"); //open file based output
        
        // bubble(intArray, diction, q3);  //sorts vector in other sorting algo
        
        // q3.close();   //close the file
    }

    return 0;
}


int converter(string word)                       //takes string and converts to word
{
    int result = 0;   
    int num;                                    //stores the ascii converter character
    int exponent;                               //determines how to append the numbers

    for(int i = 0; i<word.length();i++)          //iterates all characters in the word
    {
        char ch = word[i];              
        num = (((int) ch) - 96);                 //converts the words to numbers between 1-26
        
        if(word.length() == 1)                   //for 1 character words
        {
            return num * 10000;
        }

        else if(word.length() == 2)             //for 2 character words
        {
            result = result * pow(10,2) + (((int) ch) - 96);
            exponent = 2;
        }

        else                                    //for 3 character words
        {
            result = result * pow(10,2) + (((int) ch) - 96);
            exponent = 0;
        }
    }

    return result*pow(10,exponent);       
}

void algo(vector<int> x, vector<string>dictions, int k, ofstream& q)
{
    vector<int> temparray(k+1);  //creates a temp array with k+1 length to consider max value as an element too

    for(int i:x)         //runs through vector 
    {
        temparray.at(i) =  temparray.at(i)+1; //add 1 to the array element at the appropriate index with O(n) complexity
    }

    for(int w = 0; w <= k; w++)         //looping the temp array giving O(K^2) where k is a constant
    {
        if(temparray[w]> 0)               //only printing indexes that have values greater than 0
        {
            while(temparray[w] != 0)     //printing multiples of the same index position
            {
                q << dictions[w] << " "; //print the correctly ordered element by searching the dictionary for corresponding word
                temparray[w] -= 1;
            }
        }
    }
}


void bubble(vector<int> x, vector<string> dictions, ofstream& q)    //bubble sort with O(n^2) time complexity
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
        q << dictions[j] << " ";   //print the correctly ordered element by searching the dictionary for corresponding word
    }

}


