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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int cnt=1;
        ListNode * temp=head;
        while(temp->next!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        if (n==cnt)
        {
            head=head->next;
        }
        else if (n==1)
        {
            temp=head;
            while((temp->next)->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=NULL;
        }
        else
        {
            temp=head;
            for (int i=1;i<cnt-n;i++)
            {
                temp=temp->next;
            }
            temp->next=(temp->next)->next;
        }
        return head;
    }
};