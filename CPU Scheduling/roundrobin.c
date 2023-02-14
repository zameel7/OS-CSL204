#include <stdio.h>

typedef struct PROCESS {
    int id, bt, at, rt;
} process;

process p[10], t[1];

int main() {
    int n, time, count, TQ, flag=0;
    int wt=0, tt=0;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    int remain = n;
    printf("Enter the process details: \n");
    for(int i = 0; i < n; i++) {
        p[i].id = i;
        printf("P[%d] => BT, AT: ", i+1);
        scanf("%d%d", &p[i].bt, &p[i].at);
        p[i].rt = p[i].bt;
    }
    printf("\nEnter TQ: ");
    scanf("%d", &TQ);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                t[1] = p[j];
                p[j] = p[j+1];
                p[j+1] = t[1];
            }
        }
    }
    printf("\nID\tTT\tWT\n");
    for(time=0, count=0; remain!=0;) {
        if(p[count].rt<=TQ && p[count].rt>0) {
            time += p[count].rt;
            p[count].rt = 0;
            flag = 1;
        }
        else if (p[count].rt>0)
        {
            p[count].rt -= TQ;
            time += TQ;
        }
        if (p[count].rt == 0 && flag == 1) 
        {
            printf("%d\t%d\t%d\n", p[count].id, time-p[count].at, time-p[count].at-p[count].bt);
            remain--;
            wt += time-p[count].at-p[count].bt;
            tt += time-p[count].at;
            flag = 0;
        }
        if ((count == n-1) || (p[count+1].at > time))
        {
            count = 0;
        }
        else if (p[count+1].at <= time)
        {
            count += 1;
        }
    }
    printf("\nAvg WT: %f\nAvg TT: %f\n", (float)wt/(float)n, (float)tt/(float)n);
    return 0;
}