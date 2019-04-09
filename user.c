#include "user.h"
#include "menu.h"


void list(LOGIN* userlist[],int count){
   	#ifdef DEBUG_MODE
	printf("debugging");
	#endif
	printf("User list(id/password)");
	for(int i=0;i<count;i++)
		printf("\n[%d] %s / %s",i+1,userlist[i]->id,userlist[i]->password);
}

int load_file(LOGIN* list[], char* filename){
  int count=0;
  int yn;
  if(NULL==fopen(filename,"r"))
   {
	while(1){
 	printf("%s file not exist! make anyway? (Yes 1, No 2) >>", filename);
	scanf("%d",&yn);
	getchar();
	if(yn==1){
	  return count;
	  }
	else if(yn==2)
	  {printf("exit the program\n");
	   return -1;
	  }
	}
   }
		
  else{
  FILE *datafile = fopen(filename, "r");
  while(!feof(datafile)){
    list[count]=(LOGIN*)malloc(sizeof(LOGIN));
    if(EOF==fscanf(datafile,"%s %s",list[count]->id,list[count]->password))
    	{free(list[count]); count--;}
    count++;
  }
  
  printf("%d records read!\n",count);\
  fclose(datafile);
  return count;
  }
}

void join(LOGIN* list[], int* count){
  char id[20], pass[20];
  while(1){
    printf("Enter new user id >> ");
    scanf("%s", id);getchar();
    int dup=0;
    for(int i=0;i<*count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!");
    }
    else{
      printf("Enter password >> ");
      scanf("%s", pass);getchar();
      list[*count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[*count]->id, id);
      strcpy(list[*count]->password, pass);
      printf("New user added!");
      (*count)++;	
      break;
    }
  }
}

int login(LOGIN* list[], int count){
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  getchar();
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("No such user!!");
    return 0;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    getchar();
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!", id);
      return 1;
    }
    else{
      printf("Password incorrect!!");
      return 0;
    }
  }
  
}

void logout(int* is_login){
  *is_login = 0;
  printf("Bye!!");
}

void save_file(LOGIN* list[], int count, char* filename){
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%d records saved to %s!\n",count, filename);
  fclose(datafile);
}
