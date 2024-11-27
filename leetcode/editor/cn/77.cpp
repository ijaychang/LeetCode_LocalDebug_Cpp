#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        vector<vector<int>> res;
        vector<int> nums;
        for(int i = 1 ; i <= n ; i ++) {
            nums.push_back(i);
        }
        backtrace(res, nums, track, 0, k);
        return res;
    }

    void backtrace(vector<vector<int>> &res, vector<int> &nums, vector<int> &track, int start, int k) {
        if (track.size() == k) {
            res.push_back(track);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrace(res, nums, track, i + 1, k);
            track.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> res = s.combine(5, 3);
    for (auto i : res) {
        cout << "[";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}