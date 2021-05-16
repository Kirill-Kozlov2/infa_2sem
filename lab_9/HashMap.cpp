#include <iostream>
#include <string>

struct Node
{
    int k;
    int v;
    bool l;
};

struct HashMap
{
    int k;
    int n_elem, size;
    Node** table;
    double r = 0.25;

    HashMap()
    {
        size = 10;
        table = new Node* [size];
        for (int j=0; j<size; ++j){
            table[j] = NULL;
        }
    }

    void add(int k, int v)
    {
        if (n_elem > r * size)
            reallocate();

        int h1 = hash(k, size-1);
        int h2 = hash(k, size+1);
        int j = 0;
        while (table[h1] != NULL && j < size){
            if (table[h1]->l = false) break;
            h1 = (h1 + h2) % size;
            ++j;
        }
        if (table[h1] == NULL){
            table[h1] = new Node;
        }
        table[h1]->k = k;
        table[h1]->v = v;
        table[h1]->l = true;
        ++n_elem;
    }

    ~HashMap()
    {
        for (int j = 0; j < size; ++j)
            if (table[j])
                delete table[j];
        delete[] table;
    }

    int get(int k)
    {
         int h1 = hash(k, size-1);
         int h2 = hash(k, size+1);
         for (int j=0; j<n_elem; ++j){
             if (table[h1]->k == k)
                return table[h1]->v;
             h1 = (h1 + h2) % size;
         }
         return -777777777;
    }

    void reallocate()
    {
        int old_size = size;
        size *= 2;
        Node** new_table = new Node* [size];
        for (int j = 0; j < size; ++j)
            new_table[j] = NULL;
        std::swap(table, new_table);
        for (int j = 0; j < old_size; ++j)
        {
            if (new_table[j] && new_table[j]->l)
                add(new_table[j]->k, new_table[j]->v);
        }
        for (int j = 0; j < old_size; ++j)
            if (new_table[j])
                delete new_table[j];
        delete[] new_table;
    }

    int pop(int k)
    {
         int h1 = hash(k, size-1);
         int h2 = hash(k, size+1);
         int elem = -777777777;
         for (int j=0; j<n_elem; ++j){
             if (table[h1]->k == k){
                 elem = table[h1]->v;
                 table[h1]->l = false;
                 --n_elem;
                 break;
             }
             h1 = (h1 + h2) % size;
         }
         return elem;
    }

    int hash(int a, int rand)
    {
        return (a * rand) % size;
    }
};

int main()
{
    HashMap D;
    D.add(12, 7);
    D.add(123, 3);
    std::cout << D.get(12) << '\n';
    std::cout << D.pop(12) << '\n';
    std::cout << D.get(123) << '\n';
    return 0;
}
