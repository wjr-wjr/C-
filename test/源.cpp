#include<iostream>
using namespace std;

int postion(int a[], int low, int high)
{
	int key = a[low];
	while (low < high)
	{
		while (low<high && a[high] > key)
		{
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low] <= key)
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = key;
	return low;
}

void quick_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int pos = postion(a, low, high);
		quick_sort(a, low, pos - 1);
		quick_sort(a, pos + 1, high);
	}
}

int main()
{
	int data[10] = {17,56,28,6,15,34,87,2,14,47};
	quick_sort(data, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << data[i];
		if (i != 9)
		{
			cout << "->";
		}
	}
	return 0;
}