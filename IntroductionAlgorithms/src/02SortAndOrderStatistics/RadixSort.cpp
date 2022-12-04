/**
* 大根堆排序
*/
#include "../../utils/iofunction.h"
#include <limits>
#include <vector>

// 设置基数为10
#define NUM_RADIX 10
// 假设数的范围为 0-100
#define NUM_RANGE 100
void exchange(int& a, int& b){
    int tem = b;
    b = a;
    a = tem;
}


/**
 * 计数排序, 升序排序
 * @param A 原始数组
 * @param B 结果数组
 * @param len 数组长度
 * @param k 数组的范围
 */
void CountingSort(int* A, int* B, int len, int const k)
{
    // 建立计数数组
    std::vector<int> count_array(k);

    // 树池话计数数组
    for(int i = 0; i < k; ++i){
        count_array[i] = 0;
    }

    // 对排数数组中的元素计数
    for(int i = 0; i < len; ++i)
    {
        count_array[A[i]]++;
    }

    // 有计数信息转为下标信息
    for(int i = 1; i < k; ++i){
        count_array[i] += count_array[i-1];
    }

    // 根据计数信息排序
    for(int i = len - 1; i >= 0; --i)
    {
        B[count_array[A[i]] - 1] = A[i];
        count_array[A[i]]--;
    }
}

/**
 * 基数排序, 升序排序
 * @param A 原始数组
 * @param len 数组长度
 * @param d 位数
 */
void RadixSort(int* A, int len, int d){

}

int main(){
    int array[] = {13,3,25,20,3,16,23,18,20,7,12,5,22,15,4,7};
    const int array_len = 16;
    int B[array_len];
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    std::cout << "堆排序" << std::endl;
    CountingSort(array, B, array_len, 100);
    PrintArray(B, array_len);

    return 0;
}