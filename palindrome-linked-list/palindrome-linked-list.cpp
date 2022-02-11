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
    bool isPalindrome(ListNode* head) 
    {
        if (head->next==NULL) return true;
        int cnt=0;
        ListNode * temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        // cout<<"part1 "<<endl;
        int mid=ceil(cnt/2.0);

        temp=head;
        for (int i=1;i<=mid;i++)
        {
            temp=temp->next;
        }
        ListNode * res=NULL;
        ListNode * last=NULL;
        while(temp!=NULL)
        {
            if (res==NULL)
            {
                res= new ListNode(temp->val);
                last=res;
            }
            else
            {
                last->next=new ListNode(temp->val);
                last=last->next;
            }
            temp=temp->next;
        }
        // cout<<"part 2"<<endl;
        temp=res;
        ListNode * prev=NULL;
        while(temp!=NULL)
        {
            ListNode * nxt=temp->next;
            temp->next=prev;
            if (nxt==NULL)
            {
                break;
            }
            prev=temp;
            temp=nxt;
        }
        res=temp;
        // cout<<"part 3"<<endl;
        ListNode * back=res;
        ListNode * front=head;
        for (int i=0;i<cnt/2;i++)
        {
            if (back->val!=front->val)
            {
                return false;
            }
            back=back->next;
            front=front->next;
        }
        // cout<<"part 4"<<endl;
        return true;
    }
};