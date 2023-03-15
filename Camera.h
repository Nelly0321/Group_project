#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>

class CameraWidget : public QWidget
{
    Q_OBJECT

public:
    CameraWidget(QWidget *parent = nullptr);

//private:
    QToolButton *goToPhotos_button;
    QToolButton *goToFilter_button;
    QLabel *label;
};



#endif // CAMERA_H

