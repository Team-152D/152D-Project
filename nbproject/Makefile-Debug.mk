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
	${OBJECTDIR}/src/Ammobox.o \
	${OBJECTDIR}/src/Application.o \
	${OBJECTDIR}/src/Audio.o \
	${OBJECTDIR}/src/DetTile.o \
	${OBJECTDIR}/src/Editor.o \
	${OBJECTDIR}/src/Fixed_Switch.o \
	${OBJECTDIR}/src/Game.o \
	${OBJECTDIR}/src/Global.o \
	${OBJECTDIR}/src/Grid.o \
	${OBJECTDIR}/src/Guard.o \
	${OBJECTDIR}/src/Image.o \
	${OBJECTDIR}/src/Level.o \
	${OBJECTDIR}/src/Main.o \
	${OBJECTDIR}/src/Menu.o \
	${OBJECTDIR}/src/MobileBoxes.o \
	${OBJECTDIR}/src/Monster.o \
	${OBJECTDIR}/src/Player.o \
	${OBJECTDIR}/src/Projectile.o \
	${OBJECTDIR}/src/Settings.o \
	${OBJECTDIR}/src/Sight.o \
	${OBJECTDIR}/src/Text.o \
	${OBJECTDIR}/src/Timed_Gate.o \
	${OBJECTDIR}/src/Timer.o \
	${OBJECTDIR}/src/UI_Button.o \
	${OBJECTDIR}/src/UI_Checkbox.o \
	${OBJECTDIR}/src/UI_IPfield.o \
	${OBJECTDIR}/src/UI_TextLabel.o \
	${OBJECTDIR}/src/View.o \
	${OBJECTDIR}/src/chat.o \
	${OBJECTDIR}/src/command.o \
	${OBJECTDIR}/src/net.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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
LDLIBSOPTIONS=-L../../../../../MinGW/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lws2_32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Ammobox.o: src/Ammobox.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Ammobox.o src/Ammobox.cpp

${OBJECTDIR}/src/Application.o: src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Application.o src/Application.cpp

${OBJECTDIR}/src/Audio.o: src/Audio.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Audio.o src/Audio.cpp

${OBJECTDIR}/src/DetTile.o: src/DetTile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DetTile.o src/DetTile.cpp

${OBJECTDIR}/src/Editor.o: src/Editor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Editor.o src/Editor.cpp

${OBJECTDIR}/src/Fixed_Switch.o: src/Fixed_Switch.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Fixed_Switch.o src/Fixed_Switch.cpp

${OBJECTDIR}/src/Game.o: src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Game.o src/Game.cpp

${OBJECTDIR}/src/Global.o: src/Global.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Global.o src/Global.cpp

${OBJECTDIR}/src/Grid.o: src/Grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Grid.o src/Grid.cpp

${OBJECTDIR}/src/Guard.o: src/Guard.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Guard.o src/Guard.cpp

${OBJECTDIR}/src/Image.o: src/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Image.o src/Image.cpp

${OBJECTDIR}/src/Level.o: src/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Level.o src/Level.cpp

${OBJECTDIR}/src/Main.o: src/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Main.o src/Main.cpp

${OBJECTDIR}/src/Menu.o: src/Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Menu.o src/Menu.cpp

${OBJECTDIR}/src/MobileBoxes.o: src/MobileBoxes.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MobileBoxes.o src/MobileBoxes.cpp

${OBJECTDIR}/src/Monster.o: src/Monster.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Monster.o src/Monster.cpp

${OBJECTDIR}/src/Player.o: src/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Player.o src/Player.cpp

${OBJECTDIR}/src/Projectile.o: src/Projectile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Projectile.o src/Projectile.cpp

${OBJECTDIR}/src/Settings.o: src/Settings.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Settings.o src/Settings.cpp

${OBJECTDIR}/src/Sight.o: src/Sight.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Sight.o src/Sight.cpp

${OBJECTDIR}/src/Text.o: src/Text.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Text.o src/Text.cpp

${OBJECTDIR}/src/Timed_Gate.o: src/Timed_Gate.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Timed_Gate.o src/Timed_Gate.cpp

${OBJECTDIR}/src/Timer.o: src/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Timer.o src/Timer.cpp

${OBJECTDIR}/src/UI_Button.o: src/UI_Button.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_Button.o src/UI_Button.cpp

${OBJECTDIR}/src/UI_Checkbox.o: src/UI_Checkbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_Checkbox.o src/UI_Checkbox.cpp

${OBJECTDIR}/src/UI_IPfield.o: src/UI_IPfield.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_IPfield.o src/UI_IPfield.cpp

