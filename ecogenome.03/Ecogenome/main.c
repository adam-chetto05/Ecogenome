#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

struct admins admin[100];
int admin_number = 1;
int currentSize = 100;

void HandleMainSwitch(){
    printf("**menu**\n");
    printf("Search using ID: 1\n");
    printf("Search using IG: 2\n");
    printf("Add new admin or variety: 3\n");
    printf("Exit: 4\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 4) {
            printf("Invalid choice, please select between 1 and 4\n");
        }
        else
            printf("You selected: %d\n", choice);
        switch (choice) {
            case 1:
                printf("Searching using ID...\n");
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_Id(id);
                break;
            case 2:
                 printf("Searching using IG...\n");
                 int ig;
                 printf("Enter IG to search: ");
                 scanf("%d", &ig);
                 search_ig(ig);
                break;
            case 3:
                printf("Adding new variety or admin!\n");
                check_admin();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

        }
}


void WriteToFileE() {
    FILE *file = fopen("data.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d %d %s %s %s %s %d %d %d %s %d %s %d %d %d %d %d %s %d %d %.2f\n",
                S[currentSize].ID, S[currentSize].IG, S[currentSize].CROP, S[currentSize].DOI, S[currentSize].ORGINE, S[currentSize].Taxon, S[currentSize].Precocite,
                S[currentSize].Premieres_gousses, S[currentSize].Jours_maturite, S[currentSize].Couleur_fleur, S[currentSize].Intensite_stries_florales,
                S[currentSize].Couleur_aile_florale, S[currentSize].Nombre_fleur, S[currentSize].Nombre_branches, S[currentSize].Ramification_terminale,
                S[currentSize].Hauteur, S[currentSize].Vigueur_plante, S[currentSize].Couleur_gousse, S[currentSize].Longueur_gousses,
                S[currentSize].Nombre_graines_par_plante_individuelle, S[currentSize].Rendement_QdivHa);
        fclose(file);
        currentSize++;
    } else {
        printf("Error opening file\n");
    }
}


void WriteToFileA(char *nv_user,char *nv_mdp){
    FILE *file = fopen("admin.txt","a");
    if (file != NULL){
        fprintf(file, "%s %s \n", admin[admin_number].user_name , admin[admin_number].password);
        fclose(file);
    }else{
    printf("error opening file \n");
    }

}


int ReadFromFile(int id) {

    FILE *file = fopen("data.txt", "r");
    if (file != NULL) {
        int size = 0;
        while (fscanf(file, "%d %d %s %s %s %s %d %d %d %s %d %s %d %d %d %d %d %s %d %d %f",
                      &S[size].ID, &S[size].IG, S[size].CROP, S[size].DOI, S[size].ORGINE, &S[size].Taxon,
                      &S[size].Precocite, &S[size].Premieres_gousses, &S[size].Jours_maturite, S[size].Couleur_fleur,
                      &S[size].Intensite_stries_florales, S[size].Couleur_aile_florale, &S[size].Nombre_fleur,
                      &S[size].Nombre_branches, &S[size].Ramification_terminale, &S[size].Hauteur, &S[size].Vigueur_plante,
                      S[size].Couleur_gousse, &S[size].Longueur_gousses, &S[size].Nombre_graines_par_plante_individuelle,
                      &S[size].Rendement_QdivHa) == 21) {

                          if (S[size].ID == id){
                            printf(" id :%d \n ig :%d \n crop: %s \n doi :%s \n origine: %s \n taxon :%s \n Precocite :%d \n Premieres gousses :%d \n Jours maturite :%d \n Couleur fleur :%s \n Intensite des stries florales :%d \n Couleur de l'aile florale :%s \n Nombres des fleurs :%d \n Nombres des branches :%d \n Ramification terminale :%d \n Hauteur :%d \n Vigueurs des plantes :%d \n Couleur des gousses :%s \n Longueur des gousses :%d \n Nombres des graines par plantes individuelle :%d \n Rendement Q/Ha :%f \n ",
                            S[size].ID, S[size].IG, S[size].CROP, S[size].DOI, S[size].ORGINE, S[size].Taxon,
                            S[size].Precocite, S[size].Premieres_gousses, S[size].Jours_maturite, S[size].Couleur_fleur,
                            S[size].Intensite_stries_florales, S[size].Couleur_aile_florale, S[size].Nombre_fleur,
                            S[size].Nombre_branches, S[size].Ramification_terminale, S[size].Hauteur, S[size].Vigueur_plante,
                            S[size].Couleur_gousse, S[size].Longueur_gousses, S[size].Nombre_graines_par_plante_individuelle,
                            S[size].Rendement_QdivHa);
                            return 1;
                            break;
                          }

            size++;
        }

        fclose(file);
        currentSize = size + 100;
        return 0;
    } else {
        printf("Error opening file\n");
    }
}


