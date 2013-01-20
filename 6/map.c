#include "map.h"
#include "stdio.h"

void map_init(struct map* m)
{
  for(int i=0;i<MAP_SIZE;i++)
    m->content[i] = NULL;
}

key_t map_insert(struct map* m, value_t v)
{
  int counter = 0;
  while(m->content[counter] != NULL)
    counter++;
  
  if (counter == MAP_SIZE)
    printf("MAP full!\n");
  
  m->content[counter] = v;
  return counter;
}

value_t map_find(struct map* m, key_t k)
{
  if (k >= MAP_SIZE || k < 0)
    return NULL;
  return m->content[k];
}

value_t map_remove(struct map* m, key_t k)
{
  if (k >= MAP_SIZE || k < 0)
    return NULL;
  
  value_t v = m->content[k];
  m->content[k] = NULL;
  return v;
}

void map_for_each(struct map* m, void (*exec)(key_t k, value_t v, int aux), int aux)
{
  for(int i=0;i<MAP_SIZE;i++)
  {
    if (m->content[i] != NULL)
      exec(i,m->content[i],aux);
  }
}


void map_remove_if(struct map* m, bool (*cond)(key_t k, value_t v, int aux), int aux)
{
  for(int i=0;i<aux;i++)
  {
    if (m->content[i] != NULL)
    {
      if (cond(i,m->content[i],aux))
        map_remove(m,i);
    }
  }
}