${OBJECTDIR}/src/UI_TextLabel.o: src/UI_TextLabel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_TextLabel.o src/UI_TextLabel.cpp

${OBJECTDIR}/src/View.o: src/View.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/View.o src/View.cpp

${OBJECTDIR}/src/chat.o: src/chat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/chat.o src/chat.cpp

${OBJECTDIR}/src/command.o: src/command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/command.o src/command.cpp

${OBJECTDIR}/src/net.o: src/net.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/net.o src/net.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/src/tests/newsimpletest1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/src/tests/newsimpletest1.o: src/tests/newsimpletest1.cpp 
	${MKDIR} -p ${TESTDIR}/src/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I../../../../../MinGW/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/src/tests/newsimpletest1.o src/tests/newsimpletest1.cpp


${OBJECTDIR}/src/Ammobox_nomain.o: ${OBJECTDIR}/src/Ammobox.o src/Ammobox.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Ammobox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Ammobox_nomain.o src/Ammobox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Ammobox.o ${OBJECTDIR}/src/Ammobox_nomain.o;\
	fi

${OBJECTDIR}/src/Application_nomain.o: ${OBJECTDIR}/src/Application.o src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Application.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Application_nomain.o src/Application.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Application.o ${OBJECTDIR}/src/Application_nomain.o;\
	fi

${OBJECTDIR}/src/Audio_nomain.o: ${OBJECTDIR}/src/Audio.o src/Audio.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Audio.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Audio_nomain.o src/Audio.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Audio.o ${OBJECTDIR}/src/Audio_nomain.o;\
	fi

${OBJECTDIR}/src/DetTile_nomain.o: ${OBJECTDIR}/src/DetTile.o src/DetTile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/DetTile.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DetTile_nomain.o src/DetTile.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/DetTile.o ${OBJECTDIR}/src/DetTile_nomain.o;\
	fi

${OBJECTDIR}/src/Editor_nomain.o: ${OBJECTDIR}/src/Editor.o src/Editor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Editor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Editor_nomain.o src/Editor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Editor.o ${OBJECTDIR}/src/Editor_nomain.o;\
	fi

${OBJECTDIR}/src/Fixed_Switch_nomain.o: ${OBJECTDIR}/src/Fixed_Switch.o src/Fixed_Switch.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Fixed_Switch.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Fixed_Switch_nomain.o src/Fixed_Switch.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Fixed_Switch.o ${OBJECTDIR}/src/Fixed_Switch_nomain.o;\
	fi

${OBJECTDIR}/src/Game_nomain.o: ${OBJECTDIR}/src/Game.o src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Game.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Game_nomain.o src/Game.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Game.o ${OBJECTDIR}/src/Game_nomain.o;\
	fi

${OBJECTDIR}/src/Global_nomain.o: ${OBJECTDIR}/src/Global.o src/Global.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Global.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Global_nomain.o src/Global.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Global.o ${OBJECTDIR}/src/Global_nomain.o;\
	fi

${OBJECTDIR}/src/Grid_nomain.o: ${OBJECTDIR}/src/Grid.o src/Grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Grid.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Grid_nomain.o src/Grid.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Grid.o ${OBJECTDIR}/src/Grid_nomain.o;\
	fi

${OBJECTDIR}/src/Guard_nomain.o: ${OBJECTDIR}/src/Guard.o src/Guard.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Guard.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Guard_nomain.o src/Guard.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Guard.o ${OBJECTDIR}/src/Guard_nomain.o;\
	fi

${OBJECTDIR}/src/Image_nomain.o: ${OBJECTDIR}/src/Image.o src/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Image.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Image_nomain.o src/Image.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Image.o ${OBJECTDIR}/src/Image_nomain.o;\
	fi

${OBJECTDIR}/src/Level_nomain.o: ${OBJECTDIR}/src/Level.o src/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Level.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Level_nomain.o src/Level.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Level.o ${OBJECTDIR}/src/Level_nomain.o;\
	fi

${OBJECTDIR}/src/Main_nomain.o: ${OBJECTDIR}/src/Main.o src/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Main_nomain.o src/Main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Main.o ${OBJECTDIR}/src/Main_nomain.o;\
	fi

${OBJECTDIR}/src/Menu_nomain.o: ${OBJECTDIR}/src/Menu.o src/Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Menu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Menu_nomain.o src/Menu.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Menu.o ${OBJECTDIR}/src/Menu_nomain.o;\
	fi

${OBJECTDIR}/src/MobileBoxes_nomain.o: ${OBJECTDIR}/src/MobileBoxes.o src/MobileBoxes.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/MobileBoxes.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MobileBoxes_nomain.o src/MobileBoxes.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/MobileBoxes.o ${OBJECTDIR}/src/MobileBoxes_nomain.o;\
	fi

