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
CMAKE_COMMAND = /snap/clion/259/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/259/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mikhail/labs/labs/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mikhail/labs/labs/game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/game.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game.cpp.o: /home/mikhail/labs/labs/game/game.cpp
CMakeFiles/game.dir/game.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/game.cpp.o -MF CMakeFiles/game.dir/game.cpp.o.d -o CMakeFiles/game.dir/game.cpp.o -c /home/mikhail/labs/labs/game/game.cpp

CMakeFiles/game.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/game.cpp > CMakeFiles/game.dir/game.cpp.i

CMakeFiles/game.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/game.cpp -o CMakeFiles/game.dir/game.cpp.s

CMakeFiles/game.dir/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/main.cpp.o: /home/mikhail/labs/labs/game/main.cpp
CMakeFiles/game.dir/main.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/main.cpp.o -MF CMakeFiles/game.dir/main.cpp.o.d -o CMakeFiles/game.dir/main.cpp.o -c /home/mikhail/labs/labs/game/main.cpp

CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/main.cpp > CMakeFiles/game.dir/main.cpp.i

CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/main.cpp -o CMakeFiles/game.dir/main.cpp.s

CMakeFiles/game.dir/game_objects/bullet.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_objects/bullet.cpp.o: /home/mikhail/labs/labs/game/game_objects/bullet.cpp
CMakeFiles/game.dir/game_objects/bullet.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/game_objects/bullet.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/game_objects/bullet.cpp.o -MF CMakeFiles/game.dir/game_objects/bullet.cpp.o.d -o CMakeFiles/game.dir/game_objects/bullet.cpp.o -c /home/mikhail/labs/labs/game/game_objects/bullet.cpp

CMakeFiles/game.dir/game_objects/bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/game_objects/bullet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/game_objects/bullet.cpp > CMakeFiles/game.dir/game_objects/bullet.cpp.i

CMakeFiles/game.dir/game_objects/bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/game_objects/bullet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/game_objects/bullet.cpp -o CMakeFiles/game.dir/game_objects/bullet.cpp.s

CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o: /home/mikhail/labs/labs/game/game_objects/dynamic_object.cpp
CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o -MF CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o.d -o CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o -c /home/mikhail/labs/labs/game/game_objects/dynamic_object.cpp

CMakeFiles/game.dir/game_objects/dynamic_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/game_objects/dynamic_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/game_objects/dynamic_object.cpp > CMakeFiles/game.dir/game_objects/dynamic_object.cpp.i

CMakeFiles/game.dir/game_objects/dynamic_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/game_objects/dynamic_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/game_objects/dynamic_object.cpp -o CMakeFiles/game.dir/game_objects/dynamic_object.cpp.s

CMakeFiles/game.dir/game_objects/invadership.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_objects/invadership.cpp.o: /home/mikhail/labs/labs/game/game_objects/invadership.cpp
CMakeFiles/game.dir/game_objects/invadership.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/game_objects/invadership.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/game_objects/invadership.cpp.o -MF CMakeFiles/game.dir/game_objects/invadership.cpp.o.d -o CMakeFiles/game.dir/game_objects/invadership.cpp.o -c /home/mikhail/labs/labs/game/game_objects/invadership.cpp

CMakeFiles/game.dir/game_objects/invadership.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/game_objects/invadership.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/game_objects/invadership.cpp > CMakeFiles/game.dir/game_objects/invadership.cpp.i

CMakeFiles/game.dir/game_objects/invadership.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/game_objects/invadership.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/game_objects/invadership.cpp -o CMakeFiles/game.dir/game_objects/invadership.cpp.s

CMakeFiles/game.dir/game_objects/spaceship.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_objects/spaceship.cpp.o: /home/mikhail/labs/labs/game/game_objects/spaceship.cpp
CMakeFiles/game.dir/game_objects/spaceship.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/game_objects/spaceship.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/game_objects/spaceship.cpp.o -MF CMakeFiles/game.dir/game_objects/spaceship.cpp.o.d -o CMakeFiles/game.dir/game_objects/spaceship.cpp.o -c /home/mikhail/labs/labs/game/game_objects/spaceship.cpp

CMakeFiles/game.dir/game_objects/spaceship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/game_objects/spaceship.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/game_objects/spaceship.cpp > CMakeFiles/game.dir/game_objects/spaceship.cpp.i

CMakeFiles/game.dir/game_objects/spaceship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/game_objects/spaceship.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/game_objects/spaceship.cpp -o CMakeFiles/game.dir/game_objects/spaceship.cpp.s

CMakeFiles/game.dir/game_screen/game_screen.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/game_screen/game_screen.cpp.o: /home/mikhail/labs/labs/game/game_screen/game_screen.cpp
CMakeFiles/game.dir/game_screen/game_screen.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/game_screen/game_screen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/game_screen/game_screen.cpp.o -MF CMakeFiles/game.dir/game_screen/game_screen.cpp.o.d -o CMakeFiles/game.dir/game_screen/game_screen.cpp.o -c /home/mikhail/labs/labs/game/game_screen/game_screen.cpp

CMakeFiles/game.dir/game_screen/game_screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/game_screen/game_screen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/game_screen/game_screen.cpp > CMakeFiles/game.dir/game_screen/game_screen.cpp.i

