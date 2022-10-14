#include <iostream>

typedef struct node {
    int val;
    node* next;
}node;

class stack {
    public:
        // constructor
        stack() {
            this->size = 0;
            this->head = nullptr;
        }

        friend std::ostream& operator<< (std::ostream& out, stack s) {
            node* temp = s.head;
            out<<"----------"<<std::endl;
            while(temp) {
                out<<temp->val<<std::endl;
                temp = temp->next;
            }
            out<<"----------"<<std::endl;
            return out;
        }

        void push(int val) {
            node* temp = new node;
            temp->val = val;
            temp->next = this->head;
            this->head = temp;
            ++this->size;
        }

        int pop() {
            int val = this->head->val;
            std::cout<<"Popped "<<val<<std::endl;
            if(!this->head) {
                std::cout<<"Stack is Empty";
                return -1;
            }
            node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            --this->size;
            return val;
        }

        int getSize() {
            return this->size;
        }
    
    private:
        int size;
        node* head;
};

int main() {
    stack mystack;
    mystack.push(5);
    mystack.push(9);
    mystack.push(10);
    mystack.push(20);
    std::cout<<mystack;
    mystack.pop();
    std::cout<<mystack;
    std::cout<<"Number of elements in the Stack = "<<mystack.getSize();
    return 0;
}