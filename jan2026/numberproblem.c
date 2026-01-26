# include <stdio.h>

int main(){
    
    int a;
    scanf("%d", &a);

    if (a>0){
        printf("Positive Numbers");
    }else if (a<0){
        printf("Negative nubers");
    }else{
        printf("Zero!");
    }
    

    return 0;
}