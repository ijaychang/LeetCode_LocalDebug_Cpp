> Problem: [92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/description/)

[TOC]

# 思路
$[left,right]$ 范围内的子链表定义为 $subList$。

我们只要将 $[left,right]$ 范围内的链表反转，然后令 $left-1$ 处节点的 $next$指针指向 $right$ 位置的节点，令 $left$ 位置处节点的 $next$ 指针指向 $right$ 位置后的那个节点。

# 解题方法

定义五个指针 $cur$ $prev$ $next$ $pLeft$ $pPrevLeft$
* $cur$ 指向当前访问的节点
* $prev$ 指向之前访问过的节点
* $next$ 指向 $cur$ 的下一个节点
* $pLeft$ 指向 $left$ 位置所在节点
* $pPrevLeft$ 指向 $left$ 位置节点的前驱节点

pos 指当前访问节点所在位置

**算法步骤**

遍历整个链表
* 当 $pos == left-1$ 时，用 $pPrevLeft$ 指针记录下 $left-1$ 这个位置的节点。
* 当 $pos == left$ 时，用 $pLeft$ 记录下 $left$ 这个位置的节点。
* 当 $pos >= left + 1$ 且 $pos <= right$ 则需要将 $cur$ 的 $next$ 指针指向前一个节点，因为 $[left,right]$ 这个范围内节点是要反转的么。为什么不是 $pos$ 不是从 $left$ 开始？ 因为没必要反转 $left-1$ 位置处的节点。
* 当 $pos == right$ 时，此时就比较关键了，是时候将 $left-1$ 处节点的 $next$ 指针指向 $right$ 位置处的节点。同时将 $left$ 处节点的 $next$ 指针指向 $right$ 处节点的后继节点。此时便完成了反转。
* 每次循环结束前，用 $prev$ 记录上一次访问的节点，将 $cur$ 移动到下一个节点


> 注意如果 $left == right$ 那么等于说是无需反转了，直接返回head就完事了，还有当 $left == 1$ 时，这种情况，反转后的头节点，实际就是 $right$ 位置的节点。这种情况，我们就直接返回 $pPrevLeft$ 就可以了，因为这个时候 $pPrevLeft$ 指向的就是 $right$ 位置的节点。其余情况就返回 $head$ 节点。

# 复杂度
- 时间复杂度: 
只需遍历一遍链表，时间复杂即是 $O(n)$

- 空间复杂度: 
  $O(1)$

# Code
```C++ []

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
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right) {
            return head;
        }
        // 初始 cur 指向头节点，prev 为 nullptr，next 为 nullptr
        // 三指针技巧反转链表
        // 定义 pos 为 cur 所在位置，初始位置为 1
        int pos = 1;
        // 定义该节点为 left 位置所在节点的前一个节点(这里定义一个虚拟节点，避免空指针问题)
        ListNode *pPrevLeft = new ListNode(-1);
        // 定义该节点为 right 位置所在节点的后一个节点
        ListNode *pLeft = nullptr;
        ListNode *cur = head, *prev = nullptr, *next = nullptr;
        for (; cur != nullptr; pos++) {
            // 令 next 指向 cur 的后一个节点
            next = cur->next;
            if (pos == left - 1) {
                pPrevLeft = cur;
            } else if(pos == left) {
                pLeft = cur;
            } else if (pos == right) {
                pPrevLeft->next = cur;
                pLeft->next = cur->next;
            }
            // cur 的后一个节点的 next 指针指向 cur
            if (pos >= left + 1 && pos <= right) {
                cur->next = prev;
            }
            // prev 用于记录之前的 cur 所指向的节点
            prev = cur;
            // 将 cur 移动到下一个节点
            cur = next;
        }
        return left == 1 ? pPrevLeft->next : head;
    }
};
```
