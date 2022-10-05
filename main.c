#include <stdio.h>
#include <stdlib.h>

const int G_ARR_SIZE = 10;

struct Currency {
    const char * currencyName[3];
    long int currencyValue;
};

void fileHandler () {
    int index = 0;
    struct Currency structArr[G_ARR_SIZE];

    FILE *fp;
    char stringBuff[255];
    char intBuff[255];
    fp = fopen("..//currency.txt", "r");

    while(fscanf(fp, "%s", stringBuff)!=EOF){
        struct Currency currency;

        currency.currencyName[0] = stringBuff[0];
        currency.currencyName[1] = stringBuff[1];
        currency.currencyName[2] = stringBuff[2];

        fscanf(fp, "%s", intBuff);

        char *ptr;
        long result;
        result = strtol(intBuff, &ptr, 10);
        currency.currencyValue = result;

        structArr[index] = currency;
        index++;
    }
    fclose(fp);
    for(int i = 0; i < 10; i++){
        printf("\n%c%c%c", structArr[i].currencyName[0], structArr[i].currencyName[1], structArr[i].currencyName[2]);
        printf(" - %i Cent", structArr[i].currencyValue);
    }

}


int main() {
    fileHandler();
    return 0;
}