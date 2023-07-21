//给定一个整数数组，它表示BST(即 二叉搜索树 )的 先序遍历 ，构造树并返回其根。 
//
// 保证 对于给定的测试用例，总是有可能找到具有给定需求的二叉搜索树。 
//
// 二叉搜索树 是一棵二叉树，其中每个节点， Node.left 的任何后代的值 严格小于 Node.val , Node.right 的任何后代的值 严格大
//于 Node.val。 
//
// 二叉树的 前序遍历 首先显示节点的值，然后遍历Node.left，最后遍历Node.right。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：preorder = [8,5,1,7,10,12]
//输出：[8,5,10,1,7,null,12]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [1,3]
//输出: [1,null,3]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= preorder.length <= 100 
// 1 <= preorder[i] <= 10^8 
// preorder 中的值 互不相同 
// 
//
// 
// Related Topics 栈 树 二叉搜索树 数组 二叉树 单调栈 
// 👍 261 👎 0


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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        unordered_map<int, int> in_map;
        int index = 0;
        // in_map记录inorder集合每个元素值对应的索引
        for (int i = 0; i < inorder.size(); i++) {
            in_map[inorder[i]] = i;
        }
        return doBuildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), in_map);
    }

    /**
     *
     * @param preorder 前序集合
     * @param pre_start 前序集合开始索引值(闭区间)
     * @param pre_end 前序集合结束索引值(开区间)
     * @param inorder 中序集合
     * @param in_start 中序集合开始索引值(闭区间)
     * @param in_end  中序集合结束索引值(开区间)
     * @param in_map 中序值,索引值map
     * @return
     */
    TreeNode *
    doBuildTree(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end,
                unordered_map<int, int> &in_map) {
        if (pre_start >= pre_end || in_start >= in_end) {
            return nullptr;
        }
        // pre_start指向的元素为根节点,rootVal为根节点的值
        // int rootVal = preorder.at(pre_start);
        int rootVal = preorder[pre_start];
        // 创建根节点
        TreeNode *root = new TreeNode(rootVal);

        // 从inorder可以得到左子树节点数量，右子树节点数量，in_root_index为在中序inorder集合的索引值
        int in_root_index = in_map.at(rootVal);
        // 左子树节点数量，右子树节点数量
        int size_left_sub_tree = in_root_index - in_start;
        int size_right_sub_tree = in_end - in_root_index - 1;
        // 设置根节点的左子树
        if (size_left_sub_tree > 0) {
            root->left = doBuildTree(preorder, pre_start + 1, pre_start + 1 + size_left_sub_tree, inorder,
                                     in_root_index - size_left_sub_tree,
                                     in_root_index, in_map);
        }
        // 设置根节点的右子树
        if (size_right_sub_tree > 0) {
            root->right = doBuildTree(preorder, pre_start + size_left_sub_tree + 1,
                                      pre_start + size_left_sub_tree + size_right_sub_tree + 1, inorder,
                                      in_root_index + 1,
                                      in_end, in_map);
        }
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        vector<int> inorder;
        for (int i = 0; i < preorder.size(); i++) {
            inorder.push_back(preorder[i]);
        }
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder, inorder);
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{8, 5, 1, 7, 10, 12};
    TreeNode *root = s.bstFromPreorder(data);
    print_tree(root);
}