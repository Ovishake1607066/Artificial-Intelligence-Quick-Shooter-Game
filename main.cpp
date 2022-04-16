#include<bits/stdc++.h>
#define ll long long
#include<GL/gl.h>
#include<windows.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include "BmpLoader.h"
using namespace std;
vector<ll> points;
vector<ll>points2;
vector<ll>points3;
vector<ll>reserved;
ll level;
ll d10=0,d9=0,d8=0,d7=0,d6=0,d5=0,userlife=0,computerlife=0;
ll optimalnumber;
ll normal=1,zoom=0,e1=0,e2,e3,e4,e5,e6,e7,snow=0,sunny=1,zoomp=1,zoomm=0,computer=0;
ll c1=1,temp0=0,temp1=0,temp2=0,temp4=0,score=0,scorecom=0, inst=1,scoreinst=0,easy=0,easy2=0,easy3=0,medium=0,hard=0,arrowgame=0,gungame=0,temp3=8,t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,tt1=0,tt2=0,tt3=0,tt4=0,tt5=0,tt6=0;
double windowHeight=1100, windowWidth=800;
GLfloat tartheta=0.0,theta =0.0,theta2 =0.0;
GLfloat angle = 0.0, axis_x=0.0, axis_y=0.0, minute= 0.0, hour=0.0,second=0.0;
GLboolean Rotate = false, uRotate=false, fan_rotate = true, cRotate= true,gunshot=false,trigger=false,ghura=true,arrowshot=false,schpt=false;
GLfloat eye_x = 0.0, eye_y = 21.0, eye_z = -68.0, look_x = -7.0, look_y = -9.0, look_z = -1.0, x1=70.0, x2=70.0, x3=70.0, x4=70.0, x5=70.0,x6=70.0,xx1=-110.0, xx2=-110.0, xx3=-110.0, xx4=-110.0, xx5=-110.0,xx6=-110.0;
GLfloat gz=-58,az=-48,triggercount=0.0,triggery=0.0,sx=-40,ux=0,cx=0;
GLfloat ina=az,xin=0.0,yin=0.0,gulix=.3,guliy=.3,guliz=.4,xxx=0,inz=gz;
const double PI = 3.14159265389;
int anglex= 0, angley = 0, anglez = 0;
int window;
int wired=0;
int animat = 0;
const int L=23;
const int dgre=3;
int ncpt=L+1;
int clikd=0;
const int nt = 40;
const int ntheta = 20;

bool light_1_on=true;
bool light_2_on=true;
bool light_3_on=true;
bool light_spot_on=false;
bool light_spot2_on=false;
bool light_1=true;
bool light_2=true;
bool light_3=true;
bool light_spot=true;
bool light_spot2=true;
bool diffuse_1_on=true;
bool specular_1_on=true;
bool ambient_1_on=true;
bool diffuse_2_on=true;
bool specular_2_on=true;
bool ambient_2_on=true;
bool diffuse_spot_on=true;
bool specular_spot_on=true;
bool ambient_spot_on=true;

enum textureid
{
    wall = 1,
    sidewall1 = 2,
    ceilbmp=3,
    field=4,
    target=5,ten=6,nine=7,eight=8,seven=9,six=10,five=11,uten=12,
    zero=13,
    sfield=14,
    sceilbmp=15
};
float deltaAngle = 0.0f;
float deltaAngle2 = 0.0f;
int xOrigin = -1;
int yOrigin = -1;
GLfloat ctrlpoints[L+1][3] =
{
    {9.3, 0.0, 0.0},
    {9.0, 0.0, 0.0},
    {8.9, 0.1, 0.0},
    {8.9, 0.1, 0.0},
    {8.8, 0.3, 0.0},
    {8.5, 0.5, 0.0},
    {8.0,4.5,0.0},
    {7.0,4.5,0.0},
    {5.0,1.0,0.0},
    {4.5,.5,0.0},
    {4.5,.5,0.0},
    {4.0,1.0,0.0},
    {2.0,4.5,0.0},
    {1.0,4.5,0.0},
    {0.5, 0.5, 0.0},
    {0.3, 0.3, 0.0},
    {0.1, 0.1, 0.0},
    {0.1, 0.1, 0.0},
    {0.1, 0.1, 0.0},
    {0.0, 0.0, 0.0},
    {-0.1, -0.1, 0.0},
    {-0.1, -0.2, 0.0},
    {-0.1, -0.2, 0.0},
    {-0.1, -0.3, 0.0}
};

GLfloat ctrlpoints2[L+1][3] =
{
    { 0.0, 0.0, 0.0},
    { 7.0, 3.0, 0.0},
    {0.0,4.0,0.0},
    {10.0,4.0,0.0},
    {7.0,0.0,0.0},
    {10.0,-4.0,0.0},
    {0.0,-4.0,0.0},
    { 7.0, -3.0, 0.0},
    { 5.0, -3.0, 0.0},
    {0.0, 0.0, 0.0}
};
double ex=0, ey=0, ez=15, lx=0,ly=0,lz=0, hx=0,hy=1,hz=0;

float wcsClkDn[3],wcsClkUp[3];

class point1
{
public:
    point1()
    {
        x=0;
        y=0;
    }
    int x;
    int y;
} clkpt[2];
int flag=0;
GLint viewport[4];
GLdouble modelview[16];
GLdouble projection[16];




long long nCr(int n, int r)
{
    if(r > n / 2) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


void BezierCurve ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints[i][0];
        y+=coef*ctrlpoints[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);


}
void BezierCurve2 ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints2[i][0];
        y+=coef*ctrlpoints2[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);


}


