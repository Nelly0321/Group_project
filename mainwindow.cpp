#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QStyle>
#include <QStyleOptionTitleBar>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    resize(500,600);
    setWindowTitle("Face Filter App");
    setWindowIcon(QIcon("C:/Users/Asus/OneDrive/Desktop/Filters/Icons/window_icon.jpg"));

    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    QPushButton* minimizeButton = findChild<QPushButton*>("qt_minimize_button");
    if (minimizeButton != nullptr){
        minimizeButton->setIcon(QIcon("C:/Users/Asus/OneDrive/Desktop/Filters/Icons/minimize.jpg"));
    }

    QPushButton* maximizeButton = findChild<QPushButton*>("qt_maximize_button");
    if (maximizeButton != nullptr){
        maximizeButton->setIcon(QIcon("C:/Users/Asus/OneDrive/Desktop/Filters/Icons/maximize.jpg"));
    }

    QPushButton* closeButton = findChild<QPushButton*>("qt_close_button");
    if (closeButton != nullptr){
        closeButton->setIcon(QIcon("C:/Users/Asus/OneDrive/Desktop/Filters/Icons/close.jpg"));
    }

    cameraWidget = new CameraWidget;
    photosWidget = new PhotosWidget;
    filterWidget = new FilterWidget;

    stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(cameraWidget); //0 index
    stackedLayout->addWidget(photosWidget);  //1 index
    stackedLayout->addWidget(filterWidget);  //2 index

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackedLayout);
    setLayout(mainLayout);

    connect(cameraWidget->goToPhotos_button,&QToolButton::clicked,this,[this](){stackedLayout->setCurrentIndex(1);});
    connect(cameraWidget->goToFilter_button,&QToolButton::clicked,this,[this](){
        delete filterWidget->view;
        delete filterWidget->scene;
        filterWidget->setImage("Images/image0.jpg");
        stackedLayout->setCurrentIndex(2);});
    connect(filterWidget->fromFilterback_button,&QToolButton::clicked,this,[this](){stackedLayout->setCurrentIndex(0);});
    connect(photosWidget->fromPhotosBack_button,&QToolButton::clicked,this,[this](){stackedLayout->setCurrentIndex(0);});

    connect(photosWidget->button_array[0],&QToolButton::clicked,this,[this](){
        delete filterWidget->view;
        delete filterWidget->scene;
        filterWidget->setImage(photosWidget->path_array[0]);
        stackedLayout->setCurrentIndex(2);});
    connect(photosWidget->button_array[1],&QToolButton::clicked,this,[this](){
        delete filterWidget->view;
        delete filterWidget->scene;
        filterWidget->setImage(photosWidget->path_array[1]);
        stackedLayout->setCurrentIndex(2);});
    connect(photosWidget->button_array[2],&QToolButton::clicked,this,[this](){
        delete filterWidget->view;
        delete filterWidget->scene;
        filterWidget->setImage(photosWidget->path_array[2]);
        stackedLayout->setCurrentIndex(2);});
    connect(photosWidget->button_array[3],&QToolButton::clicked,this,[this](){
        delete filterWidget->view;
        delete filterWidget->scene;
        filterWidget->setImage(photosWidget->path_array[3]);
        stackedLayout->setCurrentIndex(2);});

    connect(photosWidget->button_array[4],&QToolButton::clicked,this,&MainWindow::addPhoto);
}


void MainWindow::addPhoto()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", "", "JPEG files (*.jpg);;All files (*.*)");
    if(filePath=="")
    {
        return;
    }
    QToolButton* button = new QToolButton(this);
    button->setIcon(QIcon(filePath));
    button->setIconSize(QSize(200, 200));
    button->setAutoRaise(true);
    button->setStyleSheet("QToolButton { border: none; }");
    photosWidget->button_array.append(button);


    QToolButton* tmp=new QToolButton;
    tmp=photosWidget->button_array[photosWidget->button_array.size()-2];
    photosWidget->button_array[photosWidget->button_array.size()-2]=photosWidget->button_array[photosWidget->button_array.size()-1];
    photosWidget->button_array[photosWidget->button_array.size()-1]=tmp;

    photosWidget->lay->removeItem(photosWidget->grid_lay);
    if (photosWidget->grid_lay)
    {
        delete photosWidget->grid_lay;
    }

    photosWidget->grid_lay= new QGridLayout();
    for(int i=0;i<photosWidget->button_array.size();i++)
    {
        photosWidget->grid_lay->addWidget(photosWidget->button_array[i],i/3,i%3);
    }
    photosWidget->lay->addLayout(photosWidget->grid_lay);
    setLayout(photosWidget->grid_lay);

    connect(photosWidget->button_array[photosWidget->button_array.size()-2],&QToolButton::clicked,this,[this,filePath](){
        delete filterWidget->view;
        delete filterWidget->scene;
        filterWidget->setImage(filePath);
        stackedLayout->setCurrentIndex(2);});
}


MainWindow::~MainWindow()
{

}





