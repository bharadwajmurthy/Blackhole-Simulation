//#include "stdafx.h"
#include <stdlib.h>
#include <glut.h>
#include <stdio.h>

#define INIT_VIEW_X    0.0
#define INIT_VIEW_Y    0.0
#define INIT_VIEW_Z   -4.5
#define VIEW_LEFT     -2.0
#define VIEW_RIGHT     2.0
#define VIEW_BOTTOM   -2.0
#define VIEW_TOP       2.0
#define VIEW_NEAR      1.0
#define VIEW_FAR     200.0

float f = 1, f1 = 0.2, f2 = 2, f3 = 3, f4 = 4, f5 = 4.5, f6 = 5.5, f7 = 6, f8 = 6.5;
int choice = 0;
int i = 0;
int fullscreen = 0;
float sunrev = 0.0, r = 0.0;
float delsunrev = 0.0;
float delang = 0.01;
float planetorb = 0.0;
float planetrev = 0.0;
float delplanetorb = 0.0;
float delplanetrev = 0.0;
float moonorb = 0.0;
float moonrev = 0.0;
float delmoonorb = 0.0;
float delmoonrev = 0.0;
float tilt = 0.0;
float merorb = 0.0;
float merrev = 0.0;
float delmerorb = 0.0;
float delmerrev = 0.0;
float venuorb = 0.0;
float venurev = 0.0;
float delvenuorb = 0.0;
float delvenurev = 0.0;
float marorb = 0.0;
float marrev = 0.0;
float delmarorb = 0.0;
float delmarrev = 0.0;
float juporb = 0.0;
float juprev = 0.0;
float deljuporb = 0.0;
float deljuprev = 0.0;
float satorb = 0.0;
float satrev = 0.0;
float delsatorb = 0.0;
float delsatrev = 0.0;
float uraorb = 0.0;
float urarev = 0.0;
float deluraorb = 0.0;
float delurarev = 0.0;
float neporb = 0.0;
float neprev = 0.0;
float delneporb = 0.0;
float delneprev = 0.0;




