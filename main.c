#include<stdio.h>
#include<sys/stat.h>

void better_size(off_t size) {
	float more_info = (float)size;
	
	if (size < 1024) {
		printf("B: %lu\n", size);
		return;
	}
	
	char counter = 0;
	while(more_info > 1024) {
		counter++;
		more_info /= 1024;
	}
	
	printf("counter: %d\n", counter);
	switch(counter) {
		case 0:
			printf("B: %f\n", more_info);
		break;
		
		case 1:
			printf("KB: %f\n", more_info);
		break;

		case 2:
			printf("MB: %f\n", more_info);
		break;
	
		case 3:
			printf("GB: %f\n", more_info);
		break;
	}
}

int main() {
	struct stat sb;
	stat("a.out", &sb);
	better_size(sb.st_size);
}
