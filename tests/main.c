struct pair {
    int a;
    int b;
};

void bar() {
}

void foo(struct pair p, int q) {
    p.a = q;
}

int main() {
    struct pair p;
    p.a = 4;
    p.b = 10;
    foo(p, p);
    return 0;
}