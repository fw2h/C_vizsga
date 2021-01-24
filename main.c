//Kaczúr Gyula Dániel -9-
//GBHZYJ
//gcc -pedantic -Wall -Wextra main.c funcs.c

#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        reverse(stdin);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            FILE *fp = fopen(argv[i],"r");
            if(NULL == fp)
            {
                fprintf(stderr,"File not exists(%s).\n",argv[i]);
                continue;
            }
            reverse(fp);
            fclose(fp);  
        }
    }
    return 0;
}