GLfloat AmbientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat DiffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat SpecularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SpecRef[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat LightPos[] = { -50.0f, 50.0f, 100.0f, 1.0f };
GLubyte Shine = 128;

void SetupRend()
{
	glClearColor(0.1f, 0.0f, 0.1f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);
	glMateriali(GL_FRONT, GL_SHININESS, Shine);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (choice == 0){
		//glPushMatrix();
		glLoadIdentity();

		//glPushMatrix();
		glTranslatef(0.0, 0.0, -8.0);
		glRotatef(90.0*tilt, 1.0, 0.0, 0.0);
		glRotatef(sunrev, 0.0, 0.0, 1.0);

		//glPushMatrix();
		glColor3f(1, 1, 0);
		glutSolidSphere(0.5, 20, 20);




		//venus
		glPushMatrix();
		glRotatef(venuorb, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.2, 0.0);
		glRotatef(venurev, 0.0, 0.0, 1.0);
		glColor3f(1, 1, 0);
		glutWireSphere(0.1, 10, 10);
		glPopMatrix();

		//mercury
		glPushMatrix();
		glRotatef(merorb, 0.0, 0.0, 1.0);
		glTranslatef(2.0, 0.0, 0.0);
		glRotatef(merrev, 0.0, 0.0, 1.0);
		glColor3f(0.5, 0.5, 0);
		glutWireSphere(0.2, 10, 10);
		glPopMatrix();



		//earth
		glPushMatrix();
		glRotatef(planetorb, 0.0, 0.0, 1.0);
		glTranslatef(3.0, 0.0, 0.0);
		glRotatef(planetrev, 0.0, 0.0, 1.0);
		glColor3f(0, 1, 0);
		glutWireSphere(0.3, 20, 20);

		glRotatef(moonorb, 0.0, 0.0, 1.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef(moonrev, 0.0, 0.0, 1.0);
		glColor3f(.9, .8, .7);
		glutWireSphere(0.08, 10, 10);
		glPopMatrix();

		//mars
		glPushMatrix();
		glRotatef(marorb, 0.0, 0.0, 1.0);
		glTranslatef(4.0, 0.2, 0.0);
		glRotatef(marrev, 0.0, 0.0, 1.0);
		glColor3f(1, 0, 0);
		glutWireSphere(0.1, 10, 10);
		glPopMatrix();

		//jupiter
		glPushMatrix();
		glRotatef(juporb, 0.0, 0.0, 1.0);
		glTranslatef(4.50, 0.0, 0.0);
		glRotatef(juprev, 0.0, 0.0, 1.0);
		glColor3f(0.6, 0.1, 0.2);
		glutWireSphere(0.4, 20, 20);
		glPopMatrix();

		//saturn
		glPushMatrix();
		glRotatef(satorb, 0.0, 0.0, 1.0);
		glTranslatef(5.5, 0.0, 0.0);
		glRotatef(satrev, 0.0, 0.0, 1.0);
		glColor3f(0.2, 0.1, 0.8);
		glutWireSphere(0.2, 10, 10);

		glPopMatrix();




		//uranus
		glPushMatrix();
		glRotatef(uraorb, 0.0, 0.0, 1.0);
		glTranslatef(6.0, 0.0, 0.0);
		glRotatef(urarev, 0.0, 0.0, 1.0);
		glColor3f(0.0, 0.5, 1.0);
		glutWireSphere(0.2, 10, 10);
		glPopMatrix();

		//neptune
		glPushMatrix();
		glRotatef(neporb, 0.0, 0.0, 1.0);
		glTranslatef(6.5, 0.2, 0.0);
		glRotatef(neprev, 0.0, 0.0, 1.0);
		glColor3f(0, 0.1, 0.1);
		glutWireSphere(0.1, 10, 10);
		glPopMatrix();
	}
	else if (choice == 1){
		//glPushMatrix();
		glLoadIdentity();

		//glPushMatrix();
		glTranslatef(0.0, 0.0, -8.0);
		glRotatef(90.0*tilt, 1.0, 0.0, 0.0);
		glRotatef(sunrev, 0.0, 0.0, 1.0);

		//glPushMatrix();
		//black hole
		glColor3f(0, 0, 0);
		if (r < 100){
			for (unsigned int k = 0; k < 5000000; k++);
			r += 0.002;
		}
		glutSolidSphere(r, 20, 20);
		if (f>0)
			f -= 0.01;
		if (f1 > 0)
			f1 -= 0.001;
		if (f2 > 0)
			f2 -= 0.01;
		if (f3 > 0)
			f3 -= 0.01;
		if (f4 > 0)
			f4 -= 0.01;
		if (f5 > 0)
			f5 -= 0.01;
		if (f6 > 0)
			f6 -= 0.01;
		if (f7 > 0)
			f7 -= 0.01;
		if (f8 > 0)
			f8 -= 0.01;
		if (r == 10)
			choice = 2;
		//asteroid
		glPushMatrix();
		glRotatef(venuorb, 0.0, 0.0, 1.0);
		glTranslatef(f6, f5, f5);
		glRotatef(venurev, 0.0, 0.0, 1.0);
		glColor3f(1, 1, 0);
		glScalef(0.1, 0.1, 0.1);
		glutSolidIcosahedron();
		glPopMatrix();
		glPushMatrix();
		glRotatef(venuorb, 0.0, 0.0, 1.0);
		glTranslatef(f7, f8, f8);
		glRotatef(venurev, 0.0, 0.0, 1.0);
		glColor3f(1, 1, 0);
		glScalef(0.2, 0.2, 0.2);
		glutSolidIcosahedron();
		glPopMatrix();
		glPushMatrix();
		glRotatef(venuorb, 0.0, 0.0, 1.0);
		glTranslatef(f5,0, f4);
		glRotatef(venurev, 0.0, 0.0, 1.0);
		glColor3f(1, 1, 0);
		glScalef(0.1, 0.1, 0.1);
		glutSolidIcosahedron();
		glPopMatrix();
		glPushMatrix();
		glRotatef(venuorb, 0.0, 0.0, 1.0);
		glTranslatef(f3, f4,0);
		glRotatef(venurev, 0.0, 0.0, 1.0);
		glColor3f(0, 0.1, 0.9);
		glScalef(0.05, 0.05, 0.05);
		glutSolidIcosahedron();
		glPopMatrix();
		//venus
		glPushMatrix();
		glRotatef(venuorb, 0.0, 0.0, 1.0);
		glTranslatef(f, f1, 0.0);
		glRotatef(venurev, 0.0, 0.0, 1.0);
		glColor3f(1, 1, 0);
		glutWireSphere(0.1, 10, 10);
		glPopMatrix();


		//mercury
		glPushMatrix();
		glRotatef(merorb, 0.0, 0.0, 1.0);
		glTranslatef(f2, 0.0, 0.0);
		glRotatef(merrev, 0.0, 0.0, 1.0);
		glColor3f(0.5, 0.5, 0);
		glutWireSphere(0.2, 10, 10);
		glPopMatrix();



		//earth
		glPushMatrix();
		glRotatef(planetorb, 0.0, 0.0, 1.0);
		glTranslatef(f3, 0.0, 0.0);
		glRotatef(planetrev, 0.0, 0.0, 1.0);
		glColor3f(0, 1, 0);
		glutWireSphere(0.3, 20, 20);

		glRotatef(moonorb, 0.0, 0.0, 1.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef(moonrev, 0.0, 0.0, 1.0);
		glColor3f(.9, .8, .7);
		glutWireSphere(0.08, 10, 10);
		glPopMatrix();

		//mars
		glPushMatrix();
		glRotatef(marorb, 0.0, 0.0, 1.0);
		glTranslatef(f4, 0.2, 0.0);
		glRotatef(marrev, 0.0, 0.0, 1.0);
		glColor3f(1, 0, 0);
		glutWireSphere(0.1, 10, 10);
		glPopMatrix();

		//jupiter
		glPushMatrix();
		glRotatef(juporb, 0.0, 0.0, 1.0);
		glTranslatef(f5, 0.0, 0.0);
		glRotatef(juprev, 0.0, 0.0, 1.0);
		glColor3f(0.6, 0.1, 0.2);
		glutWireSphere(0.4, 20, 20);
		glPopMatrix();

		//saturn
		glPushMatrix();
		glRotatef(satorb, 0.0, 0.0, 1.0);
		glTranslatef(f6, 0.0, 0.0);
		glRotatef(satrev, 0.0, 0.0, 1.0);
		glColor3f(0.2, 0.1, 0.8);
		glutWireSphere(0.2, 10, 10);


		glPopMatrix();




		//uranus
		glPushMatrix();
		glRotatef(uraorb, 0.0, 0.0, 1.0);
		glTranslatef(f7, 0.0, 0.0);
		glRotatef(urarev, 0.0, 0.0, 1.0);
		glColor3f(0.0, 0.5, 1.0);
		glutWireSphere(0.2, 10, 10);
		glPopMatrix();

		//neptune
		glPushMatrix();
		glRotatef(neporb, 0.0, 0.0, 1.0);
		glTranslatef(f8, 0.2, 0.0);
		glRotatef(neprev, 0.0, 0.0, 1.0);
		glColor3f(0, 0.1, 0.1);
		glutWireSphere(0.1, 10, 10);
		glPopMatrix();
	}
	else if (choice == 2){

	}

	glFlush();

	glutSwapBuffers();
}

void ChangeWindow(GLsizei w, GLsizei h)
{
	GLfloat Ratio;
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	Ratio = (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f, Ratio, VIEW_NEAR, VIEW_FAR);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(INIT_VIEW_X, INIT_VIEW_Y, INIT_VIEW_Z);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
}

void CheckRot()
{
	// will be used to keep angles between 0.0 and 360.0 degrees
	if (sunrev > 360.0)
		sunrev -= 360.0;
	if (sunrev < 0.0)
		sunrev += 360;
	if (planetrev > 360.0)
		planetrev -= 360.0;
	if (planetrev < 0.0)
		planetrev += 360;
	if (planetorb > 360.0)
		planetorb -= 360.0;
	if (planetorb < 0.0)
		planetorb += 360;
	if (moonrev > 360.0)
		moonrev -= 360.0;
	if (moonrev < 0.0)
		moonrev += 360;
	if (moonorb > 360.0)
		moonorb -= 360.0;
	if (moonorb < 0.0)
		moonorb += 360;
	if (merrev > 360.0)
		merrev -= 360.0;
	if (merrev < 0.0)
		merrev += 360;
	if (merorb > 360.0)
		merorb -= 360.0;
	if (merorb < 0.0)
		merorb += 360;
	if (venurev > 360.0)
		venurev -= 360.0;
	if (venurev < 0.0)
		venurev += 360;
	if (venuorb > 360.0)
		venuorb -= 360.0;
	if (venuorb < 0.0)
		venuorb += 360;
	if (marrev > 360.0)
		marrev -= 360.0;
	if (marrev < 0.0)
		marrev += 360;
	if (marorb > 360.0)
		marorb -= 360.0;
	if (marorb < 0.0)
		marorb += 360;
	if (juprev > 360.0)
		juprev -= 360.0;
	if (juprev < 0.0)
		juprev += 360;
	if (juporb > 360.0)
		juporb -= 360.0;
	if (juporb < 0.0)
		juporb += 360;
	if (satrev > 360.0)
		satrev -= 360.0;
	if (satrev < 0.0)
		satrev += 360;
	if (satorb > 360.0)
		satorb -= 360.0;
	if (satorb < 0.0)
		satorb += 360;
	if (urarev > 360.0)
		urarev -= 360.0;
	if (urarev < 0.0)
		urarev += 360;
	if (uraorb > 360.0)
		uraorb -= 360.0;
	if (uraorb < 0.0)
		uraorb += 360;
	if (neprev > 360.0)
		neprev -= 360.0;
	if (neprev < 0.0)
		neprev += 360;
	if (neporb > 360.0)
		neporb -= 360.0;
	if (neporb < 0.0)
		neporb += 360;

}

void SpecialKeys(int key, int x, int y)
{
	// will be used to change rotation angles and rates
	if (key == GLUT_KEY_LEFT)
	{
		delsunrev += delang;
		delplanetorb += 1.0* delang;
		delplanetrev += 30.*delang;
		delmoonorb += 5.0*delang;
		delmoonrev += 50.0*delang;
		delmerorb += 1.5*delang;
		delmerrev += 25.0*delang;
		delvenuorb += 1.0*delang;
		delvenurev += 20.0*delang;
		delmarorb += 1.5*delang;
		delmarrev += 25.0*delang;
		deljuporb += 1.0*delang;
		deljuprev += 15.0*delang;
		delsatorb += 1.5*delang;
		delsatrev += 19.0*delang;

		deluraorb += 1.5*delang;
		delurarev += 15.0*delang;
		delneporb += 1.0*delang;
		delneprev += 10.0*delang;

	}

	if (key == GLUT_KEY_RIGHT)
	{
		delsunrev -= delang;
		delplanetorb -= 1.0* delang;
		delplanetrev -= 30.*delang;
		delmoonorb -= 5.0*delang;
		delmoonrev -= 50.0*delang;
		delmerorb -= 1.5*delang;
		delmerrev -= 25.0*delang;
		delvenuorb -= 1.0*delang;
		delvenurev -= 20.0*delang;
		delmarorb -= 1.5*delang;
		delmarrev -= 25.0*delang;
		deljuporb -= 1.0*delang;
		deljuprev -= 15.0*delang;
		delsatorb -= 1.5*delang;
		delsatrev -= 19.0*delang;
		deluraorb -= 1.8*delang;
		delurarev -= 15.0*delang;
		delneporb -= 1.0*delang;
		delneprev -= 10.0*delang;

	}

	if (key == GLUT_KEY_UP)
	{
		tilt += 1.0;
	}


	if (key == GLUT_KEY_DOWN)
	{
		tilt -= 1.0;
	}

	CheckRot();
	glutPostRedisplay();
}

void KeyPress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'f':
		if (fullscreen == 1)
		{
			glutReshapeWindow(320, 240);
			glutPositionWindow(5, 30);
		}
		else
			glutFullScreen();
		fullscreen = 1 - fullscreen;
		break;

	case 'F':
		if (fullscreen == 1)
		{
			glutReshapeWindow(320, 240);
			glutPositionWindow(5, 30);
		}
		else
			glutFullScreen();
		fullscreen = 1 - fullscreen;
		break;

	case 'Q':
		exit(1);
		break;

	case 'q':
		exit(1);
		break;
	}
	glutPostRedisplay();
}

void animate(void)
{
	// motion between frames will be controlled here
	// this function is set to run on idle
	sunrev += delsunrev;
	planetorb += delplanetorb;
	planetrev += delplanetrev;
	moonorb += delmoonorb;
	moonrev += delmoonrev;
	merorb += delmerorb;
	merrev += delmerrev;
	venuorb += delvenuorb;
	venurev += delvenurev;
	marorb += delmarorb;
	marrev += delmarrev;
	juporb += deljuporb;
	juprev += deljuprev;
	satorb += delsatorb;
	satrev += delsatrev;
	uraorb += deluraorb;
	urarev += delurarev;
	neporb += delneporb;
	neprev += delneprev;
	CheckRot();
	glutPostRedisplay();
}
void main_menu(int op){
	if (op == 1){
		choice = 0;
	}
	if (op == 2){
		choice = 1;
	}
}
void main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // double buffered window
	glutCreateWindow("Orbit Demo");                        // Graphics Window Title
	glutReshapeWindow(640, 480);                             // Graphics Window Size
	SetupRend();                                            // lighting and material properties
	glutReshapeFunc(ChangeWindow);                         // function to maintain aspect ratios
	glutKeyboardFunc(KeyPress);                            // function to handle key press
	glutSpecialFunc(SpecialKeys);                          // function to handle special keys
	glutDisplayFunc(Display);                              // graphics display function
	glutIdleFunc(animate);                                  // updates object motions
	glutCreateMenu(main_menu);
	glutAddMenuEntry("solar system", 1);
	glutAddMenuEntry("black hole", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();                                         // enters the GLUT event processing loop
}
