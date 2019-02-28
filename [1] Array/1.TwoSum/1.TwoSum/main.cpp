//
//  main.cpp
//  1.TwoSum
//
//  Created by 林海生 on 2019/2/27.
//  Copyright © 2019年 林海生. All rights reserved.
//

//Question one:
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].


//思路：
//1.首先进行排序，
//2.然后创建两个指针，分别指向头和尾。
//3.当两个位置的合比target大的时候，尾部向前一位，这样合就变小了。
//  合比target小的时候，头部向前一位，这样合就变大了。直到找到对应的答案。

#include <iostream>
#include <vector>
#include <algorithm>
#include "unordered_map"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result;
        if (nums.size()  < 2) {
            return result;
        }

        vector<int> newNums(nums.begin(),nums.end());
        //排序
        sort(newNums.begin(), newNums.end());

        //两个指针指向头和尾部
        int front = 0;
        int back = newNums.size()-1;
        while (front < back) {
            int sum = (newNums[front] + newNums[back]);//求和
            if (sum > target){
                back--;
            }else if (sum < target){
                front++;
            }else{
                result.push_back(newNums[front]);
                result.push_back(newNums[back]);
                back--;
                front++;
            }
        }

        vector<int> pos;
        //将数据对比原数据找出对应的index。unordered_map用于过滤重复添加的index。例如【3,3】以免发生最后return为[0,0]而不是[0,1]。
        for (int i = 0; i < result.size(); i++ ) {
            for (int j = 0 ; j < nums.size(); j++) {
                if (nums[j] == result[i] && hash.find(j) == hash.end()){
                    pos.push_back(j);
                    hash[j] = nums[j];
                    break;
                }
            }
        }

        //通过异或快速交换位置。
        if (pos.size() > 1 &&pos[0]> pos[1]){
            pos[0] = pos[0] ^ pos[1];
            pos[1] = pos[0] ^ pos[1];
            pos[0] = pos[0] ^ pos[1];
        }

        return pos;
    }
};

int main(int argc, const char * argv[]) {
    Solution *s = new Solution;
    //调试例子一。
    vector<int> result;
    result.push_back(6);
    result.push_back(1);
    result.push_back(11);
    result.push_back(3);
    result.push_back(2);
    //调试例子二。
    //    vector<int> result;
    //    result.push_back(3);
    //    result.push_back(3);

    s->twoSum(result, 9);
    return 0;
}



