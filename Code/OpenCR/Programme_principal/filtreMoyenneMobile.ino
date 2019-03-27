int filtreMoyenneMobile(float tableau[], int taille){
  float moyenne = 0;

          for (int i = 0; i<taille ; i++){ //Décalage des valeurs du filtre pour l'ancienne commande
          moyenne = moyenne + tableau[i];
          }

          moyenne = moyenne / taille;

    return (int)(moyenne);
}
