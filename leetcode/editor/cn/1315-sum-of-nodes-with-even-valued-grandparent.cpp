//给你一棵二叉树，请你返回满足以下条件的所有节点的值之和： 
//
// 
// 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。） 
// 
//
// 如果不存在祖父节点值为偶数的节点，那么返回 0 。 
//
// 
//
// 示例： 
//
// 
//
// 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
//输出：18
//解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在 1 到 10^4 之间。 
// 每个节点的值在 1 到 100 之间。 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 88 👎 0


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
    int sumEvenGrandparent(TreeNode *root) {
        int sum = 0;
        traverse(root, nullptr, nullptr, sum);
        return sum;
    }

    void traverse(TreeNode *root, TreeNode *parent, TreeNode *grandparent, int &sum) {

        if (!root) {
            return;
        }
        if (grandparent && grandparent->val % 2 == 0) {
            sum += root->val;
        }
        traverse(root->left, root, parent, sum);
        traverse(root->right, root, parent, sum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5};
    Tree *tree = new Tree(l);
    int sum = s.sumEvenGrandparent(tree->root);
    cout << sum << endl;
}