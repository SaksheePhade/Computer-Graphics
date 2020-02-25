#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int xx1, yy1, xx2, yy2;

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

void BLA(int x1,int y1,int x2,int y2)
{
    int x,y,dx,dy,s1,s2,P,count=1;
    x = x1;
    y = y1;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    s1 = sign(x2-x1);
    s2 = sign(y2-y1);
    
    P = 2*dy - dx;
    
    int d;
    if(dx==0) d = dy;
    else d = dx;
    
    while(count<d)
    {
        if(P<0)
        {
            x = x + s1;
            P = P + 2*dy;
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
            glFlush();
        }
        else
        {
            x = x + s1;
            y = y + s2;
            P = P + 2*dy - 2*dx;
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
            glFlush();    
        }
        count++;
    }
    
}

void renderfunction()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	    
	    glColor3f (1.0, 1.0, 0.0);
	    glBegin(GL_POINTS);
	    dda(xx1,yy1,xx1,yy2);
         dda(xx1,yy2,xx2,yy2);
         dda(xx2,yy2,xx2,yy1);
         dda(xx2,yy1,xx1,yy1);
        
    	    glColor3f(0.0,1.0,0.0);
	    dda(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
         dda((xx1+xx2)/2,yy2,xx2,(yy1+yy2)/2);
         dda(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
    	    dda((xx1+xx2)/2,yy1,xx1,(yy1+yy2)/2);
    	   
         glColor3f(0.0,0.0,1.0);
         dda((xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);
    	    dda((xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2);
	    dda((xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2);
         dda((xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2); 

	glEnd();
	glFlush();
}


void renderfunction2()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	    
	    glColor3f (1.0, 1.0, 0.0);
	    glBegin(GL_POINTS);
	    BLA(xx1,yy1,xx1,yy2);
         BLA(xx1,yy2,xx2,yy2);
         BLA(xx2,yy2,xx2,yy1);
    	    BLA(xx2,yy1,xx1,yy1);
    	
         glColor3f(0.0,1.0,0.0);
	    BLA(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
         BLA((xx1+xx2)/2,yy2,xx2,(yy1+yy2)/2);
         BLA(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
    	    BLA((xx1+xx2)/2,yy1,xx1,(yy1+yy2)/2);
    	   
         glColor3f(0.0,0.0,1.0);
         BLA((xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);
    	    BLA((xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2);
	    BLA((xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2);
         BLA((xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2); 

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
    printf("\n\tMENU\n1.DDA algo\n2.Bresenham's algo\n3.Exit\nEnter choice : ");
    scanf("%d",&ch);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
   
  do{
           
    switch(ch)
    {
        case 1 :  printf("\n Enter vertex x1 ");
                  scanf("%d",&xx1);
                  printf("\n Enter vertex y1 ");
   	             scanf("%d",&yy1);
   	             printf("\n Enter vertex x2 ");
   	             scanf("%d",&xx2);
   	             printf("\n Enter vertex y2 ");
   	             scanf("%d",&yy2);
   	             glutCreateWindow("DDA Line Algorithm");
	             init();
	             glutDisplayFunc(renderfunction);
	             glutMainLoop();
	             break;
   	    
   	    case 2 : printf("\n Enter vertex x1 ");
                  scanf("%d",&xx1);
                  printf("\n Enter vertex y1 ");
   	             scanf("%d",&yy1);
   	             printf("\n Enter vertex x2 ");
   	             scanf("%d",&xx2);
   	             printf("\n Enter vertex y2 ");
   	             scanf("%d",&yy2);
   	             glutCreateWindow("BLA Line Algorithm");
	             init();
	             glutDisplayFunc(renderfunction2);
	             glutMainLoop();
   	             break;
   	    
   	    case 3 : return 0;
    }
    
   }while(1);
   	
	
}
/*
a3-402-09@a3-402-09:~/23244$ ./a.out

	MENU
1.DDA algo
2.Bresenham's algo
3.Exit
Enter choice : 1

 Enter vertex x1 100

 Enter vertex y1 100

 Enter vertex x2 400

 Enter vertex y2 400

	MENU
1.DDA algo
2.Bresenham's algo
3.Exit
Enter choice : 2

 Enter vertex x1 100

 Enter vertex y1 100

 Enter vertex x2 400

 Enter vertex y2 400
 
	MENU
1.DDA algo
2.Bresenham's algo
3.Exit
Enter choice : 3

*/
     

