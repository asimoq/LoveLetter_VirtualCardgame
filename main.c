#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "debugmalloc.h"
#include "pakliletrehoz.h"
#include "kartyaleirasok.h"
#include "interakciok.h"

//pakli strukturaja: a valtozo elso tombje lesz a jatek altal kovetett azonosito, a masodik tomb 0 valtozo 1-8 jeloli a lap tipusat,
//a masodik tomb 1  valtozo a lap helyet jeloli meg:(0:pakliban; 1:egyes jatekos nal; 2:kettes jatekosnal; 3:harmas...;
// 4:negyes...; 10:egyes jatekos elott; 20: kettes j. elott stb...; 88: kivett lap; 99: eldobott lap)

//a soron levo jatekosnak kioszt egy uj lapot. main.c hasznalja.
void ujkartya(int **kartya, int jatekos){
        int melyik = 0;
        int siker = 0;
        int reszosszeg = 1;
        for(int i = 0;i <16;i++){
            if(reszosszeg>1) //nem kell olyan nagy számokkal számolnia a gépnek
                reszosszeg=1;
            reszosszeg=reszosszeg*kartya[i][1];
        }
        if(reszosszeg==0){
            do{
                melyik = rand()%16;
                if( kartya[melyik][1] == 0){
                    kartya[melyik][1] = jatekos;
                    siker=1;
                }
            }while(siker == 0);
        }
        else{
            for(int i = 0;i <16;i++){
                if(kartya[i][1]==88)
                    kartya[i][1]=jatekos;
            }
        }
    return;
}
//megnezi, hogy egy adott jatekos meg benn van-e a jatekban, vagy mar kiesett. main.c hasznalja.
bool bennvane(int **kartya, int jatekos){
    for(int i =0;i<16;i++){
        if((kartya[i][1]) == jatekos)
            return false;
    }
    return true;
}
//minimum ket jatekos van-e meg a jatekban, ha van akkor true, egyebkent false.
bool minketto(int **kartya,int jatekos){
    int jatekosszam = 0;
    for(int i =0;i<16;i++){
        if(kartya[i][1] <= 4 && kartya[i][1] != 0 && kartya[i][1] != jatekos)
            jatekosszam++;
    }
    if(jatekosszam >= 1)
        return true;
    else
        return false;
}
//egy adott jatekos elso lapjanak az erteket adja vissza.
int ertekkeres(int **kartya, int jatekos){
    for(int i = 0; i <16; i++){
        if(kartya[i][1]==jatekos)
            return kartya[i][0];
    }
    return 0;
}
//fo program, funkcioi: menuredszer kezelese, jatekoskor lebonyolitasa, a jatekallas mentese es elohivasa, gyoztes kihirdetese.
int main(void){
    srand(time(NULL));
    printf("Welcome to Love Letter! the virtual card game\n");
    printf("---------------------------------------------\n");


    int **kartya;
    kartya = (int**) malloc(16 * sizeof(int*));
    kartya[0] = (int*) malloc(2 * 16 * sizeof(int));
    for (int y = 1; y < 16; ++y){
        kartya[y] = kartya[0] + y * 2;
    }


    int menupont = 0;
    menumegnyit://goto menu kiirasa
    pakligeneral(kartya);
    printf("\nStart a new game: [1]  Load a saved game: [2]  Short briefing on the rules: [3]  Exit: [4]\n");
    scanf("%d",&menupont);
    if(menupont == 1)
        goto ujjatek;
    if(menupont == 2){
        FILE* fp;
        if(fp = fopen("allas.txt", "r")){
            fclose(fp);
            goto regijatek;
        }
        else{
            printf("You don't have a gamesave.\n");
            goto menumegnyit;
        }
    }
    if(menupont == 3){
        szabaly();
        goto menumegnyit;
    }
    if(menupont == 4){
        free(kartya[0]);
        free(kartya);
        return 0;
    }


    //goto uj jatek inditasa
    ujjatek:
        {
        int jatekosszam = 0;
        bool jatekoservenyes = false;
        do{
            printf("Pick the player-count:\n");
            scanf("%d", &jatekosszam);
            if(jatekosszam < 2 || jatekosszam > 4){
                printf("This game can only be played by 2 to 4 players at a time.\n");}
            if(jatekosszam >= 2 && jatekosszam <=4){
                jatekoservenyes = true;
            }
        }while(jatekoservenyes == false);
        paklikever(kartya,jatekosszam);

        //elso jatekos lepese.
        int jatekos = 1;
        int kijatszas = 1;


        //Fo jatekciklus kezdete
        while(minketto(kartya,jatekos)){
            clrscr();
            ujkartya(kartya,jatekos);
            regijatek:
            if(menupont==2){
                FILE* fp;
                fp = fopen("allas.txt", "r");
                for(int i = 0; i < 16; i++){ //pakli mentese
                    fscanf(fp, "%d\t%d\n" , &kartya[i][0], &kartya[i][1]);
                }
                fscanf(fp,"%d\t%d",&jatekos,&jatekosszam);
                fclose(fp);
                menupont=0;

            }
            printf("\n ----------Cards of Player %d.-----------\n", jatekos);

            //for(int i = 0; i < 16; i++) //pakli kiiratasa
            //   printf("%d \t %d \t %d \n" , i , kartya[i][0], kartya[i][1]);
            kartyakiiras(kartya,jatekos);
            printf("\n---------which card would you like to play? 1. or 2.---------");
            scanf("%d",&kijatszas);
            //fajlba mentes
            if(kijatszas==3){
                    FILE* fp;
                    fp = fopen("allas.txt", "w");
                    for(int i = 0; i < 16; i++) //pakli mentese
                        fprintf(fp, "%d\t%d\n" , kartya[i][0], kartya[i][1]);
                    fprintf(fp,"%d\t%d",jatekos,jatekosszam);
                    fclose(fp);
                    printf("Save succesful, Would you like to continue?\n[1]-yes   [2]-no, i rather quit.\n");
                    scanf("%d",&kijatszas);
                    if(kijatszas==2){
                        free(kartya[0]);
                        free(kartya);
                    return 0;
                    }
                    else{
                        printf("\n---------which card would you like to play? 1. or 2.---------");
                        scanf("%d",&kijatszas);
                    }
            }
            interakciok(kartya,kijatszas,jatekos);

            //jatekos leptetese
            if(jatekos == jatekosszam){
                jatekos = 1;
            }

            else{
                jatekos++;
            }
            while(bennvane(kartya, jatekos)){
                if(jatekos == jatekosszam){
                    jatekos = 1;
                }

                else{
                    jatekos++;
                }
            }
            //lapok felfedesenek megakadajozasa
            printf("The next player is %d. Please give him/her the device.\n",jatekos);
            getch();
            clrscr();
            printf("Press any key to continue...\n");
            getch();
            //handmaid levetele:
            handmaidlevet(kartya,jatekos);

        }//nincs tobb kartya a pakliban
        printf("------It's the end of this round!------\n\n");
        int max = 0;
        int maxkinel = 0;
        //gyoztes kivalasztasa, azonos ertek eseten a kesobbi jatekos nyer, igy kiegyensulyozva a jatekossorrend adta hatranyat.
        for(int i = 0; i < 16 ; i++){
            if(kartya[i][1]<=4 && kartya[i][1]>0){
                if(kartya[i][0]>=max){
                maxkinel=i;
                max=kartya[i][0];
                }
            }
        }
        printf("---------------------------------\n");
        printf("Player %d. won the game, congrats!\n",kartya[maxkinel][1]);
        printf("---------------------------------\n");
        goto menumegnyit;
    }
}
