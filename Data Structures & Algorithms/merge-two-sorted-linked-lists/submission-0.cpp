/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* dummyNode=new ListNode();
        ListNode* temp=dummyNode;
        while(temp1!=NULL && temp2!=NULL) {
            int val1=temp1->val, val2=temp2->val;
            if(val1<val2) {
                temp->next=temp1;
                temp1=temp1->next;
            }
            else {
                temp->next=temp2;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        if(temp1) {
            temp->next=temp1;
        }
        else {
            temp->next=temp2;
        }
        return dummyNode->next;
    }
};