void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(-Nx,-Ny,-Nz);
}
void matColor(float kdr, float kdg, float kdb,  float shiny, int frnt_Back, float ambFactor=.5, float specFactor=.5)
{

    const GLfloat mat_ambient[]    = { kdr*ambFactor, kdg*ambFactor, kdb*ambFactor, 1.0f };
    const GLfloat mat_diffuse[]    = { kdr, kdg, kdb, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f*specFactor, 1.0f*specFactor, 1.0f*specFactor, 1.0f };
    const GLfloat high_shininess[] = { shiny };
    if(frnt_Back==0)
    {
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    }
    else if(frnt_Back==1)
    {
        glMaterialfv(GL_BACK, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_BACK, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_BACK, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_BACK, GL_SHININESS, high_shininess);
    }
    else if(frnt_Back==2)
    {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);
    }

}
void bowBezier()
{
    int i, j;
    float x, y, z, r;
    float x1, y1, z1, r1;
    float theta;

    const float startx = 0, endx = ctrlpoints[L][0];

    const float dx = (endx - startx) / nt;
    const float dtheta = 2*PI / ntheta;

    float t=0;
    float dt=1.0/nt;
    float xy[2];
    BezierCurve( t,  xy);
    x = xy[0];
    r = xy[1];

    float p1x,p1y,p1z,p2x,p2y,p2z;
    for ( i = 0; i < nt; ++i )
    {
        theta = 0;
        t+=dt;
        BezierCurve( t,  xy);
        x1 = xy[0];
        r1 = xy[1];


        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= 1; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;
            z = r * sina;
            z1 = r1 * sina;



            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }

            glVertex3f (x1, y1, z1);


        }
        glEnd();
        x = x1;
        r = r1;
    }

}

