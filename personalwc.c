#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main(int argc, char * argv[])
{
	int char_count ;
	int word_count ;
	int line_count ;
	char filename[80];
	FILE *p_f = NULL;
	 if (argc >= 3)
	{
	    int i=2;  //用来指定输入的第一个文件
	    while(argc>=3)
        {
        char_count=0,word_count=1,line_count=1;
		p_f = fopen(argv[i++], "r");//i++ 指向下一个文件
		if (p_f == NULL)
		{
			printf("找不到该文档！\n");
			printf("请按enter键继续....");
			getchar();
			exit(0);
		}
		while (1)
		{
			char ch;
			ch = fgetc(p_f);
			if (ch >= '!'&&ch <= '}')
			{
				char_count++;
            }
            else if (ch == ' ')
			{
				word_count++;
			}
            else if (ch == '\n')
			{
				line_count++;
				word_count++;
			}
			else if (ch = EOF)
			{
				break;
			}
		}

		if (strcmp(argv[1],"-c")==0)
		{
			printf("The no.%d file's char count is %d\n", i-2,char_count);
		}
		else if (strcmp(argv[1],"-w")==0)
		{
			printf("The no.%d file's word count is %d\n", i-2,word_count);
		}
		else if (strcmp(argv[1],"-l")==0)
		{
			printf("The no.%d file's line count is %d\n", i-2,line_count);
		}
        argc--;
        }
		fclose(p_f);
	}

    else{

        printf("输入格式有误！");
    }
}
