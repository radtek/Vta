#include "convertor.h"

Convertor::Convertor()
{

}
QString Convertor::VtaSR_En_to_Hi(const QString& str)
{

       QString s =  str;
                 QStringList MatraT,MatraHT,MatraHLT,MatraLT,HiHaT,HiHaHT;

                 MatraT<<"n:"<<"aa"<<"ee"<<"e"<< "au"<<"ai"<<"oo"<<"o"<<"i"<<"a"<<"u";
                 MatraHT<<"ं"<<"1ा" <<"1ी" <<"1े" <<"1ौ" <<"1ै" <<"1ू" <<"1ो"<<"1ि"<<"1"<<"1ु";

                 MatraHLT<<"1ा" <<"1े"<<"1ी" <<"1ो"<<"1ौ" <<"1ै"<<"1ू" <<"1ि"<<"1ु"<<"न्:"<<"1";
                 MatraLT<<"आ"<<"ए"<<"ई"<<"ओ"<<"औ"<<"ऐ"<<"ऊ"<<"इ"<<"उ"<<"ं"<<"अ";

                 HiHaT<<"gy"<<"ksh"<<"N"<<"dh"<< "kh"<<"k"<<"gh"<<"n~"<<"n"<<"chh"<<"ch"<<"jh"<<"j"<<"th"<<"t:"<<"t"<<
                      "dh"<<"d"<<"ph"<<"p"<< "bh"<<"b"<<"m"<<"y"<<"r"<<"l"<<"v"<<"Sh"<<"sh"<<"s"<<"h"<<"g"<<"f"<<"z";
                 HiHaHT<<"ज्ञ्"<<"क्ष्"<<"ण्"<<"ढ्"<<"ख्"<<"क्"<<"घ्"<<"ङ्"<<"न्"<<"छ्"<<"च्"<<"झ्"<<"ज्"<<"थ्"<<"ट्"<< "त्"<<
                       "ध्"<<"द्"<<"फ्"<<"प्"<<"भ्"<<"ब्"<<"म्"<<"य्"<<"र्"<<"ल्"<<"व्"<<"ष्"<<"श्"<<"स्"<<"ह्"<<"ग्"<<"फ्"<<"ज्";



                 for(int fc = 0;fc<HiHaT.length();fc++)
                {
                        s  =  s.replace(HiHaT[fc],HiHaHT[fc],Qt::CaseInsensitive);
                }

                for(int ma = 0;ma<MatraT.length();ma++)
                 {
                       s  =  s.replace(MatraT[ma],MatraHT[ma],Qt::CaseInsensitive);
                 }
                       s  =  s.replace("्1", "",Qt::CaseInsensitive);

                for(int ma = 0;ma<MatraLT.length();ma++)
                 {
                     s  =  s.replace(MatraHLT[ma],MatraLT[ma],Qt::CaseInsensitive);
                 }




}
