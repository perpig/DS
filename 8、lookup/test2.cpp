#include <bits\stdc++.h>
using namespace std;


//方法一：暴力，此方法时间复杂度不为log(n)
double Test2Force(int* nums1, int* nums2, int size1, int size2) 
{
    vector<int> array;

    int index1 = 0;
    int index2 = 0;

    while(index1 < size1 || index2 < size2){
        if(index1 == size1){
            for (int i = index2; i < size2; i++){
                array.push_back(nums2[i]);
            }
            break;
        }else if (index2 == size2){
            for (int i = index1; i < size1; i++){
                array.push_back(nums1[i]);
            }
            break;
        }
        array.push_back(nums1[index1] < nums2[index2] ? nums1[index1] : nums2[index2]);
        if(nums1[index1] < nums2[index2]){
            index1++;
        }
        else{
            index2++;
        }
    }

    int sizeArray = array.size() / 2;
    if(array.size() % 2 == 0) return (array[sizeArray - 1] + array[sizeArray]) / 2.00;
    else return array[sizeArray];
};



//方法2：Leetcode,切分
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2)
            return findMedianSortedArrays(nums2, nums1);
        if (!size1) {
            return (size2 % 2)
                       ? nums2[size2 / 2]
                       : (nums2[size2 / 2 - 1] + nums2[size2 / 2]) / 2.0;
        }
        int lmax1, lmax2, rmin1, rmin2;
        int c1 = 0, c2;
        int start = 0, end = size1 + size2 - 1;
        while (true) {
            c2 = (size1 + size2) / 2 - c1;
            lmax1 = (!c1) ? INT_MIN : nums1[c1 - 1];
            rmin1 = (c1 == size1) ? INT_MAX : nums1[c1];
            lmax2 = (!c2) ? INT_MIN : nums2[c2 - 1];
            rmin2 = (c2 == size2) ? INT_MAX : nums2[c2];
            if (lmax1 > rmin2 || lmax2 > rmin1)
                c1++;
            else
                break;
        }
        double ji = (max(lmax1, lmax2) + min(rmin1, rmin2)) / 2.0;
        double ou = min(rmin1, rmin2);
        return (size1 + size2) % 2 ? ou : ji;
    };



//方法3：二分递归
int kMinNum(int start1, int end1, int nums1[], int start2, int end2, int nums2[], int k) {
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;
    if (len1 > len2) return kMinNum(start2, end2, nums2, start1, end1, nums1, k);
    if (len1 == 0) return nums2[start2 + k - 1];
    if (k == 1) return min(nums1[start1], nums2[start2]);
    int i = start1 + min(len1, k / 2) - 1;
    int j = start2 + min(len2, k / 2) - 1;

    if (nums1[i] > nums2[j]) {
        return kMinNum(start1, end1, nums1, j + 1, end2, nums2, k - (j - start2 + 1));
    } else {
        return kMinNum(i + 1, end1, nums1, start2, end2, nums2, k - (i - start1 + 1));
    }
};

double Test4S1(int nums1[], int nums2[], int n, int m) {
    int left = (n + m + 1) / 2;
    int right = (n + m + 2) / 2;
    return (kMinNum(0, n - 1, nums1, 0, m - 1, nums2, left) + kMinNum(0, n - 1, nums1, 0, m - 1, nums2, right)) * 0.5;
};


int main() {
    vector<int> nums3={1, 3, 5};
    vector<int> nums4={2, 4, 6};
    int nums1[] = {1, 3, 5};
    int nums2[] = {2, 4, 6};
    int n = sizeof(nums1) / sizeof(nums1[0]);
    int m = sizeof(nums2) / sizeof(nums2[0]);
    cout << "方法1: " << Test2Force(nums1, nums2, n, m) << endl;
    cout << "方法2: " << findMedianSortedArrays(nums3, nums4) << endl;
    cout << "方法3: " << Test4S1(nums1, nums2, n, m) << endl;

    return 0;
}