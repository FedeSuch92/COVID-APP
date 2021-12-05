##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCContacts
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211
ProjectPath            :=C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/UOCContacts
IntermediateDirectory  :=../bin/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=fosp
Date                   :=13/11/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../lib/lib$(ProjectName)d.a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOCContacts.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_date.c$(ObjectSuffix) $(IntermediateDirectory)/src_contact.c$(ObjectSuffix) $(IntermediateDirectory)/src_person.c$(ObjectSuffix) $(IntermediateDirectory)/src_csv.c$(ObjectSuffix) $(IntermediateDirectory)/src_api.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList)
	@$(MakeDirCommand) "C:\Users\fosp\MyPrivateDocuments\FEDE_SUCH_ESPARZA_PERSONAL\Practicas_Programacion\PR1\UOC20211\UOC20211/.build-debug"
	@echo rebuilt > "C:\Users\fosp\MyPrivateDocuments\FEDE_SUCH_ESPARZA_PERSONAL\Practicas_Programacion\PR1\UOC20211\UOC20211/.build-debug/UOCContacts"

MakeIntermediateDirs:
	@$(MakeDirCommand) "../bin/Debug"


../bin/Debug:
	@$(MakeDirCommand) "../bin/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_date.c$(ObjectSuffix): src/date.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_date.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_date.c$(DependSuffix) -MM src/date.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/UOCContacts/src/date.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_date.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_date.c$(PreprocessSuffix): src/date.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_date.c$(PreprocessSuffix) src/date.c

$(IntermediateDirectory)/src_contact.c$(ObjectSuffix): src/contact.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_contact.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_contact.c$(DependSuffix) -MM src/contact.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/UOCContacts/src/contact.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_contact.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_contact.c$(PreprocessSuffix): src/contact.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_contact.c$(PreprocessSuffix) src/contact.c

$(IntermediateDirectory)/src_person.c$(ObjectSuffix): src/person.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_person.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_person.c$(DependSuffix) -MM src/person.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/UOCContacts/src/person.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_person.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_person.c$(PreprocessSuffix): src/person.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_person.c$(PreprocessSuffix) src/person.c

$(IntermediateDirectory)/src_csv.c$(ObjectSuffix): src/csv.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_csv.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_csv.c$(DependSuffix) -MM src/csv.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/UOCContacts/src/csv.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_csv.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_csv.c$(PreprocessSuffix): src/csv.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_csv.c$(PreprocessSuffix) src/csv.c

$(IntermediateDirectory)/src_api.c$(ObjectSuffix): src/api.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_api.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_api.c$(DependSuffix) -MM src/api.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/UOCContacts/src/api.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_api.c$(PreprocessSuffix): src/api.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_api.c$(PreprocessSuffix) src/api.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../bin/Debug/


