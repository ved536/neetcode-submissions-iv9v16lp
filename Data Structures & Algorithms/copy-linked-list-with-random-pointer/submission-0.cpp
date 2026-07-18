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
    Node* copyRandomList(Node* head) {
        if( head == NULL ){
            return NULL;
        }

        unordered_map< Node*, Node*>m;
        Node* newHead = new Node(head-> val);
        Node* oldtemp = head->next;
        Node* newtemp = newHead;
        m[head] = newHead;
        while( oldtemp != nullptr ){
            Node* Newcopy = new Node(oldtemp -> val);
            m[oldtemp] = Newcopy;
            newtemp ->next = Newcopy;
            oldtemp = oldtemp-> next;
            newtemp = newtemp->next;
        }
        oldtemp = head;
        newtemp = newHead;
        while( oldtemp != nullptr ){
            newtemp->random = m[oldtemp->random];
            newtemp = newtemp->next;
            oldtemp = oldtemp->next;
        }

        return newHead;
    }
};
