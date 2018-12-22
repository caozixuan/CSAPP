#include<stdlib.h> 
int main(){
int entity_1=rand();
void*entity_2;
void*entity_3;
void*entity_4;

struct entity_5 { } ; 
struct entity_6 { } ; 
struct entity_7 { } ; 
struct entity_8 { } ; 
struct entity_9 { } ; 
struct entity_10 { 
entity_11 entity_12 ; 
void * entity_2 , * entity_3 , * entity_4 ; 
} ; 
int entity_13 = 100 ; 
static entity_5 entity_14 [ entity_13 ] ; 
static entity_7 entity_15 [ entity_13 ] ; 
static entity_8 entity_16 [ entity_13 ] ; 
static entity_8 entity_17 [ entity_13 ] ; 
static entity_9 * entity_18 [ entity_13 ] ; 
struct entity_10 * entity_19 = malloc( sizeof( * entity_19 ) ) ; 
entity_19 -> entity_12 = entity_12 ( NULL) ; 
entity_19 -> entity_2 = rand();
entity_19 -> entity_3 = rand();
entity_19 -> entity_4 = rand();
pthread_mutex_lock( & entity_15 [ entity_1 ] ) ; 
entity_20 ( entity_18 [ entity_1 ] , entity_19 ) ; 
entity_21 [ entity_1 ] ++ ; 
pthread_cond_signal( & entity_16 [ entity_1 ] ) ;         // safe
pthread_mutex_unlock( & entity_15 [ entity_1 ] ) ; 
return 0
}