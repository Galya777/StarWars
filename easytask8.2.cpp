﻿#include <iostream>
using namespace std;
#include <iostream>
const int MIN = 2;
bool insertAt(int*& arr, int& size, int& capacity, int elem, int pos)
{
	if (size + 1 > capacity) {

		int* newArr = new (nothrow) int[capacity * 2];
		if (!newArr)
			return false;

		capacity *= 2;
		for (int i = 0; i < pos; i++)
			newArr[i] = arr[i];

		newArr[pos] = elem;

		size++;
		for (int i = pos + 1; i < size; i++)
			newArr[i] = arr[i - 1];

		delete[] arr;
		arr = newArr;

	}
	else {
		for (int i = size; i > pos; i--)
			arr[i] = arr[i - 1];

		arr[pos] = elem;
		size++;

	}

	return true;
}
int* Array(int size)
{
	return new(nothrow) int[size];
}
 int* max( int* array, unsigned size)
{
	 int* max = array;
	for (unsigned i = 1; i < size; ++i) {
		if (array[i] > * max)
			max = array + i;
	}
	return max;
} void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}

void selectionSort(int* array, unsigned size)
{
	for (unsigned i = 0; i < size - 1; ++i) {
		 swap(array + i, array + (max(array + i, size - i) - array));
	}
}
int main()
{
	int bedrooms;
	int size;
	int n;
	cin >> bedrooms;
	if (bedrooms > 4 && bedrooms < 1024) {
		int* bedroomsize = Array(2*bedrooms);
		if (!bedroomsize) { 
			cout << "Not enough memory!" << endl;
			return 1;
		}
		for ( n = 0; n < bedrooms; n++) {
			cin >> size;
			bedroomsize[n] = size;
		}
		if (size != 0 && !(size & (size - 1))) {
			char command;
			cin >> command;
			switch (command){
			case 'A':
				int assaulters;
				cin >> assaulters;
				for (int i = 0; i < assaulters; i++) {
					if (int(max(bedroomsize, bedrooms)) != MIN) {
						int newroom= int(max(bedroomsize, bedrooms))/2;
						int capacity = bedrooms * 2;
						insertAt(bedroomsize, bedrooms, capacity,newroom,n);
						for (unsigned i = 0; i < bedrooms; ++i) {
							cout << bedroomsize[i] << " ";
						}
						cout << endl;
						break;
					}
					else {
						cout << "Thy again after Hoth!" << endl;
					}
				}
				break;
			case 'P':
				selectionSort(bedroomsize, bedrooms);
				for (unsigned i = 0; i < bedrooms; ++i) {
					cout << bedroomsize[i] << " ";
				}
				cout << endl;
				break;
			case 'E':
				delete[] bedroomsize;
				break;
			}


		}
	return 0;
}

