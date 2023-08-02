//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的
//方法解决这个问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 104] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 
// 👍 1131 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string DELIMITER_STR = ",";
    string NULL_STR = "#";

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) {
            return NULL_STR;
        }
        string left_subtree = serialize(root->left);
        string right_subtree = serialize(root->right);
        return to_string(root->val) + DELIMITER_STR + left_subtree + DELIMITER_STR + right_subtree;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        size_t start;
        size_t end = 0;
        vector<string> v;
        while ((start = data.find_first_not_of(DELIMITER_STR, end)) != string::npos) {
            end = data.find(DELIMITER_STR, start);
            v.push_back(data.substr(start, end - start));
        }
        TreeNode *root = doDeserialize(v);
        return root;

    }

    TreeNode *doDeserialize(vector<string> &v) {
        if (v.empty()) {
            return nullptr;
        }
        // 取出第一个元素
        string str = v.front();
        // 删掉第一个元素
        v.erase(v.begin());
        if (str == NULL_STR) {
            return nullptr;
        }
        int val = stoi(str);
        TreeNode *root = new TreeNode(val);
        root->left = doDeserialize(v);
        root->right = doDeserialize(v);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Codec c;
    vector<int> data{1, 2, 3, -1, -1, 4, 5};
    Tree *tree = new Tree(data);
    string s = c.serialize(tree->root);
    cout << s << endl;
    TreeNode *root = c.deserialize(s);
    print_tree(root);

}