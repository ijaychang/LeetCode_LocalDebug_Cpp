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

    void traverse(NTreeNode *root) {
        if (!root) {
            return;
        }
        printf("进入节点 %d ", root->val);
        if (root->children.empty()) {
            return;
        }
        for (NTreeNode *p : root->children) {
            int p_val = !p ? -1 : p->val;
            printf("从节点 %d 进入节点 %d ", root->val, p_val);
            traverse(p);
            printf("从节点 %d 回到节点 %d ", p_val, root->val);
        }
        printf("离开节点 %d ", root->val);
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    // 遇到0表示null
    // 遇到-1表示该层结束
    auto l = {1, 2, 3, 0, 4, 5, 6, 0};
    NTree *ntree = new NTree(l);
    s.traverse(ntree->root);
}