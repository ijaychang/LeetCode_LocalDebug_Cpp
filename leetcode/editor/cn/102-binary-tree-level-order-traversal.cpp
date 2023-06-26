//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[9,20],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
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
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 广度优先搜索 二叉树 
// 👍 1711 👎 0


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
//    vector<vector<int>> levelOrder(TreeNode *root) {
//        vector<vector<int>> res;
//        if (!root) {
//            return res;
//        }
//        queue<TreeNode *> q;
//        TreeNode *node;
//        for (q.push(root); !q.empty();) {
//            res.push_back(vector<int>());
//            int currentLevelSize = q.size();
//            for (int count = 0; !q.empty() && count < currentLevelSize; count++) {
//                node = q.front();
//                q.pop();
//                res.back().push_back(node->val);
//                if (node->left) {
//                    q.push(node->left);
//                }
//                if (node->right) {
//                    q.push(node->right);
//                }
//            }
//        }
//        return res;
//
//    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> currentLevelNodes;
        currentLevelNodes.push(root);
        traverse(currentLevelNodes, res);
        return res;
    }

    void traverse(queue<TreeNode *> &currentLevelNodes, vector<vector<int>> &res) {
        if (currentLevelNodes.empty()) {
            return;
        }
        queue<TreeNode *> nextLevelNodes;
        res.push_back(vector<int>());
        for (TreeNode *p; !currentLevelNodes.empty();) {
            p = currentLevelNodes.front();
            currentLevelNodes.pop();
            res.back().push_back(p->val);
            if (p->left) {
                nextLevelNodes.push(p->left);
            }
            if (p->right) {
                nextLevelNodes.push(p->right);
            }
        }
        traverse(nextLevelNodes, res);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto list = {1, 2, 3, 4, 5, 6, 7};
    Tree *tree = new Tree(list);
    vector<vector<int>> res = s.levelOrder(tree->root);
    for (auto i = res.begin(); i < res.end(); i++) {
        vector<int> v = *i;
        cout << "[";
        for (auto j = v.begin(); j < v.end(); j++) {
            cout << *j << " ";
        }
        cout << "]" << endl;
    }

}