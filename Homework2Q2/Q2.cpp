#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


void swap(int& m, int& n) {
	int temp = m;
	m = n;
	n = temp;
}

void MaxHeapify(int arr[], int i, int size) {
	
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest;
	if (left < size && arr[left] > arr[i])
		largest = left;
	else
		largest = i;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, largest, size);
	}
}

void BuildMaxHeap(int arr[], int size) {
	for (int i = size / 2 -1; i >= 0; i--) {
		MaxHeapify(arr, i, size);
	}
}

void Heapsort(int arr[], int size) {
	BuildMaxHeap(arr, size);
	for (int i = size -1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		//size = size - 1;
		MaxHeapify(arr, 0, i);
	}
}

void print(int arr[], int n) {
	cout << "{";
	for (int i = 0; i < n; i++) {
		if (i + 1 != n)
			cout << arr[i] << ",";
		else
			cout << arr[i];
	}
	cout << "}";
}


int main() {
	//Generate input array
	const int N = 100;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	srand((unsigned)time(NULL));
	for (int i = N - 1; i > 0; i--) {
		int index = rand() % i;
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	//Print input array
	cout << "Random permutation array: "<<endl;
	print(arr, N);
	Heapsort(arr, N);
	cout << endl;
	cout << "\nOutput array: " << endl;
	print(arr, N);
	return 0;
}