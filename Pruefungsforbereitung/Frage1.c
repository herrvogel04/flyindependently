#include <stdio.h>
#include <string.h>
#define MAXBUCHSTABENZAHL 100
#define MAXDATAZAHL 100

struct Nutzerwerte
{
    char Wert[MAXBUCHSTABENZAHL];
};
void main(){
    int frage = 'y';
    printf("Ich werde die Werte auflisten\n");
    struct Nutzerwerte Eingabe[MAXDATAZAHL];
    int i = 0;
    while(frage == 'y'){
        printf("geben Sie %d. Wert ein: ", i+1);
        scanf(" %s", Eingabe[i].Wert);
        i++;
        printf("\nWollen Sie weitermachen?[y/n] : ");
        scanf("%d", &frage);
    }
for(int k=0; k<=i; k++){
    printf("%s\t", Eingabe[k].Wert);
}

}