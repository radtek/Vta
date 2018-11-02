#ifndef VTAKEY_H
#define VTAKEY_H

#include <QLineEdit>
#include <QAbstractItemModel>
#include <QtGui>
#include "getactivewindow.h"

QT_BEGIN_NAMESPACE
class QCompleter;
QT_END_NAMESPACE

class VtaKey  : public QLineEdit
{
    Q_OBJECT

public:
    VtaKey(QWidget *parent = 0);
    ~VtaKey();
   // QString PopedString;

protected:
    void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    void focusInEvent(QFocusEvent *e) Q_DECL_OVERRIDE;

private slots:
    void insertCompletion(const QString &completion);
    QAbstractItemModel *modelFromFile(const QString& fileName,const QString& NewStr);

private:
    QString textUnderCursor()  ;
    QString Vta_En_to_Hi(  QString str);
    void SetString(const QString& str);
    void setCompleter();
    QCompleter *completer() const;
    int SendText();
private:
     QCompleter *c;
     QStringList wordList;
     bool isfrist;
     QStringList EnglishList,HindiWord;
     QString Tempist;
      GetActiveWindowT  *VtaKeyThread;
};

#endif // VTAKEY_H
