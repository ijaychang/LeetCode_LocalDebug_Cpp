//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 深度优先搜索 二叉树 
// 👍 1841 👎 0


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
//    方法一：递归法
//    vector<int> inorderTraversal(TreeNode *root) {
//        // vector<int>* res_ptr;
//        vector<int> res;
//        doInorderTraversal(root, &res);
//        return res;
//    }
//
//    void doInorderTraversal(TreeNode *root, vector<int> *res_ptr) {
//        if (!root) {
//            return;
//        }
//        doInorderTraversal(root->left, res_ptr);
//        res_ptr->push_back(root->val);
//        doInorderTraversal(root->right, res_ptr);
//    }


//    方法二：迭代法
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *cur;
        for (cur = root; cur || !s.empty();) {
            for (; cur; cur = cur->left) {
                s.push(cur);
            }
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            // cur的右子树的根节点为null，则下次访问cur的父节点
            cur = cur->right;
        }
        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto list = {1, 2, 3, 4, 5};
    Tree *tree = new Tree(list);
    vector<int> res = s.inorderTraversal(tree->root);
    for (auto i = res.begin(); i < res.end(); i++) {
        std::cout << *i << ' ';
    }
}