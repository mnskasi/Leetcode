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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode * start=head;
        for (int i=1;i<k;i++)
        {
            start=start->next;
        }
        ListNode * temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        ListNode * last=head;
        for (int i=0;i<(cnt-k);i++)
        {
            last=last->next;
        }
        int data=start->val;
        start->val=last->val;
        last->val=data;
        return head;
    }
};