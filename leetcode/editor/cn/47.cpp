//47. 全排列 II
//中等
//        相关标签
//相关企业
//        给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//
//
//
//示例 1：
//
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
//[1,2,1],
//[2,1,1]]
//示例 2：
//
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
//提示：
//
//1 <= nums.length <= 8
//-10 <= nums[i] <= 10


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // 记录「路径」
        vector<int> track;
        // 「路径」中的元素会被标记为true，避免重复使用
        vector<bool> used(nums.size(), false);

        backtrace(nums, track, used);
        return res;
    }

    void backtrace(vector<int> &nums, vector<int> &track, vector<bool> &used) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrace(nums, track, used);
            track.pop_back();
            used[i] = false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data({1, 1, 2});
    s.permuteUnique(data);
    for (int i = 0; i < s.res.size(); i++) {
        vector<int> v = s.res[i];
        cout << "[";
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << ",";
        }
        cout << "]" << endl;
    }
}