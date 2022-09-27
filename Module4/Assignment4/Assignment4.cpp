// CS110C
// PROF LUTTRELL
// KRISTINA HELWING
// 092322
// ASSIGNMENT 4

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

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

const int MAX_SIZE = 128;
int merge(int theArray[], int first, int mid, int last)
{
    int accessCount = 0;
    int tempArray[MAX_SIZE];
    memset(tempArray, 0xdeadbeef, sizeof(tempArray));
    int first1 = first;   // begin first subarray
    int last1 = mid;      // end first subarray
    int first2 = mid + 1; // begin second subarray
    int last2 = last;     // end second subarray
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        accessCount += 2;
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            accessCount++;
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            accessCount++;
            first2++;
        } // end if
        index++;
    } // end while
    while (first1 <= last1)
    {
        tempArray[index] = theArray[first1];
        accessCount++;
        first1++;
        index++;
    } // end while
    while (first2 <= last2)
    {
        tempArray[index] = theArray[first2];
        accessCount++;
        first2++;
        index++;
    }
    for (index = first; index <= last; index++)
    {
        accessCount++;
        theArray[index] = tempArray[index];
    }
    return accessCount;
} // end merge

int mergeSort(int theArray[], int first, int last)
{
    int accessCount = 0;
    if (first < last)
    {
        int mid = first + ((last - first) / 2); // midpoint index
        accessCount += mergeSort(theArray, first, mid);
        accessCount += mergeSort(theArray, mid + 1, last);
        accessCount += merge(theArray, first, mid, last);
        
    } // end if
    return accessCount;
}

int mergeSort(int *numbers, int size)
{
    //cout << "before: " << endl;
    //printArray(numbers, size);
    int accessCount = size > 0 ? mergeSort(numbers, 0, size - 1) : 0;
    //cout << "after: " << endl;
    //printArray(numbers, size);
    return accessCount;
}

int bubbleSort(int *numbers, int size)
{
    int accessCount = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
                accessCount++;
            }
        }
    }
    return accessCount;
}

int countingSort(int *numbers, int size)
{
    int accessCount = 0;
    // using array inex to count
    // Allocate a new array of size
    int *newArray = new int[size];
    // with a for loop fill each new element with the array of zero
    for (int i = 0; i < size; i++)
    {
        newArray[i] = 0;
    }
    // printArray(numbers, size);
    //  with a for loop
    for (int i = 0; i < size; i++)
    {
        accessCount++;
        newArray[numbers[i]]++;
    }
    // printArray(newArray, size);

    // with another for loop for each element of new array
    int outputIndex = 0;

    for (int i = 0; i < size; i++)
    {
        int count = newArray[i];
        //(nested for loop) insert new array[i's] worth of index into numbers

        for (int j = outputIndex; j < outputIndex + count; j++)
        {
            numbers[j] = i;
            ++accessCount;
        }
        outputIndex += count;
    }

    delete[] newArray;
    return accessCount;
}

int *makeRandomArray(int numItems, bool constrain = false)
{
    int *myArray = new int[numItems];
    for (int i = 0; i < numItems; i++)
    {
        int value = rand();
        if (constrain)
        {
            // For counting sort we want numItems to be
            // the non-included upper bound.
            value = value % (numItems - 1);
        }
        myArray[i] = value;
    }
    return myArray;
}
int getSortStats(int numItems, string sortType)
{
    int *itemsData = makeRandomArray(numItems, sortType == "counting");
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
    const int SIZE_COUNT = 3;
    for (int i = 0; i < SIZE_COUNT; i++)
    {
        int passResults[] = {0, 0, 0};
        for (int j = 0; j < SIZE_COUNT; j++)
        {
            passResults[j] = getSortStats(arraySizes[i], sortType);
        }
        cout << outputStr << "\t" << arraySizes[i] << "\t";
        int total = 0;
        for (int j = 0; j < SIZE_COUNT; j++)
        {
            int passResult = passResults[j];
            total += passResult;
            cout << passResult << "\t";
        }
        cout << total / 3 << endl;
    }
}
int main()
{
    int mergeSortInput[] = {1, 4, 5, 4, 3, 2, 3};
    int mergeSortAccessCount = mergeSort(mergeSortInput, 7);
    cout << "access count for merge sort was: " << mergeSortAccessCount << endl;

    int *countSortInput = makeRandomArray(8, true);
    // printArray(countSortInput, 8);
    countingSort(countSortInput, 8);
    // printArray(countSortInput, 8);
    cout << "Is Sorted: " << isSorted(countSortInput, 8) << endl;
    delete[] countSortInput;
    int bubbleSortInput[] = {5, 4, 3, 2, 1};
    int bubbleSortAccessCount = bubbleSort(bubbleSortInput, 5);
    cout << "access count for bubble sort was: " << bubbleSortAccessCount << endl;
    int countingSortInput[] = {5, 4, 3, 2, 1};
    int countingSortAccessCount = countingSort(countingSortInput, 5);
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