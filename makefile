!b32 = true
!alone32 = true
start = true

name = Rinerest

#sourse = $(name).cpp
sourse = source.cpp
#sourse2 = glad.c

#headers=source.h 

resource = resource
resource32 = resource-x32

flags = -m64 -static
flags32 = -m32 -static

link=  -lglfw3 -lgdi32 -lglu32 -lopengl32 -lkernel32 -luser32 -lws2_32 -lfreetype

#change = Rinegine/images.h Rinegine/font.h Rinegine/def.h Rinegine/main.h 

RineginePath = ../
include ../Rinegine/makefile

#libs = 		-Llibraries/GLFW/64/lib-mingw-w64 	-Llibraries/FreeType/64/lib 
#includes = 		-Ilibraries/GLFW/64/include	-Ilibraries/FreeType/64/include/freetype2	-Ilibraries/GLAD/include	-IRinegine	-I.	-ILibs/stb_master
#compilator = D:/mingw/mingw64/bin/


#libs32 =	-Llibraries/GLFW/32/lib-mingw-w64	-Llibraries/FreeType/32/lib 
#includes32 = 	-Ilibraries/GLFW/32/include	-Ilibraries/FreeType/32/include/freetype2	-Ilibraries/GLAD/include	-IRinegine	-I.	-ILibs/stb_master
#compilator32 = D:/mingw/mingw32/bin/

#output=files/$(name).exe


#outputoend = $(name).o 
outputFolder = files

outputo = $(name).o  $(outputoRinegine)
outputo32 = $(name)-x32.o $(outputo32Rinegine)
# objects/glad.o

output32=$(outputFolder)/$(name)-x32.exe
output=$(outputFolder)/$(name).exe

#outputo32end = $(name)-x32.o + outputo32Rinegine
#objects/glad-x32.o



run: $(output) 
	$(output)
##############################

run32: $(output32)
	$(output32)

##############################
runall: $(output32) $(output)
	$(output)

isClean := 0

clean:
	del -rf *.s *.o *.exe output\*.exe files\*.exe

#clean:
#	$(clean)
##############################32
$(output32): $(name32).o 
	$(compilator32)windres -o $(resource32).o $(resource).rc 
#	windres -i -m32 "$(resource).rc" --input-format=rc -o "$(resource)-x32.res" -O coff
	$(compilator32)g++ -o $(output32) $(flags32) $(outputo32) $(libs32) $(link) $(resource)-x32.o -mwindows
# $(resource)-x32.o -mwindows
#------------------------------
$(name32).o:$(sourse) $(headers) $(change) makefile
#ifeq ($(isClean), 0)
#	del -rf *.s *.o *.exe output\*.exe files\*.exe
#	isClean := 1
#endif
#	del -rf *.s *.o output\*.exe *.log files\*.exe
	$(compilator32)g++   $(flags32) -g0  -c $(sourse) $(includes32) $(link) -o $(name)-x32.o
#------------------------------
##############################64
$(output): $(name).o 
	$(compilator)windres -o $(resource).o   $(resource).rc 
#	windres -i "$(resource).rc" --input-format=rc -o "$(resource).res" -O coff
	$(compilator)g++ -o $(output)   $(flags)   $(outputo)   $(libs)   $(link) $(resource).o -mwindows
#$(resource).o     -mwindows
#------------------------------
$(name).o: $(sourse) $(headers) $(change) makefile
#ifeq '$(isClean)' '0'
#	del -rf *.s *.o *.exe output\*.exe files\*.exe
#	isClean := 1
#endif
#	del -rf *.s *.o output\*.exe *.log files\*.exe
#	$(compilator)g++   $(flags) -g3 -Wall -Wextra -c $(sourse) $(includes)  $(link) -o $(name).o
	$(compilator)g++   $(flags) -g0   -c $(sourse) $(includes)  $(link) -o $(name).o
#	$(compilator)g++ $(flags) -g3 -Wall -O1 -c $(sourse2) $(includes) $(link) -o $(outputo2)
##############################ALL

#	windres -o resource.o resource.rc
	

