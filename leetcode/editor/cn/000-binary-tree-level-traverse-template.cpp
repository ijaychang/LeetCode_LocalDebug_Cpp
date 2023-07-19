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
//    vector<vector<int>> levelTraverse(TreeNode *root) {
//        if (!root) {
//            return {};
//        }
//        vector<vector<int>> res;
//        queue<TreeNode *> q;
//        q.push(root);
//
//        for (; !q.empty();) {
//            int levelSize = q.size();
//            res.push_back(vector<int>());
//            for (int i = 0; i < levelSize; i++) {
//                TreeNode *cur = q.front();
//                q.pop();
//                res.back().push_back(cur->val);
//                if (cur->left) {
//                    q.push(cur->left);
//                }
//                if (cur->right) {
//                    q.push(cur->right);
//                }
//            }
//        }
//        return res;
//    }

    /**
 * 二叉树层序遍历代码模板
 * @param root
 */
    void levelTraverse(TreeNode *root) {
        if (!root) {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);

        // 外层for循环控制从上往下层的遍历
        for (; !q.empty();) {
            int sz = q.size();
            // 内层for循环控制当前层从左到右的遍历
            for (int i = 0; i < sz; i++) {
                TreeNode *cur = q.front();
                q.pop();
                // 将下一层节点放入队列
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
    }

};

int main() {
    Solution s;
    // 0表示null
    auto l = {1, 2, 0, 3, 4, 5};
    Tree *tree = new Tree(l);
    s.levelTraverse(tree->root);

//    vector<vector<int>> res = s.levelTraverse(tree->root);
//    for (auto i = res.begin(); i < res.end(); i++) {
//        vector<int> v = *i;
//        cout << "[";
//        for (auto j = v.begin(); j < v.end(); j++) {
//            cout << *j << " ";
//        }
//        cout << "]" << endl;
//    }
}