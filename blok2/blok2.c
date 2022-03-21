// blok2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <stdio.h>
#pragma warning(disable:4996)
#include <Windows.h>


int uloha2_1_1(int cislo1, int cislo2) {
    int vysledok = 0;
    
    __asm {                          // zaciatok bloku asm
        MOV EAX, cislo1              //Do EAX sa nahra cislo1
        MOV ECX, cislo2              //Do ECX sa nahra cislo2
        ADD EAX, ECX                 //EAX = EAX + ECX           
        MOV vysledok, EAX            //EAX sa nahra do premennej vysledok     
    }                               
    
    printf("%d + %d = %d", cislo1, cislo2, vysledok);
    return vysledok;
}
int uloha2_1_2(int cislo) {
    int vysledok = 0;
    __asm {                          // zaciatok bloku asm
        MOV EAX, cislo               //Do EAX sa nahra
        SHL EAX, 1                   //EAX = cislo<<1           
        MOV vysledok, EAX            //EAX sa nahra do premennej vysledok     
    }
    printf("%d * 2 = %d", cislo, vysledok);
    return vysledok;
}

void uloha2_1_3(int cislo) {

    __asm {                          // zaciatok bloku asm
        MOV EAX, cislo               //Do EAX sa nahra cislo
        MOV ECX, 10                  //Do EAC sa nahra 10
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
void uloha2_1_4() {
    int pole[3];
    __asm {                          // zaciatok bloku asm
        MOV EAX, 0               //Do EAX sa nahra cislo
        CPUID
        MOV pole[0], EBX
        MOV pole[1], EDX
        MOV pole[2], ECX
    }
    for (int i = 0; i < 3; i++) {
        printf("%s", &pole[i]);
    }

}


void uloha2_5_1() {
    int color = 2;
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
    uloha2_1_4();
    /*for (int i = 1; i <= 15; i++) {
        uloha2_1_3(i);
    }*/
    
}
