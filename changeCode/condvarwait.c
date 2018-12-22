#include<stdlib.h>
unsigned long long bioWaitStepOfType(int type) {
    struct pthread_mutex_t{};
    int BIO_NUM_OPS = 100;
    static unsigned long long bio_pending[BIO_NUM_OPS];
    static pthread_mutex_t bio_mutex[BIO_NUM_OPS];
    unsigned long long val;
    pthread_mutex_lock(&bio_mutex[type]);
    val = bio_pending[type];
    if (val != 0) {
        pthread_cond_wait(&bio_step_cond[type],&bio_mutex[type]);
        val = bio_pending[type];
    }
    pthread_mutex_unlock(&bio_mutex[type]);
    return val;
}
