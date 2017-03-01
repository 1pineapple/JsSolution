// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<ctime>
#include <thread>
#include <chrono>
using namespace std;
void heapify(int arr[], int n, int i)
{
	int largest = i;  
	int l = 2 * i + 1;  
	int r = 2 * i + 2;  
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int *arr, int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void main()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	int n;
	cout << "Enter size ";
	cin >> n;
	srand(time(NULL));
	int *arr=new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand()%10-3;
	//printArray(arr, n); можна скористатися якщо маленький масив щоб подивитися на нього просто заберіть // і цей коменнат
	cout << "Wait please" << endl;
	start = std::chrono::high_resolution_clock::now();
	heapSort(arr, n);
	stop = std::chrono::high_resolution_clock::now();
	//cout << "Sorted array is \n"; можна скористатися якщо маленький масив щоб подивитися на нього просто заберіть // і цей коменнат
	//printArray(arr, n); можна скористатися якщо маленький масив щоб подивитися на нього просто заберіть // і цей коменнат
	std::cout << "\nTime: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " miliseconds\n";
	system("pause");
}

