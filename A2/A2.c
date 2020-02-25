#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int rad;

int sign(int x)
{
    if(x>0) return 1;
    if(x==0) return 0;
    else return -1;
}


void dda(int X1,int Y1, int X2,int Y2)   
{
    float x,y,dx,dy,length;
    int i;
    dx=abs(X2-X1);
    dy=abs(Y2-Y1);
    if(dx>=dy)
        length=dx;
    else
        length=dy;
    dx=(X2-X1)/length;
    dy=(Y2-Y1)/length;
    x=X1;
    y=Y1;
    i=1;
    while(i<=length)
    {
       glColor3f (1.0, 1.0, 0.0); 
       glBegin(GL_POINTS);
       glVertex2i(x,y);
       glEnd();
       glFlush();
       x=x+dx;
       y=y+dy;
       i=i+1;
    }
    glFlush();
}


void plot(int x,int y)
{
      glColor3f (1.0, 0.0, 0.0);
      glBegin(GL_POINTS);
      glVertex2i(x,y);
      glEnd();
}

void MidPoint(int r)   
{
     int i,x,y;
     float P;
     glBegin(GL_POINTS);
          glVertex2i(0,r);
     glEnd();
     x = 0;
     y = r;
     P = 5/4 - r;
     
     while(y>x) {
     
     if(P<0) {
          P = P + 2*x + 3;
          x = x+1;
     }
     
     if(P>=0) {
          P = P + 2*(x-y) + 5;
          y = y-1;
          x = x+1;
     }
          plot(x,y);
          plot(x,-y);
          plot(-x,y);
          plot(-x,-y);
          plot(y,x);
          plot(y,-x);
          plot(-y,-x);
          plot(-y,x);
         
       glFlush();
     
     }
     
     glFlush();
          
}


void BLA(int r)
{
	int x,y,i=0;
	float D;
	x = 0;
	y = r;
	plot(0,r);
	D = 3 - 2*r;
	while(x<=y) {
		if(D<0) {
			D = D + 4*x + 6;
			x = x + 1;
		}
		if(D>=0) {
			D = D + 4*(x - y) + 10;
			x = x + 1;
			y = y - 1;
		}
		plot(x,y);
		plot(-x,y);
		plot(x,-y);
		plot(-x,-y);
		plot(y,x);
		plot(-y,x);
		plot(-y,-x);
		plot(y,-x);
		
		glFlush();
	}
	glFlush();	    
}

void renderfunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	   
	glBegin(GL_POINTS);
	   MidPoint(rad);
	   MidPoint(2*rad);
	   dda(0,-rad,sqrt(3)*rad,-rad);
	   dda(0,-rad,-sqrt(3)*rad,-rad);
	   dda(sqrt(3)*rad,-rad,0,2*rad);
	   dda(0,2*rad,-sqrt(3)*rad,-rad);
	glEnd();
	
	glFlush();
}

void renderfunction2()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	   
	glBegin(GL_POINTS);
	   BLA(rad);
	   BLA(2*rad);
	   dda(0,-rad,sqrt(3)*rad,-rad);
	   dda(0,-rad,-sqrt(3)*rad,-rad);
	   dda(sqrt(3)*rad,-rad,0,2*rad);
	   dda(0,2*rad,-sqrt(3)*rad,-rad);
	glEnd();
	
	glFlush();
}

void init(void)
{
       //glViewport(0,0,640,480);  
       glMatrixMode(GL_PROJECTION);  
       //glLoadIdentity();  
       gluOrtho2D(-100,100,-100,100);  
       glMatrixMode(GL_MODELVIEW);     
}

int main(int argc, char **argv)
{
    int ch;
    printf("\n\tMENU\n1.Mid-point algo\n2.Bresenham's algo\n3.Exit\nEnter choice : ");
    scanf("%d",&ch);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
   
  do{
           
    switch(ch)
    {
        case 1 :  printf("\nEnter radius : ");
                  scanf("%d",&rad);
   	             glutCreateWindow("Mid-point circle Algorithm");
	             init();
	             glutDisplayFunc(renderfunction);
	             glutMainLoop();
	             break;
   	    
   	    case 2 : printf("\nEnter radius : ");
   	    	     scanf("%d",&rad);
   	             glutCreateWindow("BLA Line Algorithm");
	             init();
	             glutDisplayFunc(renderfunction2);
	             glutMainLoop();
   	             break;
   	    
   	    case 3 : return 0;
    }
    
   }while(1);
   	
	
}

