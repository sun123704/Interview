/*
����һ��int���飬���дһ�����������㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*ֱ�Ӳ�������*/
int *IntertionSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;

	/*�������е�i=1~i=n-1��Ԫ������ѡ�����λ�ò���*/
	for (int i = 1; i < n; ++i)
	{
		/*Ҫ�����Ԫ��*/
		int tmp = A[i];
		/*������������β��ǰѰ�Һ���λ��*/
		int j = i - 1;
		for (; j >= 0; --j)
		{
			if (A[j] > tmp)
				A[j + 1] = A[j];
			else
				break;
		}//for
		A[j + 1] = tmp;
	}
	return A;
}

//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	IntertionSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}
