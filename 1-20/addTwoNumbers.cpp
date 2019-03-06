/*
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
 *
示例:
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tempNum = 0;
        ListNode *l3 = new ListNode(0);
        ListNode *list = l3;
        while (l1 || l2){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            if (val1 + val2 + tempNum >= 10){
                l3->val = (val1 + val2 + tempNum) % 10;
                tempNum = 1;
            }
            else{
                 l3->val = val1 + val2;
                 l3->val = l3->val+tempNum;
                 tempNum = 0;
            }
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            if (l1 || l2){
                ListNode *tmp = new ListNode(0);
                l3->next = tmp;
                l3 = l3->next; 
            }
        }
        
        if(tempNum != 0){
            ListNode *tmp = new ListNode(0);
            l3->next = tmp;
            l3 = l3->next;
            l3->val = tempNum;
        }
        return list;
	}
};

int main(){
	Solution M ;

	ListNode *L1 = new ListNode(2);
	L1->next = new ListNode(4);
	L1->next->next = new ListNode(6);

	ListNode *L2 = new ListNode(5);
	L2->next = new ListNode(8);
	L2->next->next = new ListNode(3);

	ListNode *L3 = M.addTwoNumbers(L1,L2);

	while(L3){
		cout << "val: " << L3->val <<endl;
		L3 = L3->next;
	}

}
