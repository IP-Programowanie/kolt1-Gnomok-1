#define _CRT_SECURE_NO_WARNINGS
#include"Kol1.h"
#include <iostream>
using namespace std;
MyStructure* AllocateArray(int lenght, MyStructure structure) {
    MyStructure* structureArray = new MyStructure[lenght + 1];
    structureArray += 1;
    for (int i = 0; i < lenght; i++) {
        structureArray[i] = structure;
    }
    MyStructure temp; 
    temp.symbol = '0' + lenght; temp.number = 0;
    structureArray[-1] = temp;
    return structureArray;
}
void DeallocateArray(MyStructure* array) {
    if (array != nullptr) {
        MyStructure* originalArray = array - 1;
        delete[] originalArray;
    }
}

void WriteArrayToFile(const char fileName[], MyStructure* array) {
    FILE* file = fopen(fileName, "w");
    int lenght = array[-1].symbol - '0';
    fprintf(file, "%d\n", lenght);
    fprintf(file, "%f;%c\n", array[0].number, array[0].symbol);

    fclose(file);
}
MyStructure* ReadAndAllocateFromFile(const char fileName[]) {
    FILE* file = fopen(fileName, "r");
    int lenght = 0;
    float bufferFloat;
    char bufferChar;
    fscanf(file, "%d", &lenght);
    MyStructure tempStruct;
    fscanf(file, "%f;%c", &bufferFloat, &bufferChar);
    tempStruct.number = bufferFloat;
    tempStruct.symbol = bufferChar;
    return AllocateArray(lenght, tempStruct);
}

bool Compare(MyStructure* struct1, MyStructure* struct2) {
    int lenght1 = struct1[-1].symbol - '0';
    int lenght2 = struct2[-1].symbol - '0';
    if (lenght1 != lenght2) return false;
    for (int i = 0; i < lenght1; i++) {
        if (struct1[i].number != struct2[i].number) return false;
    }
    return true;
}

MyStructure* FindShortest(MyStructure* arr1, MyStructure* arr2) {
    if (arr1[-1].symbol - '0' < arr2[-1].symbol - '0') return arr1;
    return arr2;
}
MyStructure* FindLongest(MyStructure* arr1, MyStructure* arr2) {
    if (arr1[-1].symbol - '0' < arr2[-1].symbol - '0') return arr2;
    return arr1;
}