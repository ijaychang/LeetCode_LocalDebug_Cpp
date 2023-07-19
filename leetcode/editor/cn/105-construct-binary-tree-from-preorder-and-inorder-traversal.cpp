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
            return null;
        }
        unordered_map<int, int> inMap;
        int index = 0;
        for (auto i = inorder.begin(); i < inorder.end(); i++, index++) {
            inMap.insert((*i, index));
        }
        return doBuildTree(preorder, inorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }

    TreeNode *doBuildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder int inStart, int inEnd,
                          unordered_map<int, int> &inMap) {
        if (preStart >= preEnd) {
            return;
        }
        // preStart指向的元素为根节点
        int rootVal = preorder.at(preStart);
        // 创建根节点
        TreeNode *root = new TreeNode(rootVal);

        // 从inorder找左子树，右子树
        int indexOfRoot = inMap.at(rootVal);
        // 左子树节点数量，右子树节点数量
        int nodeNumOfLeftTree = indexOfRoot - inStart;
        int nodeNumOfRightTree = inEnd - indexOfRoot;
        // 创建左子树
        TreeNode *leftRoot = doBuildTree(preorder, preStart + 1, preStart + nodeNumOfLeftTree, inorder, inStart,
                                         inStart + nodeNumOfLeftTree, inMap);

        // 创建右子树
        TreeNode *rightRoot = doBuildTree(preorder, preStart + nodeNumOfLeftTree + 1,
                                          preStart + nodeNumOfLeftTree + nodeNumOfRightTree, inorder, indexOfRoot + 1,
                                          inEnd);

        // 设置根节点的左子树
        root->left = leftRoot;
        // 设置根节点的右子树
        root->right = rightRoot;

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    // 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
}