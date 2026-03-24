
// #include <stdio.h>

// int main() {
//     int a;
//     if (scanf("%d", &a) != 1) {
//         printf("Failed to read an integer!\n");
//         return 1;
//     }
//     printf("You entered: %d\n", a);
//     return 0;
// }



// # include <stdio.h>


// int main(){
//     int a,b;
//     scanf("%d", &a);
//     scanf("%d", b);
//     float c = a+b;
//     printf("%f", c);

// }




#include <stdio.h>

int main() {
    char first_name, last_name;
    int age;

    if (scanf(" %c", &first_name) != 1) return 1;
    if (scanf(" %c", &last_name) != 1) return 1;
    if (scanf("%d", &age) != 1) return 1;

    printf("First Name: %c\n", first_name);
    printf("Last Name: %c\n", last_name);
    printf("Age: %d\n", age);

    return 0;
}
