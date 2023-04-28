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
    int a, b;
    a = 15;
    b = 10;
    if(a == b){
        printf("not fuck you\n");
    }
    else {
        printf("fuck you\n");
    }
    return 0;
}