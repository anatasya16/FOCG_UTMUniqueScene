#include <Windows.h>
#include <iostream>
#include <fstream>
#include<stdio.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#define PI 3.1416
using namespace std;

void introscreen();
GLint i, j, k;
GLfloat sun_x = 0, sun_y = 0;
GLfloat ax = 0, bx = 0, cx = 0, dx = 0, str = 500.0, mn = 500.0;
GLfloat sr = 0.0, sg = 0.749, sb = 1.0;
///////////////////////////////////////////////////////////////////

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1000.0, 0.0, 500.0, 0.0, 1.0);
}

////////////////////*** BACKGROUND ***//////////////////////
void Sky() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.4, 0.0);
    glVertex2d(0, 0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2d(0, 1900);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2d(1900, 1900);
    glColor3f(1.0, 0.4, 1.0);
    glVertex2d(1900, 0);

    glEnd();
}

/////////////////*** OBJECT MODELS ***///////////////////

///***STRING***///
void renderbitmap(float x, float y, void* font, char* string) {
    char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void introscreen() {
    glColor3f(1.0f, 0.9f, 0.3f);
    char buf[100] = { 0 };
    sprintf_s(buf, "#IamUTM");
    renderbitmap(-120, 40, GLUT_BITMAP_TIMES_ROMAN_24, buf);

}

///***SHAPES***///
void circle(GLdouble rad)
{
	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;

	glBegin(GL_POLYGON);
	{
		for (i = 0; i <= 50; i++, theta += delTheta)
		{
			glVertex2f(rad * cos(theta), rad * sin(theta));
		}
	}
	glEnd();
}

void Sun_Model() {
	glPushMatrix();
    glTranslatef(500, 300, 0);
    glScalef(1.2, 1, 0);
	circle(30);
	glPopMatrix();
}

    //Cloud_Model
void cloud_model_one() {
	glColor3f(1.25, 0.924, 0.930);

	///Top_Left
	glPushMatrix();
	glTranslatef(320, 210, 0);
	circle(15);
	glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right
    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(16);
    glPopMatrix();

    ///middle_Fill
    glPushMatrix();
    glTranslatef(355, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305, 204, 0);
    circle(10);
    glPopMatrix();
}

void cloud_model_Two() {
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305, 205, 0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334, 207, 0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320, 207, 0);
    circle(10);
    glPopMatrix();
}

void cloud_model_Three() {
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300, 200, 0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340, 220, 0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380, 200, 0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360, 190, 0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320, 190, 0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340, 190, 0);
    circle(20);
    glPopMatrix();
}

void field() {
    ///Field
    glBegin(GL_POLYGON);
    glColor3f(0.533, 1.393, 0.3);
    glVertex2i(0, 0);
    glVertex2i(0, 70);
    glVertex2i(1000, 70);
    glVertex2i(1000, 0);
    glEnd();


    ///Field_Shadow_1
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.3);
    glVertex2i(0, 0);
    glVertex2i(0, 50);
    glVertex2i(500, 0);
    glEnd();

    ///Field_Shadow_2
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.3);
    glVertex2i(500, 0);
    glVertex2i(1000, 50);
    glVertex2i(1000, 0);
    glEnd();
}

//Hill_Model
void hill_big() {
    ///Hill_Big
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);
    glEnd();

    ///Hill_Big_Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.33, 0.28);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(166, 150);
    glVertex2i(200, 145);
    glVertex2i(160, 70);
    glEnd();

}
void hill_small() {
    ///Hill_Small
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(250, 100);
    glVertex2i(310, 175);
    glVertex2i(370, 100);
    glEnd();

    ///Hill_Small_Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.06, 0.18, 0.31);
    glVertex2i(250, 100);
    glVertex2i(310, 175);
    glVertex2i(298, 136);
    glVertex2i(320, 133);
    glVertex2i(308, 100);
    glEnd();
}

    //Tree_Model
