//给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,1,4,null,2], k = 1
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：root = [5,3,6,2,4,null,null,1], k = 3
//输出：3
// 
//
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数为 n 。 
// 1 <= k <= n <= 104 
// 0 <= Node.val <= 104 
// 
//
// 
//
// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？ 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 747 👎 0


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
//    方法一：递归法
//    int kthSmallest(TreeNode *root, int k) {
//        int rank = 0, res = 0;
//        traverse(root, k, rank, res);
//        return res;
//    }
//
//    void traverse(TreeNode *root, int k, int &rank, int &res) {
//        if (!root) {
//            return;
//        }
//        traverse(root->left, k, rank, res);
//        rank++;
//        if (rank == k) {
//            res = root->val;
//            return;
//        }
//        traverse(root->right, k, rank, res);
//    }

//    方法二：迭代法

    int kthSmallest(TreeNode *root, int k) {
        if (!root) {
            return 0;
        }
        stack<TreeNode *> s;
        int rank = 0;
        for (TreeNode *cur = root; cur || !s.empty();) {
            for (; cur; cur = cur->left) {
                s.push(cur);
            }
            cur = s.top();
            s.pop();
            rank++;
            if (rank == k) {
                return cur->val;
            }
            // cur的右子树的根节点为null，则下次访问cur的父节点
            cur = cur->right;
        }
        return 0;
    }


};


//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto list = {6, 3, 9, 1, 4, 7, 10};
    Tree *tree = new Tree(list);
    int res = s.kthSmallest(tree->root, 3);
    cout << res << endl;
}