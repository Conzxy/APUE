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
CMAKE_SOURCE_DIR = /home/conzxy/apue/APUE/thread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/conzxy/apue/APUE/thread/build

# Include any dependencies generated for this target.
include CMakeFiles/sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort.dir/flags.make

CMakeFiles/sort.dir/sort.cc.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/sort.cc.o: ../sort.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/conzxy/apue/APUE/thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sort.dir/sort.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sort.dir/sort.cc.o -c /home/conzxy/apue/APUE/thread/sort.cc

CMakeFiles/sort.dir/sort.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort.dir/sort.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/conzxy/apue/APUE/thread/sort.cc > CMakeFiles/sort.dir/sort.cc.i

CMakeFiles/sort.dir/sort.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort.dir/sort.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/conzxy/apue/APUE/thread/sort.cc -o CMakeFiles/sort.dir/sort.cc.s

CMakeFiles/sort.dir/mythread/condition.cc.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/mythread/condition.cc.o: ../mythread/condition.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/conzxy/apue/APUE/thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sort.dir/mythread/condition.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sort.dir/mythread/condition.cc.o -c /home/conzxy/apue/APUE/thread/mythread/condition.cc

CMakeFiles/sort.dir/mythread/condition.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort.dir/mythread/condition.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/conzxy/apue/APUE/thread/mythread/condition.cc > CMakeFiles/sort.dir/mythread/condition.cc.i

CMakeFiles/sort.dir/mythread/condition.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort.dir/mythread/condition.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/conzxy/apue/APUE/thread/mythread/condition.cc -o CMakeFiles/sort.dir/mythread/condition.cc.s

CMakeFiles/sort.dir/mythread/thread.cc.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/mythread/thread.cc.o: ../mythread/thread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/conzxy/apue/APUE/thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sort.dir/mythread/thread.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sort.dir/mythread/thread.cc.o -c /home/conzxy/apue/APUE/thread/mythread/thread.cc

CMakeFiles/sort.dir/mythread/thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort.dir/mythread/thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/conzxy/apue/APUE/thread/mythread/thread.cc > CMakeFiles/sort.dir/mythread/thread.cc.i

CMakeFiles/sort.dir/mythread/thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort.dir/mythread/thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/conzxy/apue/APUE/thread/mythread/thread.cc -o CMakeFiles/sort.dir/mythread/thread.cc.s

# Object files for target sort
sort_OBJECTS = \
"CMakeFiles/sort.dir/sort.cc.o" \
"CMakeFiles/sort.dir/mythread/condition.cc.o" \
"CMakeFiles/sort.dir/mythread/thread.cc.o"

# External object files for target sort
sort_EXTERNAL_OBJECTS =

../bin/sort: CMakeFiles/sort.dir/sort.cc.o
../bin/sort: CMakeFiles/sort.dir/mythread/condition.cc.o
../bin/sort: CMakeFiles/sort.dir/mythread/thread.cc.o
../bin/sort: CMakeFiles/sort.dir/build.make
../bin/sort: CMakeFiles/sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/conzxy/apue/APUE/thread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort.dir/build: ../bin/sort

.PHONY : CMakeFiles/sort.dir/build

CMakeFiles/sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort.dir/clean

CMakeFiles/sort.dir/depend:
	cd /home/conzxy/apue/APUE/thread/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/conzxy/apue/APUE/thread /home/conzxy/apue/APUE/thread /home/conzxy/apue/APUE/thread/build /home/conzxy/apue/APUE/thread/build /home/conzxy/apue/APUE/thread/build/CMakeFiles/sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort.dir/depend

