#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include<GL/glut.h>

#endif
#include<stdio.h>
#include<math.h>

#define PI 3.14159265359
#define PI2 PI/2
#define PI3 3*PI/2
#define DEG_TO_RAD 0.0174532925


/*
	Player X
	Player Y
	Player Delta X
	Player Delta Y
	Player angle
*/
float px , py , pdx , pdy ,pa;

int mapX = 8 , mapY = 8 , mapSize = 64;	// Constants. Dont Change After Initilization.
int map[]=
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,	
};


/*
	This is the core function of just drawing map tiles in the left.
	This does not contain any raycasting or other information.
	This is coded after player drawing and movement.
	xo : X offset
	yo : Y offset
*/
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


			// We add and subtract 1 pixel so we can se lines.
			glVertex2i(xo+1			,yo+1			);
			glVertex2i(xo+1			,yo+mapSize-1	);
			glVertex2i(xo+mapSize-1	,yo+mapSize-1	);
			glVertex2i(xo+mapSize-1	,yo+1			);


			glEnd();

			
		}
	}
}


// √(x^2 + y^2)
float dist(float ax,float ay,float bx,float by,float ang)
{
	return  sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
}



/*
	This function is meat and bone of all this codebase.
	TODO: Understant this magic and document.
	TODO: Remove leftover debug prints
*/
void drawRays2D()
{
	/*
		Ray Num
		Map X
		Map Y
		Map Position
		Depth Of Field
		Ray X
		Ray Y
		Ray angle
		X offset
		Y offset
		Distance Total
	*/
	int r,mx,my,mp,dof; float rx,ry,ra,xo,yo,distT;


	// Math works with radian. We started our rays from 30 degrees counter clockwise. 
	// if our FOV 60 degrees it means we see equal amount both left and right
	ra=pa-DEG_TO_RAD*30; 


	// If more than 2 pi or less than 0 reset to nice number.
	if(ra < 0)
	{
		ra+=2*PI;
	}
	if (ra > 2*PI)
	{
		ra-=2*PI;
	}

	// Horizontal ?
	for(r=0;r<60;r++)
	{
		dof=0;
		float distH=100000,hx=px,hy=py;
		float aTan=-1/tan(ra);
		if(ra>PI){ ry=(((int)py>>6)<<6)-0.0001; rx=(py-ry)*aTan+px; yo=-64; xo=-yo*aTan;}//looking up
		if(ra<PI){ ry=(((int)py>>6)<<6)+64;     rx=(py-ry)*aTan+px; yo= 64; xo=-yo*aTan;}//looking down
		if(ra==0 || ra==PI) { rx=px; ry=py; dof=8;} // rigth or left
		while (dof<8)
		{
			printf("%f - xo  %f - yo  %f -ra    %f   -pa\n", xo,yo,ra,pa);
			mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
			if(mp > 0 && mp<mapX*mapY && map[mp]==1) { hx=rx; hy=ry; distH=dist(px,py,hx,hy,ra); dof = 8;} // wall hit
			else{ rx+=xo; ry+=yo; dof+=1;}
		}



		// Vertical ?
		
		dof=0;
		float distV=100000,vx=px,vy=py;
		float nTan=-tan(ra);
		if(ra>PI2 && ra<PI3){ rx=(((int)px>>6)<<6)-0.0001; ry=(px-rx)*nTan+py; xo=-64; yo=-xo*nTan;}//looking left
		if(ra<PI2 || ra>PI3){ rx=(((int)px>>6)<<6)+64;     ry=(px-rx)*nTan+py; xo= 64; yo=-xo*nTan;}//looking right
		if(ra==0 || ra==PI) { ry=py; rx=px; dof=8;} // up or down
		while (dof<8)
		{
			printf("%f - xo  %f - yo  %f -ra    %f   -pa\n", xo,yo,ra,pa);
			mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
			if(mp > 0 && mp<mapX*mapY && map[mp]==1) { vx=rx; vy=ry; distV=dist(px,py,vx,vy,ra); dof = 8;} // wall hit
			else{ rx+=xo; ry+=yo; dof+=1;}
		}

		if(distH > distV) { rx=vx; ry=vy; distT = distV;}
		if(distH < distV) { rx=hx; ry=hy; distT = distH;}

		glColor3f(1,0,0);	glLineWidth(3);	glBegin(GL_LINES);	glVertex2i(px,py);	glVertex2i(rx,ry);	glEnd();
		ra+=DEG_TO_RAD; if(ra < 0) { ra+=2*PI;} if (ra > 2*PI) { ra-=2*PI;}
		
		
		//	Draw wall

		float lineH = (mapSize*320)/distT; // away little close big
		float lineOffset = 160 - lineH/2;
		glLineWidth(20); 
		glBegin(GL_LINES);
		glVertex2i(r*8+530,lineOffset); 
		glVertex2i(r*8+530,lineH+lineOffset); 
		glEnd();
	}
	
}



/*
	This is the first function that is coded. Logic is simple.
	Draw player at coordinates below as a square.
	Buttons change global variables for player so we just draw it.
*/
void drawPlayer2D()
{
	glColor3f(1,1,0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2d(px,py);
	glEnd();

	glColor3f(1,0,0);
	glBegin(GL_LINES);
	glLineWidth(3);
	glVertex2i(px,py);
	glVertex2i(px+pdx*5,py+pdy*5);
	glEnd();
}


/*
	Nothing fancy. Press button if pressed change value.
*/
void buttons(unsigned char key, int x ,int y)
{
	if(key == 'a')
	{
		pa-=0.1; 
		if(pa<0)
		{
			pa+=2*PI;
		}

		pdx=cos(pa)*5;
		pdy=sin(pa)*5;

	}
	if(key == 'd')
	{
		pa+=0.1;
		if(pa>2*PI)
		{
			pa-=2*PI;
		}

		pdx=cos(pa)*5;
		pdy=sin(pa)*5;

	}
	if(key == 'w'){	px +=pdx;	py+=pdy; }
	if(key == 's'){	px -=pdx;	py-=pdy; }
	glutPostRedisplay();

}

/*
	This is the main Display function. 
	Order matters because it is drawn FIFO.
	First things get drawn. Next draw command draws over it.
*/
void display()
{   
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 	drawMap2D();
 	drawPlayer2D();
	drawRays2D();
	glutSwapBuffers();  
}

/*
	Setting basic global values.
	Nothing fancy.
*/
void init()
{
	px = 300;
	py = 300;
	pdx = cos(pa);
	pdy = sin(pa);
	glClearColor(0.3,0.3,0.3,0);
	gluOrtho2D(0,1024,512,0);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024,512);
	glutCreateWindow("Sex is not Free, Unlike linux.");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(buttons);
	glutMainLoop();
	return 0;
}

