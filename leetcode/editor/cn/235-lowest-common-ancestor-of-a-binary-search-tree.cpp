//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5] 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//输出: 6 
//解释: 节点 2 和节点 8 的最近公共祖先是 6。
// 
//
// 示例 2: 
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//输出: 2
//解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。 
//
// 
//
// 说明: 
//
// 
// 所有节点的值都是唯一的。 
// p、q 为不同节点且均存在于给定的二叉搜索树中。 
// 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 1126 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一：前序遍历 DFS
//class Solution {
//public:
//
//    void traverse(TreeNode *root, TreeNode *target, vector<TreeNode *> &ancestorList) {
//        if (root == nullptr) {
//            return;
//        }
//        ancestorList.push_back(root);
//        if (root->val == target->val) {
//            return;
//        }
//        if (target->val < root->val ) {
//            traverse(root->left, target, ancestorList);
//        } else {
//            traverse(root->right, target, ancestorList);
//        }
//    }
//
//    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
//        vector<TreeNode *> pAncestorList;
//        vector<TreeNode *> qAncestorList;
//        traverse(root, p, pAncestorList);
//        traverse(root, q, qAncestorList);
//        TreeNode *ancestor;
//        for (int i = 0 ; i < pAncestorList.size() && i < qAncestorList.size() ; i++) {
//            if (pAncestorList[i] == qAncestorList[i]) {
//                ancestor = pAncestorList[i];
//            } else {
//                break;
//            }
//        }
//        return ancestor;
//    }
//};

// 方法二：DFS 一次遍历
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *t = root;
        TreeNode *ancestor;
        for (;t != nullptr;) {
            if (p->val < t->val && q->val < t->val) {
                t = t->left;
            } else if (p->val > t->val && q->val > t->val) {
                t = t->right;
            } else {
                ancestor = t;
                break;
            }
        }
        return ancestor;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> list = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    Tree *tree = new Tree(list);
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(4);
    TreeNode *ancestor = s.lowestCommonAncestor(tree->root, p, q);
    cout << "ancestor =" << ancestor->val << endl;
}