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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode * > ans(k,NULL);
        ListNode * temp=head;
        int ind=0;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        temp = head;
        for (int i=0;i<k;i++)
        {
            if (i < cnt%k)
            {
                ListNode* prev=NULL;
                for (int j=0;j<=(cnt/k);j++)
                {
                    if (j==0)
                    {
                        ans[i]= temp;
                        prev=temp;
                        temp=temp->next;
                    }
                    else
                    {
                        prev->next=temp;
                        temp=temp->next;
                        prev=prev->next;
                    }
                }
                if (prev!=NULL) prev->next=NULL;
            }
            else
            {
                ListNode * prev=NULL;
                for (int j=0;j< (cnt/k);j++)
                {
                    if (j==0)
                    {
                        ans[i]= temp;
                        prev=temp;
                        temp=temp->next;
                    }
                    else
                    {
                        prev->next=temp;
                        temp=temp->next;
                        prev=prev->next;
                    }
                }
                if (prev!=NULL) prev->next=NULL;
            }
        }
        return ans;
    }
};