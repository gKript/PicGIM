rem cd ..\PicGIM_Documentation
del /S /Q html
doxygen Doxyfile_DEFINE
copy .\* .\html\PicGIM_05
rem copy .\*.jpg .\html\PicGIM_05
rem copy .\*.gif .\html\PicGIM_05
rem copy .\*.css .\html\PicGIM_05
rem copy .\*.c .\html\PicGIM_05
echo done!!!

C:\Programmi\CopyTo\CopyTo.exe	 DocumentationSynk.cp2
