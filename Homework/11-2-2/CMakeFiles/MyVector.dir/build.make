# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/lys/2019_ITE1015_2019087101/11-2-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lys/2019_ITE1015_2019087101/11-2-2

# Include any dependencies generated for this target.
include CMakeFiles/MyVector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyVector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyVector.dir/flags.make

CMakeFiles/MyVector.dir/main.cpp.o: CMakeFiles/MyVector.dir/flags.make
CMakeFiles/MyVector.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lys/2019_ITE1015_2019087101/11-2-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyVector.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyVector.dir/main.cpp.o -c /home/lys/2019_ITE1015_2019087101/11-2-2/main.cpp

CMakeFiles/MyVector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyVector.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lys/2019_ITE1015_2019087101/11-2-2/main.cpp > CMakeFiles/MyVector.dir/main.cpp.i

CMakeFiles/MyVector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyVector.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lys/2019_ITE1015_2019087101/11-2-2/main.cpp -o CMakeFiles/MyVector.dir/main.cpp.s

CMakeFiles/MyVector.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MyVector.dir/main.cpp.o.requires

CMakeFiles/MyVector.dir/main.cpp.o.provides: CMakeFiles/MyVector.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyVector.dir/build.make CMakeFiles/MyVector.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MyVector.dir/main.cpp.o.provides

CMakeFiles/MyVector.dir/main.cpp.o.provides.build: CMakeFiles/MyVector.dir/main.cpp.o


CMakeFiles/MyVector.dir/my_vector2.cpp.o: CMakeFiles/MyVector.dir/flags.make
CMakeFiles/MyVector.dir/my_vector2.cpp.o: my_vector2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lys/2019_ITE1015_2019087101/11-2-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyVector.dir/my_vector2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyVector.dir/my_vector2.cpp.o -c /home/lys/2019_ITE1015_2019087101/11-2-2/my_vector2.cpp

CMakeFiles/MyVector.dir/my_vector2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyVector.dir/my_vector2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lys/2019_ITE1015_2019087101/11-2-2/my_vector2.cpp > CMakeFiles/MyVector.dir/my_vector2.cpp.i

CMakeFiles/MyVector.dir/my_vector2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyVector.dir/my_vector2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lys/2019_ITE1015_2019087101/11-2-2/my_vector2.cpp -o CMakeFiles/MyVector.dir/my_vector2.cpp.s

CMakeFiles/MyVector.dir/my_vector2.cpp.o.requires:

.PHONY : CMakeFiles/MyVector.dir/my_vector2.cpp.o.requires

CMakeFiles/MyVector.dir/my_vector2.cpp.o.provides: CMakeFiles/MyVector.dir/my_vector2.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyVector.dir/build.make CMakeFiles/MyVector.dir/my_vector2.cpp.o.provides.build
.PHONY : CMakeFiles/MyVector.dir/my_vector2.cpp.o.provides

CMakeFiles/MyVector.dir/my_vector2.cpp.o.provides.build: CMakeFiles/MyVector.dir/my_vector2.cpp.o


# Object files for target MyVector
MyVector_OBJECTS = \
"CMakeFiles/MyVector.dir/main.cpp.o" \
"CMakeFiles/MyVector.dir/my_vector2.cpp.o"

# External object files for target MyVector
MyVector_EXTERNAL_OBJECTS =

MyVector: CMakeFiles/MyVector.dir/main.cpp.o
MyVector: CMakeFiles/MyVector.dir/my_vector2.cpp.o
MyVector: CMakeFiles/MyVector.dir/build.make
MyVector: CMakeFiles/MyVector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lys/2019_ITE1015_2019087101/11-2-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MyVector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyVector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyVector.dir/build: MyVector

.PHONY : CMakeFiles/MyVector.dir/build

CMakeFiles/MyVector.dir/requires: CMakeFiles/MyVector.dir/main.cpp.o.requires
CMakeFiles/MyVector.dir/requires: CMakeFiles/MyVector.dir/my_vector2.cpp.o.requires

.PHONY : CMakeFiles/MyVector.dir/requires

CMakeFiles/MyVector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyVector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyVector.dir/clean

CMakeFiles/MyVector.dir/depend:
	cd /home/lys/2019_ITE1015_2019087101/11-2-2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lys/2019_ITE1015_2019087101/11-2-2 /home/lys/2019_ITE1015_2019087101/11-2-2 /home/lys/2019_ITE1015_2019087101/11-2-2 /home/lys/2019_ITE1015_2019087101/11-2-2 /home/lys/2019_ITE1015_2019087101/11-2-2/CMakeFiles/MyVector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyVector.dir/depend

