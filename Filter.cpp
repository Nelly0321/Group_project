#include "Filter.h"
#include <QPixmap>

FilterWidget::FilterWidget(QWidget *parent)
    : QWidget(parent)
{

    fromFilterback_button->setIcon(QIcon("Icons/home.png"));
    fromFilterback_button->setIconSize(QSize(30, 30));
    fromFilterback_button->setAutoRaise(true);
    fromFilterback_button->setStyleSheet("QToolButton { border: none; }");

    zoomIn->setIcon(QIcon("Icons/zoomIn.png"));
    zoomIn->setIconSize(QSize(30, 30));
    zoomIn->setAutoRaise(true);
    zoomIn->setStyleSheet("QToolButton { border: none; }");

    zoomOut->setIcon(QIcon("Icons/zoomOut.jpg"));
    zoomOut->setIconSize(QSize(30, 30));
    zoomOut->setAutoRaise(true);
    zoomOut->setStyleSheet("QToolButton { border: none; }");

    rotate_left->setIcon(QIcon("Icons/rotateLeft.png"));
    rotate_left->setIconSize(QSize(30, 30));
    rotate_left->setAutoRaise(true);
    rotate_left->setStyleSheet("QToolButton { border: none; }");

    rotate_right->setIcon(QIcon("Icons/rotateRight.png"));
    rotate_right->setIconSize(QSize(30, 30));
    rotate_right->setAutoRaise(true);
    rotate_right->setStyleSheet("QToolButton { border: none; }");

    crop->setIcon(QIcon("Icons/crop.jpg"));
    crop->setIconSize(QSize(30, 30));
    crop->setAutoRaise(true);
    crop->setStyleSheet("QToolButton { border: none; }");

    paint->setIcon(QIcon("Icons/paint.jpg"));
    paint->setIconSize(QSize(30, 30));
    paint->setAutoRaise(true);
    paint->setStyleSheet("QToolButton { border: none; }");

    filter1->setIcon(QIcon("Icons/yellow_eyes.jpg"));
    filter1->setIconSize(QSize(80, 80));
    filter1->setAutoRaise(true);
    filter1->setStyleSheet("QToolButton { border: none; }");

    filter2->setIcon(QIcon("Icons/black_and_white.jpg"));
    filter2->setIconSize(QSize(80, 80));
    filter2->setAutoRaise(true);
    filter2->setStyleSheet("QToolButton { border: none; }");

    filter3->setIcon(QIcon("Icons/smooth_skin.jpg"));
    filter3->setIconSize(QSize(80, 80));
    filter3->setAutoRaise(true);
    filter3->setStyleSheet("QToolButton { border: none; }");

    filter4->setIcon(QIcon("Icons/vintage.jpg"));
    filter4->setIconSize(QSize(80, 80));
    filter4->setAutoRaise(true);
    filter4->setStyleSheet("QToolButton { border: none; }");

    hlay->addWidget(filter1);
    hlay->addWidget(filter2);
    hlay->addWidget(filter3);
    hlay->addWidget(filter4);

    vlay1->addWidget(view);

    vlay2->addWidget(fromFilterback_button,1);
    vlay2->addWidget(zoomIn,2);
    vlay2->addWidget(zoomOut,3);
    vlay2->addWidget(rotate_left,4);
    vlay2->addWidget(rotate_right,5);
    vlay2->addWidget(crop,6);
    vlay2->addWidget(paint,7);

    main_hlay->addLayout(vlay1);
    main_hlay->addLayout(vlay2);
    main_vlay->addLayout(main_hlay);
    main_vlay->addLayout(hlay);
    setLayout(main_vlay);

    connect(zoomIn,&QToolButton::clicked,this,&FilterWidget::slotZoomin);
    connect(zoomOut,&QToolButton::clicked,this,&FilterWidget::slotZoomout);
    connect(rotate_right,&QToolButton::clicked,this,&FilterWidget::slotRotateRight);
    connect(rotate_left,&QToolButton::clicked,this,&FilterWidget::slotRotateleft);

}
void FilterWidget::slotZoomin()
{
    view->scale(1.1,1.1);
}

void FilterWidget::slotZoomout()
{
    view->scale(1/1.1,1/1.1);
}

void FilterWidget::slotRotateleft()
{
    view->rotate(-5);
}

void FilterWidget::slotRotateRight()
{
    view->rotate(5);
}

void FilterWidget::setImage(QString path)
{
    QPixmap pixmap(path);
    QPixmap resized = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);
    scene = new QGraphicsScene;
    scene->addPixmap(resized);
    view = new QGraphicsView(scene);
    vlay1->addWidget(view);
}


