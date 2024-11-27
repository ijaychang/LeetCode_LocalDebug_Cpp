#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    int trackSum = 0;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);
        return res;
    }

    void backtrace(vector<int> &candidates, int target, int start) {
        // 触发结束条件
        if (trackSum == target) {
            res.push_back(track);
        }
        if (trackSum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            track.push_back(candidates[i]);
            trackSum += candidates[i];
            backtrace(candidates, target, i + 1);
            trackSum -= candidates[i];
            track.pop_back();
        }
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> candidates({10, 1, 2, 7, 6, 1, 5});
    // 1,1,2,5,6,7,10
    vector<vector<int>> res = s.combinationSum2(candidates, 8);
    for (int i = 0; i < res.size(); i++) {
        vector<int> v = res[i];
        cout << "[";
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << ",";
        }
        cout << "]" << endl;
    }
}