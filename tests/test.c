struct pair {
    int x;
    int y;
};

int main() {
    struct pair a, b;
    a.x = 10;
    a.y = 12;

    b = a;

    printf("%d, %d", b.x, b.y);
}