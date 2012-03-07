#include "myglwidget.h"
#include <iostream>
using namespace std;

bool to_run;
bool mvcube = true;//girar cubo?
GLfloat radius = 0.5; //raio do cubo
GLfloat radiusrev = radius*-1.0;
GLfloat react=0.01;
GLfloat pre[13][6];
GLfloat gas[13][10] = {
                { 0.3,-0.2, 0.2, 0.002, 0.001, 0.001, 1.0, 0.0, 0.0, 1.0},
                { 0.3, 0.1, 0.2,-0.001, 0.002,-0.001, 0.0, 0.0, 1.0, 1.0},
                {-0.1, 0.0, 0.4, 0.001, 0.001,-0.001, 0.0, 0.0, 1.0, 1.0},
                { 0.0,-0.3, 0.0,-0.001,-0.001,-0.001, 0.0, 1.0, 1.0, 1.0},
                { 0.1, 0.2, 0.3, 0.001,-0.001, 0.001, 0.7, 0.0, 1.0, 1.0},
                {-0.4, 0.3, 0.0,-0.001,-0.001,-0.001, 0.5, 0.0, 0.0, 1.0},
                { 0.1, 0.2, 0.3, 0.001,-0.001, 0.001, 0.0, 0.0, 0.5, 1.0},
                {-0.2, 0.3, 0.0,-0.001,-0.001,-0.001, 0.0, 0.0, 1.0, 1.0},
                { 0.4, 0.2, 0.3, 0.001,-0.001, 0.001, 0.5, 0.0, 1.0, 1.0},
                { 0.1, 0.3, 0.0,-0.001,-0.001,-0.001, 0.1, 0.0, 1.0, 1.0},
                { 0.3, 0.2,-0.4, 0.001,-0.001, 0.001, 0.1, 1.0, 1.0, 1.0},
                { 0.2,-0.3, 0.0,-0.001,-0.001,-0.001, 0.0, 0.5, 1.0, 1.0},
                { 0.1, 0.2, 0.0, 0.001,-0.001, 0.001, 1.0, 0.0, 0.0, 1.0}
                    };
int ngas = sizeof(gas)/sizeof(*gas); //tamanho do array de particulas

myGLWidget::myGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(run()));
    timer->start(1000);
}

void myGLWidget::initializeGL(){
    glClearColor(1,1,1,0);
    glClearDepth(1);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

}

void myGLWidget::resizeGL( int width, int height )
{//não esta redimensionando o painel GL
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);

}

void imprime(GLfloat args[]) {
//cout << args[0] << ", " << args[1] << ", " << args[2] << ", " << args[3] << ", " << args[4] << ", " << args[5] << endl;
}

void myGLWidget::cube(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor4f(0.0, 0.0, 0.0, 0.1);
    glBegin(GL_QUADS);			// Face posterior
        glNormal3f(0.0, 0.0, 1.0);	// Normal da face
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    glColor4f(0.0, 0.0, 0.0, 0.2); // Alpha blending
    glBegin(GL_QUADS);        	// Face frontal
        glNormal3f(0.0, 0.0, -1.0); 	// Normal da face
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    glColor4f(0.0, 0.0, 0.0, 0.15);
    glBegin(GL_QUADS);        	// Face lateral esquerda
        glNormal3f(-1.0, 0.0, 0.0); 	// Normal da face
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    glColor4f(0.0, 0.0, 0.0, 0.15);
    glBegin(GL_QUADS);        	// Face lateral direita
        glNormal3f(1.0, 0.0, 0.0);	// Normal da face
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    glColor4f(0.0, 0.0, 0.0, 0.11);
    glBegin(GL_QUADS);        	// Face superior
        glNormal3f(0.0, 1.0, 0.0);  	// Normal da face
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    glColor4f(0.0, 0.0, 0.0, 0.25);
    glBegin(GL_QUADS);        	// Face inferior
        glNormal3f(0.0, -1.0, 0.0); 	// Normal da face
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
    glEnd();



//    glPushMatrix();

//    glPopMatrix();
};

void myGLWidget::particle(GLfloat args[], int p, bool ck)
{
    GLfloat mx=args[3], my=args[4], mz=args[5];
    if ((args[0] >= radius) || (args[0] <= radiusrev)){
        mx = args[3]*-1.0;
    }
    if ((args[1] >= radius) || (args[1] <= radiusrev)){
        my = args[4]*-1.0;
    }
    if ((args[2] >= radius) || (args[2] <= radiusrev)){
        mz = args[5]*-1.0;
    }

    if(ck){ // gera um segundo array de particulas com as posições pre processadas
        pre[p][0] = args[0] + mx;
        pre[p][1] = args[1] + my;
        pre[p][2] = args[2] + mz;
        pre[p][3] = args[3];
        pre[p][4] = args[4];
        pre[p][5] = args[5];
    }
    else{
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
            args[0] = args[0] + mx;
            args[1] = args[1] + my;
            args[2] = args[2] + mz;
            args[3] = mx;
            args[4] = my;
            args[5] = mz;
        }
        else{
           //cout << n << " bumps===========================================" << endl;
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
                int x2 = x+3; // no array gas moms entao entre 3~5, em bump e antimom 0~2
                for (int a=0;a<n;a++){
                    if (((args[x2]<_zero) && (bump[a][x]>_zero)) || ((args[x2]>_zero) && (bump[a][x]<_zero))){
                        antimom[x] += bump[a][x];
                    }
                    else{
                        disp[x]++;
                        promom[x] += bump[a][x];
                    }
                   //cout << a << " " << x << " " << bump[a][x] << endl;
                }
               //cout << args[x2] << " momento anterior" << endl;
                if (antimom[x] == 0){//no caso de momentos estarem no mesmo sentido
                    args[x2] = promom[x]/disp[x]; //setando novo momento
                }
                else{//no caso de momento em sentido oposto
                    args[x2] = antimom[x]/disp[x]; //setando novo momento
                }
               //cout << args[x2] << " < novo momento " << antimom[x] << " " << disp[x] << endl;
            }

        }
        glPushMatrix();
        glPointSize(200*react);
        glBegin(GL_POINTS);
            glColor4f(args[6], args[7], args[8], args[9]);
            glVertex3f(args[0], args[1], args[2]); //X, Y, Z
        glEnd();
//        imprime(args);
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
    for (int p=0;p<ngas;p++){
        particle(gas[p], p, true);
    }
    for (int p=0;p<ngas;p++){
        particle(gas[p], p, false);
    }
}
/*
class SimpleThread: public Thread {
        private:
                void run() {
                       //cout << "Quente";
                        while (to_run){
                            QGLWidget::updateGL();
                        }
                       //cout << "Congelado" << endl;
                }
};*/

void myGLWidget::run(){
    if(to_run)
        for(int x=0;x<100;x++){
            updateGL();
        }
}

void myGLWidget::play(bool checked){
    if(checked)
        to_run=true;
    else
        to_run=false;
}

void myGLWidget::girox(int v){
    glRotatef(v,0,1,0);
    updateGL();
}

void myGLWidget::giroy(int v){
    glRotatef(v,1,0,0);
    updateGL();
}

void myGLWidget::giroz(int v){
    glRotatef(v,0,0,1);
    updateGL();
}
