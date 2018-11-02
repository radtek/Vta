#include "vtaaiml.h"

VtaAiml::VtaAiml(const QString& aimlSet) :
    regexp("&lt;(/*)html:(.+)&gt;")
{

     parser = new AIMLParser(false);
    regexp.setMinimal(true);

    currentPath = qApp->applicationDirPath();


     QDir dir(currentPath + "/VTAFile");
     QStringList subdirs = dir.entryList(QDir::Dirs);
     subdirs.removeAll(".");
     subdirs.removeAll("..");

      setAIMLSet(aimlSet);

}
QString VtaAiml::setAIMLSet(QString aimlSet)
{

 //   QString dirname = currentPath + "/VTAFile/" + aimlSet;
 //   QDir dir(dirname, "*.aiml");
  //  QStringList files = dir.entryList();
    /*pd = new QProgressDialog(paren);
    pd->setSizeGripEnabled(true);
    pd->setWindowTitle(QString("\"%1\" VTA AIML set Loading").arg(aimlSet));
    pd->setCancelButton(NULL);
    pd->setMinimum(0);
    pd->setMaximum(files.count()-1);
    pd->show(); */
  //  fileIndex = 0;


    if (!parser->loadAIMLSet(aimlSet))
       return "Check errors in debug.log!";
    else
        return "";

}

QString VtaAiml::validateInput(const QString& str)
{
    QString input = str;
    if (input.trimmed().isEmpty())
        return "";

     QString result;

     result =  parser->getResponse(input);

   // QString html = Qt::convertFromPlainText(result);
   // html.replace(regexp, "<\\1\\2>"),
   // qWarning(qPrintable(html));
    return result;
}
void VtaAiml::ClearAiml()
{
    parser->clear();
}