void check_admin() {
    admin[0] = (struct admins){"admin", "admin"};
    char user[100], password[100];
    int i, size_admin, found;
    size_admin = admin_number;
    printf("Administrator required for this action \n");
    printf("username: ");
    scanf("%99s", user);
    printf("password: ");
    scanf("%99s", password);
    found = 0;
    for (i = 0; i < size_admin; i++) {
        int user_choice;
        if (strcmp(admin[i].user_name, user) == 0 && strcmp(admin[i].password, password) == 0) {
            found = 1;
            printf(" add new admin: 1 \n add new variety : 2 \n go back to menu : 3 \n ");
            scanf("%d", &user_choice);

            switch (user_choice) {
                case 1:
                    add_admin();
                    break;
                case 2:
                    ajout_espece();
                    break;
                case 3:
                    HandleMainSwitch();
                    break;
                default:
                    printf("invalid choice\n");
                    break;
            }
        }
     }   // ################################ zid i check admin wach kayn ta west file admin #######################################
    FILE *file = fopen("admin.txt","r");
    if (file != NULL){
        int found,size,user_choice;
        size = 0;
    while(fscanf(file,"%s %s",admin[size].user_name, admin[size].password)==2){
        if(strcmp(admin[size].user_name, user)==0 && strcmp(admin[size].password, password)==0 ){
            found = 1;
            printf(" add new admin: 1 \n add new variety : 2 \n go back to menu : 3 \n");
            scanf("%d", &user_choice);

            switch (user_choice) {
                case 1:
                    add_admin();
                    break;
                case 2:
                    ajout_espece();
                    break;
                case 3:
                    HandleMainSwitch();
                    break;
                default:
                    printf("invalid choice \n");
                    break;
            }
            fclose(file);
            return;
            }
            size++;
        }
        fclose(file);
    }

    if (!found){
        printf("username or password incorrect\n");
    }
}


void add_admin() {
    char nv_user[100], nv_mdp[100];

    printf(" Enter administrator username: \n");
    scanf("%99s", nv_user);
    printf(" Enter administrator password: \n");
    scanf("%99s", nv_mdp);
    if (admin_number < 100) {
        strncpy(admin[admin_number].user_name, nv_user, sizeof(admin[admin_number].user_name) - 1);
        admin[admin_number].user_name[sizeof(admin[admin_number].user_name) - 1] = '\0';
        strncpy(admin[admin_number].password, nv_mdp, sizeof(admin[admin_number].password) - 1);
        admin[admin_number].password[sizeof(admin[admin_number].password) - 1] = '\0';
        WriteToFileA(nv_user, nv_mdp);
        admin_number++;

    } else {
        printf("The maximum number of administrators has been reached. \n");
    }
}


void ajout_espece() {
    if (currentSize < 126) {
        printf("Please enter the following criteria in detail:\n");

        S[currentSize].ID = currentSize;

        printf("IG: ");
        scanf("%d", &S[currentSize].IG);

        printf("Precocite: ");
        scanf("%d", &S[currentSize].Precocite);

        printf("Premieres gousses: ");
        scanf("%d", &S[currentSize].Premieres_gousses);

        printf("Jours maturite: ");
        scanf("%d", &S[currentSize].Jours_maturite);

        printf("Intensite stries florales: ");
        scanf("%d", &S[currentSize].Intensite_stries_florales);

        printf("Nombre fleur: ");
        scanf("%d", &S[currentSize].Nombre_fleur);

        printf("Nombre branches: ");
        scanf("%d", &S[currentSize].Nombre_branches);

        printf("Ramification terminale: ");
        scanf("%d", &S[currentSize].Ramification_terminale);

        printf("Hauteur: ");
        scanf("%d", &S[currentSize].Hauteur);

        printf("Vigueur plante: ");
        scanf("%d", &S[currentSize].Vigueur_plante);

        printf("Longueur gousses: ");
        scanf("%d", &S[currentSize].Longueur_gousses);

        printf("Nombre de graines par plante individuelle: ");
        scanf("%d", &S[currentSize].Nombre_graines_par_plante_individuelle);

        printf("Rendement Q/Ha: ");
        scanf("%f", &S[currentSize].Rendement_QdivHa);

        printf("veuillez entre les phrase avec _ au lieu d'espace \n");

        printf("Taxon: ");
        scanf(" %s", S[currentSize].Taxon);

        printf("CROP: ");
        scanf(" %s", S[currentSize].CROP);

        printf("DOI: ");
        scanf(" %s", S[currentSize].DOI);

        printf("ORIGINE: ");
        scanf(" %s", S[currentSize].ORGINE);

        printf("Couleur fleur: ");
        scanf(" %s", S[currentSize].Couleur_fleur);

        printf("Couleur de l'aile florale: ");
        scanf(" %s", S[currentSize].Couleur_aile_florale);

        printf("Couleur de gousse: ");
        scanf(" %s", S[currentSize].Couleur_gousse);

        char assurance;
        printf("Are you sure the information is correct? y/n: ");
        scanf(" %c", &assurance);

        if (assurance == 'y' || assurance == 'Y') {
            WriteToFileE();
        } else {
            printf("Please proceed with the procedure\n");
            ajout_espece();
        }
    } else {
        printf("Database full \n");
    }
}


