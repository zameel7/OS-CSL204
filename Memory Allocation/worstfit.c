#include <stdio.h>

typedef struct Details
{
    int id, size, alloc;
} details;


int main() {
    int pno, bno;
    details process[20], memory[20];
    printf("Enter the no. of processes: ");
    scanf("%d", &pno);
    printf("Enter process details\n");
    for (int i = 0; i < pno; i++)
    {
        printf("P[%d]: process size => ", i+1);
        scanf("%d", &process[i].size);
        process[i].alloc = 0;
        process[i].id = i;
    }
    printf("Enter the no. of memory blocks: ");
    scanf("%d", &bno);
    printf("Enter memory block details\n");
    for (int i = 0; i < bno; i++)
    {
        printf("B[%d]: block size => ", i+1);
        scanf("%d", &memory[i].size);
        memory[i].alloc = 0;
        memory[i].id = i;
    }
    for (int i = 0; i < bno; i++)
    {
        for (int j = 0; j < bno-i-1; j++)
        {
            if (memory[j].size < memory[j+1].size)
            {
                int temp, temp1;
                temp = memory[j].size;
                temp1 = memory[j].id;
                memory[j].size = memory[j+1].size;
                memory[j].id = memory[j+1].id;
                memory[j+1].size = temp;
                memory[j+1].id = temp1;
            }
        }
    }
    printf("Process ID\tProcess size\tBlock ID\tBlock Size\n");
    for (int i = 0; i < pno; i++)
    {
        for (int j = 0; j < bno; j++)
        {
            if ((process[i].size <= memory[j].size) && (memory[j].alloc == 0))
            {
                printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].id+1, process[i].size, memory[j].id+1, memory[j].size);
                memory[j].alloc = 1;
                process[i].alloc = 1;
                break;
            }
        }
        if (process[i].alloc == 0)
        {
            printf("%d\t\t%d\t\tNot Allocated\n", process[i].id+1, process[i].size);
        }
    }
}