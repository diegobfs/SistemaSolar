#include <windows.h>
#include <stdio.h>
#include <glut.h>
#include <gl.h>
#include <glu.h>
#include <glaux.h>

int myCubo() {

	int IndiceLista = glGenLists(1);
	glNewList(IndiceLista, GL_COMPILE);

	glBegin(GL_QUADS);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, 0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, 0.25f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.25f, -0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, -0.25f, -0.25f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, -0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.25f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.25f, 0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, -0.25f, -0.25f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.25f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, 0.25f, 0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, -0.25f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, -0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, -0.25f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, -0.25f, 0.25f);


	glEnd();
	glEndList();

	return IndiceLista;
}

int myCuboInvertido() {

	int IndiceLista = glGenLists(1);
	glNewList(IndiceLista, GL_COMPILE);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, 0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.25f);

	
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.25f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, -0.25f, -0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, -0.25f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, -0.25f);
	

	
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.25f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, -0.25f, -0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, -0.25f);


	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, 0.25f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.25f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, -0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, -0.25f);

	
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25f, -0.25f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, -0.25f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, -0.25f, 0.25f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25f, -0.25f, 0.25f);


	glEnd();
	glEndList();

	return IndiceLista;
}