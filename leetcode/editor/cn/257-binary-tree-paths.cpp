//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 
// 👍 985 👎 0


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
//    方法一
//    vector<string> binaryTreePaths(TreeNode *root) {
//        if (!root) {
//            return {};
//        }
//        vector<string> res;
//
//        stack<TreeNode *> s;
//        vector<int> track;
//
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
//            // 叶子节点打印路径
//            if (!cur->left && !cur->right) {
//                int sz = track.size();
//                string sb;
//                for (int i = 0; i < sz; i++) {
//                    sb = sb + to_string(track[i]);
//                    if (i != sz - 1) {
//                        sb += "->";
//                    }
//                }
//                res.push_back(sb);
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
//        return res;
//    }

    // 方法二[后续遍历迭代法]
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) {
            return {};
        }
        stack<TreeNode *> s;
        TreeNode *pre, *cur = root;
        vector<string> res;
        vector<int> track;

        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                track.push_back(cur->val);
                cur = cur->left;
            }
            cur = s.top();
            // 没有右子树，或右子树已经访问过了
            if (!cur->right || cur->right == pre) {

                // 左右子树都没有，说明是访问到叶子节点了
                if (!cur->left && !cur->right) {
                    // 从根节点到叶子节点的一条路径
                    string sb = "";
                    for (int i = 0; i < track.size(); i++) {
                        sb += to_string(track[i]);
                        if (i != track.size() - 1) {
                            sb += "->";
                        }
                    }
                    res.push_back(sb);
                }

                pre = cur;
                // 这里将cur置为null，防止节点(有左子树的节点)被重复访问
                cur = nullptr;
                // 访问完叶子节点，或右子树访问过了，那么要将track撤掉尾部1个元素
                track.pop_back();
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
    auto l = {7, 1, 5, 3, 6, 4};
    Tree *tree = new Tree(l);
    vector<string> res = s.binaryTreePaths(tree->root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}