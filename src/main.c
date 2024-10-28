#include<stdio.h>
#include<stdlib.h>

void print_problem(int *numbers, int target);
int lowest_index(int* A, int n);
void target_backwards_division(int* numbers, int n, int target);
int* new_numbers(int* numbers, int n, int k);
int* divisibility_matrix(int* numbers, const int n, int target);

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
    target_backwards_division(numbers, 6, target);

}


void print_problem(int *numbers, int target){
    printf("\n----------------------------------------------\n");
    printf("|                   [%3d]                    |\n", target);
    printf("|  ");
    for(int x = 0; x<6; x++){
        printf("[%2d]   ", numbers[x]);
    }
    printf("|\n");
    printf("----------------------------------------------\n\n");

}

int lowest_index(int* A, int n){
    int lowest_index = 0;
    if(n <= 0){
        return -1;
    }

    for(int x = 0; x<n; x++){
        if(A[x] == 0){
            continue;
        }
        else if(A[x] < A[lowest_index]){
            lowest_index = x;
        }
    }

    return lowest_index;
}


int* divisibility_matrix(int* numbers, const int n, int target){
    int* divisible = malloc(sizeof(int) * n);

    for(int x = 0; x<n; x++){
        if(numbers[x] == 1){
            divisible[x] = 999;
            continue;
        }
        else if(target % numbers[x] == 0){
            divisible[x] = target / numbers[x];
            // printf("%d is %d x %d, ", target, numbers[x], (target / numbers[x]));
            // target_backwards_division(new_numbers, n-1, (target / numbers[x]));
            // printf("\n");

        }
        else{
            divisible[x] = 999;
        }
    }

    printf("\nDivisibility matrix: %d\n", target);
    for(int x = 0; x < n; x++){
        printf("[%3d]  ", numbers[x]);
    }
    printf("\n");    
    for(int x = 0; x < n; x++){
        printf("[%3d]  ", divisible[x]);
    }
    printf("\n");


    return divisible;
}


int* new_numbers(int* numbers, int n, int k){
    if(n == 1){
        printf("Cannot shrink further\n");
        return NULL;
    }

    int* new_numbers = malloc(sizeof(int) * (n-1));
    for(int y = 0; y < n-1; y++){
        if(y < k){
            new_numbers[y] = numbers[y];
        }
        else if (y >= k){
            new_numbers[y] = numbers[y+1];
        }
    }

    return new_numbers;
}


void target_backwards_division(int* numbers, const int n, int target){

    if(target == 0){
        printf("Solved!\n");
        return;
    }
    if(n == 1){
        if(target == numbers[0]){
            printf("Solved!\n");
        }
        else{
            printf("Not solved!\n");
        }
        return;
    }

    int* divisible = divisibility_matrix(numbers, n, target);

    int i = lowest_index(divisible, n);
    if(divisible[i] == 999){
        int new_divisor = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(x != y){
                    new_divisor = numbers[x] + numbers[y];
                    if(target % new_divisor == 0){
                        printf("%d is (%d + %d) x %d\n", target, numbers[x], numbers[y] , (target / new_divisor));
                    }
                }
            }
        }
        
        
    }


    int* new = new_numbers(numbers, n, i);
    target_backwards_division(new, n-1, divisible[i]);
    

}
