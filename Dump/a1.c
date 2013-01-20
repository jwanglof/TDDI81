#include <stdio.h>
#include <stdlib.h>

int main()
{
  int heltal = 1;
  float flyttal = 0.1;
  char tecken = 'c';
  char text[] = "abc\0";
  int array[] = {1,2,3,4,5};

  printf("heltal: value=%i, adress=%p\n",heltal,&heltal);
  printf("text: adress=%p value=",&text);
  printf("%i\n",sizeof(text)/sizeof(char));
  printf("%s\n",text);
  char* current = &text[0];
  int counter = 0;
  while(counter < (sizeof(text)/sizeof(char) - 1)){
    printf("%c\n",*current);
    current++;
    counter++;
  }
  /*for (int i = 0;i < sizeof(text)/(sizeof(char)-2);i++){
    printf("%s\n",text[i]);
    }*/

  for (int i = 0; i < (sizeof(array)/sizeof(int));i++){
    printf("%i",array[i]);
  }

  printf("\n");

  char wagg[5];
  getline(wagg,5);
}

void getline(char array[], int size) {
  int index = 0;
  while(index < size){
    char input = getchar();
    printf("%c\n",input);
    array[index] = input;
    index++;
  }
  array[index] = '\0';
  printf("YOOO:%s\n",array);
}
