//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4], k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6], k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 
// 👍 2251 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)


//class Solution {
//public:
//    int res = -1;
//
//    int findKthLargest(vector<int> &nums, int k) {
//        // 将第k大，转化为第几个
//        int target = nums.size() - k;
//        quickSort(nums, 0, nums.size() - 1, target);
//        return res;
//    }
//
//    void quickSort(vector<int> &nums, int low, int high, int target) {
//        if (low >= high) {
//            if (low == target) {
//                res = nums[low];
//            }
//            return;
//        }
//        int p = partition(nums, low, high);
//        if (p == target) {
//            res = nums[p];
//            return;
//        }
//        if (target >= p) {
//            quickSort(nums, p + 1, high, target);
//        } else {
//            quickSort(nums, low, p - 1, target);
//        }
//    }
//
//
//    int partition(vector<int> &nums, int low, int high) {
//        int mid = low + ((high - low) >> 1);
//        if (mid != high) {
//            swap(nums[mid], nums[high]);
//        }
//        int pivot = nums[high];
//        int pLeft = low, pRight = high;
//        while (pLeft < pRight) {
//            // left 指针一直往右移动，直到nums[left] >= pivot 停下
//            while (nums[pLeft] <= pivot && pLeft < pRight) {
//                pLeft++;
//            }
//            // right 指针一直往左移动，直到nums[right] <= pivot 停下
//            while (nums[pRight] >= pivot && pLeft < pRight) {
//                pRight--;
//            }
//            swap(nums[pLeft], nums[pRight]);
//        }
//        swap(nums[pLeft], nums[high]);
//        return pLeft;
//    }
//};

// 方法一 快排
//class Solution {
//public:
//    int res = -1;
//
//    int findKthLargest(vector<int> &nums, int k) {
//        // 将第k大，转化为第几个
//        int target = nums.size() - k;
//        quickSort(nums, 0, nums.size() - 1, target);
//        return res;
//    }
//
//    void quickSort(vector<int> &nums, int low, int high, int target) {
//        if (low >= high) {
//            if (low == target) {
//                res = nums[low];
//            }
//            return;
//        }
//        int p = partition(nums, low, high);
//        if (p == target) {
//            res = nums[p];
//            return;
//        }
//        if (target >= p) {
//            quickSort(nums, p + 1, high, target);
//        } else {
//            quickSort(nums, low, p - 1, target);
//        }
//    }
//
//    int partition(vector<int> &nums, int low, int high) {
//        int randIndex = (rand() % (high - low + 1)) + low;
//        swap(nums[low],nums[randIndex]);
//        int pivot = nums[low];
//        int pLeft = low + 1, pRight = high;
//        bool flip = true;
//        for(;;) {
//            while(pLeft <= pRight && nums[pLeft] < pivot) {
//                pLeft++;
//            }
//            while(pLeft <= pRight && nums[pRight] > pivot) {
//                pRight--;
//            }
//            // 针对用例40的优化：nums[pLeft] nums[pRight] 都等于 pivot，则交替递增pLeft,递减pRight
//            while(pLeft <= pRight && (nums[pLeft] == pivot && nums[pRight] == pivot)) {
//                if (flip) {
//                    pLeft++;
//                } else {
//                    pRight--;
//                }
//                flip = !flip;
//            }
//
//            if (pLeft > pRight) {
//                break;
//            }
//            swap(nums[pLeft++],nums[pRight--]);
//        }
//        swap(nums[low],nums[pRight]);
//        return pRight;
//    }
//};

// 方法二(优先级队列)
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        auto cmp = [](int a,int b){return a < b;};
        priority_queue<int,vector<int>, decltype(cmp)> q(cmp);
        for(int i = 0 ; i < nums.size(); i ++) {
            q.push(nums[i]);
        }

        for(int count = 1; count <= k ; count ++) {
            int val = q.top();
            q.pop();
            if (count == k) {
                return val;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums = {1};
    //vector<int> nums = {3,2,3,1,2,4,5,5,6};
    //vector<int> nums = {3, 2, 1, 5, 6, 4};
    // vector<int> nums = {5, 6, 4};
    int res = s.findKthLargest(nums, 1);
    cout << res << endl;
}