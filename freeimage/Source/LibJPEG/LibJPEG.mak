# Microsoft Developer Studio Generated NMAKE File, Based on LibJPEG.dsp
!IF "$(CFG)" == ""
CFG=LibJPEG - Win32 Debug
!MESSAGE No configuration specified. Defaulting to LibJPEG - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "LibJPEG - Win32 Release" && "$(CFG)" != "LibJPEG - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibJPEG.mak" CFG="LibJPEG - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibJPEG - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibJPEG - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "LibJPEG - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\LibJPEG.lib"


CLEAN :
	-@erase "$(INTDIR)\jcapimin.obj"
	-@erase "$(INTDIR)\jcapistd.obj"
	-@erase "$(INTDIR)\jccoefct.obj"
	-@erase "$(INTDIR)\jccolor.obj"
	-@erase "$(INTDIR)\jcdctmgr.obj"
	-@erase "$(INTDIR)\jchuff.obj"
	-@erase "$(INTDIR)\jcinit.obj"
	-@erase "$(INTDIR)\jcmainct.obj"
	-@erase "$(INTDIR)\jcmarker.obj"
	-@erase "$(INTDIR)\jcmaster.obj"
	-@erase "$(INTDIR)\jcomapi.obj"
	-@erase "$(INTDIR)\jcparam.obj"
	-@erase "$(INTDIR)\jcphuff.obj"
	-@erase "$(INTDIR)\jcprepct.obj"
	-@erase "$(INTDIR)\jcsample.obj"
	-@erase "$(INTDIR)\jctrans.obj"
	-@erase "$(INTDIR)\jdapimin.obj"
	-@erase "$(INTDIR)\jdapistd.obj"
	-@erase "$(INTDIR)\jdatadst.obj"
	-@erase "$(INTDIR)\jdatasrc.obj"
	-@erase "$(INTDIR)\jdcoefct.obj"
	-@erase "$(INTDIR)\jdcolor.obj"
	-@erase "$(INTDIR)\jddctmgr.obj"
	-@erase "$(INTDIR)\jdhuff.obj"
	-@erase "$(INTDIR)\jdinput.obj"
	-@erase "$(INTDIR)\jdmainct.obj"
	-@erase "$(INTDIR)\jdmarker.obj"
	-@erase "$(INTDIR)\jdmaster.obj"
	-@erase "$(INTDIR)\jdmerge.obj"
	-@erase "$(INTDIR)\jdphuff.obj"
	-@erase "$(INTDIR)\jdpostct.obj"
	-@erase "$(INTDIR)\jdsample.obj"
	-@erase "$(INTDIR)\jdtrans.obj"
	-@erase "$(INTDIR)\jerror.obj"
	-@erase "$(INTDIR)\jfdctflt.obj"
	-@erase "$(INTDIR)\jfdctfst.obj"
	-@erase "$(INTDIR)\jfdctint.obj"
	-@erase "$(INTDIR)\jidctflt.obj"
	-@erase "$(INTDIR)\jidctfst.obj"
	-@erase "$(INTDIR)\jidctint.obj"
	-@erase "$(INTDIR)\jidctred.obj"
	-@erase "$(INTDIR)\jmemmgr.obj"
	-@erase "$(INTDIR)\jmemnobs.obj"
	-@erase "$(INTDIR)\jquant1.obj"
	-@erase "$(INTDIR)\jquant2.obj"
	-@erase "$(INTDIR)\jutils.obj"
	-@erase "$(INTDIR)\transupp.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\LibJPEG.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O1 /I "..\zlib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Fp"$(INTDIR)\LibJPEG.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LibJPEG.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\LibJPEG.lib" 
LIB32_OBJS= \
	"$(INTDIR)\jcapimin.obj" \
	"$(INTDIR)\jcapistd.obj" \
	"$(INTDIR)\jccoefct.obj" \
	"$(INTDIR)\jccolor.obj" \
	"$(INTDIR)\jcdctmgr.obj" \
	"$(INTDIR)\jchuff.obj" \
	"$(INTDIR)\jcinit.obj" \
	"$(INTDIR)\jcmainct.obj" \
	"$(INTDIR)\jcmarker.obj" \
	"$(INTDIR)\jcmaster.obj" \
	"$(INTDIR)\jcomapi.obj" \
	"$(INTDIR)\jcparam.obj" \
	"$(INTDIR)\jcphuff.obj" \
	"$(INTDIR)\jcprepct.obj" \
	"$(INTDIR)\jcsample.obj" \
	"$(INTDIR)\jctrans.obj" \
	"$(INTDIR)\jdapimin.obj" \
	"$(INTDIR)\jdapistd.obj" \
	"$(INTDIR)\jdatadst.obj" \
	"$(INTDIR)\jdatasrc.obj" \
	"$(INTDIR)\jdcoefct.obj" \
	"$(INTDIR)\jdcolor.obj" \
	"$(INTDIR)\jddctmgr.obj" \
	"$(INTDIR)\jdhuff.obj" \
	"$(INTDIR)\jdinput.obj" \
	"$(INTDIR)\jdmainct.obj" \
	"$(INTDIR)\jdmarker.obj" \
	"$(INTDIR)\jdmaster.obj" \
	"$(INTDIR)\jdmerge.obj" \
	"$(INTDIR)\jdphuff.obj" \
	"$(INTDIR)\jdpostct.obj" \
	"$(INTDIR)\jdsample.obj" \
	"$(INTDIR)\jdtrans.obj" \
	"$(INTDIR)\jerror.obj" \
	"$(INTDIR)\jfdctflt.obj" \
	"$(INTDIR)\jfdctfst.obj" \
	"$(INTDIR)\jfdctint.obj" \
	"$(INTDIR)\jidctflt.obj" \
	"$(INTDIR)\jidctfst.obj" \
	"$(INTDIR)\jidctint.obj" \
	"$(INTDIR)\jidctred.obj" \
	"$(INTDIR)\jmemmgr.obj" \
	"$(INTDIR)\jmemnobs.obj" \
	"$(INTDIR)\jquant1.obj" \
	"$(INTDIR)\jquant2.obj" \
	"$(INTDIR)\jutils.obj" \
	"$(INTDIR)\transupp.obj"

