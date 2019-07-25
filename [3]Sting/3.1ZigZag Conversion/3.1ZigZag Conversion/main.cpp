//
//  main.cpp
//  3.1ZigZag Conversion
//
//  Created by 林海生 on 2019/7/25.
//  Copyright © 2019 林海生. All rights reserved.
//
//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

//比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

//    P   I     N
//    A  L S   I G
//    Y A   H R
//    P      I


//    P    H
//    A   S I
//    Y  I   R
//    P L     I  G
//    A         N

//    P      R         H
//    A     I I       G
//    Y    H   N     E
//    P   S     G   D
//    A I        A C
//    L           B

// 第一排和最后排都是完整的加上((总深度-1)*2)；
// 中间几排要面对2种情况。例:
//      P    H
// *->  A   S I        *-> 这一排从 A 到 S 再从 S 到 I 分为两种 第一种种是：
//      Y  I   R        (当前位置+(总深度-当前深度-1)*2;如  1+(5-1-1)*2 = 7【s[7]为S】
//      P L     I  G    第二种为 (当前位置+深度*2)   第一种的时候  7+1*2 = 9【s[9]为I】
//      A         N


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0 || numRows == 1){
            return s;
        }
        string newS;

        for (int i = 0; i < numRows;i++){
            if (i == 0 || i == numRows-1){
                int k = i;
                while (k <s.length()) {
                    newS.push_back(s[k]);
                    k += ((numRows-1)*2);
                }
            }else{
                int j = i;
                while (j < s.length()) {
                    newS.push_back(s[j]);
                    j += (numRows - i - 1)*2;
                    if (j <s.length()){
                        newS.push_back(s[j]);
                        j += (i*2);
                    }
                }
            }
        }
        return newS;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 4);
    return 0;

}
