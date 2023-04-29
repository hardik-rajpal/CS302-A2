void foo(int *b){
    printf("at b: %d\n",*b);
}
int main(){
    int a[4][4];
    int *b;
    int i,j;
    /*for (i = 0; i < 4; i = i + 1) {
        for (j = 0; j < 4; j = j + 1) {
            a[i][j] = i + j;
        }
    }*/
    b = a[2];
    printf("at b: %d\n",*b);
    foo(a[2]);
    foo(b);
    return 0;
}
