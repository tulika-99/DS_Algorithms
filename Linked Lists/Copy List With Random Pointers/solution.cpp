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

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;

        // Adding new Nodes for Copying
        Node *temp = head;
        while (temp)
        {
            Node *next = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = next;
            temp = temp->next->next;
        }
        Node *temp1 = head;
        Node *newHead = head->next;
        // MArking the Random Pointers
        while (temp1)
        {
            if (temp1->random)
                temp1->next->random = temp1->random->next;
            temp1 = temp1->next->next;
        }

        temp = newHead;
        temp1 = head;
        // Separate the old nodes
        while (temp->next)
        {
            temp1->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp1->next = NULL;
        temp = newHead;
        temp1 = head;
        return newHead;
    }
};