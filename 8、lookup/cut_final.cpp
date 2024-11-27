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
        int c1 = 0, c2;                 // 切割的位置 c1直接设置为最前面
        while (true)
        {
            c2 = (size1 + size2) / 2 - c1;           // 算出c2的位置
            lmax1 = (!c1) ? INT_MIN : nums1[c1 - 1]; // 对边界进行处理
            rmin1 = (c1 == size1) ? INT_MAX : nums1[c1];
            lmax2 = (!c2) ? INT_MIN : nums2[c2 - 1];
            rmin2 = (c2 == size2) ? INT_MAX : nums2[c2];
            if (lmax1 > rmin2 || lmax2 > rmin1) // 开始比较对角线上的关系
                c1++;      // 找不到合适的切割位置就往后移动一个单位继续
            else
                break; // 如果找到合适的切割位置就结束循环
        }
        double ou = (max(lmax1, lmax2) + min(rmin1, rmin2)) / 2.0;
        double ji = min(rmin1, rmin2);
        return (size1 + size2) % 2 ? ji : ou;
    }
};
