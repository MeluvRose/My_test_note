#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LENGTH 128

int main()
{
	/*
	FILE	*p_file;
	static char	str[64];

	p_file = fopen("tips.txt", "rt");
	if (p_file != NULL)
	{
		if (fgets(str, 64, p_file) != 0)
			printf("%s\n", str);
		else
			printf("파일에서 문자열을 읽을 수 없습니다.\n");
		fclose(p_file);
	}
	*/

	int line_count = 0;
	char buffer[MAX_LENGTH];
	FILE *p_file = NULL;

	p_file = fopen("data.txt", "rt");
	if(p_file != NULL)
	{
		printf("data.txt 파일의 내용은 다음과 같습니다.\n\n");
		while (fgets(buffer, MAX_LENGTH, p_file) != 0)
		{
			line_count++;
			printf("[%d]번째 줄 : %s", line_count, buffer);
		}
		fclose(p_file);
		printf("\n\n");
	}
	return 0;
}
