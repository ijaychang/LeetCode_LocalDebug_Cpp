//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。 
//
// 
//
// 示例 1： 
//
// 
//输入:a = "11", b = "1"
//输出："100" 
//
// 示例 2： 
//
// 
//输入：a = "1010", b = "1011"
//输出："10101" 
//
// 
//
// 提示： 
//
// 
// 1 <= a.length, b.length <= 104 
// a 和 b 仅由字符 '0' 或 '1' 组成 
// 字符串如果不是 "0" ，就不含前导零 
// 
// Related Topics 位运算 数学 字符串 模拟 
// 👍 1087 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void compute(int digit, int &carry, string &res) const {
        if (digit >= 2) {
            digit = digit - 2;
            carry = 1;
        } else {
            carry = 0;
        }
        char ch = digit + 48;
        res = ch + res;
    }

    string addBinary(string a, string b) {
        int szA = a.length(), szB = b.length();
        int carry = 0, i = szA - 1, j = szB - 1;
        string res;
        for (; i >= 0 || j >= 0; i--, j--) {
            int digit = carry;
            if (i >= 0 ) {
                digit = digit + a[i] - 48;
            }
            if (j >= 0) {
                digit = digit + b[j] - 48;
            }
            compute(digit, carry, res);
        }
        if (carry == 1) {
            res = '1' + res;
        }
        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    string res = s.addBinary("1", "111");
    cout << res << endl;
}