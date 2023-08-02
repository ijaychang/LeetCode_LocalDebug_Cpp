//给你一棵二叉树的根节点 root ，返回所有 重复的子树 。 
//
// 对于同一类的重复子树，你只需要返回其中任意 一棵 的根结点即可。 
//
// 如果两棵树具有 相同的结构 和 相同的结点值 ，则认为二者是 重复 的。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [1,2,3,4,null,2,4,null,null,4]
//输出：[[2,4],[4]] 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [2,1,1]
//输出：[[1]] 
//
// 示例 3： 
//
// 
//
// 
//输入：root = [2,2,2,3,null,3,null]
//输出：[[2,3],[3]] 
//
// 
//
// 提示： 
//
// 
// 树中的结点数在 [1, 5000] 范围内。 
// -200 <= Node.val <= 200 
// 
// Related Topics 树 深度优先搜索 哈希表 二叉树 
// 👍 689 👎 0


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

    unordered_map<string, int> subtrees_map;
    vector<TreeNode *> res;

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        traverse(root);
        return res;
    }

    string traverse(TreeNode *root) {
        if (!root) {
            return "#";
        }
        string left_sub_tree = traverse(root->left);
        string right_sub_tree = traverse(root->right);

        string sub_tree = to_string(root->val) + "," + left_sub_tree + "," + right_sub_tree;

        int count = subtrees_map[sub_tree];
        if (count == 1) {
            res.push_back(root);
        }
        subtrees_map[sub_tree] = count + 1;
        return sub_tree;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{1, 2, 3, 4, -1, 2, 4, -1, -1, 4};
    // vector<int> data{2, 1, 1};
    Tree *tree = new Tree(data);
    vector<TreeNode *> res = s.findDuplicateSubtrees(tree->root);
    for (int i = 0; i < res.size(); i++) {
        print_tree(res[i]);
    }
}