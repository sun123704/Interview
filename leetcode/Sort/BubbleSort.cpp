/*
����һ��int���飬���дһ��ð�������㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*�����³� T(n)=O(n^2) S(n)=O(1) �ȶ�*/
int *BubbleSort(int *A, int n)
{
	if (n <= 0)
		return A;

	/*����n-1��ð��*/
	for (int i = 0; i < n - 1; ++i)
	{
		/*ÿ��ð�����ͷ��n-i-1β�ȽϹ���*/
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (A[j] > A[j + 1])
			{
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}//if
		}//for
	}//for
	return A;
}

/*С������ T(n)=O(n^2) S(n)=O(1) �ȶ�*/
int *BubbleSort2(int *A, int n)
{
	if (n <= 0)
		return A;

	/*����n-1��ð��*/
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (A[j] < A[j - 1])
			{
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j-1] = tmp;
			}//if
		}
	}

	return A;
}

/*ð�������Ż�*/
int *BubbleSort3(int *A, int n)
{
	if (n <= 0)
		return A;

	/*����n-1��ð��*/
	bool flag = true;
	for (int i = 0; i < n - 1 && flag; ++i)
	{
		flag = false;
		for (int j = n - 1; j > i; --j)
		{
			if (A[j] < A[j - 1])
			{
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j-1] = tmp;

				flag = true;
			}//if
		}
	}
	return A;
}
//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	BubbleSort3(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}