# 堆排序 HeapSort.cpp
堆是一种完全二叉树：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。对堆中的结点按层进行编号，映射到数组中，用公式描述堆的定义就是：

** 大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2] **
** 小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2] **
一般升序排序用大顶堆，降序排序用小顶堆。

## 步骤1
构造初始堆，将无序序列构造成大顶堆：从最后一个非叶子节点开始，下标是** arr.length/2-1 **。根据大顶堆性质调整父节点与子节点位置。
## 步骤2
完成步骤1后即找到了最大元素，将堆顶与末尾元素交换，继续步骤1，找到第二大元素，如此循环。