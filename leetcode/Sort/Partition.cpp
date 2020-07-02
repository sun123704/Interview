int Partition(int *arr, int start, int end, int pivotIndex) {
	if(arr == NULL || start > end) return -1;
	int pivot = arr[pivotIndex];
	Swap(arr, end, pivotIndex);  // 把pivot放在末尾
	int startIndex = start;      // 分界坐标初始化
	for (int i = start; i < end; i++) {
		if (arr[i] < pivot) {
			Swap(arr, i, startIndex);
			startIndex++;
		}
	}
	Swap(arr, end, startIndex);
	return startIndex;
}