/*
 * Le programme ci-dessous à été réalisé par l'équipe d'ARACHNUS
 * dans la cadre d'un cours de projet en génie robotique
 * de l'université de Sherbrooke (S4-GRO).
 */


/*************************************************** 
  Fonctions qui calcul le changement d'angle de chaque moteur en Y pour stabiliser le robot
 ****************************************************/

#define distanceMilieuRobotAxeRotPatte 82.77    // Distance entre l'axe de rotation du suport à patte et le milieu du robot
#define distanceSupportPatte 76.78              // Distance entre les deux axes de rotation sur le support

float anglePatteArriereGauche = 0;              // Changement d'angle de la patte arrière gauche (initulisé pour le moment)
float anglePatteArriereDroite = 0;              // Changement d'angle de la patte arrière droit  (initulisé pour le moment)

float angleAxeXPatte1 = 0;                      // Angle entre l'axe en x de robot et la patte 1
float angleAxeXPatte2 = -45;                    // Angle entre l'axe en x de robot et la patte 1
float angleAxeXPatte3 = 45;                     // Angle entre l'axe en x de robot et la patte 1


deltaAngleMoteurHauteur stabilisationRobot(angleRobot aRobot2){

  deltaAngleMoteurHauteur dMAngle2; // Objet local pour le calcul de la variation d'angle du robot

  // Calcul de la distance entre la patte 2 et 3 et le milieu du robot en X
  float distanceEnXPatte2 = sin(angleAxeXPatte2*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);
  float distanceEnXPatte3 = sin(angleAxeXPatte3*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);

  // Calcul de la variation d'hauteur de chaque patte pour stabiliser le robot dans l'axe des X
  float deltaHauteurXPatte1 = 0;
  float deltaHauteurXPatte2 = sin(aRobot2.angleX*3.14/180)*(distanceEnXPatte2);
  float deltaHauteurXPatte3 = sin(aRobot2.angleX*3.14/180)*(distanceEnXPatte3);

  // Calcul de la distance entre la patte 1, 2 et 3 et le milieu du robot en Y
  float distanceEnYPatte1 = (distanceMilieuRobotAxeRotPatte+distanceSupportPatte);
  float distanceEnYPatte2 = cos(angleAxeXPatte2*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);
  float distanceEnYPatte3 = cos(angleAxeXPatte3*3.14/180.0)*(distanceMilieuRobotAxeRotPatte+distanceSupportPatte);

  // Calcul de la variation d'hauteur de chaque patte pour stabiliser le robot dans l'axe des Y
  float deltaHauteurYPatte1 = -sin(aRobot2.angleY*3.14/180)*(distanceEnYPatte1);
  float deltaHauteurYPatte2 = sin(aRobot2.angleY*3.14/180)*(distanceEnYPatte2);
  float deltaHauteurYPatte3 = sin(aRobot2.angleY*3.14/180)*(distanceEnYPatte3);

  // Calculs des delta hauteur pour la stabilisation totale du robot
  float deltaHauteurPatte1 = deltaHauteurXPatte1 + deltaHauteurYPatte1;
  float deltaHauteurPatte2 = deltaHauteurXPatte2 + deltaHauteurYPatte2;
  float deltaHauteurPatte3 = deltaHauteurXPatte3 + deltaHauteurYPatte3;

  // Transfert de la variation en hauteur en une variation en angle des moteur côté vert de chaque patte
  // 2 mm = 1 deg puisque la cinématique inverse n'est pas encore implanté
  dMAngle2.deltaAngleMoteur1 = (int)(deltaHauteurPatte1/2);
  dMAngle2.deltaAngleMoteur2 = (int)(deltaHauteurPatte2/2);
  dMAngle2.deltaAngleMoteur3 = (int)(deltaHauteurPatte3/2);

  // La variation d'angle est retournée
  return dMAngle2; 
}
