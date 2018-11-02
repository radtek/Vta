#ifndef VTAAIML_H
#define VTAAIML_H

#include <QtGui>
#include "aimlparser.h"

class VtaAiml
{
public:
    VtaAiml(const QString& aimlSet);
    QString validateInput(const QString& str);
     void  ClearAiml();
    QString  setAIMLSet(QString aimlSet);


private slots:

    void  determineWidgetsDirection(const QString& input);

private :
    QRegExp regexp;
    bool server;
    AIMLParser *parser;
    QString currentPath;
   // uint fileIndex;

};

#endif // VTAAIML_H
