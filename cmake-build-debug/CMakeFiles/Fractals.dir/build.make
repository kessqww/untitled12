# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anakrasnuk/CLionProjects/untitled12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anakrasnuk/CLionProjects/untitled12/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fractals.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Fractals.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Fractals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fractals.dir/flags.make

CMakeFiles/Fractals.dir/main.cpp.o: CMakeFiles/Fractals.dir/flags.make
CMakeFiles/Fractals.dir/main.cpp.o: /Users/anakrasnuk/CLionProjects/untitled12/main.cpp
CMakeFiles/Fractals.dir/main.cpp.o: CMakeFiles/Fractals.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/anakrasnuk/CLionProjects/untitled12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Fractals.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Fractals.dir/main.cpp.o -MF CMakeFiles/Fractals.dir/main.cpp.o.d -o CMakeFiles/Fractals.dir/main.cpp.o -c /Users/anakrasnuk/CLionProjects/untitled12/main.cpp

CMakeFiles/Fractals.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Fractals.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anakrasnuk/CLionProjects/untitled12/main.cpp > CMakeFiles/Fractals.dir/main.cpp.i

CMakeFiles/Fractals.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Fractals.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anakrasnuk/CLionProjects/untitled12/main.cpp -o CMakeFiles/Fractals.dir/main.cpp.s

# Object files for target Fractals
Fractals_OBJECTS = \
"CMakeFiles/Fractals.dir/main.cpp.o"

# External object files for target Fractals
Fractals_EXTERNAL_OBJECTS =

Fractals: CMakeFiles/Fractals.dir/main.cpp.o
Fractals: CMakeFiles/Fractals.dir/build.make
Fractals: /Library/Frameworks/./sfml-graphics.framework/Versions/2.6.1/sfml-graphics
Fractals: /Library/Frameworks/./sfml-audio.framework/Versions/2.6.1/sfml-audio
Fractals: /Library/Frameworks/./sfml-network.framework/Versions/2.6.1/sfml-network
Fractals: /Library/Frameworks/./sfml-window.framework/Versions/2.6.1/sfml-window
Fractals: /Library/Frameworks/./sfml-system.framework/Versions/2.6.1/sfml-system
Fractals: CMakeFiles/Fractals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/anakrasnuk/CLionProjects/untitled12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Fractals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fractals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fractals.dir/build: Fractals
.PHONY : CMakeFiles/Fractals.dir/build

CMakeFiles/Fractals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Fractals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Fractals.dir/clean

CMakeFiles/Fractals.dir/depend:
	cd /Users/anakrasnuk/CLionProjects/untitled12/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anakrasnuk/CLionProjects/untitled12 /Users/anakrasnuk/CLionProjects/untitled12 /Users/anakrasnuk/CLionProjects/untitled12/cmake-build-debug /Users/anakrasnuk/CLionProjects/untitled12/cmake-build-debug /Users/anakrasnuk/CLionProjects/untitled12/cmake-build-debug/CMakeFiles/Fractals.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Fractals.dir/depend

