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
// 方法1：这个n*n的代码居然超过了96.8%，12ms
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* t1 = head;
        Node* ans = NULL;
        Node* t2;
        while(t1){
            if(ans==NULL)ans = t2 = new Node(t1->val);
            else{
                t2->next = new Node(t1->val);
                t2 = t2->next;
            }
            t1 = t1->next;
        }
        t1 = head;
        t2 = ans;
        while(t1){
            Node* t3 = head;
            Node* t4 = ans;
            while(t1->random != t3){
                t3 = t3->next;
                t4 = t4->next;
            }
            t2->random = t4;

            t1 = t1->next;
            t2 = t2->next;
        }
        return ans;
    }
};

// 方法2： O(n)，也是12ms
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
        
        Node* ans = NULL;
        Node* t1;
        Node* t2;
        t1 = head;
        while(t1){
            t2 = t1->next;
            t1->next = new Node(t1->val);
            t1->next->next = t2;
            t1 = t2;
        }
        t1 = head;
        while(t1){
            t2 = t1->next;
            if(t1->random)
                t2->random = t1->random->next;
            t1 = t2->next;
        }
        t1 = head;
        if(head)
            ans = head->next;
        while(t1){
            t2 = t1->next;
            t1->next = t2->next;
            t1 = t1->next;
            if(t1)
                t2->next = t1->next;
        }
        return ans;
    }
};