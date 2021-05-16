#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int value;
    Node* next;
};

void print_list(Node* head)
{
    Node* p_node = head;
    while(p_node != NULL){
        cout << p_node->value<<' ';
        p_node = p_node->next;
    }
    cout<<endl;
}

void push_back(Node ** head, int value)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }
    Node * p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }
    Node * new_node = new Node;
    p_node->next = new_node;
    new_node->value = value;
    new_node->next = NULL;
}

int pop(Node** head, int index);

int main()
{
    Node* list = NULL;
    for (int j = 1; j <= 1; ++j) push_back(&list, j);
    print_list(list);
    int r;
    cin >> r;
    cout << pop(&list, r) << endl;
    print_list(list);
    return 0;
}

int pop(Node** head, int index)
{
    int v;
    int k = 0;
    Node * p_node = *head;
    if (index == 0){
        *head = p_node->next;
        v = p_node->value;
        delete p_node;
        return v;
    }
    else{
        while (p_node->next != NULL and k < index-1) {
            p_node = p_node->next;
            ++k;
        }
        if (k == index-1){
            Node* pop_node = p_node->next;
            v = pop_node->value;
            p_node->next = (pop_node)->next;
            delete pop_node;
            return v;
        }
        else{
            return INT_MIN;
        }
    }
}
