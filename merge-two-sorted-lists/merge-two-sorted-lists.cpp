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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode * temp1=list1;
        ListNode * temp2= list2;
        ListNode * res=NULL;
        ListNode * last=NULL;
        int data;
        while(temp1!=NULL && temp2!=NULL)
        {
            
            if (temp1-> val <= temp2->val)
            {
                data=temp1->val;
                temp1=temp1->next;
            }
            else
            {
                data=temp2->val;
                temp2=temp2->next;
            }
            if (res==NULL)
            {
                res=new ListNode(data);
                last=res;
            }
            else
            {
                last->next=new ListNode (data);
                last=last->next;
            }
        }
        while(temp1!=NULL)
        {
            data=temp1->val;
                temp1=temp1->next;
            if (res==NULL)
            {
                res=new ListNode(data);
                last=res;
            }
            else
            {
                last->next=new ListNode (data);
                last=last->next;
            }
        }
        while(temp2!=NULL)
        {
            data=temp2->val;
            temp2=temp2->next;
            if (res==NULL)
            {
                res=new ListNode(data);
                last=res;
            }
            else
            {
                last->next=new ListNode (data);
                last=last->next;
            }
        }
        return res;
    }
};