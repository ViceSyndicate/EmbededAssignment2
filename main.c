#include <stdio.h>
#include <stdlib.h>

const int G_ARR_SIZE = 100;

struct Currency {
    char * currencyName[4];
    long int currencyValue;
};

void fileHandler () {
    int currenciesCount = 0;
    struct Currency structArr[G_ARR_SIZE];

    FILE *fp;
    char stringBuff[255];
    char intBuff[255];
    fp = fopen("..//currencyBadFormat.txt", "r");

    while(fscanf(fp, "%s", stringBuff)!=EOF){
        struct Currency currency;

        currency.currencyName[0] = stringBuff[0];
        currency.currencyName[1] = stringBuff[1];
        currency.currencyName[2] = stringBuff[2];
        currency.currencyName[3] = '\0';

        fscanf(fp, "%s", intBuff);
        
        char *ptr;
        long result;
        result = strtol(intBuff, &ptr, 10);
        currency.currencyValue = result;

        structArr[currenciesCount] = currency;
        currenciesCount++;
    }
    fclose(fp);
    printf("%-3s", "num| cur | val\n");
    printf("%-3s", "-  |  -  |  -\n");
    for(int i = 0; i < currenciesCount; i++){
        printf("%-3i%c", i, '|');
        printf("%2c%c%-2c", structArr[i].currencyName[0], structArr[i].currencyName[1], structArr[i].currencyName[2]);
        printf("%c%5d\n", '|', structArr[i].currencyValue);
    }
}

int main() {
    fileHandler();
    int i;
    scanf("%i", i);
    return 0;
}