#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums1, nums2;
    int size;
    cin >> size;
    nums1.resize(size), nums2.resize(size); // 调整大小
    for (int i = 0; i < size; i++)
    {
        cin >> nums1[i]; // 存数组
    }
    for (int i = 0; i < size; i++)
    {
        cin >> nums2[i]; // 存数组
    }

    int mid = size;            // 表示两个数组的中间位置（中位数的位置）
    int i = 0, j = 0;          // 标记nums1,nums2移动的位置
    int left = -1, right = -1; // mid/中位数的左右到数字
    for (int k = 0; k <= mid; k++)
    {
        left = right; // 更新left为上一次移动后的数组
        // 开始下一次移动
        if (i < size && (j >= size || nums1[i] < nums2[j])) 
        // 如果nums1没移动完 ，并且nums2移动完了，或者nums1此时更小
        {
            right = nums1[i]; // 这一次的往后移动一个数 存的是nums1的
            i++;              // 移动nums1
        }
        else
        {
            right = nums2[j];
            j++;
        }
    }

    if (mid % 2 == 0)
    {
        cout << (int)((left + right) / 2.0); 
        // 如果是偶数 中位数是两边数的平均
    }
    else
    {
        cout << right;
    }
    return 0;
}