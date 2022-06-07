#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// display array function
void displayArray(int* arrayObj, int arraySize);

// binary search!
int binarySearch(int array[], int itemLookup, int arrayLength);

// trinary search
int trinarySearch(int* arr, int lo, int hi, int value);

// binary search recursion
int binarySearchRecursion(int* arrayObj, int itemLookup, int startPos, int arrayLength);

// selection sort! - helper function
int findSmallestIndex(int *arrayObj, int arraySize);

// selection sort! - main function
int* selectionSortAsc(int* arrayObj, int arraySize);

// selection sort - no malloc + no destroy
void selectionSortAscNoDest(int* arrayObj, int arraySize);

// selection sort desc - no malloc + no destroy
void selectionSortDescNoDest(int* arrayObj, int arraySize);

// insertion sort asc -
void insertionSort(int* arrayObj, int arraySize);

// bubble sort
void bubbleSort(int *arrayObj, int arraySize);

// recursion countdown
void countdown(int i);

// recursion tail countdown
void countdownTail(int i);

// call stack! = e.g.1
void greet2(char *name);

// call stack! = e.g.2
void bye();

// call stack! = e.g.3
void greet(char* name);

// recursion Tail factorial
int factorialTail(int inputNum, int carryOver);

// recursion factorial!
int factorialNoTail(int inputNum);

// recursive sum!
int recursiveSum(int* arrayObj, int arrayIndex, int arraySize);

// recursive sum tail!
int recursiveSumTail(int* arrayObj, int arrayIndex, int arraySize, int carryOver);

// count
int recursiveCount(int* arrayObj, int arrayIndex, int arraySize);

// maxItem
int recursiveMaxItem(int* arrayObj, int arraySize);

// merge Sort
void mergeSort(int* arrayObj, int left, int right);

// merge helper
void mergeHelper(int* arrayObj, int left, int middle, int right);

// quickSort
void quickSort(int* arrayObj, int start, int end);

// partition
int quickSortPartition(int* arrayObj, int start, int end);

// gcd
int gcd(int x, int y);

// fib
int iterFib(int n);

