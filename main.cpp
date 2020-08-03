#include <iostream>
#include <GL/glut.h>
#include<math.h>
#include<fstream>
#include "blenerToOpengl.h"
#include <GL/freeglut.h>
#include <strings.h>
using namespace std;
int pany = 0,panx = 0,roty = 0, rotx= 0, panz =0,rotz=0.0;
float zom=1.0;
float xpos=1.0;
float cri=0;
int d=0;
float manpos=4.1;
float carpos=26.0;
char str[100];
int flag=0;
/*!this function enables the GL_DEPTH_TEST and clears the color of the back screen
*/
void init()
{
    glEnable(GL_DEPTH_TEST);//use to enable GL graphic capabilties
    /*!glClearColor gives the background color of the window
	*/
    glClearColor(0.5294,0.8078,0.9803,1.0);
    glDepthFunc(GL_LEQUAL);
    ifstream fin;
}
/*!this function makes lines when starting and ending point of
   a line is given return type is void and its argument are the start and end pointa
   of the line and also a variable color which decides the color of the line
  */
void lines(float a, float b, float c,float d,float e,float f,int color)
{
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    if(color==1)
        glColor3f(0.5,0.2,0);
    glVertex3f(a,b,c);// starting point
    glVertex3f(d,e,f);// ending point
    glEnd();
    glFlush();
}

/*!this function makes circle when radius of a circle is given return type is void and its argument are
    radius of the circle and also a variable color which decides the color of the circle
  */
