#include <stdio.h>

typedef struct PROCESS
{
    int id, bt, at, wt, tt, ct;
}process;


int main() {
    int n;
    float awt, att;
    process p[10];
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    printf("Process details: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]: Burst time, Arrival time => ", i+1);
        scanf("%d%d", &p[i].bt, &p[i].at);
        p[i].id = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (p[j].at > p[j+1].at)
            {
                int temp1 = p[j].at;
                int temp2 = p[j].bt;
                int temp3 = p[j].id;
                p[j].at = p[j+1].at;
                p[j].bt = p[j+1].bt;
                p[j].id = p[j+1].id;
                p[j+1].at = temp1;
                p[j+1].bt = temp2;
                p[j+1].id = temp3;
            }
        }
    }
    p[0].wt = 0;
    p[0].tt = p[0].bt+p[0].wt;
    p[0].ct = p[0].at+p[0].tt;
    for (int i = 1; i < n; i++)
    {
        p[i].ct = p[i-1].ct + p[i].bt;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
        awt += p[i].wt;
        att += p[i].tt;
    }
    printf("\nPID\tBT\tWT\tTT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].id+1, p[i].bt, p[i].wt, p[i].tt);
    }
}