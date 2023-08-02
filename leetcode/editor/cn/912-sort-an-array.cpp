//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 104 
// -5 * 104 <= nums[i] <= 5 * 104 
// 
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 
// 👍 871 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> tmp;

    vector<int> sortArray(vector<int> &nums) {
        // 在 C++ 中，没有获取数组长度的函数，要数组数组的长度，我们可以使用 sizeof 首先获取整个数组的占用字节大小，
        // 再次使用 sizeof 获取单个元素的内存大小，最后相除得到数组长度
        int n = nums.size();
        doSort(nums, 0, n - 1);
        return nums;
    }

    void doSort(vector<int> &nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (high + low) / 2;
        doSort(nums, low, mid);
        doSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    // 合并nums[low..mid] nums[mid+1,high]
    void merge(vector<int> &nums, int low, int mid, int high) {
        tmp.clear();
        for (int i = low; i <= high; i++) {
            tmp.push_back(nums[i]);
        }

        // 数组双指针技巧，合并两个有序数组
        int p1 = low, p2 = mid + 1, p = low;
        for (; p1 <= mid && p2 <= high;) {
            if (tmp[p1 - low] <= tmp[p2 - low]) {
                nums[p] = tmp[p1 - low];
                p1++;
            } else {
                nums[p] = tmp[p2 - low];
                p2++;
            }
            p++;
        }

        for (; p1 <= mid;) {
            nums[p] = tmp[p1 - low];
            p1++;
            p++;
        }

        for (; p2 <= high;) {
            nums[p] = tmp[p2 - low];
            p2++;
            p++;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    vector<int> res = s.sortArray(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}