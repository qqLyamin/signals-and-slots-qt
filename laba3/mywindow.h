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
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>
#include <QApplication>
#include <QStyleFactory>

class MyWindow : public QWidget
{

    Q_OBJECT

    int number_of_style = 0;

    QVBoxLayout * my_QVBOX_layout_right;
    QVBoxLayout * my_QVBOX_layout_left;

    QGridLayout * my_GRID_layout;

    QHBoxLayout * my_QHBOX_layout;

    QHBoxLayout * my_main_layout;

    QFrame * myFrame;
    QPushButton * my_disable_button;
    QPushButton * my_style_button;
    QSlider * my_slider;
    QSpinBox * mySpin;
    QLineEdit * myLE;
    QLabel * myLabel;

public:
    MyWindow(QWidget *parent = 0);
    ~MyWindow();

    void create_horizontal_layout();
    void create_vertical_layout();
    void create_grid_layout();

public slots:

    void my_layout_change(int);
    void my_disable_slot();
    void my_LE_slot(QString);
    void change_window_style();

signals:

    void my_LE_signal(int);


};

#endif // MYWINDOW_H