void scoredisplay (int posx, int posy, int posz, int space_char, int scorevar)
{
    int j=0,p,k;
    //matColor(0.802, 0.200, 0.100,20,0,1,1);
    //matColor(0.0,0.5,0.8,20,1,1,1);
    GLvoid *font_style1 = GLUT_BITMAP_HELVETICA_18;
    glRasterPos3f ((posx+70),posy, posz);
    glutBitmapCharacter(font_style1,'C');
    glRasterPos3f ((posx+70-space_char),posy, posz);
    glutBitmapCharacter(font_style1,'O');
    glRasterPos3f ((posx+70-2*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'M');
    glRasterPos3f ((posx+70-3*space_char),posy, posz);
    glutBitmapCharacter(font_style1,' ');
    glRasterPos3f ((posx+70-4*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'S');
    glRasterPos3f ((posx+70-5*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'C');
    glRasterPos3f ((posx+70-6*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'O');
    glRasterPos3f ((posx+70-7*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'R');
    glRasterPos3f ((posx+70-8*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'E');
    glRasterPos3f ((posx+70-9*space_char),posy, posz);
    glutBitmapCharacter(font_style1,':');

    p = scorevar;
    j = 0;
    k = 0;
    while(p > 9)
    {
        k = p % 10;
        glRasterPos3f ((posx+(j*space_char)),posy, posz);
        glutBitmapCharacter(font_style1,48+k);
        j++;
        p /= 10;
    }
    glRasterPos3f ((posx+(j*space_char)), posy, posz);
    glutBitmapCharacter(font_style1,48+p);

}
void scoredisplay2 (int posx, int posy, int posz, int space_char, int scorevar)
{
    int j=0,p,k;
    //matColor(0.802, 0.200, 0.100,20,0,1,1);
    //matColor(0.0,0.5,0.8,20,1,1,1);
    GLvoid *font_style1 = GLUT_BITMAP_HELVETICA_18;
    glRasterPos3f ((posx+70),posy, posz);
    glutBitmapCharacter(font_style1,'U');
    glRasterPos3f ((posx+70-space_char),posy, posz);
    glutBitmapCharacter(font_style1,'S');
    glRasterPos3f ((posx+70-2*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'E');
    glRasterPos3f ((posx+70-3*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'R');
    glRasterPos3f ((posx+70-4*space_char),posy, posz);
    glutBitmapCharacter(font_style1,' ');
    glRasterPos3f ((posx+70-5*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'S');
    glRasterPos3f ((posx+70-6*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'C');
    glRasterPos3f ((posx+70-7*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'O');
    glRasterPos3f ((posx+70-8*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'R');
    glRasterPos3f ((posx+70-9*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'E');
    glRasterPos3f ((posx+70-10*space_char),posy, posz);
    glutBitmapCharacter(font_style1,':');

    p = scorevar;
    j = 0;
    k = 0;
    while(p > 9)
    {
        k = p % 10;
        glRasterPos3f ((posx+(j*space_char)),posy, posz);
        glutBitmapCharacter(font_style1,48+k);
        j++;
        p /= 10;
    }
    glRasterPos3f ((posx+(j*space_char)), posy, posz);
    glutBitmapCharacter(font_style1,48+p);

}
void scoredisplayinstant (int posx, int posy, int posz, int space_char, int scorevar,int inst)
{
    if(inst)
    {
        int j=0,p,k;

        GLvoid *font_style1 = GLUT_BITMAP_HELVETICA_18;
        glRasterPos3f ((posx+32),posy, posz);
        glutBitmapCharacter(font_style1,'L');
        glRasterPos3f ((posx+32-space_char),posy, posz);
        glutBitmapCharacter(font_style1,'E');
        glRasterPos3f ((posx+32-2*space_char),posy, posz);
        glutBitmapCharacter(font_style1,'V');
        glRasterPos3f ((posx+32-3*space_char),posy, posz);
        glutBitmapCharacter(font_style1,'E');
        glRasterPos3f ((posx+32-4*space_char),posy, posz);
        glutBitmapCharacter(font_style1,'L');
        glRasterPos3f ((posx+32-5*space_char),posy, posz);
        glutBitmapCharacter(font_style1,':');
        if(scorevar>3)
            p=scorevar-1;
        else
            p = scorevar;
        j = 0;
        k = 0;
        while(p > 9)
        {
            k = p % 10;
            glRasterPos3f ((posx+(j*space_char)),posy, posz);
            glutBitmapCharacter(font_style1,48+k);
            j++;
            p /= 10;
        }
        //glRasterPos3f ((posx+(j*space_char)), posy, posz);
        glRasterPos3f ((posx+32-6*space_char),posy, posz);
        glutBitmapCharacter(font_style1,48+p);
    }

}
void dischar (int posx, int posy, int posz, int space_char, string ss)
{
    if(inst)
    {
        int j=0,p,k;
        //matColor(0.0, 0.0500, 0.100,20,0,1,1);
        //matColor(0.0,0.5,0.8,20,1,1,1);
        char ch1=ss[0],ch2=ss[1],ch3=ss[2],ch4=ss[3],ch5=ss[4],ch6=ss[5],ch7=ss[6],ch8=ss[7];
        GLvoid *font_style1 = GLUT_BITMAP_HELVETICA_18;
        glRasterPos3f ((posx+25),posy, posz);
        glutBitmapCharacter(font_style1,ch1);
        glRasterPos3f ((posx+25-space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch2);
        glRasterPos3f ((posx+25-2*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch3);
        glRasterPos3f ((posx+25-3*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch4);
        glRasterPos3f ((posx+25-4*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch5);
        glRasterPos3f ((posx+25-5*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch6);
        glRasterPos3f ((posx+25-6*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch7);

    }

}
void mouseMove(int x, int y)
{
    if (xOrigin >= 0 && yOrigin>=0)
    {
        deltaAngle = (x - xOrigin) * 0.05f;
        deltaAngle2 = (y - yOrigin) * 0.05f;
        look_x=deltaAngle;
        look_y=deltaAngle2;
    }
}

void mouseButton(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON)
    {
        if(state ==GLUT_DOUBLE)
        {
            eye_z-=10.0;
            look_z-=10.0;
        }
        else if (state == GLUT_DOWN)
        {
            if(flag!=1)
            {
                flag=1;
                clkpt[0].x=x;
                clkpt[0].y=y;
            }
            if((x>=238 && x<=286) && (y>=408 && y<=423))
            {
                gungame=1;
                arrowgame=0;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=351 && x<=388) && (y>=401 && y<=416))
            {
                arrowgame=1;
                gungame=0;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=61 && x<=156) && (y>=492 && y<=532))
            {
                level=1;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=191 && x<=268) && (y>=483 && y<=520))
            {
                level=2;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=337 && x<=393) && (y>=470 && y<=504))
            {
                level=3;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=479 && x<=514) && (y>=461 && y<=493))
            {
                level=5;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=609 && x<=650) && (y>=450 && y<=480))
            {
                level=6;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=763 && x<=826) && (y>=418 && y<=448))
            {
                easy2=1;
                medium=0;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else if((x>=882 && x<=952) && (y>=400 && y<=435))
            {
                easy2=0;
                medium=1;
                score=0;
                scorecom=0;
                scoreinst=0;
                points.clear();
                points=reserved;
                d5=0,d6=0,d7=0,d8=0,d9=0,d10=0;
                userlife=0,computerlife=0;
            }
            else
            {
                triggercount+=1.0;
                //cout<<triggercount<<endl;
                if(triggercount>=5.0)
                {
                    trigger=true;
                    triggercount=0.0;
                }
                gunshot=true;
                arrowshot=true;
                if((easy2 || medium) && (gungame || arrowgame))
                {
                    if(computer)
                    {
                        computerlife+=1;
                    }
                    else
                    {
                        userlife+=1;
                    }
                }
            }

            //cout<<"\nD: "<<x<<" "<<y<<" wcs: "<<wcsClkDn[0]<<" "<<wcsClkDn[1];
        }
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_UP)
        {
            xOrigin = -1;
            yOrigin=-1;
        }
        else
        {
            xOrigin = x;
            yOrigin= y;

        }
    }
    else if (button == GLUT_MIDDLE_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            trigger=true;
            triggercount=0.0;
        }
    }
}

static GLfloat v_Cube[8][3] =
{
    {0.0, 0.0, 0.0},
    {2.0, 0.0, 0.0},
    {0.0, 2.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 2.0, 0.0},
    {0.0, 2.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 2.0, 2.0}
};

static GLubyte quadIndices[6][4] =
{
    {1, 4, 7, 6},
    {7, 4, 2, 5},
    {3, 5, 2, 0},
    {3, 6, 7, 5},
    {0, 2, 4, 1},
    {1, 6, 3, 0}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}
void cube(GLfloat r, GLfloat g, GLfloat b)
{
    GLfloat no_mat[] = {0, 0, 0, 1.0};
    GLfloat mat_ambient[] = {r,g,b,1.0};
    GLfloat mat_diffuse[] = {r,g,b,1.0};
    GLfloat mat_specular[] = {r,g,b,1.0};
    GLfloat mat_shininess[] = {60};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_Cube[quadIndices[i][0]][0], v_Cube[quadIndices[i][0]][1], v_Cube[quadIndices[i][0]][2],
                    v_Cube[quadIndices[i][1]][0], v_Cube[quadIndices[i][1]][1], v_Cube[quadIndices[i][1]][2],
                    v_Cube[quadIndices[i][2]][0], v_Cube[quadIndices[i][2]][1], v_Cube[quadIndices[i][2]][2]);

        glVertex3fv(&v_Cube[quadIndices[i][0]][0]);
        glTexCoord2f(1,0);
        glVertex3fv(&v_Cube[quadIndices[i][1]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_Cube[quadIndices[i][2]][0]);
        glTexCoord2f(0,1);
        glVertex3fv(&v_Cube[quadIndices[i][3]][0]);
        glTexCoord2f(1,1);
    }
    glEnd();
}

class node
{
public:
    GLint x, y, z;
    node(GLint x, GLint y, GLint z) :
        x(x), y(y), z(z) {}
};

void triangle(node a, node b, node c,  GLfloat p,GLfloat r, GLfloat g, GLfloat bl)
{
    GLfloat no_mat[] = {0, 0, 0, 1.0};
    GLfloat mat_ambient[] = {r,g,bl,1.0};
    GLfloat mat_diffuse[] = {r,g,bl,1.0};
    GLfloat mat_specular[] = {r,g,bl,1.0};
    GLfloat mat_shininess[] = {60};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_TRIANGLES);
    glVertex3f(a.x, a.y, a.z);
    glTexCoord2f(0,.01);
    glVertex3f(b.x, b.y, b.z);
    glTexCoord2f(0,0);
    glVertex3f(c.x, c.y, c.z);
    glTexCoord2f(.01,.01);

    glVertex3f(a.x, a.y, a.z+p);
    glTexCoord2f(0,1);
    glVertex3f(b.x, b.y, b.z+p);
    glTexCoord2f(0,0);
    glVertex3f(c.x, c.y, c.z+p);
    glTexCoord2f(.5,.5);
    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(a.x, a.y, a.z);
    glVertex3f(a.x, a.y, a.z+p);
    glVertex3f(b.x, b.y, b.z+p);
    glVertex3f(b.x, b.y, b.z);

    glVertex3f(a.x, a.y, a.z);
    glVertex3f(a.x, a.y, a.z+p);
    glVertex3f(c.x, c.y, c.z+p);
    glVertex3f(c.x, c.y, c.z);

    glVertex3f(b.x, b.y, b.z);
    glVertex3f(c.x, c.y, c.z);
    glVertex3f(c.x, c.y, c.z+p);
    glVertex3f(b.x, b.y, b.z+p);

    glEnd();
}
void triangle2(node a, node b, node c,  GLfloat p,GLfloat r, GLfloat g, GLfloat bl)
{
    GLfloat no_mat[] = {0, 0, 0, 1.0};
    GLfloat mat_ambient[] = {r,g,bl,1.0};
    GLfloat mat_diffuse[] = {r,g,bl,1.0};
    GLfloat mat_specular[] = {r,g,bl,1.0};
    GLfloat mat_shininess[] = {60};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x, c.y, c.z);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x+p, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x+p, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x+p, c.y, c.z);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x+p, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x+p, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x, b.y, b.z);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x+p, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x+p, c.y, c.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x, c.y, c.z);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x, c.y, c.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x+p, c.y, c.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x+p, b.y, b.z);

    glEnd();
}

void floor()
{

    glPushMatrix();
    glScalef(150,1,100);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();

}
void ceil()
{
    glPushMatrix();
    glScalef(155,1,100);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();
}

void back_wall()
{
    glPushMatrix();
    glScalef(150, 80, 1);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();
}

void side_wall()
{
    glPushMatrix();
    glScalef(1, 80, 100);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();
}

void gun()
{

    glPushMatrix();
    //trigger
    glTranslatef(0,triggery,0);
    glScalef(0.5,1.4,.2);
    cube(0.043, 0.043, 0.035);
    glPopMatrix();

    //nol
    glPushMatrix();
    glTranslatef(0,3.8,2.3);
    glScalef(0.5,.3,1.4);

    cube(0.098, 0.098, 0.098);
    glPopMatrix();

    //body
    glPushMatrix();

    glTranslatef(0,2.8,-1.1);
    glScalef(0.5,.8,1.7);

    cube(0.098, 0.098, 0.098);
    glPopMatrix();

}
void light1()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT0);
    if(diffuse_1_on && light_1_on)
    {
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_dif);
    }
    else
    {
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_no);
    }
    if(specular_1_on && light_1_on)
    {
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_spec);
    }
    else
    {
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_no);
    }
    if(ambient_1_on && light_1_on)
    {
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_no);
    }
    glLightfv(GL_LIGHT0, GL_POSITION, l_pos);
}
void light2()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT1);
    if(diffuse_2_on && light_2_on)
    {
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_dif);
    }
    else
    {
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_no);
    }
    if(specular_2_on && light_2_on)
    {
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_spec);
    }
    else
    {
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_no);
    }
    if(ambient_2_on && light_2_on)
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_no);
    }
    glLightfv(GL_LIGHT1, GL_POSITION, l_pos);
}
void light3()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT2);
    if(light_3_on)
    {
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_dif);
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_spec);
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_no);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_no);
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_no);
    }
    glLightfv(GL_LIGHT2, GL_POSITION, l_pos);
}
void arrowf()
{
    glPushMatrix();
    triangle2(node(0,0,0), node(0, 5, 0), node(0, 2.5, 4.2),.5,0,0,0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.002,1.29,-18);
    triangle2(node(0,0,0), node(0, 3, 0), node(0, 1.5, 4), .5,0, 0, 0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,2.4,-16);
    glScalef(.3,.3,8.5);
    cube(0,0,0);
    glPopMatrix();
    glPopMatrix();
}
void targetline()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d10==0)
        glBindTexture(GL_TEXTURE_2D, ten);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(5,0,-.5);
    glScalef(3,3,3);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d9==0)
        glBindTexture(GL_TEXTURE_2D, nine);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(20,0,-.5);
    glScalef(3,3,3);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d8==0)
        glBindTexture(GL_TEXTURE_2D, eight);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(35,0,-.5);
    glScalef(3,3,3);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d7==0)
        glBindTexture(GL_TEXTURE_2D, seven);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(50,0,-.5);
    glScalef(3,3,3);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d6==0)
        glBindTexture(GL_TEXTURE_2D, six);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(65,0,-.5);
    glScalef(3,3,3);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d5==0)
        glBindTexture(GL_TEXTURE_2D, five);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(80,0,-.5);
    glScalef(3,3,3);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    glScalef(47,3,.5);
    cube(0.545, 0.271, 0.075);
    glPopMatrix();
    glPopMatrix();
}
void arrowbow()
{
    glPushMatrix();

    glRotatef( anglex, 1.0, 0.0, 0.0);
    glRotatef( angley, 0.0, 1.0, 0.0);
    glRotatef( anglez, 0.0, 0.0, 1.0);

    glRotatef( 90, 0.0, 0.0, 1.0);
    glTranslated(-3.5,0,0);
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );

    matColor(0.502, 0.000, 0.00,20,0,1,1);
    //matColor(0.0,0.5,0.8,20,1,1,1);


    bowBezier();
    glPopMatrix();
}

