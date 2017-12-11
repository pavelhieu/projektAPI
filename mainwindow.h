#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void downloadFinish(QNetworkReply *odpoved);

    void on_pushButtonOK_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager manager;

};

#endif // MAINWINDOW_H
