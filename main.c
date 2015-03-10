#include <stdio.h>
#include <math.h>

#define _SIZE_ 4800

int primes[_SIZE_] = {2, 3, 5};

int binary_check(int n){
    int right=0, left=_SIZE_-1, middle;
    do {
        middle = (left + right) / 2;
        if (primes[middle] == n)
            return 1;
        if (primes[middle] > n)
            left = middle-1;
        if (primes[middle] < n)
            right = middle+1;
    } while (left >= right);
    return 0;
}

int find_next_prime(int a){
    int next_prime = primes[a-1]+2, i, sqrt_number, option=0;
    while (1) {
        sqrt_number = (int)sqrt(next_prime);
        option=0;
        for (i=0; primes[i]<=sqrt_number; i++)
            if (next_prime%primes[i] == 0) {
                next_prime += 2;
                option = 1;
                break;
            }
        
        if(option == 0) return next_prime;
    }
    
    return 0; /* 發生例外 */
}

int main(){
    int n, sqrt_number, i, is_prime;
    for (i=1000; i<_SIZE_; i++) {
        primes[i] = find_next_prime(i);
    }
    
    while (scanf("%d", &n) != EOF) {
        if (n==0) break;
        
        if (n == 1) {
            printf("1\n");
            continue;
        }
        
        if (n <= primes[_SIZE_ - 1]) {
            printf("%d\n", binary_check(n) ? 0 : 1);
            continue;
        }
        
        sqrt_number =sqrt(n);
        is_prime = 1;
        for (i=0; i<_SIZE_; i++) {
            if (sqrt_number < primes[i]) break;
            if (n%primes[i] == 0){
                is_prime = 0;
                break;
            }
        }
        printf("%d\n", is_prime ? 0 : 1);
    }
    
    return 0;
}
