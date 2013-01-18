#include "map.h"


void map_init(struct map* m)
{
  m->content = (value_t)malloc(sizeof(value_t)*MAP_SIZE);
}

key_t map_insert(struct map* m, value_t v)
{
  int counter = 0;
  while(*(m.content+counter) != NULL)
    counter++;
  
  if (counter == MAP_SIZE)
  {
    printf("MAP full!");
    PANIC();
  }

  *(m.content+counter) = v;
}

value_t map_find(struct map* m, key_t k)
{
  return *(m.content+k);
}

value_t map_remove(struct map* m, key_t k)
{
  value_t v = m.content+k;
  *(m.content+k) = NULL;
  return v;
}

void map_for_each(struct map* m, void (*exec)(key_t k, value_t v, int aux), int aux)
{
  for(int i=0;i<aux;i++)
    exec(i,v,aux);
}


void map_remove_if(struct map* m, bool (*cond)(key_t k, value_t v, int aux), int aux)
{

}