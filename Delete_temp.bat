
:: delete all temp file, for release source code and check-in to code database

@echo delete all temp file...

del /f /s /q Debug\*.idb
del /f /s /q Debug\*.sbr
del /f /s /q Debug\*.bsc
del /f /s /q Debug\*.pdb
del /f /s /q Debug\*.pch
del /f /s /q Debug\*.obj
del /f /s /q Debug\*.lib
del /f /s /q Debug\*.ilk
del /f /s /q Debug\*.exp
del /f /s /q Debug\*.res

del /f /s /q Release\*.idb
del /f /s /q Release\*.sbr
del /f /s /q Release\*.bsc
del /f /s /q Release\*.pdb
del /f /s /q Release\*.pch
del /f /s /q Release\*.obj
del /f /s /q Release\*.lib
del /f /s /q Release\*.ilk
del /f /s /q Release\*.exp
del /f /s /q Release\*.res

del /f /s /q Output\*.idb
del /f /s /q Output\*.sbr
del /f /s /q Output\*.bsc
del /f /s /q Output\*.pdb
del /f /s /q Output\*.pch
del /f /s /q Output\*.obj
del /f /s /q Output\*.lib
del /f /s /q Output\*.ilk
del /f /s /q Output\*.exp
del /f /s /q Output\*.res
del /f /s /q Output\MtkCommIODLL.log

del /f /s /q *.ncb

copy /b Output\SN_Setup.ini.bak Output\SN_Setup.ini
