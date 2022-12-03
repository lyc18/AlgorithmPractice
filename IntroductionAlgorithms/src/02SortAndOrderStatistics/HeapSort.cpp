/**
* 大根堆排序
*/
#include "../../utils/iofunction.h"
#include <limits>
void exchange(int& a, int& b){
    int tem = b;
    b = a;
    a = tem;
}


/**
 * 维护大根堆
 * @param array 原始数组
 * @param m_index 维护下标
 * @param heap_size 堆中元素的长度
 */
// 注意: 树结构以数组形式存储, 操作时以下标为1开始比较方便, 在这种情况下, 只需在每次使用数组中数据时下标-1即可
void MaxHeapMaintain(int* array, int m_index, int heap_size)
{
    // 寻找维护节点与其儿子节点最大值的下标
    int l = m_index * 2;
    int r = m_index * 2 + 1;
    int largest = m_index;
    if(l <= heap_size && array[l-1] > array[m_index-1]) { largest = l; }
    if(r <= heap_size && array[r-1] > array[largest-1]) { largest = r; }

    // 如果儿子节点的值大于父节点, 则交换最大的儿子节点与父节点的位置, 并维护儿子节点的堆性质
    if(largest != m_index)
    {
        exchange(array[largest-1], array[m_index-1]);
        MaxHeapMaintain(array, largest, heap_size);
    }
}

/**
 * 构建大根堆
 * @param array 原始数组
 * @param array_len 堆中元素个数
 */
void BuildMaXHeap(int* array, int array_len)
{
    // 从第一个非叶子节点开始维护堆性质
    for(int i = array_len/2; i > 0; --i)
    {
        MaxHeapMaintain(array, i, array_len); // 注意: 树结构以数组形式存储, 操作时以下标为1开始比较方便, 在这种情况下, 只需在每次使用数组中数据时下标-1即可
    }
}

/**
 * 大根堆排序, 升序排序
 * @param array 原始数组
 * @param array_len 数组长度
 */
void HeapSort(int* array, int array_len)
{
    // 堆中元素个数
    int heap_size = array_len;

    // 构建大根堆
    BuildMaXHeap(array, heap_size);

    // 排序, 每次交换堆首与堆尾元素, 直到堆中元素个数为1
    for(int i = heap_size; i > 0; --i)  // 注意: 树结构以数组形式存储, 操作时以下标为1开始比较方便, 在这种情况下, 只需在每次使用数组中数据时下标-1即可
    {
        exchange(array[i-1], array[0]);
        // 每次排序后heap-size-1并重新维护A[0]位置的堆性质
        heap_size--;
        MaxHeapMaintain(array, 1, heap_size);
    }
}

/**
 * 返回优先队列最大值
 * @param A 优先队列
 * @return 最大值
 */
int MaxMum(int* A){
    return A[0];
}

/**
 *返回并弹出A中具有最大关键字的元素
 * @param A 优先队列
 * @param heapSize 堆中元素
 * @return 最大值
 */
int ExtractMax(int* A, int heapSize){
    // 获取最大值
    int max = A[0];

    // 删除最大值
    A[0] = A[heapSize-1];
    // 维护堆
    MaxHeapMaintain(A, 1, heapSize-1);

    return max;
}

/**
 * 将元素x关键字增加到key
 * @param A 返回并弹出A中具有最大关键字的元素
 * @param x 要增加元素值的下标
 * @param key 增加值
 */
void IncreaseKey(int* A, int x, int key)
{
    if(key < A[x - 1])
        return;
    A[x - 1] = key;
    while(x > 0 && A[x - 1] > A[x / 2 - 1])
    {
        exchange(A[x - 1], A[x / 2 - 1]);
        x = x / 2;
    }
}

/**
 * 增加一个元素x
 * @param A 优先队列
 * @param x 增加的值
 * @param heapSize 堆中元素
 */
void Insert(int* A, int x, int heapSize)
{
    heapSize++;
    A[heapSize - 1] = std::numeric_limits<int>::min();
    IncreaseKey(A,heapSize,x);
}

int main(){
    int array[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int array_len = 16;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    std::cout << "堆排序" << std::endl;
    HeapSort(array, array_len);
    PrintArray(array, array_len);

    return 0;
}