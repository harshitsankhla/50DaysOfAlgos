#include <iostream>

typedef struct node {
    int val;
    node* next;
}node;

class linkedlist {
    public:
        // constructor
        linkedlist() {
            this->size = 0;
            this->head = nullptr;
            this->last = nullptr;
        }

        // add a node to the list
        void add_node(int val) {
            node* temp = new node;
            temp->val = val;
            if (size==0) {
                head = temp;
            }
            else {
                last->next = temp;
            }
            last = temp;
            last->next = nullptr;
            size++;
        }

        void delete_node(int index) {
            if (!head) {
                std::cout<<"List is Empty !"<<std::endl;
                return;
            }
            if ((index >= size) || (index < 0)) {
                std::cout<<"Invalid Index for Node to Delete !"<<std::endl;
            }
            else {
                node* temp = head;
                if (index == 0) {
                    head = head->next;
                    delete temp;
                }
                else {
                    for (int i=0; i<index-1; i++) {
                        temp = temp->next;
                    }
                    node* remove = temp->next;
                    temp->next = remove->next;
                    delete remove;
                }
            --size;
            }
        }

        // print all elements
        void print_list() {
            node* temp = head;
            while(temp) {
                std::cout<<temp->val<<"->";
                temp = temp->next;
            }
            std::cout<<"end"<<std::endl;
        }

        // last becomes first
        void reverse_list() {
            if (!head) {
                std::cout<<"List is Empty !"<<std::endl;
                return;
            }
            last = head;
            node*prev = nullptr;
            node*next = nullptr;
            while(head->next) {
                next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            head->next = prev;
        }

        // return value of node in list specified by index starting from 0
        int get_node(int index) {
            if (!head) {
                std::cout<<"List is Empty !"<<std::endl;
                return -1;
            }
            if (index==0) {
                return head->val;
            }
            else if (index==(size-1)) {
                return last->val;
            }
            else if (index < 0 || index >= size) {
                std::cout<<"Invalid Index !";
                return -1;
            }
            else {
                node* temp = head;
                for (int i=0; i<index; i++) {
                    temp = temp->next;
                }
                return temp->val;
            }
        }

        int search_node(int val) {
            if (!head) {
                std::cout<<"List is Empty !"<<std::endl;
                return -1;
            }
            node* temp = head;
            for (int i=0; i<size; i++) {
                if (temp->val==val) {
                    std::cout<<"Value "<<val<<" found at index "<<i<<std::endl;
                    return i;
                }
                temp=temp->next;
            }
            std::cout<<"Value "<<val<<" does not exist in list !"<<std::endl;
            return -1;
        }

        // return the number of elements in the list
        int get_list_size() {
            return this->size;
        }

    private:
        int size;
        node* head;
        node* last;
};

// driver program
int main() {
    linkedlist mylist;
    mylist.add_node(1);
    mylist.add_node(2);
    mylist.add_node(3);
    mylist.add_node(4);
    mylist.print_list();
    std::cout<<"List size = "<<mylist.get_list_size()<<std::endl;
    mylist.delete_node(2);
    mylist.reverse_list();
    mylist.print_list();
    mylist.reverse_list();
    mylist.print_list();
    mylist.search_node(2);
    mylist.search_node(3);
    return 0;
}