#include <string.h>
#include "header.h"

#define INITCAP 8 


char **read(FILE *fp, char **lines, int *lSize)
{
    char *buffer;
    int BUFSIZE = INITCAP;
    size_t  bsize = 1024;
    int l;
    buffer = malloc(bsize * sizeof(char));
    memcheck(buffer);
    while ((l = getline(&buffer, &bsize, fp)) != -1)
    {
        if((*lSize) == BUFSIZE)
        {
            BUFSIZE = BUFSIZE * 2;
            lines = realloc(lines, BUFSIZE * sizeof(char *));
            memcheck(lines);
        }
        lines[(*lSize)++] = buffer;
        buffer = malloc(bsize * sizeof(char));
        memcheck(buffer);

    }
    free(buffer);
    return lines;
}

void write(char **lines, int lSize)
{
    for (int i = 0; i < lSize; i++)
    {
        printf("%d ",lSize-i);
        int leng = strlen(lines[lSize-i-1]);
        if (!((leng == 2 && lines[lSize-i-1][leng-1] == '\r') || (leng == 1 && lines[lSize-i-1][leng-1] == '\n')))
        {
            for (int j = 0; j < leng; j++)
            {
                if (!((lines[lSize-i-1][leng-j-1] == '\n') || (lines[lSize-i-1][leng-j-1] == '\r')))
                {
                    printf("%c",lines[lSize-i-1][leng-j-1]);
                }   
            }
        } 
        printf("\n");  
    }
}

void reverse(FILE *fp)
{
    char **lines;
    int lSize = 0;

    lines = (char **)malloc(sizeof(char *) * INITCAP);
    memcheck(lines);
    
    lines = read(fp,lines,&lSize);
    write(lines,lSize);

    for (int i = 0; i < lSize; i++)
    {
        free(lines[i]);
    }
    free(lines);  
}

void memcheck(void *p)
{
    if(p == NULL)
    {
        fprintf(stderr,"No memory.");
        exit(1);
    }
}