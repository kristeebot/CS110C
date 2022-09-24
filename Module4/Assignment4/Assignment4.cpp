// CS110C
// PROF LUTTREL
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


int main()
{
    int mergeSortInput[] = {5, 4, 3, 2, 1};
    int mergeSortAccessCount = mergeSort(mergeSortInput, 5);
    cout << "access count for merge sort was: " << mergeSortAccessCount << endl;
    int bubbleSortInput[] = {5, 4, 3, 2, 1};
    int bubbleSortAccessCount = bubbleSort(bubbleSortInput, 5);
    cout << "access count for bubble sort was: " << bubbleSortAccessCount << endl;
    int countingSortInput[] = {5, 4, 3, 2, 1};
    int countingSortAccessCount = bubbleSort(countingSortInput, 5);
    cout << "access count for counting sort was: " << countingSortAccessCount << endl;
    return 0;
}