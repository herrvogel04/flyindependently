/************************* 

WO IST DIE SONNE (MEC105 EINFÜHRUNG IN DIE PROGRAMMIERUNG -- PROJEKT)

01.12.2023 : (Anfang)
10.12.2023 : (V1.0)--(Der Code funktioniert, allerdings ohne Fehlertoleranz und nicht schnell.)
15.12.2023 : (V1.1)--(Der Code funktioniert Dank Zurückrufen des CSV-Dateies schneller, allerdings ohne Fehlertoleranz.)
20.12.2023 : (V1.2)--(Der Code funktioniert schnell und fehlertolerant.)
24.12.2023 : (V1.3)--(Es wird ein Sound-Effekt [\a] gemacht, wenn der Nutzer beim Eingeben einen Fehler macht.)
25.12.2023 : (Letzte Aktualisierung und das Hochladen des Codes. Dokumentation wurde erstellt und ins Deutsch übersetzt.)

  Ich habe "goto" mehrmals genutzt und ich weiß, dass es nicht so gut ist, um einen effizienten und schnellen Code zu schreiben.
  Da ich Schritt für Schritt den Code entwickelt habe und nicht genug Erfahrung habe, konnte ich mir nicht früher vorstellen, dass das
  Implementieren vom Fehlertoleranz so schwierig sein wird. Kurz gesagt, ich weiß, dass es einen besseren Weg gibt, um das Code
  weiter funktionieren zu lassen bzw. Fehler tolerieren zu lassen, statt nacheinander "goto" zu nutzen :(   

Yağız Ömer KUŞ (220507051) (Mechatronik)

*************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define CONSTANTFURBUFFER 1000
#define MAXBUCHSTABENZAHL 51
#define STADTANZAHL 81                                                //Die constanten Zahlen wurden bestimmt.
#define ZWISCHENMERIDIANEN 86.84
#define ZWISCHENPARALLELEN 111

char Buffer[CONSTANTFURBUFFER];                                       //Buffer 

struct StadtInfos {                                                   //Array für die Städte
    char NameS[MAXBUCHSTABENZAHL];
    char Parallelen[MAXBUCHSTABENZAHL];
    char Meridianen[MAXBUCHSTABENZAHL];
};

float DistanzRechnung(float Pn, float Pz, float Mn, float Mz){        //Eine Funktion zur Distanzrechnung

    float DistanzM = (Mn - Mz)*ZWISCHENMERIDIANEN;
    float DistanzP = (Pn - Pz)*ZWISCHENPARALLELEN;                                              
    return sqrtf(DistanzM*DistanzM+DistanzP*DistanzP); 
}

void WoSollSizten(float Pn, float Pz, float Anknft, float Abfhrt){    //Eine Funktion zur Rechnung und zum Informieren, woher die Sonne am Meisten kommt. 

    float ZeitBufferVMTG = 0;
    float ZeitBufferNMTG = 0;

    if(Abfhrt <= 7 && Anknft <= 7){
        ZeitBufferVMTG = 0;
        ZeitBufferNMTG = 0;
    }
    else if(Abfhrt <= 7 && Anknft >= 7 && Anknft < 12){
        ZeitBufferVMTG = Anknft-7;
        ZeitBufferNMTG = 0;        
    }
    else if(Abfhrt <= 7 && Anknft >= 12 && Anknft < 19 ){
        ZeitBufferVMTG = 5;
        ZeitBufferNMTG = Anknft-12;
    }
    else if(Abfhrt <= 7 && Anknft >= 19 ){
        ZeitBufferVMTG = 5;
        ZeitBufferNMTG = 7;
    }
    else if(Abfhrt >= 7 && Abfhrt < 12 && Anknft >= 7 && Anknft < 12){
        ZeitBufferVMTG = Anknft-Abfhrt;
        ZeitBufferNMTG = 0;
    }
    else if(Abfhrt >= 7 && Abfhrt < 12 && Anknft >= 12 && Anknft < 19 ){
        ZeitBufferVMTG = 12-Abfhrt;
        ZeitBufferNMTG = Anknft-12;
    }
    else if(Abfhrt >= 7 && Abfhrt < 12 && Anknft >= 19 ){
        ZeitBufferVMTG = 12-Abfhrt;
        ZeitBufferNMTG = 7;
    }
    else if(Abfhrt >= 12 && Abfhrt < 19 && Anknft >= 12 && Anknft < 19 ){
        ZeitBufferVMTG = 0;
        ZeitBufferNMTG = Anknft-Abfhrt;
    }
    else if(Abfhrt >= 12 && Abfhrt < 19 && Anknft >= 19 ){
        ZeitBufferVMTG = 0;
        ZeitBufferNMTG = 19-Abfhrt;
    }
    else if(Abfhrt >= 19 && Anknft >= 19 ){
        ZeitBufferVMTG = 0;
        ZeitBufferNMTG = 0;
    }
    else
        printf("\nOOPS!\n");                                                                         

    printf("Vormittag: %.1f Stunden\n", ZeitBufferVMTG);
    printf("Nachmittag: %.1f Stunden\n", ZeitBufferNMTG);

    
    if(Pn < Pz){
        
        if(ZeitBufferNMTG>ZeitBufferVMTG)
        printf("\nBitte Kaufen Sie am rechten Sitzplatz ein Ticket\nSonne wird Meistens von der linken Seite kommen!\n");
        else if(ZeitBufferNMTG<ZeitBufferVMTG)
        printf("\nBitte Kaufen Sie am linken Sitzplatz ein Ticket\nSonne wird Meistens von der rechten Seite kommen!\n");
        else if(ZeitBufferNMTG==0.0 && ZeitBufferVMTG==0.0)
        printf("\nEs ist egal, wo Sie sitzen...\nEs gibt keine Sonne während der Reise.\n");
        else if(ZeitBufferNMTG==ZeitBufferVMTG)
        printf("\nEs ist egal, wo Sie sitzen...\nSonne wird von der beiden Seite gleichmaessig kommen!\n");
        else
        printf("\nOOPS!\n");    
    
    }
    else {

        if(ZeitBufferNMTG>ZeitBufferVMTG)
        printf("\nBitte Kaufen Sie am linken Sitzplatz ein Ticket\nSonne wird Meistens von der rechten Seite kommen!\n");
        else if(ZeitBufferNMTG<ZeitBufferVMTG)
        printf("\nBitte Kaufen Sie am rechten Sitzplatz ein Ticket\nSonne wird Meistens von der linken Seite kommen!\n");
        else if(ZeitBufferNMTG==ZeitBufferVMTG)
        printf("\nEs ist egal, wo Sie sitzen...\nSonne wird von der beiden Seite gleichmaessig kommen!\n");
        else
        printf("\nOOPS!\n");    

    }
}

int KontrollEingabe(char Ntzr[MAXBUCHSTABENZAHL], char Datei[MAXBUCHSTABENZAHL]){   
        if (strcmp(Ntzr, Datei)==0)
            return 1;                                                  //Es wurde mit dieser Funktion kontrolliert, ob der Nutzer die Infos richtig eingegeben hat.
        else                                                                                
            return 0;
}

int main(void) {
    
    printf("\n\n########################################################################\n");   
    printf("#                         WO IST DIE SONNE V1.3                        #\n");
    printf("#                            (c) herrVogel                             #\n");
    printf("########################################################################\n\n");  

    struct StadtInfos StadtARRAY[STADTANZAHL];                        //Array wurde hier genutzt.
    
    FILE *Koordinaten = fopen("koordinaten.csv","r");                 //CSV wurde zurückgerufen.

    for(int i = 0 ; i < STADTANZAHL ; i ++){                          //Die Infos in CSV wurden als String genommen.       
        
        fgets(Buffer, sizeof(Buffer), Koordinaten);
        
        strcpy(StadtARRAY[i].NameS, strtok(Buffer,", "));
        //printf("%s\n", StadtARRAY[i].NameS);       -- TEST --
        
        strcpy(StadtARRAY[i].Parallelen, strtok(NULL,", "));          
        //printf("%s\n", StadtARRAY[i].Parallelen);  -- TEST --

        strcpy(StadtARRAY[i].Meridianen, strtok(NULL,","));
        //printf("%s\n", StadtARRAY[i].Meridianen);  -- TEST --
 
    }
    
    printf("--        Programm : Die Dateien wurden erfolgreich genommen!          --\n\n");   
    printf("                                 ACHTUNG!!                               \n");
    printf("-- 1) Achten Sie bitte auf die Gross- und Kleinbuchstaben beim Eingeben--\n"); 
    printf("-- 2) Nur die englischen Charakteren sind erlaubt                      --\n");
    printf("-- 3) Dieses Programm enthaltet nur die Staedte von der Tuerkei        --\n\n");  
        
    float Zeitraum;                                      
    char NutzerStadtName[MAXBUCHSTABENZAHL]; 
    char ZielStadtName[MAXBUCHSTABENZAHL];  
    float Abfahrt;  
    float Ankunft; 
    int KontrolBuffer1=0; 
    int KontrolBuffer2=0;
    int KontrolBufferZahl1; 
    int KontrolBufferZahl2; 

start:
                     
    printf("\nWo sind Sie? : ");
    scanf("%s", NutzerStadtName);
                                                      
    printf("Wohin wollen Sie fahren? : ");
    scanf("%s", ZielStadtName);

for(int i = 0 ; i < STADTANZAHL ; i ++) { 
    KontrolBuffer1 = KontrollEingabe(NutzerStadtName, StadtARRAY[i].NameS);
    if(KontrolBuffer1 == 1)
    break;
}
for(int i = 0 ; i < STADTANZAHL ; i ++) { 
    KontrolBuffer2 = KontrollEingabe(ZielStadtName, StadtARRAY[i].NameS);
    if(KontrolBuffer2 == 1)
    break;
}

if(KontrolBuffer1 ==1 && KontrolBuffer2 ==1) 
    goto oops;
else {
    printf("%c\n#ACHTUNG!# Bitte geben Sie gueltige Infos ein!\n--Zahlen sind nicht erlaubt\n--Gross und Kleinbuchstaben sind wictig\n--Nur die englischen Charakteren sind erlaubt\nBeispiel: Ankara/Istanbul/Izmir\n",'\a');
    goto start;
}

oops:

//ZITAT AUS DEM INTERNET (Ich zitiere nur den Beispiel-Code. Es überprüft, ob die eingegebenen Daten Float sind) --
printf("Abfahrt: ");
while(scanf("%f",&Abfahrt) != 1)
{
printf("%c\n#ACHTUNG!# Bitte geben Sie eine Zahl ein!",'\a');
printf("\n\nAbfahrt: ");
while(getchar() != '\n');
}
                                                    
printf("Ankunft: ");
while(scanf("%f",&Ankunft) != 1)
{
printf("%c\n#ACHTUNG!# Bitte geben Sie eine Zahl ein!",'\a');
printf("\n\nAnkunft: ");
while(getchar() != '\n');
}
//ENDE DES ZITATS (Quelle : https://stackoverflow.com/questions/26583717/how-to-scanf-only-integer)--------------------

if(Abfahrt>=Ankunft || Abfahrt>23 || Ankunft>23 || Abfahrt<0 || Ankunft<0){
printf("%c\n#ACHTUNG!# Eingabe ist nicht logisch oder Zahlen sind nicht zwischen 0 und 23. Versuchen Sie bitte noch einmal...\n\n",'\a');
goto oops;
}

Zeitraum = Ankunft - Abfahrt;

 /**********----------{BERECHNUNG VON DISTANZ UND GESCHWINDIGKEIT}-----------**********/
              
