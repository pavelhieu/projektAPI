#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include "api.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&manager,SIGNAL(finished(QNetworkReply*)), SLOT(downloadFinish(QNetworkReply*)));

    ui->lineEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 102)}");
    ui->textBrowser->setStyleSheet("QTextBrowser { background: rgb(255, 255, 102)}");
    ui->pushButtonOK->setStyleSheet("QPushButton { background: rgb(255, 255, 102) }");
    ui->centralWidget->setStyleSheet("QWidget { background: rgb(255, 255, 204) }");
    ui->mainToolBar->setStyleSheet("QToolBar { background: rgb(255, 255, 204) }");
    ui->menuBar->setStyleSheet("QMenuBar { background: rgb(255, 255, 204) }");
    ui->statusBar->setStyleSheet("QStatusBar { background: rgb(255, 255, 204) }");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::downloadFinish(QNetworkReply *odpoved)
{
    if(!odpoved->error())
    {
//        QByteArray b = odpoved->readAll();
//        QJsonDocument doc = QJsonDocument::fromJson(b);
//       qDebug() << doc;
//        ui->textBrowser->setText(doc.toJson());

//        QJsonObject object = doc.object();
//        qDebug() << object;
//------------------------------------------------
        QString weather;
        QString strReply = (QString)odpoved->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(strReply.toUtf8());
        qDebug() << jsonDocument;

        QJsonObject o1 = jsonDocument.object();
        QJsonValue v1 = o1.value(QString("wind"));
        QJsonObject item1 = v1.toObject();
        QJsonValue vys1 = item1["speed"];
        qDebug() << vys1.toDouble();

        QJsonObject o2 = jsonDocument.object();
        QJsonValue v2 = o2.value(QString("main"));
        QJsonObject item2 = v2.toObject();
        QJsonValue tep = item2["temp"];
        double teplota =tep.toDouble() - (273.15);
        qDebug() << teplota;


        QJsonObject jsonObject = jsonDocument.object();
        QJsonArray weatherArraay = jsonObject["weather"].toArray();
        //        QJsonObject windArraay = jsonObject["wind"].toObject();


        foreach (const QJsonValue & value, weatherArraay) {
            QJsonObject obj = value.toObject();
            QJsonDocument docu = QJsonDocument::fromVariant(obj.toVariantMap());
            weather.append(obj["main"].toString());
        }
        ui->textBrowser->setText("Weather in " + ui->lineEdit->text()+
                                 ":\n\t\t" + weather + "\n\t\tWind: "
                                 + QString::number(vys1.toDouble())+"m/s"
                                 + "\n\t\tTemperature: " + QString::number(teplota) +"°С" );


        QFile file("library.json");
        if (!file.open(QIODevice::WriteOnly))
            return;
        file.write(ui->textBrowser->toHtml().toLatin1());
        file.close();
    }
    else
    {
        QMessageBox::warning(this,"chyba","Nenašel jsem žadné město "+ ui->lineEdit->text() + ".\n Zadejte "
                                                                                              "prosim jiný město");
        qDebug() << "chyba" << odpoved->errorString();

    }
}

void MainWindow::on_pushButtonOK_clicked()
{
    API apicko;
    QNetworkRequest request;
    QString nazev = ui->lineEdit->text();
    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Zadejte mesto","Zadejte mesto");
    }
//    qDebug() << nazev;
    request.setUrl(apicko.getUrl(nazev));
    manager.get(request);
    qDebug() << request.url();
}
