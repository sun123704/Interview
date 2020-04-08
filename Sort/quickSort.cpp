/*
����һ��int���飬���дһ���鲢�����㷨��������Ԫ������
����һ��int����A������Ĵ�Сn���뷵�����������顣
����������
[1,2,3,5,2,3],6
[1,2,2,3,3,5]
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

/*���ֺ���*/
int partition(int *A, int left, int right);
/*�ݹ�ʵ��*/
void QuickSort(int *A, int left, int right);
/*�ǵݹ�ʵ��*/
void QuickSort2(int *A, int left, int right);

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = a;
}

int partition(int *A, int left, int right)
{
	///*���ѡ��*/
	srand((int)time(NULL));
	int pos = left + (rand() % (right - left + 1));
	///*����*/
	swap(A[pos], A[right]);

	/*�������С�ڵ�������{}����ʼ��Ϊleft���*/
	int lessPos = left - 1;
	int pivot = A[right];
	for (int i = left; i < right; ++i)
	{
		if (A[i] <= pivot)
		{
			/*��������С�ڵ�������β������*/
			++lessPos;
			swap(A[lessPos], A[i]);
		}//if
	}
	swap(A[lessPos + 1], A[right]);
	return lessPos + 1;
}


/*��������*/
int *QuickSort(int *A, int n)
{
	if (A == NULL || n <= 0)
		return A;
	QuickSort2(A, 0, n-1);
	return A;
}


/*��������ĵݹ�ʵ��*/
void QuickSort(int *A, int left, int right)
{
	if (left < right)
	{
		int pos = partition(A, left, right);
		QuickSort(A, left, pos - 1);
		QuickSort(A, pos + 1, right);
	}//if
}

/*��������ķǵݹ�ʵ��*/
void QuickSort2(int *A, int left, int right)
{
	stack<int> st;
	if (left < right)
	{
		int mid = partition(A, left, right);
		if (left < mid - 1)
		{
			st.push(left);
			st.push(mid - 1);
		}//if

		if (right > mid + 1)
		{
			st.push(mid + 1);
			st.push(right);
		}//if

		/*��ʵ������ջ����ÿһ���������Ӵ�����βԪ���±꣬
		��һ��whileѭ��ʱȡ�������Χ������������н���partition����*/
		while (!st.empty())
		{
			int rhs = st.top();
			st.pop();
			int lhs = st.top();
			st.pop();

			mid = partition(A, lhs, rhs);

			if (lhs < mid - 1)
			{
				st.push(lhs);
				st.push(mid - 1);
			}//if

			if (rhs > mid + 1)
			{
				st.push(mid + 1);
				st.push(rhs);
			}//if
		}//while
	}//if

}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 2, 3 };
//	QuickSort(arr, 6);
//
//	for (int i = 0; i < 6; ++i)
//		cout << arr[i] << "\t";
//	cout << endl;
//	system("pause");
//	return 0;
//}