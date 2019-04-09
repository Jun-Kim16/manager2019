#include "menu.h"

char* ask_menu(int is_login){
  
  char* menu=malloc(sizeof(char)*30);
  if(is_login==1)
    printf("\n#");
  else
    printf("\n>");
  
  fgets(menu,sizeof(menu),stdin);
  menu[strlen(menu)-1]='\0';
#ifdef DEBUG_MODE
 printf("successed");
#endif
  return menu;
}
