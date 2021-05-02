#include <windows.h>	//Inclusion de variables de windows

#include <glut.h>	//Inclusion de GLUT
#include <GL/gl.h>		//Inclusion de GL		 	
#include <GL/glu.h>	
#include <stdio.h>
#include <math.h>	//Inclusion de librerias auxiliares	
#define INCREMENTO .06
#define DISTANCIA 5000
#define PI 3.1416

float alpha=0;
float beta =0;

extern boolean orbita;
extern float fovy;
extern int W_WIDTH;
extern int W_HEIGHT;

void myCamara() {
	//Configuración de la matriz de proyeccion
	glMatrixMode(GL_PROJECTION);
	//La ponemos auno
	glLoadIdentity();
	//glOrtho(-1900.0, 1900.0f, -1900.0, 1900.0f, -1900.0f, 1900.0f);
	gluPerspective(fovy, (float)W_WIDTH / (float)W_HEIGHT, 1.0, 13000.0);
	gluLookAt(((float)DISTANCIA * (float)sin(alpha) * cos(beta)), ((float)DISTANCIA * (float)sin(beta)), ((float)DISTANCIA * cos(alpha) * cos(beta)), 0, 0, 0, 0, cos(beta), 0);
}


void myTeclado(unsigned char tras,int x,int y)
{
	switch (tras) {
	case 'l':
		break;
	case 'c':
			break;
	case 'r':
			break;
	case 'p':
		break;
	case 'a':
		//Activamos la orbita
		orbita = 1;
		break;
	case 'b':
		//Desactivamos la orbita
		orbita = 0;
		break;
	default:
	break;
	}
// Se se modificou algo redebúxase
  glutPostRedisplay();
}

/**************************************
FUNCION DE CONTROL DE TECLAS ESPECIAIS:
**************************************
*/
 void myTeclasespeciales(int cursor,int x,int y) 
{
	switch(cursor) 
	{
//Traslaciones:
		case GLUT_KEY_F1:
	   		break;
		case GLUT_KEY_F2:
	
		break;
		case GLUT_KEY_F3:
			
		break;
		case GLUT_KEY_F4:
						break;
		case GLUT_KEY_F5:
			
		break;
		case GLUT_KEY_F6:
		
		break;
//Giros:
		case GLUT_KEY_UP:
			beta-=INCREMENTO;
			break;
		case GLUT_KEY_DOWN:
			beta+=INCREMENTO;
			break;
		case GLUT_KEY_RIGHT:
			alpha-=INCREMENTO;
			break;
		case GLUT_KEY_LEFT:
			alpha+=INCREMENTO;
			break;
		default:
			break;
	}

	if(alpha>=PI*2.0 && alpha<=0 ) alpha=0;
	if(beta>=PI*2.0 && beta<=0 ) beta=0; //hay que repasarlo para evitar el salto


		glutPostRedisplay();
}