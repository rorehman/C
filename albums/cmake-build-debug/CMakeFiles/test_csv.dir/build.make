# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/rauha/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/rauha/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/rauha/CLionProjects/albums

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_csv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_csv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_csv.dir/flags.make

CMakeFiles/test_csv.dir/test_csv.c.o: CMakeFiles/test_csv.dir/flags.make
CMakeFiles/test_csv.dir/test_csv.c.o: ../test_csv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_csv.dir/test_csv.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_csv.dir/test_csv.c.o   -c /cygdrive/c/Users/rauha/CLionProjects/albums/test_csv.c

CMakeFiles/test_csv.dir/test_csv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_csv.dir/test_csv.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/rauha/CLionProjects/albums/test_csv.c > CMakeFiles/test_csv.dir/test_csv.c.i

CMakeFiles/test_csv.dir/test_csv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_csv.dir/test_csv.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/rauha/CLionProjects/albums/test_csv.c -o CMakeFiles/test_csv.dir/test_csv.c.s

CMakeFiles/test_csv.dir/csv.c.o: CMakeFiles/test_csv.dir/flags.make
CMakeFiles/test_csv.dir/csv.c.o: ../csv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_csv.dir/csv.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_csv.dir/csv.c.o   -c /cygdrive/c/Users/rauha/CLionProjects/albums/csv.c

CMakeFiles/test_csv.dir/csv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_csv.dir/csv.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/rauha/CLionProjects/albums/csv.c > CMakeFiles/test_csv.dir/csv.c.i

CMakeFiles/test_csv.dir/csv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_csv.dir/csv.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/rauha/CLionProjects/albums/csv.c -o CMakeFiles/test_csv.dir/csv.c.s

# Object files for target test_csv
test_csv_OBJECTS = \
"CMakeFiles/test_csv.dir/test_csv.c.o" \
"CMakeFiles/test_csv.dir/csv.c.o"

# External object files for target test_csv
test_csv_EXTERNAL_OBJECTS =

test_csv.exe: CMakeFiles/test_csv.dir/test_csv.c.o
test_csv.exe: CMakeFiles/test_csv.dir/csv.c.o
test_csv.exe: CMakeFiles/test_csv.dir/build.make
test_csv.exe: CMakeFiles/test_csv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test_csv.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_csv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_csv.dir/build: test_csv.exe

.PHONY : CMakeFiles/test_csv.dir/build

CMakeFiles/test_csv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_csv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_csv.dir/clean

CMakeFiles/test_csv.dir/depend:
	cd /cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/rauha/CLionProjects/albums /cygdrive/c/Users/rauha/CLionProjects/albums /cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug /cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug /cygdrive/c/Users/rauha/CLionProjects/albums/cmake-build-debug/CMakeFiles/test_csv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_csv.dir/depend