${OBJECTDIR}/src/Monster_nomain.o: ${OBJECTDIR}/src/Monster.o src/Monster.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Monster.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Monster_nomain.o src/Monster.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Monster.o ${OBJECTDIR}/src/Monster_nomain.o;\
	fi

${OBJECTDIR}/src/Player_nomain.o: ${OBJECTDIR}/src/Player.o src/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Player.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Player_nomain.o src/Player.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Player.o ${OBJECTDIR}/src/Player_nomain.o;\
	fi

${OBJECTDIR}/src/Projectile_nomain.o: ${OBJECTDIR}/src/Projectile.o src/Projectile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Projectile.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Projectile_nomain.o src/Projectile.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Projectile.o ${OBJECTDIR}/src/Projectile_nomain.o;\
	fi

${OBJECTDIR}/src/Settings_nomain.o: ${OBJECTDIR}/src/Settings.o src/Settings.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Settings.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Settings_nomain.o src/Settings.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Settings.o ${OBJECTDIR}/src/Settings_nomain.o;\
	fi

${OBJECTDIR}/src/Sight_nomain.o: ${OBJECTDIR}/src/Sight.o src/Sight.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Sight.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Sight_nomain.o src/Sight.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Sight.o ${OBJECTDIR}/src/Sight_nomain.o;\
	fi

${OBJECTDIR}/src/Text_nomain.o: ${OBJECTDIR}/src/Text.o src/Text.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Text.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Text_nomain.o src/Text.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Text.o ${OBJECTDIR}/src/Text_nomain.o;\
	fi

${OBJECTDIR}/src/Timed_Gate_nomain.o: ${OBJECTDIR}/src/Timed_Gate.o src/Timed_Gate.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Timed_Gate.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Timed_Gate_nomain.o src/Timed_Gate.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Timed_Gate.o ${OBJECTDIR}/src/Timed_Gate_nomain.o;\
	fi

${OBJECTDIR}/src/Timer_nomain.o: ${OBJECTDIR}/src/Timer.o src/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Timer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Timer_nomain.o src/Timer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Timer.o ${OBJECTDIR}/src/Timer_nomain.o;\
	fi

${OBJECTDIR}/src/UI_Button_nomain.o: ${OBJECTDIR}/src/UI_Button.o src/UI_Button.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/UI_Button.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_Button_nomain.o src/UI_Button.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/UI_Button.o ${OBJECTDIR}/src/UI_Button_nomain.o;\
	fi

${OBJECTDIR}/src/UI_Checkbox_nomain.o: ${OBJECTDIR}/src/UI_Checkbox.o src/UI_Checkbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/UI_Checkbox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_Checkbox_nomain.o src/UI_Checkbox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/UI_Checkbox.o ${OBJECTDIR}/src/UI_Checkbox_nomain.o;\
	fi

${OBJECTDIR}/src/UI_IPfield_nomain.o: ${OBJECTDIR}/src/UI_IPfield.o src/UI_IPfield.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/UI_IPfield.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_IPfield_nomain.o src/UI_IPfield.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/UI_IPfield.o ${OBJECTDIR}/src/UI_IPfield_nomain.o;\
	fi

${OBJECTDIR}/src/UI_TextLabel_nomain.o: ${OBJECTDIR}/src/UI_TextLabel.o src/UI_TextLabel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/UI_TextLabel.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UI_TextLabel_nomain.o src/UI_TextLabel.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/UI_TextLabel.o ${OBJECTDIR}/src/UI_TextLabel_nomain.o;\
	fi

${OBJECTDIR}/src/View_nomain.o: ${OBJECTDIR}/src/View.o src/View.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/View.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/View_nomain.o src/View.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/View.o ${OBJECTDIR}/src/View_nomain.o;\
	fi

${OBJECTDIR}/src/chat_nomain.o: ${OBJECTDIR}/src/chat.o src/chat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/chat.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/chat_nomain.o src/chat.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/chat.o ${OBJECTDIR}/src/chat_nomain.o;\
	fi

${OBJECTDIR}/src/command_nomain.o: ${OBJECTDIR}/src/command.o src/command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/command.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/command_nomain.o src/command.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/command.o ${OBJECTDIR}/src/command_nomain.o;\
	fi

${OBJECTDIR}/src/net_nomain.o: ${OBJECTDIR}/src/net.o src/net.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/net.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -w -I../../../../../MinGW/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/net_nomain.o src/net.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/net.o ${OBJECTDIR}/src/net_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/152d-project.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
