//给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 uppe
//r）之内的 区间和的个数 。 
//
// 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。 
//
// 
//示例 1：
//
// 
//输入：nums = [-2,5,-1], lower = -2, upper = 2
//输出：3
//解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0], lower = 0, upper = 0
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -231 <= nums[i] <= 231 - 1 
// -105 <= lower <= upper <= 105 
// 题目数据保证答案是一个 32 位 的整数 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 
// 👍 551 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int res = 0;

    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int sum = mergeSort(nums, 0, nums.size() - 1, lower, upper);
        if (sum >= lower && sum <= upper) {
            cout << sum << endl;
            res++;
        }
        return res;
    }

    int mergeSort(vector<int> &nums, int low, int high, int lower, int upper) {
        if (low >= high) {
            return nums[low];
        }

        int mid = (low + high) / 2;
        int leftSum = mergeSort(nums, low, mid, lower, upper);
        int rightSum = mergeSort(nums, mid + 1, high, lower, upper);

        // 还要考虑一个问题，就是左侧数组的最后一个元素，与右侧数组的第一个元素的和
        // 且左数组，右数组均大于1个数
        if (mid - low > 0 && high - mid - 1 > 0) {
            if (nums[mid] == INT32_MIN)
            int sumBoundary = nums[mid] + nums[mid + 1];
            if (sumBoundary >= lower && sumBoundary <= upper) {
                cout << sumBoundary << endl;
                res++;
            }
        }
        if (leftSum >= lower && leftSum <= upper) {
            cout << leftSum << endl;
            res++;
        }
        if (rightSum >= lower && rightSum <= upper) {
            cout << rightSum << endl;
            res++;
        }
        return leftSum + rightSum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums{2147483647, -2147483648, -1, 0};
    int res = s.countRangeSum(nums, -1, 0);
    cout << res << endl;
}