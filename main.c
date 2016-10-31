#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main(){
  struct stat buffer;
  int err = stat("file.txt", &buffer);
  if( err < 0){
    printf("Error message:[%s]\n", strerror(errno));
  }

  int counter = 0;
  long s = buffer.st_size;
  while( s > 1000 ){
    counter ++;
    s = s / 1000;
  }

  //Not most efficient, but I'll use if statements unless osmething better comes to mind
  char end[2];
  switch(counter) {
  case 0 :
    printf("Triggered Case 0\n");
    strcpy(end, "B");
    break;
  case 1 :
    printf("Triggered Case 1\n");
    strcpy(end, "KB");
    break;
  case 2 :
    printf("Triggered Case 2\n");
    strcpy(end, "MB");
    break;
  case 3 :
    printf("Triggered Case 3\n");
    strcpy(end, "GB");
    break;
  case 4:
    printf("Triggered Case 4\n");
    strcpy(end, "TB");
    break;
  }
  
  printf("File Size: [%d%s]\n", s, end );
  printf("Mode: [%o]\n", buffer.st_mode);
  printf("Time of Last Access: [%s]\n", ctime(&buffer.st_atim));

  char dirPerms[10];
  dirPerms[0] = S_ISDIR( buffer.st_mode) ? "d" : "-";
  dirPerms[1] = ( buffer.st_mode & S_IRUSR ) ? "r" : "-";
  dirPerms[2] = ( buffer.st_mode & S_IWUSR ) ? "w" : "-";
  dirPerms[3] = ( buffer.st_mode & S_IXUSR ) ? "x" : "-";
  dirPerms[4] = ( buffer.st_mode & S_IRGRP ) ? "r" : "-";
  dirPerms[5] = ( buffer.st_mode & S_IWGRP ) ? "w" : "-";
  dirPerms[6] = ( buffer.st_mode & S_IXGRP ) ? "x" : "-";
  dirPerms[7] = ( buffer.st_mode & S_IROTH ) ? "r" : "-";
  dirPerms[8] = ( buffer.st_mode & S_IWOTH ) ? "w" : "-";
  dirPerms[9] = ( buffer.st_mode & S_IXOTH ) ? "x" : "-";

  char str[100];
  strcpy(str, ctime(&buffer.st_atim) );
  strncpy( str, str, strlen(str) - 9);
  char newStr[100];
  int i =4;
  for(;i<strlen(str);i++){
    newStr[i-4] = str[i];
  }
  printf("%s %s %s %d %s\n", dirPerms, buffer.st_uid, buffer.st_gid, buffer.st_size, newStr );
  
  return 0;
}
