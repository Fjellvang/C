#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	// test
	FILE* files[argc];
	//test af buffer
	char buffer[argc][100];

	for (int i = 1; i < argc; ++i)
	{
		// Open files
		files[i] = fopen(argv[i], "r");
		if (!files[i])
		{
			// If files doesnt exist, terminate with failure
			perror("fopen_failed");
			return EXIT_FAILURE;
		}
		
	}

	printf("Files successfully read. trying to print.\n");
	
	// Print to buffer
	// i starting at 1 because of argc counding filename as argument
	for (int i = 1; i < argc; ++i)
	{
		fread(buffer[i-1], 1, sizeof(files[i]), files[i]);
	}
	//fread(buffer[0], 1, sizeof(files[1]), files[1]);
	
	
	printf("Trying to print file\n");
	for (int j = 0; j < argc-1; ++j)
	{	
		for (int i = 0; i < strlen(buffer[j]); ++i)
		{
			printf("%d\n", buffer[j][i]);
		}
		printf("Printing Next file.\n");
	}
	


	//printf("%s\n", argv[1]);
	//File* logfile = fopen()
	return 0;
}