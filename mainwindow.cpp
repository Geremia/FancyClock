#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QSettings>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | windowFlags());

    connect(this, &MainWindow::customContextMenuRequested, this, &MainWindow::showContextMenu);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1); //1 → 1 ms granularity

    QSettings sts;
    restoreGeometry(sts.value("MainGeometry"));
    restoreState(sts.value("MainState"));

    updateTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QTime currentTime = QTime::currentTime();
    QString currentTimeText = currentTime.toString("hh:mm:ss.zzz");
    if (currentTime.second() % 2 == 0)
        currentTimeText[2] = ' ';
    else
        currentTimeText[5] = ' ';
    if (currentTime.second() % 3 == 0)
        currentTimeText[8] = ' ';
    ui->lcdNumber->display(currentTimeText);
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu;
    contextMenu.addAction(QString("Exit"),this,SLOT(close()));
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
if (e->button() == Qt::RightButton)
    emit customContextMenuRequested(e->pos());
else
    QMainWindow::mouseReleaseEvent(e);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    m_mousepos = e->pos();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    this->move(e->globalPos()-m_mousepos);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QSettings settings;
    settings.setValue("MainGeometry", saveGeometry());
    settings.setValue("MainState", saveState());
    e->accept();
}
