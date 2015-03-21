#include <stdlib.h>
#include <GL/glut.h> 
#include <stdio.h>

int g_inHeight;
int g_inWidth;

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(0,1.0f,0);
	glVertex2i(10,10);
	glVertex2i(10,200);
	glVertex2i(200,200);
	glVertex2i(200,10);
	glEnd();

	unsigned char* ptrBuf = new unsigned char[g_inWidth*g_inHeight*3];
	glReadPixels(0,0,g_inWidth,g_inHeight,GL_RGB,GL_UNSIGNED_BYTE,ptrBuf);
	int i , j;
	int heightEnd = g_inHeight-100>0 ? g_inHeight - 100 : 0;
	for( i=g_inHeight-1 ; i>=heightEnd ; i-- )
	{
		if( i%2==0 )
			continue;
		for( j=0 ; j<g_inWidth ; j++ )
		{
			int tmpIndex = (i*g_inWidth + j)*3;
			ptrBuf[ tmpIndex ] = 255;
			ptrBuf[ tmpIndex + 1] = 255;
			ptrBuf[ tmpIndex + 2] = 255;
		}
	}

	glDrawPixels(g_inWidth,g_inHeight,GL_RGB,GL_UNSIGNED_BYTE,ptrBuf);

	delete []ptrBuf;
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);

}

void myReshape(GLsizei w,GLsizei h)
{
	g_inHeight = h;
	g_inWidth = w;
	//设置视口
	glViewport(0,0,w,h);
	//指明当前矩阵为GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	//将当前矩阵置换为单位阵
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
	//指明当前矩阵为GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char ** argv)
{
	/*初始化*/
	glutInit(&argc,argv);
	//双缓存
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400,400);

	/*创建窗口*/
	glutCreateWindow("test");

	init();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return(0);
}