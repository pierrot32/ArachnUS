/*
 * Le programme ci-dessous à été réalisé par l'équipe d'ARACHNUS
 * dans la cadre d'un cours de projet en génie robotique
 * de l'université de Sherbrooke (S4-GRO).
 */

 
/*************************************************** 
  Fonctions qui fait la moyenne de tableau
  ****************************************************/

int filtreMoyenneMobile(float tableau[], int taille){
  float moyenne = 0;

  for (int i = 0; i<taille ; i++){ //Décalage des valeurs du filtre pour l'ancienne commande
    moyenne = moyenne + tableau[i];
  }

  moyenne = moyenne / taille;

  return (int)(moyenne);
}
