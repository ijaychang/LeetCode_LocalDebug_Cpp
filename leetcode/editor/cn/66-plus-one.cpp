//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。 
//
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 
//
// 你可以假设除了整数 0 之外，这个整数不会以零开头。 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = [1,2,3]
//输出：[1,2,4]
//解释：输入数组表示数字 123。
// 
//
// 示例 2： 
//
// 
//输入：digits = [4,3,2,1]
//输出：[4,3,2,2]
//解释：输入数组表示数字 4321。
// 
//
// 示例 3： 
//
// 
//输入：digits = [0]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= digits.length <= 100 
// 0 <= digits[i] <= 9 
// 
// Related Topics 数组 数学 
// 👍 1285 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // carry 初始值为1，相当于进位到个位的值为1
        int carry = 1;
        vector<int> res;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int digit = digits[i];
            if (digit == 9 && carry == 1) {
                carry = 1;
                digit = 0;
            } else {
                digit = digit + carry;
                carry = 0;
            }
            res.push_back(digit);
        }
        if (carry == 1) {
            res.push_back(1);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data ({9,9,9,9});
    vector<int> res = s.plusOne(data);
    for(auto i = res.begin() ; i < res.end() ; i++) {
        cout << (*i) << endl;
    }

}