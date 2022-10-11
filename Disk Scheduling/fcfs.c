#include <stdio.h>
#include <stdlib.h>

void main() {
    int cpos, oreq[20], n;
    printf("Enter the no. of requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &oreq[i]);
    }
    printf("Enter the current head position: ");
    scanf("%d", &cpos);
    int dist=0, a, b, seek[20], count=0;
    printf("\n||FCFS||\n");
    for(int i = 0; i<n; i++) {
        if(i==0) {
            a = cpos;
            b = oreq[i];
        }
        else {
            a = oreq[i-1];
            b = oreq[i];
        }
        seek[count++] = a;
        dist += abs(a-b);
        printf("(%d - %d) ", a, b);
        if(i!=(n-1)) printf("+");
    }
    seek[count++] = b;
    printf("\nSeek order: ");
    for (int i = 0; i < count; i++)
    {
        printf("| %d ", seek[i]);
    }
    printf("|");
    printf("\nTotal seek time = %d\n\n", dist);
}