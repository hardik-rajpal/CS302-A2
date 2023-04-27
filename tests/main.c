struct person{
    int fnc;
    int lnc;
};
struct book
{
    int pages;
    int rating;
    int pg[10][5];
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
    int a[10][5];
    int **p,*q;
    a[3][2] = 45;
    p = a;//size of p = 4B
    printf("%p, %p\n",a,a+3);
    printf("%p, %p\n",p,p+3*5);
    q = *(p+3*5+2);
    printf("%d\n",q);
    return 0;
}