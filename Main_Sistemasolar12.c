#include <windows.h>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "SistemaSolar1.2/Definicion.h"
#include <math.h>	

#define STB_IMAGE_IMPLEMENTATION
#include "SistemaSolar1.2/stb_image.h"

int W_WIDTH = 1024;
int W_HEIGHT = 1024;
int w = 1024;
int h = 1024;
GLuint textura;
#define GL_PI 3.14f
float fovy = 45;

//Llamamos a mi esfera
extern myEsfera();
extern myCubo();
extern myCuboInvertido();
//Llamamos a myCamera
extern myCamera();
extern void myTeclado(unsigned char tras, int x, int y);
extern void myTeclasespeciales(int cursor, int x, int y);
int fondo;
int fondotextura;
int texturaPanel;
int objeto2;
int panel;


//Variables de iluminación
GLfloat Ambient[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat Diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SpecRef[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat Specular[4]= { 1.0f, 1.0f, 1.0f, 1.0f };
//Luz criptoniana
//GLfloat Specular[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
//Variables de definición de la posición del foco y dirección de iluminación
GLfloat LuzPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat SpotDir[] = { 1.0f, 1.0f, 1.0f};

//Planetas
objeto sol = { 0, 0, 0, 10, 0, 150, 0, 0, {1.0f, 1.0f, 0.0f}, 0, 0, 0};
objeto mercurio = {200, 10, 0, 10, 0, 20, 0, 0, {0.658824, 0.658824, 0.658824}, 0, 0, 0};
objeto venus = { 300, 12, 0, 10, 0, 50, 0, 0, {1.0f, 0.5f, 0.0f}, 0, 0, 0};
objeto tierra = { 600, 5, 0, 10, 0, 70, 0, 0, {0.0f, 0.5f, 0.5f}, 0, 1, 0};
objeto luna = { 200, 20, 0, 10, 0, 20, 0, 1, {1.0f, 1.0f, 1.0f }, 0, 0, 0};
objeto iss = { 130, 10, 0, 10, 0, 15, 0, 1, {1.0f, 1.0f, 1.0f}, 0, 0, 0};
objeto marte = { 900, 8, 0, 10, 0, 40, 0, 0, {1.0f, 0.0f, 0.0f}, 0, 0, 0};
objeto jupiter = { 1080, 4, 0, 10, 0, 110, 0, 0, {1.0f, 0.5f, 0.0f}, 0, 0, 0};
objeto saturno = { 1370, 6, 0, 10, 0, 90, 0, 0, {0.5f, 0.251f, 0.0f}, 1, 0, 0};
objeto urano = { 1630, 5, 0, 10, 0, 80, 0, 0, {0.5f, 1.0f, 1.0f}, 0, 0, 0};
objeto neptuno = { 1800, 9, 0, 10, 0, 80, 0, 0, {0.5f, 1.0f, 1.0f}, 0, 0, 0};

//Definicio de la esfera
int myObjeto;
int camara = 1;
const int sides = 100;  // The amount of segment to create the circle
boolean orbita = 1;

void myEjes(void) {
	// Creamos el eje X
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glEnd();

	// Creamos el eje Y
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glEnd();

	// Creamos el eje Z
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 50.0f);
	glEnd();

	// Creamos la normal 
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(30.0f, 30.0f, 30.0f);
	glEnd();
}

void myTelescopio(float distancia, float angulo, float distancia_obj, float angulo_obj, int satelite) {
	//Configurmos la matriz de proyeccion
	glMatrixMode(GL_PROJECTION);
	//La ponemos a uno
	glLoadIdentity();

	//gluPerspective(45.0, 1, 0.05, 1.5);
	gluPerspective(45.0, (float)W_WIDTH/(float)W_HEIGHT, 1.0, 9000.0);
	if (satelite == 0) {
		gluLookAt(distancia * cos(angulo * GL_PI / 180.0), 0, -1 * distancia * sin(angulo * GL_PI / 180.0), distancia_obj * cos(angulo_obj * GL_PI / 180.0), 0, -1 * distancia_obj * sin(angulo_obj * GL_PI / 180.0), 0, 1, 0);
	}else if (satelite == 1) {
		gluLookAt(distancia * cos(angulo * GL_PI / 180.0), 0, -1 * distancia * sin(angulo * GL_PI / 180.0), distancia_obj * cos((angulo_obj + angulo) * GL_PI / 180.0) + distancia * cos(angulo * GL_PI / 180.0), 0, -1 * distancia_obj * sin((angulo_obj + angulo) * GL_PI / 180.0) + -1 * distancia * sin(angulo * GL_PI / 180.0), 0, 1, 0);
	}
}

void onMenu(int opcion) {
	switch (opcion)
	{
	case 1:
		camara = 1;
		break;
	case 2:
		camara = 2;
		break;
	case 3:
		camara = 3;
		break;
	case 4:
		camara = 4;
		break;
	case 5:
		camara = 5;
		break;
	case 6:
		camara = 6;
		break;
	case 7:
		camara = 7;
		break;
	case 8:
		camara = 8;
		break;
	case 9:
		camara = 9;
		break;
	case 10:
		camara = 10;
		break;
	case 11:
		camara = 11;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void changeSize(GLint newWidth, GLint newHeight) {
	W_HEIGHT = newHeight;
	W_WIDTH = newWidth;
	glViewport(0, 0, newWidth, newHeight);
	onMenu(camara);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(fovy, (float)newWidth / (float)newHeight, 0.1, 5000.0);
}

void myMenu() {
	int menuFondo;

	menuFondo = glutCreateMenu(onMenu);
	glutAddMenuEntry("Voyayer", 1);
	glutAddMenuEntry("Sol", 2);
	glutAddMenuEntry("Mercurio", 3);
	glutAddMenuEntry("Venus", 4);
	glutAddMenuEntry("Marte", 5);
	glutAddMenuEntry("Jupiter", 6);
	glutAddMenuEntry("Saturno", 7);
	glutAddMenuEntry("Urano", 8);
	glutAddMenuEntry("Neptuno", 9);
	glutAddMenuEntry("Luna", 10);
	glutAddMenuEntry("ISS", 11);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//Creamos las orbitas dependiendo de la distancia al sol
void myOrbita(float radius) {
	if (orbita == 1) {
		glBegin(GL_LINE_LOOP);
			glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
			for (int a = 0; a < 360; a += 360 / sides) {
				double heading = a * 3.1415926535897932384626433832795 / 180;
				glVertex3f(cos(heading) * radius, 0, sin(heading) * radius);
			}
		glEnd();
		glFlush();
	}
}

//Anillos de saturno
void anillo(float radius){
	//110-160
	if (radius >= 110 && radius < 126) {
		glColor3f(0.3f, 0.3f, 0.3f);
	}
	else if (radius >= 126 && radius < 142) {
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else if (radius >= 142 && radius <=160) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	glPushMatrix();
		glRotatef(15.0, 1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
			for (int a = 0; a < 360; a += 360 / sides) {
				double heading = a * 3.1415926535897932384626433832795 / 180;
				glVertex3f(cos(heading) * radius, 0, sin(heading) * radius);
			}
		glEnd();
	glPopMatrix();
}

//Función para dibujar el planeta
void dibuja_planeta(objeto *planeta, objeto* luna, objeto* ISS) {
	glPushMatrix();
		myOrbita(planeta->distancia);
		glRotatef(planeta->angulo_trans, 0.0, 1.0, 0.0);
		glTranslatef(planeta->distancia, 0.0, 0.0);
		glPushMatrix();
			if (planeta->anillo == 1) {
				for (int i = 110; i <= 160; i++) {
					anillo(i);
				}
			}
			glRotatef(planeta->angulo_rot, 0.0, 1.0, 0.0);
			glScalef(planeta->tamaño, planeta->tamaño, planeta->tamaño);
			//glColor3f(planeta->color.R, planeta->color.G, planeta->color.B);
			glBindTexture(GL_TEXTURE_2D, planeta->textura);
			glCallList(planeta->listarender);
			glBindTexture(GL_TEXTURE_2D, 0);
		glPopMatrix();

		if (planeta->tiene_satelite == 1) {
			//Luna
			glPushMatrix();
				myOrbita(luna->distancia);
				glRotatef(luna->angulo_trans, 0.0, 1.0, 0.0);
				glTranslatef(luna->distancia, 0.0, 0.0);
				glPushMatrix();
					glRotatef(luna->angulo_rot, 0.0, 1.0, 0.0);
					glScalef(luna->tamaño, luna->tamaño, luna->tamaño);
					//glColor3f(luna->color.R, luna->color.G, luna->color.B);
					glBindTexture(GL_TEXTURE_2D, luna->textura);
					glCallList(luna->listarender);
					glBindTexture(GL_TEXTURE_2D, 0);
				glPopMatrix();
			glPopMatrix();

			//ISS		
			glPushMatrix();
				myOrbita(iss.distancia);
				glRotatef(ISS->angulo_trans, 0.0, 1.0, 0.0);
				glTranslatef(ISS->distancia, 0.0, 0.0);
				glPushMatrix();
					glRotatef(ISS->angulo_rot, 0.0, 1.0, 0.0);
					glScalef(ISS->tamaño, ISS->tamaño, ISS->tamaño);
					//glColor3f(ISS->color.R, ISS->color.G, ISS->color.B);
					glBindTexture(GL_TEXTURE_2D, ISS->textura);
					glCallList(ISS->listarender);
					glBindTexture(GL_TEXTURE_2D, 0);
				glPopMatrix();
				//Panel 1
				glPushMatrix();
					glRotatef(ISS->angulo_trans, 0.0, 1.0, 0.0);
					glTranslatef(-6, 0.0, 0.0);
					glPushMatrix();
						glRotatef(ISS->angulo_rot, 0.0, 1.0, 0.0);
						glScalef(10,10,10);
						//glColor3f(1.0, 0.0, 0.0);
						glBindTexture(GL_TEXTURE_2D, panel);
						glCallList(objeto2);
						glBindTexture(GL_TEXTURE_2D, 0);
					glPopMatrix();
				glPopMatrix();
				//Panel 2
				glPushMatrix();
					glRotatef(ISS->angulo_trans, 0.0, 1.0, 0.0);
					glTranslatef(6, 0.0, 0.0);
					glPushMatrix();
						glRotatef(ISS->angulo_rot, 0.0, 1.0, 0.0);
						glScalef(10, 10, 10);
						//glColor3f(ISS->color.R, ISS->color.G, ISS->color.B);
						glBindTexture(GL_TEXTURE_2D, panel);
						glCallList(ISS->listarender);
						glBindTexture(GL_TEXTURE_2D, 0);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			
		}
	glPopMatrix();
}

//Movimiento de los planetas
void myMovimiento(objeto *planeta) {
	planeta->angulo_trans += planeta->velocidad_trans;
	if (planeta->angulo_trans >= 360.0f) {
		planeta->angulo_trans -= 360.0;
	}
	planeta->angulo_rot += planeta->velocidad_rot;
	if (planeta->angulo_rot >= 360.0f) {
		planeta->angulo_rot -= 360.0;
	}

	glutPostRedisplay();
	glutTimerFunc(MYTIEMPO, myMovimiento, planeta);
}

//Cargamos las texturas
int Carga_Texturas(char* nombre) {
	glGenTextures(1, &textura);
	glBindTexture(GL_TEXTURE_2D, textura); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	unsigned char* data = stbi_load(nombre, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data); //con mimap 

	}
	else
	{
		//std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	return textura;
}

//Cargamos las texturas en la estructura
void texturas() {
	sol.textura = Carga_Texturas("../Textures/Sol.bmp");
	mercurio.textura = Carga_Texturas("../Textures/Mercurio.bmp");
	venus.textura = Carga_Texturas("../Textures/Venus.bmp");
	tierra.textura = Carga_Texturas("../Textures/Terra.bmp");
	marte.textura = Carga_Texturas("../Textures/Marte.bmp");
	jupiter.textura = Carga_Texturas("../Textures/Jupiter.bmp");
	saturno.textura = Carga_Texturas("../Textures/Saturno.bmp");
	urano.textura = Carga_Texturas("../Textures/Urano.bmp");
	neptuno.textura = Carga_Texturas("../Textures/Neptuno.bmp");
	luna.textura = Carga_Texturas("../Textures/Luna.bmp");
	iss.textura = Carga_Texturas("../Textures/Iss.jpg");
	panel = Carga_Texturas("../Textures/panel.jpg");
	fondotextura = Carga_Texturas("../Textures/Fondo.bmp");
}

// Función de display
void Display(void) {
	// Clear the window with current clearing color
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	switch (camara){
		case 1:
			myCamara();
			break;
		case 2: 
			myTelescopio(tierra.distancia, tierra.angulo_trans, sol.distancia, sol.angulo_trans, sol.satelite);
			break;
		case 3:
			myTelescopio(tierra.distancia, tierra.angulo_trans, mercurio.distancia, mercurio.angulo_trans, mercurio.satelite);
			break;
		case 4:
			myTelescopio(tierra.distancia, tierra.angulo_trans, venus.distancia, venus.angulo_trans, venus.satelite);
			break;
		case 5:
			myTelescopio(tierra.distancia, tierra.angulo_trans, marte.distancia, marte.angulo_trans, marte.satelite);
			break;
		case 6:
			myTelescopio(tierra.distancia, tierra.angulo_trans, jupiter.distancia, jupiter.angulo_trans, jupiter.satelite);
			break;
		case 7:
			myTelescopio(tierra.distancia, tierra.angulo_trans, saturno.distancia, saturno.angulo_trans, tierra.satelite);
			break;
		case 8:
			myTelescopio(tierra.distancia, tierra.angulo_trans, urano.distancia, urano.angulo_trans, urano.satelite);
			break;
		case 9:
			myTelescopio(tierra.distancia, tierra.angulo_trans, neptuno.distancia, neptuno.angulo_trans, neptuno.satelite);
			break;
		case 10:
			myTelescopio(tierra.distancia, tierra.angulo_trans, luna.distancia, luna.angulo_trans, luna.satelite);
			break;
		case 11:
			myTelescopio(tierra.distancia, tierra.angulo_trans, iss.distancia, iss.angulo_trans, iss.satelite);
			break;
		default:
			break;
	}

	glMatrixMode(GL_MODELVIEW); //Matriz del Modelo
	glLoadIdentity(); // Inicializamos la matriz del modelo a la identidad
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Deshabilitamos las luces
	glDisable(GL_LIGHTING);
	dibuja_planeta(&sol, &luna, &iss);
	//Habilitamos las luces
	glEnable(GL_LIGHTING);

	dibuja_planeta(&mercurio, &luna, &iss);
	dibuja_planeta(&venus, &luna, &iss);
	dibuja_planeta(&tierra, &luna, &iss);
	dibuja_planeta(&marte, &luna, &iss);
	dibuja_planeta(&jupiter, &luna, &iss);
	dibuja_planeta(&saturno, &luna, &iss);
	dibuja_planeta(&urano, &luna, &iss);
	dibuja_planeta(&neptuno, &luna, &iss);

	glRotatef(0.0, 0.0, 0.0, 0.0);
	glTranslatef(0, 0.0, -1800.0);
	glScalef(20000, 20000, 20000);
	glBindTexture(GL_TEXTURE_2D, fondotextura);
	glCallList(fondo);
	glBindTexture(GL_TEXTURE_2D, 0);

	glFlush();
	glutSwapBuffers();
}

void luz() {
	//Definimos las iluminaciones
	glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);
	glLightfv(GL_LIGHT0, GL_POSITION, LuzPos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, SpotDir);

	//Efectos del foco
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 179.0f);
	// Activamos las luces
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	//Definimos el seguimiento del color como propiedad luminosa de los materiales
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	//Definimos las propiedades del brillo metálico
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);
	glMateriali(GL_FRONT, GL_SHININESS, 1);
}

//Main del proyecto
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	//Posicion de la ventana
	glutInitWindowPosition(100, 100);
	//Tamano de la ventana
	glutInitWindowSize(W_WIDTH, W_HEIGHT);
	//Tipo de color y buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//Crear la ventana
	glutCreateWindow("Sistema Solar -> A actiba orbita, B -> Oculta orbita");

	//Detecta la profundidad de objectos y no dibujar caras ocultas
	glClearDepth( 1.0f );
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // Habilita la ocultacion de caras
	glCullFace(GL_BACK);
	glEnable(GL_NORMALIZE);

	//Cargo texturas
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);

	glBindTexture(GL_TEXTURE_2D, fondo);

	//Eventos
	glutKeyboardFunc(myTeclado);
	glutSpecialFunc(myTeclasespeciales);
	glutReshapeFunc(changeSize);

	myObjeto = myEsfera();
	sol.listarender = mercurio.listarender = venus.listarender = tierra.listarender = luna.listarender = marte.listarender = jupiter.listarender = saturno.listarender = urano.listarender = neptuno.listarender = myObjeto;
	
	iss.listarender = objeto2 = myCubo();
	fondo = myCuboInvertido();

	glutDisplayFunc(Display);

	luz();
	
	//Lazo principal
	myMovimiento(&sol);
	myMovimiento(&mercurio);
	myMovimiento(&venus);
	myMovimiento(&tierra);
	myMovimiento(&luna);
	myMovimiento(&iss);
	myMovimiento(&marte);
	myMovimiento(&jupiter);
	myMovimiento(&saturno);
	myMovimiento(&urano);
	myMovimiento(&neptuno);
	
	myMenu();
	
	texturas();
	myCamara();
	glutMainLoop();
	return 0;
}