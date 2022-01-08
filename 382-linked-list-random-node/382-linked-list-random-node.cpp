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
    vector<int> nums;
    int flag=0;
    Solution(ListNode* head) 
    {
        ListNode * temp=head;
        
        while(temp!=NULL)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        for (auto i:nums)
        {
            cout<<i<<endl;
        }
    }
    
    int getRandom() 
    {
        if (flag==0)
        {
            srand(time(0));
            flag=1;
        }
        return nums[rand()%(nums.size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */