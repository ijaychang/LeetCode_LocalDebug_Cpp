//370.区间加法( labuladong 题解
//.难度中等
//假设你有一个长度为n的数组，初始情况下所有的数字均为0,你将会被给出k个更新的操作。
//其中，每个操作会被表示为一个三元组: [startIndex, endIndex, inc],你需要将子数
//        组A[startIndex ... endIndex] (包括 startIndex和endIndex)增加inc。
//请你返回k次操作后的数组。
//示例:
//输入: length = 5, updates = [[1,3,2], [2,4,3],[0,2,-2]]
//输出: [-2, 0,3,5,3]
//解释:
//初始状态:
//[0,0,0, 0, 0]
//进行了操作[1,3,2] 后的状态:
//[0,2,2,2,0]
//进行了操作[2,4,3] 后的状态:
//[0,2,5,5,3]
//进行了操作[0,2,-2] 后的状态:
//[-2,0,3,5,3]



#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class DiffArray {
public:
    vector<int> diff;

    DiffArray(vector<int> nums) {
        if (nums.size() == 0) {
            return;
        }
        diff.assign(nums.size(), 0);
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    void update(int start, int end, int inc) {
        if (start > end || (start < 0 || start >= diff.size())) {
            cout << "params start or end is invalid";
            return;
        }
        diff[start] += inc;
        if (end < diff.size() - 1) {
            diff[end + 1] -= inc;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size(), 0);
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void print_array(vector<int> res) {
    for (auto p = res.begin(); p < res.end(); p++) {
        cout << *p << " ";
    }
    cout << endl;
}

int main() {
    DiffArray *diffArray = new DiffArray({0, 0, 0, 0, 0});

    print_array(diffArray->result());
    diffArray->update(1, 3, 2);
    print_array(diffArray->result());
    diffArray->update(2, 4, 3);
    print_array(diffArray->result());
    diffArray->update(0, 2, -2);
    print_array(diffArray->result());
    return 0;
}