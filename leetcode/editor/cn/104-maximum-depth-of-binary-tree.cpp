//给定一个二叉树，找出其最大深度。 
//
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例： 
//给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 1630 👎 0


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
    // 方法一： DFS深度优先
//    int maxDepth(TreeNode *root) {
//        if (!root) {
//            return 0;
//        }
//        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//    }

    // 方法二： BFS广度优先
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode *> q;
        TreeNode *node;
        int maxDepth = 0, currentLevelSize;
        for (q.push(root); !q.empty(); maxDepth++) {
            currentLevelSize = q.size();
            for (int count = 0; count < currentLevelSize; count++) {
                node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return maxDepth;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto list = {1, 2, 3, 4, 5, 6, 7, 8};
    Tree *tree = new Tree(list);
    int maxDepth = s.maxDepth(tree->root);
    cout << maxDepth << endl;
}