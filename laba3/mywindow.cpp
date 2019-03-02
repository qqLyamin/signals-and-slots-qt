#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)
{
    Qt::WindowFlags myflags;
    myflags |= Qt::CustomizeWindowHint;
    myflags |= Qt::WindowTitleHint;
    this->setWindowFlags(myflags);
    this->setWindowTitle("SignalSlot_2019_2");
    this->setFixedSize(400, 200);

    QPushButton * my_first_button = new QPushButton(QObject::tr("Exit"), this);
    my_first_button->move(300, 20);

    QSlider * my_slider = new QSlider(Qt::Horizontal, this);
    my_slider->move(60, 20);
    my_slider->setMaximum(10);
    my_slider->setMinimum(0);
    my_slider->setTickInterval(2);
    my_slider->setFixedSize(150, 20);
    my_slider->setTickPosition(QSlider::TicksBelow);

    QSpinBox * mySpin = new QSpinBox(this);
    mySpin->move(5, 20);
    mySpin->setMaximum(10);
    mySpin->setMinimum(0);
    mySpin->setSingleStep(2);
    mySpin->setValue(my_slider->value());

    QLineEdit * myLE = new QLineEdit(this);
    myLE->setFixedSize(70, 20);
    myLE->move(220, 20);
    myLE->setValidator(new QIntValidator(0, 10, this));

//    connect(lineEdit, SIGNAL(textChanged(QString)), SLOT(onTextChanged(QString)));
//    connect(spinbox, SIGNAL(valueChanged(QString)), lineEdit, SLOT(setText(QString)));
//    connect(myLE, SLOT(onTextChanged(QString)), mySpin, SIGNAL(setValue(onTextChanged)));

    connect(my_slider, SIGNAL(sliderMoved(int)), mySpin, SLOT(setValue(int)));
    connect(mySpin, SIGNAL(valueChanged(int)), my_slider, SLOT(setValue(int)));

    connect(myLE, SIGNAL(textchanged(QString)), SLOT(onTextChanged(QString)));
    connect(mySpin, SIGNAL(valueChanged(QString)), myLE, SLOT(setText(QString)));


//    connect(myLE, SIGNAL(textChanged(QString), SLOT(onTextChanged));
//    connect(myLE, SIGNAL(valueChanged(int)), mySpin, SLOT(setValue(int)));


    connect(my_first_button, SIGNAL(clicked(bool)), this, SLOT(close()));

}

MyWindow::~MyWindow()
{

}
