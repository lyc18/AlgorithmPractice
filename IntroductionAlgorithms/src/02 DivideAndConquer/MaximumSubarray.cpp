#include "../../utils/iofunction.h"
#include <vector>
#include <limits>

/**
 * 分治法求包含mid的最大子数组
 * @param array 原始数组
 * @param start_index 起始下标
 * @param mid_index 中间(被包含的)下标
 * @param end_index 结束下标
 * @return {最大子数组起始下标, 最大子数组结束下标, 最大子数组和}
 */
std::vector<int> FindMaxCrossingSubarray(int* array, int start_index, int mid_index, int end_index){
    // 定义返回变量
    std::vector<int> ret(3);

    // 定义变量,记录当前左右两边最大和,以及相应的下标
    int l_sum_max = 0;
    int r_sum_max = 0;
    int l_max_index = mid_index;
    int r_max_index = mid_index + 1;

    // 累计和
    int sum = 0;

    // 寻找左边最大子数组
    for(int i = mid_index; i >= start_index; --i){
        // 若累计和比当前和最大,则更新当前信息
        sum += array[i];
        if(sum >= l_sum_max)
        {
            l_sum_max = sum;
            l_max_index = i;
        }
    }

    // 寻找右边最大子数组
    sum = 0;
    for(int i = mid_index + 1; i <= end_index; ++i){
        // 若累计和比当前和最大,则更新当前信息
        sum += array[i];
        if(sum >= r_sum_max)
        {
            r_sum_max = sum;
            r_max_index = i;
        }
    }

    // 合并左右最大子数组
    ret.push_back(l_max_index);
    ret.push_back(r_max_index);
    ret.push_back(l_sum_max + r_sum_max);

    return ret;
}

/**
 * 分治法求最大子数组 O(nlgn)
 * @param array 原始数组
 * @param start_index 起始下标
 * @param end_index 结束下标
 * @return {最大子数组起始下标, 最大子数组结束下标, 最大子数组和}
 */
std::vector<int> FindMaximumSubarray(int* array, int start_index, int end_index){
    // 如果长度为1, 则最大子数组为其本身
    if(start_index == end_index){
        std::vector<int> ret = {start_index, end_index, array[start_index]};
        return ret;
    }else{ // 使用分治法求最大子数组

        // 将原始数组分为两部分, 分别求最大子数组
        int mid = (start_index + end_index) / 2;

        // 递归求仅在单个子数组中的最大子数组
        std::vector<int> l_max = FindMaximumSubarray(array, start_index, mid);
        std::vector<int> r_max = FindMaximumSubarray(array, mid + 1, end_index);

        // 求跨越两个子数组的最大子数组
        std::vector<int> m_max = FindMaxCrossingSubarray(array, start_index, mid, end_index);

        // 返回三种情况中最大的最大子数组
        if(l_max[2] > r_max[2] && l_max[2] > m_max[2])
            return l_max;
        else if (r_max[2] > l_max[2] && r_max[2] > m_max[2])
            return r_max;
        else
            return m_max;
    }
}

/**
 * 动态规划法求最大子数组 O(n)
 * @param array 原始数组
 * @param array_len 数组长度
 * @return {最大子数组起始下标, 最大子数组结束下标, 最大子数组和}
 */
std::vector<int> FindMaximumSubarrayDP(int* array, int array_len){
    // 定义返回变量
    std::vector<int> ret;

    // 定义变量,记录当前最大和,以及相应的左右下标
    int sum_max = std::numeric_limits<int>::min();
    int l_max_index = 0;
    int r_max_index = 0;

    // 包含子数组末尾的累计和
    int sum = 0;
    int l_tem_index = 0;
    int r_tem_index = 0;
    for(int i = 1; i < array_len; ++i){
//        if(sum + array[i] <= array[i]){
//            sum = array[i];
//            l_tem_index = i;
//            r_tem_index = i;
//        }else{
//            sum = sum + array[i];
//            r_tem_index = i;
//        }
//
//        if(sum_max < sum)
//        {
//            sum_max = sum;
//            l_max_index = l_tem_index;
//            r_max_index = r_tem_index;
//        }
sum = sum + array[i] > array[i] ? sum + array[i] : array[i];
sum_max = sum_max > sum ? sum_max : sum;
    }

    // 合并左右最大子数组
    ret.push_back(l_max_index);
    ret.push_back(r_max_index);
    ret.push_back(sum_max);

    return ret;
}
int main(){
    int array[] = {12,56,64,16,321,13,46,7,165,49,31,};
    int array_len = 11;
    std::cout << "原始序列" << std::endl;
    PrintArray(array, array_len);
    std::cout << "分治法找最大子数组" << std::endl;
    std::vector<int> ret = FindMaximumSubarray(array, 0, array_len - 1);
    PrintArray(ret, ret.size());
    std::cout << "动态规划法找最大子数组" << std::endl;
    std::vector<int> ret_dp = FindMaximumSubarrayDP(array, array_len);
    PrintArray(ret_dp, ret_dp.size());
    return 0;
}
