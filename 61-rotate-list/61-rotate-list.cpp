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
    ListNode * rotate(ListNode * head)
    {
        if (head==NULL) return head;
        ListNode *temp=head;
        ListNode * prev=NULL;
        while(temp!=NULL)
        {
            ListNode * front=temp->next;
            temp->next=prev;
            if (front==NULL)
            {
                break;
            }
            prev=temp;
            temp=front;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head==NULL) return head;
        int len=0;
        ListNode * itr=head;
        while(itr!=NULL)
        {
            len++;
            itr=itr->next;
        }
        int d=k%len;
        d=len-d;
        if (d==0 or d==len)
        {
            return head;
        }
        ListNode *temp1=head;
        ListNode * temp2=head;
        for (int i=0;i<d;i++)
        {
            temp1=temp2;
            temp2=temp2->next;
            
        }
        temp1->next=NULL;
        ListNode *ptr1=rotate(head);
        ListNode * ptr2=rotate(temp2);
        ListNode * tempptr=ptr1;
        while(tempptr->next!=NULL)
        {
            tempptr=tempptr->next;
        }
        tempptr->next=ptr2;
        return rotate(ptr1);
    }
};