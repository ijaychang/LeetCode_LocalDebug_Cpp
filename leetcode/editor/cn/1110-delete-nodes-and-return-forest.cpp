//给出二叉树的根节点 root，树上每个节点都有一个不同的值。 
//
// 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。 
//
// 返回森林中的每棵树。你可以按任意顺序组织答案。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
//输出：[[1,2,null,4],[6],[7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,4,null,3], to_delete = [3]
//输出：[[1,2,4]]
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数最大为 1000。 
// 每个节点都有一个介于 1 到 1000 之间的值，且各不相同。 
// to_delete.length <= 1000 
// to_delete 包含一些从 1 到 1000、各不相同的值。 
// 
// Related Topics 树 深度优先搜索 数组 哈希表 二叉树 
// 👍 297 👎 0


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
    // 方法一 递归法dfs
//    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
//        vector<TreeNode *> res;
//        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
//        traverse(root, nullptr, to_delete_set, res);
//        return res;
//    }
//
//    void traverse(TreeNode *root, TreeNode *parent, unordered_set<int> &to_delete_set, vector<TreeNode *> &res) {
//        if (!root) {
//            return;
//        }
//
//        if (!isNeedDeleted(root, to_delete_set)) {
//            // 是整棵树的根节点,且该节点不用删除，则需放到结果集中
//            if (!parent || isNeedDeleted(parent, to_delete_set)) {
//                res.push_back(root);
//            }
//            traverse(root->left, root, to_delete_set, res);
//            traverse(root->right, root, to_delete_set, res);
//            return;
//        }
//
//        // root节点需要删除
//        // 存在左子树
//        if (root->left) {
//            // 左子树根节点不需要删除
//            if (!isNeedDeleted(root->left, to_delete_set)) {
//                traverse(root->left, nullptr,to_delete_set,res);
//            } else { // 左子树根节点需要删除
//                traverse(root->left->left, root->left, to_delete_set, res);
//                traverse(root->left->right, root->left, to_delete_set, res);
//            }
//        }
//
//        // 存在右子树
//        if (root->right) {
//            // 右子树根节点不需要删除
//            if (!isNeedDeleted(root->right, to_delete_set)) {
//                traverse(root->right, nullptr,to_delete_set,res);
//            } else { // 右子树根节点需要删除
//                traverse(root->right->left, root->right, to_delete_set, res);
//                traverse(root->right->right, root->right, to_delete_set, res);
//            }
//        }
//
//        // 判断当前root节点是父节点的左子树根节点，还是右子树根节点
//        if (parent) {
//            if (root == parent->left) {
//                parent->left = nullptr;
//            }
//            if (root == parent->right) {
//                parent->right = nullptr;
//            }
//        }
//    }
//
//    bool isNeedDeleted(TreeNode *node, unordered_set<int> &to_delete_set) {
//        return to_delete_set.count(node->val);
//    }



    // 方法二 递归法精简版
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        if (!root) {
            return {};
        }
        vector<TreeNode *> res;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        bool deleted = to_delete_set.count(root->val) > 0;
        if (!deleted) {
            res.push_back(root);
        }
        dfs(root, to_delete_set, res);
        return res;
    }


    TreeNode *dfs(TreeNode *root, unordered_set<int> &to_delete_set, vector<TreeNode *> &res) {
        if (!root) {
            return nullptr;
        }

        bool deleted = to_delete_set.count(root->val) > 0;
        if (deleted) {
            TreeNode *left_root = dfs(root->left, to_delete_set, res);
            TreeNode *right_root = dfs(root->right, to_delete_set, res);
            if (left_root) {
                res.push_back(left_root);
            }
            if (right_root) {
                res.push_back(right_root);
            }
            return nullptr;
        }

        root->left = dfs(root->left, to_delete_set, res);
        root->right = dfs(root->right, to_delete_set, res);

        return root;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {1,2,3,4,5,6,7};
    vector<int> to_delete = {3, 5};
    Tree *tree = new Tree(l);

    vector<TreeNode *> res = s.delNodes(tree->root, to_delete);
    for (int i = 0; i < res.size(); i++) {
        print_tree(res[i]);
    }
}