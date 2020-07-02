#include <iostream>
#include <time.h>
#include <cstdlib>
#define N 10
using namespace std;

// ��������
void HeapSort(int * array);
// ���󶥶Ѻ���
void BuildMaxHeap(int * array);
// ����Ϊ�󶥶Ѻ���
void MaxHeapify(int * array, int n);
// ���ضѵ����ݸ���
int HeapSize;

void HeapSort(int * array)
{
	BuildMaxHeap(array);
	for (int i = N - 1; i >= 0; i--)//�������±��0  -  N-1
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		HeapSize -= 1;
		MaxHeapify(array, 1);//�ڶ��У��Ѷ�Ԫ���±��1��ʼ
	}
}

void BuildMaxHeap(int * array)
{
	HeapSize = N;
	for (int i = N / 2; i >= 1; i--)//ע��i��ȡֵ,�ѵĸ߶ȴ�1  -  N/2
	{
		MaxHeapify(array, i);
	}
}

void MaxHeapify(int * array, int temp)
{
	int largest;//��tempΪ����������ĶѶ�
	int l = 2 * temp;//����tempΪ��������������
	int r = 2 * temp + 1;//����tempΪ����������Ҷ���

	if (l <= HeapSize && array[l - 1] > array[temp - 1])//�����ж�������Ƿ���ڣ���l<=HeapSize
	{
		largest = l;
	}
	else{
		largest = temp;
	}

	if (r <= HeapSize && array[r - 1] > array[largest - 1])//�����ж��Ҷ����Ƿ���ڣ���r<=HeapSize
	{
		largest = r;
	}

	if (largest != temp)
	{
		int t = array[temp - 1];
		array[temp - 1] = array[largest - 1];
		array[largest - 1] = t;
		MaxHeapify(array, largest);//����Ϊ�󶥶�
	}
}

/*=====================================================================*/
/*������ǵݹ��㷨��T(n)=O(nlogn) S(n)=O(1)*/

//����������A[idx]ʹ��A[idx...n]���ɴ󶥶�
void HeapAdjust(int *A, int idx, int n)
{
	int tmp = A[idx];  // ��ȡ����ǰԪ��idx
	for (int j = 2 * idx + 1; j < n; j=2*j+1) { // ��idx�����ӽڵ�2*idx+1��ʼ
		if (j < n - 1 && A[j] < A[j + 1]) { // �����ӽڵ�С�����ӽڵ㣬jָ�����ӽڵ�
			++j;
		}

		if(tmp >= A[j]) {
			break;
		} else {   // �����ڵ�idxС���ӽڵ㣬�ӽڵ㸳ֵ�����ڵ�idx
			A[idx] = A[j];
			idx = j;
		}		
	}
	A[idx] = tmp;
}

int *HeapSort2(int *A, int n)
{
	if (n <= 0)
		return A;
    
	// 1. �����󶥶�
	// �����һ����Ҷ�ӽڵ㿪ʼ�������󶥶�
	for (int i = n / 2 - 1; i >= 0; --i) {
		HeapAdjust(A, i, n-1);
	}

    // 2. �����ѽṹ + �����Ѷ�Ԫ����ĩβԪ��
	for (int i = n - 1; i > 0; --i) {
		int tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;

		HeapAdjust(A, 0, i - 1);
	}

	return A;
}

//int main()
//{
//	//����һ������������
//	int array[N];
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
//	HeapSort(array);
//	for (int k = 0; k < N; k++)
//	{
//		cout << array[k] << "  ";
//	}
//	cout << endl;
//
//	/*�ǵݹ������*/
//
//	system("pause");
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
//	HeapSort2(array,N);
//	for (int k = 0; k < N; k++)
//	{
//		cout << array[k] << "  ";
//	}
//	cout << endl;
//	return 0;
//}


