//在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。 
//
// 如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记； 
//
// 而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。 
//
// 
//
// 给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。 
//
// 
//
// 示例 1： 
//
// 输入：label = 14
//输出：[1,3,4,14]
// 
//
// 示例 2： 
//
// 输入：label = 26
//输出：[1,2,6,10,26]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= label <= 10^6 
// 
// Related Topics 树 数学 二叉树 
// 👍 202 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        // 计算 label 在哪一层
        // 假设得到 label 在第 k 层
        int k = (int) ceil(log2(label + 1)), val = label, sumOfHeadTail;
        for (int i = k; i >= 1; i--) {
            sumOfHeadTail = (1 << (i - 1)) + (1 << i) - 1;
            if (i % 2 == 0) {
                // 偶数行放到结果集的 label 值需要还原为原值
                if (i != k) {
                    res.push_back(sumOfHeadTail - val);
                } else {
                    res.push_back(val);
                    val = sumOfHeadTail - val;
                }
            } else {
                res.push_back(val);
            }
            // 偶数行需要转为正序的 label 值
            val = val / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> res = s.pathInZigZagTree(26);
    for (auto i = res.begin(); i < res.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}