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
 * 选择数组中第min_num小元素(min_num 小于数组长度)
 * @param A 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @param min_num
 * @return
 */
int RandomiedSelect(int* A, int start_index, int end_index, int min_num){
    // 如果只有一个元素则直接返回
    if(start_index == end_index)
        return A[start_index];
    // 对数组进行一次快速排序
    int q = patitionRandom(A, start_index, end_index);
    // 计算主元是第几小元素
    int k = q - start_index + 1;
    // 如果主元就是第min_num小元素, 则返回主元
    if(k == min_num)
        return A[q];
    else if(k > min_num) // 如果主元比第min_num小元素大, 则递归先择左侧元素
        return RandomiedSelect(A, start_index, q - 1, min_num);
    else // 如果主元比第min_num小元素小, 则递归先择右侧元素
        return RandomiedSelect(A, q + 1, end_index, min_num - k);
}



int main(){
    srand(time(nullptr)); // 用当前时间作为种子

    int array[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int array_len = 16;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    int r = RandomiedSelect(array, 0, array_len - 1, 5);
    std::cout << "第5小的元素是:" << r << std::endl;
    return 0;
}
