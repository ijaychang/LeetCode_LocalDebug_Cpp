//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。 
//
// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。 
//
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并
//的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//输出：[1,2,2,3,5,6]
//解释：需要合并 [1,2,3] 和 [2,5,6] 。
//合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]
//解释：需要合并 [1] 和 [] 。
//合并结果是 [1] 。
// 
//
// 示例 3： 
//
// 
//输入：nums1 = [0], m = 0, nums2 = [1], n = 1
//输出：[1]
//解释：需要合并的数组是 [] 和 [1] 。
//合并结果是 [1] 。
//注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m + n 
// nums2.length == n 
// 0 <= m, n <= 200 
// 1 <= m + n <= 200 
// -109 <= nums1[i], nums2[j] <= 109 
// 
//
// 
//
// 进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？ 
// Related Topics 数组 双指针 排序 
// 👍 1947 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    版本一
//    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
//        vector<int> tmp;
//        for (int i = 0; i < nums1.size(); i++) {
//            tmp.push_back(nums1[i]);
//        }
//
//        int p1 = 0, p2 = 0, p = 0;
//        for (; p1 <= m - 1 && p2 <= n - 1;) {
//            if (tmp[p1] <= nums2[p2]) {
//                nums1[p++] = tmp[p1++];
//            } else {
//                nums1[p++] = nums2[p2++];
//            }
//        }
//
//        for (; p1 <= m - 1;) {
//            nums1[p++] = tmp[p1++];
//        }
//
//        for (; p2 <= n - 1;) {
//            nums1[p++] = nums2[p2++];
//        }
//    }

    // 版本一基础上优化
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        //  辅助数组 tmp ，用于合并阶段暂存元素；
        vector<int> tmp;
        for (int i = 0; i < nums1.size(); i++) {
            tmp.push_back(nums1[i]);
        }

        int p1 = 0, p2 = 0, p = 0;
        for (; p1 <= m - 1 || p2 <= n - 1;) {
            if (p1 > m - 1) { // p1已经移动完了
                nums1[p++] = nums2[p2++];
            } else if (p2 > n - 1) { // p2已经移动完了
                nums1[p++] = tmp[p1++];
            } else if (tmp[p1] <= nums2[p2]) {
                nums1[p++] = tmp[p1++];
            } else {
                nums1[p++] = nums2[p2++];
            }
        }
    }


    // 从后往前
//    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
//        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
//        for (; p1 >= 0 || p2 >= 0;) {
//            if (p1 < 0) {
//                nums1[p--] = nums2[p2--];
//            } else if (p2 < 0) {
//                nums1[p--] = nums1[p1--];
//            } else if (nums1[p1] >= nums2[p2]) { // 大的从后往前放
//                nums1[p--] = nums1[p1--];
//            } else {
//                nums1[p--] = nums2[p2--];
//            }
//        }
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    s.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << endl;
    }
}