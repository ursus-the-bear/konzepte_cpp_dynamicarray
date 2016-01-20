//
//  main.cpp
//  DynamicArray
//
//  Created by ursus on 20/01/16.
//  Copyright © 2016 Ursus Schneider. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <class T> class dynamicArray {

private:
    T * myArray;
    int arrayLength;
    int currentPosition;
    int extendArrayBy;
    
public:
    // constructor
    dynamicArray (int initialSize = 10) {
        myArray = new T [initialSize];
        arrayLength = initialSize;
        currentPosition = -1;
        extendArrayBy = 10;
    }

    // destructor
    ~dynamicArray () {
        delete [] myArray;
    }
    
    // function declarations
    bool add (T toAdd);
    bool removeElement (int elementNo);
    int length ();
    bool extendArray (int newExtendValue);
    
    // operator overloading
    T operator[](int index);
    
};

// overload the index operator
template <class T> T dynamicArray<T>::operator[](const int index){
    
    // preamble
    if (index < 0) return -1;
    if (index > arrayLength) return -1;
    
    // only access positiv index values
    return myArray [index];
}

template <class T> bool dynamicArray<T>::add (T toAdd) {
    
    // see if you need to resize the array
    if (currentPosition == (arrayLength - 1)) {
        // need to create a bigger array here!
        // create a new array to hold the old values
        T * newArray;
        newArray = new T [arrayLength + 1];
        arrayLength++;
        
        // copy the array values of the current array
        for (int i = 0; i < arrayLength - 1; i++)
            newArray [i] = myArray [i];
        
        // add the new value
        newArray [arrayLength] = toAdd;
        
        // replace the old array with the new array
        if (arrayLength > 0)
            delete [] myArray;
        myArray = newArray;
}
    
    // add to the array
    currentPosition++;
    myArray [currentPosition] = toAdd;
    
    // all OK
    return true;
}
// get the current array size
template <class T> int dynamicArray<T>::length () {
    return arrayLength;
}

// remove element number x
template <class T> bool dynamicArray<T>::removeElement (int elementNo) {
 
    // preamble
    if (arrayLength == 0)
        return true;
    if (arrayLength < elementNo)
        return true;
    
    // go through the array moving everything
    
    
    
    // create a new, smaller, array
    T * newArray;
    newArray = new T [arrayLength - 1];
    
    // now copy the values to the new array
    int newArrayPos = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (i != elementNo) {
            newArray [newArrayPos] = myArray [i];
            newArrayPos++;
        }
    }
        
    // replace the old array with the new array
    // delete [] myArray;
    myArray = newArray;
    
    // all OK
    return true;
}
// extend array by
template <class T> bool dynamicArray<T>::extendArray (int newExtendValue) {
    extendArrayBy = newExtendValue;
}



int main (int argc, const char * argv[]) {

    // create a new dynamic array
    dynamicArray <int> numbers;
    
    numbers.add (2);
    numbers.add (5);
    numbers.add (7);
    numbers.add (1);
    
    //cout << "Array: " << numbers.myArray[1] << endl;
    
    cout << "Array: " << numbers [0] << endl;
    cout << "Array: " << numbers [1] << endl;
    cout << "Array: " << numbers [2] << endl;
    cout << "Array: " << numbers [3] << endl;
    
    // numbers.removeElement (5);   // removes nothing -> only 4 elements in the array
    // numbers.removeElement (2);
    
    
    
    
    
    
    return 0;
}