void drawStrokeText(char* str,int x,int y,int z)
{
    char *c;
    glPushMatrix();
    glTranslatef(x, y,z);
    glRotatef(180,0,0,1);
    glRotatef(180,1,0,0);
    glScalef(.044f,.044f,0.008f);

    for (c=str; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}
void targetboxmove()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d10==0)
        glBindTexture(GL_TEXTURE_2D, ten);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(x1,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d9==0)
        glBindTexture(GL_TEXTURE_2D, nine);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(x2,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d8==0)
        glBindTexture(GL_TEXTURE_2D, eight);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(x3,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d7==0)
        glBindTexture(GL_TEXTURE_2D, seven);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(x4,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d6==0)
        glBindTexture(GL_TEXTURE_2D, six);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(x5,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    if(d5==0)
        glBindTexture(GL_TEXTURE_2D, five);
    else
        glBindTexture(GL_TEXTURE_2D, zero);
    glTranslatef(x6,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
void alllights()
{
    glPushMatrix();
    glTranslatef(-70,20,0);
    light1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-140,24,-15);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();

    //light2
    glPushMatrix();
    glTranslatef(70,20,0);
    light2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(82,24,30);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();

    //light3
    glPushMatrix();
    glTranslatef(5,0,55);
    light3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,185);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();

    //light3
    glPushMatrix();
    glTranslatef(0,0,55);
    light3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,185);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0,34,185);
    glScalef(1.0,1.5,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
}
void display(void)
{
    //scoreinst=0;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-7,7,-7,7, 3, 300);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z, look_x,look_y,look_z, 0,1,0);
    glViewport(0, 0, windowHeight, windowWidth);
    glRotatef(angle, axis_x, axis_y,0.0);
    if(userlife>3)
    {
        glPushMatrix();
        matColor(0.002, 0.500, 0.000,20,0,1,1);
        dischar(-15.5,23.5,-45,2,"GAME   ");
        matColor(0.002, 0.500, 0.000,20,0,1,1);
        dischar(-25.5,23.5,-45,3,"OVER   ");
        if(score>scorecom)
        {
            matColor(0.502, 0.000, 0.000,20,0,1,1);
            dischar(-8.5,19.5,-45,2,"USER   ");
            matColor(0.502, 0.000, 0.000,20,0,1,1);
            dischar(-28.5,19.5,-45,3,"WON   ");
        }
        else
        {
            matColor(0.502, 0.000, 0.000,20,0,1,1);
            dischar(-8.5,19.5,-45,2,"COMPUTER");
            matColor(0.502, 0.000, 0.000,20,0,1,1);
            dischar(-22.5,19.5,-45,2,"R      ");
            matColor(0.502, 0.000, 0.000,20,0,1,1);
            dischar(-28.5,19.5,-45,3,"WON   ");
        }
        glTranslatef(cx,0,0);
        glPushMatrix();
        matColor(0.000, 0.392, 0.000,20,0,1,1);
        dischar(-11,15.5,-45,2,"Select ");
        matColor(0.000, 0.392, 0.000,20,0,1,1);
        dischar(-24,15.5,-45,2,"Levels ");
        glPopMatrix();
        glPopMatrix();
        easy2=0,medium=0,arrowgame=0,gungame=0;
    }
    else
    {
        ;
    }
    points2=points;
    sort(points2.begin(),points2.end());
    ll minnum=10000;
    ll shotnumber=0;
    for(ll i=0; i<points2.size(); i++)
    {
        if(points2[i]<minnum && points2[i]!=0)
            minnum=points2[i];
        if(points2[i]==0)
            shotnumber++;
    }
    if(level<=3)
        optimalnumber=max(minnum,points2[level-1+shotnumber]);
    else
        optimalnumber=max(minnum,points2[level-1]);
    if((level*5+score)<=scorecom)
        optimalnumber=0;
    if(easy2)
    {
        glPushMatrix();
        targetboxmove();
        glPopMatrix();
    }
    if (medium)
    {
        //targets on number boxes
        glPushMatrix();
        glTranslatef(sx,11,15);
        targetline();
        glPopMatrix();
    }
    if(arrowgame)
    {
        //Arrow
        glPushMatrix();
        glTranslatef(-23.1,11,az);
        arrowf();
        glPopMatrix();

        //bow
        glPushMatrix();
        glTranslatef(-24.1,9,-64);
        glScalef(4,4,4);
        //glRotatef(-40,0,0,1);
        glRotatef(46,0,1,0);
        glRotatef(15,1,0,0);
        arrowbow();
        glPopMatrix();
    }
    if(gungame)
    {
        //gun
        glPushMatrix();
        glTranslatef(-23,9.8,-62);
        //glRotatef(theta,0,1,0);
        glRotatef(theta2,0,0,1);
        gun();
        glPopMatrix();


        //guli
        glPushMatrix();
        glTranslatef(-22.7,13.52,gz);
        glPushMatrix();
        glScalef(gulix,guliy,guliz);
        cube(0,0,0);
        glPopMatrix();
        glPopMatrix();

    }



    //ceil
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e1);
    glTranslatef(0,75,30);
    ceil();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //back wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e2);
    glTranslatef(0,20,110);
    back_wall();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //side wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e3);
    glTranslatef(-160,20,30);
    side_wall();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //side wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e3);
    glTranslatef(115,20,30);
    side_wall();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //field
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e5);
    glTranslatef(0,-50,10);
    floor();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //lights
    glPushMatrix();
    alllights();
    glPopMatrix();


    glPushMatrix();
    if(computer)
    {

        matColor(0.9, 0.0500, 0.100,20,0,1,1);
        dischar(14,16,-45,2,"COMPUTER");
        matColor(0.9, 0.0500, 0.100,20,0,1,1);
        dischar(0,16,-45,2,"R      ");
        matColor(0.9, 0.0500, 0.100,20,0,1,1);
        dischar(12,12,-45,2,"MODE   ");
        //Sleep(10);
        //computer=0;
        if(optimalnumber==10)
        {
            if(x1<=-12 && x1>=-14 && easy2)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
            else if(sx>=-10.2 && sx<=-9.1 && medium && temp0==0)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
        }
        else if(optimalnumber==9)
        {
            if(x2<=-12 && x2>=-14 &&easy2)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
            else if(sx>=-25.1 && sx<=-24.1&&medium && temp0==0)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
        }
        else if(optimalnumber==8)
        {
            if(x3<=-12 && x3>=-14 &&easy2)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
            else if(sx>=-40.1 && sx<=-39.1 && medium && temp0==0)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
        }
        else if(optimalnumber==7)
        {
            if(x4<=-12 && x4>=-14 &&easy2)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
            else if(sx>=-55.1 && sx<=-54.1&&medium && temp0==0)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
        }
        else if(optimalnumber==6)
        {
            if(x5<=-12 && x5>=-14 &&easy2)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
            else if(sx>=-70.1 && sx<=-69.1&&medium&& temp0==0)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
        }
        else if(optimalnumber==5)
        {
            if(x6<=-12 && x6>=-14 &&easy2)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
            else if(sx>=-85.1 && sx<=-84.1 && medium && temp0==0)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
        }
        else
        {
            if(x6<=-6 && x6>=-7 && easy2)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
            else if(sx>=-100.1 && sx<=-99.1 && medium&& temp0==0)
            {
                mouseButton(GLUT_LEFT_BUTTON,GLUT_DOWN,40,40);
            }
        }

    }
    else
    {
        matColor(0.9, 0.0500, 0.100,20,0,1,1);
        dischar(11.9,16,-45,2,"USER    ");
        matColor(0.9, 0.0500, 0.100,20,0,1,1);
        dischar(14,12,-45,2,"MODE    ");
    }
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(34,-16,-45,2,"Basic  ");
    glPushMatrix();
    glTranslatef(46,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.8,.2);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(22,-16,-45,3,"Easy   ");
    glPushMatrix();
    glTranslatef(34,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.2,.9);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(8,-16,-45,3,"Normal  ");
    glPushMatrix();
    glTranslatef(19,-15.8,-52);
    glScalef(2,.01,2);
    cube(.6,.7,0);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(-12,-16,-45,3,"Hard  ");
    glPushMatrix();
    glTranslatef(3,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.5,.5);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(-28,-16,-45,3,"Extreme");
    glPushMatrix();
    glTranslatef(-15,-15.8,-52);
    glScalef(2,.01,2);
    cube(.8,.1,0);
    glPopMatrix();
    matColor(0.05, 0.100, 0.0500,20,0,1,1);
    dischar(-58,-9,-45,3,"Box    ");
    dischar(-61,-16,-45,3,"Hit    ");
    glPushMatrix();
    glTranslatef(-40,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.1,.8);
    glPopMatrix();
    matColor(0.05, 0.100, 0.0500,20,0,1,1);
    dischar(-76,-9,-45,3,"Target  ");
    dischar(-84,-16,-45,3,"Hit    ");
    glPushMatrix();
    glTranslatef(-60,-15.8,-52);
    glScalef(2,.01,2);
    cube(1,1,0);
    glPopMatrix();
    matColor(0.08, 0.0500, 0.100,20,0,1,1);
    dischar(33,-16,-26,3,"Gun    ");
    glPushMatrix();
    glTranslatef(46,-15.8,-35);
    glScalef(2,.01,2);
    cube(.7,.4,.3);
    glPopMatrix();
    matColor(0.08, 0.0500, 0.100,20,0,1,1);
    dischar(20,-16,-26,4,"Arrow  ");
    glPushMatrix();
    glTranslatef(28,-15.8,-35);
    glScalef(2,.01,2);
    cube(.1,.6,.4);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,34,90);
    glScalef(1.0,1.5,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glPushMatrix();
    matColor(0.802, 0.200, 0.100,20,0,1,1);
    scoredisplay2(-133,35,0,6,score);
    glPopMatrix();
    glPushMatrix();
    matColor(0.802, 0.200, 0.100,20,0,1,1);
    scoredisplay(-136,25,0,7,scorecom);
    glPopMatrix();
    glPushMatrix();
    matColor(0.000, 0.000, 0.804,20,0,1,1);
    scoredisplayinstant(42,35,0,4,level,inst);
    glPopMatrix();


    if(easy==0 && hard==0 && easy2==0 && easy3==0 && medium==0 && gungame==0 && arrowgame==0 && userlife==0)
    {
        glPushMatrix();
        matColor(0.502, 0.000, 0.000,20,0,1,1);
        dischar(-8.5,21.5,-45,2,"SHOOTING");
        matColor(0.502, 0.000, 0.000,20,0,1,1);
        dischar(-22.5,21.5,-45,2,"G       ");
        matColor(0.502, 0.000, 0.000,20,0,1,1);
        dischar(-28.5,21.5,-45,3,"GAME   ");
        glTranslatef(cx,0,0);
        glPushMatrix();
        matColor(0.000, 0.392, 0.000,20,0,1,1);
        dischar(-11,14.5,-45,2,"Select ");
        matColor(0.000, 0.392, 0.000,20,0,1,1);
        dischar(-24,14.5,-45,2,"Levels ");
        glPopMatrix();
        glPopMatrix();
    }


    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'm':
        triggercount+=1.0;
        //cout<<triggercount<<endl;
        if(triggercount>=5.0)
        {
            trigger=true;
            triggercount=0.0;
        }
        gunshot=true;
        break;
    case 'H':
        medium=1;
        easy2=0;
        score=0;
        break;
    case 'E':
        medium=0;
        easy2=1;
        score=0;
        break;
    case 'G':
        gungame=1;
        arrowgame=0;
        score=0;
        break;
    case 'A':
        arrowgame=1;
        gungame=0;
        score=0;
        break;
    case 27:
        exit(1);
    }
}