void Tree_Model_One() {
    glPushMatrix();
    glTranslatef(110, 110, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110, 100, 0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(109, 70);
    glVertex2f(109, 90);
    glVertex2f(111, 90);
    glVertex2f(111, 70);
    glEnd();

}
void Tree_Model_Two() {
    glPushMatrix();
    glTranslatef(130, 130, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125, 126, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135, 126, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 125, 0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(129, 110);
    glVertex2f(129, 124);
    glVertex2f(131, 124);
    glVertex2f(131, 110);
    glEnd();
}

void Tree_Model_Three() {
    glBegin(GL_POLYGON);
    glVertex2f(125, 123);
    glVertex2f(133, 145);
    glVertex2f(141, 123);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(132, 110);
    glVertex2f(132, 124);
    glVertex2f(134, 124);
    glVertex2f(134, 110);
    glEnd();
}

    //Tilla_Model
void Tilla_One_Model() {
    ///Tilla
    glBegin(GL_POLYGON);
    glColor3f(0.01, 0.9, 0.35);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(230, 110);
    glVertex2i(230, 70);
    glEnd();

}

void Tilla_Two_Model() {
    glColor3f(0.01, 0.9, 0.35);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430, 90, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420, 87, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390, 70, 0);
    circle(30);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(445, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455, 75, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465, 70, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470, 65, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480, 60, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485, 55, 0);
    circle(20);
    glPopMatrix();
}

void Tilla_Three_Model() {
    ///Tilla
    glBegin(GL_POLYGON);
    glColor3f(0.01, 0.9, 0.35);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(300, 110);
    glVertex2i(300, 70);
    glEnd();
}


    //bird
void birdie() {
    //1
    glColor3f(0.3f, 0.3f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-600, 265);
    glVertex2f(-630, 265);
    glVertex2f(-630, 250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-630, 275);
    glVertex2f(-640, 275);
    glVertex2f(-630, 265);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glVertex2f(-700, 285);
    glVertex2f(-730, 285);
    glVertex2f(-730, 270);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-730, 295);
    glVertex2f(-740, 295);
    glVertex2f(-730, 285);
    glEnd();


    //3

    glBegin(GL_POLYGON);
    glVertex2f(-850, 285);
    glVertex2f(-880, 285);
    glVertex2f(-880, 270);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-880, 295);
    glVertex2f(-890, 295);
    glVertex2f(-880, 285);
    glEnd();
}

    //Mosque_Model
void Mosque_Roof_Shape() {
    glPushMatrix();
    glTranslatef(332.5, 129, 0);
    glScalef(1.07, 0.87, 0);
    circle(40);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.222, 0.7, 0.7);
    glVertex2i(290, 115);
    glVertex2i(290, 130);
    glVertex2i(375, 130);
    glVertex2i(375, 115);
    glEnd();
}

void Mosque_Roof_MoonStar() {
    //The_Stick
    glBegin(GL_POLYGON);
    glColor3f(0.111, 0.4, 0.4);
    glVertex2f(109, 70);
    glVertex2f(109, 90);
    glVertex2f(111, 90);
    glVertex2f(111, 70);
    glEnd();

    //Moon
    glColor3f(0.111, 0.4, 0.4);
    glPushMatrix();
    glTranslatef(110, 100, 0);
    glScalef(1.07, 0.87, 0);
    circle(15);
    glPopMatrix();

    //Moon_BG
    glColor3f(0.999, 0.35, 0.207);
    glPushMatrix();
    glTranslatef(105, 103, 0);
    glScalef(1.07, 0.87, 0);
    circle(13);
    glPopMatrix();
}

void Mosque_Fence() {
    ///Mosque_Fence_1
    glBegin(GL_POLYGON);
    glColor3f(0.333, 0.83, 0.83);
    glVertex2i(380, 120);
    glVertex2i(368, 132);
    glVertex2i(437, 132);
    glVertex2i(425, 120);
    glEnd();

    ///Mosque_Fence_2
    glBegin(GL_POLYGON);
    glColor3f(0.222, 0.7, 0.7);
    glVertex2i(368, 132);
    glVertex2i(368, 146);
    glVertex2i(437, 146);
    glVertex2i(437, 132);
    glEnd();
}

void Mosque_Wall_Model1() {
    ///Mosque_Wall_M1_1
    glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
    glVertex2i(230, 30);
    glVertex2i(230, 100);
    glVertex2i(290, 100);
    glVertex2i(290, 30);
    glEnd();

    ///Mosque_Wall_M1_2
    glBegin(GL_POLYGON);
    glColor3f(.204, .570, .730);
    glVertex2i(220, 88);
    glVertex2i(220, 108);
    glVertex2i(290, 108);
    glVertex2i(290, 88);
    glEnd();

    ///Mosque_Wall_M1_3
    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(265, 70);
    glVertex2i(265, 115);
    glVertex2i(350, 115);
    glVertex2i(350, 70);
    glEnd();

    ///Mosque_Wall_M1_3_Shadow
    glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
    glVertex2i(265, 70);
    glVertex2i(330, 115);
    glVertex2i(350, 115);
    glVertex2i(350, 70);
    glEnd();

    ///Mosque_Wall_M1_4
    glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
    glVertex2i(350, 30);
    glVertex2i(350, 100);
    glVertex2i(435, 100);
    glVertex2i(435, 30);
    glEnd();

    ///Mosque_Wall_M1_5
    glBegin(GL_POLYGON);
    glColor3f(.280, .540, .700);
    glVertex2i(350, 88);
    glVertex2i(350, 108);
    glVertex2i(445, 108);
    glVertex2i(445, 88);
    glEnd();
}

