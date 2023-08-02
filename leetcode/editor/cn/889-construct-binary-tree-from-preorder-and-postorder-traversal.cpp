//给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵
//树的后序遍历，重构并返回二叉树。 
//
// 如果存在多个答案，您可以返回其中 任何 一个。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [1], postorder = [1]
//输出: [1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= preorder.length <= 30 
// 1 <= preorder[i] <= preorder.length 
// preorder 中所有值都 不同 
// postorder.length == preorder.length 
// 1 <= postorder[i] <= postorder.length 
// postorder 中所有值都 不同 
// 保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 318 👎 0


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
    unordered_map<int, int> postMap;

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            postMap[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    // preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
    TreeNode *
    build(vector<int> &preorder, int preStart, int preEnd, vector<int> &postorder, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }

        // 根节点值
        int rootVal = preorder[preStart];
        // 创建根节点
        TreeNode *root = new TreeNode(rootVal);

        if (preStart == preEnd) {
            return root;
        }

        // 左子树根节点值
        int leftRootVal = preorder[preStart + 1];

        // 从后续遍历序列中找到左子树根节点所在序列的索引位置
        int leftRootIndex = postMap[leftRootVal];
        int leftSize = leftRootIndex - postStart + 1;
        int rightSize = postEnd - leftRootIndex;

        // 构建左子树
        root->left = build(preorder, preStart + 1, preStart + leftSize, postorder, postStart, postStart + leftSize - 1);

        // 构建右子树
        root->right = build(preorder, preStart + 1 + leftSize, preEnd, postorder, postStart + leftSize, postEnd - 1);

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> preorder{1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder{4, 5, 2, 6, 7, 3, 1};
    TreeNode *root = s.constructFromPrePost(preorder, postorder);
    print_tree(root);
}