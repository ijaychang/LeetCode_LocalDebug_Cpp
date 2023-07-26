//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并
//返回这颗 二叉树 。 
//
// 
//
// 示例 1: 
//
// 
//输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//输出：[3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入：inorder = [-1], postorder = [-1]
//输出：[-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder 和 postorder 都由 不同 的值组成 
// postorder 中每一个值都在 inorder 中 
// inorder 保证是树的中序遍历 
// postorder 保证是树的后序遍历 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 1057 👎 0


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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> inMap;
        // inorder 和 postorder 都由 不同 的值组成
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
    }

    TreeNode *build(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd,
                    unordered_map<int, int> &inMap) {

        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // 找根节点
        int rootVal = postorder[postEnd];
        // 得到左子树有几个节点，右子树有几个节点
        int inRootIndex = inMap.at(rootVal);
        int leftSize = inRootIndex - inStart;
        int rightSize = inEnd - inRootIndex;

        TreeNode *root = new TreeNode(rootVal);
        // 计算左子树inorder数组inStart,inEnd,左子树postorder数组postStart,postEnd

        // 构建左子树
        root->left = build(inorder, inStart, inRootIndex - 1, postorder, postStart, postStart + leftSize - 1, inMap);
        // 构建右子树
        root->right = build(inorder, inRootIndex + 1, inEnd, postorder, postStart + leftSize, postEnd - 1, inMap);
        return root;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};

    TreeNode *root = s.buildTree(inorder, postorder);

    print_tree(root);
}