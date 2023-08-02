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
    int res = 0;

    int reversePairs(vector<int> &nums) {
        doSort(nums, 0, nums.size() - 1);
        return res;
    }

    void doSort(vector<int> &nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        doSort(nums, low, mid);
        doSort(nums, mid + 1, high);
        merge(nums, low, mid, high);

    }

    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> tmp;
        for (int i = low; i <= high; i++) {
            tmp.push_back(nums[i]);
        }

        // 数组双指针技巧，合并两个有序数组
        // p1-low,p2-low 是为了定位到p1,p2指向的tmp元素的位置
        int p1 = low, p2 = mid + 1, p = low;
        for (; p1 <= mid || p2 <= high;) {
            if (p1 > mid) {
                nums[p++] = tmp[p2 - low];
                p2++;
            } else if (p2 > high) {
                nums[p++] = tmp[p1 - low];
                p1++;
            } else if (tmp[p1 - low] <= tmp[p2 - low]) {
                nums[p++] = tmp[p1 - low];
                p1++;
            } else {
                // 这句是关键，就是说 p1 指向左侧数组的元素值大于 p2 指向的右侧数组元素时，那么此时 p1 的右边元素[在左侧数组] 也肯定是大于 p2所指向的元素值的
                res = res + (mid - p1) + 1;
                nums[p++] = tmp[p2 - low];
                p2++;
            }
        }
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