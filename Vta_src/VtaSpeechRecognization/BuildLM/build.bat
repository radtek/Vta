text2wfreq < VtaSR_En_NoM.trigram.txt | wfreq2vocab > BGram/VtaSR_En_NoM.trigram.vocab
text2idngram -vocab BGram/VtaSR_En_NoM.trigram.vocab -idngram BGram/VtaSR_En_NoM.trigram.idngram < VtaSR_En_NoM.trigram.txt
idngram2lm -vocab_type 0 -idngram BGram/VtaSR_En_NoM.trigram.idngram -vocab BGram/VtaSR_En_NoM.trigram.vocab -arpa VtaSR_En_NoM.trigram.lm
pause