void search_Id(int id){
    int size = (sizeof(S) / sizeof(S[0]));
    int debut = 0;
    int fin = size - 1;
    int milieu;
    int found =0;

    while (debut <= fin){
        milieu = (debut + fin) / 2;

        if (S[milieu].ID ==id){
            printf(" id : %d \n ig : %d \n crop : %s \n doi : %s \n origine : %s \n taxon : %s \n Precocite : %d \n Premieres gousses : %d \n Jours maturite : %d \n Couleur fleur : %s \n Intensite stries florales : %d \n Couleur de l'aile florale : %s \n Nombres des fleurs : %d \n Nombres des branches : %d \n Ramification terminale : %d \n Hauteur : %d \n Vigueurs des plantes : %d \n Couleur des gousses : %s \n Longueur des gousses : %d \n Nombres des graines par plantes individuelle : %d \n Rendement Q/Ha : %.2f \n ",
            S[id].ID, S[id].IG, S[id].CROP, S[id].DOI, S[id].ORGINE, S[id].Taxon,
            S[id].Precocite, S[id].Premieres_gousses, S[id].Jours_maturite, S[id].Couleur_fleur,
            S[id].Intensite_stries_florales, S[id].Couleur_aile_florale, S[id].Nombre_fleur,
            S[id].Nombre_branches, S[id].Ramification_terminale, S[id].Hauteur, S[id].Vigueur_plante,
            S[id].Couleur_gousse, S[id].Longueur_gousses, S[id].Nombre_graines_par_plante_individuelle,
            S[id].Rendement_QdivHa);
            found = 1;
            return;
        }
        else if (S[milieu].ID < id){
            debut = milieu + 1;
        }
        else {
            fin = milieu - 1;
        }
    }
        if(!found){
          /*  printf("id not found \n");
              int choice;
              printf("Are you looking to search in an external file 1: yes \t 2: no\n");
            scanf("%d",&choice);
            if (choice == 1){}*/
                found = ReadFromFile(id);

        }
        if(!found) {
            printf("The ID you are looking for does not exist \n");
        }
        return;
    }


void search_ig(int ig){
    int found;
    int size = sizeof(S) / sizeof(S[0]);
    int i;
    for (i=0 ; i < size ; i++){
        if (S[i].IG == ig){
            found = 1;
            printf(" id : %d \n ig : %d \n crop : %s \n doi : %s \n origine : %s \n taxon : %s \n Precocite : %d \n Premieres gousses : %d \n Jours maturite : %d \n Couleur fleur : %s \n Intensite stries florales : %d \n Couleur de l'aile florale : %s \n Nombres des fleurs : %d \n Nombres des branches : %d \n Ramification terminale : %d \n Hauteur : %d \n Vigueurs des plantes : %d \n Couleur des gousses : %s \n Longueur des gousses : %d \n Nombres des graines par plantes individuelle : %d \n Rendement Q/Ha : %.2f \n ",
            S[i].ID, S[i].IG, S[i].CROP, S[i].DOI, S[i].ORGINE, S[i].Taxon,
            S[i].Precocite, S[i].Premieres_gousses, S[i].Jours_maturite, S[i].Couleur_fleur,
            S[i].Intensite_stries_florales, S[i].Couleur_aile_florale, S[i].Nombre_fleur,
            S[i].Nombre_branches, S[i].Ramification_terminale, S[i].Hauteur, S[i].Vigueur_plante,
            S[i].Couleur_gousse, S[i].Longueur_gousses, S[i].Nombre_graines_par_plante_individuelle,
            S[i].Rendement_QdivHa);
            break;
            return;
        }
    }
        if(!found) {
            printf("If the ID you just entered does not exist, please make sure there are no errors. \n");
  }
}

