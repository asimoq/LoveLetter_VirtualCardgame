#include <stdio.h>
#include <stdlib.h>


//tarolja es indexxel hivva kiirja a kartyaertekekhez tartozo leirasokat.
void kartyaleiras(int **kartya, int index){
    if( kartya[index][0] == 1 ){
        printf("\n\n[1]The Guard: \n When you discard the Guard, choose a player and name a card (other than Guard).\n If that player has that card, that player is knocked out of the round.\n If all other players still in the round are protected by the Handmaid, this card does nothing.\n");
    }
    if( kartya[index][0] == 2 ){
        printf("\n\n[2]The priest:\n When you discard the Priest, you can look at one other player's hand.\n Do not reveal the hand to all players.\n");
    }
    if( kartya[index][0] == 3 ){
        printf("\n\n[3]The Baron:\n When discarded, choose one other player still in the round.\n You and that player secretly compare your hands.\n The player with the lower rank is knocked out of the round.\n In case of a tie, nothing happens.\n If all other players still in the round are protected by the Handmaid, this card does nothing.\n");
    }
    if( kartya[index][0] == 4 ){
        printf("\n\n[4]The Handmaid :\n When you discard the Handmaid, you are immune to the effects of other players'\n cards until the start of your next turn.\n If all players other than the player whose turn it is are protected by Susannah,\n the player must choose him- or herself if possible.\n");
    }
    if( kartya[index][0] == 5 ){
        printf("\n\n[5]The Prince :\n When you discard Prince Arnaud, choose one player still in the round (including yourself).\n That player discards his or her hand (do not apply its effect) and draws a new card.\n the deck is empty, that player draws the card that was removed at the start of the round.\n If all other players are protected by the Handmaid, you must choose yourself.\n");
    }
    if( kartya[index][0] == 6 ){
        printf("\n\n[6]The King :\n When you discard King Arnaud IV, trade the card in your hand with the card held by another player of your choice.\n You cannot trade with a player who is out of the round, nor with someone protected by the Handmaid.\n If all other players still in the round are protected by the Handmaid, this card does nothing.\n");
    }
    if( kartya[index][0] == 7 ){
        printf("\n\n[7]The Countess :\n Unlike other cards, which take effect when discarded, the text on the Countess applies while she is in your hand.\n In fact, she has no effect when you discard her.\n If you ever have the Countess and either the King or Prince in your hand, you must discard the Countess.\n You do not have to reveal the other card in your hand.\n");
    }
    if( kartya[index][0] == 8 ){
        printf("\n\n[8]The Princess :\n If you discard the Princess-no matter how or why-she has tossed your letter into the fire.\n You are knocked out of the round.\n");
    }
}

// kiirja egy adott jatekos osszes kezbentartott lapjat.
void kartyakiiras(int **kartya, int jatekos){
    int d = 1;
    for(int i = 0; i < 16; i++){
        if( kartya[i][1] == jatekos){
            printf("\n%d. card:",d);
            kartyaleiras(kartya,i);
            d++;
        }
    }
}
//torli a konzolt.
void clrscr()
{
    system("@cls||clear");
}

void szabaly(){
    clrscr();
    printf("\nMain goal:\nEliminate all other players, or have the most valuable card when the deck empties.\n");
    printf("\nIn every round you choose one of the two cards in your hand and discard it. Apply any effect on the card you discarded. You must apply its effect, even if it is bad for you.\nOnce you finish applying the card's effect, the turn passes to the player on your left.");
    printf("\n\nA round ends if the deck is empty at the end of a turn.The player with the highest ranked person wins the round. In case of a tie, the player who came later in the beginning of the game wins.\nA round also ends if all players but one are out of the round, in which case the remaining player wins.\n\n");




}
