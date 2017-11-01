#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void get_info(char * file_name) {
  struct stat file;
  if (stat(file_name, &file) == 0) {
    printf("file size: %lu\n", file.st_size);
    printf("mode: %d\n", file.st_mode);
    printf("time last accessed: %s\n", ctime(&file.st_atime));
  } else { //!
    printf("%d: %s\n", errno, strerror(errno)); 
  }
}

char* better_size(off_t size) {
	float more_info = (float)size;
	char *out = malloc(30*sizeof(char));
	
	if (size < 1024) {
		sprintf(out, "B: %lu", size);
		return out;
	}
	
	char counter = 0;
	while(more_info > 1024) {
		counter++;
		more_info /= 1024;
	}
	
	switch(counter) {
		case 0:
			sprintf(out, "B: %f", more_info);
		break;
		
		case 1:
			sprintf(out, "KB: %f", more_info);
		break;

		case 2:
			sprintf(out, "MB: %f", more_info);
		break;
	
		case 3:
			sprintf(out, "GB: %f", more_info);
		break;
	}
	
	return out;
}

int main() {
        get_info("main.c");
	
	struct stat sb;
	stat("main.c", &sb);
	printf("better size of main.c: %s\n", better_size(sb.st_size));
	
	stat("stat", &sb);
	printf("better size of exec: %s\n", better_size(sb.st_size));

	return 0;
}
