#include "HelperFunctions.h";
#include <algorithm>
#include <ctime>
#include <chrono>

void fillWithRandomIntegers(int* const begin, int* const end) 
{
	std::srand(unsigned(std::time(nullptr)));
    for (int* iter = begin; end - iter > 0; ++iter) 
    {
        *iter = std::rand();
        *iter %= 199;
        *iter -= 99;
    }
}

int* binarySearchLowerBound(int* leftPtr, int* rightPtr, int& const element) 
{
    int* mid;
    while (rightPtr - leftPtr > 0)
    {
        mid = leftPtr + (rightPtr - leftPtr) / 2;

        if (element >= *mid)
        {
            leftPtr = mid + 1;
        }
        else
        {
            rightPtr = mid;
        }
    }

    //if (leftPos < length && leftPtr <= element) leftPos++;

    return leftPtr;
}

void shiftArrayRight(int* leftPtr, int* rightPtr)
{
    if (rightPtr - leftPtr < 1) return;
    const int lastElementValue = *(rightPtr - 1);

    for (int* i = leftPtr; i - leftPtr > 0; --i) {
        int& prev = *(i - 1);
        int& curr = *i;
        curr = prev;
    }

    *leftPtr = lastElementValue;
}

void bubbleSort(int* leftPtr, int* rightPtr) 
{
    int iterations = 0;
    bool isSorted = false;
    do
    {
        isSorted = true;
        for (int* iter = leftPtr + 1; rightPtr - iter - iterations > 0 ; ++iter)
        {
            int& prevItem = *(iter - 1);
            int& currItem = *iter;
            if (currItem < prevItem) {
                isSorted = false;
                std::swap(currItem, prevItem);
            }
        }
        ++iterations;
    } while (!isSorted);
}

void shakerSort(int* leftPtr, int* rightPtr)
{
    int iter = 0;
    bool isSorted = false;
    do
    {
        isSorted = true;
        for (int* i = leftPtr + 1 + iter; rightPtr - i > iter; ++i)
        {
            int& prevItem = *(i - 1);
            int& currItem = *i;
            if (currItem < prevItem) {
                isSorted = false;
                std::swap(currItem, prevItem);
            }
        }

        for (int* i = rightPtr - iter - 2; i - leftPtr >= iter; --i)
        {
            int& prevItem = *(i - 1);
            int& currItem = *i;
            if (currItem < prevItem) {
                isSorted = false;
                std::swap(currItem, prevItem);
            }
        }

        ++iter;
    } while (!isSorted);
}

void combSort(int* leftPtr, int* rightPtr)
{
    int size = rightPtr - leftPtr;
    int gap = size;
    bool isSorted = false;
    do
    {
        gap = std::max(1, gap * 10 / 13);
        isSorted = true;
        for (int i = 0; i < size - gap; ++i)
        {
            int& currItem = leftPtr[i];
            int& nextItem = leftPtr[i+gap];
            if (currItem > nextItem) {
                isSorted = false;
                std::swap(currItem, nextItem);
            }
        }
    } while (!isSorted || gap != 1);
}

void insertSort(int* leftPtr, int* rightPtr) 
{
    // with STL
    //TODO: implement same algorithm without STL

    for (auto i = leftPtr; i != rightPtr; ++i) 
        std::rotate(std::upper_bound(leftPtr, i, *i), i, i + 1);
}

int* partition(int* leftPtr, int* rightPtr)
{
    int* pivot = rightPtr - 1;
    int* smallerElement = leftPtr;

    for (int* iter = leftPtr; pivot - iter > 0; ++iter) 
    {
        if (*iter <= *pivot)
        {
            std::swap(*smallerElement, *iter);
            ++smallerElement;
        }
    }

    std::swap(*smallerElement, *pivot);
    return smallerElement;
}

void quickSort(int* leftPtr, int* rightPtr) 
{
    if (rightPtr - leftPtr > 0) 
    {
        int* pivot = partition(leftPtr, rightPtr);
        
        quickSort(leftPtr, pivot);
        quickSort(pivot + 1, rightPtr);
    }
}