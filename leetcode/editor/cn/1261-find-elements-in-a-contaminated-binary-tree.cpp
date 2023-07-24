//给出一个满足下述规则的二叉树： 
//
// 
// root.val == 0 
// 如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 
//1 
// 如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x 
//+ 2 
// 
//
// 现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。 
//
// 请你先还原二叉树，然后实现 FindElements 类： 
//
// 
// FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。 
// bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：
//["FindElements","find","find"]
//[[[-1,null,-1]],[1],[2]]
//输出：
//[null,false,true]
//解释：
//FindElements findElements = new FindElements([-1,null,-1]); 
//findElements.find(1); // return False 
//findElements.find(2); // return True 
//
// 示例 2： 
//
// 
//
// 输入：
//["FindElements","find","find","find"]
//[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
//输出：
//[null,true,true,false]
//解释：
//FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
//findElements.find(1); // return True
//findElements.find(3); // return True
//findElements.find(5); // return False 
//
// 示例 3： 
//
// 
//
// 输入：
//["FindElements","find","find","find","find"]
//[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
//输出：
//[null,true,false,false,true]
//解释：
//FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
//findElements.find(2); // return True
//findElements.find(3); // return False
//findElements.find(4); // return False
//findElements.find(5); // return True
// 
//
// 
//
// 提示： 
//
// 
// TreeNode.val == -1 
// 二叉树的高度不超过 20 
// 节点的总数在 [1, 10^4] 之间 
// 调用 find() 的总次数在 [1, 10^4] 之间 
// 0 <= target <= 10^6 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 哈希表 二叉树 
// 👍 44 👎 0


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
class FindElements {
private:
    unordered_set<int> val_set;
public:
    FindElements(TreeNode *root) {
        root->val = 0;
        buildTree(root);
    }

    void buildTree(TreeNode *root) {
        if (!root) {
            return;
        }
        val_set.insert(root->val);
        if (root->left) {
            root->left->val = root->val * 2 + 1;
            val_set.insert(root->left->val);
            buildTree(root->left);
        }

        if (root->right) {
            root->right->val = root->val * 2 + 2;
            val_set.insert(root->right->val);
            buildTree(root->right);
        }
    }

    bool find(int target) {
        return val_set.count(target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    auto l = {0, -1, 0};
    Tree *tree = new Tree(l);
    FindElements *findElements = new FindElements(tree->root);
    bool flag = findElements->find(1);
    cout << flag << endl;

    flag = findElements->find(2);
    cout << flag << endl;

    l = {0, 0, 0, 0, 0};
    tree = new Tree(l);
    findElements = new FindElements(tree->root);
    flag = findElements->find(1);
    cout << flag << endl;
    flag = findElements->find(3);
    cout << flag << endl;
    flag = findElements->find(5);
    cout << flag << endl;
}