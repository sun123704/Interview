/*
����һ��int���飬���дһ��ѡ�������㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;
int *SelectionSort(int *A, int n)
{
	if (n <= 0)
		return A;

	/*����n-1��ѡ��*/
	for (int i = 0; i < n - 1; ++i)
	{
		/*ÿ��ѡ���ҵ�i��n-1����СԪ��λ�ã�����iλ��*/
		int minPos = i;
		for (int j = i+1; j < n; ++j)
		{
			if (A[j] < A[minPos])
			{
				minPos = j;
			}//if
		}//for

		/*����СԪ�ط��ڴ���ѡ�����λ*/
		int tmp = A[i];
		A[i] = A[minPos];
		A[minPos] = tmp;
	}//for
	return 0;
}

//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	SelectionSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}