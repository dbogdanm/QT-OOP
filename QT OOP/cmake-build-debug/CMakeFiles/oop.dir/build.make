# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2024.1.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2024.1.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ripip\Desktop\OOP_cLion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ripip\Desktop\OOP_cLion\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/oop.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/oop.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/oop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oop.dir/flags.make

CMakeFiles/oop.dir/main.cpp.obj: CMakeFiles/oop.dir/flags.make
CMakeFiles/oop.dir/main.cpp.obj: CMakeFiles/oop.dir/includes_CXX.rsp
CMakeFiles/oop.dir/main.cpp.obj: C:/Users/ripip/Desktop/OOP_cLion/main.cpp
CMakeFiles/oop.dir/main.cpp.obj: CMakeFiles/oop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ripip\Desktop\OOP_cLion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oop.dir/main.cpp.obj"
	"D:\CLion 2024.1.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/oop.dir/main.cpp.obj -MF CMakeFiles\oop.dir\main.cpp.obj.d -o CMakeFiles\oop.dir\main.cpp.obj -c C:\Users\ripip\Desktop\OOP_cLion\main.cpp

CMakeFiles/oop.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/oop.dir/main.cpp.i"
	"D:\CLion 2024.1.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ripip\Desktop\OOP_cLion\main.cpp > CMakeFiles\oop.dir\main.cpp.i

CMakeFiles/oop.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/oop.dir/main.cpp.s"
	"D:\CLion 2024.1.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ripip\Desktop\OOP_cLion\main.cpp -o CMakeFiles\oop.dir\main.cpp.s

CMakeFiles/oop.dir/generated/src/Helper.cpp.obj: CMakeFiles/oop.dir/flags.make
CMakeFiles/oop.dir/generated/src/Helper.cpp.obj: CMakeFiles/oop.dir/includes_CXX.rsp
CMakeFiles/oop.dir/generated/src/Helper.cpp.obj: C:/Users/ripip/Desktop/OOP_cLion/generated/src/Helper.cpp
CMakeFiles/oop.dir/generated/src/Helper.cpp.obj: CMakeFiles/oop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ripip\Desktop\OOP_cLion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/oop.dir/generated/src/Helper.cpp.obj"
	"D:\CLion 2024.1.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/oop.dir/generated/src/Helper.cpp.obj -MF CMakeFiles\oop.dir\generated\src\Helper.cpp.obj.d -o CMakeFiles\oop.dir\generated\src\Helper.cpp.obj -c C:\Users\ripip\Desktop\OOP_cLion\generated\src\Helper.cpp

CMakeFiles/oop.dir/generated/src/Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/oop.dir/generated/src/Helper.cpp.i"
	"D:\CLion 2024.1.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ripip\Desktop\OOP_cLion\generated\src\Helper.cpp > CMakeFiles\oop.dir\generated\src\Helper.cpp.i

CMakeFiles/oop.dir/generated/src/Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/oop.dir/generated/src/Helper.cpp.s"
	"D:\CLion 2024.1.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ripip\Desktop\OOP_cLion\generated\src\Helper.cpp -o CMakeFiles\oop.dir\generated\src\Helper.cpp.s

# Object files for target oop
oop_OBJECTS = \
"CMakeFiles/oop.dir/main.cpp.obj" \
"CMakeFiles/oop.dir/generated/src/Helper.cpp.obj"

# External object files for target oop
oop_EXTERNAL_OBJECTS =

oop.exe: CMakeFiles/oop.dir/main.cpp.obj
oop.exe: CMakeFiles/oop.dir/generated/src/Helper.cpp.obj
oop.exe: CMakeFiles/oop.dir/build.make
oop.exe: CMakeFiles/oop.dir/linkLibs.rsp
oop.exe: CMakeFiles/oop.dir/objects1.rsp
oop.exe: CMakeFiles/oop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\ripip\Desktop\OOP_cLion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable oop.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\oop.dir\link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copying tastatura.txt..."
	"D:\CLion 2024.1.4\bin\cmake\win\x64\bin\cmake.exe" -E copy_if_different C:/Users/ripip/Desktop/OOP_cLion/tastatura.txt C:/Users/ripip/Desktop/OOP_cLion/cmake-build-debug

# Rule to build all files generated by this target.
CMakeFiles/oop.dir/build: oop.exe
.PHONY : CMakeFiles/oop.dir/build

CMakeFiles/oop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\oop.dir\cmake_clean.cmake
.PHONY : CMakeFiles/oop.dir/clean

CMakeFiles/oop.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ripip\Desktop\OOP_cLion C:\Users\ripip\Desktop\OOP_cLion C:\Users\ripip\Desktop\OOP_cLion\cmake-build-debug C:\Users\ripip\Desktop\OOP_cLion\cmake-build-debug C:\Users\ripip\Desktop\OOP_cLion\cmake-build-debug\CMakeFiles\oop.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/oop.dir/depend

