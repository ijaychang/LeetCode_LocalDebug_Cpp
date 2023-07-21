/**
 *
 *
 * @file
 * @author   Jay Chang (jaychang1987@gmail.com)
 * @date     2023-07
 * @brief
 * @version  0.0.1
 *
 * Last Modified:  2023-07-19
 * Modified By:    Jay Chang (jaychang1987@gmail.com)
 * 
 */
#include "ntree.h"

namespace LeetCode {
    void print_tree(NTreeNode *root) {
        using std::cout;
        using std::endl;
        using std::queue;

        if (root == nullptr) {
            cout << "NULL" << endl;
            return;
        }
        queue<NTreeNode *> root_ptrs;

        root_ptrs.push(root);

        while (!root_ptrs.empty()) {
            NTreeNode *temp = root_ptrs.front();
            if (temp == nullptr) {
                cout << "NULL ";
            } else {
                cout << temp->val << " ";
            }
            if (temp->children.empty()) {
                continue;
            }
            for (NTreeNode *p : temp->children) {
                root_ptrs.push(p);
            }
            root_ptrs.pop();
        }
        cout << endl;
    }

    bool is_same_tree(NTreeNode *root1, NTreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr || root2 == nullptr) {
            return false;
        } else if (root1->val == root2->val) {
            if (root1->children.empty() && root2->children.empty()) {
                return true;
            } else if (root1->children.empty() || root2->children.empty()) {
                return false;
            } else if (root1->children.size() != root2->children.size()) {
                return false;
            } else {
                auto p1 = root1->children.begin();
                auto p2 = root2->children.begin();
                for (; p1 <= root1->children.end() && p2 <= root2->children.end(); p1++, p2++) {
                    if (!is_same_tree(*p1, *p2)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    NTree::NTree(std::initializer_list<int> il) : q(il) {
        if (q.empty())
            return;
        root = deserialize(q);
    }

    void delete_root_helper(NTreeNode *root) {
        if (root == nullptr)
            return;
        std::vector<NTreeNode *> p_children = root->children;
        delete root;
        root = nullptr;
        if (p_children.empty()) {
            return;
        }
        for (NTreeNode *p : p_children) {
            delete_root_helper(p);
        }
        return;
    }

    NTree::~NTree() {
        delete_root_helper(root);
    }

    NTreeNode *NTree::deserialize(std::queue<int> &in) {
        using std::queue;

        queue<NTreeNode *> root_ptrs;
        // -1相当于null
        if (in.empty() || in.front() == NULL_VAL) {
            return nullptr;
        }
        // 创建一个节点
        NTreeNode *temp = new NTreeNode(in.front());
        // 定义用于返回的节点指针
        NTreeNode *ret = temp;
        in.pop();
        root_ptrs.push(temp);

        while (!in.empty()) {
            temp = root_ptrs.front();

            int v = in.front();

        }
        return ret;
    }

    void NTree::print() {
        print_tree(root);
    }

    bool NTree::operator==(const NTree &t2) const {
        return is_same_tree(root, t2.root);
    }

} // namespace LeetCode