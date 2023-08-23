#include <iostream>
#include <vector>

using namespace std;

// 普通快排,取数组第一个元素作为基准值

// 普通快排,取数组最后一个元素作为基准值

// 随机取一个基准值

class Solution {
public:
    // normalQuickSort 相当于二叉树的先序遍历， 把nums[low..high]看做二叉树的节点
    void quickSort(vector<int> &nums, int low, int high) {
        if (low >= high) {
            return;
        }
        // int p = normalFirstPartition(nums, low, high);
        // int p = normalLastPartition(nums, low, high);
        // int p = randomFirstPartition(nums,low,high);
        int p = randomLastPartition(nums, low, high);
        // 左侧的数组都小于nums[p]
        quickSort(nums, low, p - 1);
        // 右侧的数组都大于nums[p]
        quickSort(nums, p + 1, high);

    }

    // 取数组第一个元素作为基准值
    int normalFirstPartition(vector<int> &nums, int low, int high) {
        int pivot = nums[low];
        int j = low;
        // i 一直往右移动，直到 nums[i] > pivot
        for (int i = low + 1; i <= high; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[++j]);
            }
        }
        swap(nums[j], nums[low]);
        return j;
    }

    // 随机取一个元素作为基准值，并将此值与数组第一个元素交换
    int randomFirstPartition(vector<int> &nums, int low, int high) {
        int randIndex = (rand() % (high - low + 1)) + low;
        swap(nums[randIndex], nums[low]);
        int pivot = nums[low];
        int j = low;
        // i 一直往右移动，直到 nums[i] > pivot
        for (int i = low + 1; i <= high; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[++j]);
            }
        }
        swap(nums[j], nums[low]);
        return j;
    }

    // 取数组最后一个元素作为基准值
    int normalLastPartition(vector<int> &nums, int low, int high) {
        int pivot = nums[high];
        int j = low, i = low;
        for (; i <= high; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[j++]);
            }
        }
        return j - 1;
    }

    // 随机取一个元素作为基准值，并将此值与数组最后一个元素交换
    int randomLastPartition(vector<int> &nums, int low, int high) {
        int randIndex = (rand() % (high - low + 1)) + low;
        swap(nums[randIndex], nums[high]);
        int pivot = nums[high];
        int j = low, i = low;
        for (; i <= high; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[j++]);
            }
        }
        return j - 1;
    }

    int randomDoublePointPartition(vector<int> &nums, int low, int high) {
        int pivot = nums[rand() % (high - low + 1) + low];
        int pl = low - 1, pr = high + 1;
        for (int cur = low; cur < pr;) {
            if (nums[cur] < pivot) {
                swap(nums[++pl], nums[cur++]);
            } else if (nums[cur] > pivot) {
                swap(nums[cur], nums[--pr]);
            } else {
                cur++;
            }
        }
        return pl + 1;
    }

    // 双路 从两端向中间挺近，设立两个区：小于等于区，大于等于区
    /* 从两端向中间挺近，设立两个区：小于等于区，大于等于区 如何克服含大量重复元素的数组导致不平衡问题： 等于基准的数在两边均有分布，避免集中在一边，从而克服了不平衡问题。 */
    int twoRoadsPartition(vector<int> &nums, int low, int high) {
        int randIndex = (rand() % (high - low + 1)) + low;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    // vector<int> nums = {5, 1, 1, 2, 0, 0};
    // vector<int> nums = {3,4, 2, 1, 3};
    vector<int> nums = {5, 9, 2, 1, 4, 7, 5, 8, 3, 6};
    s.quickSort(nums, 0, nums.size() - 1);
    for (auto n : nums) {
        cout << n << " ";
    }
    cout << endl;
}