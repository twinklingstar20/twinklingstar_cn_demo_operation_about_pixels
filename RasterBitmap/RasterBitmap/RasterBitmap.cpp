#include <stdlib.h>
#include <GL/glut.h> 

GLubyte rasters[24] = {
	0xc0,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,
	0xff,0x00,0xff,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,
	0xff,0xc0,0xff,0xc0
};
void background(void)
{
	//设置背景颜色为黑色
	glClearColor(0.0,0.0,0.0,0.0);
}

void myDisplay(void)
{
	//buffer设置为颜色可写
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);
	glRasterPos2i(20,20);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	glBitmap(10,12,0.0,0.0,11.0,0.0,rasters);
	//强制OpenGL函数在有限时间内运行
	glFlush();
}

void init()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void myReshape(GLsizei w,GLsizei h)
{
	//设置视口
	glViewport(0,0,w,h);
	//指明当前矩阵为GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	//将当前矩阵置换为单位阵
	glLoadIdentity();
	gluOrtho2D(0.0,w,0.0,h);
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