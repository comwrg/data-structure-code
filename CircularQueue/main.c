#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

/*
 *
 * ================================================
 *
 *         initially an array of length 5
 *    front
 *     |
 *     v
 * +--------+---------+---------+--------+--------+
 * |   0    |    1    |    2    |    3   |    4   |
 * +--------+---------+---------+--------+--------+
 * |        |         |         |        |        |
 * +--------+---------+---------+--------+--------+
 *     ^
 *     \
 *    rear
 *
 * ================================================
 *
 *           push val0, val0, val2, val3
 *    front
 *     |
 *     v
 * +--------+---------+---------+--------+--------+
 * |   0    |    1    |    2    |    3   |    4   |
 * +--------+---------+---------+--------+--------+
 * |  val0  |  val1   |  val2   |  val3  |        |
 * +--------+---------+---------+--------+--------+
 *                                            ^
 *                                            \
 *                                           rear
 *
 * ================================================
 *
 *                  pop 3 itmes
 *                                 front
 *                                  |
 *                                  v
 * +--------+---------+---------+--------+--------+
 * |   0    |    1    |    2    |    3   |    4   |
 * +--------+---------+---------+--------+--------+
 * |        |         |         |  val3  |        |
 * +--------+---------+---------+--------+--------+
 *                                            ^
 *                                            \
 *                                           rear
 *
 * ================================================
 *
 *                 push val4, val5
 *
 *                                 front
 *                                  |
 *                                  v
 * +--------+---------+---------+--------+--------+
 * |   0    |    1    |    2    |    3   |    4   |
 * +--------+---------+---------+--------+--------+
 * |  val5  |         |         |  val3  |  val4  |
 * +--------+---------+---------+--------+--------+
 *               ^
 *               \
 *              rear
 *
 */

typedef struct Queue {
    int * pBase;
    int front;
    int rear;
    int len;
} QUEUE, * PQUEUE;

void init(int len, PQUEUE pQueue) {
    pQueue->pBase = (int *)malloc(sizeof(int) * len);
    pQueue->front = 0;
    pQueue->rear  = 0;
    pQueue->len   = len;
}

bool push(PQUEUE pQueue, int val) {
    if (pQueue->rear - pQueue->front == pQueue->len) {
        return false;
    }
    *(pQueue->pBase + pQueue->rear % pQueue->len) = val;
    pQueue->rear++;
    return true;
}

bool pop(PQUEUE pQueue, int * val) {
    if (pQueue->rear == pQueue->front) {
        return false;
    }
    *val = *(pQueue->pBase + pQueue->front % pQueue->len);
    pQueue->front++;
    return true;
}

void show(PQUEUE pQueue) {
    for (int i = pQueue->front; i < pQueue->rear; i++) {
        printf("%d ", pQueue->pBase[i % pQueue->len]);
    }
    printf("| %d, %d", pQueue->front, pQueue->rear);
    printf("\n");
}


#define LEN 10
int main(void) {
    QUEUE queue;
    init(LEN, &queue);
    for (int j = 0; j < 2; j++) {

        for (int i = 0; i < 10; i++) {
            printf("try push %d. ", i);
            bool b = push(&queue, i);
            if (b)
                printf("succeed.");
            else
                printf("failed.");
            printf("\n");
        }
        printf("\nshow: ");
        show(&queue);
        printf("\n");

        for (int i = 0; i < 9; i++) {
            printf("try pop. ");
            int r;
            bool b = pop(&queue, &r);
            if (b)
                printf("succeed. value is %d", r);
            else
                printf("failed.");
            printf("\n");
        }
        printf("\n");
        printf("show: ");
        show(&queue);
        printf("-------------\n");
    }

    return 0;
}
