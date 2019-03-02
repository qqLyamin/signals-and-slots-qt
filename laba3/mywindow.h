#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QRect>
#include <QMouseEvent>
#include <QSlider>
#include <QLineEdit>
#include <QSpinBox>

class MyWindow : public QWidget
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = 0);
    ~MyWindow();

};

#endif // MYWINDOW_H