int main() {

int admin_number = 1;
    S[0] =  (struct data){1, 11283 , .CROP ="ILB", "10.18730/5ZR70", "AFG", "vicia faba equina", 42, 41, 93, "blanc", 3, "violet fonce", 9, 11, 15, 95, 5, "noir", 14, 223, 67};
    S[1] =  (struct data){1, 11283 , .CROP ="ILB", "10.18730/5ZR70", "AFG", "vicia faba equina", 42, 41, 93, "blanc", 3, "violet fonce", 9, 11, 15, 95, 5, "noir", 14, 223, 67};
    S[2] =  (struct data){2, 11285 , .CROP ="ILB", "10.18730/5ZR81", "AFG", "vicia faba major", 73, 89, 160, "blanc", 5, "violet fonce", 19, 18, 20, 160, 9, "noir", 20, 365, 95};
    S[3] =  (struct data){3, 11310 , .CROP ="ILB", "10.18730/5ZRWN", "AFG", "vicia faba minor", 23, 19, 56, "blanc", 1, "violet fonce", 4, 5, 7,65 , 6, "noire", 9, 126, 39};
    S[4] =  (struct data){4, 11657 , .CROP ="ILB", "10.18730/602H$", "AFG", "vicia faba equina", 48, 51, 103, "blanc", 3, "violet fonce", 11, 13, 14, 99, 6, "noir", 15, 249, 73};
    S[5] =  (struct data){5, 11725 , .CROP ="ILB", "10.18730/604KT", "AFG", "vicia faba major", 68, 73, 158, "blanc", 5, "violet fonce", 17, 16, 14, 158, 7, "noir", 16, 354, 92};
    S[6] =  (struct data){6, 11727 , .CROP ="ILB", "10.18730/604NW", "AFG", "vicia faba minor", 29, 25, 66, "blanc", 1, "violet fonce", 5, 8, 7, 10, 63, "noir", 12, 135, 41};
    S[7] =  (struct data){7, 12142 , .CROP ="ILB", "10.18730/60FQC", "AFG", "vicia faba major", 77, 83, 154, "blanc", 5, "violet fonce", 17, 15, 19, 155, 9, "noir", 17, 372, 95};
    S[8] =  (struct data){8, 11779 , .CROP ="ILB", "10.18730/60630", "CAN", "vicia faba equina", 58, 49, 109, "blanc", 3, "violet fonce", 12, 11, 10, 98, 6, "noir", 12, 208, 53};
    S[9] =  (struct data){9, 11820, .CROP ="ILB", "10.18730/607A2", "CAN", "vicia faba major", 76, 85, 161, "blanc", 5, "violet fonce", 16,  19, 15, 155, 8, "noir", 18, 367, 88};
    S[10] = (struct data){10,11843, .CROP ="ILB", "10.18730/6081S", "CAN", "vicia faba equina", 49, 58, 102, "blanc", 5, "violet fonce", 10, 9, 12, 101, 5, "noir", 11, 203, 51};
    S[11] = (struct data){11,11863, .CROP ="ILB", "10.18730/608H4", "CAN", "vicia faba major", 61, 68, 143, "blanc", 5, "violet fonce", 15, 16, 17, 151, 8, "noir", 19, 327, 76};
    S[12] = (struct data){12,11522, .CROP ="ILB", "10.18730/5ZYZZ", "CHN", "vicia faba equina", 47, 52, 105, "blanc", 3, "violet fonce", 10, 14, 11, 91, 7, "noir", 13, 235, 59};
    S[13] = (struct data){13,13811, .CROP ="ILB", "10.18730/61R4A", "CHN", "vicia faba minor", 29, 32, 47, "blanc", 1, "violet fonce", 8, 6, 9,67 , 7, "noir", 11, 17, 49};
    S[14] = (struct data){14,13814, .CROP ="ILB", "10.18730/61R7D", "CHN", "vicia faba equina", 58, 49, 109, "blanc", 3, "violet fonce", 12, 11, 10, 98, 6, "noir", 12, 208, 51};
    S[15] = (struct data){15,13815, .CROP ="ILB", "10.18730/61R8E", "CHN", "vicia faba major", 69, 75, 160, "blanc", 5, "violet fonce", 15,  17, 14, 150, 8, "noir", 16, 357, 81};
    S[16] = (struct data){16, 13971, .CROP ="ILB", "10.18730/61WSB", "CHN",  "vicia faba major", 76, 85, 161, "blanc", 5, "violet fonce", 16,  19, 15, 155, 8, "noir", 18, 367, 88};
    S[17] = (struct data){17, 14202, .CROP ="ILB", "10.18730/622RH", "CHN", "vicia faba equina", 48, 46, 102, "blanc", 3, "violet fonce", 10, 12, 11, 102, 6, "noir", 11, 213, 59};
    S[18] = (struct data){18, 14205, .CROP ="ILB", "10.18730/622TK", "CHN", "vicia faba major", 72, 88, 170, "blanc", 5, "violet fonce", 17,  16, 17, 159, 9, "noir", 18, 372, 88};
    S[19] = (struct data){19, 14322, .CROP ="ILB", "10.18730/6261B", "CHN", "vicia faba minor", 27, 23, 67, "blanc", 1, "violet fonce", 5, 9, 5,66 , 3, "noire", 9, 134, 41};
    S[20] = (struct data){20, 14323, .CROP ="ILB", "10.18730/6262C", "CHN", "vicia faba major", 88, 91, 172, "blanc", 5, "violet fonce", 17,  16, 17, 164, 8, "noir", 18, 372, 91};
    S[21] = (struct data){21, 14332, .CROP ="ILB", "10.18730/626BN", "CHN", "vicia faba major", 76, 88, 175, "blanc", 5, "violet fonce", 16, 14, 17, 166, 8, "noir", 19, 377, 88};
    S[22] = (struct data){22, 14336, .CROP ="ILB", "10.18730/626FS", "CHN", "vicia faba minor", 22, 20, 55, "blanc", 1, "violet fonce", 3, 6, 4,55 , 3, "noir", 7, 122, 33};
    S[23] = (struct data){23, 14337, .CROP ="ILB", "10.18730/626GT", "CHN", "vicia faba equina", 54, 51, 105, "blanc", 3, "violet fonce", 13, 10, 12, 94, 6, "noir", 11, 224, 56};
    S[24] = (struct data){24, 70620, .CROP ="ILB", "10.18730/7PN8P", "CHN", "vicia faba minor", 28, 29, 43, "blanc", 1, "violet fonce", 4, 5, 7,62 , 6, "noir", 9, 126, 44};
    S[25] = (struct data){25, 70621, .CROP ="ILB", "10.18730/7PN9Q", "CHN", "vicia faba major", 65, 77, 166, "blanc", 5, "violet fonce", 15,  17, 18, 164, 8, "noir", 17, 367, 84};
    S[26] = (struct data){26, 72218, .CROP ="ILB", "10.18730/7R573", "CHN", "vicia faba equina", 47, 54, 108, "blanc", 5, "violet fonce", 12, 11, 10, 121, 5, "noir", 12, 224, 59};
    S[27] = (struct data){27, 72220, .CROP ="ILB", "10.18730/7R5A6", "CHN", "vicia faba equina", 58, 49, 109, "blanc", 3, "violet fonce", 12, 11, 10, 98, 6, "noir", 12, 208, 53};
    S[29] = (struct data){29, 72223, .CROP ="ILB", "10.18730/7R5C8", "CHN", "vicia faba major", 61, 75, 160, "blanc", 5, "violet fonce", 11,  15, 17, 169, 9, "noir", 18, 387, 94};
    S[30] = (struct data){30, 72224, .CROP ="ILB", "10.18730/7R5D9", "CHN", "vicia faba major", 71, 84, 166, "blanc", 5, "violet fonce", 15,  18, 16, 166, 8, "noir", 18, 371, 87};
    S[31] = (struct data){31, 72226, .CROP ="ILB", "10.18730/7R5FB", "CHN", "vicia faba major", 82, 89, 159, "blanc", 5, "violet fonce", 16,  18, 16, 167, 9, "noir", 18, 372, 88};
    S[32] = (struct data){32, 72227, .CROP ="ILB", "10.18730/7R5GC", "CHN", "vicia faba equina", 52, 44, 101, "blanc", 3, "violet fonce", 10, 12, 11, 100, 5, "noir", 11, 219, 59};
    S[33] = (struct data){33, 99322, .CROP ="ILB", "10.18730/8G3PU", "CHN", "vicia faba major", 77, 88, 162, "blanc", 5, "violet fonce", 18, 17, 19, 149, 8, "noir", 19, 330, 86};
    S[34] = (struct data){34, 99324, .CROP ="ILB", "10.18730/8G3R1", "CHN", "vicia faba major", 61, 68, 143, "blanc", 5, "violet fonce", 15, 16, 17, 151, 8, "noir", 19, 327, 76};
    S[35] = (struct data){35, 12424, .CROP ="ILB", "10.18730/944ZP", "CHN", "vicia faba minor", 37, 39, 48, "blanc", 1, "violet fonce", 7, 9, 10,69 , 7, "noir", 7, 116, 40};
    S[36] = (struct data){36, 11505, .CROP ="ILB", "10.18730/5ZYGG", "DEU", "vicia faba minor", 31, 33, 44, "blanc", 1, "violet fonce", 6, 7, 8,65 , 5, "noir", 11, 113, 49};
    S[37] = (struct data){37, 12882, .CROP ="ILB", "10.18730/6118J", "DEU", "vicia faba equina", 58, 61, 112, "blanc", 3, "violet fonce", 13, 10, 12, 94, 5, "noir", 12, 244, 66};
    S[38] = (struct data){38, 12945, .CROP ="ILB", "10.18730/612MS", "DEU", "vicia faba major", 67, 71, 183, "blanc", 5, "violet fonce", 19, 17, 18, 180, 9, "noir", 19, 397, 98};
    S[40] = (struct data){40, 12974, .CROP ="ILB", "10.18730/61333", "DEU", "vicia faba major", 79, 85, 167, "blanc", 5, "violet fonce", 16,  19, 15, 155, 8, "noir", 18, 367, 85};
    S[41] = (struct data){41, 12976, .CROP ="ILB", "10.18730/61355", "DEU", "vicia faba minor", 22, 20, 55, "blanc", 1, "violet fonce", 5, 7, 6,59 , 4, "noir", 7, 132, 43};
    S[42] = (struct data){42, 12979, .CROP ="ILB", "10.18730/61388", "DEU", "vicia faba major", 72, 81, 160, "blanc", 5, "violet fonce", 14,  18, 15, 151, 8, "noir", 18, 361, 81};
    S[43] = (struct data){43, 13251, .CROP ="ILB", "10.18730/618P$", "DEU", "vicia faba equina", 55, 52, 101, "blanc", 3, "violet fonce", 11, 12, 14, 101, 6, "noir", 11, 242, 61};
    S[44] = (struct data){44, 14277, .CROP ="ILB", "10.18730/624WB", "ECU", "vicia faba equina", 54, 59, 115, "blanc", 3, "violet fonce", 11, 10, 12, 98, 6, "noir", 12, 208, 51};
    S[45] = (struct data){45, 117988, .CROP ="ILB", "10.18730/8YRXX","ECU", "vicia faba major", 75, 78, 163, "blanc", 5, "violet fonce", 18, 15, 19, 168, 9, "noir", 19, 367, 96};
    S[46] = (struct data){46, 117989, .CROP ="ILB", "10.18730/8YRYY","ECU", "vicia faba minor", 19, 22, 41, "blanc", 1, "violet fonce", 2, 4, 5,41 , 3, "noir", 5, 101, 23};
    S[47] = (struct data){47, 124723, .CROP ="ILB", "10.18730/94K2X","ECU", "vicia faba equina", 54, 51, 105, "blanc", 3, "violet fonce", 13, 10, 12, 94, 6, "noir", 11, 224, 56};
    S[48] = (struct data){48, 155357, .CROP ="ILB", "10.18730/AAQGB","ECU", "vicia faba minor", 22, 23, 60, "blanc", 1, "violet fonce", 4, 7, 6, 11, 61, "noir", 10, 129, 41};
    S[49] = (struct data){49, 11456, .CROP ="ILB", "10.18730/5ZX27","ESP",  "vicia faba major", 77, 77, 159, "blanc", 5, "violet fonce", 18,  19, 16, 167, 8, "noir", 18, 377, 79};
    S[50] = (struct data){50, 11462, .CROP ="ILB", "10.18730/5ZX8D","ESP",  "vicia faba major", 66, 61, 123, "blanc", 5, "violet fonce", 15, 17, 17, 161, 9, "noir", 19, 387, 89};
    S[51] = (struct data){51, 13576, .CROP ="ILB", "10.18730/61GX1", "ESP", "vicia faba equina", 59, 57, 119, "blanc", 3, "violet fonce", 11, 13, 12, 113, 7, "noir", 13, 221, 63};
    S[52] = (struct data){52, 13580, .CROP ="ILB", "10.18730/61H15", "ESP", "vicia faba minor", 27, 25, 61, "blanc", 1, "violet fonce", 7, 6, 7, 10, 73, "noir", 11, 78, 38};
    S[53] = (struct data){53, 13585, .CROP ="ILB", "10.18730/61H59", "ESP", "vicia faba major", 77, 75, 159, "blanc", 5, "violet fonce", 4,  17, 16, 161, 9, "noir", 19, 392, 90};
    S[54] = (struct data){54, 13587, .CROP ="ILB", "10.18730/61H7B", "ESP", "vicia faba major", 70, 71, 159, "blanc", 5, "violet fonce", 17, 16, 18, 181, 7, "noir", 15, 371, 87};
    S[55] = (struct data){55, 13599, .CROP ="ILB", "10.18730/61HHN", "ESP", "vicia faba minor", 27, 22, 51, "blanc", 1, "violet fonce", 7, 6, 5,66 , 5, "noir", 6, 102, 47};
    S[56] = (struct data){56, 13602, .CROP ="ILB", "10.18730/61HMR", "ESP", "vicia faba equina", 57, 50, 101, "blanc", 3, "violet fonce", 11, 12, 10, 100, 6, "noir", 10, 229, 64};
    S[57] = (struct data){57, 13622, .CROP ="ILB", "10.18730/61J87", "ESP", "vicia faba equina", 56, 50, 101, "blanc", 3, "violet fonce", 11, 12, 10, 101, 7, "noir", 12, 237, 61};
    S[58] = (struct data){58, 13824, .CROP ="ILB", "10.18730/61RFN", "ESP", "vicia faba minor", 27, 18, 52, "blanc", 1, "violet fonce", 6, 7, 9,78 , 6, "noire", 10, 116, 49};
    S[59] = (struct data){59, 14001, .CROP ="ILB", "10.18730/61XN2", "ESP", "vicia faba equina", 44, 51, 111, "blanc", 3, "violet fonce", 11, 10, 3, 118, 6, "noir", 12, 254, 63};
    S[60] = (struct data){60, 74105, .CROP ="ILB", "10.18730/7ST4Z", "ESP", "vicia faba major", 75, 78, 163, "blanc", 5, "violet fonce", 18, 15, 19, 168, 9, "noir", 19, 367, 96};
    S[61] = (struct data){61, 74108, .CROP ="ILB", "10.18730/7ST7$", "ESP", "vicia faba equina", 52, 48, 101, "blanc", 3, "violet fonce", 11, 10, 9, 99, 5, "noir", 10, 231, 59};
    S[62] = (struct data){62, 74109, .CROP ="ILB", "10.18730/7ST8=", "ESP", "vicia faba major", 81, 75, 173, "blanc", 5, "violet fonce", 16, 16, 18, 162, 7, "noir", 15, 363, 76};
    S[63] = (struct data){63, 74113, .CROP ="ILB", "10.18730/7STB1", "ESP", "vicia faba equina", 52, 58, 99, "blanc", 3, "violet fonce", 10, 11, 12, 112, 5, "noir", 12, 254, 65};
    S[64] = (struct data){64, 74116, .CROP ="ILB", "10.18730/7STE4", "ESP", "vicia faba major", 71, 81, 169, "blanc", 5, "violet fonce", 18,  17, 16, 171, 9, "noir", 18, 384, 94};
    S[65] = (struct data){65, 74120, .CROP ="ILB", "10.18730/7STH7", "ESP", "vicia faba minor", 25, 23, 55, "blanc", 1, "violet fonce", 8, 6, 5,61 , 5, "noir", 11, 87, 48};
    S[66] = (struct data){66, 74125, .CROP ="ILB", "10.18730/7STPC", "ESP", "vicia faba minor", 22, 27, 46, "blanc", 1, "violet fonce", 6, 7, 4,49 , 3, "noir", 9, 85, 32};
    S[67] = (struct data){67, 74140, .CROP ="ILB", "10.18730/7SV0P", "ESP", "vicia faba minor", 33, 29, 88, "blanc", 1, "violet fonce", 7, 9, 5,65 , 3, "noire", 10, 124, 44};
    S[68] = (struct data){68, 74155, .CROP ="ILB", "10.18730/7SVA*", "ESP", "vicia faba major", 75, 84, 171, "blanc", 5, "violet fonce", 15,  17, 16, 161, 8, "noir", 17, 361, 82};
    S[69] = (struct data){69, 74157, .CROP ="ILB", "10.18730/7SVB~", "ESP", "vicia faba equina", 51, 59, 115, "blanc", 3, "violet fonce", 13, 12, 14, 104, 6, "noir", 10, 235, 59};
    S[70] = (struct data){70, 74161, .CROP ="ILB", "10.18730/7SVD=", "ESP", "vicia faba minor", 26, 35, 58, "blanc", 1, "violet fonce", 6, 7, 9, 11, 85, "noir", 10, 123, 48};
    S[71] = (struct data){71, 74167, .CROP ="ILB", "10.18730/7SVJ3", "ESP", "vicia faba major", 77, 75, 159, "blanc", 5, "violet fonce", 4,  17, 16, 161, 9, "noir", 19, 392, 90};
    S[72] = (struct data){72, 74168, .CROP ="ILB", "10.18730/7SVK4", "ESP", "vicia faba equina", 53, 52, 111, "blanc", 3, "violet fonce", 11, 10, 12, 180, 6, "noir", 13, 274, 69};
    S[73] = (struct data){73, 74174, .CROP ="ILB", "10.18730/7SVR9", "ESP", "vicia faba equina", 53, 49, 103, "blanc", 3, "violet fonce", 11, 13, 10, 108, 6, "noir", 10, 288, 65};
    S[74] = (struct data){74, 100171, .CROP ="ILB", "10.18730/8GXSM", "ESP","vicia faba major", 78, 76, 166, "blanc", 5, "violet fonce", 18, 16, 17, 168, 8, "noir", 17, 379, 83};
    S[75] = (struct data){75, 11344, .CROP ="ILB", "10.18730/5ZZ89", "ETR", "vicia faba major", 77, 84, 164, "blanc", 5, "violet fonce", 17, 15, 19, 165, 9, "noir", 19, 385, 92};
    S[76] = (struct data){76, 11355, .CROP ="ILB", "10.18730/5ZZG8", "ETR", "vicia faba minor", 21, 28, 49, "blanc", 1, "violet fonce", 6, 8, 5,55 , 45, "noir", 6, 122, 52};
    S[77] = (struct data){77, 11357, .CROP ="ILB", "10.18730/5ZZJ0", "ETR", "vicia faba major", 82, 73, 169, "blanc", 5, "violet fonce", 17, 18, 16, 178, 8, "noir", 16, 389, 93};
    S[78] = (struct data){78, 11359, .CROP ="ILB", "10.18730/5ZZK2", "ETR", "vicia faba minor", 23, 28, 77, "blanc", 1, "violet fonce", 9, 8, 6, 11, 77, "noir", 13, 89, 43};
    S[79] = (struct data){79, 11361, .CROP ="ILB", "10.18730/5ZZM5", "ETR", "vicia faba minor", 29, 25, 66, "blanc", 1, "violet fonce", 5, 8, 7, 10, 63, "noir", 12, 135, 41};
    S[80] = (struct data){80, 11363, .CROP ="ILB", "10.18730/5ZZP8", "ETR", "vicia faba equina", 56, 47, 106, "blanc", 3, "violet fonce", 10, 11, 12, 112, 6, "noir", 12, 301, 65};
    S[81] = (struct data){81, 11368, .CROP ="ILB", "10.18730/5ZZR4", "ETR", "vicia faba major", 84, 77, 163, "blanc", 5, "violet fonce", 17, 16, 18, 162, 8, "noir", 17, 343, 82};
    S[82] = (struct data){82, 11371, .CROP ="ILB", "10.18730/5ZZV0", "ETR", "vicia faba equina", 53, 51, 100, "blanc", 3, "violet fonce", 11, 10, 12, 112, 6, "noir", 13, 243, 63};
    S[83] = (struct data){83, 11373, .CROP ="ILB", "10.18730/5ZZX6", "ETR", "vicia faba major", 79, 74, 167, "blanc", 5, "violet fonce", 17, 18, 19, 169, 8, "noir", 18, 348, 83};
    S[84] = (struct data){84, 11376, .CROP ="ILB", "10.18730/5ZZZ2", "ETR", "vicia faba minor", 28, 29, 66, "blanc", 1, "violet fonce", 5, 8, 7, 10, 72, "noir", 10, 149, 48};
    S[85] = (struct data){85, 11379, .CROP ="ILB", "10.18730/60034", "ETR", "vicia faba minor", 29, 31, 59, "blanc", 1, "violet fonce", 5, 8, 9,68 , 4, "noir", 6, 107, 39};
    S[86] = (struct data){86, 11380, .CROP ="ILB", "10.18730/60056", "ETR", "vicia faba major", 69, 77, 169, "blanc", 5, "violet fonce", 18,  16, 17, 171, 9, "noir", 19, 392, 95};
    S[87] = (struct data){87, 11382, .CROP ="ILB", "10.18730/60069", "ETR", "vicia faba equina", 55, 52, 108, "blanc", 3, "violet fonce", 10, 12, 11, 111, 6, "noir", 12, 289, 62};
    S[88] = (struct data){88, 11386, .CROP ="ILB", "10.18730/600B0", "ETR", "vicia faba major", 65, 68, 153, "blanc", 5, "violet fonce", 16, 14, 17, 158, 9, "noir", 18, 377, 91};
    S[89] = (struct data){89, 11389, .CROP ="ILB", "10.18730/600D4", "ETR", "vicia faba equina", 55, 51, 104, "blanc", 3, "violet fonce", 12, 11, 12, 112, 7, "noir", 12, 298, 75};
    S[90] = (struct data){90, 11394, .CROP ="ILB", "10.18730/600H8", "ETR", "vicia faba equina", 42, 50, 101, "blanc", 3, "violet fonce", 10, 12, 11, 138, 6, "noir", 12, 294, 66};
    S[91] = (struct data){91, 11395, .CROP ="ILB", "10.18730/600K0", "ETR", "vicia faba major", 79, 72, 169, "blanc", 5, "violet fonce", 18,  17, 16, 168, 9, "noir", 18, 382, 88};
    S[92] = (struct data){92, 11400, .CROP ="ILB", "10.18730/600N7", "ETR", "vicia faba minor", 33, 35, 55, "blanc", 1, "violet fonce", 8, 4, 6,59 , 5, "noir", 6, 102, 42};
    S[93] = (struct data){93, 11404, .CROP ="ILB", "10.18730/600Q2", "ETR", "vicia faba equina", 54, 49, 112, "blanc", 3, "violet fonce", 11, 10, 12, 111, 5, "noir", 12, 235, 57};
    S[94] = (struct data){94, 11409, .CROP ="ILB", "10.18730/600T6", "ETR", "vicia faba minor", 32, 29, 67, "blanc", 1, "violet fonce", 9, 7, 6, 9, 53, "noir", 10, 125, 44};
    S[95] = (struct data){95, 11410, .CROP ="ILB", "10.18730/600V1", "ETR", "vicia faba equina", 54, 45, 101, "blanc", 3, "violet fonce", 10, 9, 11, 107, 6, "noir", 10, 211, 55};
    S[96] = (struct data){96, 11411, .CROP ="ILB", "10.18730/600W4", "ETR", "vicia faba major", 74, 82, 179, "blanc", 5, "violet fonce", 17,  16, 18, 188, 9, "noir", 19, 392, 96};
    S[97] = (struct data){97, 11412, .CROP ="ILB", "10.18730/600X6", "ETR", "vicia faba minor", 30, 35, 42, "blanc", 1, "violet fonce", 7, 9, 10,68 , 5, "noir", 9, 89, 37};
    S[98] = (struct data){98, 11413, .CROP ="ILB", "10.18730/600Y8", "ETR", "vicia faba major", 71, 75, 173, "blanc", 5, "violet fonce", 18,  15, 17, 189, 9, "noir", 19, 377, 92};
    S[99] = (struct data){99, 11415, .CROP ="ILB", "10.18730/60100", "ETR", "vicia faba equina", 46, 52, 122, "blanc", 3, "violet fonce", 11, 13, 12, 148, 7, "noir", 13, 303, 69};

// main menu
printf("Hello dear user! \nPlease select an option:\n");



HandleMainSwitch();

int choice_user;

printf("If you want to continue: 1\nTo exit the program: 2\n");
scanf("%d", &choice_user);


do {
    HandleMainSwitch();
}while(choice_user !=2);
}
