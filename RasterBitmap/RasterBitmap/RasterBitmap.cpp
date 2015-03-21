#include <stdlib.h>
#include <GL/glut.h> 

GLubyte rasters[24] = {
	0xc0,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,
	0xff,0x00,0xff,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,
	0xff,0xc0,0xff,0xc0
};
void background(void)
{
	//���ñ�����ɫΪ��ɫ
	glClearColor(0.0,0.0,0.0,0.0);
}

void myDisplay(void)
{
	//buffer����Ϊ��ɫ��д
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);
	glRasterPos2i(20,20);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	//ǿ��OpenGL����������ʱ��������
	glFlush();
}

void init()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void myReshape(GLsizei w,GLsizei h)
{
	//�����ӿ�
	glViewport(0,0,w,h);
	//ָ����ǰ����ΪGL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	//����ǰ�����û�Ϊ��λ��
	glLoadIdentity();
	gluOrtho2D(0.0,w,0.0,h);
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