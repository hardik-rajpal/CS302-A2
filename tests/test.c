/*
need to update (1) ptrl (2) y= *x to transfer struct members
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

struct ghosala bird(int x, int y, int z) {
    struct ghosala g;
    g.eggs = x;
    g.koyal_koila.x = 2 * y;
    g.koyal_koila.y = 3 * z;
    return g;
}
void dostuff(){
    printf("doing stuff\n");
}
int main() {
    struct ghosala g;
    struct pair p;
    int a,b,c;
    dostuff();
    return 0;
}