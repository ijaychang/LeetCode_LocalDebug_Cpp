//给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。 
//
// 
// 例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。 
// 
//
// 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。 
//
// 返回这些数字之和。题目数据保证答案是一个 32 位 整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,0,1,0,1,0,1]
//输出：22
//解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
// 
//
// 示例 2： 
//
// 
//输入：root = [0]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在 [1, 1000] 范围内 
// Node.val 仅为 0 或 1 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 237 👎 0


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

// 性能较差
//    int sumRootToLeaf(TreeNode *root) {
//        if (!root) {
//            return {};
//        }
//        stack<TreeNode *> s;
//        vector<int> track;
//
//        int sum = 0;
//        // 节点是否访问完成
//        unordered_map<TreeNode *, bool> visited_map;
//        // 每个节点的父节点
//        unordered_map<TreeNode *, TreeNode *> parent_map;
//
//        for (s.push(root); !s.empty();) {
//            TreeNode *cur = s.top();
//            s.pop();
//            // 当前节点的左右子树都为null，则表示当前节点为叶子节点
//            // 此时就可以计算从根节点到叶子节点路径上得到的二进制数的十进制数值
//            track.push_back(cur->val);
//
//
//            // 叶子节点打印路径
//            if (!cur->left && !cur->right) {
//                int sz = track.size();
//                for (int i = 0; i < sz; i++) {
//                    cout << track[i] << " ";
//                }
//                cout << endl;
//                for (int i = 0; i < sz; i++) {
//                    if (track[i] == 1) {
//                        sum += pow(2, sz - i - 1);
//                    }
//                }
//                // 相当于撤销操作
//                track.pop_back();
//                visited_map[cur] = true;
//            }
//
//            // 父节点的左右子树都已经访问过了，则可以撤销该父节点了
//            for (TreeNode *parent = parent_map[cur]; parent && parent != root;) {
//                if (parent) {
//                    if (parent->left && parent->right) {
//                        if (visited_map[parent->left] && visited_map[parent->right]) {
//                            visited_map[parent] = true;
//                            track.pop_back();
//                        }
//                    } else if (parent->left) {
//                        if (visited_map[parent->left]) {
//                            visited_map[parent] = true;
//                            track.pop_back();
//                        }
//                    } else if (parent->right) {
//                        if (visited_map[parent->right]) {
//                            visited_map[parent] = true;
//                            track.pop_back();
//                        }
//                    }
//                }
//                parent = parent_map[parent];
//            }
//
//
//            if (cur->right) {
//                parent_map[cur->right] = cur;
//                s.push(cur->right);
//            }
//            if (cur->left) {
//                parent_map[cur->left] = cur;
//                s.push(cur->left);
//            }
//        }
//        return sum;
//    }

// 递归法
//    int sumRootToLeaf(TreeNode *root) {
//        if (!root) {
//            return 0;
//        }
//        return traverse(root, 0);
//    }
//
//    int traverse(TreeNode *root, int val) {
//        val = val << 1 | root->val;
//        if (!root->left && !root->right) {
//            return val;
//        }
//        return traverse(root->left, val) + traverse(root->right, val);
//    }

    // 迭代法(带打印调试)
//    int sumRootToLeaf(TreeNode *root) {
//        if (!root) {
//            return 0;
//        }
//        stack<TreeNode *> s;
//        TreeNode *pre;
//        TreeNode *cur = root;
//        int res = 0, val = 0;
//        vector<int> track;
//
//        while (cur || !s.empty()) {
//            while (cur) {
//                s.push(cur);
//                val = (val << 1) | cur->val;
//                track.push_back(cur->val);
//                cur = cur->left;
//            }
//            cur = s.top();
//
//            // 没有右子树，或右子树已经访问过了
//            if (!cur->right || cur->right == pre) {
//                // 左右子树都没有，说明是访问到叶子节点了
//                if (!cur->left && !cur->right) {
//                    res += val;
//
//                    for (int i = 0; i < track.size(); i++) {
//                        cout << track[i] << " ";
//                    }
//                    cout << endl;
//                }
//                val = val >> 1;
//                track.pop_back();
//                // 这里将cur置为null，防止节点(有左子树的节点)被重复访问
//                pre = cur;
//                cur = nullptr;
//                s.pop();
//            } else {
//                pre = cur;
//                cur = cur->right;
//            }
//        }
//
//        return res;
//    }

    int sumRootToLeaf(TreeNode *root) {
        if (!root) {
            return 0;
        }
        stack<TreeNode *> s;
        TreeNode *pre;
        TreeNode *cur = root;
        int res = 0, val = 0;

        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                val = (val << 1) | cur->val;
                cur = cur->left;
            }
            cur = s.top();

            // 没有右子树，或右子树已经访问过了
            if (!cur->right || cur->right == pre) {
                // 左右子树都没有，说明是访问到叶子节点了
                if (!cur->left && !cur->right) {
                    res += val;
                }
                val = val >> 1;
                pre = cur;
                // 这里将cur置为null，防止节点(有左子树的节点)被重复访问
                cur = nullptr;
                s.pop();
            } else {
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto l = {1, 2, 3, 4, 0, 6, 7, 8, 9};
    Tree *tree = new Tree(l);
    int sum = s.sumRootToLeaf(tree->root);
    cout << sum << endl;

}