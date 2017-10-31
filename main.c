#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

void get_info(char * file_name) {
  struct stat file;
  if (stat(file_name, &file) == 0) {
    printf("file size: %lu\n", file.st_size);
    printf("mode: %d\n", file.st_mode);
    printf("time last accessed: %s\n", ctime(&file.st_atime));
  }
}

int main() {
  get_info("main.c");
}
