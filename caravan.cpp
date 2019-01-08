/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include "pack_animal.h"
#include "general.h"
#include <stdlib.h>

typedef struct Node* node;
struct Node{
  PackAnimal animal;
  node next;
};

struct CaravanImplementation{
  node head;
  int length;
};

Caravan new_caravan()
{
    Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
    caravan->head = 0;
    caravan->length = 0;
    return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal != 0) {
    node toAdd = (node)malloc(sizeof(struct Node*));
    if (caravan->head == 0) {
      caravan->head = toAdd;
    }
    else{
      node current = caravan->head;
      while (current->next != 0) {
      current = current->next;
      current->next = toAdd;
      toAdd->next = 0;
      }
    }

  }
}


void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
}

int get_caravan_load(Caravan caravan)
{
  node current = caravan->head;
  int load = 0;
  while (current->next != 0) {
    load += get_load(current->animal);
    current = current->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  node current = caravan->head;
  while (current->next != 0) {
    unload (current->animal);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  node current = caravan->head;
  int pace = get_actual_speed(caravan->head->animal);
  while (current->next != 0) {
    if (pace > get_actual_speed(current->animal)) {
      pace = get_actual_speed(current->animal);
    }
    current = current->next;
  }
  return pace;
}

void optimize_load(Caravan caravan){

}
