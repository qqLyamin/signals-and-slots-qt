#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)
{

    myFrame = new QFrame(this);
    myFrame->setFrameStyle(6);

    Qt::WindowFlags myflags;
    myflags |= Qt::CustomizeWindowHint;
    myflags |= Qt::WindowTitleHint;
    this->setWindowFlags(myflags);
    this->setWindowTitle("SignalSlot_2019_2");

    QPushButton * my_first_button = new QPushButton(QObject::tr("Exit"), this);

    my_style_button = new QPushButton(QObject::tr("Fusion style"), this);

    my_disable_button = new QPushButton(QObject::tr("Disable"), this);

    my_slider = new QSlider(Qt::Horizontal, this);
    my_slider->setMaximum(99);
    my_slider->setMinimum(0);
    my_slider->setTickInterval(2);
    my_slider->setMinimumWidth(150);
    my_slider->setTickPosition(QSlider::TicksBelow);

    mySpin = new QSpinBox(this);
    mySpin->setMaximum(99);
    mySpin->setMinimum(0);
    mySpin->setSingleStep(2);
    mySpin->setValue(my_slider->value());

    myLE = new QLineEdit(this);
    myLE->setValidator(new QIntValidator(0, 99, this));

    myLabel = new QLabel("00", this);
    myLabel->setFrameStyle(7);

    QComboBox * mycombobox = new QComboBox(this);
    mycombobox->addItem("Horizontal L-out");
    mycombobox->addItem("Vertical L-out");
    mycombobox->addItem("Grid L-out");

    my_QVBOX_layout_right = new QVBoxLayout();
    my_QVBOX_layout_right->addWidget(mycombobox);
    my_QVBOX_layout_right->addWidget(my_first_button);
    my_QVBOX_layout_right->addWidget(my_disable_button);
    my_QVBOX_layout_right->addWidget(my_style_button);

    create_horizontal_layout();

    my_main_layout = new QHBoxLayout(this);
    my_main_layout->addWidget(myFrame);
    my_main_layout->addLayout(my_QVBOX_layout_right);


    connect(myLE, SIGNAL(textChanged(QString)), myLabel, SLOT(setText(QString)));
    connect(my_slider, SIGNAL(sliderMoved(int)), mySpin, SLOT(setValue(int)));
    connect(mySpin, SIGNAL(valueChanged(int)), my_slider, SLOT(setValue(int)));
    connect(mySpin, SIGNAL(valueChanged(QString)), myLE, SLOT(setText(QString)));
    connect(myLE, SIGNAL(textChanged(QString)), this, SLOT(my_LE_slot(QString)));
    connect(this, SIGNAL(my_LE_signal(int)), mySpin, SLOT(setValue(int)));
    connect(my_first_button, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(my_disable_button, SIGNAL(clicked(bool)), this, SLOT(my_disable_slot()));
    connect(mycombobox, SIGNAL(activated(int)), this, SLOT(my_layout_change(int)));
    connect(my_style_button, SIGNAL(clicked(bool)), this, SLOT(change_window_style()));

}

void MyWindow::my_LE_slot(QString input)
{
    emit my_LE_signal(input.toInt());
}

void MyWindow::change_window_style()
{
    if(number_of_style == 0)
    {
        QApplication::setStyle(QStyleFactory::create("Windows"));
        my_style_button->setText("Fusion");
        number_of_style = 1;
    }
    else if(number_of_style == 1)
    {
        QApplication::setStyle(QStyleFactory::create("Fusion"));
        my_style_button->setText("Windows Vista");
        number_of_style = 2;
    }
    else
    {
        QApplication::setStyle(QStyleFactory::create("windowsvista"));
        my_style_button->setText("Windows");
        number_of_style = 0;
    }
}

void MyWindow::my_disable_slot()
{
    if(myFrame->isEnabled())
    {
        myFrame->setDisabled(true);
        my_disable_button->setText("Enable");
    }
    else
    {
        myFrame->setEnabled(true);
        my_disable_button->setText("Disable");
    }
}

void MyWindow::my_layout_change(int number)
{
    //удаляю старые layoutы
    if(myFrame->layout() == my_QHBOX_layout)
    {
        qDebug() << "deleted 1st";
        delete my_QHBOX_layout;
    }
    else if(myFrame->layout() == my_QVBOX_layout_left)
    {
        qDebug() << "deleted 2nd";
        delete my_QVBOX_layout_left;
    }
    else if(myFrame->layout() == my_GRID_layout)
    {
        qDebug() << "deleted 3d";
        delete my_GRID_layout;
    }

    if(number == 0)
    {
        this->hide();
        create_horizontal_layout();
        this->show();
    }
    else if(number == 1)
    {
        this->hide();
        create_vertical_layout();
        this->show();
    }
    else
    {
        this->hide();
        create_grid_layout();
        this->show();
    }
}

void MyWindow::create_horizontal_layout()
{
    my_QHBOX_layout = new QHBoxLayout();
    my_QHBOX_layout->addWidget(mySpin);
    my_QHBOX_layout->addWidget(my_slider);
    my_QHBOX_layout->addWidget(myLE);
    my_QHBOX_layout->addWidget(myLabel);
    myFrame->setLayout(my_QHBOX_layout);
}

void MyWindow::create_vertical_layout()
{
    my_QVBOX_layout_left = new QVBoxLayout();
    my_QVBOX_layout_left->addWidget(mySpin);
    my_QVBOX_layout_left->addWidget(my_slider);
    my_QVBOX_layout_left->addWidget(myLE);
    my_QVBOX_layout_left->addWidget(myLabel);
    myFrame->setLayout(my_QVBOX_layout_left);
}

void MyWindow::create_grid_layout()
{
    my_GRID_layout = new QGridLayout();
    my_GRID_layout->addWidget(mySpin);
    my_GRID_layout->addWidget(my_slider);
    my_GRID_layout->addWidget(myLE);
    my_GRID_layout->addWidget(myLabel);
    myFrame->setLayout(my_GRID_layout);
}



MyWindow::~MyWindow()
{

}




