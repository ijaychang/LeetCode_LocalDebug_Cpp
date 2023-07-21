//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
//
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 2013 👎 0


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
    TreeNode *doBuildTree(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end,
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
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    // 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = s.buildTree(preorder, inorder);
    print_tree(root);
}