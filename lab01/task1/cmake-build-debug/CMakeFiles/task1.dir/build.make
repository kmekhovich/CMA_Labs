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
CMAKE_SOURCE_DIR = /Users/kmekhovich/labs/CMA_Labs/lab01/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/task1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task1.dir/flags.make

CMakeFiles/task1.dir/main.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/main.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/main.cpp

CMakeFiles/task1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/main.cpp > CMakeFiles/task1.dir/main.cpp.i

CMakeFiles/task1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/main.cpp -o CMakeFiles/task1.dir/main.cpp.s

CMakeFiles/task1.dir/symmetric_matrix.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/symmetric_matrix.cpp.o: ../symmetric_matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task1.dir/symmetric_matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/symmetric_matrix.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/symmetric_matrix.cpp

CMakeFiles/task1.dir/symmetric_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/symmetric_matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/symmetric_matrix.cpp > CMakeFiles/task1.dir/symmetric_matrix.cpp.i

CMakeFiles/task1.dir/symmetric_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/symmetric_matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/symmetric_matrix.cpp -o CMakeFiles/task1.dir/symmetric_matrix.cpp.s

CMakeFiles/task1.dir/random_generator.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/random_generator.cpp.o: ../random_generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task1.dir/random_generator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/random_generator.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/random_generator.cpp

CMakeFiles/task1.dir/random_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/random_generator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/random_generator.cpp > CMakeFiles/task1.dir/random_generator.cpp.i

CMakeFiles/task1.dir/random_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/random_generator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/random_generator.cpp -o CMakeFiles/task1.dir/random_generator.cpp.s

CMakeFiles/task1.dir/quadratic_matrix.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/quadratic_matrix.cpp.o: ../quadratic_matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task1.dir/quadratic_matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/quadratic_matrix.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/quadratic_matrix.cpp

CMakeFiles/task1.dir/quadratic_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/quadratic_matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/quadratic_matrix.cpp > CMakeFiles/task1.dir/quadratic_matrix.cpp.i

CMakeFiles/task1.dir/quadratic_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/quadratic_matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/quadratic_matrix.cpp -o CMakeFiles/task1.dir/quadratic_matrix.cpp.s

CMakeFiles/task1.dir/lu_helper.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/lu_helper.cpp.o: ../lu_helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/task1.dir/lu_helper.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/lu_helper.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/lu_helper.cpp

CMakeFiles/task1.dir/lu_helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/lu_helper.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/lu_helper.cpp > CMakeFiles/task1.dir/lu_helper.cpp.i

CMakeFiles/task1.dir/lu_helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/lu_helper.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/lu_helper.cpp -o CMakeFiles/task1.dir/lu_helper.cpp.s

CMakeFiles/task1.dir/vector.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/vector.cpp.o: ../vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/task1.dir/vector.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/vector.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/vector.cpp

CMakeFiles/task1.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/vector.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/vector.cpp > CMakeFiles/task1.dir/vector.cpp.i

CMakeFiles/task1.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/vector.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/vector.cpp -o CMakeFiles/task1.dir/vector.cpp.s

CMakeFiles/task1.dir/clock_guard.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/clock_guard.cpp.o: ../clock_guard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/task1.dir/clock_guard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/clock_guard.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/clock_guard.cpp

CMakeFiles/task1.dir/clock_guard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/clock_guard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/clock_guard.cpp > CMakeFiles/task1.dir/clock_guard.cpp.i

CMakeFiles/task1.dir/clock_guard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/clock_guard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/clock_guard.cpp -o CMakeFiles/task1.dir/clock_guard.cpp.s

CMakeFiles/task1.dir/ldlt_helper.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/ldlt_helper.cpp.o: ../ldlt_helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/task1.dir/ldlt_helper.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/ldlt_helper.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/ldlt_helper.cpp

CMakeFiles/task1.dir/ldlt_helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/ldlt_helper.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/ldlt_helper.cpp > CMakeFiles/task1.dir/ldlt_helper.cpp.i

CMakeFiles/task1.dir/ldlt_helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/ldlt_helper.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/ldlt_helper.cpp -o CMakeFiles/task1.dir/ldlt_helper.cpp.s

CMakeFiles/task1.dir/checker.cpp.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/checker.cpp.o: ../checker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/task1.dir/checker.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1.dir/checker.cpp.o -c /Users/kmekhovich/labs/CMA_Labs/lab01/task1/checker.cpp

CMakeFiles/task1.dir/checker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1.dir/checker.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kmekhovich/labs/CMA_Labs/lab01/task1/checker.cpp > CMakeFiles/task1.dir/checker.cpp.i

CMakeFiles/task1.dir/checker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1.dir/checker.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kmekhovich/labs/CMA_Labs/lab01/task1/checker.cpp -o CMakeFiles/task1.dir/checker.cpp.s

# Object files for target task1
task1_OBJECTS = \
"CMakeFiles/task1.dir/main.cpp.o" \
"CMakeFiles/task1.dir/symmetric_matrix.cpp.o" \
"CMakeFiles/task1.dir/random_generator.cpp.o" \
"CMakeFiles/task1.dir/quadratic_matrix.cpp.o" \
"CMakeFiles/task1.dir/lu_helper.cpp.o" \
"CMakeFiles/task1.dir/vector.cpp.o" \
"CMakeFiles/task1.dir/clock_guard.cpp.o" \
"CMakeFiles/task1.dir/ldlt_helper.cpp.o" \
"CMakeFiles/task1.dir/checker.cpp.o"

# External object files for target task1
task1_EXTERNAL_OBJECTS =

task1: CMakeFiles/task1.dir/main.cpp.o
task1: CMakeFiles/task1.dir/symmetric_matrix.cpp.o
task1: CMakeFiles/task1.dir/random_generator.cpp.o
task1: CMakeFiles/task1.dir/quadratic_matrix.cpp.o
task1: CMakeFiles/task1.dir/lu_helper.cpp.o
task1: CMakeFiles/task1.dir/vector.cpp.o
task1: CMakeFiles/task1.dir/clock_guard.cpp.o
task1: CMakeFiles/task1.dir/ldlt_helper.cpp.o
task1: CMakeFiles/task1.dir/checker.cpp.o
task1: CMakeFiles/task1.dir/build.make
task1: CMakeFiles/task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable task1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task1.dir/build: task1
.PHONY : CMakeFiles/task1.dir/build

CMakeFiles/task1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task1.dir/clean

CMakeFiles/task1.dir/depend:
	cd /Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kmekhovich/labs/CMA_Labs/lab01/task1 /Users/kmekhovich/labs/CMA_Labs/lab01/task1 /Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug /Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug /Users/kmekhovich/labs/CMA_Labs/lab01/task1/cmake-build-debug/CMakeFiles/task1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task1.dir/depend

