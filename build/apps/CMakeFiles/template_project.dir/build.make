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
CMAKE_BINARY_DIR = /home/aczi/test/hardgame/build

# Include any dependencies generated for this target.
include apps/CMakeFiles/template_project.dir/depend.make

# Include the progress variables for this target.
include apps/CMakeFiles/template_project.dir/progress.make

# Include the compile flags for this target's objects.
include apps/CMakeFiles/template_project.dir/flags.make

apps/CMakeFiles/template_project.dir/main.cpp.o: apps/CMakeFiles/template_project.dir/flags.make
apps/CMakeFiles/template_project.dir/main.cpp.o: ../apps/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aczi/test/hardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/CMakeFiles/template_project.dir/main.cpp.o"
	cd /home/aczi/test/hardgame/build/apps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/template_project.dir/main.cpp.o -c /home/aczi/test/hardgame/apps/main.cpp

apps/CMakeFiles/template_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template_project.dir/main.cpp.i"
	cd /home/aczi/test/hardgame/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aczi/test/hardgame/apps/main.cpp > CMakeFiles/template_project.dir/main.cpp.i

apps/CMakeFiles/template_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template_project.dir/main.cpp.s"
	cd /home/aczi/test/hardgame/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aczi/test/hardgame/apps/main.cpp -o CMakeFiles/template_project.dir/main.cpp.s

# Object files for target template_project
template_project_OBJECTS = \
"CMakeFiles/template_project.dir/main.cpp.o"

# External object files for target template_project
template_project_EXTERNAL_OBJECTS =

bin/template_project: apps/CMakeFiles/template_project.dir/main.cpp.o
bin/template_project: apps/CMakeFiles/template_project.dir/build.make
bin/template_project: lib/libtemplate_lib_one.a
bin/template_project: lib/libtemplate_lib_two.a
bin/template_project: apps/CMakeFiles/template_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aczi/test/hardgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/template_project"
	cd /home/aczi/test/hardgame/build/apps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/CMakeFiles/template_project.dir/build: bin/template_project

.PHONY : apps/CMakeFiles/template_project.dir/build

apps/CMakeFiles/template_project.dir/clean:
	cd /home/aczi/test/hardgame/build/apps && $(CMAKE_COMMAND) -P CMakeFiles/template_project.dir/cmake_clean.cmake
.PHONY : apps/CMakeFiles/template_project.dir/clean

apps/CMakeFiles/template_project.dir/depend:
	cd /home/aczi/test/hardgame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aczi/test/hardgame /home/aczi/test/hardgame/apps /home/aczi/test/hardgame/build /home/aczi/test/hardgame/build/apps /home/aczi/test/hardgame/build/apps/CMakeFiles/template_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/CMakeFiles/template_project.dir/depend
