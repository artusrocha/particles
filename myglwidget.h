#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QTimer>

class myGLWidget : public QGLWidget
{
Q_OBJECT
public:
    explicit myGLWidget(QWidget *parent = 0);

signals:

public slots:
    void run();
    void girox(int v);
    void giroy(int v);
    void giroz();
    void giroz_();
    void play(bool checked);
    void cubesize(double);
    void add(int n);
    void faster(int s);
    void reset();
    void twoparticles();
    void chain();

protected:
    void initializeGL();
    void resizeGL( int width, int height );
    void paintGL();
    void cube();
    void particle(GLfloat args[], int p, bool ck);
    
private:

};

#endif // MYGLWIDGET_H
