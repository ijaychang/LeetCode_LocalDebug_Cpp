> Problem: [215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/description/)

[TOC]

# 思路
利用快排的 partition 分区算法


# 解题方法

题目要求第 k 大的元素值，可以转化为求第 k 大元素所在的索引。我们知道快排 partition 时需要返回一个索引 p 。 使得 nums[p] 大于等于 nums[low...p-1] 中的任何一个元素，nums[p] 小于等于 nums[p+1...high] 中的任何一个元素。那么此时 nums[p]，是不是就是第 p 个元素，我们只要限定当 p == nums.length - k 时，返回 nums[p] 就可以了。

不过我们要针对测试用例针对 partition 方法进行一些优化。

* 普通快排
以一个固定位置，比如数组第1个或最后1个元素值作为基准值。那么当数组是基本有序的时候，分区会极不平衡。时间复杂度会退化到 $O(n*n)$，想象下极端情况下，左分区只有1个元素，右分区是除了左分区那1个元素外的所有元素。这样的情况跟没有分区无异。
     
* 随机位置基准值快排
在普通快排基础上，做了一个小小的优化，即随机取基准值。以避免数组基本有序的情况下，分区不平衡的问题。
  
* 随机位置基准值双路快排
在随机快排的基础上，针对数组含有大量相同元素值的情况做了优化，定义左右两个指针，pLeft,pRight。

1. pLeft一直往右移动，直到 nums[pLeft] > pivot
2. pRight一直往左移动，知道 nums[pRight] < pivot
3. nums[pLeft] == pivot 且 nums[pRight] == pivot 时，通过 flip 变量控制 pLeft，pRight指针交替移动。从而有效地提升针对含大量相同元素值的数组进行 parition 时，左右分区的平衡度。

# 复杂度
- 时间复杂度: 
$O(logn)$

- 空间复杂度: 
 $O(n)$

# Code
```C++ []

class Solution {
public:
    int res = -1;

    int findKthLargest(vector<int> &nums, int k) {
        // 将第k大，转化为第几个
        int target = nums.size() - k;
        quickSort(nums, 0, nums.size() - 1, target);
        return res;
    }

    void quickSort(vector<int> &nums, int low, int high, int target) {
        if (low >= high) {
            if (low == target) {
                res = nums[low];
            }
            return;
        }
        int p = partition(nums, low, high);
        if (p == target) {
            res = nums[p];
            return;
        }
        if (target >= p) {
            quickSort(nums, p + 1, high, target);
        } else {
            quickSort(nums, low, p - 1, target);
        }
    }

    int partition(vector<int> &nums, int low, int high) {
        int randIndex = (rand() % (high - low + 1)) + low;
        swap(nums[low],nums[randIndex]);
        int pivot = nums[low];
        int pLeft = low + 1, pRight = high;
        bool flip = true;
        for(;;) {
            while(pLeft <= pRight && nums[pLeft] < pivot) {
                pLeft++;
            }
            while(pLeft <= pRight && nums[pRight] > pivot) {
                pRight--;
            }
            // 针对测试用例40的优化：nums[pLeft] nums[pRight] 都等于 pivot，则交替递增pLeft,递减pRight
            // 此项优化可以使得对于大量相同(更有甚者全部相同)元素值，可以做到分区平衡
            while(pLeft <= pRight && (nums[pLeft] == pivot && nums[pRight] == pivot)) {
                if (flip) {
                    pLeft++;
                } else {
                    pRight--;
                }
                flip = !flip;
            }

            if (pLeft > pRight) {
                break;
            }
            swap(nums[pLeft++],nums[pRight--]);
        }
        swap(nums[low],nums[pRight]);
        return pRight;
    }
};
```
