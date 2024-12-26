#include <iostream>
#include <iomanip>
#include <thread>
#include <vector>
#include <limits>

using namespace std;

/* ============================ Global Variables ============================ */

// Array size and the original & working arrays for sorting
int arrSize;                    // Size of the array
vector<int> originalArray, arr; // Arrays for original and working data

/* ============================ Function Definitions ============================ */

/**
 * Clears the terminal line for visual effects (used after every update to the array)
 */
void clearLine() {
    cout << "\033[1A\033[2K"; // ANSI escape codes to clear the line
}

/**
 * Prints the current array with optional highlighted elements (for visualization)
 * @param highlight1 - The index of the first element to highlight
 * @param highlight2 - The index of the second element to highlight
 */
void printVisualArray(int highlight1 = -1, int highlight2 = -1) {
    for (int i = 0; i < arrSize; i++) {
        if (i == highlight1 || i == highlight2)
            cout << "{" << setw(2) << arr[i] << "} "; // Highlight element
        else
            cout << " " << setw(2) << arr[i] << "  "; // Regular element
    }
    cout.flush();
    cout << endl;
}

/**
 * Simulates a delay between array updates to visualize sorting progress
 */
void simulateDelay() {
    this_thread::sleep_for(chrono::milliseconds(600)); // Adjust time for faster/slower visualization
    clearLine(); // Clear line for the next update
}

/**
 * Get a valid integer from the user input
 * This function ensures that the input is a valid integer and not invalid characters.
 * @return Valid integer input from the user.
 */
int getValidInteger() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear(); // Reset the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } else {
            return value; // Return valid input
        }
    }
}

/**
 * Prompts the user to input the array size and elements
 */
void inputArray() {
    cout << "Enter the size of the array: ";
    arrSize = getValidInteger();

    while (arrSize <= 0) {
        cout << "Array size must be a positive integer. Try again: ";
        arrSize = getValidInteger();
    }

    originalArray.resize(arrSize);  // Resize the arrays based on input size
    arr.resize(arrSize);

    cout << "Enter " << arrSize << " elements of the array (integers only):\n";
    for (int i = 0; i < arrSize; i++) {
        originalArray[i] = getValidInteger();  // Populate originalArray with user input
    }
    arr = originalArray; // Copy original data into arr for sorting
}

/**
 * Prints the array passed as an argument
 * @param array - The array to be printed
 */
void printArray(const vector<int> &array) {
    cout << "[ ";
    for (int i = 0; i < arrSize; i++) {
        cout << setw(2) << array[i] << " ";
    }
    cout << "]" << endl;
}

/**
 * Resets the working array back to the original array
 */
void resetArray() {
    arr = originalArray; // Restore the working array to the original
}

/* ============================ Sorting Algorithms ============================ */

/**
 * Bubble Sort Algorithm with visual updates after every swap.
 */
void bubbleSort() {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - 1 - i; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);  // Swap elements if necessary
            }
            printVisualArray(j, j + 1);   // Visual feedback for each comparison
            simulateDelay();
        }
    }
}

/**
 * Insertion Sort Algorithm with visual updates.
 */
void insertionSort() {
    for (int i = 1; i < arrSize; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift elements to the right
            printVisualArray(j, j + 1);  // Visualize the process
            simulateDelay();
            j--;
        }
        arr[j + 1] = key;
        printVisualArray(j + 1, i);  // Highlight the inserted element
        simulateDelay();
    }
}

/**
 * Selection Sort Algorithm with visual updates.
 */
void selectionSort() {
    for (int i = 0; i < arrSize - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Find the minimum element
            }
            printVisualArray(i, minIndex);  // Visualize the process
            simulateDelay();
        }
        swap(arr[i], arr[minIndex]);  // Place the minimum element in the correct position
    }
}

/**
 * Quick Sort Helper Function (Partition)
 * @param low - Starting index
 * @param high - Ending index
 * @return The index of the pivot after partitioning
 */
int partitionArray(int low, int high) {
    int pivot = arr[low];
    int left = low + 1, right = high;

    while (left <= right) {
        while (left <= right && arr[left] <= pivot) left++;
        while (left <= right && arr[right] > pivot) right--;

        if (left < right) {
            swap(arr[left], arr[right]);  // Swap elements if needed
            printVisualArray(left, right);  // Visualize the process
            simulateDelay();
        }
    }
    swap(arr[low], arr[right]);  // Swap pivot into the correct position
    printVisualArray(low, right);
    simulateDelay();

    return right;
}

/**
 * Quick Sort Recursive Function
 * @param low - Starting index
 * @param high - Ending index
 */
void quickSort(int low, int high) {
    if (low >= high) return;

    int pivotIndex = partitionArray(low, high);  // Partition the array
    quickSort(low, pivotIndex - 1);  // Sort the left partition
    quickSort(pivotIndex + 1, high);  // Sort the right partition
}

/**
 * Merge Sort Helper Function
 * @param left - Starting index
 * @param mid - Middle index
 * @param right - Ending index
 */
void merge(int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    // Merge two sorted halves into one sorted array
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
        printVisualArray(i - 1, j - 1);  // Visualize the process
        simulateDelay();
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        temp[k++] = arr[i++];
        printVisualArray(i - 1);  // Visualize the process
        simulateDelay();
    }
    // Copy remaining elements from the right half
    while (j <= right) {
        temp[k++] = arr[j++];
        printVisualArray(j - 1);  // Visualize the process
        simulateDelay();
    }

    // Copy merged array back into the original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

/**
 * Merge Sort Recursive Function
 * @param left - Starting index
 * @param right - Ending index
 */
void mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(left, mid);  // Sort the left partition
    mergeSort(mid + 1, right);  // Sort the right partition
    merge(left, mid, right);  // Merge the two sorted halves
}

/* ============================ User Interaction ============================ */

/**
 * Displays the main menu of sorting options.
 */
void showMenu() {
    cout << "\n================ Sorting Visualizer ================\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "0. Exit\n";
    cout << "===================================================\n";
    cout << "Enter your choice: ";
}

/* ============================ Main Function ============================ */
int main() {
    inputArray(); // Ask user for array input initially

    while (true) {
        cout << "\nOriginal Array:\n";
        printArray(originalArray); // Display the original array

        showMenu();  // Show menu to select sorting algorithm

        int choice = getValidInteger();

        switch (choice) {
            case 1:
                cout << "Selection Sort:\n";
                selectionSort();  // Perform Selection Sort
                break;
            case 2:
                cout << "Insertion Sort:\n";
                insertionSort();  // Perform Insertion Sort
                break;
            case 3:
                cout << "Bubble Sort:\n";
                bubbleSort();  // Perform Bubble Sort
                break;
            case 4:
                cout << "Merge Sort:\n";
                mergeSort(0, arrSize - 1);  // Perform Merge Sort
                break;
            case 5:
                cout << "Quick Sort:\n";
                quickSort(0, arrSize - 1);  // Perform Quick Sort
                break;
            case 0:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }

        cout << "\nSorted Array:\n";
        printArray(arr); // Display the sorted array

        // Options after sorting
        cout << "\nDo you want to:\n";
        cout << "1. Use the original array\n";
        cout << "2. Input a new array\n";
        cout << "3. Exit the program\n";
        cout << "Enter your choice: ";

        int postSortChoice = getValidInteger();

        if (postSortChoice == 2) {
            inputArray(); // Input a new array
        } else if (postSortChoice == 3) {
            cout << "Exiting program.\n";
            return 0;
        } else {
            resetArray(); // Reset to the original array
        }
    }
    return 0;
}
