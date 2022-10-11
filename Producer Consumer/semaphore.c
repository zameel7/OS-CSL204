#include <stdio.h>

int x, full=0, empty=3, mutex=1;

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

void produce() {
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    mutex=signal(mutex);
    printf("\nProduced item %d\n", x);
}

void consume() {
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    x--;
    mutex=signal(mutex);
    printf("\nConsumed item %d\n", x);
}

int main() {
    printf("Implement Producer Consumer\n");
    int n=0;
    while(n != 3) {
        printf("1.Produce\n2.Consume\n3.Exit\n=> ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                if ((empty!= 0) && (mutex==1))
                {
                    produce();
                }
                else
                {
                    printf("\nAlready full!\n");
                }
                break;
            case 2:
                if ((full!= 0) && (mutex==1))
                {
                    consume();
                }
                else
                {
                    printf("\nAlready empty!\n");
                }
                break;
            case 3:
                break;
        }
    }
    return 0;
}