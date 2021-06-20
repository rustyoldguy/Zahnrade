##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Zahnrade
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade
ProjectPath            :=/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade/Zahnrade
IntermediateDirectory  :=../build-$(ConfigurationName)/Zahnrade
OutDir                 :=../build-$(ConfigurationName)/Zahnrade
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Josef Wismeth 
Date                   :=03/04/21
CodeLitePath           :=/home/josef/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
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
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Zahnrade/menues.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Zahnrade/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Zahnrade/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Zahnrade"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Zahnrade"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Zahnrade/.d:
	@mkdir -p "../build-$(ConfigurationName)/Zahnrade"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Zahnrade/menues.cpp$(ObjectSuffix): menues.cpp ../build-$(ConfigurationName)/Zahnrade/menues.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade/Zahnrade/menues.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menues.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Zahnrade/menues.cpp$(DependSuffix): menues.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Zahnrade/menues.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Zahnrade/menues.cpp$(DependSuffix) -MM menues.cpp

../build-$(ConfigurationName)/Zahnrade/menues.cpp$(PreprocessSuffix): menues.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Zahnrade/menues.cpp$(PreprocessSuffix) menues.cpp

../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(ObjectSuffix): menuefrage.cpp ../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade/Zahnrade/menuefrage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(DependSuffix): menuefrage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(DependSuffix) -MM menuefrage.cpp

../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(PreprocessSuffix): menuefrage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Zahnrade/menuefrage.cpp$(PreprocessSuffix) menuefrage.cpp

../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(ObjectSuffix): cmpdouble.cpp ../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade/Zahnrade/cmpdouble.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmpdouble.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(DependSuffix): cmpdouble.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(DependSuffix) -MM cmpdouble.cpp

../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(PreprocessSuffix): cmpdouble.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Zahnrade/cmpdouble.cpp$(PreprocessSuffix) cmpdouble.cpp

../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(ObjectSuffix): bomasincostan.cpp ../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade/Zahnrade/bomasincostan.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bomasincostan.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(DependSuffix): bomasincostan.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(DependSuffix) -MM bomasincostan.cpp

../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(PreprocessSuffix): bomasincostan.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Zahnrade/bomasincostan.cpp$(PreprocessSuffix) bomasincostan.cpp

../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(ObjectSuffix): zahnrad.cpp ../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade/Zahnrade/zahnrad.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/zahnrad.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(DependSuffix): zahnrad.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(DependSuffix) -MM zahnrad.cpp

../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(PreprocessSuffix): zahnrad.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Zahnrade/zahnrad.cpp$(PreprocessSuffix) zahnrad.cpp

../build-$(ConfigurationName)/Zahnrade/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Zahnrade/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/ZAHNRAD-Versionen/Zahnrade/Zahnrade/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Zahnrade/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Zahnrade/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Zahnrade/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Zahnrade/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Zahnrade/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Zahnrade//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


