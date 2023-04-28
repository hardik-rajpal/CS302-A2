/*
need to update (1) ptrl, which is *y = x and (2) y= *x to copy "struct" variables x and y
just reuse the loop from = expression.
struct pair {
    int x;
    int y;
};

struct ghosala {
    int eggs;
    struct pair koyal_koila;
};

struct ghosala bird(int x) {
    struct ghosala g;
    g.eggs = x;
    g.koyal_koila.x = 2 * x;
    g.koyal_koila.y = 3 * x;
    return g;
}

int main() {
    struct ghosala g;
    struct pair p;
    p.x = 12;
    p.y=34;
    g.eggs = 2;
    g.koyal_koila = p;
    printf("g.eggs: %d, g.kk.x: %d, g.kk.y: %d\n",g.eggs,g.koyal_koila.x,g.koyal_koila.y);
    return 0;
}
*/

struct pair {
    int x;
    int y;
};

struct ghosala {
    int eggs;
    struct pair koyal_koila;
};

int main() {
    struct pair *x[10][20];
    int i,j;
    struct pair cpy[10][20];

    x[0][0]= &cpy[0][0];
    x[0][0]->x= 1;
    for(j=0;j<20;j = j+1){
        x[0][j] = &cpy[0][j];
        x[0][j]->x = 1;
    }
    for(i=1;i<10;i = i+1){
        x[i][0] = &cpy[i][0];
        x[i][0]->x = x[i-1][0]->x+1;
        for(j=1;j<20;j = j+1){
            x[i][j] = &cpy[i][j];
            x[i][j]->x = x[i][j-1]->x+1;
        }
    }
    for(i=0;i<10;i = i+1){
        for(j=0;j<20;j = j+1){
            printf("%d, ",x[i][j]->x);
        }
        printf("\n");
    }
    return 0;
}