int main() {

    // Binary search
    int arrayTest[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arrayTest)/sizeof(arrayTest[0]);
    printf("\nThe array has length of %d", len);
    printf("\nChecking if %d exists in array, Position - %d",
           5,
           binarySearch(arrayTest,5,10));
    printf("\nChecking if %d exists in array, Position - %d",
           15,
           binarySearch(arrayTest,15,10));

    printf("\nChecking if %d exists in array, Position - %d",
           7,
           binarySearchRecursion(arrayTest,7,0,10));
    printf("\nChecking if %d exists in array, Position - %d",
           25,
           binarySearchRecursion(arrayTest,25,0,10));


    // Selection Sort - ascending!
    int array1[] = {5,7,6,8,0};
    int arrayLength = sizeof(array1)/sizeof(array1[0]);
    int *sortedAscArray = selectionSortAsc(array1,arrayLength); // grokking
    // let's print sorted array
    displayArray(sortedAscArray, arrayLength);
    // print original array
    displayArray(array1,arrayLength);

    int array2[] = {15,17,16,82,10};
    int arrayLength2 = sizeof(array2)/sizeof(array2[0]);
    // print original array
    displayArray(array2,arrayLength);
    // sort!
    selectionSortAscNoDest(array2,arrayLength2); // cps500
    // let's print sorted array
    displayArray(array2, arrayLength);

    int array3[] = {115,176,176,862,1099};
    int arrayLength3 = sizeof(array3)/sizeof(array3[0]);
    // print original array
    displayArray(array3,arrayLength);
    // sort!
    selectionSortDescNoDest(array3,arrayLength3); // cps500
    // let's print sorted array
    displayArray(array3, arrayLength);

    printf("\nRecursive Countdown....");
    // recursion countdown
    countdown(10);

    printf("\nCall stack stuff...");
    greet("Avi");

    countdownTail(10);

    printf("\nThe factorial of 5 is %d",factorialTail(5,1));

    printf("\nThe factorial of 15 is %d",factorialNoTail(10));

    int foo[] = {1,2,3,4,5};
    int lenFoo = sizeof(foo)/sizeof(foo[0]);
    printf("\n The sum of array foo is %d", recursiveSum(foo, 0, lenFoo));

    int bar[] = {1,2,3,4,5,6,7,8};
    int lenBar = sizeof(bar)/sizeof(bar[0]);
    printf("\n The sum of array bar is %d", recursiveSumTail(bar, 0, lenBar, 0));

    int test[] = {1,2,3,4,5,6,7,8};
    printf("\nThere are %d elements in test array", recursiveCount(test,0, lenBar));


    int testMax[] = {12,52,83,478,56,69,70,81};
    int lentestMax = sizeof(testMax)/sizeof(testMax[0]);
    printf("\nThe max item in the test array is %d", recursiveMaxItem(testMax,lentestMax));

    int sortTest[] = {12,52,83,478,56,69,70,81};
    printf("\nBefore merge sort...");
    displayArray(sortTest, lentestMax);
    mergeSort(sortTest,0,lentestMax);
    printf("\nAfter merge sort...");
    displayArray(sortTest, lentestMax);

    int insertSortTestArray[] = {45745,1231,77,233,88};
    int insertSortTestArrayLen = sizeof(insertSortTestArray)/sizeof(insertSortTestArray[0]);
    printf("\nPrior to insertion sort...");
    displayArray(insertSortTestArray, insertSortTestArrayLen);
    insertionSort(insertSortTestArray, insertSortTestArrayLen);
    printf("\nAfter insertion sort...");
    displayArray(insertSortTestArray, insertSortTestArrayLen);

    int bubbleSortTestArray[] = {45745,1231,77,233,88,8923,3242};
    int bubbleSortTestArrayLen = sizeof(bubbleSortTestArray)/sizeof(bubbleSortTestArray[0]);
    printf("\nPrior to bubble sort...");
    displayArray(bubbleSortTestArray, bubbleSortTestArrayLen);
    bubbleSort(bubbleSortTestArray, bubbleSortTestArrayLen);
    printf("\nAfter bubble sort...");
    displayArray(bubbleSortTestArray, bubbleSortTestArrayLen);

    printf("\nThe gcd of 256 and 312 is %d", gcd(256,312));

    printf("\nThe fibonacci of 4 is %d", iterFib(4));

    int qSortTestArray[] = {45745,1231,77,233,88,8923,3242, 1231,57757,2};
    int qSortTestArrayLen = sizeof(qSortTestArray)/sizeof(qSortTestArray[0]);
    printf("\nPrior to quick sort...");
    displayArray(qSortTestArray, qSortTestArrayLen);
    quickSort(qSortTestArray,0,9);
    printf("\nAfter quick sort...");
    displayArray(qSortTestArray, qSortTestArrayLen);

    return 0;
}

// iterative Fibonacci function
int iterFib(int n){
    int f1 = 0;
    int f2 = 1;
    for(int i =0; i< n;i++){
        int temp = f1 + f2;
        printf("\nFoo%d", temp);
        f1 = f2;
        f2 = temp;
    }
    return f2;
}

// Utility function to display arrays
void displayArray(int* arrayObj, int arraySize){
    printf("\n");
    putchar('[');
    for(int i=0; i<arraySize;i++){
        if(i==arraySize-1){
            printf("%d",arrayObj[i]);
        } else{
            printf("%d,",arrayObj[i]);
        }
    }
    putchar(']');
}

