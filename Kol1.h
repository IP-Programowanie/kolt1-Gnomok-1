#define _CRT_SECURE_NO_WARNINGS
#pragma once
struct MyStructure {
	float number;
	char symbol;
};

MyStructure* AllocateArray(int lenght, MyStructure structure);
void DeallocateArray(MyStructure* array);
void WriteArrayToFile(const char fileName[], MyStructure* array);
MyStructure* ReadAndAllocateFromFile(const char fileName[]);
bool Compare(MyStructure* struct1, MyStructure* struct2);
MyStructure* FindShortest(MyStructure* arr1, MyStructure* arr2);
MyStructure* FindLongest(MyStructure* arr1, MyStructure* arr2);