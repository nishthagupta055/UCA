
#include <stdio.h>
#include <stdlib.h> 
#include <sys/time.h> 


void fill_arr(int arr[], int n, int type) {
    
    if(type == 1) {
       
        for(int i = 0; i < n; i++) {
            arr[i] = rand() % (n + 1);
        }    
    }else if(type == 2) {
        
        for(int i = 0; i < n; i++) {
            arr[i] = i * 10;
        }
    }else {
     
        for(int i = 0; i < n; i++) {
            arr[i] = (n - i - 1) * 10;
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubble_sort(int arr[], int n) {
    
    for(int i = 0; i < n - 1; i++) {
       int swap_done = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap_done = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        
        if(swap_done == 0) {
            break;
        }
    }
    
}


void run_tests(int n, int type) {
    
    int arr[n];
    
     fill_arr(arr, n, type);
    
   struct timeval start, end;
    
    gettimeofday(&start, NULL);
    
   bubble_sort(arr, n);
    
     gettimeofday(&end, NULL);
    
    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    
     printf("For n=%d ", n);
    if(type == 1) {
        printf("and random set\n");
    }else if(type == 2) {
        printf("and sorted set\n");
    }else {
        printf("and reverse sorted set\n");
    }
    printf("The elapsed time is %d seconds and %d micros\n", seconds, micros);
}

int main() {
    for(int i = 8; i <= 36; i += 4) {
        for(int type = 1; type <= 3; type++) {
            run_tests(i * 1000, type);
        }
        printf("\n");
    }
    
}