void Mosque_Wall_Model2() {
    ///Mosque_Wall_M2_1
    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(380, 70);
    glVertex2i(380, 122);
    glVertex2i(425, 122);
    glVertex2i(425, 70);
    glEnd();

    ///Mosque_Wall_M2_Shadow
    glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
    glVertex2i(380, 70);
    glVertex2i(425, 105);
    glVertex2i(425, 70);
    glEnd();

    Mosque_Fence();
}

void Mosque_Wall_Model3() {
    //Roof_Triangle_1
    glBegin(GL_TRIANGLES);
    glColor3f(0.111, 0.4, 0.4);
    glVertex2i(368, 145);
    glVertex2i(402.5, 300);
    glVertex2i(437, 145);
    glEnd();

    //Roof_Triangle_2
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.3, 0.3);
    glVertex2i(393, 260);
    glVertex2i(402.5, 300);
    glVertex2i(411, 260);
    glEnd();

    //Mosque_Wall_M3_1
    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(380, 40);
    glVertex2i(380, 130);
    glVertex2i(425, 130);
    glVertex2i(425, 40);
    glEnd();

    ///Mosque_Wall_M3_Shadow
    glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
    glVertex2i(380, 40);
    glVertex2i(425, 75);
    glVertex2i(425, 40);
    glEnd();

    Mosque_Fence();
}

void Mosque_Tower() {
    glPushMatrix();
    glTranslatef(165.34, 170, 0);
    glScalef(0.57, 0.55, 0);
    Mosque_Wall_Model3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(41, 80, 0);
    glScalef(0.88, 0.8, 0);
    Mosque_Wall_Model2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.5, 0, 0);
    Mosque_Wall_Model2();
    glPopMatrix();
}
    //////////////////Mosque_MAIN_Model/////////////////
void Mosque_Model() {

    //Calling_Roof
    glPushMatrix();
    glTranslatef(197.8, 85, 0);
    Mosque_Roof_MoonStar();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.222, 0.7, 0.7);
    glTranslatef(-25, 0, 0);
    Mosque_Roof_Shape();
    glPopMatrix();

    //Roof_Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.187, 0.678, 0.678);
    glVertex2i(329, 115);
    glVertex2i(350, 130);
    glVertex2i(350, 115);
    glEnd();

    //Calling_Building
    glPushMatrix();
    glTranslatef(225, 25, 0);
    glScalef(0.55, 0.55, 0);
    Mosque_Tower();
    glPopMatrix();
    Mosque_Wall_Model1();
    Mosque_Tower();

    ///Mosque_Door1
    glPushMatrix();
    glColor3f(.204, .570, .730);
    glTranslatef(158.069, 43, 0);
    glScalef(0.448, 0.4, 0);
    Mosque_Roof_Shape();
    glPopMatrix();

    ///Mosque_Door2
   glBegin(GL_POLYGON);
   glColor3f(0.222, 0.7, 0.7);
   glVertex2i(288.3, 70);
   glVertex2i(288.3, 95);
   glVertex2i(326.3, 95);
   glVertex2i(326.3, 70);
   glEnd();

    //Mosque_Window1
    glBegin(GL_POLYGON);
    glColor3f(0.111, 0.4, 0.4);
    glVertex2i(387, 70);
    glVertex2i(387, 108);
    glVertex2i(402, 108);
    glVertex2i(402, 70);
    glEnd();
}
///=======================================================================================================///


///=================///
///***   Object  ***///
///=================///


///*** Sun ***///
void Sun() {
	glColor3f(1, 1, 0);
	glPushMatrix();
    Sun_Model();
	glPopMatrix();
}

