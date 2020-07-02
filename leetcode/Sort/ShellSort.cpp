/*
����һ��int���飬���дһ��ϣ�������㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*ϣ������*/
void ShellSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return;

	/*��������*/
	int d = n;
	while (d > 1)
	{
		d = (d + 1) / 2;
		for (int i = d; i < n; ++i)
		{						
			/*Ҫ�����Ԫ��*/
			int tmp = A[i];
			/*������������β��ǰѰ�Һ���λ��*/
			int j = i-d;
			for (; j >= 0; j-=d)
			{
				if (A[j] > tmp)
					A[j + d] = A[j];
				else
					break;
			}//for
			A[j + d] = tmp;
		}//for
	}//while
}


//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	ShellSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}