#ifndef MAIN_H
#define MAIN_H
struct data {
    int ID, IG, Taxon, Precocite, Premieres_gousses, Jours_maturite;
    int Intensite_stries_florales, Nombre_fleur, Nombre_branches;
    int Ramification_terminale, Hauteur, Vigueur_plante, Longueur_gousses;
    int Nombre_graines_par_plante_individuelle;
    float Rendement_QdivHa;
    char CROP[100], DOI[100], ORGINE[100], Couleur_fleur[100];
    char Couleur_aile_florale[100], Couleur_gousse[100];
} S[126];


struct admins {

    char user_name[100];
    char password[100];

}admin[100];

#endif // DATA_H


