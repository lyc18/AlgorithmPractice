#include <iostream>

/**
 * 插入排序升序排序
 * @param array 需要排序的数组
 * @param array_len 数组长度
 */
void InsertionSortAscending(int* array, int array_len){
    for(int i = 1; i < array_len; ++i)
    {
        // 选择要排序的元素key
        int key = array[i];
        int insert_index = i - 1;

        // 将在key前面且比key大的元素向后移动
        // 直到遇到一个小于等于key的元素
        while(insert_index >= 0 && array[insert_index] > key)
        {/**/
            array[insert_index + 1] = array[insert_index];
            insert_index--;
        }

        // 将元素key放置到有序序列中
        array[insert_index + 1] = key;

    }
}

/**
 * 插入排序降序排序
 * @param array 需要排序的数组
 * @param array_len 数组长度
 */
void InsertionSortDescending(int* array, int array_len){
    for(int i = 1; i < array_len; ++i)
    {
        // 选择要排序的元素key
        int key = array[i];
        int insert_index = i - 1;

        // 将在key前面且比key大的元素向后移动
        // 直到遇到一个大于等于key的元素
        while (insert_index >= 0 && array[insert_index] < key)  // 注意点:可在查找的同时后移元素
        {
            array[insert_index + 1] = array[insert_index];
            insert_index--;
        }

        // 将元素key放置到有序序列中
        array[insert_index + 1] = key;
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
    int array[] = {12,56,64,16,321,13,46,7,16,49,31,};
    int array_len = 11;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    std::cout << "升序序列" << std::endl;
    InsertionSortAscending(array, array_len);
    PrintArray(array, array_len);
    std::cout << "降序序列" << std::endl;
    InsertionSortDescending(array, array_len);
    PrintArray(array, array_len);

    return 0;
}