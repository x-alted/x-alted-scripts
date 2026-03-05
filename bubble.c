#include <stdio.h>

int swap(int* arrData, int index1, int index2) 
{
	int temp = arrData[index1];
	arrData[index1] = arrData[index2];
	arrData[index2] = temp;
	return 0;
}

int printRawArray(int* arrData, int size, char* spacer)
{
	printf("size = %d :   ", size);
	for (int i = 0; i < size; i++)
	{
		printf("%d%s", arrData[i], spacer);
	}
	return 0;
}

int bubblesort_once(int* arrData, int size)
{
	//go through once
	for (int i = 0; i < size-1; i++)
	{
		if (arrData[i] > arrData[i + 1])
		{
			printf("swapping at %d\n", i);
			swap(arrData, i, i + 1);
			printf("after swap the array is:  ");
			printRawArray(arrData, 15, ", ");
		}
	}
	printf("after one loop\n");
	printRawArray(arrData, 15, ", ");
	printf("\n\n");

}

int bubblesort(int* arrData, int size)
{
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arrData[i] > arrData[i + 1])
			{
				printf("swapping at %d\n", i);
				swap(arrData, i, i + 1); //*meh*
			}
		}
	}
	printf("after 15*15 loops\n");
	printRawArray(arrData, 15, ", ");
	printf("\n\n");

}

//the following function is recursive, 
// and is included just to show a hint of what is possible out there.
void bubblesort_recurse(int* arrData, int size)
{
	//go through once
	for (int i = 0; i < size - 1; i++)
	{
		if (arrData[i] > arrData[i + 1])
		{
			printf("swapping at %d\n", i);
			swap(arrData, i, i + 1); //*meh*
		}
	}
	//call MYSELF 
	if (size > 1)
	{
		bubblesort_recurse(arrData, size - 1);
	}
	else {
		printRawArray(arrData, 15, ", ");
	}
}


int main()
{
	int arrInput1[] = { 37, 14, 28, 45, 18, 23, 40, 12, 32, 49, 16, 30, 42, 11, 26 };
	int arrInput2[] = { 37, 22, 48, 14, 31, 19, 43, 12, 26, 40, 17, 35, 45, 11, 29 };
	int arrInput3[] = { 36, 22, 47, 15, 31, 19, 43, 28, 12, 39, 25, 41, 18, 34, 48 };
	int iArrSize = 0;
	printf("sizeof(arrInput1) = %d\t\t", sizeof(arrInput1));
	printf("sizeof(arrInput1[0]) = %d", sizeof(arrInput1[0]));

	iArrSize = sizeof(arrInput1) / sizeof(arrInput1[0]);
	printf("iArrSize = %d\n", iArrSize);
	printRawArray(arrInput1, iArrSize, ", ");
	bubblesort_once(arrInput1, iArrSize);
	//bubblesort(arrInput2, iArrSize);
	//bubblesort_recurse(arrInput3, iArrSize);
	return 0;
}