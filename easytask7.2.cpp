﻿#include <iostream>
using namespace std;
void Sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		int currMinIndex = 0;
		for (int j = i + 1; j < size; j++)
			if (arr[j] < arr[currMinIndex])
				currMinIndex = j;
		if (i != currMinIndex)
			swap(arr[i], arr[currMinIndex]);
	}
}
//Този алгоритъм сортира елементите по възходящ ред. По принцип не е особено бърз, но елементите в случая не са чак толкова много.
//Смятам, че е достатъчен за този проблем и не е необходимо да се използват по-сложни алгоритми.
int main()
{
	const int MAX = 52;
	int array[MAX];
	int arr[MAX];
	int dough;
	int i, j;
	for (i = 0; i < MAX; i++) {
		cin >> dough;
		for (j = 0; j < 13; i++) {
			int paint;
			paint = dough / 100;
			int card;
			card = dough % 100;
			array[i] = paint;
			arr[j] = card;
		}
		Sort(array, 4);
		for (int r = 0; r < 4; r++) {
			Sort(arr, 13);
		}
		  
	return 0;
	//paint
}   //1.Пика
	//2.Купа
	//3.Каро
	//4.Спатия