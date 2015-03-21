#include <stdlib.h>
#include <GL/glut.h> 



void myDisplay(void)
{
	//buffer����Ϊ��ɫ��д
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor4f(1.0f,0,0,1.0f);
	glVertex3f(-1.0f,-1.0f,-6.0f);
	glVertex3f(1.0f,-1.0f,-6.0f);
	glVertex3f(1.0f,1.0f,-6.0f);
	glVertex3f(-1.0f,1.0f,-6.0f);

	glColor4f(0,1.0f,0,0.0f);
	glVertex3f(-1.0f + 1.5f,-1.0f,-6.0f);
	glVertex3f(1.0f + 1.5f,-1.0f,-6.0f);
	glVertex3f(1.0f + 1.5f,1.0f,-6.0f);
	glVertex3f(-1.0f + 1.5f,1.0f,-6.0f);

	glColor4f(0,0,1.0f,0.5f);
	glVertex3f(-1.0f - 1.5f,-1.0f,-6.0f);
	glVertex3f(1.0f - 1.5f,-1.0f,-6.0f);
	glVertex3f(1.0f - 1.5f,1.0f,-6.0f);
	glVertex3f(-1.0f - 1.5f,1.0f,-6.0f);
	glEnd();

	//ǿ��OpenGL����������ʱ��������
	glFlush();
}

void init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void myReshape(GLsizei w,GLsizei h)
{
	//�����ӿ�
	glViewport(0,0,w,h);
	//ָ����ǰ����ΪGL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	//����ǰ�����û�Ϊ��λ��
	glLoadIdentity();
	gluPerspective(45.0f,(float)w/(float)h,0.1f,1000.0f);
	//ָ����ǰ����ΪGL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char ** argv)
{
	/*��ʼ��*/
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);

	/*��������*/
	glutCreateWindow("test");

	init();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return(0);
}