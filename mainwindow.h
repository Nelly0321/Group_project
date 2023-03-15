#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "Camera.h"
#include "Filter.h"
#include "Photos.h"


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPhoto();

private:
    QStackedLayout *stackedLayout;
    CameraWidget *cameraWidget;
    PhotosWidget *photosWidget;
    FilterWidget *filterWidget;
};


#endif // MAINWINDOW_H