CMakeFiles/game.dir/game_screen/game_screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/game_screen/game_screen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/game_screen/game_screen.cpp -o CMakeFiles/game.dir/game_screen/game_screen.cpp.s

CMakeFiles/game.dir/context/context.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/context/context.cpp.o: /home/mikhail/labs/labs/game/context/context.cpp
CMakeFiles/game.dir/context/context.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/context/context.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/context/context.cpp.o -MF CMakeFiles/game.dir/context/context.cpp.o.d -o CMakeFiles/game.dir/context/context.cpp.o -c /home/mikhail/labs/labs/game/context/context.cpp

CMakeFiles/game.dir/context/context.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/context/context.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/context/context.cpp > CMakeFiles/game.dir/context/context.cpp.i

CMakeFiles/game.dir/context/context.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/context/context.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/context/context.cpp -o CMakeFiles/game.dir/context/context.cpp.s

CMakeFiles/game.dir/factory/factory.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/factory/factory.cpp.o: /home/mikhail/labs/labs/game/factory/factory.cpp
CMakeFiles/game.dir/factory/factory.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/game.dir/factory/factory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/factory/factory.cpp.o -MF CMakeFiles/game.dir/factory/factory.cpp.o.d -o CMakeFiles/game.dir/factory/factory.cpp.o -c /home/mikhail/labs/labs/game/factory/factory.cpp

CMakeFiles/game.dir/factory/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/factory/factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/factory/factory.cpp > CMakeFiles/game.dir/factory/factory.cpp.i

CMakeFiles/game.dir/factory/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/factory/factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/factory/factory.cpp -o CMakeFiles/game.dir/factory/factory.cpp.s

CMakeFiles/game.dir/score_table/score_table.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/score_table/score_table.cpp.o: /home/mikhail/labs/labs/game/score_table/score_table.cpp
CMakeFiles/game.dir/score_table/score_table.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/game.dir/score_table/score_table.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/score_table/score_table.cpp.o -MF CMakeFiles/game.dir/score_table/score_table.cpp.o.d -o CMakeFiles/game.dir/score_table/score_table.cpp.o -c /home/mikhail/labs/labs/game/score_table/score_table.cpp

CMakeFiles/game.dir/score_table/score_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/score_table/score_table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/score_table/score_table.cpp > CMakeFiles/game.dir/score_table/score_table.cpp.i

CMakeFiles/game.dir/score_table/score_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/score_table/score_table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/score_table/score_table.cpp -o CMakeFiles/game.dir/score_table/score_table.cpp.s

CMakeFiles/game.dir/save_table/save_table.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/save_table/save_table.cpp.o: /home/mikhail/labs/labs/game/save_table/save_table.cpp
CMakeFiles/game.dir/save_table/save_table.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/game.dir/save_table/save_table.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/save_table/save_table.cpp.o -MF CMakeFiles/game.dir/save_table/save_table.cpp.o.d -o CMakeFiles/game.dir/save_table/save_table.cpp.o -c /home/mikhail/labs/labs/game/save_table/save_table.cpp

CMakeFiles/game.dir/save_table/save_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/save_table/save_table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail/labs/labs/game/save_table/save_table.cpp > CMakeFiles/game.dir/save_table/save_table.cpp.i

CMakeFiles/game.dir/save_table/save_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/save_table/save_table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail/labs/labs/game/save_table/save_table.cpp -o CMakeFiles/game.dir/save_table/save_table.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/game.cpp.o" \
"CMakeFiles/game.dir/main.cpp.o" \
"CMakeFiles/game.dir/game_objects/bullet.cpp.o" \
"CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o" \
"CMakeFiles/game.dir/game_objects/invadership.cpp.o" \
"CMakeFiles/game.dir/game_objects/spaceship.cpp.o" \
"CMakeFiles/game.dir/game_screen/game_screen.cpp.o" \
"CMakeFiles/game.dir/context/context.cpp.o" \
"CMakeFiles/game.dir/factory/factory.cpp.o" \
"CMakeFiles/game.dir/score_table/score_table.cpp.o" \
"CMakeFiles/game.dir/save_table/save_table.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/game.cpp.o
game: CMakeFiles/game.dir/main.cpp.o
game: CMakeFiles/game.dir/game_objects/bullet.cpp.o
game: CMakeFiles/game.dir/game_objects/dynamic_object.cpp.o
game: CMakeFiles/game.dir/game_objects/invadership.cpp.o
game: CMakeFiles/game.dir/game_objects/spaceship.cpp.o
game: CMakeFiles/game.dir/game_screen/game_screen.cpp.o
game: CMakeFiles/game.dir/context/context.cpp.o
game: CMakeFiles/game.dir/factory/factory.cpp.o
game: CMakeFiles/game.dir/score_table/score_table.cpp.o
game: CMakeFiles/game.dir/save_table/save_table.cpp.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/mikhail/labs/labs/game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mikhail/labs/labs/game /home/mikhail/labs/labs/game /home/mikhail/labs/labs/game/cmake-build-debug /home/mikhail/labs/labs/game/cmake-build-debug /home/mikhail/labs/labs/game/cmake-build-debug/CMakeFiles/game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/game.dir/depend

