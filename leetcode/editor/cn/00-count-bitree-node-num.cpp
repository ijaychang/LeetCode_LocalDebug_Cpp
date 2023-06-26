//统计二叉树节点数。


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
    int count(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int leftCount = count(root->left);
        int rightCount = count(root->left);
        return leftCount + rightCount + 1;
    }

};


//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto list = {6, 3, 9, 1, 4, 7, 10};
    Tree *tree = new Tree(list);
    int res = s.count(tree->root);
    cout << res << endl;
}