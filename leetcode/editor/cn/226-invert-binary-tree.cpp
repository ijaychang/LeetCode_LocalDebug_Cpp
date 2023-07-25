//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [2,1,3]
//输出：[2,3,1]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目范围在 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 1639 👎 0


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
    // 解题思维模式之遍历
//    TreeNode *invertTree(TreeNode *root) {
//        traverse(root);
//        return root;
//    }
//
//    void traverse(TreeNode *root) {
//        if (!root) {
//            return;
//        }
//        TreeNode *tmp = root->left;
//        root->left = root->right;
//        root->right = tmp;
//
//        traverse(root->left);
//        traverse(root->right);
//    }

    // 解题思维模式之分解
    // 定义：将以 root 为根的这棵二叉树翻转，返回翻转后的二叉树的根节点
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{4, 2, 7, 1, 3, 6, 9};
    Tree *tree = new Tree(data);
    TreeNode *root = s.invertTree(tree->root);
    print_tree(root);
}