class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node* temp = head;
        while(temp){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        temp = head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* ans = dummy;

        temp = head;
        while(temp){

            ans->next = temp->next;
            ans = ans->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};

