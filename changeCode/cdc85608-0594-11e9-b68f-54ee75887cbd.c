#include<stdlib.h> 
int main(){
int entity_1=rand();

struct entity_2 { } ; 
int entity_3 = 100 ; 
static unsigned long long entity_4 [ entity_3 ] ; 
static entity_2 entity_5 [ entity_3 ] ; 
unsigned long long entity_6 ; 
pthread_mutex_lock( & entity_5 [ entity_1 ] ) ; 
entity_6 = entity_4 [ entity_1 ] ; 
if ( rand()){ 
pthread_cond_wait( & entity_7 [ entity_1 ] , & entity_5 [ entity_1 ] ) ;    // safe
entity_6 = entity_4 [ entity_1 ] ; 
} 
pthread_mutex_unlock( & entity_5 [ entity_1 ] ) ; 
return entity_6 ; 
return 0
}