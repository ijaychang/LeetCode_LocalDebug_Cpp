//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 
// 👍 1036 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        vector<int> tmp(nums.begin(),nums.end());
        return mergeSort(nums, 0, nums.size() - 1, tmp);
    }

    int mergeSort(vector<int> &nums, int low, int high,vector<int> &tmp) {
        if (low >= high) {
            return 0;
        }
        // 数组双指针技巧，合并两个有序数组
        // p1-low,p2-low 是为了定位到p1,p2指向的tmp元素的位置
        int mid = (low + high) / 2;
        int left_res = mergeSort(nums, low, mid, tmp);
        int right_res = mergeSort(nums, mid + 1, high, tmp);

        for (int i = low; i <= high; i++) {
            tmp[i] = nums[i];
        }

        int p1 = low, p2 = mid + 1, p = low, res = left_res + right_res;
        for (; p1 <= mid || p2 <= high;) {
            if (p1 > mid) {
                nums[p++] = tmp[p2++];
            } else if (p2 > high) {
                nums[p++] = tmp[p1++];
            } else if (tmp[p1] <= tmp[p2]) {
                nums[p++] = tmp[p1++];
            } else {
                // 这句是关键，就是说 p1 指向左侧数组的元素值大于 p2 指向的右侧数组元素时，那么此时 p1 的右边元素[在左侧数组] 也肯定是大于 p2所指向的元素值的
                res = res + (mid - p1) + 1;

                // 打印所有逆序对
//                for (int i = p1 ; i <= mid ; i ++) {
//                    cout << tmp[i] << "->" << tmp[p2] << endl;
//                }

                nums[p++] = tmp[p2++];
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums{7, 5, 6, 4};

    int res = s.reversePairs(nums);
    cout << res << endl;

    for (auto v : nums) {
        cout << v << endl;
    }
}