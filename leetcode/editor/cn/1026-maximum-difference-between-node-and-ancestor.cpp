//给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。 
//
//
// （如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先） 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
//输出：7
//解释： 
//我们有大量的节点与其祖先的差值，其中一些如下：
//|8 - 3| = 5
//|3 - 7| = 4
//|8 - 1| = 7
//|10 - 13| = 3
//在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
// 
//
// 示例 2： 
//
// 
//输入：root = [1,null,2,null,0,3]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在 2 到 5000 之间。 
// 0 <= Node.val <= 105 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 210 👎 0


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
private:
    int max_val = INT32_MIN;

public:
//    解法一[可惜超时了]
//    int maxAncestorDiff(TreeNode *root) {
//        if (!root) {
//            return max_val;
//        }
//        traverse(root, nullptr);
//        return max_val;
//    }
//
//    int traverse(TreeNode *root, TreeNode *parent) {
//        if (!root) {
//            return INT32_MIN;
//        }
//        int left_max_val = INT32_MIN, right_max_val = INT32_MIN;
//        if (root->left) {
//            left_max_val = traverse(root->left, root);
//        }
//        if (root->right) {
//            right_max_val = traverse(root->right, root);
//        }
//        if (parent) {
//            if (root->left) {
//                max_val = max(max_val, traverse(root->left, parent));
//            }
//            if (root->right) {
//                max_val = max(max_val, traverse(root->right, parent));
//            }
//            max_val = max(max_val, abs(parent->val - root->val));
//        }
//        return max_val = max({max_val, left_max_val, right_max_val});
//    }

//    int maxAncestorDiff(TreeNode *root) {
//        if (!root) {
//            return {};
//        }
//        stack<TreeNode *> s;
//        vector<int> track;
//
//        // 节点是否访问完成
//        unordered_map<TreeNode *, bool> visited_map;
//        // 每个节点的父节点
//        unordered_map<TreeNode *, TreeNode *> parent_map;
//        int max_val = INT32_MIN;
//
//        for (s.push(root); !s.empty();) {
//            TreeNode *cur = s.top();
//            s.pop();
//            // 当前节点的左右子树都为null，则表示当前节点为叶子节点
//            // 此时就可以计算从根节点到叶子节点路径上得到的二进制数的十进制数值
//            track.push_back(cur->val);
//
//            // 叶子节点打印路径
//            if (!cur->left && !cur->right) {
//                int sz = track.size();
//                int mi = track[0];
//                int ma = track[0];
//                for (int i = 0; i < sz; i++) {
//                    mi = min(mi, track[i]);
//                    ma = max(ma, track[i]);
//                }
//                max_val = max(max_val, abs(ma - mi));
//
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
//
//        return max_val;
//    }

//    迭代法
//    int maxAncestorDiff(TreeNode *root) {
//        if (!root) {
//            return {};
//        }
//        stack<TreeNode *> s;
//        TreeNode *pre, *cur = root;
//        vector<int> track;
//        int res = INT32_MIN;
//
//        while (cur || !s.empty()) {
//            while (cur) {
//                s.push(cur);
//                track.push_back(cur->val);
//                cur = cur->left;
//            }
//            cur = s.top();
//            // 没有右子树，或右子树已经访问过了
//            if (!cur->right || cur->right == pre) {
//
//                // 左右子树都没有，说明是访问到叶子节点了
//                if (!cur->left && !cur->right) {
//                    // 从根节点到叶子节点的一条路径
//                    int mi = track[0], ma = track[0];
//                    for (int i = 0; i < track.size(); i++) {
//                        mi = min(mi, track[i]);
//                        ma = max(ma, track[i]);
//                    }
//                    res = max(res, abs(ma - mi));
//                }
//
//                pre = cur;
//                // 这里将cur置为null，防止节点(有左子树的节点)被重复访问
//                cur = nullptr;
//                // 访问完叶子节点，或右子树访问过了，那么要将track撤掉尾部1个元素
//                track.pop_back();
//                s.pop();
//            } else {
//                pre = cur;
//                cur = cur->right;
//            }
//        }
//        return res;
//    }

    // 递归法
    int maxAncestorDiff(TreeNode *root) {
        int mi = root->val, ma = root->val, res = INT32_MIN;
        traverse(root, mi, ma, res);
        return res;
    }

    void traverse(TreeNode *root, int mi, int ma, int &res) {
        if (!root) {
            return;
        }
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        // 是叶子节点
        if (!root->left && !root->right) {
            res = max(res, abs(ma - mi));
            return;
        }
        traverse(root->left, mi, ma, res);
        traverse(root->right, mi, ma, res);
    }


//leetcode submit region end(Prohibit modification and deletion)


};


int main() {
    Solution s;
    auto l = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    Tree *tree = new Tree(l);
    int max_val = s.maxAncestorDiff(tree->root);
    cout << max_val << endl;
}