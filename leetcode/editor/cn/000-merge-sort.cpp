#include <iostream>

using namespace std;


class Solution {
public:

    int *tmp;

    /**
     *
     * @param nums 数组
     * @param n 数组长度
     */
    void sort(int nums[], int n) {
        tmp = new int[n];
        doSort(nums, 0, n - 1);
    }

    void doSort(int nums[], int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (high + low) / 2;
        // 将左侧的数组排好序
        doSort(nums, low, mid);
        // 将右侧的数组排好序
        doSort(nums, mid + 1, high);
        // 将左右侧数组合并
        merge(nums, low, mid, high);
    }

    // 合并nums[low..mid] nums[mid+1,high]
    void merge(int nums[], int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            tmp[i - low] = nums[i];
        }

        // 数组双指针技巧，合并两个有序数组
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
                nums[p++] = tmp[p2 - low];
                p2++;
            }
        }
    }


};
//leetcode submit region end(Prohibit modification and deletion)



template<class T>

int length(T &arr) {
    return sizeof(arr) / sizeof(arr[0]);
}

int main() {
    Solution s;

    int nums[] = {11, 9, 22, 12, 1, 3, 5, 7, 2, 4, 6, 13, 8, 10};
    s.sort(nums, length(nums));
    for (auto n : nums) {
        cout << n << endl;
    }
}