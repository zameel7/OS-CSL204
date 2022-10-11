#include <stdio.h>
#include <stdlib.h>

void main() {
    int cpos, req[20], oreq[20], i, n, g, choice, pos=0, dist=0;
    printf("Enter the no. of requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for(i=0; i<n; i++) {
        scanf("%d", &req[i]);
        oreq[i] = req[i];
    }
    printf("Enter the current head position: ");
    scanf("%d", &cpos);
    req[n] = 199;
    req[n+1] = 0;
    req[n+2] = cpos;
    n = n+3;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(req[j] > req[j+1]) {
                int temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
    printf("\n||C SCAN||\n");
    int seek[20], count=0;
    while(req[pos]!=cpos) pos++;
    for(i=pos; i<n-1; i++) {
        int a=req[i];
        int b=req[i+1];
        dist += abs(a-b);
        printf("(%d - %d) ", a, b);
        printf("+");
        seek[count++] = req[i];
    }
    dist += 199;
    seek[count++] = 199;
    printf("(%d - %d) + ", 199, 0);
    for(i=0; i<pos-1; i++) {
        seek[count++] = req[i];
        dist += abs(req[i]-req[i+1]);
        printf("(%d - %d) ", req[i], req[i+1]);
        if(i!=(1)) printf("+");
    }
    printf("\nSeek order: ");
    for (int i = 0; i < count; i++)
    {
        printf("| %d  ", seek[i]);
    }
    printf("|");
    
    printf("\nTotal seek time = %d\n\n", dist);
}