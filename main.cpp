#include <stdlib.h>
#include <glut.h>
#include <stdio.h>

int w=400, h=400, z=0;
int x1=0, y1=0, sudut=0, z1=0;
int skalaX =1 , skalaY=1, skalaZ=1;
int cx, cy;

void mouse(int tombol, int state, int x, int y){
cx = x-(w/2);
cy = (h/2)-y;
}

void motion (int x, int y){
cx = x-(w/2);
cy = (h/2)-y;
}



void renderScene(void){
GLfloat LightPosition[] = {10.0f, 10.0f, 20.0f, 0.0f};
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(1,1,1,1);
LightPosition[0] = cx;
LightPosition[1] = cy;

glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0,0,z);
glRotatef(sudut,x1,y1,z1);
glScalef(skalaX, skalaY, skalaZ);

//tanah
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0,4.6,0.4);
glTranslatef(-0.6, -1.5, -0.46);
glScalef(5,0.03,5);
glutSolidCube(2);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

//dinding
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.3402, 0.3412, 0.3117);
glutSolidCube(3);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

//pintu depan
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5,-0.76,0);
glTranslatef(-0.6,-0.76,1.46);
glScalef(9,15,1);
glutSolidCube(0.1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();


//pintu belakang
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5,0.8,0);
glTranslatef(-0.6,-0.76,-1.46);
glRotatef(180,0,1,0);
glScalef(9,15,1);
glutSolidCube(0.1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

//atap
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(1.0f,0.4f,0.0f);
glTranslatef(0,1.5,0);
glRotatef(45,0,1,0);
glScalef(3,1,3);
glutSolidOctahedron();
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

//pagar depan
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslatef(-3.8, -0.8, 2.6);
glRotatef(90,0,1,0);
glScalef(-0.1, 0.6, 0.8);
pagar();
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();


//kanopi depan
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.76, 1, 0.3);
glTranslatef(-0.6,0.5,1.8);
glScalef(1.3, 0.1, 1.2);
glutSolidCube(1);
glEnable(GL_COLOR_MATERIAL);
glPopMatrix();

//tiang depan kiri
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.45, 0.11, 0.3);
glTranslatef(-1.2,-0.5,2.2);
glScalef(0.1, 2.06, 0.1);
glutSolidCube(1);
glEnable(GL_COLOR_MATERIAL);
glPopMatrix();

//tiang depan kanan
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.45, 0.11, 0.3);
glTranslatef(0,-0.5,2.2);
glScalef(0.1, 2.06, 0.1);
glutSolidCube(1);
glEnable(GL_COLOR_MATERIAL);
glPopMatrix();


glutSwapBuffers();
}

void resize(int w1, int h1){
glViewport(0,0,w1,h1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void myKeyboard(unsigned char key, int x, int y){
if (key == 'x') {
y1=0;
x1=1;
z1=0;
sudut+=-10;}
else if (key == 'y') {
y1=1;
x1=0;
z1=0;
sudut+=-10;}
else if (key == 'z') {
y1=0;
x1=0;
z1=1;
sudut+=-10;
}
}

void mySpecialKeyboard(int key, int x, int y){
switch(key){
case GLUT_KEY_UP :
z +=3;
break;

case GLUT_KEY_DOWN :
z -=3;
break;
}
}


void init(){
GLfloat LightPosition[] = {10.0f, 10.0f, 20.0f, 0.0f};
GLfloat LightAmbient[] = {0.0f, 1.0f, 0.0f, 1.0f};
GLfloat LightDiffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat LightSpecular[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat Shine[] = { 80 };

glShadeModel(GL_SMOOTH);
glClearColor(0.0f,0.0f,0.0f,0.5f);
glClearDepth(1.0f);
glEnable(GL_DEPTH_TEST);
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

glMaterialfv(GL_FRONT, GL_SPECULAR, LightSpecular);
glMaterialfv(GL_FRONT, GL_SHININESS, Shine);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
return;
}
void timer(int value){
glutPostRedisplay();
glutTimerFunc(50,timer,0);
}
void main (int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
glutInitWindowPosition(100,100);
glutInitWindowSize(480,480);
glutCreateWindow("Rumah Deni & Magfir - 3D");
glutDisplayFunc(renderScene);
glutReshapeFunc(resize);
glutKeyboardFunc(myKeyboard);
glutSpecialFunc(mySpecialKeyboard);
glutTimerFunc(1,timer,0);
glutMouseFunc(mouse);
glutPassiveMotionFunc(motion);
init();
glutMainLoop();
}
