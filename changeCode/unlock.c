#include<stdlib.h>
void bioCreateBackgroundJob(int type, void *arg1, void *arg2, void *arg3) {
    struct pthread_t{};
    struct pthread_mutex{};
    struct pthread_mutex_t{};
    struct pthread_cond_t{};
    struct list{};
    struct bio_job {
        time_t time;
        void *arg1, *arg2, *arg3;
    };
    int BIO_NUM_OPS=100;

    static pthread_t bio_threads[BIO_NUM_OPS];
    static pthread_mutex_t bio_mutex[BIO_NUM_OPS];
    static pthread_cond_t bio_newjob_cond[BIO_NUM_OPS];
    static pthread_cond_t bio_step_cond[BIO_NUM_OPS];
    static list *bio_jobs[BIO_NUM_OPS];

    struct bio_job *job = malloc(sizeof(*job));

    job->time = time(NULL);
    job->arg1 = arg1;
    job->arg2 = arg2;
    job->arg3 = arg3;
    pthread_mutex_lock(&bio_mutex[type]);
    listAddNodeTail(bio_jobs[type],job);
    bio_pending[type]++;
    pthread_cond_signal(&bio_newjob_cond[type]);
    pthread_mutex_unlock(&bio_mutex[type]);
}
