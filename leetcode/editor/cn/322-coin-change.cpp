//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。 
//
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。 
//
// 你可以认为每种硬币的数量是无限的。 
//
// 
//
// 示例 1： 
//
// 
//输入：coins = [1, 2, 5], amount = 11
//输出：3 
//解释：11 = 5 + 5 + 1 
//
// 示例 2： 
//
// 
//输入：coins = [2], amount = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：coins = [1], amount = 0
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 231 - 1 
// 0 <= amount <= 104 
// 
// Related Topics 广度优先搜索 数组 动态规划 
// 👍 2462 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

//    方法一：递归法（自顶向下）
//    int coinChange(vector<int> &coins, int amount) {
//        // 备忘录
//        int memo[amount + 1];
//        memset(memo, 0, sizeof(memo));
//        return dp(coins, amount, memo);
//    }
//
//    int dp(vector<int> &coins, int amount, int memo[]) {
//        // base case
//        if (amount == 0) {
//            return 0;
//        }
//        if (amount < 0) {
//            return -1;
//        }
//        if (memo[amount] != 0) {
//            return memo[amount];
//        }
//        int res = INT32_MAX;
//        // 选择
//        for (int coin : coins) {
//            int tmp = dp(coins, amount - coin, memo);
//            if (tmp == -1) {
//                continue;
//            }
//            res = min(res, tmp + 1);
//        }
//        res = (res == INT32_MAX) ? -1 : res;
//        return (memo[amount] = res);
//    }

    // 方法二：迭代法（自底向上）
    int coinChange(vector<int> &coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        int dp[amount + 1], res;
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        for (int am = 1; am <= amount; am++) {
            res = INT32_MAX;
            for (int coin : coins) {
                if (am - coin >= 0 && dp[am - coin] != -1) {
                    res = min(res, dp[am - coin] + 1);
                }
            }
            dp[am] = (res == INT32_MAX) ? -1 : res;
        }
        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 21;
    int res = s.coinChange(coins, amount);
    cout << res << endl;
}