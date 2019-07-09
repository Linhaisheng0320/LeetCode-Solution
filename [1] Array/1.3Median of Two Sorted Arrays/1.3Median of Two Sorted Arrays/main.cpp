//
//  main.cpp
//  1.3Median of Two Sorted Arrays
//
//  Created by 林海生 on 2019/3/4.
//  Copyright © 2019年 林海生. All rights reserved.
//

#include <iostream>
#include "vector"

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0){
            return medianArray(nums2);
        }

        if (nums2.size() == 0){
            return medianArray(nums1);
        }

        int length = nums1.size() + nums1.size();
        int flag =  (length & 0) == 0;
        int mind  = length/2;
        int j = 0,k = 0;
        int a = 0,b = 0;
        vector<int> medianNum;


        for (int i = 0;i < length; i++){
            a = j < nums1.size() ? nums1[j] : INT_MAX;
            b = k < nums2.size() ? nums2[k] : INT_MAX;
            if (a < b){
                medianNum.push_back(a);
                j++;

            }else{
                medianNum.push_back(b);
                k++;
            }

            if(i == mind){
                break;
            }
        }

        return ((medianNum[mind] + medianNum[mind-flag])/2.0);
    }

    double medianArray(vector<int>& nums){
        if (nums.size() > 0){
            int flag = (nums.size() & 0)==0;
            int median = nums.size()/2;
            return ((nums[median] + nums[median-flag])/2);
        }else{
            return 0;
        }
    };
};



int main(int argc, const char * argv[]) {
    vector<int> num1 = {1,2};
    vector<int> num2 = {2,3,6};
    Solution s;
    auto num = s.findMedianSortedArrays(num1, num2);
    // insert code here...
    std::cout << num;
    return 0;
}
