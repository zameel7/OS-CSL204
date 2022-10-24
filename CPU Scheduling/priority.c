#include <stdio.h>

typedef struct PROCESS
{
    int id, bt, wt, tt, ct, pr;
}process;


int main() {
    int n;
    float awt=0, att=0;
    process p[10];
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    printf("Process details: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: Burst time, Priority => ", i+1);
        scanf("%d%d", &p[i].bt, &p[i].pr);
        p[i].id = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (p[j].pr > p[j+1].pr)
            {
                int temp1 = p[j].bt;
                int temp2 = p[j].id;
                int temp3 = p[j].pr;
                p[j].bt = p[j+1].bt;
                p[j].id = p[j+1].id;
                p[j].pr = p[j+1].pr;
                p[j+1].bt = temp1;
                p[j+1].id = temp2;
                p[j+1].pr = temp3;
            }
        }
    }
    p[0].wt = 0;
    p[0].tt = p[0].bt;
    awt += p[0].wt;
    att += p[0].tt;
    for (int i = 1; i < n; i++)
    {
        p[i].tt = p[i-1].tt + p[i].bt;
        p[i].wt = p[i].tt - p[i].bt;
        awt += p[i].wt;
        att += p[i].tt;
    }
    printf("\nPID\tPRI\tBT\tWT\tTT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].id+1, p[i].pr, p[i].bt, p[i].wt, p[i].tt);
    }
    printf("Average waiting time: %f\n", (float)awt/n);
    printf("Average turnaround tme: %f\n", (float)att/n);
}