#include<stdio.h>


void print_problem(int *numbers, int target);



int main(int argc, char* argv[]){
    int numbers[6];
    int target;

    for(int x = 0; x<6; x++){
        printf("Please enter a number: ");
        scanf("%d", &numbers[x]);
    }
    printf("Please enter the target number: ");
    scanf("%d", &target);


    print_problem(numbers, target);

}


void print_problem(int *numbers, int target){
    printf("\t\t %d\n", target);
    for(int x = 0; x<6; x++){
        printf("  %d  ", numbers[x]);
    }
    printf("\n");
}
