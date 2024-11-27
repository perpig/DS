#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2) // 保证一数组的个数一定小于二数组
            return findMedianSortedArrays(nums2, nums1);
        if (!size1) // 空数组的情况直接处理
        {
            return (size2 % 2)
                       ? nums2[size2 / 2]
                       : (nums2[size2 / 2 - 1] + nums2[size2 / 2]) / 2.0;
        }
        int lmax1, lmax2, rmin1, rmin2; // 左边最大值 右边最小值
        int c1, c2;                     // 切割的位置
        int left = 0, right = size1;    // 表示当前c1存在的区间
        while (left <= right)           // 范围没有缩小到一个位置的时候继续循环
        {
            c1 = (left + right) / 2;                 // c1是这个范围二分的结果
            c2 = (size1 + size2) / 2 - c1;           // 算出c2的位置
            lmax1 = (!c1) ? INT_MIN : nums1[c1 - 1]; // 对边界进行处理
            rmin1 = (c1 == size1) ? INT_MAX : nums1[c1];
            lmax2 = (!c2) ? INT_MIN : nums2[c2 - 1];
            rmin2 = (c2 == size2) ? INT_MAX : nums2[c2];
            if (lmax1 > rmin2)  // 开始比较对角线上的关系
                right = c1 - 1; // 如果第一个数组左边太大了，说明此时中位数比c1要往左移
            else if (lmax2 > rmin1)
                left = c1 + 1; // 如果第二个数组的左边太大了，c2需要往左走，那么c1往右走
            else               // 找到中位数了
                break;
        }
        double ou = (max(lmax1, lmax2) + min(rmin1, rmin2)) / 2.0;
        double ji = min(rmin1, rmin2);
        return (size1 + size2) % 2 ? ji : ou;
    }
};
