#include "../../utils/iofunction.h"
#include <cstdlib>
#include <ctime>

void exchange(int& a, int& b){
    int tem = b;
    b = a;
    a = tem;
}


/**
 * 将原数组差分, 并返回拆分的主元
 * @param array 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @return 拆分的主元
 */
int patition(int* array, int start_index, int end_index)
{
    // 固定选择最后一个为主元
    int key = array[end_index];
    int i = start_index; // i 指向第一个大于主元的元素
    for(int j = start_index; j < end_index; ++j)
    {
        // 如果array[j]小于等于key则将array[j]与array[i]交换
        if(array[j] <= key)
            exchange(array[j], array[i++]);
    }
    // 分割结束后将主元放在中间
    exchange(array[end_index],array[i]);
    return i;
}

/**
 * 将原数组差分, 并返回拆分的主元, 随机选择主元
 * @param array 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @return 拆分的主元
 */
int patitionRandom(int* array, int start_index, int end_index)
{
    // 生成指定范围的随机数作为主元
    int randomValue = (rand() % (start_index - end_index)) + start_index;//范围[start_index,end_index)

    // 将主元放入最后
    exchange(array[end_index], array[randomValue]);

    return patition(array, start_index, end_index);
}

/**
 * 快速排序, 升序排序
 * @param array 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @return
 */
void QuickSort(int* array, int start_index, int end_index){
    if(start_index < end_index){
        // 将原数组差分, 并获取拆分的主元
        int index = patition(array, start_index, end_index);
        // 递归快速排序子数组
        QuickSort(array, start_index, index - 1);
        QuickSort(array, index + 1, end_index);
    }
}

/**
 * 快速排序, 升序排序， 使用循环减少递归次数
 * @param array 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @return
 */
void QuickSortLoop(int* array, int start_index, int end_index){
    while(start_index < end_index){
        // 将原数组差分, 并获取拆分的主元
        int index = patition(array, start_index, end_index);
        // 递归快速排序子数组
        QuickSort(array, start_index, index - 1);
        start_index = index + 1;
    }
}

/**
 * 快速排序, 升序排序
 * @param array 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @return
 */
void QuickSortRandom(int* array, int start_index, int end_index){
    if(start_index < end_index){
        // 将原数组差分, 并获取拆分的主元
        int index = patitionRandom(array, start_index, end_index);
        // 递归快速排序子数组
        QuickSort(array, start_index, index - 1);
        QuickSort(array, index + 1, end_index);
    }
}


int main(){
    srand(time(nullptr)); // 用当前时间作为种子

    int array[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int array_len = 16;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    std::cout << "普通快速排序" << std::endl;
    QuickSort(array, 0, array_len - 1);
    PrintArray(array, array_len);
    std::cout << "循环快速排序" << std::endl;
    QuickSortLoop(array, 0, array_len - 1);
    PrintArray(array, array_len);
    std::cout << "随机快速排序" << std::endl;
    QuickSortRandom(array, 0, array_len - 1);
    PrintArray(array, array_len);




    return 0;
}
