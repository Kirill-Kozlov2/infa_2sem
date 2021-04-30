int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new)
{
    if (source == NULL){
        if (n_new == 0){
            return NULL;
        }
        else{
        int* new_array = new int[n_new];
        return new_array;
        }
    }
    else if (n_new == 0){
        delete [] source;
        return NULL;
    }
    else{
        unsigned int n = n_old;
        if (n_old > n_new){
            n = n_new;
        }
        int* new_array = new int[n_new];
        for (int i=0; i < n; ++i){
            new_array[i] = source[i];
        }
        delete [] source;
        return new_array;
    }
}
