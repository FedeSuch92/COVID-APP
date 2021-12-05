##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOC20211
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211
ProjectPath            :=C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211
IntermediateDirectory  :=./bin/Debug
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
OutputFile             :=./bin/$(ProjectName)d
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOC20211.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)test/include $(IncludeSwitch)UOCContacts/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UOCContactsd 
ArLibs                 :=  "libUOCContactsd.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix) $(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d ".build-debug\UOCContacts" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

".build-debug\UOCContacts":
	@$(MakeDirCommand) ".build-debug"
	@echo stam > ".build-debug\UOCContacts"




MakeIntermediateDirs:
	@$(MakeDirCommand) "./bin/Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./bin/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix): test/src/test_suite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_suite.c$(DependSuffix) -MM test/src/test_suite.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/test/src/test_suite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_suite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_suite.c$(PreprocessSuffix): test/src/test_suite.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_suite.c$(PreprocessSuffix) test/src/test_suite.c

$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix): test/src/test_pr1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix) -MM test/src/test_pr1.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/test/src/test_pr1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix): test/src/test_pr1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix) test/src/test_pr1.c

$(IntermediateDirectory)/test_src_test.c$(ObjectSuffix): test/src/test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test.c$(DependSuffix) -MM test/src/test.c
	$(CC) $(SourceSwitch) "C:/Users/fosp/MyPrivateDocuments/FEDE_SUCH_ESPARZA_PERSONAL/Practicas_Programacion/PR1/UOC20211/UOC20211/test/src/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test.c$(PreprocessSuffix): test/src/test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test.c$(PreprocessSuffix) test/src/test.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./bin/Debug/


