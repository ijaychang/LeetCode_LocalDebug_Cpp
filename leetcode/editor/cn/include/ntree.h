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
#ifndef _NTREE_H_
#define _NTREE_H_

#include <vector>
#include <iostream>
#include <initializer_list>
#include <queue>
#include <list>

namespace LeetCode {
    int NULL_VAL = -1;

    struct NTreeNode {
        int val;
        std::vector<NTreeNode *> children;


        NTreeNode(int x = 0) : val(x) {}
    };

    void print_tree(NTreeNode *root);

    bool is_same_tree(NTreeNode *root1, NTreeNode *root2);

    class NTree {
    public:
        NTreeNode *root;

    private:
        std::queue<int> q;

    public:
        NTree(std::initializer_list<int> il);

        ~NTree();

        void print();

        bool operator==(const NTree &t2) const;

    private:
        NTreeNode *deserialize(std::queue<int> &in);
    };
} // namespace LeetCode

#endif //!_NTREE_H_