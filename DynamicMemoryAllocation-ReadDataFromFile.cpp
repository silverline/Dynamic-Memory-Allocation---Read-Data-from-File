#include<stdio.h>
#include<stdlib.h>
/* Our structure */
void dump_buffer(void *buffer, int buffer_size);

void ReadFile(char *name)
{
	FILE *file;
	char *buffer;
	unsigned long fileLen;

	//Open file
	file = fopen(name, "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s", name);
		return;
	}
	
	//Get file length
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	//Allocate memory
	buffer=(char *)malloc(fileLen);

	if (!buffer)
	{
		fprintf(stderr, "Memory error!");
        fclose(file);
		return;
	}

	//Read file contents into buffer
	fread(buffer, fileLen, 1, file);
	
	//printf("%s\n",buffer);

	dump_buffer(buffer, fileLen);

	fclose(file);

	//Do what ever with buffer

	free(buffer);
}

void dump_buffer(void *buffer, int buffer_size)
{
  int i;

  for(i = 0;i < buffer_size;++i)
     printf("%02x", ((char *)buffer)[i]);
  printf("\n");
}

int main()
{
	ReadFile("C:\\Image\\asdf.txt");	
}
