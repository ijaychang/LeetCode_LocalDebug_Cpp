//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。 
//
// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层
//为第 h 层，则该层包含 1~ 2h 个节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,4,5,6]
//输出：6
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目范围是[0, 5 * 104] 
// 0 <= Node.val <= 5 * 104 
// 题目数据保证输入的树是 完全二叉树 
// 
//
// 
//
// 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？ 
// Related Topics 树 深度优先搜索 二分查找 二叉树 
// 👍 998 👎 0


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
    int countLevel(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(countLevel(root->left), countLevel(root->right));
    }

    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        // 左子树高度
        int lh = countLevel(root->left);
        // 右子树高度
        int rh = countLevel(root->right);

        // 左右子树高度一样，说明左子树一定是一棵完美二叉树,因为节点已经填充到右子树了
        if (lh == rh) {
            return (1 << lh) + countNodes(root->right);
        }
        // 高度不相等，则右子树一定是一棵完美二叉树
        return (1 << rh) + countNodes(root->left);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int> list = {1, 2, 3, 4, 5, 6};
    Tree *tree = new Tree(list);
    Solution s;
    int res = s.countNodes(tree->root);
    cout << res << endl;
}