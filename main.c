#include <stdio.h>
#include <stdlib.h>

const int G_ARR_SIZE = 10;

struct Currency {
    const char * currencyName;
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
        currency.currencyName = stringBuff;

        fscanf(fp, "%s", intBuff);

        char *ptr;
        long result;
        result = strtol(intBuff, &ptr, 10);
        currency.currencyValue = result;

        structArr[index] = currency;
        index++;
    }
    fclose(fp);
}


int main() {
    fileHandler();
    return 0;
}
