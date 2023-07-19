//给你一棵二叉树的根节点，返回该树的 直径 。 
//
// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。 
//
// 两节点之间路径的 长度 由它们之间边数表示。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,4,5]
//输出：3
//解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 104] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 1360 👎 0


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

    int diameterOfBinaryTree(TreeNode *root) {
        int res = INT32_MIN;
        traverse(root, res);
        return res;
    }

    int traverse(TreeNode *root, int &res) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = traverse(root->left, res);
        int rightDepth = traverse(root->right, res);
        res = max(res, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {1};
    Tree *tree = new Tree(l);
    int res = s.diameterOfBinaryTree(tree->root);
    cout << res << endl;
}