class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int ptr1=0;
        int ptr2=0;
        stack<int>s;
        while(ptr1<pushed.size() or ptr2<popped.size())
        {
            
            if (s.size()==0)
            {
                s.push(pushed[ptr1]);
                ptr1++;
            }
            else
            {
                while(!s.empty() and s.top()==popped[ptr2])
                {
                    s.pop();
                    ptr2++;
                }
                if (ptr1!=pushed.size())
                {
                    s.push(pushed[ptr1++]);
                }
                else if (ptr2!=popped.size())
                {
                    return false;
                }
            }
        }
        return true;
    }
};