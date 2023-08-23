#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:


    int partition(vector<int> &nums, int low, int high, int pivot) {
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

    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }


};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    //vector<int> nums = {5, 1, 1, 2, 0, 0};
    vector<int> nums = {4, 2, 1, 3, 5, 6};
    int p = s.partition(nums, 0, nums.size() - 1, 4);
    cout << p << endl;
    cout << "#####################################" << endl;
    for (auto n : nums) {
        cout << n << endl;
    }
}