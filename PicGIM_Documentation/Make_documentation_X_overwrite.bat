@noecho
cd ..\PicGIM_Documentation

doxygen Doxyfile_DEFINE

copy .\*.jpg	.\html\PicGIM_05
copy .\*.png	.\html\PicGIM_05
copy .\*.gif	.\html\PicGIM_05
copy .\*.css	.\html\PicGIM_05
copy .\*.c 		.\html\PicGIM_05


cd html\PicGIM_05
del doxygen.css
rename picgim.css doxygen.css
cd ..
cd ..


echo Done!!!
C:\Programmi\CopyTo\CopyTo.exe	 .\DocumentationSynk.cp2
echo Syncronized!!!
