#include <stdio.h>
#pragma warning(disable:4996)
#include <Windows.h>
#include <string.h>
#include "moje_funkcie.h"

int uloha2_1_1(int cislo1, int cislo2) {
    //funkcia scita cislo1 a cislo2 a vysledok vypise
    int vysledok = 0; 
    __asm {                          // zaciatok bloku asm
        MOV EAX, cislo1              //Do EAX sa nahra cislo1
        MOV ECX, cislo2              //Do ECX sa nahra cislo2
        ADD EAX, ECX                 //EAX = EAX + ECX           
        MOV vysledok, EAX            //EAX sa nahra do premennej vysledok     
    }                               
    
    printf("%d + %d = %d\n", cislo1, cislo2, vysledok);
    return vysledok;
}
int uloha2_1_2(int cislo) {
    //funkcia vynasobi cislo * 2 pomocou shift logical left(SHL)
    int vysledok = 0;
    __asm {                          // zaciatok bloku asm
        MOV EAX, cislo               //Do EAX sa nahra
        SHL EAX, 1                   //EAX = cislo<<1           
        MOV vysledok, EAX            //EAX sa nahra do premennej vysledok     
    }
    printf("%d * 2 = %d\n", cislo, vysledok);
    return vysledok;
}

void uloha2_1_3(int cislo) {
    //funkcia vypise dekadicke cislo 1-15 v sestnaskovej sustave
    __asm {                          // zaciatok bloku asm
        MOV EAX, cislo               //Do EAX sa nahra cislo
        MOV ECX, 10                  //Do ECX sa nahra 10
        CMP ECX, EAX                 //POROVNA EAX a ECX
        JG ElseBlock                 //AK ECX > EAX jump na ElseBlock
        ADD EAX, 55                  // EAX + 55
        JMP AfterConditionalBlock    // jump na AfterConditionalBlock
        ElseBlock:
        ADD EAX, 48                 // EAX + 48
        AfterConditionalBlock:
        MOV cislo, EAX            //EAX sa nahra do premennej cislo     
    }
    printf("%c\n", cislo);
    
}

void uloha2_2() {
    char pole_znakov[] = "architektura_pocitacov_je_super_predmet_milujem_ho";
    char* pointer = pole_znakov;
    printf("%s\n", pole_znakov);
    printf("%p\n", pointer);
    pointer++;
    *pointer = '?'; 
    printf("%s", pole_znakov);
    pointer = pointer + 10000;
    *pointer = 'h';
}
int prevod_kodovania(znak) {
    switch (znak) {
    case 165: //Ľ
        znak = 188;
        break;
    case 169: //Š
        znak = 138;
        break;
    case 171: //Ť
        znak = 141;
        break;
    case 174: //Ž
        znak = 142;
        break;
    case 181: //ľ
        znak = 190;
        break;
    case 185: //š
        znak = 154;
        break;
    case 187: //ť
        znak = 157;
        break;
    case 190: //ž
        znak = 158;
        break;
    }
    return znak;
}

void uloha2_3_1() {
    FILE *fr, *fw;
    int znak;

    fr = fopen("poviedka_in.html", "r");
    fw = fopen("poviedka_out.html", "w");
    if (fr == NULL) {
        printf("subor ktory sa pokusate otvorit neexistuje");
        return;
    }
    znak = fgetc(fr);
    while (znak != EOF) {
        znak = prevod_kodovania(znak);
        fputc(znak, fw);
        znak = fgetc(fr);
    }
    fclose(fr);
    fclose(fw);

}

void uloha2_3_2() {
    FILE* fr, * fw;
    int znak;

    fr = fopen("koniec_poviedky_in.html", "rb");
    fw = fopen("koniec_poviedky_out.html", "w");
    znak = fgetc(fr);

    while (znak != EOF) {
        znak = znak ^ 27; //desifrovanie
        prevod_kodovania(znak);
        fputc(znak, fw);
        znak = fgetc(fr);
    }
    fclose(fr);
    fclose(fw);

}

void uloha2_5_1() {
    //funkcia vypise cisla 0-50(1 cislo za sekundu) a zmeni farbu textu pokial je cislo delitelne desiatimi
    int color = 2;  //zelena
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i <= 50; i++) {
        SetConsoleTextAttribute(hConsole, color);
        printf("%d\n", i);
        if (i % 10 == 0 && i != 0) {
            color = color + 1;
        }
        Sleep(1000);
    }
}




int main()
{
    uloha2_3_2();
    
}
