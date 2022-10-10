#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int G_ARR_SIZE = 100;

struct Currency {
    char * currencyName;
    long int currencyValue;
};


struct Currency structArr[G_ARR_SIZE];

char stringArr[100][4];

void fileHandler () {
    int index = 0;


    FILE *fp;

    char buff[255];
    fp = fopen("..//currency.txt", "r");
    while(fscanf(fp, "%s", buff)!=EOF){


        strncpy(stringArr[index], buff, 3);
        structArr[index].currencyName = stringArr[index];


        fscanf(fp, "%s", buff);

        char *ptr;
        long result;
        result = strtol(buff, &ptr, 10);
        structArr[index].currencyValue = result;

        index++;
    }
    fclose(fp);
}

void printTable () {
    for (int i = 0; i < 20; i++) {
        printf("%c", *structArr[i].currencyName);
        printf("%c", *(structArr[i].currencyName+1));
        printf("%c: ", *(structArr[i].currencyName+2));

        printf("%ld\n", structArr[i].currencyValue);
    }
}




int main() {

    fileHandler();
    printTable();
    return 0;
}
