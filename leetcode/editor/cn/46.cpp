//46. 全排列
//        中等
//相关标签
//        相关企业
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
//
//
//
//示例 1：
//
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//示例 2：
//
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
//示例 3：
//
//输入：nums = [1]
//输出：[[1]]
//
//
//提示：
//
//1 <= nums.length <= 6
//-10 <= nums[i] <= 10
//nums 中的所有整数 互不相同


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &nums) {
        // 记录「路径」
        vector<int> track;
        // 「路径」中的元素会被标记为true，避免重复使用
        vector<bool> used(nums.size(), false);

        backtrace(nums, track, used);
    }

    void backtrace(vector<int> &nums, vector<int> &track, vector<bool> &used) {
        // 触发结束条件
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
    vector<int> data({1, 2, 3});
    s.permute(data);
    for (int i = 0 ;i < s.res.size() ;i ++) {
        vector<int> v = s.res[i];
        cout << "[";
       for (int j = 0 ; j < v.size() ; j ++) {
           cout << v[j] << ",";
       }
        cout << "]" << endl;
    }
}