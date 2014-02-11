#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Application.o \
	${OBJECTDIR}/src/Audio.o \
	${OBJECTDIR}/src/Global.o \
	${OBJECTDIR}/src/Image.o \
	${OBJECTDIR}/src/Main.o \
	${OBJECTDIR}/src/Menu.o \
	${OBJECTDIR}/src/Settings.o \
	${OBJECTDIR}/src/Text.o \
	${OBJECTDIR}/src/UI_Button.o \
	${OBJECTDIR}/src/UI_Checkbox.o \
	${OBJECTDIR}/src/UI_TextLabel.o \
	${OBJECTDIR}/src/View.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../../../MinGW/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Application.o: src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Application.o src/Application.cpp

${OBJECTDIR}/src/Audio.o: src/Audio.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Audio.o src/Audio.cpp

${OBJECTDIR}/src/Global.o: src/Global.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Global.o src/Global.cpp

${OBJECTDIR}/src/Image.o: src/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Image.o src/Image.cpp

${OBJECTDIR}/src/Main.o: src/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Main.o src/Main.cpp

${OBJECTDIR}/src/Menu.o: src/Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Menu.o src/Menu.cpp

${OBJECTDIR}/src/Settings.o: src/Settings.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Settings.o src/Settings.cpp

${OBJECTDIR}/src/Text.o: src/Text.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Text.o src/Text.cpp

${OBJECTDIR}/src/UI_Button.o: src/UI_Button.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_Button.o src/UI_Button.cpp

${OBJECTDIR}/src/UI_Checkbox.o: src/UI_Checkbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_Checkbox.o src/UI_Checkbox.cpp

${OBJECTDIR}/src/UI_TextLabel.o: src/UI_TextLabel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_TextLabel.o src/UI_TextLabel.cpp

${OBJECTDIR}/src/View.o: src/View.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/View.o src/View.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
