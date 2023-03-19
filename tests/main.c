struct pair {
    int a, b;
};

int foo(int x) {
    return x * x;
}

int main() {
    int x;
    int y;
    struct pair p;
    x = 10;
    p = foo(x) + 1;
    return 0;
}