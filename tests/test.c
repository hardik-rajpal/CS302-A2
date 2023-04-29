int abs(int x) {
    if(x<0){
        return -x;
    }
    else{
        return x;
    }
}

int main() {
    int y,a;
    a = 4;
    y=abs(a);
    printf("y: %d, a:%d\n",y,a);
    return 0;
}