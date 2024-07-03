#define _CRT_SECURE_NO_WARNINGS
#include "Wybor.h"
#include"Kol1.h"
#include<iostream>
using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczać pomiędzy #ifdef a #endif. 
*/

#ifdef Kol_1

int main()
{
    MyStructure a;
    a.number = 15;
    a.symbol = 'n';
    MyStructure* array1 = AllocateArray(7, a);
    MyStructure b;
    b.number = 9;
    b.symbol = 'm';
    MyStructure* array2 = AllocateArray(10, b);
    MyStructure c;
    c.number = 4;
    c.symbol = 't';
    MyStructure* array3 = AllocateArray(4, c);
    
    MyStructure* shortest = FindShortest(FindShortest(array1, array2), array3);
    MyStructure* longest = FindLongest(FindLongest(array1, array2), array3);
    WriteArrayToFile("smallest.txt", shortest);
    WriteArrayToFile("largest.txt", longest);

    MyStructure* loadedArray1 = ReadAndAllocateFromFile("smallest.txt");
    MyStructure* loadedArray2 = ReadAndAllocateFromFile("largest.txt");


    bool areEqual1 = Compare(shortest, loadedArray1);
    bool areEqual2 = Compare(longest, loadedArray2);

    if (areEqual1 == true && areEqual2 == true) {
        cout << "PODOBNE.\n";
    }
    else {
        cout << "NIE PODOBNE.\n";
    }

    DeallocateArray(array1);
    DeallocateArray(array2);
    DeallocateArray(array3);
    DeallocateArray(loadedArray1);
    DeallocateArray(loadedArray2);

    return 0;


}
#endif
