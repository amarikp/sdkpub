# Makefile for Intel Proton Compiler 5.0

CXX = icl
LINK = link

!ifdef debug

SUFFIX = d
DR = _Dbg

!else

SUFFIX =
DR = _Rls

!endif    

OUTDLL = ..\..\bin\cvaux$(SUFFIX).dll
OUTLIB = ..\..\lib\cvaux$(SUFFIX).lib
OBJS = ..\..\_temp\cvaux$(DR)\correspond.obj ..\..\_temp\cvaux$(DR)\cvaux.obj \
..\..\_temp\cvaux$(DR)\cvBilateralFiltering.obj \
..\..\_temp\cvaux$(DR)\cvcalibfilter.obj ..\..\_temp\cvaux$(DR)\cvclique.obj \
..\..\_temp\cvaux$(DR)\cvcontourex.obj ..\..\_temp\cvaux$(DR)\cvepilines.obj \
..\..\_temp\cvaux$(DR)\cvgraphex.obj ..\..\_temp\cvaux$(DR)\cvhmm1d.obj \
..\..\_temp\cvaux$(DR)\cvsubdiv2.obj ..\..\_temp\cvaux$(DR)\cvtexture.obj \
..\..\_temp\cvaux$(DR)\cvvideo.obj ..\..\_temp\cvaux$(DR)\decomppoly.obj \
..\..\_temp\cvaux$(DR)\ExtendedEdges.obj ..\..\_temp\cvaux$(DR)\precomp.obj 


INC = ../src/_cvaux.h ../include/cvaux.h 

CXXFLAGS2 = /I"../../cv/include" /I"../include" /I"../src" /I"../../cv/src"  /nologo /GX /GB /W4 /I "$(VCHOME)/include"  "/Qwd171,424,981" /Qxi /Qaxi /c /Fo
LINKFLAGS2 = /libpath:..\..\lib /nologo /subsystem:windows /dll /pdb:none /machine:I386 /out:$(OUTDLL) /implib:$(OUTLIB) /nodefaultlib:libm /nodefaultlib:libirc /libpath:"$(VCHOME)/lib"  

!ifdef debug

CXXFLAGS = /D"CVAUX_DLL" /D"WIN32" /D"_WINDOWS" /D"_DEBUG"  /Gm /Zi /Od /FD /GZ $(CXXFLAGS2)
LIBS = cvd.lib kernel32.lib user32.lib gdi32.lib 
LINKFLAGS = $(LINKFLAGS2) /debug 

!else

CXXFLAGS = /D"NDEBUG" /D"CVAUX_DLL" /D"WIN32" /D"_WINDOWS"  /O2 /Ob2 $(CXXFLAGS2)
LIBS = cv.lib kernel32.lib user32.lib gdi32.lib 
LINKFLAGS = $(LINKFLAGS2)  

!endif


$(OUTDLL): $(OBJS)
	-mkdir ..\..\bin 2>nul
	-mkdir ..\..\lib 2>nul
	$(LINK)  $(LINKFLAGS) $** $(LIBS) 
	

all: $(OUTDLL)

..\..\_temp\cvaux$(DR)\correspond.obj: ..\src\correspond.cpp $(INC)
	@-mkdir ..\..\_temp\cvaux$(DR) 2>nul
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\correspond.obj ..\src\correspond.cpp
..\..\_temp\cvaux$(DR)\cvaux.obj: ..\src\cvaux.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvaux.obj ..\src\cvaux.cpp
..\..\_temp\cvaux$(DR)\cvBilateralFiltering.obj: ..\src\cvBilateralFiltering.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvBilateralFiltering.obj ..\src\cvBilateralFiltering.cpp
..\..\_temp\cvaux$(DR)\cvcalibfilter.obj: ..\src\cvcalibfilter.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvcalibfilter.obj ..\src\cvcalibfilter.cpp
..\..\_temp\cvaux$(DR)\cvclique.obj: ..\src\cvclique.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvclique.obj ..\src\cvclique.cpp
..\..\_temp\cvaux$(DR)\cvcontourex.obj: ..\src\cvcontourex.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvcontourex.obj ..\src\cvcontourex.cpp
..\..\_temp\cvaux$(DR)\cvepilines.obj: ..\src\cvepilines.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvepilines.obj ..\src\cvepilines.cpp
..\..\_temp\cvaux$(DR)\cvgraphex.obj: ..\src\cvgraphex.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvgraphex.obj ..\src\cvgraphex.cpp
..\..\_temp\cvaux$(DR)\cvhmm1d.obj: ..\src\cvhmm1d.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvhmm1d.obj ..\src\cvhmm1d.cpp
..\..\_temp\cvaux$(DR)\cvsubdiv2.obj: ..\src\cvsubdiv2.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvsubdiv2.obj ..\src\cvsubdiv2.cpp
..\..\_temp\cvaux$(DR)\cvtexture.obj: ..\src\cvtexture.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvtexture.obj ..\src\cvtexture.cpp
..\..\_temp\cvaux$(DR)\cvvideo.obj: ..\src\cvvideo.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\cvvideo.obj ..\src\cvvideo.cpp
..\..\_temp\cvaux$(DR)\decomppoly.obj: ..\src\decomppoly.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\decomppoly.obj ..\src\decomppoly.cpp
..\..\_temp\cvaux$(DR)\ExtendedEdges.obj: ..\src\ExtendedEdges.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\ExtendedEdges.obj ..\src\ExtendedEdges.cpp
..\..\_temp\cvaux$(DR)\precomp.obj: ..\src\precomp.cpp $(INC)
	-$(CXX) $(CXXFLAGS)..\..\_temp\cvaux$(DR)\precomp.obj ..\src\precomp.cpp
