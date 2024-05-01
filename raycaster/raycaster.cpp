#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>


typedef struct Player
{
	float x , y;
};

int mapX = 8 , mapY = 8 , mapSize = 64;
int map[64] = 
{
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,1,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,1,1,0,0,1,
	1,1,1,1,1,1,1,1,
};

Player player;


void drawMap2D()
{
	int x,y,xo,yo;
	for(y=0;y<mapY;y++)
	{
		for(x=0;x<mapX;x++)
		{
			if(map[y*mapX+x] == 1)	{ glColor3f(1,1,1);	}
			else					{ glColor3f(0,0,0);	}
			xo=x*mapSize;	yo=y*mapSize;

			glBegin(GL_QUADS);


			glVertex2i(xo+1			,yo+1			);
			glVertex2i(xo+1			,yo+mapSize-1	);
			glVertex2i(xo+mapSize-1	,yo+mapSize-1	);
			glVertex2i(xo+mapSize-1	,yo+1			);


			glEnd();

			
		}
	}
}

void drawPlayer()
{
	glColor3f(1,1,0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2d(player.x,player.y);
	glEnd();
}

void buttons(unsigned char key, int x ,int y)
{
	if(key == 'a'){player.x -=5;}
	if(key == 'w'){player.y -=5;}
	if(key == 's'){player.y +=5;}
	if(key == 'd'){player.x +=5;}
	glutPostRedisplay();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawMap2D();
	drawPlayer();
	glutSwapBuffers();
}

void init()
{
	player.x = 300;
	player.y = 300;
	glClearColor(0.3,0.3,0.3,0);
	gluOrtho2D(0,1024,512,0);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024,512);
	glutCreateWindow("Sex is not Free, Unlike linux.");
	Player* player;
	init();



	drawPlayer();


	glutDisplayFunc(display);
	glutKeyboardFunc(buttons);
	glutMainLoop();
	return 0;
}

