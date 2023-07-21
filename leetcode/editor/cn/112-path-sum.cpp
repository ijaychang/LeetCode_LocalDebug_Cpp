//给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和
// targetSum 。如果存在，返回 true ；否则，返回 false 。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//输出：true
//解释：等于目标和的根节点到叶节点路径如上图所示。
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：false
//解释：树中存在两条根节点到叶子节点的路径：
//(1 --> 2): 和为 3
//(1 --> 3): 和为 4
//不存在 sum = 5 的根节点到叶子节点的路径。 
//
// 示例 3： 
//
// 
//输入：root = [], targetSum = 0
//输出：false
//解释：由于树是空的，所以不存在根节点到叶子节点的路径。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 1207 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 方法一 递归法
    bool hasPathSum(TreeNode *root, int targetSum) {
        int sum = 0;
        bool flag = false;
        traverse(root, sum, flag, targetSum);
        return flag;
    }

    void traverse(TreeNode *root, int sum, bool &flag, int targetSum) {
        if (!root) {
            return;
        }
        sum += root->val;
        // 是叶子节点
        if (!root->left && !root->right) {
            if (sum == targetSum) {
                flag = true;
                return;
            }
            return;
        }
        traverse(root->left, sum, flag, targetSum);
        traverse(root->right, sum, flag, targetSum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    Tree *tree = new Tree(l);
    bool flag = s.hasPathSum(tree->root, 22);
    cout << flag << endl;
}