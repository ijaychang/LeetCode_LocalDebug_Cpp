//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
// Related Topics 链表 分治 堆（优先队列） 归并排序 
// 👍 2611 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // 方法一
//class Solution {
//public:
//    ListNode *mergeKLists(vector<ListNode *> &lists) {
//        if (lists.empty()) {
//            return nullptr;
//        }
//        if (lists.size() == 1) {
//            return lists[0];
//        }
//
//        ListNode *res = lists[0];
//        for (int i = 1; i < lists.size(); i++) {
//            res = merge(lists[i], res);
//        }
//        return res;
//    }
//
//    ListNode *merge(ListNode *list1, ListNode *list2) {
//        ListNode *p, *dummy = new ListNode(-1), *p1 = list1, *p2 = list2;
//        p = dummy;
//        for (; p1 != nullptr && p2 != nullptr;) {
//            if (p1->val <= p2->val) {
//                p->next = p1;
//                p1 = p1->next;
//            } else {
//                p->next = p2;
//                p2 = p2->next;
//            }
//            p = p->next;
//        }
//        if (p1 != nullptr) {
//            p->next = p1;
//        }
//        if (p2 != nullptr) {
//            p->next = p2;
//        }
//        return dummy->next;
//    }
//};

// 方法二
//class Solution {
//public:
//    ListNode *mergeKLists(vector<ListNode *> &lists) {
//        if (lists.empty()) {
//            return nullptr;
//        }
//        return merge(lists, 0, lists.size() - 1);
//    }
//
//    ListNode *merge(vector<ListNode *> &lists, int low, int high) {
//        if (low > high) {
//            return nullptr;
//        }
//        if (high == low) {
//            return lists[low];
//        }
//        int mid = ((high - low) >> 1) + low;
//        ListNode *left = merge(lists, low, mid);
//        ListNode *right = merge(lists, mid + 1, high);
//        return mergeTwoList(left, right);
//    }
//
//    ListNode *mergeTwoList(ListNode *list1, ListNode *list2) {
//        if ((!list1) || (!list2)) {
//            return list1 ? list1 : list2;
//        }
//        ListNode *p, *dummy = new ListNode(-1), *p1 = list1, *p2 = list2;
//        p = dummy;
//        for (; p1 != nullptr && p2 != nullptr;) {
//            if (p1->val <= p2->val) {
//                p->next = p1;
//                p1 = p1->next;
//            } else {
//                p->next = p2;
//                p2 = p2->next;
//            }
//            p = p->next;
//        }
//        if (p1 != nullptr) {
//            p->next = p1;
//        }
//        if (p2 != nullptr) {
//            p->next = p2;
//        }
//        return dummy->next;
//    }
//};

// 方法三 (优先级队列)

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode* a,ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>, decltype(cmp)> q(cmp);

        ListNode *p;
        for (int i = 0 ; i < lists.size() ;i ++) {
            for(p = lists[i]; p != nullptr; p = p->next) {
                q.push(p);
            }
        }
        ListNode *dummy = new ListNode(-1);
        p = dummy;
        for (;!q.empty();) {
            p->next = q.top();
            q.pop();
            p = p->next;
        }
        p->next = nullptr;
        return dummy->next;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    // [],[-1,5,11],[],[6,10]
    Solution s;
    vector<int> v1{};
    vector<int> v2{-1, 5, 11};
    vector<int> v3{};
    vector<int> v4{6, 10};
    List *list1 = new List(v1);
    List *list2 = new List(v2);
    List *list3 = new List(v3);
    List *list4 = new List(v4);
    vector<ListNode *> list;
    list.push_back(list1->head);
    list.push_back(list2->head);
    list.push_back(list3->head);
    list.push_back(list4->head);
    ListNode *res = s.mergeKLists(list);
    print_list(res);
}