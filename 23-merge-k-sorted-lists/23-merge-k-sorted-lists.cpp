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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode * res=NULL;
        ListNode * end=NULL;
        while (true)
        {
            int flag=INT_MAX;
            int flagind=0;
            for (int i=0;i<lists.size();i++)
            {
                if (lists[i]!=NULL)
                {
                    if (lists[i]->val < flag)
                    {
                        flagind=i;
                        flag=lists[i]->val;
                    }
                }
            }
            if (flag==INT_MAX)
            {
                return res;
            }
            if (res==NULL)
            {
                res=new ListNode(flag);
                lists[flagind]=lists[flagind]->next;
                end=res;
            }
            else
            {
                ListNode * temp=new ListNode(flag);
                end->next=temp;
                end=end->next;
                lists[flagind]=lists[flagind]->next;
            }
        }
        return res;
    }
};