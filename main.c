#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
  struct stat buffer;
  int err = stat("file.txt", &buffer);
  if( err < 0){
    printf("Error message:[%s]\n", strerror(errno));
  }
  printf("File Size: [%d]\n", buffer.st_size);
  printf("Mode: [%d]\n", buffer.st_mode);
  printf("Time of Last Access: [%s]\n", buffer.st_atim);
  return 0;
}
