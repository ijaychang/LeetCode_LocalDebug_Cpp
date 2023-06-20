//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[1,2,3]
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
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 示例 5： 
//
// 
//输入：root = [1,null,2]
//输出：[1,2]
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
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 深度优先搜索 二叉树 
// 👍 1080 👎 0


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
//    方法一： 递归法
//    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int> res;
//        doPreorderTraversal(root, res);
//        return res;
//    }
//
//    void doPreorderTraversal(TreeNode *root, vector<int> &res) {
//        if (!root) {
//            return;
//        }
//        res.push_back(root->val);
//        doPreorderTraversal(root->left, res);
//        doPreorderTraversal(root->right, res);
//    }



//   方法二：迭代法
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        stack<TreeNode *> s;
        for (s.push(root); !s.empty();) {
            TreeNode *cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right) {
                s.push(cur->right);
            }

            if (cur->left) {
                s.push(cur->left);
            }
        }
        return res;
    }

};




//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto list = {7, 1, 5, 3, 6, 4};
    Tree *tree = new Tree(list);
    vector<int> res = s.preorderTraversal(tree->root);
    for (auto i = res.begin(); i < res.end(); i++) {
        std::cout << *i << ' ';
    }
}