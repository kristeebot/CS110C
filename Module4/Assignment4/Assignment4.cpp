// CS110C
// PROF LUTTRELL
// KRISTINA HELWING
// 092322
// ASSIGNMENT 4

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int mergeSort(int *numbers, int size)
{
    return -1;
}
int bubbleSort(int *numbers, int size)
{
    return -1;
}
int countingSort(int *numbers, int size)
{
    return -1;
}

int *makeRandomArray(int numItems, bool constrain = false)
{
    int *myArray = new int[numItems];
    for (int i = 0; i < numItems; i++)
    {
        int value = rand();
        if (constrain)
        {
            value = value % numItems;
        }
        myArray[i] = value;
    }
    return myArray;
}
int getSortStats(int numItems, string sortType)
{
    int *itemsData = makeRandomArray(numItems);
    int accessCount = 0;
    if (sortType == "bubble")
    {
        accessCount = bubbleSort(itemsData, numItems);
    }
    else if (sortType == "merge")
    {
        accessCount = mergeSort(itemsData, numItems);
    }
    else if (sortType == "counting")
    {
        accessCount = countingSort(itemsData, numItems);
    }
    else
    {
        cout << "Bad sort type input: " << sortType << endl;
    }
    delete[] itemsData;
    return accessCount;
}
void printSortedStats(string sortType)
{
    int pad = strlen("counting") - sortType.size();
    string outputStr = string(sortType);
    for (int i = 0; i < pad; i++)
    {
        outputStr = outputStr + " ";
    }
    int arraySizes[] = {8, 32, 128};
    for (int i = 0; i < 3; i++)
    {
        int passResults[] = {0, 0, 0};
        for (int j = 0; j < 3; j++)
        {
            passResults[j] = getSortStats(arraySizes[i], sortType);
        }
        cout << outputStr << "\t" << arraySizes[i] << "\t";
        int total = 0;
        for (int j = 0; j < 3; j++)
        {
            int passResult = passResults[j];
            total += passResult;
            cout << passResult << "\t";
        }
        cout << total / 3 << endl;
    }
}
bool isSorted(int *numbers, int size)
{
    if (size <= 1)
    {
        return true;
    }
    int previousElement = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (previousElement > numbers[i])
        {
            return false;
        }
        previousElement = numbers[i];
    }
    return true;
}
void printArray(int *numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;
}
int main()
{   int *countSortInput = makeRandomArray(8, true);
    printArray(countSortInput, 8);
    countingSort(countSortInput, 8);
    printArray(countSortInput, 8);
    cout << "Is Sorted: " << isSorted(countSortInput, 8) << endl;
    int mergeSortInput[] = {5, 4, 3, 2, 1};
    int mergeSortAccessCount = mergeSort(mergeSortInput, 5);
    cout << "access count for merge sort was: " << mergeSortAccessCount << endl;
    int bubbleSortInput[] = {5, 4, 3, 2, 1};
    int bubbleSortAccessCount = bubbleSort(bubbleSortInput, 5);
    cout << "access count for bubble sort was: " << bubbleSortAccessCount << endl;
    int countingSortInput[] = {5, 4, 3, 2, 1};
    int countingSortAccessCount = bubbleSort(countingSortInput, 5);
    cout << "access count for counting sort was: " << countingSortAccessCount << endl;

    int *bubbleOneData = makeRandomArray(8, true);
    bubbleSortAccessCount = bubbleSort(bubbleOneData, 8);
    cout << "Bubble array length of 8: " << bubbleSortAccessCount << endl;
    delete[] bubbleOneData;
    printSortedStats("bubble");
    printSortedStats("merge");
    printSortedStats("counting");

    return 0;
}