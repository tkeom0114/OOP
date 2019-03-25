# Example Makefile for ArcEngine C++ Programming with Qt on Linux

#
# The PROGRAM macro defines the name of the program or project.  It
# allows the program name to be changed by editing in only one
# location
#

PROGRAM = qt_sample

#
# The INCLUDEDIRS macro contains a list of include directories
# to pass to the compiler so it can find necessary header files.
#
# The LIBDIRS macro contains a list of library directories
# to pass to the linker so it can find necessary libraries.
#
# The LIBS macro contains a list of libraries that the the
# executable must be linked against.
#

INCLUDEDIRS = \
	-I$(ARCENGINEHOME)/include \
	-I/usr/X11R6/include \
	-I$(QTDIR)/include


LIBDIRS = \
	-L$(ARCENGINEHOME)/bin \
	-L/usr/X11R6/lib

LIBS = \
	-larcsdk -lqtctl -laoctl \
	-lqt

#
# The CXXSOURCES macro contains a list of source files.
#
# The CXXOBJECTS macro converts the CXXSOURCES macro into a list
# of object files.
#
# The CXXFLAGS macro contains a list of options to be passed to
# the compiler.  Adding "-g" to this line will cause the compiler
# to add debugging information to the executable.
#
# The CXX macro defines the C++ compiler.
#
# The LDFLAGS macro contains all of the library and library
# directory information to be passed to the linker.
#

CXXSOURCES = qt_sample.cpp
CXXOBJECTS = $(CXXSOURCES:.cpp=.o)
CXXFLAGS = -DESRI_UNIX $(INCLUDEDIRS)
CXX = g++

LDFLAGS = $(LIBDIRS) $(LIBS)

#
# Default target: the first target is the default target.
# Just type "make -f Makefile.LinuxQt" to build it.
#

all: $(PROGRAM)

#
# Link target: automatically builds its object dependencies before
# executing its link command.
#

$(PROGRAM): $(CXXOBJECTS)
	$(CXX) -o $@ $(CXXOBJECTS) $(LDFLAGS)

#
# Object targets: rules that define objects, their dependencies, and
# a list of commands for compilation.
#

qt_sample.o: qt_sample.cpp qt_sample.h
	$(CXX) $(CXXFLAGS) -c -o qt_sample.o qt_sample.cpp

#
# Clean target: "make -f Makefile.LinuxQt clean" to remove unwanted objects and executables.
#

clean:
	$(RM) -f $(CXXOBJECTS) $(PROGRAM)

#
# Run target: "make -f Makefile.LinuxQt run" to execute the application
#

run:
          ./$(PROGRAM)