# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/sakshitha/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/sakshitha/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sakshitha/CPPfiles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sakshitha/CPPfiles/build

# Include any dependencies generated for this target.
include CMakeFiles/mongo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mongo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mongo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mongo.dir/flags.make

CMakeFiles/mongo.dir/database.cpp.o: CMakeFiles/mongo.dir/flags.make
CMakeFiles/mongo.dir/database.cpp.o: /home/sakshitha/CPPfiles/database.cpp
CMakeFiles/mongo.dir/database.cpp.o: CMakeFiles/mongo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sakshitha/CPPfiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mongo.dir/database.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mongo.dir/database.cpp.o -MF CMakeFiles/mongo.dir/database.cpp.o.d -o CMakeFiles/mongo.dir/database.cpp.o -c /home/sakshitha/CPPfiles/database.cpp

CMakeFiles/mongo.dir/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mongo.dir/database.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sakshitha/CPPfiles/database.cpp > CMakeFiles/mongo.dir/database.cpp.i

CMakeFiles/mongo.dir/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mongo.dir/database.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sakshitha/CPPfiles/database.cpp -o CMakeFiles/mongo.dir/database.cpp.s

# Object files for target mongo
mongo_OBJECTS = \
"CMakeFiles/mongo.dir/database.cpp.o"

# External object files for target mongo
mongo_EXTERNAL_OBJECTS =

libmongo.a: CMakeFiles/mongo.dir/database.cpp.o
libmongo.a: CMakeFiles/mongo.dir/build.make
libmongo.a: CMakeFiles/mongo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sakshitha/CPPfiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmongo.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mongo.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mongo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mongo.dir/build: libmongo.a
.PHONY : CMakeFiles/mongo.dir/build

CMakeFiles/mongo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mongo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mongo.dir/clean

CMakeFiles/mongo.dir/depend:
	cd /home/sakshitha/CPPfiles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sakshitha/CPPfiles /home/sakshitha/CPPfiles /home/sakshitha/CPPfiles/build /home/sakshitha/CPPfiles/build /home/sakshitha/CPPfiles/build/CMakeFiles/mongo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mongo.dir/depend