// Binary Search
int binarySearch(int arrayInput[], int itemLookup, int arrayLength){
    int low=0;
    int high=arrayLength;
    while(low<=high){
        int mid=(low+high)/2;
        int itemCheck=arrayInput[mid];
        if (itemCheck==itemLookup){
            return mid;
        } else if (itemLookup>itemCheck){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    // base case
    return -1;
}

// Binary Search Recursion
int binarySearchRecursion(int* arrayObj, int itemLookup, int startPos, int arrayLength){
    // base case
    if(arrayLength >= startPos){
        int mid = (startPos+arrayLength)/2;
        if (arrayObj[mid] == itemLookup){
            return mid;
        } else if (itemLookup > arrayObj[mid]){
            return binarySearchRecursion(arrayObj, itemLookup, mid+1, arrayLength);
        } else { // if (itemLookup < arrayObj[mid])
            return binarySearchRecursion(arrayObj, itemLookup, startPos, mid-1);
        }
    }

    // cover for case when item is not present after covering all items in the array
    return -1;
}

int trinarySearch(int* arr, int lo, int hi, int value){
    if (hi >= lo){
        // find the middle values
        int mid1 = lo + (hi - 1)/3;
        int mid2 = hi - (hi -1)/3 ;
        // Check if value was present or not..
        // Starting with mid1
        if (arr[mid1] == value){
            return mid1;
        }
        // Starting with mid2
        if (arr[mid2] == value){
            return mid2;
        }
        // Check if value was less than arr[mid1]
        if (value < arr[mid1]) {
            return trinarySearch(arr, lo, mid1-1, value);
        }
        // Check if value was greater than arr[mid2]
        else if (value > arr[mid2]){
            return trinarySearch(arr,mid2+1, hi, value);
        } else {
            // This means that the value was between arr[mid1] and arr[mid2]
            return trinarySearch(arr,mid1+1, mid2-1, value);
        }
    }
    return -1;
}

// Selection Sort - helper function -- find the index associated with the smallest value in array
int findSmallestIndex(int *arrayObj, int arraySize){
    // Assume the smallest item is the first value
    int smallest = arrayObj[0];
    int smallestIndex = 0;
    for(int i=0; i < arraySize; i++){
        if(arrayObj[i] < smallest){
            smallest = arrayObj[i];
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

// Selection Sort - Ascending!
int* selectionSortAsc(int* arrayObj, int arraySize) {
    // Create a new array in the heap
    int *newAscSortedArray = (int *) malloc(sizeof(int) * arraySize);
    for(int i=0; i < arraySize; i++ ){
        // find the index associated with the smallest element in the array!
        int smallestIndex = findSmallestIndex(arrayObj, arraySize);
        // load the new array with the "smallest values" associated using the index!
        newAscSortedArray[i] = arrayObj[smallestIndex];
        // essentially remove the smallest value by setting it a high value
        arrayObj[smallestIndex] = INT_MAX;
    }
    return newAscSortedArray;
}

// Selection Sort without Destroying!
void selectionSortAscNoDest(int* arrayObj, int arraySize){
    int smallestIndex, smallestValue;
    for(int i=0; i<arraySize; i++){
        smallestIndex=i;
        smallestValue=arrayObj[i];
        // now we will iterate through the array to find the minimum values
        for(int j=i+1; j<arraySize; j++){
            if(arrayObj[j]<smallestValue){
                smallestIndex=j;
                smallestValue=arrayObj[j];
            }
        }
        // swapping time - move the current ith run with the smallest value
        arrayObj[smallestIndex] = arrayObj[i];
        // swapping time - replace the smallest value with the greater value
        arrayObj[i] = smallestValue;
    }
}

// Selection Sort Descending without Destroying
void selectionSortDescNoDest(int* arrayObj, int arraySize){
    int largestIndex, largestValue;
    for(int i=0; i<arraySize; i++){
        largestIndex=i;
        largestValue=arrayObj[i];
        // now let's iterate through the array to find the ACTUAL max values excluding ith position
        for(int j=i+1; j<arraySize; j++){
            if(arrayObj[j] > largestValue){
                largestIndex=j;
                largestValue=arrayObj[j];
            }
        }
        // now we have to swap - replace the current ith value with
        arrayObj[largestIndex] = arrayObj[i];
        arrayObj[i] = largestValue;
    }
}

void insertionSort(int* arrayObj, int arraySize){
    for(int i=1; i < arraySize; i++){
        int key = arrayObj[i];
        int j = i-1;
        while(j>=0 && arrayObj[j]>key){
            arrayObj[j+1] = arrayObj[j];
            j=j-1;
        }
        arrayObj[j+1] = key;
    }
}

void bubbleSort(int *arrayObj, int arraySize){
    for(int i=0; i<arraySize-1; i++){
        // to counter for cases if the tail elements are already sorted
        int swapped = 0;
        for(int j=0; j<arraySize-i-1; j++){
            if(arrayObj[j] > arrayObj[j+1]){
                int temp = arrayObj[j+1];
                arrayObj[j+1] = arrayObj[j];
                arrayObj[j] = temp;
                // setting to one in case sorting action occurs
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}


// recursion countdown
void countdown(int i){
    putchar('[');
    //print out character
    printf("%d", i);
    //base case
    if(i==0){
        putchar(']');
        return;
    } else{
        countdown(i-1);
        putchar(']'); // yoyo!
    }
}

void countdownTail(int i){
    if (i==0){
        return;
    }
    printf("\n%d", i);
    countdownTail(i-1);
}

// call stack eg.2
void greet2(char* name){
    printf("\nHow are you, %s?", name);
}

void bye(){
    printf("\nTake it easy!");
}

void greet(char* name){
    printf("\nHello %s !", name);
    greet2(name);
    printf("\nTalk to you later then!");
    bye();
}

int gcd(int x, int y){
    if(y==0){
        return x;
    }
    return gcd(y, x%y);
}


int factorialTail(int inputNum, int carryOver){
    if(inputNum==0){
        return carryOver;
    } else {
        factorialTail(inputNum-1, inputNum*carryOver);
    }
}

int factorialNoTail(int inputNum){
    if(inputNum==0){
        return 1;
    } else{
        return inputNum* factorialNoTail(inputNum-1);
    }
}

int recursiveSum(int* arrayObj, int arrayIndex, int arraySize){
    if(arrayIndex==arraySize){
        return 0;
    } else {
        return arrayObj[arrayIndex] + recursiveSum(arrayObj,arrayIndex+1, arraySize);
    }
}

int recursiveSumTail(int* arrayObj, int arrayIndex, int arraySize, int carryOver){
    if(arrayIndex==arraySize){
        return carryOver;
    } else {
        return recursiveSumTail(arrayObj, arrayIndex+1, arraySize, carryOver+arrayObj[arrayIndex]);
    }
}

int recursiveCount(int* arrayObj, int arrayIndex, int arraySize){
    if (arrayIndex==arraySize){
        return 0;
    } else{
        return 1+ recursiveCount(arrayObj,arrayIndex+1, arraySize);
    }
}

int recursiveMaxItem(int* arrayObj, int arraySize){
    int maxValue = arrayObj[0];
    if(arraySize==2){
        if (arrayObj[0] > arrayObj[1]){
            maxValue = arrayObj[0];
            return maxValue;
        } else {
            maxValue = arrayObj[1];
            return maxValue;
        }
    }
    int maxInterim = recursiveMaxItem(arrayObj+1, arraySize-1);
    return (maxValue > maxInterim ? maxValue: maxInterim);
}


// merge Sort
void mergeSort(int* arrayObj, int left, int right){
    if(left < right){
        int middle = left+(right-left)/2;
        mergeSort(arrayObj,left, middle);
        mergeSort(arrayObj,middle+1,right);
        mergeHelper(arrayObj,left, middle, right);
    }
}

// merge helper
void mergeHelper(int* arrayObj, int left, int middle, int right){
    // let's create a temp array
    int temp[right-left];
    int i = left;
    int j = middle;
    int index = 0;
    // capturing elements in sorted fashion between "left" and "right" arrays
    while (i< middle && j <right){
        if(arrayObj[i] < arrayObj[j]){
            temp[index] = arrayObj[i];
            i++;
        } else{
            temp[index] = arrayObj[j];
            j++;
        }
        index++;
    }
    // filling remaining of "left" array into temp
    while (i<middle){
        temp[index] = arrayObj[i];
        i++;
        index++;
    }
    // filling remaining of "right" array int temp
    while (j<right){
        temp[index] = arrayObj[j];
        j++;
        index++;
    }
    // perform in-line replacement of original arrayObj with data from temp array
    for(int k=0; k<(right-left);k++){
        arrayObj[left+k] = temp[k];
    }
}

// quickSort
void quickSort(int* arrayObj, int start, int end){
    if(start<end){
        int q = quickSortPartition(arrayObj, start, end);
        quickSort(arrayObj,start,q-1);
        quickSort(arrayObj,q+1, end);
    }
}

// partition
int quickSortPartition(int* arrayObj, int start, int end){
    int pivot = arrayObj[end];
    int i = start-1;
    int temp=0;
    for(int j=start; j< end; j++){
        if(arrayObj[j] < pivot){
            i++;
            temp = arrayObj[i];
            arrayObj[i] = arrayObj[j];
            arrayObj[j] = temp;
        }
    }
    temp = arrayObj[i+1];
    arrayObj[i+1] = arrayObj[end];
    arrayObj[end] = temp;
    return i+1;
}