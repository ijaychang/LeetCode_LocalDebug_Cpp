//给定一个二叉树，判断它是否是高度平衡的二叉树。 
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在范围 [0, 5000] 内 
// -104 <= Node.val <= 104 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 1361 👎 0


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
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        traverse(root, flag);
        return flag;
    }

    int traverse(TreeNode *root, bool &flag) {
        if (!root || !flag) {
            return 0;
        }
        int leftDepth = traverse(root->left, flag);
        int rightDepth = traverse(root->right, flag);
        int depth = max(leftDepth, rightDepth) + 1;
        if (abs(leftDepth - rightDepth) > 1) {
            flag = false;
        }
        return depth;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {3, 9, 20, -1, -1, 15, 7};
    Tree *tree = new Tree(l);
    bool flag = s.isBalanced(tree->root);
    cout << flag << endl;

    l = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    tree = new Tree(l);
    flag = s.isBalanced(tree->root);
    cout << flag << endl;
}