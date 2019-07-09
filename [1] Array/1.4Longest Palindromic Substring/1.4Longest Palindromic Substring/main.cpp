//
//  main.cpp
//  1.4Longest Palindromic Substring
//
//  Created by 林海生 on 2019/7/9.
//  Copyright © 2019年 林海生. All rights reserved.
//

//1.4 Longest Palindromic Substring //最长回文子串
//这里使用的是中心扩展法


#include <iostream>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if(len==0||len==1){
            return s;
        }

        int start = 0;
        int end = 0;
        int mlen = 0;

        for (int i = 0 ; i <len; i++) {
            int len1 =  expendaroundcenter(s, i, i);
            int len2 =  expendaroundcenter(s, i, i+1);

            mlen = max(max(len1,len2),mlen); //比较历史最大值

            if (mlen > end - start + 1){ //end和start存放历史最大 大于则交换。
                start = i - (mlen-1)/2;
                end = i + mlen/2;
            }
        }
        return s.substr(start,mlen);
    }
private:
    int expendaroundcenter(string s,int left,int right)
    //计算以left和right为中心的回文串长度
    {
        int L = left;
        int R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.longestPalindrome("ssjsiajfa")<<endl;
    return 0;
}
