#include <iostream>
using namespace std;

// Function Declarations
//void mySort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
	// Test
	int arr[] = { 3,1,2,5,6,7,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//mySort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// Function Definitions
//void mySort(int arr[], int n) {

//}
void printArray(int arr[], int size) {
	for (short i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}