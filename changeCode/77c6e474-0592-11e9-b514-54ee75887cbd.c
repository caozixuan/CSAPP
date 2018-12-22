#include<stdlib.h> 
int main(){
int entity_1=rand();

struct entity_2 { } ; 
int entity_3 = 100 ; 
static entity_2 entity_4 [ entity_3 ] ; 
unsigned long long entity_5 ; 
pthread_mutex_lock( & entity_4 [ entity_1 ] ) ; 
entity_5 = entity_6 [ entity_1 ] ;                            // safe
pthread_mutex_unlock( & entity_4 [ entity_1 ] ) ; 
return entity_5 ; 
return 0
}