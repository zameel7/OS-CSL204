#include <stdio.h>

typedef struct RESOURCE {
    int a, b, c;
} resource;

void read();
void calc();
void disp();

int n, safeSequence[10], flag[10];
resource max[10], alloc[10], need[10], available[1];

int main() {
    printf("Enter no. of process: ");
    scanf("%d", &n);
    read();
    disp();
    calc();
    printf("Safe sequence: ");
    for(int i=0; i<n; i++) {
        printf("P[%d]  ", safeSequence[i]);
    }
    printf("\n");
}

void read(){
    int i;
    printf("Enter resource details of Max resources:\nA  B  C\n");
    for(i=0; i<n; i++) {
        scanf("%d%d%d", &max[i].a, &max[i].b, &max[i].c);
        flag[i] = 1;
    }
    printf("Enter resource details of allocated resources:\nA  B  C\n");
    for(i=0; i<n; i++) {
        scanf("%d%d%d", &alloc[i].a, &alloc[i].b, &alloc[i].c);
    }
    for(i=0; i<n; i++) {
        need[i].a = max[i].a - alloc[i].a;
        need[i].b = max[i].b - alloc[i].b;
        need[i].c = max[i].c - alloc[i].c;
    }

    printf("Enter the available resources:\nA  B  C\n");
    scanf("%d%d%d", &available[0].a, &available[0].b, &available[0].c);
}

void disp() {
    printf(" MAX    ALLOC   NEED\nA B C   A B C   A B C\n");
    for(int i=0; i<n; i++) {
        printf("%d %d %d   %d %d %d   %d %d %d\n", max[i].a, max[i].b,max[i].c,alloc[i].a,alloc[i].b,alloc[i].c,need[i].a,need[i].b,need[i].c);
    }
    printf("\nAVAILABLE: %d %d %d\n", available[0].a, available[0].b, available[0].c);
}

void calc() {
    int count = 0, i = 0;
    while(count != n) {
        if(available[0].a >= need[i].a && available[0].b >= need[i].b && available[0].c >= need[i].c && flag[i] == 1) {
            safeSequence[count] = i;
            count++;
            flag[i] = 0;
            available[0].a += alloc[i].a;
            available[0].b += alloc[i].b;
            available[0].c += alloc[i].c;
        }
        i = (i+1)%n;
    }
}