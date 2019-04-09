#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  char*  menu_id;
  
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
 
  #ifdef DEBUG_MODE
	printf("DEBUG>> datafile opened!\n");
  #endif
  
  int count = load_file(userlist, argv[1]);
  if(count==-1) return 0;
  printf("Welcome!");
  while(1){
    menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
   if(is_login==1)
	{
          if(!strcmp(menu_id,"logout"))
           {logout(&is_login);continue;}
          else
            printf("%s", menu_id);
         } 

   if(is_login==0){
	if(!strcmp(menu_id,"list")) list(userlist,count);
   	else if (!strcmp(menu_id,"join")) join(userlist,&count);
    	else if (!strcmp(menu_id,"login")) is_login = login(userlist, count);
    	else if (!strcmp(menu_id,"exit")) break;
	else if (!strcmp(menu_id, "\0")) ;
	else printf("no such command");
	}
  free(menu_id);
  }
  save_file(userlist, count, argv[1]);
  return 0;
}
