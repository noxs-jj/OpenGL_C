//----------------------------------------------------------------------
// Cube en 3D avec OpenGL
//----------------------------------------------------------------------
 
//----------------------------------------------------------------------
// LIBRAIRIES
//----------------------------------------------------------------------
// LIBRAIRIES et COMMANDE Linux :
// #include <gl/glut.h>
// #include <stdlib.h>
// gcc -o prog.exe  main.c -L/usr/X11R6/lib -lglut
 
#include <openGL/gl.h>		// Header File For The OpenGL32 Library
#include <openGL/glu.h>		// Header File For The GLu32 Library
#include <glut/glut.h>		// Header File For The GLut Library
 
//----------------------------------------------------------------------
// DECLARATION DES FONCTIONS
//----------------------------------------------------------------------
void clavier(unsigned char touche, int x, int y);
void affichage();
void mouse(int button, int state, int x, int y);
void mousemotion(int x, int y);
void reshape(int x, int y);
 
// STRUCTURE
typedef struct {
  float x, y, z, r, g, b;
} point;
 
//----------------------------------------------------------------------
// VARIABLES GLOBALES
//----------------------------------------------------------------------
float xold, yold, anglex = 0, angley = 0, presse = 0;
 
// Notre cube :
// Tout les points
point p[8] = {
{-0.5, -0.5, 0.5, 1.0, 0.0, 0.0},
{-0.5, 0.5, 0.5, 0.0, 1.0, 0.0},
{0.5, 0.5, 0.5, 0.0, 0.0, 1.0},
{0.5, -0.5, 0.5, 1.0, 1.0, 1.0},
{-0.5, -0.5, -0.5, 1.0, 0.0, 0.0},
{-0.5, 0.5, -0.5, 0.0, 1.0, 0.0},
{0.5, 0.5, -0.5, 0.0, 0.0, 1.0},
{0.5, -0.5, -0.5, 1.0, 1.0, 1.0}};
 
// Toutes les faces
int f[6][4] = {
{0, 1, 2, 3},
{3, 2, 6, 7},
{4, 5, 6, 7},
{0, 1, 5, 4},
{1, 5, 6, 2},
{0, 4, 7, 3}};
 
//----------------------------------------------------------------------
// MAIN
//----------------------------------------------------------------------
int main(int argc, char* argv[]){
  glutInit(&argc, argv);             // Initialise la b. glut
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // param d'affichage
  glutInitWindowPosition(200, 200);  // Fenetre : position
  glutInitWindowSize(250, 250);      // Fenetre : taille
  glutCreateWindow("OpenGL - Cube 3D - Nicotouch.com");          // Fenetre : Nom
 
  glClearColor(0, 0, 0, 0);          // Défaut : Couleur de fond
  glPointSize(2.0);                  // Taille d'un point
  glEnable(GL_DEPTH_TEST);           // Utilisation du Tampon de Profondeur
 
  // Gestion des évènement :
  glutDisplayFunc(affichage);        // Fonction qui gère l'affichage
  glutKeyboardFunc(clavier);         // Fonction qui gère les commandes clavier
 
  glutMouseFunc(mouse);              // Prendre en compte les fonctions
  glutMotionFunc(mousemotion);       // Fonction de gestion du clic de la Souris
  glutReshapeFunc(reshape);          // Fonction de gestion du redimentionnement de la fenêtre
  glutMainLoop();                    // Boucle d'attente des évènements

  return (0);
}
 
//----------------------------------------------------------------------
// CLAVIER : gère l'activation de différent mode d'affichage
//----------------------------------------------------------------------
void clavier(unsigned char touche, int x, int y){
  switch(touche){ // en fonction des touches, on affiche :
    case 'p':
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Texture
      glutPostRedisplay(); // Raffraichissement
      break;
    case 'f':
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Arrête
      glutPostRedisplay();
      break;
    case 's':
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); // Point
      glutPostRedisplay();
      break;
    case 'd':
      glEnable(GL_DEPTH_TEST);  // Avec tampon de profondeur
      glutPostRedisplay();
      break;
    case 'D':
      glDisable(GL_DEPTH_TEST); // Sans tampon de profondeur
      glutPostRedisplay();
      break;
    case 'q':                   // Quitter
	  //close(0);
      exit(0);
  }
}
 
//----------------------------------------------------------------------
// AFFICHAGE : dessine la forme
//----------------------------------------------------------------------
void affichage(){
  int i, j;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Reset + double tampon
  for(i = 0; i < 6; i++) {                // Pour chaque face
    glBegin(GL_POLYGON);                  // On dessine un nouveau polygone
    for(j = 0; j < 4; j++) {              // Pour chaque sommet
      glColor3f(p[f[i][j]].r, p[f[i][j]].g, p[f[i][j]].b);
      glVertex3f(p[f[i][j]].x, p[f[i][j]].y, p[f[i][j]].z);
    }
    glEnd();                              // Fin du Polygone
  }
 
  glFlush();                              // On force l'affichage
 
  glLoadIdentity();                       // On initialise la matrice de translation
  //gluLookAt(-1.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
  glRotatef(-anglex, 0.0, 1.0, 0.0);      // pour faire des rotation
  glRotatef(-angley, 1.0, 0.0, 0.0);
 
  glutSwapBuffers();
}
 
//----------------------------------------------------------------------
// MOUSE : récupère les évènements souris
//----------------------------------------------------------------------
void mouse(int button, int state, int x, int y){
  // Si on appuie sur le bouton gauche
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    presse = 1; // Le booléen passe devient vrai
    xold = x;   // On sauvegarde la position
    yold = y;
  }
  // Si on relache le bouton
  if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) presse = 0;
}
 
//----------------------------------------------------------------------
// MOUSEOPTION : effectue la rotation
//----------------------------------------------------------------------
void mousemotion(int x, int y) {
  if(presse == 1) {				// Si le bouton est pressé
    anglex = anglex + (x-xold); // On modifie la position actuelle de la souris
    angley = angley + (y-yold); // en fonction de la position actuelle de la
    glutPostRedisplay();        // souris et de la dernière sauvegarde
  }
  xold = x; // On sauvegarde la position actuelle de la souris
  yold = y;
}
 
//----------------------------------------------------------------------
// RESHAPE : Redimentionnement de la fenêtre
//----------------------------------------------------------------------
void reshape(int x, int y) {
  if(x < y) glViewport(0, (y-x)/2, x, x);
  if(y < x) glViewport((x-y)/2, 0, y, y);
}