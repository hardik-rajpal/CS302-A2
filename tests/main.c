struct book
{
    int pages;
    int rating;
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
    int a, b, c, d;
    int f[10][10][10];
    struct book *sapiens;
    b = c && d;
    a = f[2][3][4]; /*f + 2*10*10*4 + 3*10*4 + 4*4*/
    c = dostuff(2,4);
    b = getint();
    printf("my mom loves me.");
    printf("and so does yours, %d/%d",100,50+50);
    for (d = 0; d == 6 && c!=b; d = d + 1)
    {
        while (b < a && b > c && d > c)
        {
            for (d = 0; d < 6; d = d + 1)
            {

                if (a < 1 || b < 1)
                {
                    a = b + c * d;
                }
                else
                {
                    a = b * b + d;
                }
            }
        }
    }

    c = c + d;
    return 0;
}