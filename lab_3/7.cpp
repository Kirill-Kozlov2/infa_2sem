unsigned int count_total_mice_amount(Cat* cats, unsigned int n)
{
    unsigned int s = 0;
    for (int i = 0; i < n; ++i){
        s += cats[i].mice_caught;
    }
    return s;
}