for(int i = 0 ; i < STADTANZAHL ; i ++) {                                                       

    if (strcmp(NutzerStadtName, StadtARRAY[i].NameS) == 0 ) {
            
        char *BufferMeridianCharPoint = &StadtARRAY[i].Meridianen[0];
        float MeridianNutzer = atof(BufferMeridianCharPoint);                         // String-->Float (Von Internet wurde Hilfe genommen.)
                                                                            
        char *BufferParallelCharPoint = &StadtARRAY[i].Parallelen[0];       
        float ParallelNutzer = atof(BufferParallelCharPoint);
        
        for(int i = 0 ; i < STADTANZAHL ; i ++) {  
            
            if (strcmp(ZielStadtName, StadtARRAY[i].NameS) == 0 ) {
            
                char *BufferMeridianCharPoint = &StadtARRAY[i].Meridianen[0];
                float MeridianZiel = atof(BufferMeridianCharPoint);                   // String-->Float (Von Internet wurde Hilfe genommen.)

                char *BufferParallelCharPoint = &StadtARRAY[i].Parallelen[0];
                float ParallelZiel = atof(BufferParallelCharPoint);

                    //printf("ParallelNutzer : %.4f\n", ParallelNutzer);    -- TEST --
                    //printf("MeridianNutzer : %.4f\n", MeridianNutzer);    -- TEST --                 
                    //printf("ParallelZiel : %.4f\n", ParallelZiel );       -- TEST --
                    //printf("MeridianZiel : %.4f\n", MeridianZiel );       -- TEST --
                        
                printf("\n##ERGEBNIS##\nDistanz : %.4fkm\n", DistanzRechnung(ParallelNutzer, ParallelZiel, MeridianNutzer, MeridianZiel));                
                printf("Geschwindigkeit : %.4fkm/h\n", DistanzRechnung(ParallelNutzer, ParallelZiel, MeridianNutzer, MeridianZiel) / Zeitraum);        
                WoSollSizten(ParallelNutzer, ParallelZiel, Ankunft, Abfahrt);                                                     
               
            }    
        }        
    }
}  

 /************--------------------{ENDE DER BERECHNUNG}--------------------************/

    char NutzerAntwort[2];
    KontrolBuffer1 = 0;
    KontrolBuffer2 = 0;
frage:    
    
    printf("\nWollen Sie weiter machen? (j/n): ");
    scanf("%s",NutzerAntwort);
                       
    if(strcmp(NutzerAntwort, "j") == 0 ) {
        printf("\n################ Das Programm wurde nochmal gestartet! ##################\n ");
        goto start;
    }
    else if(strcmp(NutzerAntwort, "n") == 0 ) {
        printf("\n################ Das Programm wurde vom Nutzer beendet! #################\n");
        return 0;
    }
    else {
        printf("%c\n#ACHTUNG!# Bitte geben Sie ein gueltiges Antwort (j/n) ein!!\n",'\a');
        goto frage;
    }
}   