void animate()
{
    if(sunny)
    {
        e1=ceilbmp;
        e2=wall;
        e3=sidewall1;
        e4=sidewall1;
        e5=field;
    }
    if(arrowshot)
    {
        az+=.6;
        if(az>=80)
        {
            arrowshot=false;
        }
    }
    else
    {
        az=ina;
    }
    if(arrowgame && easy2)
    {
        if(az<=25 && az>=24.5)
        {
            if(x1>=-32 && x1<=-22)
            {
                if(computer)
                    scorecom+=points[0];
                else
                    score+=points[0];
                scoreinst=points[0];
                points[0]=0;
                d10=1;
            }
            else if(x2>=-32 && x2<=-22)
            {
                if(computer)
                    scorecom+=points[1];
                else
                    score+=points[1];
                scoreinst=points[1];
                points[1]=0;
                d9=1;
            }
            else if(x3>=-32 && x3<=-22)
            {
                if(computer)
                    scorecom+=points[2];
                else
                    score+=points[2];
                scoreinst=points[2];
                points[2]=0;
                d8=1;
            }
            else if(x4>=-32 && x4<=-22)
            {
                if(computer)
                    scorecom+=points[3];
                else
                    score+=points[3];
                scoreinst=points[3];
                points[3]=0;
                d7=1;
            }
            else if(x5>=-32 && x5<=-22)
            {
                if(computer)
                    scorecom+=points[4];
                else
                    score+=points[4];
                scoreinst=points[4];
                points[4]=0;
                d6=1;
            }
            else if(x6>=-32 && x6<=-22)
            {
                if(computer)
                    scorecom+=points[5];
                else
                    score+=points[5];
                scoreinst=points[5];
                points[5]=0;
                d5=1;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(arrowgame && medium)
    {
        if(az<=25 && az>=24.5)
        {
            if(sx<=-28.1 && sx>=-34.1)
            {
                if(computer)
                    scorecom+=points[0];
                else
                    score+=points[0];
                scoreinst=points[0];
                points[0]=0;
                d10=1;
            }
            else if(sx<=-43.1 && sx>=-49.1)
            {
                if(computer)
                    scorecom+=points[1];
                else
                    score+=points[1];
                scoreinst=points[1];
                points[1]=0;
                d9=1;
            }
            else if(sx<=-58.1 && sx>=-64.1)
            {
                if(computer)
                    scorecom+=points[2];
                else
                    score+=points[2];
                scoreinst=points[2];
                points[2]=0;

                d8=1;
            }
            else if(sx<=-73.1 && sx>=-79.1)
            {
                if(computer)
                    scorecom+=points[3];
                else
                    score+=points[3];
                scoreinst=points[3];
                d7=1;
                points[3]=0;

            }
            else if(sx<=-88.1 && sx>=-94.1)
            {
                if(computer)
                    scorecom+=points[4];
                else
                    score+=points[4];
                scoreinst=points[4];
                points[4]=0;
                d6=1;
            }
            else if(sx<=-103.1 && sx>=-109.1)
            {
                if(computer)
                    scorecom+=points[5];
                else
                    score+=points[5];
                scoreinst=points[5];
                points[5]=0;
                d5=1;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(trigger && gungame)
    {
        if(c1)
        {
            triggery-=.05;
            if(triggery<=-4.1)
            {
                c1=0;
            }
        }
        else
        {
            triggery+=.05;
            if(triggery>=0)
            {
                trigger=false;
                c1=1;
            }
        }
    }
    if(gunshot)
    {
        gz+=.5;
        if(gz>=80)
        {
            gunshot=false;
            if((arrowgame || gungame) && (easy2 || medium))
            {

                computer=!computer;
            }
        }
    }
    else
    {
        gz=inz;
    }
    if(gungame && easy2)
    {
        if(gz<=16 && gz>=15.6)
        {
            if(x1>=-34 && x1<=-24)
            {
                if(computer)
                    scorecom+=points[0];
                else
                    score+=points[0];
                scoreinst=points[0];
                points[0]=0;
                d10=1;
            }
            else if(x2>=-34 && x2<=-24)
            {
                if(computer)
                    scorecom+=points[1];
                else
                    score+=points[1];
                scoreinst=points[1];
                points[1]=0;
                d9=1;
            }
            else if(x3>=-34 && x3<=-24)
            {
                if(computer)
                    scorecom+=points[2];
                else
                    score+=points[2];
                scoreinst=points[2];
                points[2]=0;
                d8=1;
            }
            else if(x4>=-34 && x4<=-24)
            {
                if(computer)
                    scorecom+=points[3];
                else
                    score+=points[3];
                scoreinst=points[3];
                points[3]=0;
                d7=1;
            }
            else if(x5>=-34 && x5<=-24)
            {
                if(computer)
                    scorecom+=points[4];
                else
                    score+=points[4];
                scoreinst=points[4];
                points[4]=0;
                d6=1;
            }
            else if(x6>=-34 && x6<=-24)
            {
                if(computer)
                    scorecom+=points[5];
                else
                    score+=points[5];
                scoreinst=points[5];
                points[5]=0;
                d5=1;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(gungame && medium)
    {
        if(gz<=10 && gz>=9.7)
        {
            if(sx<=-28.1 && sx>=-34.1)
            {
                if(computer)
                    scorecom+=points[0];
                else
                    score+=points[0];
                scoreinst=points[0];
                points[0]=0;
                d10=1;
            }
            else if(sx<=-43.1 && sx>=-49.1)
            {
                if(computer)
                    scorecom+=points[1];
                else
                    score+=points[1];
                scoreinst=points[1];
                points[1]=0;
                d9=1;
            }
            else if(sx<=-58.1 && sx>=-64.1)
            {
                if(computer)
                    scorecom+=points[2];
                else
                    score+=points[2];
                scoreinst=points[2];
                points[2]=0;

                d8=1;
            }
            else if(sx<=-73.1 && sx>=-79.1)
            {
                if(computer)
                    scorecom+=points[3];
                else
                    score+=points[3];
                scoreinst=points[3];
                d7=1;
                points[3]=0;

            }
            else if(sx<=-88.1 && sx>=-94.1)
            {
                if(computer)
                    scorecom+=points[4];
                else
                    score+=points[4];
                scoreinst=points[4];
                points[4]=0;
                d6=1;
            }
            else if(sx<=-103.1 && sx>=-109.1)
            {
                if(computer)
                    scorecom+=points[5];
                else
                    score+=points[5];
                scoreinst=points[5];
                points[5]=0;
                d5=1;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(easy2)
    {
        x1-=.1;
        if(x1<=40 || t1)
        {
            x2-=.1;
        }
        if(x2<=40 ||t2)
        {
            x3-=.1;
        }
        if(x3<=40 ||t3)
        {
            x4-=.1;
        }
        if(x4<=40 ||t4)
        {
            x5-=.1;
        }
        if(x5<=40 ||t5)
        {
            x6-=.1;
        }
        if(x2<=-110)
        {
            x2=70;
            t2=1;
        }
        if(x3<=-110)
        {
            x3=70;
            t3=1;
        }
        if(x4<=-110)
        {
            x4=70;
            t4=1;
        }
        if(x5<=-110)
        {
            x5=70;
            t5=1;
        }
        if(x6<=-110)
        {
            x6=70;
        }
        if(x1<=-110)
        {
            x1=70;
            t1=1;
        }
    }
    else
    {
        x1=70.0;
        x2=70.0;
        x3=70.0;
        x4=70.0;
        x5=70.0;
        x6=70.0;
        t1=0,t2=0,t3=0,t4=0,t5=0;
    }

    if(temp0)
        sx+=.18;
    else
        sx-=.18;
    if(sx<-115)
    {
        sx+=.18;
        temp0=1;
    }
    else if(sx>-7)
    {
        sx-=.18;
        temp0=0;
    }
    if(temp1)
        ux+=.1;
    else
        ux-=.1;
    if(ux<-60)
    {
        ux+=.1;
        temp1=1;
    }
    else if(ux>60)
    {
        ux-=.1;
        temp1=0;
    }
    if(temp4)
        cx+=.03;
    else
        cx-=.03;
    if(cx<-6)
    {
        cx+=.03;
        temp4=1;
    }
    else if(cx>6)
    {
        cx-=.03;
        temp4=0;
    }
    xxx+=1;
    glutPostRedisplay();
}
void LoadTexture(const char*filename, GLuint s)
{
    glGenTextures(1, &s);
    glBindTexture(GL_TEXTURE_2D, s);
    glPixelStorei(GL_UNPACK_ALIGNMENT, s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}

int main (int argc, char **argv)
{
    points.push_back(10);
    points.push_back(9);
    points.push_back(8);
    points.push_back(7);
    points.push_back(6);
    points.push_back(5);
    points2=points;
    points3=points;
    reserved=points;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("1607066");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\wall.bmp",wall);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\side.bmp",sidewall1);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\ceil3.bmp",ceilbmp);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\floor.bmp",field);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\target2.bmp",target);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\10.bmp",ten);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\9.bmp",nine);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\8.bmp",eight);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\7.bmp",seven);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\6.bmp",six);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\5.bmp",five);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\ten.bmp",uten);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\0.bmp",zero);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\sceil.bmp",sceilbmp);

    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\sfloor.bmp",sfield);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
