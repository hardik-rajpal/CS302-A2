struct person{
    int fnc;
    int lnc;
};
struct book
{
    int pages;
    int rating;
    int pg[10][5];
    int * rtptr;
    struct person author;
    struct person *authorptr;
};
int dostuff(int a, int b)
{
    a = a + b;
    return a;
}
int getint(){
    return 23;
}
int main()
{
    struct book sapiens, *bkptr;
    struct book myshlf[4][4];
    int a;
    return 0;
}