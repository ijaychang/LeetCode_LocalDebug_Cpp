//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。 
//
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。 
//
// 
//
// 示例 1： 
//
// 
//输入：p = [1,2,3], q = [1,2,3]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：p = [1,2], q = [1,null,2]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：p = [1,2,1], q = [1,1,2]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 两棵树上的节点数目都在范围 [0, 100] 内 
// -104 <= Node.val <= 104 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 1031 👎 0


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
// 方法一：递归方式
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if (p && !q || !p && q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
// 方法二：迭代方式

//    bool isSameTree(TreeNode *p, TreeNode *q) {
//        if (!p && !q) {
//            return true;
//        }
//        stack<TreeNode *> sp, sq;
//        TreeNode *cp, *cq;
//        for (sp.push(p), sq.push(q); !sp.empty() && !sq.empty();) {
//            cp = sp.top();
//            cq = sq.top();
//
//            if (cp && !cq || !cp && cq) {
//                return false;
//            }
//
//            sp.pop();
//            sq.pop();
//
//            if (cp->val != cq->val) {
//                return false;
//            }
//
//            if (cp->right && !cq->right || !cp->right && cq->right) {
//                return false;
//            }
//
//            if (cp->left && !cq->left || !cp->left && cq->left) {
//                return false;
//            }
//
//            if (cp->right) {
//                sp.push(cp->right);
//            }
//            if (cp->left) {
//                sp.push(cp->left);
//            }
//
//            if (cq->right) {
//                sq.push(cq->right);
//            }
//            if (cq->left) {
//                sq.push(cq->left);
//            }
//        }
//
//        if (sp.size() != sq.size()) {
//            return false;
//        }
//        return true;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto list1 = {1, 2, 3};
    auto list2 = {1, 2, 3};
    Tree *t1 = new Tree(list1);
    Tree *t2 = new Tree(list2);
    bool flag = s.isSameTree(t1->root, t2->root);
    cout << flag << endl;
}