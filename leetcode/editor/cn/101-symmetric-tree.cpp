//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 2452 👎 0


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
//    方法一：广度优先法
//    bool currentLevelIsSymmetric(list<TreeNode *> &l) {
//        TreeNode *headNode, *tailNode;
//        for (; !l.empty();) {
//            headNode = l.front();
//            l.pop_front();
//            tailNode = l.back();
//            l.pop_back();
//
//            if (!headNode && !tailNode) {
//                continue;
//            }
//            if (!headNode || !tailNode) {
//                return false;
//            }
//            if (headNode->val != tailNode->val) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    bool isSymmetric(TreeNode *root) {
//        if (!root) {
//            return 0;
//        }
//
//        queue<TreeNode *> q;
//        list<TreeNode *> l;
//
//        TreeNode *node;
//        int depth = 0, currentLevelSize;
//        for (q.push(root); !q.empty(); depth++) {
//            currentLevelSize = q.size();
//            l.clear();
//            for (int count = 0; count < currentLevelSize; count++) {
//                node = q.front();
//                q.pop();
//                if (!node) {
//                    l.push_back(node);
//                    continue;
//                }
//                if (node->left) {
//                    q.push(node->left);
//                } else {
//                    q.push(nullptr);
//                }
//                if (node->right) {
//                    q.push(node->right);
//                } else {
//                    q.push(nullptr);
//                }
//                l.push_back(node);
//            }
//
//            if (depth > 0 && l.size() % 2 != 0) {
//                return false;
//            }
//
//            if (depth > 0 && !currentLevelIsSymmetric(l)) {
//                return false;
//            }
//
//        }
//
//        return true;
//    }

//  方法二：深度优先法
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return check(root->left, root->right);
    }

    // 检查两棵树是否镜像对称
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }
        return check(p->right, q->left) && check(p->left, q->right);
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {1, 2, 2, 4, 6, 6, 4};
    Tree *tree = new Tree(l);
    bool flag = s.isSymmetric(tree->root);
    cout << flag;

}