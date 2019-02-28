//
//  main.cpp
//  2.1Add Two Numbers
//
//  Created by 林海生 on 2019/2/28.
//  Copyright © 2019年 林海生. All rights reserved.
//

//Question :Add Two Numbers
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example:
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.


//思路：
//创建一个ListNode用于接收
//创建一个进位的变量
//




struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *p = &head;
        int carry = 0; //进位数字

        while (l1 || l2 || carry) {

            int a = l1 ? l1->val : 0;//如果两个链表位数不同。则有以为null则取0
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry; //求和

            carry = sum/10; //余数 赋值给进位 用于下次循环相加
            p->next = new ListNode(sum%10); //将余数赋值给下一个数。
            p = p->next; //进入下一位
            l1 = l1 ? l1->next : l1; //防止越界。
            l2 = l2 ? l2->next : l2; //防止越界。

        }

        return head.next;
    }
};

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);


    ListNode *b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);

    Solution s;
    ListNode *result =  s.addTwoNumbers(a, b);

    return 0;
}
