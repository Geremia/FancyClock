#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QSettings>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "preference.h"

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
    restoreGeometry(sts.value("MainGeometry").toByteArray());
    restoreState(sts.value("MainState").toByteArray());

    //restore color
    setColor();

    updateTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setColor()
{
    QSettings sts;
    int i = sts.value("Color").toInt();
    QPalette c;
    switch (i) {
    case 0:
        c.setColor(QPalette::Foreground, Qt::black);
        break;
    case 1:
        c.setColor(QPalette::Foreground, Qt::white);
        break;
    case 2:
        c.setColor(QPalette::Foreground, Qt::green);
        break;
    case 3:
        c.setColor(QPalette::Foreground, Qt::red);
        break;
    }
    ui->lcdNumber->setPalette(c);
    this->update();
}

void MainWindow::updateTime()
{
    QTime currentTime = QTime::currentTime();
    QString currentTimeText = currentTime.toString("hh:mm:ss.zzz");
    if (currentTime.second() % 3 == 0)
        currentTimeText[2] = ' ';
    else
        currentTimeText[5] = ' ';
    if (currentTime.second() % 2 == 0)
        currentTimeText[8] = ' ';
    ui->lcdNumber->display(currentTimeText);
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu;
    contextMenu.addAction("Exit",this,SLOT(close()));
    contextMenu.addAction("Preference", this, SLOT(showPreference()));
    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::showPreference()
{
    Preference *pref = new Preference(this);
    connect(pref, &Preference::accepted, this, &MainWindow::setColor);
    pref->exec();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button()
        #ifndef Q_OS_ANDROID
            == Qt::RightButton
        #endif
            )
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
#ifdef Q_OS_ANDROID
    this->mouseReleaseEvent(e);
#else
    this->move(e->globalPos()-m_mousepos);
#endif
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QSettings settings;
    settings.setValue("MainGeometry", saveGeometry());
    settings.setValue("MainState", saveState());
    e->accept();
}
