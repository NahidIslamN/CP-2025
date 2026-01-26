# include <stdio.h>

int main(){
    int a,b,c,sum;
    scanf("%d %d %d", &a, &b, &c);
    sum = a+b+c;
    printf("%d",sum);

    int a,b,c;
    scanf("%d %d", &a,&b);
    c = a-b;
    printf("%d", c);

    // same as * and /
    long long int a,b,c;
    scanf("%lld %lld", &a,&b);
    // printf("%d %d", a,b);
    c = a%b;
    printf("%d", c);

    


    return 0;
}