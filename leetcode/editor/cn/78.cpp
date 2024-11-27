#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> track;
        vector<vector<int>> res;
        backtrace(res, nums, track, 0);
        return res;
    }

    void backtrace(vector<vector<int>> &res, vector<int> &nums, vector<int> &track, int start) {
        res.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrace(res, nums, track, i + 1);
            track.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data({1, 2, 3});
    vector<vector<int>> res = s.subsets(data);
    for (auto i : res) {
        cout << "[";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}