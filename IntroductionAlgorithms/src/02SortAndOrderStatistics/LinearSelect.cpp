#include "../../utils/iofunction.h"
#include <vector>

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
int patition(std::vector<int>& array, int start_index, int end_index)
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
int patitionSelect(std::vector<int>& array, int start_index, int end_index, int select_key)
{
    int select_index;
    for(int i = start_index; i <= end_index; ++i)
    {
        if(array[i] == select_key)
        {
            select_index = i;
            break;
        }
    }

    // 将主元放入最后
    exchange(array[end_index], array[select_index]);

    return patition(array, start_index, end_index);
}

/**
 * 插入排序
 * @param A 排序数组
 * @param size 数组实际元素大小
 */
void InsertSort(std::vector<int>& A, int start_index, int end_index){
    for(int i = start_index + 1; i <= end_index; ++i)
    {
        int key = A[i];
        int index = i - 1;
        while(index >= start_index && A[index] > key) {
            A[index + 1] = A[index];
            index--;
        }

        A[index + 1] = key;
    }
}

/**
 * 寻找主元
 * @param A 数组
 * @param len 数组长度
 * @return 主元
 */
int KeySelect(std::vector<int> A, int start_index, int end_index, int len){
    // 定义出口
    if(len < 5)
    {
        InsertSort(A, start_index, end_index);
        return A[len/2];
    }

    // 将数组分组,每组有5个元素
    std::vector<int> tem(5);
    std::vector<int> mid;
    int size = 0;
    // 利用插入排序查找每组的中值
    for(int i = start_index; i < end_index; i+=5){
        size = 0;
        for(int j = 0; j < 5 && i + j < end_index; j++)
        {
            tem[j] = A[i+j];
            size++;
        }
        InsertSort(tem, 0, size - 1);
        mid.push_back(tem[size/2]);
    }
    // 查找中值的中值
    return KeySelect(mid, 0, mid.size() - 1, mid.size());
}

/**
 * 选择数组中第min_num小元素(min_num 小于数组长度)
 * @param A 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @param min_num
 * @return
 */
int LinearSelect(std::vector<int>& A, int start_index, int end_index, int min_num){
    // 选择主元
    int key = KeySelect(A, start_index, end_index, (end_index - start_index) + 1);
    // 对数组进行一次快速排序
    int q = patitionSelect(A, start_index, end_index, key);
    // 计算主元是第几小元素
    int k = q - start_index + 1;
    // 如果主元就是第min_num小元素, 则返回主元
    if(k == min_num)
        return A[q];
    else if(k > min_num) // 如果主元比第min_num小元素大, 则递归先择左侧元素
        return LinearSelect(A, start_index, q - 1, min_num);
    else // 如果主元比第min_num小元素小, 则递归先择右侧元素
        return LinearSelect(A, q + 1, end_index, min_num - k);
}



int main(){
    srand(time(nullptr)); // 用当前时间作为种子

    std::vector<int> array = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int array_len = 16;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    int r = LinearSelect(array, 0, array_len - 1, 5);
    std::cout << "第5小的元素是:" << r << std::endl;
    return 0;
}
