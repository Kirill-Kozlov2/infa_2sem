#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int v;
    Node* next;
};

void clear_list(Node** head);
void push_back(Node** head, int v);

void print_list(Node* head)
{
    Node* p_node = head;
     while(p_node != NULL){
        cout << p_node->v<<' ';
        p_node = p_node->next;
    }
    cout<<endl;
}

int main()
{
    Node* list = NULL;
    for (int j = 1; j <= 10; ++j) push_back(&list, j);
    print_list(list);
    clear_list(&list);
    return 0;
}

void push_back(Node ** head, int v)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->v = v;
        (*head)->next = NULL;
        return;
    }
    Node * p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }
    Node * new_node = new Node;
    p_node->next = new_node;
    new_node->v = v;
    new_node->next = NULL;
}

void clear_list(Node** head)
{
    if (*head != NULL){
        Node* new_head = (*head)->next;
        delete *head;
        *head  = new_head;
    }
}
