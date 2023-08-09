//给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是 nums[i] 右侧小于 n
//ums[i] 的元素的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,6,1]
//输出：[2,1,1,0] 
//解释：
//5 的右侧有 2 个更小的元素 (2 和 1)
//2 的右侧仅有 1 个更小的元素 (1)
//6 的右侧有 1 个更小的元素 (1)
//1 的右侧有 0 个更小的元素
// 
//
// 示例 2： 
//
// 
//输入：nums = [-1]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：nums = [-1,-1]
//输出：[0,0]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 
// 👍 1002 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> countSmaller(vector<int> &nums) {
        // 初始化tmp
        int sz = nums.size();
        vector<int> tmp(nums.begin(), nums.end());
        vector<int> indexes(sz, 0);
        vector<int> tmp_indexes(sz, 0);
        vector<int> res(sz, 0);
        for (int i = 0; i < sz; i++) {
            indexes[i] = i;
            tmp_indexes[i] = i;
        }

        mergeSort(nums, 0, sz - 1, tmp, indexes, tmp_indexes, res);
        return res;
    }

    void
    mergeSort(vector<int> &nums, int low, int high, vector<int> &tmp, vector<int> &indexes, vector<int> &tmp_indexes,
              vector<int> &res) {
        if (low >= high) {
            return;
        }

        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, tmp, indexes, tmp_indexes, res);
        mergeSort(nums, mid + 1, high, tmp, indexes, tmp_indexes, res);

        // 左侧，右侧数组排好序后，重置tmp,同时更新indexes
        for (int i = low; i <= high; i++) {
            tmp[i] = nums[i];
            tmp_indexes[i] = indexes[i];
        }

        // 数组双指针技巧，合并两个有序数组
        int p1 = low, p2 = mid + 1, p = low;
        for (; p1 <= mid && p2 <= high;) {
            if (tmp[p1] <= tmp[p2]) {
                res[tmp_indexes[p1]] = res[tmp_indexes[p1]] + p2 - mid - 1;
                indexes[p] = tmp_indexes[p1];
                nums[p++] = tmp[p1++];
            } else if (tmp[p1] > tmp[p2]) {
                indexes[p] = tmp_indexes[p2];
                nums[p++] = tmp[p2++];
            }
        }

        for (; p1 <= mid;) {
            res[tmp_indexes[p1]] = res[tmp_indexes[p1]] + high - mid;
            indexes[p] = tmp_indexes[p1];
            nums[p++] = tmp[p1++];
        }
        for (; p2 <= high;) {
            indexes[p] = tmp_indexes[p2];
            nums[p++] = tmp[p2++];
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums{-1,-1};
    // vector<int> nums{9, 9, 8, 8, 7};
    vector<int> res = s.countSmaller(nums);
    cout << "###################################" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}