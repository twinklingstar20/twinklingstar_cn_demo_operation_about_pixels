#include <stdlib.h>
#include <GL/glut.h> 



void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glDepthMask(GL_FALSE);
	glBegin(GL_QUADS);
		glColor4f(1.0f,0,0,0.4f);
		glVertex3f(-1.0f,-1.0f,-6.0f);
		glVertex3f(1.0f,-1.0f,-6.0f);
		glVertex3f(1.0f,1.0f,-6.0f);
		glVertex3f(-1.0f,1.0f,-6.0f);
	glEnd();
	glDepthMask(GL_TRUE);

	glBegin(GL_QUADS);
		glColor4f(0,1.0f,0,1.0f);
		glVertex3f(-1.0f,-1.0f,-5.0f);
		glVertex3f(1.0f,-1.0f,-5.0f);
		glVertex3f(1.0f,1.0f,-5.0f);
		glVertex3f(-1.0f,1.0f,-5.0f);
	glEnd();

	glDepthMask(GL_FALSE);
	glBegin(GL_QUADS);
	glColor4f(0,0,1.0f,0.5f);
	glVertex3f(-1.0f,-1.0f,-4.0f);
	glVertex3f(1.0f,-1.0f,-4.0f);
	glVertex3f(1.0f,1.0f,-4.0f);
	glVertex3f(-1.0f,1.0f,-4.0f);
	glEnd();
	glDepthMask(GL_TRUE);

	glFlush();
}

void init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);	
}

void myReshape(GLsizei w,GLsizei h)
{
	//设置视口
	glViewport(0,0,w,h);
	//指明当前矩阵为GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	//将当前矩阵置换为单位阵
	glLoadIdentity();
	gluPerspective(45.0f,(float)w/(float)h,0.1f,1000.0f);
	//指明当前矩阵为GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char ** argv)
{
	/*初始化*/
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);

	/*创建窗口*/
	glutCreateWindow("test");

	init();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return(0);
}