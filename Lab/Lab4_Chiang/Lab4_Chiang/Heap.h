#ifndef Heap_h
#define Heap_h

#include <vector>
#include <iostream>

using namespace std;

template <typename ValueType>
class Heap
{   
  private:
    vector<ValueType> heapvec = vector<ValueType>(23);        //vector used in which we initailize all the elements to 0
    int currSize;                                             //number of elements in the heap

  public:

  /*
  Default Constructor
  Input: Vector
  Output: Define size 
  */
  Heap(){   
    currSize = 0;
  }

  /*
  Destructor
  Input: N/A
  Output: Destroy 
  */
  ~Heap(){
  }

  /*
  Internal method to percolate up in the heap
  Input:the inserted element
  Output: Calls percolate up function to insert at the end of heap 
  */
  void percolateUp(ValueType inserter){
    currSize++;  
    int hole = currSize;        //set the hole an index next
    
    heapvec[0] = inserter;        //set inserted element to equal the 0 index which isnt used
    
    for(inserter; inserter < heapvec[hole/2]; hole /= 2 ){  //this only runs given the conditions      
      heapvec[hole] = heapvec[hole/2];
    }
    heapvec[hole] = heapvec[0];
  }

  /*
  Insert element into heap
  Input: respective element
  Output: Calls percolate up function to add element 
  */
  void insert(ValueType elem){
    percolateUp(elem);
  }

  /*
  Delete min or root
  Input:N/A
  Output: Calls percolate down function to start at index 1
  */
  void deleteMin(){
    
    ValueType minItem = heapvec[1];
    
    heapvec[1] = heapvec[currSize--];
    
    percolateDown(1);
  }


  /*
  Internal method to percolate down in the heap
  Input: index for hole
  Output: percolate down the heap
  */
  void percolateDown(int hole){
      int child;                //create child first

      ValueType temp = heapvec[hole]; //move sementic just rename to "temp" while keeping address and stores it

      for(; hole * 2 <= currSize; hole = child){
          child = hole * 2;                            //looks at left child

          if(child != currSize && heapvec[child +1]< heapvec[child]){   //checks if the left child is within range and if left > right
              child++;     //move to the right child
          }
          if(heapvec[child] < temp ){      //checks if right child is less than parent
              heapvec[hole] = heapvec[child];   //if so then we make the swap using move semantics
          }
          else{                          //if none work then we move on to the next set of parent/childs
              break;
          }
      }
      heapvec[hole] = move(temp);      
  }

  /*
  Finds heap size
  Input:N/A
  Output:Returns the current size of heap
  */
  int size(){
    return currSize;
  }

  /*
  Getter Function
  Input:N/A
  Output: get the specified element in heap
  */
  ValueType getElement(int specifier){
    return heapvec[specifier];
  }


  /*
  Verifies if the heap is really a heap
  Input:N/A
  Output: indiciates yes or no to heap
  */
  void checkHeap(){
    bool checker = false;            //set bool to some dummy value

    for ( int i = 1; i <=currSize ; i++ ){
      if(i == 1){
        checker = true;
      }
      else if (areHeapElementsOrdered(i,2*i+1) && areHeapElementsOrdered(i,2*i) ){
        checker = true;
      }
      else{
        checker = false;
      }
    }

    if(checker){
      cout << "It' a heap" <<endl;
    }
    else{
      cout << "It's NOT a heap\n";
    }
  }

  /*
  Checks the conditions that determins if its a min heap
  Input:Parent and Child
  Output: Return boolean valye
  */
  bool areHeapElementsOrdered(int i, int j){
    return ((i >= currSize) || (j >= currSize) || (getElement(i) <= getElement(j)));     
  }

  /*
  Print Heap
  Input:N/A
  Output: Print min heap and current size to the console
  */
  void print(){
    cout << "\nCurrent Size: " << currSize << endl;
    for(int l=1;l<=currSize;l++){
      cout << heapvec[l] << " ";
    }
    cout <<endl;
  }
};


#endif
