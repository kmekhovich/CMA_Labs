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
CMAKE_SOURCE_DIR = /Users/kmekhovich/labs/CMA_labs/lab01/task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/task3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/task3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task3.dir/flags.make

CMakeFiles/task3.dir/main.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task3.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/main.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task3/main.cpp

CMakeFiles/task3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task3/main.cpp > CMakeFiles/task3.dir/main.cpp.i

CMakeFiles/task3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task3/main.cpp -o CMakeFiles/task3.dir/main.cpp.s

CMakeFiles/task3.dir/clock_guard.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/clock_guard.cpp.o: ../clock_guard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task3.dir/clock_guard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/clock_guard.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task3/clock_guard.cpp

CMakeFiles/task3.dir/clock_guard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/clock_guard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task3/clock_guard.cpp > CMakeFiles/task3.dir/clock_guard.cpp.i

CMakeFiles/task3.dir/clock_guard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/clock_guard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task3/clock_guard.cpp -o CMakeFiles/task3.dir/clock_guard.cpp.s

CMakeFiles/task3.dir/gmres.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/gmres.cpp.o: ../gmres.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task3.dir/gmres.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/gmres.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task3/gmres.cpp

CMakeFiles/task3.dir/gmres.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/gmres.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task3/gmres.cpp > CMakeFiles/task3.dir/gmres.cpp.i

CMakeFiles/task3.dir/gmres.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/gmres.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task3/gmres.cpp -o CMakeFiles/task3.dir/gmres.cpp.s

CMakeFiles/task3.dir/vector.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/vector.cpp.o: ../vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task3.dir/vector.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/vector.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task3/vector.cpp

CMakeFiles/task3.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/vector.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task3/vector.cpp > CMakeFiles/task3.dir/vector.cpp.i

CMakeFiles/task3.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/vector.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task3/vector.cpp -o CMakeFiles/task3.dir/vector.cpp.s

CMakeFiles/task3.dir/norm_matrix.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/norm_matrix.cpp.o: ../norm_matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/task3.dir/norm_matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/norm_matrix.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task3/norm_matrix.cpp

CMakeFiles/task3.dir/norm_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/norm_matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task3/norm_matrix.cpp > CMakeFiles/task3.dir/norm_matrix.cpp.i

CMakeFiles/task3.dir/norm_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/norm_matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task3/norm_matrix.cpp -o CMakeFiles/task3.dir/norm_matrix.cpp.s

CMakeFiles/task3.dir/smart_gauss.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/smart_gauss.cpp.o: ../smart_gauss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/task3.dir/smart_gauss.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task3.dir/smart_gauss.cpp.o -c /Users/kmekhovich/labs/CMA_labs/lab01/task3/smart_gauss.cpp

CMakeFiles/task3.dir/smart_gauss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task3.dir/smart_gauss.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_labs/lab01/task3/smart_gauss.cpp > CMakeFiles/task3.dir/smart_gauss.cpp.i

CMakeFiles/task3.dir/smart_gauss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task3.dir/smart_gauss.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_labs/lab01/task3/smart_gauss.cpp -o CMakeFiles/task3.dir/smart_gauss.cpp.s

# Object files for target task3
task3_OBJECTS = \
"CMakeFiles/task3.dir/main.cpp.o" \
"CMakeFiles/task3.dir/clock_guard.cpp.o" \
"CMakeFiles/task3.dir/gmres.cpp.o" \
"CMakeFiles/task3.dir/vector.cpp.o" \
"CMakeFiles/task3.dir/norm_matrix.cpp.o" \
"CMakeFiles/task3.dir/smart_gauss.cpp.o"

# External object files for target task3
task3_EXTERNAL_OBJECTS =

task3: CMakeFiles/task3.dir/main.cpp.o
task3: CMakeFiles/task3.dir/clock_guard.cpp.o
task3: CMakeFiles/task3.dir/gmres.cpp.o
task3: CMakeFiles/task3.dir/vector.cpp.o
task3: CMakeFiles/task3.dir/norm_matrix.cpp.o
task3: CMakeFiles/task3.dir/smart_gauss.cpp.o
task3: CMakeFiles/task3.dir/build.make
task3: CMakeFiles/task3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable task3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task3.dir/build: task3
.PHONY : CMakeFiles/task3.dir/build

CMakeFiles/task3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task3.dir/clean

CMakeFiles/task3.dir/depend:
	cd /Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kmekhovich/labs/CMA_labs/lab01/task3 /Users/kmekhovich/labs/CMA_labs/lab01/task3 /Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release /Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release /Users/kmekhovich/labs/CMA_labs/lab01/task3/cmake-build-release/CMakeFiles/task3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task3.dir/depend