void circle(float radius,int color)
{
   glBegin(GL_LINE_LOOP);
   if(color==0)
    glColor3f(0,0,1.0);
   if(color==1)
        glColor3f(1,0.7,0);
   if(color==2)
        glColor3f(0,0,0);
   for (int i=0; i < 360; i++)
   {
      float degInRad = i*0.017333;
      glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
   }
   glEnd();
}
/*! this function makes all the primitives for the 3d-viewport like road,zebra crossing,building
    the return type of this function is void and also the arguments of this function is also void
*/
void theSetup()
{

    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0,-11);
    glVertex3f(-1,0,29);
    glVertex3f(29,0,29);
    glVertex3f(29,0,-11);
    glEnd();//used for road

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-1,0.5,29);
    glVertex3f(-1,0,29);
    glVertex3f(4,0,29);
    glVertex3f(4,0.5,29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-1,0.5,-11);
    glVertex3f(-1,0,-11);
    glVertex3f(4,0,-11);
    glVertex3f(4,0.5,-11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-1,0.5,-11);
    glVertex3f(-1,0.5,29);
    glVertex3f(4,0.5,29);
    glVertex3f(4,0.5,-11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(4,0.5,-11);
    glVertex3f(4,0.5,29);
    glVertex3f(4,0,29);
    glVertex3f(4,0,-11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-1,0.5,-11);
    glVertex3f(-1,0.5,29);
    glVertex3f(-1,0,29);
    glVertex3f(-1,0,-11);
    glEnd();// used for left pedestrian

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24,0.5,-11);
    glVertex3f(24,0.5,29);
    glVertex3f(29,0.5,29);
    glVertex3f(29,0.5,-11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24,0.5,29);
    glVertex3f(24,0,29);
    glVertex3f(29,0,29);
    glVertex3f(29,0.5,29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24,0.5,-11);
    glVertex3f(24,0,-11);
    glVertex3f(29,0,-11);
    glVertex3f(29,0.5,-11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(29,0,-11);
    glVertex3f(29,0,29);
    glVertex3f(29,0.5,29);
    glVertex3f(29,0.5,-11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24,0,-11);
    glVertex3f(24,0,29);
    glVertex3f(24,0.5,29);
    glVertex3f(24,0.5,-11);
    glEnd();//used for right pedestrian

    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(-1,0.55,-11.0);
    glVertex3f(-1,0.55,-10.0);
    glVertex3f(4,0.55,-10.0);
    glVertex3f(4,0.55,-11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(-1,0.55,-8.0);
    glVertex3f(-1,0.55,-7.0);
    glVertex3f(4,0.55,-7.0);
    glVertex3f(4,0.55,-8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(-1,0.55,-5.0);
    glVertex3f(-1,0.55,-4.0);
    glVertex3f(4,0.55,-4.0);
    glVertex3f(4,0.55,-5.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(-1,0.55,-2.0);
    glVertex3f(-1,0.55,-1.0);
    glVertex3f(4,0.55,-1.0);
    glVertex3f(4,0.55,-2.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(-1,0.55,1.0);
    glVertex3f(-1,0.55,2.0);
    glVertex3f(4,0.55,2.0);
    glVertex3f(4,0.55,1.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,4.0);
    glVertex3f(-1,0.55,5.0);
    glVertex3f(4,0.55,5.0);
    glVertex3f(4,0.55,4.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,7.0);
    glVertex3f(-1,0.55,8.0);
    glVertex3f(4,0.55,8.0);
    glVertex3f(4,0.55,7.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,10.0);
    glVertex3f(-1,0.55,11.0);
    glVertex3f(4,0.55,11.0);
    glVertex3f(4,0.55,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,13.0);
    glVertex3f(-1,0.55,14.0);
    glVertex3f(4,0.55,14.0);
    glVertex3f(4,0.55,13.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,16.0);
    glVertex3f(-1,0.55,17.0);
    glVertex3f(4,0.55,17.0);
    glVertex3f(4,0.55,16.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,19.0);
    glVertex3f(-1,0.55,20.0);
    glVertex3f(4,0.55,20.0);
    glVertex3f(4,0.55,19.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,22.0);
    glVertex3f(-1,0.55,23.0);
    glVertex3f(4,0.55,23.0);
    glVertex3f(4,0.55,22.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,25.0);
    glVertex3f(-1,0.55,26.0);
    glVertex3f(4,0.55,26.0);
    glVertex3f(4,0.55,25.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(-1,0.55,28.0);
    glVertex3f(-1,0.55,29.0);
    glVertex3f(4,0.55,29.0);
    glVertex3f(4,0.55,28.0);
    glEnd();// left pedestrian k yellow yahan khatam

     glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(24,0.55,-11.0);
    glVertex3f(24,0.55,-10.0);
    glVertex3f(29,0.55,-10.0);
    glVertex3f(29,0.55,-11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(24,0.55,-8.0);
    glVertex3f(24,0.55,-7.0);
    glVertex3f(29,0.55,-7.0);
    glVertex3f(29,0.55,-8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(24,0.55,-5.0);
    glVertex3f(24,0.55,-4.0);
    glVertex3f(29,0.55,-4.0);
    glVertex3f(29,0.55,-5.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(24,0.55,-2.0);
    glVertex3f(24,0.55,-1.0);
    glVertex3f(29,0.55,-1.0);
    glVertex3f(29,0.55,-2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824,0.658824,0.658824);// used for yellow strips
    glVertex3f(24,0.6,1.0);
    glVertex3f(24,0.6,2.0);
    glVertex3f(29,0.6,2.0);
    glVertex3f(29,0.6,1.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,4.0);
    glVertex3f(24,0.6,5.0);
    glVertex3f(29,0.6,5.0);
    glVertex3f(29,0.6,4.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,7.0);
    glVertex3f(24,0.6,8.0);
    glVertex3f(29,0.6,8.0);
    glVertex3f(29,0.6,7.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,10.0);
    glVertex3f(24,0.6,11.0);
    glVertex3f(29,0.6,11.0);
    glVertex3f(29,0.6,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,13.0);
    glVertex3f(24,0.6,14.0);
    glVertex3f(29,0.6,14.0);
    glVertex3f(29,0.6,13.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,16.0);
    glVertex3f(24,0.6,17.0);
    glVertex3f(29,0.6,17.0);
    glVertex3f(29,0.6,16.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,19.0);
    glVertex3f(24,0.6,20.0);
    glVertex3f(29,0.6,20.0);
    glVertex3f(29,0.6,19.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,22.0);
    glVertex3f(24,0.6,23.0);
    glVertex3f(29,0.6,23.0);
    glVertex3f(29,0.6,22.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,25.0);
    glVertex3f(24,0.6,26.0);
    glVertex3f(29,0.6,26.0);
    glVertex3f(29,0.6,25.0);
    glEnd();

    glBegin(GL_QUADS);// used for yellow strips
    glColor3f(0.658824,0.658824,0.658824);
    glVertex3f(24,0.6,28.0);
    glVertex3f(24,0.6,29.0);
    glVertex3f(29,0.6,29.0);
    glVertex3f(29,0.6,28.0);
    glEnd();// here the yellow strip for right pedestrian end

    glBegin(GL_QUADS);// used for zebra crossing
    glColor3f(1.0,1.0,1.0);
    glVertex3f(4,0.01,10.0);
    glVertex3f(4,0.01,16.0);
    glVertex3f(6,0.01,16.0);
    glVertex3f(6,0.01,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for zebra crossing
    glColor3f(1.0,1.0,1.0);
    glVertex3f(7,0.01,10.0);
    glVertex3f(7,0.01,16.0);
    glVertex3f(9,0.01,16.0);
    glVertex3f(9,0.01,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for zebra crossing
    glColor3f(1.0,1.0,1.0);
    glVertex3f(10,0.01,10.0);
    glVertex3f(10,0.01,16.0);
    glVertex3f(12,0.01,16.0);
    glVertex3f(12,0.01,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for zebra crossing
    glColor3f(1.0,1.0,1.0);
    glVertex3f(13,0.01,10.0);
    glVertex3f(13,0.01,16.0);
    glVertex3f(15,0.01,16.0);
    glVertex3f(15,0.01,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for zebra crossing
    glColor3f(1.0,1.0,1.0);
    glVertex3f(16,0.01,10.0);
    glVertex3f(16,0.01,16.0);
    glVertex3f(18,0.01,16.0);
    glVertex3f(18,0.01,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for zebra crossing
    glColor3f(1.0,1.0,1.0);
    glVertex3f(19,0.01,10.0);
    glVertex3f(19,0.01,16.0);
    glVertex3f(21,0.01,16.0);
    glVertex3f(21,0.01,10.0);
    glEnd();

    glBegin(GL_QUADS);// used for zebra crossing
    glColor3f(1.0,1.0,1.0);
    glVertex3f(22,0.01,10.0);
    glVertex3f(22,0.01,16.0);
    glVertex3f(24,0.01,16.0);
    glVertex3f(24,0.01,10.0);
    glEnd();

    glBegin(GL_QUADS);//orange building
    glColor3f(1,0.5,0.0);
    glVertex3f(25,10,-11);
    glVertex3f(25,0.01,-11);
    glVertex3f(25,0.01,11);
    glVertex3f(25,10,11);
    glEnd();

    glBegin(GL_QUADS);// orange building
    glColor3f(1.0,0.5,0.0);
    glVertex3f(29,10,-11);
    glVertex3f(29,0.01,-11);
    glVertex3f(29,0.01,11);
    glVertex3f(29,10,11);
    glEnd();

    glBegin(GL_QUADS);//orange building
    glColor3f(1.0,0.5,0.0);
    glVertex3f(25,10,-11);
    glVertex3f(25,10,11);
    glVertex3f(29,10,11);
    glVertex3f(29,10,-11);
    glEnd();

    glBegin(GL_QUADS);//orange building
    glColor3f(1.0,0.5,0.0);
    glVertex3f(25,10,-11);
    glVertex3f(25,.01,-11);
    glVertex3f(29,.01,-11);
    glVertex3f(29,10,-11);
    glEnd();

    glBegin(GL_QUADS);//orange building
    glColor3f(1.0,0.5,0.0);
    glVertex3f(25,10,11);
    glVertex3f(25,.01,11);
    glVertex3f(29,.01,11);
    glVertex3f(29,10,11);
    glEnd();

    glBegin(GL_QUADS);// side face brown window
    glColor3f(0.36,0.25,0.20);
    glVertex3f(24.75,7,-8);
    glVertex3f(24.75,7,-1);
    glVertex3f(24.75,9,-1);
    glVertex3f(24.75,9,-8);
    glEnd();

    glBegin(GL_QUADS);// side face brown window
    glColor3f(0.36,0.25,0.20);
    glVertex3f(24.5,7,9);
    glVertex3f(24.5,7,2);
    glVertex3f(24.5,5,2);
    glVertex3f(24.5,5,9);
    glEnd();

    glBegin(GL_QUADS);// side face brown window
    glColor3f(0.36,0.25,0.20);
    glVertex3f(24.75,3,-8);
    glVertex3f(24.75,3,-1);
    glVertex3f(24.75,1,-1);
    glVertex3f(24.75,1,-8);
    glEnd();

    glBegin(GL_QUADS);//front face window
    glColor3f(0.36,0.25,0.20);
    glVertex3f(25.5,8,11.1);
    glVertex3f(25.5,7,11.1);
    glVertex3f(28.5,7,11.1);
    glVertex3f(28.5,8,11.1);
    glEnd();

    glBegin(GL_QUADS);// door
    glColor3f(0.36,0.25,0.20);
    glVertex3f(26,4,11.1);
    glVertex3f(26,0,11.1);
    glVertex3f(28,0,11.1);
    glVertex3f(28,4,11.1);
    glEnd();

    glPopMatrix();
}
/*! this function reshapes the window when maximised or minimised by
    using glViewport,loadidentity functions of glut.h
*/
void reshape( int w , int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35,(float)w/(float)h,1.0,1000);
    glMatrixMode(GL_MODELVIEW);
}

/*! this function makes bench for the 3d-viewport the return type of this function is void. the
    arguments of this function are x,y,z position of the bench and rot for the orientation of the bench
*/
void bench(int x,int y,int z,int rot)
{
    glPushMatrix();

    glTranslatef(x,y,z);
    glRotatef(rot,0,1,0);

    glBegin(GL_QUADS);// the square used for back rest of the chair
    glColor3f(0.196078,0.8,0.196078);
    glVertex3f(0,0,0);
    glVertex3f(5 ,0,0);
    glVertex3f(5,-0.6,0.1);
    glVertex3f(0,-0.6,0.1);
    glEnd();

    glColor3f(0,0,0);
    lines(0,-0.58,0.1,5,-0.58,0.1,0);
    lines(0,-0.6,0.1,0,0,0,0);
    lines(0,0,0,5,0,0,0);
    lines(5,0,0,5,-0.6,0.1,0);
    lines(0,-0.6,0.1,0,-0.6,0.7,0);
    lines(0,-0.6,0.7,5,-0.6,0.7,0);
    lines(5,-0.6,0.7,5,-0.6,0.1,0);


    glBegin(GL_QUADS); // the square used for the base of the chair
    glColor3f(0.196078,0.8,0.196078);
    glVertex3f(0,-0.6,0.1);
    glVertex3f(5,-0.6,0.1);
    glVertex3f(5,-0.6,0.7);
    glVertex3f(0,-0.6,0.7);
    glEnd();

    lines(0,-0.6,0.1,0,-1,0.1,0);
    lines(0,-0.6,0.7,0,-1,0.7,0);
    lines(5,-0.6,0.1,5,-1,0.1,0);
    lines(5,-0.6,0.7,5,-1,0.7,0);

    glTranslatef(0,-0.6,0.4);
    glRotatef(90,0,1,0);
    circle(0.5,0);
    glTranslatef(0,0,5);
    circle(0.5,0);
    glTranslatef(0,-0.6,0.4);
    glRotatef(-90,0,1,0);
    glTranslatef(0,0.6,-0.4);



    glPopMatrix();

}
/*! this function makes seesaw for the 3d-viewport the return type of this function is void. the
    arguments of this function are also void
*/

void seesaw()
{
    glPushMatrix();
    glTranslatef(26,1.55,15);
    glColor3f(0,0,0);

    glTranslatef(0,-0.75,0);
    circle(0.75,0);

    glTranslatef(0,0,1);
    circle(0.75,0);

    glColor3f(1,0,0);
    glTranslatef(0,0.75,-1);
    glRotatef(cri,0,0,1);

    glBegin(GL_QUADS);
    glVertex3f(-2.5,0,0);
    glVertex3f(2.5,0,0);
    glVertex3f(2.5,0,1);
    glVertex3f(-2.5,0,1);
    glEnd();

    glTranslatef(1,0.75,0);
    glTranslatef(0,-0.5,0.5);
    glPopMatrix();
}
/*! this function makes stick person for the 3d-viewport the return type of this function is void. the
    arguments of this function are also void
*/
void person()
{
    glPushMatrix();
    glTranslatef(manpos,4,13);
    glRotatef(-90,0,1,0);
    circle(1.0,1);

    glTranslatef(0,-1,0);
    glBegin(GL_LINES);
    glColor3f(1,0.7,0);
    glVertex3f(0,0,0);
    glVertex3f(0,-2,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0.7,0);
    glVertex3f(0,-2,0);
    glVertex3f(-1,-3,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0.7,0);
    glVertex3f(0,-2,0);
    glVertex3f(1,-3,0);
    glEnd();


    glPopMatrix();
}
/*! this function makes car for the 3d-viewport the return type of this function is void. the
    arguments of this function are also void
*/
void car()
{
    glPushMatrix();

    glColor3f(1,0,0);
    glTranslatef(6,0.5,carpos);
    glRotatef(90,0,1,0);
    circle(0.5,2);

    glTranslatef(3,0,0);
    circle(0.5,2);

    glTranslatef(0,0,2);
    circle(0.5,2);

    glTranslatef(-3,0,0);
    circle(0.5,2);//till here used to make wheels

    glTranslatef(0,0.511,0.0);

    glBegin(GL_QUADS);// used to make the cube above car
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(3,0,0);
    glColor3f(0,1,0);
    glVertex3f(+3,0,-2);
    glVertex3f(0,0,-2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(0,2,0);
    glVertex3f(3,2,0);
    glColor3f(0,1,0);
    glVertex3f(+3,2,-2);
    glVertex3f(0,2,-2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(2,0,0);
    glColor3f(0,1,0);
    glVertex3f(2,2,0);
    glVertex3f(0,2,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(0,0,-2);
    glVertex3f(2,0,-2);
    glColor3f(0,1,0);
    glVertex3f(2,2,-2);
    glVertex3f(0,2,-2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(0,0,-2);
    glColor3f(0,1,0);
    glVertex3f(0,2,-2);
    glVertex3f(0,2,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(3,0,0);
    glVertex3f(3,0,-2);
    glColor3f(0,1,0);
    glVertex3f(3,2,-2);
    glVertex3f(3,2,0);
    glEnd();// the cuboid of car has ended here

    glPopMatrix();
}
/*! this function makes tree for the 3d-viewport the return type of this function is void. the
    arguments of this function are also void. This function is used to read the vertices and faces from the blender file to make complex objects.
*/
void tree()
{
    glPushMatrix();
    glTranslatef(3,4,20);
    glColor3f(0,1,0);
    Render r;
    strcpy(str,"C:\\Users\\Dell\\Desktop\\roadSide\\tree.txt");
    r.load(str);
    r.draw1(str);
    r.draw2(1);
    r.deletememory();
    glPopMatrix();
}
/*! this function makes dustbin  for the 3d-viewport the return type of this function is void. the
    arguments of this function are also void
*/
void dustbin()
{
    glPushMatrix();
    glTranslatef(22,2,29);
    glColor3f(0.9,0.1,0.3);
    GLUquadricObj *p=gluNewQuadric();
    glRotatef(-90,1,0,0);
    gluCylinder(p,0.75,1.1,2,50,50);
    glTranslatef(0,0,2);
    circle(1.1,2);
    glTranslatef(0,0,-1.9999999);
    circle(0.75,2);
    glTranslatef(0,1,2);
    lines(0,0,0,0,0,1,1);
    glTranslatef(0,-2,0);
    lines(0,0,0,0,0,1,1);

    glBegin(GL_QUADS);
    glColor3f(1,0,0.7);
    glVertex3f(0,0,1);
    glVertex3f(0,2,1);
    glVertex3f(0,2,0.5);
    glVertex3f(0,0,0.5);
    glEnd();
    glPopMatrix();
}
/*! this function makes traffic light for the 3d-viewport the return type of this function is void. the
    arguments of this function are also voi
*/
void trafficLight()
{
    glPushMatrix();
    glTranslatef(23,0.2,-7);
    glRotatef(-90,1,0,0);
    glColor3f(1,0.9,0);
    GLUquadricObj *p=gluNewQuadric();
    gluCylinder(p,0.5,0.5,10,50,50);
    glRotatef(-90,0,1,0);
    glTranslatef(10,0,-0.5);
    gluCylinder(p,0.5,0.5,15,50,50);

    glBegin(GL_QUADS);
    glColor3f(1,0.9,0.0);
    glVertex3f(0,0,14.5);
    glVertex3f(0,0,15);
    glVertex3f(-1.3,0,15);
    glVertex3f(-1.3,0,14.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0.9,0.0);
    glVertex3f(0,0,9.5);
    glVertex3f(0,0,10);
    glVertex3f(-1.3,0,10);
    glVertex3f(-1.3,0,9.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0.0);
    glVertex3f(-1.3,0,15);
    glVertex3f(-1.3,0,9.5);
    glVertex3f(-3.3,0,9.5);
    glVertex3f(-3.3,0,15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0.0);
    glVertex3f(-1.3,0,13.75);
    glVertex3f(-1.3,0,14.75);
    glVertex3f(-3.3,0,14.75);
    glVertex3f(-3.3,0,13.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0.5,0.0);
    glVertex3f(-1.3,0,11.75);
    glVertex3f(-1.3,0,12.75);
    glVertex3f(-3.3,0,12.75);
    glVertex3f(-3.3,0,11.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1.0,0.0);
    glVertex3f(-1.3,0,9.75);
    glVertex3f(-1.3,0,10.75);
    glVertex3f(-3.3,0,10.75);
    glVertex3f(-3.3,0,9.75);
    glEnd();

    glPopMatrix();

}
/*!
    this function is used to display all the objects which are made by simple transformation in order to give the desired output
*/
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GLUT_RGB);
    glLoadIdentity();
    glTranslatef(-21,10,-70);
    glRotatef(25,1,0,0);// used to see all the diffrent faces
    glTranslatef(panx,0,0);
    glTranslatef(0,pany,0);
    glTranslatef(0,0,panz);
    glTranslatef(9,0,9);
    glRotatef(roty,0,1,0);
    glRotatef(rotx,1,0,0);
    glRotatef(rotz,0,0,1);
    glScalef(zom,zom,zom);
    theSetup();
    bench(2,3,30,-270);
    bench(2,2.7,-3,-270);
    bench(26,3,25,-90);
    seesaw();
    person();
    car();
    tree();
    dustbin();
    trafficLight();
    glutSwapBuffers();
}
/*!
    this function is used to get the keyboard input to zoom,pan,translate,rotate different objects
    to make the interactive function
*/
void keyboard(unsigned char key, int x,int y)
{

    if(key=='t')
     {
         if(d==0)
         {
             cri-= 2.0;
         }

         if(cri==-26.0)
         {
             d=1;
         }
         if(d==1)
         {
             cri+=2.0;
         }
         if(cri==26.0)
         {
             d=0;
         }
     }
    if(key=='y')
    {
        if(manpos<24)
            manpos+=0.3;
    }
    if(key=='z')
    {
        if(manpos>4.1)
            manpos-=0.3;
    }

    if(key=='p')
    {
        if(carpos>-7)
            carpos-=0.3;
    }

        if(key=='q')
    {
        if(carpos<26)
            carpos+=0.3;
    }

    if(key=='1'){zom+=0.1;} if(key=='2'){zom-=0.1;}
    if(key=='a'){panx+=1;} if(key=='b'){panx-=1;}
    if(key=='c'){pany+=1;} if(key=='d'){pany-=1;}
    if(key=='e'){panz+=1;} if(key=='f'){panz-=1;}
    if(key=='i'){roty+=5;} if(key=='j'){roty-=5;}
    if(key=='k'){rotx+=5;} if(key=='l'){rotx-=5;}
    if(key=='m'){rotz+=5;}  if(key=='n'){rotz-=5;}

    glutPostRedisplay();
}

int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    /*!glutInitDisplayMode sets the display mode as GLUT_SINGLE orGLUT_RGB
	*/
    glutInitDisplayMode(GLUT_DOUBLE);
    /*!glutInitWindowSize sets the windows size according to the arguments given
	*/
    glutInitWindowSize(800,600);
    /*! glutCreateWindow gives the title to the window which is given as string as arguments
    */
    glutCreateWindow("Road side view");
    init();
    /*!register callback when a window is maximised and minimised
    */
    glutReshapeFunc(reshape);
    /*! determines the normal plane for the windows that need to be displayed
    */
    glutDisplayFunc(display);
    /*!register callbacks for keyboard events that occur when you press a key
    */
    glutKeyboardFunc(keyboard);
    /*!glutMainLoop() is a function that loops within itself, processing events and triggering your callback functions when necessary
    */
    glutMainLoop();

    return 0;
}
