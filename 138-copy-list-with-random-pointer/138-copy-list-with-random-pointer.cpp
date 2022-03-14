/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if (head==NULL) return head;
        Node * temp=head->next;
        Node * new_list= new Node(head->val);
        Node * prev=new_list;
        while(temp!=NULL)
        {
            prev->next=new Node(temp->val);
            prev=prev->next;
            temp=temp->next;
        }
        Node * ptr1=head;
        Node * ptr2=new_list;
        while (ptr2!=NULL)
        {
            if (ptr1->random!=NULL)
            {
                Node * temp_ptr=new_list;
                Node * iter=head;
                while (iter!=ptr1->random)
                {
                    iter=iter->next;
                    temp_ptr=temp_ptr->next;
                }
                ptr2->random=temp_ptr;
            }
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        return new_list;
    }
};