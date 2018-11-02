#include "vtatask.h"

VTATask::VTATask()
{
   Tasks TaskTemp;
   TaskTemp.Task = "SearchFile";
   TaskTemp.Sentance<<"find (\\w+.*) file$";
   TaskTemp.Sentance<<"(\\w+.*) file find$";
   TaskTemp.Sentance<<"file (\\w+.*) find$";
   TaskTemp.Sentance<<"search (\\w+.*) file$";
   TaskTemp.Sentance<<"(\\w+.*) file search$";
   TaskTemp.Sentance<<"file (\\w+.*) search$";
   TaskTemp.Sentance<<"search file (\\w+.*) $";
   TaskTemp.Sentance<<"find file (\\w+.*) $";

   Tasks TaskTemp1;
   TaskTemp1.Task = "PrintSearchedFile";
   TaskTemp1.Sentance<<"(show|print) (searched|searching|search) (file|dir|Folder|directory)$";


   Tasks TaskTemp0;
   TaskTemp0.Task = "SearchFileInDrive";
   TaskTemp0.Sentance<<"search (\\w+.*) file in drive (\\w+.*)$";

   Tasks TaskTemp2;
   TaskTemp2.Task = "ShowDrives";
   TaskTemp2.Sentance<<"Show all Drive$";
   TaskTemp2.Sentance<<"Show Drives$";
   TaskTemp2.Sentance<<"print all Drive$";
   TaskTemp2.Sentance<<"print Drive$";

   Tasks TaskTemp3;
   TaskTemp2.Task = "OpenDrive";
   TaskTemp2.Sentance<<"open (\\w+.*) Drive$";
   TaskTemp2.Sentance<<"Drive (\\w+.*) open$";
   TaskTemp2.Sentance<<"open Drives (\\w+.*) $";
   TaskTemp2.Sentance<<"open (\\w+.*) Drives$";
   TaskTemp2.Sentance<<"Drives (\\w+.*) open$";
   TaskTemp2.Sentance<<"show Drives (\\w+.*) $";
   TaskTemp2.Sentance<<"sggow (\\w+.*) Drives$";
   TaskTemp2.Sentance<<"Drives (\\w+.*) show$";

   Tasks TaskTemp4;
   TaskTemp4.Task = "ShowDriveDetails";
   TaskTemp4.Sentance<<"show (\\w+.*) Drive Details$";
   TaskTemp4.Sentance<<"show Details Drive (\\w+.*)$";

   Tasks TaskTemp5;
   TaskTemp5.Task = "StartEnglishTyper";
   TaskTemp5.Sentance<<"start english writing$";
   TaskTemp5.Sentance<<"english writing start$";
   TaskTemp5.Sentance<<"open english writing$";
   TaskTemp5.Sentance<<"start english typing$";
   TaskTemp5.Sentance<<"english typing start$";
   TaskTemp5.Sentance<<"open english typing$";

   Tasks TaskTemp6;
   TaskTemp6.Task = "StartHindiTyper";
   TaskTemp6.Sentance<<"start hindi writing$";
   TaskTemp6.Sentance<<"hindi writing start$";
   TaskTemp6.Sentance<<"open hindi writing$";
   TaskTemp6.Sentance<<"start hindi typing$";
   TaskTemp6.Sentance<<"hindi typing start$";
   TaskTemp6.Sentance<<"open hindi typing$";

   Tasks TaskTemp7;
   TaskTemp7.Task = "OpenHindiDictionary";
   TaskTemp7.Sentance<<"start hindi dictionary$";
   TaskTemp7.Sentance<<"hindi dictionary start$";
   TaskTemp7.Sentance<<"open hindi dictionary$";
   TaskTemp7.Sentance<<"start hindi dictionary$";

   Tasks TaskTemp8;
   TaskTemp8.Task = "StopTyping";
   TaskTemp8.Sentance<<"stop typing$";
   TaskTemp8.Sentance<<"stop hindi typing$";
   TaskTemp8.Sentance<<"stop english typing$";

  TaskName<<TaskTemp<<TaskTemp0<<TaskTemp1<<TaskTemp2<<TaskTemp3<<TaskTemp4<<TaskTemp5<<TaskTemp6<<TaskTemp7<<TaskTemp8;

}
QStringList VTATask::GetCaptureList(int from ,int to)
{
    QStringList cl;
    if(CaptureFiles.length()>to)
    {
    for(int i =from;i<to;i++)
    {
        cl<<CaptureFiles.at(i);
    }
    }
    else
    {
        for(int i =0;i<CaptureFiles.length();i++)
        {
             cl<<CaptureFiles.at(i);
        }
    }
   return cl;
}
QStringList VTATask::GetCaptureList()
{
   return CaptureFiles;
}
QStringList VTATask::GetCaptureListSpilt(int from ,int to)
{
    QStringList cl;
   if(CaptureFiles.length()>to)
   {
    for(int i =from;i<to;i++)
    {
         QString st =CaptureFiles.at(i);
       cl<<st.split(QRegExp("\\s+"),QString::SkipEmptyParts);
    }
   }
   else
   {
      cl<<GetCaptureListSpilt();
   }
   return cl;
}
QStringList VTATask::GetCaptureListSpilt()
{

    QStringList cl;
    for(int i =0;i<CaptureFiles.length();i++)
    {
         QString st =CaptureFiles.at(i);
         cl<<st.split(QRegExp("\\s+"),QString::SkipEmptyParts);
    }
    if(cl.contains("and",Qt::CaseInsensitive))
    {
       for(int i=0;i<cl.length();i++)
       {
           if(cl.at(i) == "and" || cl.at(i) == "and")
           {
               cl.removeAt(i);
           }
       }
    }

   return cl;
}

QString VTATask::SearchTask(QString str)
{
     CaptureFiles.clear();

     for(int tn=0;tn<TaskName.length();tn++)
     {
          for(int t=0;t<TaskName.at(tn).Sentance.length();t++)
          {
               QRegularExpression re(TaskName.at(tn).Sentance.at(t),QRegularExpression::CaseInsensitiveOption);
               QRegularExpressionMatch match = re.match(str);
               if (match.hasMatch())
               {
                    int i = 1;
                       while(!match.captured(i).isEmpty())
                   {
                         CaptureFiles.operator<<(match.captured(i));
                        i++;
                   }
                    return TaskName.at(tn).Task;
               }
          }
     }
   return "";

}
