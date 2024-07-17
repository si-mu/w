#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int x[20],sf=0,count=0;

int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return FALSE;
    }
    return TRUE;
}

void nqueens(int k, int n) {
    int i, a;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (a = 1; a <= n; a++)
                    printf("%d\t", x[a]);
                printf("\n");
                sf=1;
                count++;
            } else {
                nqueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    printf("\nThe solution to the N-Queens problem is:\n");
    nqueens(1, n);
    if(!sf) printf("Doesnt exist\n");
    printf("No. of solutions: %d\n",count);
    return 0;
}

