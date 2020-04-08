/*
����һ��int���飬���дһ���鲢�����㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int* MergeSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;

	MergeSort(A, 0, n - 1);
	return A;
}

void MergeSort(int *A, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(A, left, mid);
	MergeSort(A, mid + 1, right);

	Merge(A, left, mid, right);
}

/*��������left~mid��mid+1~right���������кϲ�*/
void Merge(int *A, int left, int mid, int right)
{
	int *tmp = new int[right - left + 1];
	/*�ϲ�������Ԫ�ص�tmp��ʱ����*/
	int lhs = left, rhs = mid + 1, k = 0;
	while (lhs <= mid && rhs <= right)
	{
		if (A[lhs] <= A[rhs])
			tmp[k++] = A[lhs++];
		else
			tmp[k++] = A[rhs++];
	}//while

	/*ֱ�ӿ���ʣ��Ԫ��*/
	while (lhs <= mid)
	{
		tmp[k++] = A[lhs++];
	}//while

	while (rhs <= right)
	{
		tmp[k++] = A[rhs++];
	}//while

	/*������ʱ�������ݵ�ԭ����*/
	for (int i = left; i <= right; ++i)
	{
		A[i] = tmp[i - left];
	}//for

	delete[]tmp;
}

/*=====================================================*/
/*�ǵݹ�ʵ�ֹ鲢����*/

void Merge(int *arr3, int *arr1, int begin, int m, int end) {
	int i = begin, j = m + 1, k, h;
	for (k = i; i <= m && j <= end; k++) {
		if (arr3[i] < arr3[j])
			arr1[k] = arr3[i++];
		else
			arr1[k] = arr3[j++];
	}
	if (i <= m) {
		for (h = 0; h <= m - i; h++)
			arr1[k + h] = arr3[i + h];
	}
	else {
		for (h = 0; h <= end - j; h++)
			arr1[k + h] = arr3[j + h];
	}
}

void MergePass(int *s, int *t, int k, int n)
{
	int i = 0;
	while (i <= n - 2 * k)
	{
		Merge(s, t, i, i + k - 1, i + 2 * k - 1);
		i += 2 * k;
	}//while

	//���ʣ�������һ��k���Ȼ���...��ô���ڽ���һ�κϲ�
	if (i < n - k + 1)
		Merge(s, t, i, i + k - 1, n-1);
	else
		for (int j = i; j < n; ++j)
			t[j] = s[j];

	for (i = 0; i < n; ++i)
	{
		s[i] = t[i];
	}//for
}

/*�ǵݹ�������*/
int *MergeSort2(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;
	int *ret = new int[n + 1];
	int k = 1;
	while (k < n)
	{
		MergePass(A, ret, k, n);
		k *= 2;
	}
	return A;
}


//int main()
//{
//	const int N = 10;
//	int array[N];
//	srand(time(0));
//	for (int i = 0; i < N; i++)
//	{
//		array[i] = rand() % 101;//���鸳ֵʹ�������������1-100֮��������   
//	}
//	cout << "����ǰ��" << endl;
//	for (int j = 0; j < N; j++)
//	{
//		cout << array[j] << "  ";
//	}
//	MergeSort(array, 6);
//	cout << endl << "�����" << endl;
//	for (int i = 0; i < N; ++i)
//		cout << array[i] << "  ";
//	cout << endl;
//
//	//������������ӣ�����ÿ�β�����ͬ������� 
//	srand(time(0));
//	for (int i = 0; i < N; i++)
//	{
//		array[i] = rand() % 101;//���鸳ֵʹ�������������1-100֮��������   
//	}
//	cout << "����ǰ��" << endl;
//	for (int j = 0; j < N; j++)
//	{
//		cout << array[j] << "  ";
//	}
//	cout << endl << "�����" << endl;
//	//���ö��������Ը������������   
//	MergeSort2(array,N);
//	for (int k = 0; k < N; k++)
//	{
//		cout << array[k] << "  ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}