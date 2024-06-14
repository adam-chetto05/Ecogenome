#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

struct admins admin[100];
int admin_number = 1;
int currentSize = 100;

void WriteToFileE() {
    FILE *file = fopen("data.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d %d %d %s %s %d %d %d %d %s %d %s %d %d %d %d %d %s %d %d %.2f\n",
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
void ReadFromFile(int id) {

    FILE *file = fopen("data.txt", "r");
    if (file != NULL) {
        int size = 0;
        while (fscanf(file, "%d %d %s %s %s %d %d %d %d %s %d %s %d %d %d %d %d %s %d %d %f",
                      &S[size].ID, &S[size].IG, S[size].CROP, S[size].DOI, S[size].ORGINE, &S[size].Taxon,
                      &S[size].Precocite, &S[size].Premieres_gousses, &S[size].Jours_maturite, S[size].Couleur_fleur,
                      &S[size].Intensite_stries_florales, S[size].Couleur_aile_florale, &S[size].Nombre_fleur,
                      &S[size].Nombre_branches, &S[size].Ramification_terminale, &S[size].Hauteur, &S[size].Vigueur_plante,
                      S[size].Couleur_gousse, &S[size].Longueur_gousses, &S[size].Nombre_graines_par_plante_individuelle,
                      &S[size].Rendement_QdivHa) == 21) {

                          if (S[size].ID == id){
                            printf(" id :%d \n ig :%d \n crop: %s \n doi :%s \n origine: %s \n taxon :%d \n Precocite :%d \n Premieres gousses :%d \n %d \n %s \n %d \n %s \n %d \n %d \n %d \n %d \n %d \n %s \n %d \n %d \n %f \n ",
                            S[size].ID, S[size].IG, S[size].CROP, S[size].DOI, S[size].ORGINE, S[size].Taxon,
                            S[size].Precocite, S[size].Premieres_gousses, S[size].Jours_maturite, S[size].Couleur_fleur,
                            S[size].Intensite_stries_florales, S[size].Couleur_aile_florale, S[size].Nombre_fleur,
                            S[size].Nombre_branches, S[size].Ramification_terminale, S[size].Hauteur, S[size].Vigueur_plante,
                            S[size].Couleur_gousse, S[size].Longueur_gousses, S[size].Nombre_graines_par_plante_individuelle,
                            S[size].Rendement_QdivHa);
                            break;
                          }

            size++;
        }
        fclose(file);
        currentSize = size + 100;
    } else {
        printf("Error opening file\n");
    }
}






void check_admin() {
    admin[0] = (struct admins){"admin", "admin"};
    char user[100], password[100];
    int i, size_admin, found;
    size_admin = admin_number;
    printf("admin requis pour cette action \n");
    printf("username: ");
    scanf("%99s", user);
    printf("password: ");
    scanf("%99s", password);
    found = 0;
    for (i = 0; i < size_admin; i++) {
        int user_choice;
        if (strcmp(admin[i].user_name, user) == 0 && strcmp(admin[i].password, password) == 0) {
            found = 1;
            printf(" ajouter un nouveau admin: 1 \n ajouter une nouvelle espece : 2 \n ");
            scanf("%d", &user_choice);

            switch (user_choice) {
                case 1:
                    add_admin();
                    break;
                case 2:
                    ajout_espece();
                    break;
                default:
                    printf("Choix invalide\n");
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
            printf(" ajouter un nouveau admin: 1 \n ajouter une nouvelle espece : 2 \n ");
            scanf("%d", &user_choice);

            switch (user_choice) {
                case 1:
                    add_admin();
                    break;
                case 2:
                    ajout_espece();
                    break;
                default:
                    printf("Choix invalide\n");
                    break;
            }
            }
            size++;
        }
    }



    if (!found)
        printf("username or password incorrect\n");
}

void add_admin() {
    char nv_user[100], nv_mdp[100];

    printf(" entre admin user name: \n");
    scanf("%99s", nv_user);
    printf(" entre admin password: \n");
    scanf("%99s", nv_mdp);
    if (admin_number < 100) {
        strncpy(admin[admin_number].user_name, nv_user, sizeof(admin[admin_number].user_name) - 1);
        admin[admin_number].user_name[sizeof(admin[admin_number].user_name) - 1] = '\0';
        strncpy(admin[admin_number].password, nv_mdp, sizeof(admin[admin_number].password) - 1);
        admin[admin_number].password[sizeof(admin[admin_number].password) - 1] = '\0';
        WriteToFileA(nv_user, nv_mdp);
        admin_number++;

    } else {
        printf("nombre maximum d'admin est atteint");
    }
}

void ajout_espece() {
    if (currentSize < 126) {
        printf("Veuillez entrer les critères suivants en détail:\n");

        S[currentSize].ID = currentSize;

        printf("IG: ");
        scanf("%d", &S[currentSize].IG);

        printf("Taxon: ");
        scanf("%d", &S[currentSize].Taxon);

        printf("Précocité: ");
        scanf("%d", &S[currentSize].Precocite);

        printf("Premières gousses: ");
        scanf("%d", &S[currentSize].Premieres_gousses);

        printf("Jours maturité: ");
        scanf("%d", &S[currentSize].Jours_maturite);

        printf("Intensité stries florales: ");
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

        printf("CROP: ");
        scanf("%s", S[currentSize].CROP);

        printf("DOI: ");
        scanf("%s", S[currentSize].DOI);

        printf("ORIGINE: ");
        scanf("%s", S[currentSize].ORGINE);

        printf("Couleur fleur: ");
        scanf("%s", S[currentSize].Couleur_fleur);

        printf("Couleur de l'aile florale: ");
        scanf("%s", S[currentSize].Couleur_aile_florale);

        printf("Couleur de gousse: ");
        scanf("%s", S[currentSize].Couleur_gousse);

        char assurance;
        printf("Êtes-vous sûr que les informations sont correctes? y/n: ");
        scanf(" %c", &assurance);

        if (assurance == 'y' || assurance == 'Y') {
            WriteToFileE();
        } else {
            printf("Veuillez reprendre la procédure.\n");
            ajout_espece();
        }
    } else {
        printf("Donnees pleines \n");
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
            printf(" id :%d \n ig :%d \n crop :%s \n DOI :%s \n Origin :%s \n Taxon :%d \n Precocite :%d \n Premieres gousses :%d \n",S[id].ID, S[id].IG, S[id].CROP, S[id].DOI, S[id].ORGINE, S[id].Taxon, S[id].Precocite, S[id].Premieres_gousses );
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
            printf("id not found \n");
            int choice;
            printf("est ce que vous voulez chercher dans un file exterieure ? 1: yes \t 2: no\n");
            scanf("%d",&choice);
            if (choice == 1){
                ReadFromFile(id);
            }
        }
        return;
    }



// search lin
void search_ig(int ig){
    int found;
    int size = sizeof(S) / sizeof(S[0]);
    int i;
    for (i=0 ; i < size ; i++){
        if (S[i].IG == ig){
            found = 1;
            printf(" id :%d \n ig :%d \n crop :%s \n DOI :%s \n Origin :%s \n Taxon :%d \n Precocite :%d \n Premieres gousses :%d \n",S[i].ID, S[i].IG, S[i].CROP, S[i].DOI, S[i].ORGINE, S[i].Taxon, S[i].Precocite, S[i].Premieres_gousses );
            break;
            return;
        }
    }
        if(!found) {
            printf("ig que vous venez d'entre n'existe pas veuillez vous s'assure qu'il est y'a pas d'erreur ");
  }
}


int main() {

int admin_number = 1;

    S[0] = (struct data){1, 11283 , "ILB", "10.18730/5ZR70", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[1] = (struct data){1, 11283 , "ILB", "10.18730/5ZR70", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[2] = (struct data){2, 11285 , "ILB", "10.18730/5ZR81", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[3] = (struct data){3, 11310 , "ILB", "10.18730/5ZRWN", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[4] = (struct data){4, 11657 , "ILB", "10.18730/602H$", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[5] = (struct data){5, 11725 , "ILB", "10.18730/604KT", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[6] = (struct data){6, 11727 , "ILB", "10.18730/604NW", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[7] = (struct data){7, 12142 , "ILB", "10.18730/60FQC", "AFG", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[8] = (struct data){8, 11779 , "ILB", "10.18730/60630", "CAN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[9] = (struct data){9, 11820, "ILB", "10.18730/607A2", "CAN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[10] = (struct data){10,11843, "ILB", "10.18730/6081S", "CAN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[11] = (struct data){11,11863, "ILB", "10.18730/608H4", "CAN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[12] = (struct data){12,11522, "ILB", "10.18730/5ZYZZ", "CHN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[13] = (struct data){13,13811, "ILB", "10.18730/61R4A", "CHN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[14] = (struct data){14,13814, "ILB", "10.18730/61R7D", "CHN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[15] = (struct data){15,13815, "ILB", "10.18730/61R8E", "CHN", 0, 0, 0, 0, "", 0, "",0,0,0,0,0,"",0,0,0};
    S[16] = (struct data){16, 13971, "ILB", "10.18730/61WSB", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[17] = (struct data){17, 14202, "ILB", "10.18730/622RH", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[18] = (struct data){18, 14205, "ILB", "10.18730/622TK", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[19] = (struct data){19, 14322, "ILB", "10.18730/6261B", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[20] = (struct data){20, 14323, "ILB", "10.18730/6262C", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[21] = (struct data){21, 14332, "ILB", "10.18730/626BN", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[22] = (struct data){22, 14336, "ILB", "10.18730/626FS", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[23] = (struct data){23, 14337, "ILB", "10.18730/626GT", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[24] = (struct data){24, 70620, "ILB", "10.18730/7PN8P", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[25] = (struct data){25, 70621, "ILB", "10.18730/7PN9Q", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[26] = (struct data){26, 72218, "ILB", "10.18730/7R573", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[27] = (struct data){27, 72220, "ILB", "10.18730/7R595", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[28] = (struct data){28, 72221, "ILB", "10.18730/7R5A6", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[29] = (struct data){29, 72223, "ILB", "10.18730/7R5C8", "CHN", 0, 0, 0, 0, "", 0, "", 0, 0, 0, 0, 0, "", 0, 0, 0};
    S[30] = (struct data){30, 72224, "ILB", "10.18730/7R5D9", "CHN",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[31] = (struct data){31, 72226, "ILB", "10.18730/7R5FB", "CHN",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[32] = (struct data){32, 72227, "ILB", "10.18730/7R5GC", "CHN",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[33] = (struct data){33, 99322, "ILB", "10.18730/8G3PU", "CHN",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[34] = (struct data){34, 99324, "ILB", "10.18730/8G3R1", "CHN", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[35] = (struct data){35, 12424, "ILB", "10.18730/944ZP", "CHN", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[36] = (struct data){36, 11505, "ILB", "10.18730/5ZYGG", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[37] = (struct data){37, 12882, "ILB", "10.18730/6118J", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[38] = (struct data){38, 12945, "ILB", "10.18730/612HP", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[39] = (struct data){39, 12954, "ILB", "10.18730/612MS", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[40] = (struct data){40, 12974, "ILB", "10.18730/61333", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[41] = (struct data){41, 12976, "ILB", "10.18730/61355", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[42] = (struct data){42, 12979, "ILB", "10.18730/61388", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[43] = (struct data){43, 13251, "ILB", "10.18730/618P$", "DEU", 0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[44] = (struct data){44, 14277, "ILB", "10.18730/624WB", "ECU",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[45] = (struct data){45, 117988, "ILB", "10.18730/8YRXX","ECU",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[46] = (struct data){46, 117989, "ILB", "10.18730/8YRYY","ECU",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[47] = (struct data){47, 124723, "ILB", "10.18730/94K2X","ECU",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[48] = (struct data){48, 155357, "ILB", "10.18730/AAQGB","ECU",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[49] = (struct data){49, 11456, "ILB", "10.18730/5ZX27","ESP",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[50] = (struct data){50, 11462, "ILB", "10.18730/5ZX8D","ESP",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[51] = (struct data){51, 0, "", "","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[52] = (struct data){52, 0, "", "","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[53] = (struct data){53, 0, "", "","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[54] = (struct data){54, 0, "", "","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[55] = (struct data){55, 0, "", "","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[56] = (struct data){56, 0, "", "","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[57] = (struct data){57, 0, "", "","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[58] = (struct data){58,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[59] = (struct data){59,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[60] = (struct data){60,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[61] = (struct data){61,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[62] = (struct data){62,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[63] = (struct data){63,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[64] = (struct data){64,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[65] = (struct data){65,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[66] = (struct data){66,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[67] = (struct data){67,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[68] = (struct data){68,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[69] = (struct data){69,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[70] = (struct data){70,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[71] = (struct data){71,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[72] = (struct data){72,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[73] = (struct data){73,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[74] = (struct data){74,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[75] = (struct data){75,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[76] = (struct data){76,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[77] = (struct data){77,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[78] = (struct data){78,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[79] = (struct data){79,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[80] = (struct data){80,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[81] = (struct data){81,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[82] = (struct data){82,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[83] = (struct data){83,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[84] = (struct data){84,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[85] = (struct data){85,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[86] = (struct data){86,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[87] = (struct data){87,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[88] = (struct data){88,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[89] = (struct data){89,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[90] = (struct data){90,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[91] = (struct data){91,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[92] = (struct data){92,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[93] = (struct data){93,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[94] = (struct data){94,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[95] = (struct data){95,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[96] = (struct data){96,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[97] = (struct data){97,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[98] = (struct data){98,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};
    S[99] = (struct data){99,0,"","","",0,0,0,0,"",0,"",0,0,0,0,0,"",0,0,0};






// main menu
printf("Hello dear user!\nPlease select an option:\n");





void HandleMainSwitch(){
    printf("Search using ID: 1\n");
    printf("Search using IG: 2\n");
    printf("Add new one: 3\n");
    printf("Add new admin: 4\n");
    printf("Exit: 5\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice, please select between 1 and 5\n");
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
                printf("Adding new one...\n");
                check_admin();
                break;
            case 4:
                printf("nchaelah ikoun lkhir...\n");
                // Add logic dchi haja
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

        }
}
HandleMainSwitch();

int choice_user;

printf("si tu veux continuer: 1 \nquitter le programme: 2 \n");
scanf("%d", &choice_user);


do {
    HandleMainSwitch();
}while(choice_user !=2);
}
