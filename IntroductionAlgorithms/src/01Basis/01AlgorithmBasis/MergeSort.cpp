#include <iostream>
#include <vector>
#include <limits>

/**
 * 升序排序合并操作
 * @param array 排序数组
 * @param start_index 排序开始下标(第一段有序序列起始下标)
 * @param mid_index 中间下标(第一段有序序列结束下标)
 * @param end_index 排序结束下标(第二段有序序列结束下标)
 */
void MergeAscending(int* array, int start_index,int mid_index, int end_index)
{
    // 声明两个vector存储需要排序的两段序列
    std::vector<int> L;
    std::vector<int> R;

    // 将原始数组中两段有序的序列复制到L,R中
    for(int i = start_index; i <= mid_index; ++i)  // 注意:i的取值范围,start_index<= i <=mid_index
    {
        L.push_back(array[i]);
    }
    for (int i = mid_index + 1; i <= end_index; ++i) { // 注意:i的取值范围,mid_index + 1 <= i <= end_index
        R.push_back(array[i]);
    }

    // 合并两个有序序列
#if 0
    auto i = L.begin();
    auto j = R.begin();
    int index = start_index;
    while(i != L.end() && j != R.end()) {
        if(*i <= *j)
        {
            array[index++] = *i;
            i++;
        }else{
            array[index++] = *j;
            j++;
        }
    }

    while(i != L.end()) {
        array[index++] = *i;
        i++;
    }
    while(j != R.end()) {
        array[index++] = *j;
        j++;
    }
#else
    L.push_back(std::numeric_limits<int>::max());
    R.push_back(std::numeric_limits<int>::max());
    auto i = L.begin();   // 注意:使用begin()后最好不要修改原始vector, 因为修改原始vector后其存储空间位置可能改变
    auto j = R.begin();
    for(int index = start_index; index <= end_index; ++index) {
        if(*i <= *j)
        {
            array[index] = *i;
            i++;
        } else{
            array[index] = *j;
            j++;
        }
    }
#endif
}

/**
 * 降序排序合并操作
 * @param array 排序数组
 * @param start_index 排序开始下标(第一段有序序列起始下标)
 * @param mid_index 中间下标(第一段有序序列结束下标)
 * @param end_index 排序结束下标(第二段有序序列结束下标)
 */
void MergeDescending(int* array, int start_index,int mid_index, int end_index)
{
    // 声明两个vector存储需要排序的两段序列
    std::vector<int> L;
    std::vector<int> R;

    // 将原始数组中两段有序的序列复制到L,R中
    for(int i = start_index; i <= mid_index; ++i)
    {
        L.push_back(array[i]);
    }
    for (int i = mid_index + 1; i <= end_index; ++i) {
        R.push_back(array[i]);
    }
    // 在最后加上int的最小值防止越界
    L.push_back(std::numeric_limits<int>::min());
    R.push_back(std::numeric_limits<int>::min());

    // 合并
    auto i = L.begin();
    auto j = R.begin();
    for(int index = start_index; index <= end_index; ++index){
        if(*i >= *j)
        {
            array[index] = *i;
            ++i;
        } else{
            array[index] = *j;
            ++j;
        }
    }
}

/**
 * 递归归并排序, 升序排序
 * @param array 排序数组
 * @param start_index 排序开始下标
 * @param end_index 排序结束下标
 */
void MergeSortAscending(int* array, int start_index, int end_index) {
    // 如果当前所需排序序列长度不为1, 则递归归并排序
    if(start_index < end_index)
    {
        int mid = (start_index + end_index) / 2;
        MergeSortAscending(array, start_index, mid);
        MergeSortAscending(array, mid + 1, end_index);
        MergeAscending(array,start_index, mid, end_index);
    }
}

/**
 * 递归归并排序, 降序排序
 * @param array 排序数组
 * @param start_index 排序开始下标
 * @param end_index 排序结束下标
 */
void MergeSortDescending(int* array, int start_index, int end_index) {
    // 如果当前所需排序序列长度不为1, 则递归归并排序
    if (start_index < end_index){
        int mid = (start_index + end_index) / 2;
        MergeSortDescending(array, start_index, mid);
        MergeSortDescending(array, mid + 1, end_index);
        MergeDescending(array, start_index, mid, end_index);
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

int main() {
    int array[] = {12,56,64,16,321,13,46,7,16,49,31,};
    int array_len = 11;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    std::cout << "升序序列" << std::endl;
    MergeSortAscending(array,0, array_len - 1);
    PrintArray(array, array_len);
    std::cout << "降序序列" << std::endl;
    MergeSortDescending(array, 0, array_len - 1);
    PrintArray(array, array_len);

    return 0;
}