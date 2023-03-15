#include "Camera.h"
#include <QHBoxLayout>

CameraWidget::CameraWidget(QWidget *parent)
    : QWidget(parent)
{
    goToPhotos_button = new QToolButton;
    goToFilter_button = new QToolButton;

    goToPhotos_button->setIcon(QIcon("Icons/add_picT.jpg"));
    goToPhotos_button->setIconSize(QSize(30, 30));
    goToPhotos_button->setAutoRaise(true);
    goToPhotos_button->setStyleSheet("QToolButton { border: none; }");

    goToFilter_button->setIcon(QIcon("Icons/camera_t.png"));
    goToFilter_button->setIconSize(QSize(30, 30));
    goToFilter_button->setAutoRaise(true);
    goToFilter_button->setStyleSheet("QToolButton { border: none; }");

    QHBoxLayout* lay=new QHBoxLayout;
    lay->addWidget(goToFilter_button);
    lay->addWidget(goToPhotos_button);
    setLayout(lay);

}



