//#include <iostream>
//
//using namespace std;
//
//
//void mergeSort(int arr[], int startIndex, int lastIndex);
//void merge(int arr[], int startIndex, int lastIndex, int mid);
//
//void mergeSort(int arr[], int startIndex, int lastIndex)
//{
//	int mid;
//	if (startIndex < lastIndex) {
//		mid = (startIndex + lastIndex) / 2;
//		mergeSort(arr, startIndex, mid);
//		mergeSort(arr, mid + 1, lastIndex);
//		merge(arr, startIndex, lastIndex, mid);
//	}
//
//
//}
//
//void merge(int arr[], int startIndex, int lastIndex, int mid)
//{
//	int * leftArray;
//	int * rightArray;
//	int i, j, k;
//
//	int n1 = mid - startIndex + 1;
//	int n2 = lastIndex - mid + 1;
//
//	leftArray = new int[n1];
//	rightArray = new int[n2];;
//
//	for (i = 0; i < n1; i++) {
//		leftArray[i] = arr[startIndex + i];
//	}
//	for (j = 0; j < n2; j++) {
//		rightArray[i] = arr[mid + 1 + j];
//	}
//
//	i = 0;
//	j = 0;
//	k = startIndex;
//
//	while (i < n1 && j < n2) {
//		if (leftArray[i] <= rightArray[j]) {
//			arr[k] = leftArray[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = rightArray[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i < n1) {
//		arr[k] = leftArray[i];
//		i++;
//		k++;
//	}
//
//	while (j < n2) {
//		arr[k] = rightArray[j];
//		j++;
//		k++;
//	}
//
//	delete[] leftArray;
//	delete[] rightArray;
//
//}
//
//
//
//int main(void) {
//	int a[] = { 7,4,2,19,5 };
//	int i;
//	mergeSort(a, 0, 4);
//	for (i = 0; i<5; i++)
//		cout << a[i] << "\n";
//	system("pause");
//	return 0;
//}




/*
* http://ideone.com/40wFkI
*/
#include <iostream>
using namespace std;

void mergeSort(int arrayToSort[], int startIndex, int lastIndex);
void merge(int arrayToSort[], int startIndex, int lastIndex, int mid);

int main(void) {
	int a[] = { 7,4,2,19,5 };
	int i;
	mergeSort(a, 0, 4);
	for (i = 0; i<5; i++)
		cout << a[i] << "\n";


	system("pause");
	return 0;
}

void mergeSort(int arrayToSort[], int startIndex, int lastIndex)
{
	int mid;

	if (lastIndex > startIndex)
	{
		mid = (startIndex + lastIndex) / 2;
		mergeSort(arrayToSort, startIndex, mid);
		mergeSort(arrayToSort, mid + 1, lastIndex);
		merge(arrayToSort, startIndex, lastIndex, mid);
	}
}
void merge(int arrayToSort[], int startIndex, int lastIndex, int mid)
{
	int* leftArray = NULL;
	int* rightArray = NULL;
	int i, j, k;
	int n1 = mid - startIndex + 1;
	int n2 = lastIndex - mid;
	leftArray = new int[n1];
	rightArray = new int[n2];
	for (i = 0; i < n1; i++)
		leftArray[i] = arrayToSort[startIndex + i];
	for (j = 0; j < n2; j++)
		rightArray[j] = arrayToSort[mid + 1 + j];

	i = 0;
	j = 0;
	k = startIndex;

	while (i < n1 && j < n2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			arrayToSort[k] = leftArray[i];
			i++;
		}
		else
		{
			arrayToSort[k] = rightArray[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		arrayToSort[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arrayToSort[k] = rightArray[j];
		j++;
		k++;
	}

	delete[] leftArray;
	delete[] rightArray;
}
