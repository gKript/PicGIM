@noecho
cd ..\PicGIM_Documentation
del /S /Q html
doxygen Doxyfile_DEFINE
rem copy .\* .\html\PicGIM_05
copy .\*.jpg .\html\PicGIM_05
copy .\*.png .\html\PicGIM_05
copy .\*.gif .\html\PicGIM_05
copy .\*.css .\html\PicGIM_05
copy .\*.c .\html\PicGIM_05
echo Done!!!
C:\Programmi\CopyTo\CopyTo.exe	 .\DocumentationSynk.cp2
echo Syncronized!!!