///*** Cloud_One_Model_One ***///
void cloud_one() {
    glPushMatrix();
    glTranslatef(-290, -100, 0);
    glScalef(1.7, 1.6, 0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Two_Model_one ***///
void cloud_two() {
    glPushMatrix();
    glTranslatef(88, 150, 0);
    glScalef(1.1, 1, 0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Three_Model_Two ***///
void cloud_three() {
    glPushMatrix();
    glTranslatef(-130, 80, 0);
    cloud_model_Two();
    glPopMatrix();
}

///*** Cloud_Four_Model_Two ***///
void cloud_four() {
    glPushMatrix();
    glTranslatef(200, 100, 0);
    glScalef(1.1, 1.1, 0);
    cloud_model_Two();
    glPopMatrix();
}

///*** Cloud_Five_Model_Three ***///
void cloud_five() {
    glPushMatrix();
    glTranslatef(-595, 60, 0);
    glScalef(1.9, 1.7, 0);
    cloud_model_Three();
    glPopMatrix();
}

///*** Cloud_Six_Model_Three ***///
void cloud_six() {
    glPushMatrix();
    glTranslatef(250, 80, 0);
    glScalef(2.1, 1.9, 0);
    cloud_model_Three();
    glPopMatrix();
}

///*** Cloud_Seven_Model_one ***///
void cloud_seven() {
    glPushMatrix();
    glTranslatef(380, 150, 0);
    glScalef(1.2, 1.1, 0);
    cloud_model_one();
    glPopMatrix();
}

///*** Hill_big_One ***///
void Hill_Big_One() {
    glPushMatrix();
    glTranslatef(-200, -56, 0);
    glScalef(1.8, 1.8, 0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two() {
    glColor3f(0, 1, 1);
    glPushMatrix();
    glTranslatef(1180, -35, 0);
    glScalef(-1.5, 1.5, 0);
    
    hill_big();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One() {
    glPushMatrix();
    glTranslatef(-190, -110, 0);
    glScalef(1.8, 1.8, 0);
    hill_small();
    glPopMatrix();

}

///*** Tree_1 ***///
void Tree_One() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(540, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(750, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(292, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(30, -20, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(50, -10, 0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(365, -18.5, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(343.7, -29, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(760, -25, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(90, -2, 0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(125, 15, 0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve() {
    glColor3f(0.533, 1.393, 0.3);
    glPushMatrix();
    glTranslatef(400, 0, 0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Tilla_One_Model_Three ***///
void Tilla_One() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tilla_Three_Model();
    glPopMatrix();
}

/// *** Tilla_Two_Model_Two ***///
void Tilla_Two() {
    glPushMatrix();
    glTranslatef(-190, 0, 0);
    glScalef(1.1, 1.1, 0);
    Tilla_Two_Model();
    glPopMatrix();
}

/// *** Tilla_Three_Model_Two ***///
void Tilla_Three() {
    glPushMatrix();
    glTranslatef(400, 0, 0);
    Tilla_Two_Model();
    glPopMatrix();
}

/// *** Tilla_Four_Model_One ***///
void Tilla_Four() {
    glPushMatrix();
    glTranslatef(160, -95, 0);
    glScalef(2, 2, 0);
    Tilla_One_Model();
    glPopMatrix();
}

/// *** Tilla_five_Model_One ***///
void Tilla_Five() {
    glPushMatrix();
    glTranslatef(1080, -95, 0);
    glScalef(-2, 2, 0);
    Tilla_One_Model();
    glPopMatrix();
}

///*** Mosque ***///
void Mosque() {
    glPushMatrix();
    glTranslatef(280, 40, 0);
    Mosque_Model();
    glPopMatrix();
}

///*** Bird ***///
void Bird() {
    glPushMatrix();
    glTranslatef(750, 235, 0);
    glScalef(0.6, 0.6, 0);
    birdie();
    glPopMatrix();
}

///*** String ***///
void IamUTM() {
    glPushMatrix();
    glTranslatef(670, 42, 0);
    introscreen();
    glPopMatrix();
}
///=======================================================================================================///

///========================///
///*** Display Function ***///
///========================///


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

    Sky();
    Sun();
    Hill_Big_One();
    Tilla_One();
    Tilla_Two();
    Hill_Small_One();
    Mosque();
    Tilla_Four();
    Tilla_Five();
    Hill_Big_Two();
    cloud_three();
    cloud_four();
    Tilla_Three();
    cloud_one();

    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve(); 

    cloud_two();
    cloud_five();
    cloud_six();
    cloud_seven();

    Bird();
    field();
    IamUTM();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("UTM Mosque");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}