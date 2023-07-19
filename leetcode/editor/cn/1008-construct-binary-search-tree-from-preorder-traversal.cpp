//给定一个整数数组，它表示BST(即 二叉搜索树 )的 先序遍历 ，构造树并返回其根。 
//
// 保证 对于给定的测试用例，总是有可能找到具有给定需求的二叉搜索树。 
//
// 二叉搜索树 是一棵二叉树，其中每个节点， Node.left 的任何后代的值 严格小于 Node.val , Node.right 的任何后代的值 严格大
//于 Node.val。 
//
// 二叉树的 前序遍历 首先显示节点的值，然后遍历Node.left，最后遍历Node.right。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：preorder = [8,5,1,7,10,12]
//输出：[8,5,10,1,7,null,12]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [1,3]
//输出: [1,null,3]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= preorder.length <= 100 
// 1 <= preorder[i] <= 10^8 
// preorder 中的值 互不相同 
// 
//
// 
// Related Topics 栈 树 二叉搜索树 数组 二叉树 单调栈 
// 👍 261 👎 0


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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder.front());
        buildTree(root, preorder);
        return root;
    }

    void buildTree(TreeNode *root, vector<int> &preorder) {
        stack<TreeNode *> s;
        s.push(root);
        for (auto i = preorder.begin() + 1; i < preorder.end(); i++) {
            for (;!s.empty();) {
                TreeNode *node = s.top();
                if (node->val == *i) {
                    break;
                }
                s.pop();
                TreeNode *newNode = new TreeNode(*i);
                if (*i < node->val) {
                    node->left = newNode;
                    s.push(node);
                    s.push(newNode);
                }
                if (*i > node->val) {
                    node->right = newNode;
                    s.push(node);
                    s.push(newNode);
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{8, 5, 1, 7, 10, 12};
    Tree *tree = new Tree({});
    TreeNode *root = s.bstFromPreorder(data);
    tree->root = root;
    tree->print();

}