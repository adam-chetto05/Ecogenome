
#ifndef MAIN_H
#define MAIN_H


struct data {
    int ID, IG;
    char CROP[100], DOI[100], ORGINE[100], Taxon[100];
    int Precocite, Premieres_gousses, Jours_maturite;
    char Couleur_fleur[100];
    int Intensite_stries_florales;
    char Couleur_aile_florale[100];
    int Nombre_fleur, Nombre_branches, Ramification_terminale;
    int Hauteur, Vigueur_plante;
    char Couleur_gousse[100];
    int Longueur_gousses, Nombre_graines_par_plante_individuelle;
    float Rendement_QdivHa;
} S[126];


struct admins {

    char user_name[100];
    char password[100];

}admin[100];

#endif // DATA_H


