#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint m_mousepos;
    void setColor();

private slots:
    void updateTime();
    void showContextMenu(const QPoint &pos);
    void showPreference();

protected:
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *);

};

#endif // MAINWINDOW_H
