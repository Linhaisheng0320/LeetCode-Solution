//
//  main.cpp
//  1.2Longest Substring Without Repeating Characters
//
//  Created by 林海生 on 2019/3/1.
//  Copyright © 2019年 林海生. All rights reserved.
//

//Given a string, find the length of the longest substring without repeating characters.


//Question：Longest Substring Without Repeating Characters
//
//Example 1:
//
//Input: "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//
//Input: "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//
//Input: "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

//思路：
//1.记录最长度【最后输出】
//2.记录开始位置【用于计算长度 以及当出现相同字母时用于重新定位】
//3.创建容器用于存放已经访问过的字母

#include "string"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int has[256] = {0}; //所有符号总共256
        //1和0不用计算
        if (s.length() == 0){
            return 0;
        }
        if (s.length() == 1){
            return 1;
        }

        int res = 0;
        int left = 0; //记录左边位置

        for (int i = 0; i < s.length(); i++) {
            //数组种为0代表没有遇到过,出现has有数子但是小于left代表左侧起始已经超过这个字母。
            if (has[s[i]] == 0 || has[s[i]] < left){
                res = max(res,  i-left+1); //用当前和历史最大做比较【当前位置减去left为最大值】
            }else{  //有重复的
                left = has[s[i]]; //取重复字母的下个位置为left
            }
            has[s[i]] = i+1; //记录下一个位置起点
        }


        return res;
    }
};

#include <iostream>

int main(int argc, const char * argv[]) {
    string s = "abadcca";
    Solution so;
    cout << so.lengthOfLongestSubstring(s) << endl;

    return 0;
}
