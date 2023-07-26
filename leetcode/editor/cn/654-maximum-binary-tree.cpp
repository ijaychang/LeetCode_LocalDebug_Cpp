//给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建: 
//
// 
// 创建一个根节点，其值为 nums 中的最大值。 
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。 
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。 
// 
//
// 返回 nums 构建的 最大二叉树 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,2,1,6,0,5]
//输出：[6,3,5,null,2,0,null,null,1]
//解释：递归调用如下所示：
//- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
//    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
//        - 空数组，无子节点。
//        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
//            - 空数组，无子节点。
//            - 只有一个元素，所以子节点是一个值为 1 的节点。
//    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
//        - 只有一个元素，所以子节点是一个值为 0 的节点。
//        - 空数组，无子节点。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[3,null,2,null,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 1000 
// nums 中的所有整数 互不相同 
// 
// Related Topics 栈 树 数组 分治 二叉树 单调栈 
// 👍 705 👎 0


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
    /**
     * [begin,end]
     *
     * @param nums
     * @param begin
     * @param end
     * @return
     */
    int biggestIndex(vector<int> &nums, int begin, int end) {
        int biggest = nums[begin];
        int biggestIndex = begin;
        for (int i = begin; i <= end; i++) {
            biggest = max(biggest, nums[i]);
            if (biggest == nums[i]) {
                biggestIndex = i;
            }
        }
        return biggestIndex;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return traverse(nums, 0, nums.size() - 1);
    }

    TreeNode *traverse(vector<int> &nums, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        int biggest_index = biggestIndex(nums, begin, end);
        TreeNode *root = new TreeNode(nums[biggest_index]);
        root->left = traverse(nums, begin, biggest_index - 1);
        root->right = traverse(nums, biggest_index + 1, end);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{3, 2, 1, 6, 0, 5};
    TreeNode *root = s.constructMaximumBinaryTree(data);
    print_tree(root);
}