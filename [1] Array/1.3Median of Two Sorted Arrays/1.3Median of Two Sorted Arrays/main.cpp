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

        int a=0;
        int x=0;
        int b=0;
        int y=0;
        vector<int> nums;
        int length = nums1.size() + nums2.size();
        int mind = length/2;
        int flat = (length&1) == 0;
        for (int i = 0;i <= mind ; i++){
            a = x < nums1.size() ? nums1[x] : INT_MAX;
            b = y < nums2.size() ? nums2[y] : INT_MAX;

            if (a < b){
                x++;
                nums.push_back(a);
            }else{
                y++;
                nums.push_back(b);
            }
        }

        return (nums[mind]+nums[mind-flat])/2.0;
    }

    double medianArray(vector<int>& nums){
        if (nums.size() == 1){
            return nums[0];
        }

        if (nums.size() > 0){
            int flat = (nums.size()&1) == 0;;
            int mind = nums.size()/2;

            return  (nums[mind]+nums[mind-flat])/2.0;
        }
        return 0.0;
    }
};



int main(int argc, const char * argv[]) {
    vector<int> num1 = {1,3};
    vector<int> num2 = {2};
    Solution s;
    auto num = s.findMedianSortedArrays(num1, num2);
    // insert code here...
    std::cout << num;
    return 0;
}
