#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool handmaid(int **kartya, int jatekos){
    for(int i =0;i<16;i++){
        if((kartya[i][1]) == jatekos*10)
            return true;
    }
    return false;
}

void handmaidlevet(int **kartya, int jatekos){
    for(int i =0;i<16;i++){
        if((kartya[i][1]) == jatekos*10){
            kartya[i][1]=99;
        }
    }
}




void interakciok(int **kartya, int melyik, int jatekos){
    int kesz = 0;
    int i = -1;
    int interaktal = 0;
    int szabalyos = 0;
    int tipp = 0;
    //kivalasztott kartya indexenek megkeresese
    if (melyik == 1){
        while(kesz == 0){
            i++;
            if( kartya[i][1] == jatekos ){
                kesz = 1;
            }

        }
    }
    else{
        i = 16;
        while(kesz == 0){
            i--;
            if( kartya[i][1] == jatekos ){
                kesz = 1;
            }

        }
    }

    if(kartya[i][0]==1){
                printf("You can choose from these players: ");
                for(int j = 0; j < 16 ;j++){
                    if(kartya[j][1] !=0 && kartya[j][1] != jatekos && kartya[j][1] <=4)
                        printf("%d / ",kartya[j][1]);
                }
                while(szabalyos==0){
                    scanf("%d",&interaktal);
                    if(interaktal==5){
                        printf("You have discarded your card.\n");
                        kartya[i][1] = 99;
                        szabalyos = 1;
                    }
                    if(handmaid(kartya,interaktal)==true){
                        printf("This player is protected by The Handmaid. Choose another player, or press button 5 to discard your card!\n");
                    }
                    else{
                        printf("Try to guess the secret identity!(2-8)\n");
                        scanf("%d",&tipp);
                        if(tipp == ertekkeres(kartya,interaktal)){
                            printf("You guessed it, the %d. player got eliminated.\n",interaktal);
                            for(int j = 0;j <16; j++){
                                if(kartya[j][1]==interaktal){
                                        kartya[j][1]=99;
                                }
                            }
                        }
                            else{
                                printf("It's a miss...\n");
                                kartya[i][1] = 99;
                            }
                    szabalyos=1;
                    }

                }
    }
    if(kartya[i][0]==2){
                printf("You can choose from these players:  ");
                for(int j = 0; j < 16 ;j++){
                    if(kartya[j][1] !=0 && kartya[j][1] != jatekos && kartya[j][1] <=4)
                        printf("%d / ",kartya[j][1]);
                }
                while(szabalyos==0){
                    scanf("%d",&interaktal);
                    if(interaktal==5){
                        printf("You have discarded your card.\n");
                        kartya[i][1] = 99;
                        szabalyos = 1;
                    }
                    if(handmaid(kartya,interaktal)==true){
                        printf("This player is protected by The Handmaid. Choose another player, or press button 5 to discard your card!\n");
                    }
                    else{
                    printf("Player %d. has a card with the value of... : [%d]\n",interaktal,ertekkeres(kartya,interaktal));
                    kartya[i][1] = 99;
                    szabalyos=1;
                    }
                }
    }
    if(kartya[i][0]==3){
                kartya[i][1]=99;
                printf("You can choose from these players:  ");
                for(int j = 0; j < 16 ;j++){
                    if(kartya[j][1] !=0 && kartya[j][1] != jatekos && kartya[j][1] <=4)
                        printf("%d / ",kartya[j][1]);
                }
                while(szabalyos==0){
                    scanf("%d",&interaktal);
                    if(interaktal==5){
                        printf("You have discarded your card.\n");
                        kartya[i][1] = 99;
                        szabalyos = 1;
                    }
                    if(handmaid(kartya,interaktal)==true){
                        printf("This player is protected by The Handmaid. Choose another player, or press button 5 to discard your card!\n");
                    }
                    else{
                        if(ertekkeres(kartya,jatekos) > ertekkeres(kartya,interaktal)){
                            printf("You have the more valuable card, player %d. is ELIMINATED.\n",interaktal);
                            for(int j = 0;j <16; j++){
                                if(kartya[j][1]==interaktal){
                                        kartya[j][1]=99;
                                }
                            }
                        }
                        if(ertekkeres(kartya,jatekos) < ertekkeres(kartya,interaktal)){
                            printf("He has the more valuable card. You are OUT.\n");
                            for(int j = 0;j <16; j++){
                                if(kartya[j][1]==jatekos){
                                        kartya[j][1]=99;
                                }
                            }
                        }
                        if(ertekkeres(kartya,jatekos) == ertekkeres(kartya,interaktal)){
                            printf("Your cars are even.\n");
                            kartya[i][1]=99;
                        }
                    szabalyos=1;
                    }
                }

    }
    if(kartya[i][0]==4){
                printf("You are protected by The Handmaid till your next turn.\n");
                kartya[i][1]=jatekos*10;
    }
    if(kartya[i][0]==5){
                kartya[i][1]=99;
                printf("You can choose from these players: ");
                for(int j = 0; j < 16 ;j++){
                    if(kartya[j][1] !=0 && kartya[j][1] <=4)
                        printf("%d / ",kartya[j][1]);
                }
                while(szabalyos==0){
                    scanf("%d",&interaktal);
                    if(handmaid(kartya,interaktal)==true){
                        printf("This player is protected by The Handmaid. Choose another player, or press button 5 to discard your card!\n");
                    }
                    else{
                        for(int j = 0;j <16; j++){
                            if(kartya[j][1]==interaktal){
                                kartya[j][1]=99;
                            }
                        }
                        ujkartya(kartya,interaktal);
                    }
                    szabalyos=1;
                }

    }
    int ideiglenes = 0;
    int ideigleneshelye = 0;
    if(kartya[i][0]==6){
                kartya[i][1]=99;
                printf("You can choose from these players: ");
                for(int j = 0; j < 16 ;j++){
                    if(kartya[j][1] !=0 && kartya[j][1] != jatekos && kartya[j][1] <=4)
                        printf("%d / ",kartya[j][1]);
                }
                while(szabalyos==0){
                    scanf("%d",&interaktal);
                    if(interaktal==5){
                        printf("You have discarded your card.\n");
                        kartya[i][1] = 99;
                        szabalyos = 1;
                    }
                    if(handmaid(kartya,interaktal)==true){
                        printf("This player is protected by The Handmaid. Choose another player, or press button 5 to discard your card!\n");
                    }
                    else{
                        kartya[i][1]=99;
                        for(int j = 0;j <16; j++){
                            if(kartya[j][1]==jatekos){
                                ideiglenes=kartya[j][1];
                            }
                        }
                        for(int j = 0;j <16; j++){
                            if(kartya[j][1]==interaktal){
                                for(int x = 0;x <16; x++){
                                    if(kartya[x][1]==jatekos){
                                        kartya[x][1]=kartya[j][1];
                                        ideigleneshelye=j;
                                    }
                                }
                            }
                        }
                        kartya[ideigleneshelye][1]=ideiglenes;
                        szabalyos=1;
                    }
                }
    }
    if(kartya[i][0]==7){
                printf("You have discarded your card.\n");
                kartya[i][1]=99;
    }
    if(kartya[i][0]==8){
                kartya[i][1]=99;
                for(int j = 0; j < 16 ; j++){
                    if(kartya[j][1]==jatekos)
                        kartya[j][1]=99;
                }
                printf("You have discarded The PRINCESS! You got eliminated.\n\n");

                }

}
