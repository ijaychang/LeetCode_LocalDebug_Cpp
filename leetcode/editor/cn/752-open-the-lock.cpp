//你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
// 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。 
//
// 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。 
//
// 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。 
//
// 字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。 
//
// 
//
// 示例 1: 
//
// 
//输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
//输出：6
//解释：
//可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
//注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
//因为当拨动到 "0102" 时这个锁就会被锁定。
// 
//
// 示例 2: 
//
// 
//输入: deadends = ["8888"], target = "0009"
//输出：1
//解释：把最后一位反向旋转一次即可 "0000" -> "0009"。
// 
//
// 示例 3: 
//
// 
//输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], targ
//et = "8888"
//输出：-1
//解释：无法旋转到目标数字且不被锁定。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= deadends.length <= 500 
// deadends[i].length == 4 
// target.length == 4 
// target 不在 deadends 之中 
// target 和 deadends[i] 仅由若干位数字组成 
// 
// Related Topics 广度优先搜索 数组 哈希表 字符串 
// 👍 613 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    string plusOne(string s, int pos) {
        char ch[s.length() + 1];
        strcpy(ch, s.c_str());
        if (ch[pos] == '9') {
            ch[pos] = '0';
        } else {
            ch[pos] += 1;
        }
        string res(ch);
        return res;
    }

    string minusOne(string s, int pos) {
        char ch[s.length() + 1];
        strcpy(ch, s.c_str());
        if (ch[pos] == '0') {
            ch[pos] = '9';
        } else {
            ch[pos] -= 1;
        }
        string res(ch);
        return res;
    }

    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deadendsSet;
        for (string deadend: deadends) {
            deadendsSet.insert(deadend);
        }
        queue<string> q;
        unordered_set<string> visited;
        int sz = 0, step = 0;
        string cur;
        for (q.push("0000"), visited.insert("0000"); !q.empty();) {
            sz = q.size();
            for (int i = 0; i < sz; i++) {
                cur = q.front();
                q.pop();
                if (cur.compare(target) == 0) {
                    return step;
                }
                if (deadendsSet.count(cur)) {
                    continue;
                }
                for (int pos = 0; pos < 4; pos++) {
                    string tmp = plusOne(cur, pos);
                    if (!visited.count(tmp)) {
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                    tmp = minusOne(cur, pos);
                    if (!visited.count(tmp)) {
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                }
            }

            step++;
        }
        return -1;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
//    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
//    string target = "0202";

    vector<string> deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    string target = "8888";

    int res = s.openLock(deadends, target);
    cout << res << endl;
}