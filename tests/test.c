/*
struct pair {
    int x;
    int y;
};

int main() {
    struct pair p;
    struct pair q;
    q.x = 10;
    q.y = 20;
    p = *(&q);
    printf("p.x = %d, p.y = %d\n", p.x, p.y);
    return 0;
}
*/

void foo(int a, int b, int c) {
    printf("a = %d, b = %d, c = %d", a, b, c);
    return;
}

int main() {
    int a, b, c;
    a = 3;
    b = 23;
    c = 111;

    foo(a,b,c);
    return 0;
}