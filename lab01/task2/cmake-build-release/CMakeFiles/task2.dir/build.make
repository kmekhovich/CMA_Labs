# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kmekhovich/labs/CMA_labs/lab01/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/task2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task2.dir/flags.make

CMakeFiles/task2.dir/main.cpp.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2.dir/main.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task2/main.cpp

CMakeFiles/task2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task2/main.cpp > CMakeFiles/task2.dir/main.cpp.i

CMakeFiles/task2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task2/main.cpp -o CMakeFiles/task2.dir/main.cpp.s

CMakeFiles/task2.dir/matrix.cpp.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/matrix.cpp.o: ../matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task2.dir/matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2.dir/matrix.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task2/matrix.cpp

CMakeFiles/task2.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.dir/matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task2/matrix.cpp > CMakeFiles/task2.dir/matrix.cpp.i

CMakeFiles/task2.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.dir/matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task2/matrix.cpp -o CMakeFiles/task2.dir/matrix.cpp.s

CMakeFiles/task2.dir/vector.cpp.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/vector.cpp.o: ../vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task2.dir/vector.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2.dir/vector.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task2/vector.cpp

CMakeFiles/task2.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.dir/vector.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task2/vector.cpp > CMakeFiles/task2.dir/vector.cpp.i

CMakeFiles/task2.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.dir/vector.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task2/vector.cpp -o CMakeFiles/task2.dir/vector.cpp.s

CMakeFiles/task2.dir/norm_matrix.cpp.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/norm_matrix.cpp.o: ../norm_matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task2.dir/norm_matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2.dir/norm_matrix.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task2/norm_matrix.cpp

CMakeFiles/task2.dir/norm_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.dir/norm_matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task2/norm_matrix.cpp > CMakeFiles/task2.dir/norm_matrix.cpp.i

CMakeFiles/task2.dir/norm_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.dir/norm_matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task2/norm_matrix.cpp -o CMakeFiles/task2.dir/norm_matrix.cpp.s

CMakeFiles/task2.dir/clock_guard.cpp.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/clock_guard.cpp.o: ../clock_guard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/task2.dir/clock_guard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2.dir/clock_guard.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task2/clock_guard.cpp

CMakeFiles/task2.dir/clock_guard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.dir/clock_guard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task2/clock_guard.cpp > CMakeFiles/task2.dir/clock_guard.cpp.i

CMakeFiles/task2.dir/clock_guard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.dir/clock_guard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task2/clock_guard.cpp -o CMakeFiles/task2.dir/clock_guard.cpp.s

CMakeFiles/task2.dir/gmres.cpp.o: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/gmres.cpp.o: ../gmres.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/task2.dir/gmres.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2.dir/gmres.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task2/gmres.cpp

CMakeFiles/task2.dir/gmres.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.dir/gmres.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task2/gmres.cpp > CMakeFiles/task2.dir/gmres.cpp.i

CMakeFiles/task2.dir/gmres.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.dir/gmres.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task2/gmres.cpp -o CMakeFiles/task2.dir/gmres.cpp.s

# Object files for target task2
task2_OBJECTS = \
"CMakeFiles/task2.dir/main.cpp.o" \
"CMakeFiles/task2.dir/matrix.cpp.o" \
"CMakeFiles/task2.dir/vector.cpp.o" \
"CMakeFiles/task2.dir/norm_matrix.cpp.o" \
"CMakeFiles/task2.dir/clock_guard.cpp.o" \
"CMakeFiles/task2.dir/gmres.cpp.o"

# External object files for target task2
task2_EXTERNAL_OBJECTS =

task2: CMakeFiles/task2.dir/main.cpp.o
task2: CMakeFiles/task2.dir/matrix.cpp.o
task2: CMakeFiles/task2.dir/vector.cpp.o
task2: CMakeFiles/task2.dir/norm_matrix.cpp.o
task2: CMakeFiles/task2.dir/clock_guard.cpp.o
task2: CMakeFiles/task2.dir/gmres.cpp.o
task2: CMakeFiles/task2.dir/build.make
task2: CMakeFiles/task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable task2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task2.dir/build: task2
.PHONY : CMakeFiles/task2.dir/build

CMakeFiles/task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task2.dir/clean

CMakeFiles/task2.dir/depend:
	cd /Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kmekhovich/labs/CMA_labs/lab01/task2 /Users/kmekhovich/labs/CMA_labs/lab01/task2 /Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release /Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release /Users/kmekhovich/labs/CMA_labs/lab01/task2/cmake-build-release/CMakeFiles/task2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task2.dir/depend