"$(OUTDIR)\LibJPEG.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "LibJPEG - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\LibJPEG.lib"


CLEAN :
	-@erase "$(INTDIR)\jcapimin.obj"
	-@erase "$(INTDIR)\jcapistd.obj"
	-@erase "$(INTDIR)\jccoefct.obj"
	-@erase "$(INTDIR)\jccolor.obj"
	-@erase "$(INTDIR)\jcdctmgr.obj"
	-@erase "$(INTDIR)\jchuff.obj"
	-@erase "$(INTDIR)\jcinit.obj"
	-@erase "$(INTDIR)\jcmainct.obj"
	-@erase "$(INTDIR)\jcmarker.obj"
	-@erase "$(INTDIR)\jcmaster.obj"
	-@erase "$(INTDIR)\jcomapi.obj"
	-@erase "$(INTDIR)\jcparam.obj"
	-@erase "$(INTDIR)\jcphuff.obj"
	-@erase "$(INTDIR)\jcprepct.obj"
	-@erase "$(INTDIR)\jcsample.obj"
	-@erase "$(INTDIR)\jctrans.obj"
	-@erase "$(INTDIR)\jdapimin.obj"
	-@erase "$(INTDIR)\jdapistd.obj"
	-@erase "$(INTDIR)\jdatadst.obj"
	-@erase "$(INTDIR)\jdatasrc.obj"
	-@erase "$(INTDIR)\jdcoefct.obj"
	-@erase "$(INTDIR)\jdcolor.obj"
	-@erase "$(INTDIR)\jddctmgr.obj"
	-@erase "$(INTDIR)\jdhuff.obj"
	-@erase "$(INTDIR)\jdinput.obj"
	-@erase "$(INTDIR)\jdmainct.obj"
	-@erase "$(INTDIR)\jdmarker.obj"
	-@erase "$(INTDIR)\jdmaster.obj"
	-@erase "$(INTDIR)\jdmerge.obj"
	-@erase "$(INTDIR)\jdphuff.obj"
	-@erase "$(INTDIR)\jdpostct.obj"
	-@erase "$(INTDIR)\jdsample.obj"
	-@erase "$(INTDIR)\jdtrans.obj"
	-@erase "$(INTDIR)\jerror.obj"
	-@erase "$(INTDIR)\jfdctflt.obj"
	-@erase "$(INTDIR)\jfdctfst.obj"
	-@erase "$(INTDIR)\jfdctint.obj"
	-@erase "$(INTDIR)\jidctflt.obj"
	-@erase "$(INTDIR)\jidctfst.obj"
	-@erase "$(INTDIR)\jidctint.obj"
	-@erase "$(INTDIR)\jidctred.obj"
	-@erase "$(INTDIR)\jmemmgr.obj"
	-@erase "$(INTDIR)\jmemnobs.obj"
	-@erase "$(INTDIR)\jquant1.obj"
	-@erase "$(INTDIR)\jquant2.obj"
	-@erase "$(INTDIR)\jutils.obj"
	-@erase "$(INTDIR)\transupp.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\LibJPEG.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Fp"$(INTDIR)\LibJPEG.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LibJPEG.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\LibJPEG.lib" 
