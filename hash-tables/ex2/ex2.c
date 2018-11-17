#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  int i; 

  for(i = 0; i < length; i++){
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
  }
  
  i = 0; 
  char **destination = malloc(length * sizeof(char *)); 
  //neccessary to malloc data because if it isn't it will not save the data to the rout array. 
  
    while(i < length){
    if (i == 0){
      destination[i] = hash_table_retrieve(hash, "NONE");
      route[i] = destination[i];
    
    } else {
      destination[i] = hash_table_retrieve(hash, destination[i-1]);
      route[i] = destination[i];
    }
    
    i++;  //prevents infinte.
    
  }//end of while loop.

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}