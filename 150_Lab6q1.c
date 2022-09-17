#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum = 0;
int csum = 0;
int diff = 0;
void *runner(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);

    pthread_join(tid, NULL);
    int upper = atoi(argv[1]);
    int i;
    if (upper > 0)
    {
        for (i = 0; i <= upper; i++)
        {
            msum += i;
        }
    }
    diff = csum - msum;
    printf("msum = %d   csum = %d\n", msum,csum);
    printf("diff = %d\n",diff);
    return 0;
}

void *runner(void *param)
{
    int upper = (atoi(param) * 2);
    int i;
    if (upper > 0)
    {
        for (i = 0; i <= upper; i++)
        {
            csum += i;
        }
        pthread_exit(0);
    }
}

//2 แบบ 1.แม่เสร็จก่อนลูกแล้วลูกยังไม่ทำทำให้มีค่าเป็นลบ 2.ลูกเสร็จก่อนแม่ทำให้มีค่าเป็นบวก
