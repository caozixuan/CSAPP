#include<stdlib.h>
unsigned long long bioPendingJobsOfType(int type) {
    struct pthread_mutex_t{};
    int BIO_NUM_OPS = 100;
    static pthread_mutex_t bio_mutex[BIO_NUM_OPS];
    unsigned long long val;
    pthread_mutex_lock(&bio_mutex[type]);
    val = bio_pending[type];
    pthread_mutex_unlock(&bio_mutex[type]);
    return val;
}
