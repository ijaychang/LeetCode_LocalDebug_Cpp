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
        unordered_map<int, int> inMap;
        int index = 0;
        // inMap记录inorder集合每个元素值对应的索引
        for (auto i = inorder.begin(); i < inorder.end(); i++, index++) {
            inMap.insert(make_pair(*i, index));
        }
        return doBuildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inMap);
    }

    /**
     *
     * @param preorder 前序集合
     * @param preStart 前序集合开始索引值(闭区间)
     * @param preEnd 前序集合结束索引值(开区间)
     * @param inorder 中序集合
     * @param inStart 中序集合开始索引值(闭区间)
     * @param inEnd  中序集合结束索引值(开区间)
     * @param inMap 中序值,索引值map
     * @return
     */
    TreeNode *doBuildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd,
                          unordered_map<int, int> &inMap) {
        if (preStart >= preEnd) {
            return nullptr;
        }
        // preStart指向的元素为根节点,rootVal为根节点的值
        int rootVal = preorder.at(preStart);
        // 创建根节点
        TreeNode *root = new TreeNode(rootVal);

        // 从inorder可以得到左子树节点数量，右子树节点数量，inRootIndex为在中序inorder集合的索引值
        int inRootIndex = inMap.at(rootVal);
        // 左子树节点数量，右子树节点数量
        int nodeNumOfLeftTree = inRootIndex - inStart;
        int nodeNumOfRightTree = inEnd - inRootIndex - 1;
        // 判断有没有左子树，有则创建左子树
        TreeNode *leftRoot = nullptr, *rightRoot = nullptr;
        if (nodeNumOfLeftTree > 0) {
            leftRoot = doBuildTree(preorder, preStart + 1, preStart + 1 + nodeNumOfLeftTree, inorder,
                                   inRootIndex - nodeNumOfLeftTree,
                                   inRootIndex, inMap);
        }
        // 判断有没有右子树，有则创建右子树
        if (nodeNumOfRightTree > 0) {

            rightRoot = doBuildTree(preorder, preStart + nodeNumOfLeftTree + 1,
                                    preStart + nodeNumOfLeftTree + nodeNumOfRightTree + 1, inorder,
                                    inRootIndex + 1,
                                    inEnd, inMap);
        }
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
    TreeNode *root = s.buildTree(preorder, inorder);
    print_tree(root);
}