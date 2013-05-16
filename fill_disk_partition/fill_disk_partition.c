/*
 * FILENAME: fill_disk_partition.c
 * DESCRIBE: Fill the disk
 * DATE: 2013-05-15
 * AUTHOR: wokaokeji
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (1<<20)
char data[MAX_SIZE];
int main()
{

	FILE *fp = fopen("zzzz.zzzz", "a+");
	if (NULL == fp)
	{
		printf("ERROR IN fopen()");
		system("pause");
		return -1;
	}
	memset(data, 0x55, MAX_SIZE);
	unsigned size = MAX_SIZE, ret;
	unsigned long long count = 0;
	printf("sizeof(count)=%u\n", sizeof(count));
	while (1)
	{
        ret = fwrite(&data, size, 1, fp);
        if (0 < ret)
        {
            count += size;
            if ( count % (1024*1024*64) == 0)
                printf("Writen %f MB\n", (float)count/(1<<20));
            if ( 1 != ret)
            {
                printf("End?\n");
                system("pause");
                return -1;
            }
        }
        else
        {
            printf("Writen %lu Byte\n", count);
            size >>= 1;
            if (0 == size)
            {
                printf("ERROR in fwrite\n");
                system("pause");
                return -1;
            }
            else
            {
                printf("Change size to %u\n", size);
            }
        }
	}
	fclose(fp);
	return 0;
}
