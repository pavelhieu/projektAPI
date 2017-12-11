#ifndef API_H
#define API_H
#define API_KEY "6e468b98a321945daad97aea311ff9dd"
//#define SECRET "09hIJ6SpxTGcN0EDpZlnyrwITXXwJdO4yCfnOyZTQJjN4U95No"
#include <QString>
#include <QUrlQuery>



class API
{
public:
    API();


    void addQuery(QString key, QString value);

    QUrl getUrl(QString nazev);
    void clear();

private:
    QUrlQuery query;
};

#endif // API_H
