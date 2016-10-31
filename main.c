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
  return 0;
}