LIB32_OBJS= \
	"$(INTDIR)\jcapimin.obj" \
	"$(INTDIR)\jcapistd.obj" \
	"$(INTDIR)\jccoefct.obj" \
	"$(INTDIR)\jccolor.obj" \
	"$(INTDIR)\jcdctmgr.obj" \
	"$(INTDIR)\jchuff.obj" \
	"$(INTDIR)\jcinit.obj" \
	"$(INTDIR)\jcmainct.obj" \
	"$(INTDIR)\jcmarker.obj" \
	"$(INTDIR)\jcmaster.obj" \
	"$(INTDIR)\jcomapi.obj" \
	"$(INTDIR)\jcparam.obj" \
	"$(INTDIR)\jcphuff.obj" \
	"$(INTDIR)\jcprepct.obj" \
	"$(INTDIR)\jcsample.obj" \
	"$(INTDIR)\jctrans.obj" \
	"$(INTDIR)\jdapimin.obj" \
	"$(INTDIR)\jdapistd.obj" \
	"$(INTDIR)\jdatadst.obj" \
	"$(INTDIR)\jdatasrc.obj" \
	"$(INTDIR)\jdcoefct.obj" \
	"$(INTDIR)\jdcolor.obj" \
	"$(INTDIR)\jddctmgr.obj" \
	"$(INTDIR)\jdhuff.obj" \
	"$(INTDIR)\jdinput.obj" \
	"$(INTDIR)\jdmainct.obj" \
	"$(INTDIR)\jdmarker.obj" \
	"$(INTDIR)\jdmaster.obj" \
	"$(INTDIR)\jdmerge.obj" \
	"$(INTDIR)\jdphuff.obj" \
	"$(INTDIR)\jdpostct.obj" \
	"$(INTDIR)\jdsample.obj" \
	"$(INTDIR)\jdtrans.obj" \
	"$(INTDIR)\jerror.obj" \
	"$(INTDIR)\jfdctflt.obj" \
	"$(INTDIR)\jfdctfst.obj" \
	"$(INTDIR)\jfdctint.obj" \
	"$(INTDIR)\jidctflt.obj" \
	"$(INTDIR)\jidctfst.obj" \
	"$(INTDIR)\jidctint.obj" \
	"$(INTDIR)\jidctred.obj" \
	"$(INTDIR)\jmemmgr.obj" \
	"$(INTDIR)\jmemnobs.obj" \
	"$(INTDIR)\jquant1.obj" \
	"$(INTDIR)\jquant2.obj" \
	"$(INTDIR)\jutils.obj" \
	"$(INTDIR)\transupp.obj"

"$(OUTDIR)\LibJPEG.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("LibJPEG.dep")
!INCLUDE "LibJPEG.dep"
!ELSE 
!MESSAGE Warning: cannot find "LibJPEG.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "LibJPEG - Win32 Release" || "$(CFG)" == "LibJPEG - Win32 Debug"
SOURCE=.\jcapimin.c

"$(INTDIR)\jcapimin.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcapistd.c

"$(INTDIR)\jcapistd.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jccoefct.c

"$(INTDIR)\jccoefct.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jccolor.c

"$(INTDIR)\jccolor.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcdctmgr.c

"$(INTDIR)\jcdctmgr.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jchuff.c

"$(INTDIR)\jchuff.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcinit.c

"$(INTDIR)\jcinit.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcmainct.c

"$(INTDIR)\jcmainct.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcmarker.c

"$(INTDIR)\jcmarker.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcmaster.c

"$(INTDIR)\jcmaster.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcomapi.c

"$(INTDIR)\jcomapi.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcparam.c

"$(INTDIR)\jcparam.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcphuff.c

"$(INTDIR)\jcphuff.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcprepct.c

"$(INTDIR)\jcprepct.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jcsample.c

"$(INTDIR)\jcsample.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jctrans.c

"$(INTDIR)\jctrans.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdapimin.c

"$(INTDIR)\jdapimin.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdapistd.c

"$(INTDIR)\jdapistd.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdatadst.c

"$(INTDIR)\jdatadst.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdatasrc.c

"$(INTDIR)\jdatasrc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdcoefct.c

"$(INTDIR)\jdcoefct.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdcolor.c

"$(INTDIR)\jdcolor.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jddctmgr.c

"$(INTDIR)\jddctmgr.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdhuff.c

"$(INTDIR)\jdhuff.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdinput.c

"$(INTDIR)\jdinput.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdmainct.c

"$(INTDIR)\jdmainct.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdmarker.c

"$(INTDIR)\jdmarker.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdmaster.c

"$(INTDIR)\jdmaster.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdmerge.c

"$(INTDIR)\jdmerge.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdphuff.c

"$(INTDIR)\jdphuff.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdpostct.c

"$(INTDIR)\jdpostct.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdsample.c

"$(INTDIR)\jdsample.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jdtrans.c

"$(INTDIR)\jdtrans.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jerror.c

"$(INTDIR)\jerror.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jfdctflt.c

"$(INTDIR)\jfdctflt.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jfdctfst.c

"$(INTDIR)\jfdctfst.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jfdctint.c

"$(INTDIR)\jfdctint.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jidctflt.c

"$(INTDIR)\jidctflt.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jidctfst.c

"$(INTDIR)\jidctfst.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jidctint.c

"$(INTDIR)\jidctint.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jidctred.c

"$(INTDIR)\jidctred.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jmemmgr.c

"$(INTDIR)\jmemmgr.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jmemnobs.c

"$(INTDIR)\jmemnobs.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jquant1.c

"$(INTDIR)\jquant1.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jquant2.c

"$(INTDIR)\jquant2.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jutils.c

"$(INTDIR)\jutils.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\transupp.c

"$(INTDIR)\transupp.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

