#include <iostream>

using namespace std;

class Solution {
public:

    int *tmp;

    void sort(int nums[]) {
        // 在 C++ 中，没有获取数组长度的函数，要数组数组的长度，我们可以使用 sizeof 首先获取整个数组的占用字节大小，
        // 再次使用 sizeof 获取单个元素的内存大小，最后相除得到数组长度
        int n = sizeof(nums) / sizeof(nums[0]);
        tmp = new int[n];
        doSort(nums, 0, n - 1);
    }

    void doSort(int nums[], int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (high + low) / 2;
        doSort(nums, low, mid);
        doSort(nums, mid + 1, high);
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


int main() {
    Solution s;

    int nums[] = {11, 9, 22, 12, 1, 3, 5, 7, 2, 4, 6, 8, 10};
    s.sort(nums);
    for (auto n : nums) {
        cout << n << endl;
    }
}