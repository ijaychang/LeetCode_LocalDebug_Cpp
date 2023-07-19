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

    /**
     * 二叉树层序遍历代码模板
     * @param root
     */

    vector<vector<int>> levelTraverse(TreeNode *root) {
        queue<TreeNode *> currentLevelQueue;
        currentLevelQueue.push(root);
        vector<vector<int>> res;
        traverse(currentLevelQueue, res);
        return res;
    }

    void traverse(queue<TreeNode *> &currentLevelQueue, vector<vector<int>> &res) {
        if (currentLevelQueue.empty()) {
            return;
        }
        queue<TreeNode *> nextLevelQueue;
        res.push_back(vector<int>());
        for (; !currentLevelQueue.empty();) {
            TreeNode *cur = currentLevelQueue.front();
            currentLevelQueue.pop();
            res.back().push_back(cur->val);

            if (cur->left) {
                nextLevelQueue.push(cur->left);
            }
            if (cur->right) {
                nextLevelQueue.push(cur->right);
            }
        }
        traverse(nextLevelQueue, res);
    }
};

int main() {
    Solution s;
    // 0表示null
    auto l = {1, 2, 0, 3, 4, 5};
    Tree *tree = new Tree(l);
//    s.levelTraverse(tree->root);

    vector<vector<int>> res = s.levelTraverse(tree->root);
    for (auto i = res.begin(); i < res.end(); i++) {
        vector<int> v = *i;
        cout << "[";
        for (auto j = v.begin(); j < v.end(); j++) {
            cout << *j << " ";
        }
        cout << "]" << endl;
    }
}