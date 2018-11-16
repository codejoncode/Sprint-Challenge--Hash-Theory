#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

#include "ex1.h"
//https://repl.it/@codejoncode/UnlawfulTestyReference
Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  if (length < 2){
    return NULL; 
  }
  printf("Am I inside of this\n");
  HashTable *ht = create_hash_table(16);
  HashTable *ht2 = create_hash_table(16); 
  // key = weight    and the  value =  index in array 
  int key = 0; 
  int value = 0;
  int index_1, index_2, test_value_match; 
  struct Answer *returning;

  for (int weight = 0; weight< length; weight++){
    // printf("%d\n", weights[weight]);
    //create key and value 
    key = weights[weight];
    value = weight;  
    // printf("%d %d\n", key, value); 
    //place into hash table 
    hash_table_insert(ht, key, value); 
    value = limit - weights[weight];
    hash_table_insert(ht2, key, value); 
    //current value is the limit- weights[weight] should produce a positive value if its what we need
    test_value_match = hash_table_retrieve(ht2, value);
    if (test_value_match >= 0){
      index_1 = weight; 
      index_2 = hash_table_retrieve(ht, value); //gets index stored. 
      printf("Where do you fail?\n");
      
      returning->index_1 = index_1; 
      returning->index_2 = index_2;
      printf("Get here\n"); 
      destroy_hash_table(ht);
      destroy_hash_table(ht2);
      return returning;  

    } 

  }
  

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

