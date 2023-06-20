//给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[3,2,1]
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
// 树中节点的数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 深度优先搜索 二叉树 
// 👍 1050 👎 0


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
//    vector<int> postorderTraversal(TreeNode *root) {
//        vector<int> res;
//        doPostorderTraversal(root, res);
//        return res;
//    }
//
//    void doPostorderTraversal(TreeNode *root, vector<int> &res) {
//        if (!root) {
//            return;
//        }
//        doPostorderTraversal(root->left, res);
//        doPostorderTraversal(root->right, res);
//        res.push_back(root->val);
//    }

// 方法二：迭代法(非标准版)
//    vector<int> postorderTraversal(TreeNode *root) {
//        if (!root) {
//            return {};
//        }
//        vector<int> res;
//        stack<TreeNode *> s;
//        for (s.push(root); !s.empty();) {
//            TreeNode *cur = s.top();
//            s.pop();
//            res.push_back(cur->val);
//
//            if (cur->left) {
//                s.push(cur->left);
//            }
//
//            if (cur->right) {
//                s.push(cur->right);
//            }
//
//
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }

// 方法二：迭代法(标准版)
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        stack<TreeNode *> s;
        vector<int> res;
        TreeNode *pre;
        TreeNode *cur = root;

        for (; cur || !s.empty();) {
            for (; cur;) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();

            // 有右子树且右子树根节点就是刚刚访问过的节点
            if (cur->right && cur->right == pre) {
                res.push_back(cur->val);
                pre = cur;
                cur = nullptr;
                continue;
            }

            // 没有右子树
            if (!cur->right) {
                res.push_back(cur->val);
            } else {
                // 有右子树且右子树根节点不是刚刚访问过的节点 则把cur压栈
                s.push(cur);
            }
            // 用pre记录访问过的节点
            pre = cur;
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
    vector<int> res = s.postorderTraversal(tree->root);
    for (auto i = res.begin(); i < res.end(); i++) {
        cout << *i << " ";
    }
}