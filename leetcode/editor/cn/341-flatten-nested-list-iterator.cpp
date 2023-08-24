//给你一个嵌套的整数列表 nestedList 。每个元素要么是一个整数，要么是一个列表；该列表的元素也可能是整数或者是其他列表。请你实现一个迭代器将其扁平化
//，使之能够遍历这个列表中的所有整数。 
//
// 实现扁平迭代器类 NestedIterator ： 
//
// 
// NestedIterator(List<NestedInteger> nestedList) 用嵌套列表 nestedList 初始化迭代器。 
// int next() 返回嵌套列表的下一个整数。 
// boolean hasNext() 如果仍然存在待迭代的整数，返回 true ；否则，返回 false 。 
// 
//
// 你的代码将会用下述伪代码检测： 
//
// 
//initialize iterator with nestedList
//res = []
//while iterator.hasNext()
//    append iterator.next() to the end of res
//return res 
//
// 如果 res 与预期的扁平化列表匹配，那么你的代码将会被判为正确。 
//
// 
//
// 示例 1： 
//
// 
//输入：nestedList = [[1,1],2,[1,1]]
//输出：[1,1,2,1,1]
//解释：通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。 
//
// 示例 2： 
//
// 
//输入：nestedList = [1,[4,[6]]]
//输出：[1,4,6]
//解释：通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nestedList.length <= 500 
// 嵌套列表中的整数值在范围 [-106, 106] 内 
// 
// Related Topics 栈 树 深度优先搜索 设计 队列 迭代器 
// 👍 520 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


class NestedInteger {
  public:
    int m_val;
    bool m_isInteger;
    vector<NestedInteger> m_list;

    NestedInteger(const int &val) {
        this->m_val = val;
        this->m_isInteger = true;
    }

    NestedInteger(const vector<NestedInteger> &list) {
        this->m_list = list;
        this->m_isInteger = false;
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    const bool isInteger()  {
        return m_isInteger;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    const int getInteger() {
        // cout << "getInteger invoked" << endl;
        return this->m_val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() {
//        cout << "getList()" << endl;
//        cout << "getList " << this->m_list.size() << endl;

        return this->m_list;
    }
};

// 方法一 DFS
class NestedIterator {
public:
    queue<int> q;
    void traverse(vector<NestedInteger> &nestedList) {
        if (nestedList.empty()) {
            return;
        }
        for (int i = 0 ; i < nestedList.size() ; i ++) {
            NestedInteger e = nestedList[i];
            if (e.isInteger()) {
                q.push(e.getInteger());
            } else {
                vector<NestedInteger> list = e.getList();
                traverse(list);
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        traverse(nestedList);
    }

    int next() {
        int val = q.front();
        q.pop();
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    vector<NestedInteger> list;

    NestedInteger e1(0);
    list.push_back(e1);


    NestedInteger n11(1);
    NestedInteger n12(2);
    NestedInteger n13(3);
    vector<NestedInteger> list1;
    list1.push_back(n11);
    list1.push_back(n12);
    list1.push_back(n13);
    NestedInteger n1(list1);
    list.push_back(n1);



    NestedInteger n21(1);
    list.push_back(n21);

    vector<NestedInteger> list2;
    NestedInteger n221(21);
    NestedInteger n222(22);
    list2.push_back(n221);
    list2.push_back(n222);
    NestedInteger n22(list2);

    NestedInteger n23(3);
    vector<NestedInteger> list3;
    list3.push_back(n21);
    list3.push_back(n22);
    list3.push_back(n23);
    NestedInteger n2(list3);

    list.push_back(n2);


    NestedIterator it(list);
    for(;it.hasNext();) {
        cout << it.next() << endl;
    }

}