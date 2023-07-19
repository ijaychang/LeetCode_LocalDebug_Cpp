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

    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        int leftVal = root->left ? root->left->val : -1;
        int rightVal = root->right ? root->right->val : -1;
        printf("从节点 %d 进入节点 %d\n", root->val, leftVal);
        traverse(root->left);
        printf("从节点 %d 回到节点 %d\n", leftVal, root->val);

        printf("从节点 %d 进入节点 %d\n", root->val, rightVal);
        traverse(root->right);
        printf("从节点 %d 回到节点 %d\n", rightVal, root->val);
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {1, 2, 3, 4, 5};
    Tree *tree = new Tree(l);
    s.traverse(tree->root);
}