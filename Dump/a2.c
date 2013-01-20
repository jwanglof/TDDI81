#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  printf("argc=%i\n",argc);
  if (argc > 1) {
    int total = 0;
    for(int i=0;i<argc;i++){
      for(int x=0;x<strlen(argv[i]);x++) {
        printf("%c",*(argv[i]+x));
      }
      total += strlen(argv[i]);
      printf("%*i\n",20-strlen(argv[i]),strlen(argv[i]));
    }
    printf("Total length%8i\n",total);
    printf("Average length%6.2f\n",(float)(total/argc));
    return total;
  }
}
