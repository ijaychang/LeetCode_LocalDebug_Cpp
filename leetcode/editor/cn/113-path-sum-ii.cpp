//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点总数在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
// 
// 
// Related Topics 树 深度优先搜索 回溯 二叉树 
// 👍 1004 👎 0


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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> res;
        vector<int> track;
        traverse(root, track, res, targetSum);
        return res;
    }

    void traverse(TreeNode *root, vector<int> track, vector<vector<int>> &res, int targetSum) {
        if (!root) {
            return;
        }
        track.push_back(root->val);
        // 是叶子节点
        if (!root->left && !root->right) {
            int sum = 0;
            for (int i = 0; i < track.size(); i++) {
                sum += track[i];
            }
            if (sum == targetSum) {
                res.push_back(track);
            }
            return;
        }
        traverse(root->left, track, res, targetSum);
        traverse(root->right, track, res, targetSum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    Tree *tree = new Tree(l);
    vector<vector<int>> res = s.pathSum(tree->root, 22);
    for (auto path: res) {
        for (auto i : path) {
            cout << i << " ";
        }
        cout << endl;
    }
}