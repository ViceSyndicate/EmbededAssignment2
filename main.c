#include <stdio.h>
#include <stdlib.h>

const int G_ARR_SIZE = 100;

struct Currency {
    const char * currencyName;
    long int currencyValue;
};


struct currencyName {
    char currencyNameString[3];
};

struct Currency structArr[G_ARR_SIZE];
struct currencyName stringArr[G_ARR_SIZE];
void fileHandler () {
    int index = 0;


    FILE *fp;
    char stringBuff[10];
    char intBuff[255];
    fp = fopen("..//currency.txt", "r");
    while(fscanf(fp, "%s", stringBuff)!=EOF){

        stringArr[index].currencyNameString[0] = stringBuff[0];
        stringArr[index].currencyNameString[1] = stringBuff[1];
        stringArr[index].currencyNameString[2] = stringBuff[2];


        structArr[index].currencyName = stringArr[index].currencyNameString;

        fscanf(fp, "%s", intBuff);

        char *ptr;
        long result;
        result = strtol(intBuff, &ptr, 10);
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
