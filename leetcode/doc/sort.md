# 快排
## 普通
找一个基准值，比如可以第一个元素，或者最后一个元素。
![quick sort](quick-sort.png

![quick sort normal](quick-sort-normal.gif)
这里选择最后一个元素作为枢轴(基准值),一般都称作pivot，从左往右遍历数组，
如果小于等于pivot，则交换。

## 随机
随机基准位置快排是为了解决，如果数组是基本有序的情况下，分区不平衡的问题，最坏情况下时间复杂度将退化到O(n*n)的问题
## 双路
双路快排是为了解决有大量重复元素，导致分区不平衡的问题
![quick-sort-two](quick-sort-two.gif)
## 三路
三路快排同样是为了解决有大量重复元素，导致分区不平衡的问题，且多了中间一块相同元素值的分区，这块分区是不需要进行递归快排的，所以是在双路快排基础上的进一步的优化
![quick-sort-three](quick-sort-three.gif)








https://cloud.tencent.com/developer/article/1816491