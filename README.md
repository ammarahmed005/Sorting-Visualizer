# Sorting-Visualizer
Data Structures Project

Sorting Visualizer is a C++ program designed to help users understand and visualize how different sorting algorithms work. It provides a step-by-step graphical representation of sorting processes like Bubble Sort, Insertion Sort, Selection Sort, Merge Sort, and Quick Sort.

Features

Visual Representation: Highlights elements being compared or swapped during the sorting process.

Multiple Sorting Algorithms:

Bubble Sort

Insertion Sort

Selection Sort

Merge Sort

Quick Sort

Interactive Menu: Allows users to select sorting algorithms, input custom arrays, and choose options after sorting.

Input Validation: Ensures the user provides valid integer inputs.

Reusable Arrays: Users can reset to the original array or input a new one.

Cross-Platform: Compatible with most C++ compilers and platforms.

Getting Started

Prerequisites

A C++ compiler (e.g., GCC, Clang, or MSVC).

Basic knowledge of how to compile and run C++ programs on your operating system.

Installation

Clone this repository or download the source code directly:

git clone https://github.com/<YourUsername>/SortingVisualizer.git
cd SortingVisualizer

Ensure the file test13.cpp is in the project directory.

Usage

Compilation

To compile the program, use the following command (assuming you have a C++ compiler installed):

g++ -o sorting_visualizer test13.cpp -std=c++11 -pthread

Running the Program

Run the compiled program:

./sorting_visualizer

Instructions

Input Array:

The program will prompt you to enter the size of the array and its elements.

Choose Sorting Algorithm:

Use the interactive menu to select an algorithm (e.g., Bubble Sort, Quick Sort).

View the Process:

Watch the highlighted elements as the sorting progresses.

Post-Sorting Options:

Choose to use the original array, input a new array, or exit the program.

Example

Enter the size of the array: 5
Enter 5 elements of the array (integers only):
8 4 6 2 5

Original Array:
[  8   4   6   2   5 ]

================ Sorting Visualizer ================
1. Selection Sort
2. Insertion Sort
3. Bubble Sort
4. Merge Sort
5. Quick Sort
0. Exit
===================================================
Enter your choice: 3

Bubble Sort:
{ 4}  8   6   2   5  
  4  { 6}  8   2   5  
...

Sorted Array:
[  2   4   5   6   8 ]

Sorting Algorithms Explained

Bubble Sort: Repeatedly compares adjacent elements and swaps them if they are in the wrong order.

Insertion Sort: Builds a sorted portion one element at a time by inserting elements into their correct positions.

Selection Sort: Finds the minimum element in the unsorted portion and places it at the beginning.

Merge Sort: Divides the array into halves, sorts them recursively, and merges them.

Quick Sort: Divides the array around a pivot, then sorts the partitions recursively.

File Structure

SortingVisualizer/
├── test13.cpp  # Source code of the sorting visualizer
└── README.md    # Project documentation

Contributing

Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository and submit a pull request.

Guidelines

Follow consistent coding styles.

Ensure changes are thoroughly tested.

Provide detailed descriptions for pull requests.

License

This project is licensed under the MIT License. See the LICENSE file for more details.

Acknowledgments

C++ Standard Library: Used for threading, vectors, and input/output handling.

Inspired by a desire to make learning sorting algorithms interactive and fun.

Contact

For questions or feedback, reach out to:

GitHub: Ammar Ahmed Qazi
