#include "myglwidget.h"
#include <time.h>
#include <assert.h>
using namespace std;

bool mvcube = true, newpart, to_run=true;
GLfloat react=0.01, radius = 0.5, radiusrev = radius*-1.0;
int ngas = 0, speed = 1;
bool mkgas[1000000];
GLfloat pre[1000000][6];
GLfloat gas[1000000][10];

float _alea(float min, float max)
{
    srand ( time(NULL) );
    assert(max > min);
    float random = ((float) rand()) / (float) RAND_MAX;
    float range = max - min;
    return (random*range) + min;
}
float xAlea=_alea(-1.0, 1.0);
float alea(float min, float max, float x)
{
        srand ( time(0)*x );
    assert(max > min);
    float random = ((float) rand()) / (float) RAND_MAX;
    float range = max - min;
    xAlea=(random*range) + min;
    return (random*range) + min;
}

myGLWidget::myGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(run()));
    timer->start(100);
}

void myGLWidget::initializeGL(){
    glClearColor(0.8,0.8,0.8,0);
    glClearDepth(1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void myGLWidget::resizeGL( int width, int height )
{//não esta redimensionando o painel GL
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}

void myGLWidget::cube(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor4f(1.0, 0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);                // Frente
        glNormal3f(0.0, 0.0, 1.0);      // Normal
        glVertex3f(radius, radius, radius);
        glVertex3f(radiusrev, radius, radius);
        glVertex3f(radiusrev, radiusrev, radius);
        glVertex3f(radius, radiusrev, radius);
    glEnd();

    glColor4f(0.0, 0.1, 0.0, 0.1);
    glBegin(GL_POLYGON);                // Frente
        glNormal3f(0.0, 0.0, -1.0);     // Normal
        glVertex3f(radius, radius, radiusrev);
        glVertex3f(radius, radiusrev, radiusrev);
        glVertex3f(radiusrev, radiusrev, radiusrev);
        glVertex3f(radiusrev, radius, radiusrev);
    glEnd();

    glColor4f(0.0, 0.0, 0.1, 0.1);
    glBegin(GL_POLYGON);                //Esquerda
        glNormal3f(-1.0, 0.0, 0.0);     //Normal
        glVertex3f(radiusrev, radius, radius);
        glVertex3f(radiusrev, radius, radiusrev);
        glVertex3f(radiusrev, radiusrev, radiusrev);
        glVertex3f(radiusrev, radiusrev, radius);
    glEnd();

    glColor4f(0.1, 0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);              //Direita
        glNormal3f(1.0, 0.0, 0.0);    //Normal
        glVertex3f(radius, radius, radius);
        glVertex3f(radius, radiusrev, radius);
        glVertex3f(radius, radiusrev, radiusrev);
        glVertex3f(radius, radius, radiusrev);
    glEnd();

    glColor4f(0.0, 0.1, 0.0, 0.1);
    glBegin(GL_POLYGON);                // Topo
        glNormal3f(0.0, 1.0, 0.0);      // Normal
        glVertex3f(radiusrev, radius, radiusrev);
        glVertex3f(radiusrev, radius, radius);
        glVertex3f(radius, radius, radius);
        glVertex3f(radius, radius, radiusrev);
    glEnd();

    glColor4f(0.0, 0.0, 0.1, 0.1);
    glBegin(GL_POLYGON);                // Piso
        glNormal3f(0.0, -1.0, 0.0);     // Normal
        glVertex3f(radiusrev, radiusrev, radiusrev);
        glVertex3f(radius, radiusrev, radiusrev);
        glVertex3f(radius, radiusrev, radius);
        glVertex3f(radiusrev, radiusrev, radius);
    glEnd();
};

void myGLWidget::particle(GLfloat args[], int p, bool ck){
    GLfloat mx=args[3], my=args[4], mz=args[5];
    GLfloat nx=args[0], ny=args[1], nz=args[2];
    if ((args[0] >= radius) || (args[0] <= radiusrev)){
        mx = args[3]*-1.0;
        if (nx>0){
            nx = radius;
        }
        else{
            nx = radiusrev;
        }
    }
    if ((args[1] >= radius) || (args[1] <= radiusrev)){
        my = args[4]*-1.0;
        if (ny>0){
            ny = radius;
        }
        else{
            ny = radiusrev;
        }
    }
    if ((args[2] >= radius) || (args[2] <= radiusrev)){
        mz = args[5]*-1.0;
        if (nz>0){
            nz = radius;
        }
        else{
            nz = radiusrev;
        }
    }

    if(ck){ // gera um segundo array de particulas com as posições pre processadas
        pre[p][0] = nx + mx;
        pre[p][1] = ny + my;
        pre[p][2] = nz + mz;
        pre[p][3] = args[3];
        pre[p][4] = args[4];
        pre[p][5] = args[5];
    }
    else{
        args[0] = nx;
        args[1] = ny;
        args[2] = nz;
        int n = 0;
        for (int x=0;x<ngas;x++){
            GLfloat r[3] = {0,0,0};
            for (int a=0;a<3;a++){
                GLfloat i[2];
                if (pre[p][a] > pre[x][a]){
                    i[0] = pre[x][a];
                    i[1] = pre[p][a];
                }
                else{
                    i[0] = pre[p][a];
                    i[1] = pre[x][a];
                }
                while(i[0] <= i[1]){
                    i[0] += react;
                    r[a] += react;
                }
            }
            if ((r[0] <= react) && (r[1] <= react) && (r[2] <= react) && (p != x)){
                n++;
            }
        }
        GLfloat bump[n][3];
        if(n == 0){
            args[0] = nx + mx;
            args[1] = ny + my;
            args[2] = nz + mz;
            args[3] = mx;
            args[4] = my;
            args[5] = mz;
        }
        else{
            n=0;
            GLfloat antimom[3] = {0, 0, 0};//soma dos momentos de x, y, z das particulas em sentido oposto
            GLfloat promom[3] = {0, 0, 0};//soma dos momentos de x, y, z das particulas no mesmo sentido
            int disp[3] = {1, 1, 1}; //dispersão para os momentos em cada eixo x,y,z
            for (int x=0;x<ngas;x++){
                GLfloat r[3] = {0,0,0};
                for (int a=0;a<3;a++){
                    GLfloat i[2];
                    if (pre[p][a] > pre[x][a]){
                        i[0] = pre[x][a];
                        i[1] = pre[p][a];
                    }
                    else{
                        i[0] = pre[p][a];
                        i[1] = pre[x][a];
                    }
                    while(i[0] <= i[1]){
                        i[0] += react;
                        r[a] += react;
                    }
                }
                if ((r[0] <= react) && (r[1] <= react) && (r[2] <= react) && (p != x)){
                    bump[n][0] = pre[x][3]; //mom x
                    bump[n][1] = pre[x][4]; //mom y
                    bump[n][2] = pre[x][5]; //mom z
                    n++; //count bumps
                }
            }
            for (int x=0;x<3;x++){
                GLfloat _zero=0.0;
                int x2 = x+3; // no array gas moms estao entre 3~5, em bump e antimom 0~2
                for (int a=0;a<n;a++){
                    if (((args[x2]<_zero) && (bump[a][x]>_zero)) || ((args[x2]>_zero) && (bump[a][x]<_zero))){
                        antimom[x] += bump[a][x];
                    }
                    else{
                        disp[x]++;
                        promom[x] += bump[a][x];
                    }
                }
                if (antimom[x] == 0){//no caso de momentos estarem no mesmo sentido
                    args[x2] = promom[x]/disp[x]; //setando novo momento
                }
                else{//no caso de momento em sentido oposto
                    args[x2] = antimom[x]/disp[x]; //setando novo momento
                }
            }
        }
        glPushMatrix();
        glPointSize(200*react);
        glBegin(GL_POINTS);
            glColor4f(args[6], args[7], args[8], args[9]);
            glVertex3f(args[0], args[1], args[2]); //X, Y, Z
        glEnd();
        glPopMatrix();
    }

}

void myGLWidget::paintGL()
{
    cube();
    if(mvcube){ //gira o cubo, if serve para girar apenas uma vez
        glRotatef(15,1,0,0);
        glRotatef(10,0,1,0);
        mvcube=false;
    }
    if (newpart){
        newpart=false;
        for (int p=0;p<ngas;p++){
            if (mkgas[p]!=true){
                gas[p][0] = alea(-0.4, 0.4, xAlea);
                gas[p][1] = alea(-0.4, 0.4, xAlea);
                gas[p][2] = alea(-0.4, 0.4, xAlea);
                gas[p][3] = alea(-0.02, 0.02, xAlea);
                gas[p][4] = alea(-0.02, 0.02, xAlea);
                gas[p][5] = alea(-0.02, 0.02, xAlea);
                gas[p][6] = alea(-1.0, 1.0, xAlea);
                gas[p][7] = alea(-1.0, 1.0, xAlea);
                gas[p][8] = alea(-1.0, 1.0, xAlea);
                gas[p][9] =  1.0;
                mkgas[p]=true;
            }
        }
    }
    for (int p=0;p<ngas;p++){
        particle(gas[p], p, true);
    }
    for (int p=0;p<ngas;p++){
        particle(gas[p], p, false);
    }
}

void myGLWidget::play(bool checked){
    if(checked)
        to_run=true;
    else
        to_run=false;
}

void myGLWidget::run(){
    if(to_run)
        for(int x=0;x<speed;x++){
            updateGL();
        }
}

void myGLWidget::girox(int v){
    glRotatef(v,0,1,0);
    updateGL();
}

void myGLWidget::giroy(int v){
    glRotatef(v,1,0,0);
    updateGL();
}

void myGLWidget::giroz(){
    glRotatef(-5,0,0,1);
    updateGL();
}
void myGLWidget::giroz_(){
    glRotatef(5,0,0,1);
    updateGL();
}

void myGLWidget::cubesize(double v){
    radius = v;
    radiusrev = radius * -1;
    updateGL();
}

void myGLWidget::faster(int s){
    speed = s;
}

void myGLWidget::add(int n){
    ngas=n;
    newpart=true;
    updateGL();
}

void myGLWidget::reset(){
    for (int p=0;p<1000000;p++){
        mkgas[p]=false;
    }
    newpart=true;
}

void myGLWidget::twoparticles(){
    ngas = 2;
            gas[0][0] = 0.2;
            gas[0][1] = 0.2;
            gas[0][2] = 0.2;
            gas[0][3] = 0;
            gas[0][4] = -0.01;
            gas[0][5] = 0;
            gas[0][6] = 1.0;
            gas[0][7] = 0.0;
            gas[0][8] = 0.0;
            gas[0][9] =  1.0;
            mkgas[0]=true;

            gas[1][0] = 0.2;
            gas[1][1] = -0.3;
            gas[1][2] = 0.2;
            gas[1][3] = 0;
            gas[1][4] = 0.03;
            gas[1][5] = 0;
            gas[1][6] = 0.0;
            gas[1][7] = 0.0;
            gas[1][8] = 1.0;
            gas[1][9] =  1.0;
            mkgas[0]=true;
}

void myGLWidget::chain(){
    speed=10;
            gas[0][0] = 0.4;
            gas[0][1] = 0.4;
            gas[0][2] = 0.4;
            gas[0][3] = -0.03;
            gas[0][4] = -0.03;
            gas[0][5] = -0.03;
            gas[0][6] = 0;
            gas[0][7] = 0;
            gas[0][8] = 0;
            gas[0][9] =  1.0;
            mkgas[0]=true;

        for (int p=1;p<ngas;p++){
            gas[p][0] = alea(-0.03, 0.0, xAlea);
            gas[p][1] = alea(-0.03, 0.01, xAlea);
            gas[p][2] = alea(-0.03, 0.01, xAlea);
            gas[p][3] = 0;
            gas[p][4] = 0;
            gas[p][5] = 0;
            gas[p][6] = alea(-1.0, 1.0, xAlea);
            gas[p][7] = alea(-1.0, 1.0, xAlea);
            gas[p][8] = alea(-1.0, 1.0, xAlea);
            gas[p][9] =  1.0;
            mkgas[p]=true;
        }
}
