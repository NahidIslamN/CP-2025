# include <stdio.h>

int main(){
    
    int a,b,c;
    scanf ("%d %d %d", &a, &b, &c);

    if (a>b && a>c){
        printf("A is largest");
    } else if (b>a && b>c){
        printf("B is largest!");
    }else if (c>a && c>b){
        printf("C is largest");
    }else{
        printf("three are equal!");
    }
    
    

    return 0;
}