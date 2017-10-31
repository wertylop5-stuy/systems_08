#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

char* better_size(off_t size) {
	float more_info = (float)size;
	char *res = malloc(50*sizeof(char));
	
	if (size < 1024) {
		sprintf(res, "B: %lu", size);
		return res;
	}
	
	char counter = 0;
	while(more_info > 1024) {
		counter++;
		more_info /= 1024;
	}
	
	printf("counter: %d\n", counter);
	switch(counter) {
		case 0:
			sprintf(res, "B: %f", more_info);
		break;
		
		case 1:
			sprintf(res, "KB: %f", more_info);
		break;

		case 2:
			sprintf(res, "MB: %f", more_info);
		break;
	
		case 3:
			sprintf(res, "GB: %f", more_info);
		break;
	}
	return res;
}

int main() {
	struct stat sb;
	stat("main.c", &sb);
	printf("%s\n", better_size(sb.st_size));
}
