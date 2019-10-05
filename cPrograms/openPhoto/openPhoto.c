#include <file.h>
#include <stdio.h>

main()
{
    FILE *fp;
    char ch;
    fp = fopen("Amber-Heard.jpg", "rb+");

    if(fp == NULL)
    {
        printf("Error in opening the image");
        fclose(fp);
        exit(0);
    }

    printf("Successfully opened the image file");

    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\nWriting to o/p completed");
}
