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
    ListNode * deletedup(ListNode * head)
    {
        if (head==NULL or head->next==NULL) return head;
        ListNode * temp=head->next;
        ListNode * prev1=head;
        if (temp->val==head->val)
        {
            while(temp!=NULL and temp->val==head->val)
            {
                if (temp->next==NULL)
                {
                    head=NULL;
                    return head;
                }
                temp=temp->next;
            }
            return deletedup(temp);
        }
        if (temp->next==NULL)
        {
            return head;
        }
        temp=head->next->next;
        prev1=head->next;
        ListNode * prev2=head;
        while(temp!=NULL)
        {
            // cout<<"temp is "<<temp<<" "<<" prev1 is "<<prev1<<endl;
            if (temp->val==prev1->val)
            {
                ListNode * ptr=temp;
                while(ptr!=NULL and ptr->val==prev1->val)
                {
                    if (ptr->next==NULL)
                    {
                        prev2->next=NULL;
                        return head;
                    }
                    ptr=ptr->next;
                }
                temp=ptr->next;
                prev2->next=ptr;
                prev1=ptr;
            }
            else
            {
                temp=temp->next;
                prev1=prev1->next;
                prev2=prev2->next;
            }
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) 
    {
        return deletedup(head);
    }
};