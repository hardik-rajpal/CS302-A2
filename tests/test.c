struct pair {
    int x;
    int y;
};

int main() {
    struct pair p;
    p.x = 10;
    p.y = 20;
    printf("p.x = %d, p.y = %d\n", p.x, p.y);
    return 0;
}