#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string.h>

int composerDE(const char *word, const char *letter) {
    int letterCount[256] = {0};
    while (*letter != '\0') {
        letterCount[(unsigned char)(*letter)]++;
        letter++;
    }
    while (*word != '\0') {
        if (letterCount[(unsigned char)(*word)] == 0) {
            return 0;
        }
        letterCount[(unsigned char)(*word)]--;
        word++;
    }

    return 1;
}

int main(){

    int f=0, tst,woh=1,wsol=0,jou,li=0,h=0,manche=1,exite,nbr_mou7awalet=0;
    int isFound =0;
    int final1=0,final2=0;
    int thelongest;
    int wrong=0;
    int score=0;
    int choix2;
    int signe;
    int max_mou7awalet_8alta=9;
    int maxLength = 0;
    int currentLength =0;
    int matrixIndex = 0;
    int test,taille,choix;
    int i,j,count=0,vide=0;
    int stop,nb_mots=0,l=0,K=0;
    int giveup,p=0;
    int tm /*taille taw */ ,tx=0 /*taille max =0*/,tM/*likbira minili 7atithom ena*/ ;
//importation de fichier
    int tm2/*taille taw */ , tx2=0 /*taille max =0*/,tM2/*likbira minili 7atithom ena*/ ;
//importation de fichier
    char used [1000][27];
    char TFmanche[100][100];
    char conti_ou_non;
    char longestWord[10];
    char motutilisateur[10];
    char motORD[10];
    char motORD_lower[10];
    char r;
    char aleatoireCV[10];/*teb3a il choix mte3 il consonne*/
    char voyelle[] = {'A', 'E', 'I', 'O', 'U','Y'};
    char cons[]={ 'B','C','D','F', 'G', 'H', 'J', 'K', 'L', 'M', 'N' ,'P', 'Q','R','S','T','V',' W','X','Z'};
    int ligne[100];
    static char words[336531][27];
    char cpwords[33700][27];
    static char matrix[1000][27];
    static char trys[9][9];
    static char trys2[9][9];
    clock_t  start , fin  ;
    float te , deff ,totaltemps;


   FILE *fichier= fopen("dictionnaire.txt", "r");
if (fichier== NULL) {
    printf("Could not open the file.\n");
   exit(0);
}
else{
        stop=0;
        while(fgets(ligne,100,fichier)!=NULL){
            char*token=strtok(ligne,"\n");
            while(token!=NULL && stop==0){
                if(nb_mots<336532){
                    strcpy(words[nb_mots],token);
                nb_mots++;
                }

else{
 printf("manque d'espace ");
   stop=1;
}
token=strtok(NULL,"\t\n");}}
fclose(fichier);
}

    for (i = 0; i < 336532; i++) {
    for (j = 0; j < 27; j++) {
        if (words[i][j] == 'é' || words[i][j] == 'è' || words[i][j] == 'ê' || words[i][j] == 'ë') {
            words[i][j] = 'e';
        }
        if (words[i][j] == 'û' || words[i][j] == 'ù' || words[i][j] == 'ü' || words[i][j] == 'ú') {
            words[i][j] = 'u';
        }
        if (words[i][j] == 'à' || words[i][j] == 'â' || words[i][j] == 'á' || words[i][j] == 'ä') {
            words[i][j] = 'a';
        }
         if (words[i][j] == 'ö' || words[i][j] == 'ó' || words[i][j] == 'ò' ) {
            words[i][j] = 'o';
        }
         if (words[i][j] == 'ï' || words[i][j] == 'î' || words[i][j] == 'ì' ) {
            words[i][j] = 'i';
        }
         if (words[i][j] == 'ÿ' ) {
            words[i][j] = 'y';
        }
        if (words[i][j] == 'ç' ) {
            words[i][j] = 'c';
        }

    }
}
for(i=0;i<336532;i++){
    for(j=0;j<27;j++){
    words[i][j]=toupper(words[i][j]);
    }
}
  for( i=0;i<2; i++ ){
         printf("\n");
  }
    printf("          JEU    DE    MOTS      \n");

    for( i=0;i<2;i++ ){
         printf("\n");
    }
    printf("1- jouer a un \n");
    printf("2- jouer a un sous une contrainte de temps \n");
    printf("3- jouer a deux \n");
    printf("0- quitter\n");

    do{
    scanf("\n%i",&choix);
    printf("votre choix = %i",choix);
    }while((choix>3)||(choix<0));



  //les choix



do{
switch(choix){

case 1:
 fflush(stdin);
    do{
    printf("\ntapez la taille(7/8/9) du mot le plus long a retrouve = ");
    scanf("\n%i",&taille);
    if((taille>9)||(taille<7)){
        printf("\n la taille que vous avez saisie est erronee !!!");
    }
    }while((taille>9)||(taille<7));

    srand(time(NULL));
    for( i = 1 ;i<=taille;i++){
        do{
    printf("caratere %i : consonne (c/C) ou Voyelle (v/V) = ",i);
    while(getchar()!='\n');
      r=getchar();
     aleatoireCV[i-1]=r;
        }while((aleatoireCV[i-1]!= 'c') && (aleatoireCV[i-1]!='C') &&(aleatoireCV[i-1]!='v') &&( aleatoireCV[i-1]!='V'));
    }

    for( i = 0 ; i<taille ; i++){
        if((aleatoireCV[i]== 'c')||(aleatoireCV[i]=='C')){
            motORD[i] = cons[rand() % 20];
        }
        else{
             motORD[i] = voyelle[rand() % 6];
        }
    }
    for( i=0;i<6; i++ ){
         printf("\n");
    }
     for( i = 0;i<taille;i++){
        printf("        %c ",motORD[i]);
     }

//lahna il utilisateur 3ta taille il kilma wil ordinateur cbon 7at il 7ourouf

//il matrix fih il kilmet ili ijou bil 7rouf ili 3tahom il ordinateur
    for (int i = 0; i < 336532; i++) {
        if (composerDE(words[i], motORD)) {
            strcpy(matrix[matrixIndex], words[i]);
            matrixIndex++;
        }
    }

    // ylawij 3ala atwil kilma
    for (int i = 0; i <= matrixIndex ; i++) {
        currentLength = strlen(matrix[i]);
        if (currentLength >= maxLength) {
            maxLength = currentLength;
            strcpy(longestWord, matrix[i]);
        }

    }
    printf("%s",longestWord);
         /** do{
                count=0;
  printf("\n -1 ");
    scanf("%s",&motutilisateur);
    strcpy(cputi,motutilisateur);
    for( i =0 ;i<taille;i++){
            for( j = 0;j<taille;j++){
        if(motutilisateur[j]==motORD[i]){
           motutilisateur[j]='0';
           count++;
        }
            }
    }
    }while (count != strlen(cputi));*/
do{
fflush(stdin);
 printf("\n - %i ",p);
    scanf("%s",&motutilisateur);
    for(i=0;i<strlen(motutilisateur);i++){
       motutilisateur[i]=toupper(motutilisateur[i]);
    }
    isFound=0;

        for (i = 0; i < matrixIndex; i++) {
            if (strcmp(motutilisateur, matrix[i]) == 0) {
                isFound = 1;
             break;
            }
        }
            if((isFound)&&(strcmp(motutilisateur, longestWord) == 0)) {
                     //itha ken l9aha yimchi ychoufha atwil kilma wale
                printf("Correct, c'est le plus long mot.\n");
                score = strlen(motutilisateur);
                printf("%s, (%i)\n", motutilisateur, score);
                strcpy(trys[K],motutilisateur);

                do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus long mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
                }


                  if((isFound)&& strcmp(motutilisateur, longestWord) != 0){
                    printf("Correct mais pas la plus longue.\n");
                    p++;
                    strcpy(trys[K],motutilisateur);
                    K++;

                }
             if(!isFound) {
                printf("Incorrect. Word not found in the matrix.\n");
                p++;

                }


            if((p>=taille)){
                printf("Les mots que vous avez trouvés sont corrects mais pas les plus longs:\n");
                for (i = 0; i < K; i++) {
                    printf("%s (%lu)\n", trys[i], strlen(trys[i]));
                }
                 do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus lang mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
            }
      } while ( p<taille && strcmp(motutilisateur,longestWord)!=0 );//<-- tal9a atwil  kilma wala houwa ho5rij
      for (int i = 0; i <= K; i++) {
        tm = strlen(trys[i]);
        if (tm >= tx) {
            tx = tm;
        }
    }
       printf("\n");
       printf("\n");
        printf("\n");
         printf("                                                              votre score est %i :",tx);
         printf("\n");
         printf("\n");
         printf("\n");
         printf("\n");



break;

case 2:
fflush(stdin);
    do{
    printf("\ntapez la taille(7/8/9) du mot le plus long a retrouve = ");
    scanf("\n%i",&taille);
    if((taille>9)||(taille<7)){
        printf("\n la taille que vous avez saisie est erronee !!!");
    }
    }while((taille>9)||(taille<7));

    srand(time(NULL));
    for( i = 1 ;i<=taille;i++){
        do{
    printf("caratere %i : consonne (c/C) ou Voyelle (v/V) = ",i);
    while(getchar()!='\n');
      r=getchar();
     aleatoireCV[i-1]=r;
        }while((aleatoireCV[i-1]!= 'c') && (aleatoireCV[i-1]!='C') &&(aleatoireCV[i-1]!='v') &&( aleatoireCV[i-1]!='V'));
    }

    for( i = 0 ; i<taille ; i++){
        if((aleatoireCV[i]== 'c')||(aleatoireCV[i]=='C')){
            motORD[i] = cons[rand() % 20];
        }
        else{
             motORD[i] = voyelle[rand() % 6];
        }
    }
    for( i=0;i<6; i++ ){
         printf("\n");
    }
     for( i = 0;i<taille;i++){
        printf("        %c ",motORD[i]);
     }

//lahna il utilisateur 3ta taille il kilma wil ordinateur cbon 7at il 7ourouf

//il matrix fih il kilmet ili ijou bil 7rouf ili 3tahom il ordinateur
    for (int i = 0; i < 336532; i++) {
        if (composerDE(words[i], motORD)) {
            strcpy(matrix[matrixIndex], words[i]);
            matrixIndex++;
        }
    }

    // ylawij 3ala atwil kilma
    for (int i = 0; i <= matrixIndex ; i++) {
        currentLength = strlen(matrix[i]);
        if (currentLength >= maxLength) {
            maxLength = currentLength;
            strcpy(longestWord, matrix[i]);
        }

    }
    printf("%s",longestWord);
do{
fflush(stdin);
deff=0;
start=clock();
 printf("\n - %i ",p);
    scanf("%s",&motutilisateur);
     for (int i = 0; motutilisateur[i] != '\0'; i++) {
        motutilisateur[i] = toupper(motutilisateur[i]);
    }
    isFound=0;
 fin=clock() ;
 deff=((float)fin-start) / CLOCKS_PER_SEC;
 te = taille*taille;
        for (i = 0; i < matrixIndex; i++) {
            if (strcmp(motutilisateur, matrix[i]) == 0) {
                isFound = 1;
             break;
            }
        }
            if((isFound)&&(strcmp(motutilisateur, longestWord) == 0)) {
                     //itha ken l9aha yimchi ychoufha atwil kilma wale
                printf("Correct, c'est le plus long mot.");
                if (deff > te) {
            printf("   mais vous avez depassez %i s !!",te);
             printf("(%f)",te);
        }
            else{
                do {
                    printf("Correct, c'est le plus long mot (%f)." ,deff);
                         score = strlen(motutilisateur);
                printf("%s, (%i)\n", motutilisateur, score);
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus long mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
                }
            }

                  if((isFound)&& strcmp(motutilisateur, longestWord) != 0){
                    printf("Correct mais pas la plus longue.");
                    p++;
                     if (deff < taille) {

           strcpy(trys[K],motutilisateur);
                    K++;
                    printf(" (%f)",deff);
        }
                        if (deff > taille) {
            printf("   mais vous avez depassez %i (%f S)  !!",taille,deff);
        }

                }


             if(!isFound) {
                    if(deff < taille){
                printf("Incorrect. Word not found in the matrix  (%f S) .\n",deff);
                    }
                p++;
                }
          if(p>=taille || (totaltemps> te)){
                 printf("Les mots que vous avez trouves sont corrects mais pas les plus longs:\n");
                for (i = 0; i < K; i++) {
                    printf("%s (%lu)\n", trys[i], strlen(trys[i]));
                }
                 do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus lang mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);

          }

      }while( (totaltemps< te) && p<taille && strcmp(motutilisateur,longestWord)!=0 );//<-- tal9a atwil  kilma wala houwa ho5rij

 for (int i = 0; i <= K; i++) {
        tm = strlen(trys[i]);
        if (tm >= tx) {
            tx = tm;
        }
    }
       printf("\n");
       printf("\n");
        printf("\n");
         printf("                                                              votre score est %i :",tx);
         printf("\n");
         printf("\n");
         printf("\n");
         printf("\n");

break;

case 3:
do{

    if((manche%2)!=0){
        fflush(stdin);
 printf("\n manche %i---------------------------------------------------------------------------------",manche);
    do{
    printf("\ntapez la taille du mot a retrouve elle doit etre paire  ");
    scanf("\n%i",&taille);
    if(taille>26){
        printf("\n dapasser la taille  !!!");
    }
    if(taille<0){
        printf("taille negatif !!!");
    }
    if(taille%2!=0){
         printf("taille impaire !!!il doit etre pair ");
    }
    }while(((taille>26))||(taille%2!=0)||(taille<0));

    srand(time(NULL));
    for( i = 1 ;i<=taille;i++){
        do{
    printf("caratere %i : consonne (c/C) ou Voyelle (v/V) = ",i);
    while(getchar()!='\n');
      r=getchar();
     aleatoireCV[i-1]=r;
        }while((aleatoireCV[i-1]!= 'c') && (aleatoireCV[i-1]!='C') &&(aleatoireCV[i-1]!='v') &&( aleatoireCV[i-1]!='V'));
    }

    for( i = 0 ; i<taille ; i++){
        if((aleatoireCV[i]== 'c')||(aleatoireCV[i]=='C')){
            motORD[i] = cons[rand() % 20];
        }
        else{
             motORD[i] = voyelle[rand() % 6];
        }
    }
    for( i=0;i<6; i++ ){
         printf("\n");
    }
     for( i = 0;i<taille;i++){
        printf("        %c ",motORD[i]);
     }


//il matrix fih il kilmet ili ijou bil 7rouf ili 3tahom il ordinateur
    for (int i = 0; i < 336532; i++) {
        if (composerDE(words[i], motORD)) {
            strcpy(matrix[matrixIndex], words[i]);
            matrixIndex++;
        }
    }

    // ylawij 3ala atwil kilma
    for (int i = 0; i <= matrixIndex ; i++) {
        currentLength = strlen(matrix[i]);
        if (currentLength >= maxLength) {
            maxLength = currentLength;
            strcpy(longestWord, matrix[i]);
        }

    }
printf("%s",longestWord);
 p=0;
 int f=0;
 char used [1000][27];
 int tst;
 int woh=1;//na9il wale
do{

//il p bich n5aleha ti7sib fil nbr mte3 il tantative
fflush(stdin);
isFound=0;
 printf("\n - j1 : ");
            scanf("%s",&motutilisateur);
 for (int i = 0; i < strlen(motutilisateur); ++i) {
        motutilisateur[i] = toupper(motutilisateur[i]);
    }
        for (i = 0; i < matrixIndex; i++) {
            if (strcmp(motutilisateur, matrix[i]) == 0) {
                isFound = 1;
             break;
            }
        }
        if(wsol=1){
        woh=1;
        i=0;
         do{
                tst=strcmp(used[i],motutilisateur);
                if(tst==0){
                    woh=0;
                }
                i++;
            }while((woh==1)&&(i<f));
        }
            if(woh==0){
        printf("autre joueur deja fait ");
        p++;
            }

    else{
            strcpy(used[f],motutilisateur);
             f++;
            if((isFound)&&(strcmp(motutilisateur, longestWord) == 0)) {
                     //itha ken l9aha yimchi ychoufha atwil kilma wale
                printf("Correct, c'est le plus long mot.\n");
                score = strlen(motutilisateur);
                printf("vous avez gagnee j1  ");
                printf("%s, (%i)\n", motutilisateur, score);
                 strcpy(trys[K],motutilisateur);


                do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus long mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
                }
                  if((isFound)&& strcmp(motutilisateur, longestWord) != 0){
                    printf("Correct mais pas la plus longue.\n");
                    p++;
                    strcpy(trys[K],motutilisateur);
                    K++;
                }
             if(!isFound) {
                printf("Incorrect. Word not found in the matrix.\n");
                p++;
                }
    }
                if(strcmp(motutilisateur,longestWord)!=0){
                fflush(stdin);
 printf("\n - j2 :");
            scanf("%s",&motutilisateur);
            for (int i = 0; i < strlen(motutilisateur); ++i) {
        motutilisateur[i] = toupper(motutilisateur[i]);
    }
            isFound=0;
        for (i = 0; i < matrixIndex; i++) {
            if (strcmp(motutilisateur, matrix[i]) == 0) {
                isFound = 1;
             break;
            }
        }
woh=1;
i=0;
wsol=1;
         do{
                tst=strcmp(used[i],motutilisateur);
                if(tst==0){
                    woh=0;
                }
                i++;
            }while((woh==1)&&(i<f));

            if(woh==0){
        printf("autre joueur deja fait ");
        p++;
            }
    else{
              strcpy(used[f],motutilisateur);
              f++;
            if((isFound)&&(strcmp(motutilisateur, longestWord) == 0)) {
                     //itha ken l9aha yimchi ychoufha atwil kilma wale
                printf("Correct, c'est le plus long mot.\n");
                score = strlen(motutilisateur);
                printf("vous avez gagnee j2 :");
                printf("%s, (%i)\n", motutilisateur, score);
                 strcpy(trys2[h],motutilisateur);

                do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus long mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
                }


                  if((isFound)&& strcmp(motutilisateur, longestWord) != 0){
                    printf("Correct mais pas la plus longue.\n");
                    p++;//3dad il mou7awalet
                    strcpy(trys2[h],motutilisateur);
                    h++;
                }
             if(!isFound) {
                printf("Incorrect. Word not found in the matrix.\n");
                p++;
                }
                }//mte3 il tst
                }

            if(p>=taille){
                printf("Les mots que vous avez trouvés sont corrects :\n");
               for ( i = 0; i<K; i++) {
                      printf("j1  :");
                    printf("%s (%lu)\n", trys[i], strlen(trys[i]));

                }
                  for ( i = 0; i < h; i++) {
                        printf("j2  :");
                    printf("%s (%lu)\n", trys2[i], strlen(trys2[i]));
                }
                 do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus lang mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                               case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
          }
}while( p<taille && strcmp(motutilisateur,longestWord)!=0 );
 for (int i = 0; i <= K; i++) {
        tm = strlen(trys[i]);
        if (tm >= tx) {
            tx = tm;
        }
    }
         printf("\n");
         printf("\n");
         printf("\n");
         printf("                                                              J1 score est :   %i ",tx);
         printf("\n");
         printf("\n");
         printf("\n");
         printf("\n");

for (int i = 0; i <= h; i++) {
        tm2 = strlen(trys2[i]);
        if (tm2 >= tx2) {
            tx2 = tm2;
        }
    }
         printf("\n");
         printf("\n");
         printf("\n");
         printf("                                                              J2 score est :   %i ",tx2);
         printf("\n");
         printf("\n");
         printf("\n");
         printf("\n");
TFmanche[li][0]=tx;
TFmanche[li][1]=tx2;
li++;
tx=0;
tx2=0;
tm=0;
tm2=0;
h=0;
K=0;
}
 if((manche%2)==0){

 printf("\n manche %i---------------------------------------------------------------------------------",manche);
    do{
    printf("\ntapez la taille du mot a retrouve elle doit etre paire  ");
    scanf("\n%i",&taille);
    if(taille>26){
        printf("\n dapasser la taille  !!!");
    }
    if(taille<0){
        printf("taille negatif !!!");
    }
    if(taille%2!=0){
         printf("taille impaire !!!il doit etre pair ");
    }
    }while(((taille>26))||(taille%2!=0)||(taille<0));

    srand(time(NULL));
    for( i = 1 ;i<=taille;i++){
        do{
    printf("caratere %i : consonne (c/C) ou Voyelle (v/V) = ",i);
    while(getchar()!='\n');
      r=getchar();
     aleatoireCV[i-1]=r;
        }while((aleatoireCV[i-1]!= 'c') && (aleatoireCV[i-1]!='C') &&(aleatoireCV[i-1]!='v') &&( aleatoireCV[i-1]!='V'));
    }

    for( i = 0 ; i<taille ; i++){
        if((aleatoireCV[i]== 'c')||(aleatoireCV[i]=='C')){
            motORD[i] = cons[rand() % 20];
        }
        else{
             motORD[i] = voyelle[rand() % 6];
        }
    }
    for( i=0;i<6; i++ ){
         printf("\n");
    }
     for( i = 0;i<taille;i++){
        printf("        %c ",motORD[i]);
     }


//il matrix fih il kilmet ili ijou bil 7rouf ili 3tahom il ordinateur
    for (int i = 0; i < 336532; i++) {
        if (composerDE(words[i], motORD)) {
            strcpy(matrix[matrixIndex], words[i]);
            matrixIndex++;
        }
    }

    // ylawij 3ala atwil kilma
    for (int i = 0; i <= matrixIndex ; i++) {
        currentLength = strlen(matrix[i]);
        if (currentLength >= maxLength) {
            maxLength = currentLength;
            strcpy(longestWord, matrix[i]);
        }

    }
printf("%s",longestWord);
 p=0;
  f=0;
  tst;
  woh=1;
do{

//il p bich n5aleha ti7sib fil nbr mte3 il tantative
fflush(stdin);
isFound=0;
 printf("\n - j2 : ");
            scanf("%s",&motutilisateur);
           for (int i = 0; i < strlen(motutilisateur); ++i) {
        motutilisateur[i] = toupper(motutilisateur[i]);
    }
        for (i = 0; i < matrixIndex; i++) {
            if (strcmp(motutilisateur, matrix[i]) == 0) {
                isFound = 1;
             break;
            }
        }
        if(wsol=1){
        woh=1;
        i=0;
         do{
                tst=strcmp(used[i],motutilisateur);
                if(tst==0){
                    woh=0;
                }
                i++;
            }while((woh==1)&&(i<f));
        }
            if(woh==0){
        printf("autre joueur deja fait ");
        p++;
            }

    else{
            strcpy(used[f],motutilisateur);
             f++;
            if((isFound)&&(strcmp(motutilisateur, longestWord) == 0)) {
                     //itha ken l9aha yimchi ychoufha atwil kilma wale
                printf("Correct, c'est le plus long mot.\n");
                score = strlen(motutilisateur);
                printf("vous avez gagnee j2  ");
                printf("%s, (%i)\n", motutilisateur, score);
                 strcpy(trys2[h],motutilisateur);


                do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus long mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
                }
                  if((isFound)&& strcmp(motutilisateur, longestWord) != 0){
                    printf("Correct mais pas la plus longue.\n");
                    p++;
                    strcpy(trys2[h],motutilisateur);
                    h++;
                }
             if(!isFound) {
                printf("Incorrect. Word not found in the matrix.\n");
                p++;
                }
    }
                if(strcmp(motutilisateur,longestWord)!=0){

 printf("\n - j1 :");
            scanf("%s",&motutilisateur);
            for (int i = 0; i < strlen(motutilisateur); ++i) {
        motutilisateur[i] = toupper(motutilisateur[i]);
    }
            isFound=0;
        for (i = 0; i < matrixIndex; i++) {
            if (strcmp(motutilisateur, matrix[i]) == 0) {
                isFound = 1;
             break;
            }
        }
woh=1;
i=0;
wsol=1;
         do{
                tst=strcmp(used[i],motutilisateur);
                if(tst==0){
                    woh=0;
                }
                i++;
            }while((woh==1)&&(i<f));

            if(woh==0){
        printf("autre joueur deja fait ");
        p++;
            }
    else{
              strcpy(used[f],motutilisateur);
              f++;
            if((isFound)&&(strcmp(motutilisateur, longestWord) == 0)) {
                     //itha ken l9aha yimchi ychoufha atwil kilma wale
                printf("Correct, c'est le plus long mot.\n");
                score = strlen(motutilisateur);
                printf("vous avez gagnee j1");
                printf("%s, (%i)\n", motutilisateur, score);
                 strcpy(trys[K],motutilisateur);

                do {
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus long mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                        case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
                }


                  if((isFound)&& strcmp(motutilisateur, longestWord) != 0){
                    printf("Correct mais pas la plus longue.\n");
                    p++;//3dad il mou7awalet
                    strcpy(trys[K],motutilisateur);
                    K++;
                }
             if(!isFound) {
                printf("Incorrect. Word not found in the matrix.\n");
                p++;
                }
                }//mte3 il tst
                }

            if(p>=taille){
                printf("Les mots que vous avez trouvés sont corrects:\n");
               for ( i = 0; i<h; i++) {
                      printf("j2  :");
                    printf("%s (%lu)\n", trys2[i], strlen(trys2[i]));

                }
                  for ( i = 0; i < K; i++) {
                        printf("j1 :");
                    printf("%s (%lu)\n", trys[i], strlen(trys[i]));
                }
                 do {
                        printf("\n");
                    printf("1- pour afficher tout les mots possibles\n2- pour afficher la plus lang mots\n");
                    scanf("%i", &choix2);

                    switch (choix2) {
                        case 1:
                            printf("Les choix possibles:\n");
                            for (int i = 0; i < matrixIndex; i++) {
                                printf("%s\n", matrix[i]);
                            }
                            break;
                               case 2:
                            printf("Longest Word: %s\n", longestWord);
                            break;
                    }
                } while (choix2 != 1 && choix2 != 2);
          }

}while( p<taille && strcmp(motutilisateur,longestWord)!=0 );

for(int i = 0; i <= h; i++) {
        tm2 = strlen(trys2[i]);
        if (tm2 >= tx2) {
            tx2 = tm2;
        }
    }
         printf("\n");
         printf("\n");
         printf("\n");
         printf("                                                              J2 score est :   %i ",tx2);
         printf("\n");
         printf("\n");
         printf("\n");
         printf("\n");

    for (int i = 0; i <= K; i++) {
        tm = strlen(trys[i]);
        if (tm >= tx) {
            tx = tm;
        }
    }
         printf("\n");
         printf("\n");
         printf("\n");
         printf("                                                              J1 score est :   %i ",tx);
         printf("\n");
         printf("\n");
         printf("\n");
         printf("\n");
TFmanche[li][0]=tx;
TFmanche[li][1]=tx2;
li++;
tx=0;
tm2=0;
tx2=0;
tm=0;
tm2=0;
K=0;
h=0;
}
 do{
    printf("vous voulez continuer ? si oui taper 'o',si non tapez 'n' ");
    while(getchar()!='\n');
      conti_ou_non=getchar();
        }while((conti_ou_non!= 'o')&&(conti_ou_non!='n'));

if(conti_ou_non =='o'){
    manche++;
    maxLength = 0;
    longestWord[0] = '\0';

K=0;
h=0;
p=0;
tx=0;
tx2=0;
tm=0;
tm2=0;
f=0;
matrixIndex=0;

}

}while(conti_ou_non=='o');




printf("joueur1           joueur2\n");
printf("----------------------------------------\n");
for(i=0;i<li;i++){
    printf("score manche %i\n",i+1);
    printf("   %i              %i\n",TFmanche[i][0],TFmanche[i][1]);
    final1=final1+TFmanche[i][0];
    final2=final2+TFmanche[i][1];
    printf("-----------------------------------\n");
}
printf("total \n");
printf("   %i             %i\n",final1,final2);
printf("-----------------------------------\n");
if(final1>final2){
    printf("joueur  1 wins");
}
if(final1<final2){
    printf("joueur  2 wins");
}
if(final1==final2){
    printf("egalite");
}

break;
}
fflush(stdin);

printf("\n");
printf("1- jouer a un \n");
    printf("2- jouer a un sous une contrainte de temps \n");
    printf("3- jouer a deux \n");
    printf("0- quitter\n");

    do{
    scanf("\n%i",&choix);
    printf("votre choix = %i",choix);
    }while((choix>3)||(choix<0));

p=0;
manche=1;
final1=0;
final2=0;
K=0;
h=0;
p=0;
tx=0;
tx2=0;
tm=0;
tm2=0;
li=0;
f=0;
fflush(stdin);
}while(choix!=0);//<--bich y3awid wale

return 0 ;
}

