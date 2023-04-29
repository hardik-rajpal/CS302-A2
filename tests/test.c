int abs(int x) {
    if(x<0){
        return -x;
    }
    else{
        return x;
    }
}

int main() {
    int y;
    y=abs(-4);
    printf("y: %d\n",y);
    return 0;
}