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

void push_back(Node** head, int value)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }
    Node* p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }
    Node* new_node = new Node;
    p_node->next = new_node;
    new_node->value = value;
    new_node->next = NULL;
}

int unique(Node* head);

int main()
{
    Node* list = NULL;
    for (int j = 1; j <= 11; ++j) push_back(&list, j%9);
    print_list(list);
    cout << unique(list);
    return 0;
}

bool In(Node* head, int val)
{
    bool i = false;
    Node* p_node = head;
    if (p_node->value == val){
        i = true;
    }
    while(p_node->next != NULL){
        p_node = p_node->next;
        if (p_node->value == val){
            i = true;
            break;
        }
    }
    return i;
}

int unique(Node* head)
{
    if (head == NULL){
        return 0;
    }
    int u = 1;
    Node* p_node = head;
    Node* num_list = new Node;
    Node* num_node = num_list;
    num_node->value = p_node->value;
    num_node->next = NULL;
    while(p_node->next != NULL){
        p_node = p_node->next;
        if (not In(num_list, p_node->value)){
            Node* new_node = new Node;
            num_node->next = new_node;
            new_node->value = p_node->value;
            new_node->next = NULL;
            num_node = num_node->next;
            ++u;
        }
    }
    return u;
}
