# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aczi/test/hardgame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aczi/test/hardgame/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include src/CMakeFiles/template_lib_two.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/template_lib_two.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/template_lib_two.dir/flags.make

src/CMakeFiles/template_lib_two.dir/TestClass2.cpp.o: src/CMakeFiles/template_lib_two.dir/flags.make
src/CMakeFiles/template_lib_two.dir/TestClass2.cpp.o: ../src/TestClass2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aczi/test/hardgame/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/template_lib_two.dir/TestClass2.cpp.o"
	cd /home/aczi/test/hardgame/cmake-build-debug-wsl/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/template_lib_two.dir/TestClass2.cpp.o -c /home/aczi/test/hardgame/src/TestClass2.cpp

src/CMakeFiles/template_lib_two.dir/TestClass2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_lib_two.dir/TestClass2.cpp.i"
	cd /home/aczi/test/hardgame/cmake-build-debug-wsl/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aczi/test/hardgame/src/TestClass2.cpp > CMakeFiles/template_lib_two.dir/TestClass2.cpp.i

src/CMakeFiles/template_lib_two.dir/TestClass2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_lib_two.dir/TestClass2.cpp.s"
	cd /home/aczi/test/hardgame/cmake-build-debug-wsl/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aczi/test/hardgame/src/TestClass2.cpp -o CMakeFiles/template_lib_two.dir/TestClass2.cpp.s

# Object files for target template_lib_two
template_lib_two_OBJECTS = \
"CMakeFiles/template_lib_two.dir/TestClass2.cpp.o"

# External object files for target template_lib_two
template_lib_two_EXTERNAL_OBJECTS =

lib/libtemplate_lib_two.a: src/CMakeFiles/template_lib_two.dir/TestClass2.cpp.o
lib/libtemplate_lib_two.a: src/CMakeFiles/template_lib_two.dir/build.make
lib/libtemplate_lib_two.a: src/CMakeFiles/template_lib_two.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aczi/test/hardgame/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/libtemplate_lib_two.a"
	cd /home/aczi/test/hardgame/cmake-build-debug-wsl/src && $(CMAKE_COMMAND) -P CMakeFiles/template_lib_two.dir/cmake_clean_target.cmake
	cd /home/aczi/test/hardgame/cmake-build-debug-wsl/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template_lib_two.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/template_lib_two.dir/build: lib/libtemplate_lib_two.a

.PHONY : src/CMakeFiles/template_lib_two.dir/build

src/CMakeFiles/template_lib_two.dir/clean:
	cd /home/aczi/test/hardgame/cmake-build-debug-wsl/src && $(CMAKE_COMMAND) -P CMakeFiles/template_lib_two.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/template_lib_two.dir/clean

src/CMakeFiles/template_lib_two.dir/depend:
	cd /home/aczi/test/hardgame/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aczi/test/hardgame /home/aczi/test/hardgame/src /home/aczi/test/hardgame/cmake-build-debug-wsl /home/aczi/test/hardgame/cmake-build-debug-wsl/src /home/aczi/test/hardgame/cmake-build-debug-wsl/src/CMakeFiles/template_lib_two.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/template_lib_two.dir/depend

