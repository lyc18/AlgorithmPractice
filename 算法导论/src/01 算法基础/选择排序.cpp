#include <iostream>
/**
 * 选择排序升序
 * @param array 需要排序的数组
 * @param array_len 数组长度
 */
void SelectSortAscending(int* array, int array_len) {
    // 选择排序前n-1个元素
    for(int i = 0; i < array_len - 1; ++i)
    {
        // 找到未排序部分最小的元素
        int min_index = i;
        for (int j = i + 1; j < array_len; ++j) {
            if(array[j] < array[min_index])
                min_index = j;
        }

        // 将找到的最小元素与未排序部分首个元素交换
        int tem = array[min_index];
        array[min_index] = array[i];
        array[i] = tem;
    }
}

/**
 * 选择排序降序
 * @param array 需要排序的数组
 * @param array_len 数组长度
 */
void SelectSortDescending(int* array, int array_len) {
    // 选择排序前n-1个元素
    for (int i = 0; i < array_len - 1; ++i) {
        // 找到未排序部分最大元素
        int max_index = i;
        for (int j = i + 1; j < array_len; ++j) {
            if(array[j] > array[max_index])
                max_index = j;
        }

        // 将找到的最大元素与未排序部分首个元素交换
        int tem = array[max_index];
        array[max_index] = array[i];
        array[i] = tem;
    }
}

/**
 * 输出数组
 * @param array 需要输出的数组
 * @param array_len 数组长度
 */
void PrintArray(int* array, int array_len)
{
    for(int i = 0; i < array_len; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int array[] = {12,56,64,16,321,13,46,7,165,49,31,};
    int array_len = 11;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    std::cout << "升序序列" << std::endl;
    SelectSortAscending(array, array_len);
    PrintArray(array, array_len);
    std::cout << "降序序列" << std::endl;
    SelectSortDescending(array, array_len);
    PrintArray(array, array_len);

    return 0;
}