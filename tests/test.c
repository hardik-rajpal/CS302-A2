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
    int a, b, i;
    a = 1;
    while(a<35){
        a = a*2;
    }
    if(a==2){
        b = a+1;
    }
    else{
        b = a+3;
    }
    printf("a: %d, b: %d\n",a,b);
    return 0;
}