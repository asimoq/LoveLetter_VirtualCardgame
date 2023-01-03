#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void pakligeneral(int **kartya){
        for(int i = 0; i < 16; i++){
                if(i < 5){
                    kartya[i][0] = 1;
                    kartya[i][1] = 0;
                }
                if(i >= 5 & i < 13){
                    if(i%2 != 0){
                        kartya[i][0] = kartya[i-1][0]+1;
                        kartya[i][1] = 0;}
                    if(i%2 == 0){
                        kartya[i][0] = kartya[i-1][0];
                        kartya[i][1] = 0;}
                }
                if(i >= 13){
                   kartya[i][0] = kartya[i-1][0]+1;
                    kartya[i][1] = 0;}
        }
    return kartya;
}

void paklikever(int **kartya, int jatekosszam){

        kartya[rand()%16][1] = 88; //random kivesz egy lapot a jatekbol szabalynak megfeleloen
        int kinel = 0;
        int voltmar = 0;
        for(int i = 1; i <= jatekosszam; i++){
            do{
                kinel = rand()%16;
                if( kartya[kinel][1] == 0){
                    kartya[kinel][1] = i;
                    voltmar=1;
                }

            }while(voltmar == 0);
            voltmar=0;
        }
    return kartya;
}
