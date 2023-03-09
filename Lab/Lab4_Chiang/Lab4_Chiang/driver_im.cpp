//implementation file for Driver

#include "driver.h"


/*
Opens file and calls methods to test hashing
Intput: inner is the input filename
Output: outer is the output filename
*/
void Driver::process(string inner, string outer)
{
    ifFoo.open(inner);
  
    int key;

    cout << " *****     Processing in: " << inner << "     *****\n\n";
    
    while (ifFoo >> key)                //reads txt 
    {
        nums.push_back(key);        //stores in vector
    }

    ifFoo.close();                  //close the input file

    Heap<int> Heaper;               //create object to access heap class

    for(auto g:nums){              //for loops to insert, show and check if the heap we are constructing is a heap onto the CONSOLE
      Heaper.insert(g);
      Heaper.print();
      Heaper.checkHeap();
    }

  
    outFoo.open(outer);              //creates the respective output files

    outFoo << "Heap\n";
    printHeap(Heaper, outFoo);        //prints curret heap onto TXT FILE

    int permaSize = Heaper.size();    //we update the current heap size so the next for loop can use in line 42
  
    for(int l=1;l<=permaSize;l++){    //for loops to delete all elements in the heap as requested
      outFoo << "\n\nDelete Min";
      outFoo << "\nHeap After Delete Min\n";
      Heaper.deleteMin();
      Heaper.print();
      Heaper.checkHeap();
      printHeap(Heaper, outFoo);
    }

    outFoo << "\n\nDeleted All";
    
    outFoo.close();

    cout << "\n*****     Outputting as: " << outer << "     *****\n\n";
}


/*
Print the current heap onto the txt
Input:Ofstream and the actual heap
Output: print heap on the actual output text
*/
void Driver::printHeap(Heap<int>& H, ofstream& O){
  for(int l=1;l<=H.size();l++){
    O << H.getElement(l) << " ";
  }
}

