# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huan/projects/EZMuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huan/projects/EZMuduo/build

# Include any dependencies generated for this target.
include CMakeFiles/EZmuduo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EZmuduo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EZmuduo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EZmuduo.dir/flags.make

CMakeFiles/EZmuduo.dir/Acceptor.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/Acceptor.o: /home/huan/projects/EZMuduo/Acceptor.cc
CMakeFiles/EZmuduo.dir/Acceptor.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EZmuduo.dir/Acceptor.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/Acceptor.o -MF CMakeFiles/EZmuduo.dir/Acceptor.o.d -o CMakeFiles/EZmuduo.dir/Acceptor.o -c /home/huan/projects/EZMuduo/Acceptor.cc

CMakeFiles/EZmuduo.dir/Acceptor.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/Acceptor.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/Acceptor.cc > CMakeFiles/EZmuduo.dir/Acceptor.i

CMakeFiles/EZmuduo.dir/Acceptor.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/Acceptor.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/Acceptor.cc -o CMakeFiles/EZmuduo.dir/Acceptor.s

CMakeFiles/EZmuduo.dir/Channel.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/Channel.o: /home/huan/projects/EZMuduo/Channel.cc
CMakeFiles/EZmuduo.dir/Channel.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EZmuduo.dir/Channel.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/Channel.o -MF CMakeFiles/EZmuduo.dir/Channel.o.d -o CMakeFiles/EZmuduo.dir/Channel.o -c /home/huan/projects/EZMuduo/Channel.cc

CMakeFiles/EZmuduo.dir/Channel.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/Channel.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/Channel.cc > CMakeFiles/EZmuduo.dir/Channel.i

CMakeFiles/EZmuduo.dir/Channel.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/Channel.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/Channel.cc -o CMakeFiles/EZmuduo.dir/Channel.s

CMakeFiles/EZmuduo.dir/CurrentThread.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/CurrentThread.o: /home/huan/projects/EZMuduo/CurrentThread.cc
CMakeFiles/EZmuduo.dir/CurrentThread.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EZmuduo.dir/CurrentThread.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/CurrentThread.o -MF CMakeFiles/EZmuduo.dir/CurrentThread.o.d -o CMakeFiles/EZmuduo.dir/CurrentThread.o -c /home/huan/projects/EZMuduo/CurrentThread.cc

CMakeFiles/EZmuduo.dir/CurrentThread.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/CurrentThread.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/CurrentThread.cc > CMakeFiles/EZmuduo.dir/CurrentThread.i

CMakeFiles/EZmuduo.dir/CurrentThread.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/CurrentThread.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/CurrentThread.cc -o CMakeFiles/EZmuduo.dir/CurrentThread.s

CMakeFiles/EZmuduo.dir/DefaultPoller.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/DefaultPoller.o: /home/huan/projects/EZMuduo/DefaultPoller.cc
CMakeFiles/EZmuduo.dir/DefaultPoller.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/EZmuduo.dir/DefaultPoller.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/DefaultPoller.o -MF CMakeFiles/EZmuduo.dir/DefaultPoller.o.d -o CMakeFiles/EZmuduo.dir/DefaultPoller.o -c /home/huan/projects/EZMuduo/DefaultPoller.cc

CMakeFiles/EZmuduo.dir/DefaultPoller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/DefaultPoller.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/DefaultPoller.cc > CMakeFiles/EZmuduo.dir/DefaultPoller.i

CMakeFiles/EZmuduo.dir/DefaultPoller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/DefaultPoller.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/DefaultPoller.cc -o CMakeFiles/EZmuduo.dir/DefaultPoller.s

CMakeFiles/EZmuduo.dir/EpollPoller.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/EpollPoller.o: /home/huan/projects/EZMuduo/EpollPoller.cc
CMakeFiles/EZmuduo.dir/EpollPoller.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/EZmuduo.dir/EpollPoller.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/EpollPoller.o -MF CMakeFiles/EZmuduo.dir/EpollPoller.o.d -o CMakeFiles/EZmuduo.dir/EpollPoller.o -c /home/huan/projects/EZMuduo/EpollPoller.cc

CMakeFiles/EZmuduo.dir/EpollPoller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/EpollPoller.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/EpollPoller.cc > CMakeFiles/EZmuduo.dir/EpollPoller.i

CMakeFiles/EZmuduo.dir/EpollPoller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/EpollPoller.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/EpollPoller.cc -o CMakeFiles/EZmuduo.dir/EpollPoller.s

CMakeFiles/EZmuduo.dir/EventLoop.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/EventLoop.o: /home/huan/projects/EZMuduo/EventLoop.cc
CMakeFiles/EZmuduo.dir/EventLoop.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/EZmuduo.dir/EventLoop.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/EventLoop.o -MF CMakeFiles/EZmuduo.dir/EventLoop.o.d -o CMakeFiles/EZmuduo.dir/EventLoop.o -c /home/huan/projects/EZMuduo/EventLoop.cc

CMakeFiles/EZmuduo.dir/EventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/EventLoop.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/EventLoop.cc > CMakeFiles/EZmuduo.dir/EventLoop.i

CMakeFiles/EZmuduo.dir/EventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/EventLoop.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/EventLoop.cc -o CMakeFiles/EZmuduo.dir/EventLoop.s

CMakeFiles/EZmuduo.dir/InetAddress.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/InetAddress.o: /home/huan/projects/EZMuduo/InetAddress.cc
CMakeFiles/EZmuduo.dir/InetAddress.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/EZmuduo.dir/InetAddress.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/InetAddress.o -MF CMakeFiles/EZmuduo.dir/InetAddress.o.d -o CMakeFiles/EZmuduo.dir/InetAddress.o -c /home/huan/projects/EZMuduo/InetAddress.cc

CMakeFiles/EZmuduo.dir/InetAddress.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/InetAddress.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/InetAddress.cc > CMakeFiles/EZmuduo.dir/InetAddress.i

CMakeFiles/EZmuduo.dir/InetAddress.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/InetAddress.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/InetAddress.cc -o CMakeFiles/EZmuduo.dir/InetAddress.s

CMakeFiles/EZmuduo.dir/Logger.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/Logger.o: /home/huan/projects/EZMuduo/Logger.cc
CMakeFiles/EZmuduo.dir/Logger.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/EZmuduo.dir/Logger.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/Logger.o -MF CMakeFiles/EZmuduo.dir/Logger.o.d -o CMakeFiles/EZmuduo.dir/Logger.o -c /home/huan/projects/EZMuduo/Logger.cc

CMakeFiles/EZmuduo.dir/Logger.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/Logger.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/Logger.cc > CMakeFiles/EZmuduo.dir/Logger.i

CMakeFiles/EZmuduo.dir/Logger.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/Logger.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/Logger.cc -o CMakeFiles/EZmuduo.dir/Logger.s

CMakeFiles/EZmuduo.dir/Poller.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/Poller.o: /home/huan/projects/EZMuduo/Poller.cc
CMakeFiles/EZmuduo.dir/Poller.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/EZmuduo.dir/Poller.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/Poller.o -MF CMakeFiles/EZmuduo.dir/Poller.o.d -o CMakeFiles/EZmuduo.dir/Poller.o -c /home/huan/projects/EZMuduo/Poller.cc

CMakeFiles/EZmuduo.dir/Poller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/Poller.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/Poller.cc > CMakeFiles/EZmuduo.dir/Poller.i

CMakeFiles/EZmuduo.dir/Poller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/Poller.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/Poller.cc -o CMakeFiles/EZmuduo.dir/Poller.s

CMakeFiles/EZmuduo.dir/Socket.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/Socket.o: /home/huan/projects/EZMuduo/Socket.cc
CMakeFiles/EZmuduo.dir/Socket.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/EZmuduo.dir/Socket.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/Socket.o -MF CMakeFiles/EZmuduo.dir/Socket.o.d -o CMakeFiles/EZmuduo.dir/Socket.o -c /home/huan/projects/EZMuduo/Socket.cc

CMakeFiles/EZmuduo.dir/Socket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/Socket.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/Socket.cc > CMakeFiles/EZmuduo.dir/Socket.i

CMakeFiles/EZmuduo.dir/Socket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/Socket.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/Socket.cc -o CMakeFiles/EZmuduo.dir/Socket.s

CMakeFiles/EZmuduo.dir/Thread.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/Thread.o: /home/huan/projects/EZMuduo/Thread.cc
CMakeFiles/EZmuduo.dir/Thread.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/EZmuduo.dir/Thread.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/Thread.o -MF CMakeFiles/EZmuduo.dir/Thread.o.d -o CMakeFiles/EZmuduo.dir/Thread.o -c /home/huan/projects/EZMuduo/Thread.cc

CMakeFiles/EZmuduo.dir/Thread.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/Thread.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/Thread.cc > CMakeFiles/EZmuduo.dir/Thread.i

CMakeFiles/EZmuduo.dir/Thread.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/Thread.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/Thread.cc -o CMakeFiles/EZmuduo.dir/Thread.s

CMakeFiles/EZmuduo.dir/Timestamp.o: CMakeFiles/EZmuduo.dir/flags.make
CMakeFiles/EZmuduo.dir/Timestamp.o: /home/huan/projects/EZMuduo/Timestamp.cc
CMakeFiles/EZmuduo.dir/Timestamp.o: CMakeFiles/EZmuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/EZmuduo.dir/Timestamp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EZmuduo.dir/Timestamp.o -MF CMakeFiles/EZmuduo.dir/Timestamp.o.d -o CMakeFiles/EZmuduo.dir/Timestamp.o -c /home/huan/projects/EZMuduo/Timestamp.cc

CMakeFiles/EZmuduo.dir/Timestamp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EZmuduo.dir/Timestamp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huan/projects/EZMuduo/Timestamp.cc > CMakeFiles/EZmuduo.dir/Timestamp.i

CMakeFiles/EZmuduo.dir/Timestamp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EZmuduo.dir/Timestamp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huan/projects/EZMuduo/Timestamp.cc -o CMakeFiles/EZmuduo.dir/Timestamp.s

# Object files for target EZmuduo
EZmuduo_OBJECTS = \
"CMakeFiles/EZmuduo.dir/Acceptor.o" \
"CMakeFiles/EZmuduo.dir/Channel.o" \
"CMakeFiles/EZmuduo.dir/CurrentThread.o" \
"CMakeFiles/EZmuduo.dir/DefaultPoller.o" \
"CMakeFiles/EZmuduo.dir/EpollPoller.o" \
"CMakeFiles/EZmuduo.dir/EventLoop.o" \
"CMakeFiles/EZmuduo.dir/InetAddress.o" \
"CMakeFiles/EZmuduo.dir/Logger.o" \
"CMakeFiles/EZmuduo.dir/Poller.o" \
"CMakeFiles/EZmuduo.dir/Socket.o" \
"CMakeFiles/EZmuduo.dir/Thread.o" \
"CMakeFiles/EZmuduo.dir/Timestamp.o"

# External object files for target EZmuduo
EZmuduo_EXTERNAL_OBJECTS =

/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/Acceptor.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/Channel.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/CurrentThread.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/DefaultPoller.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/EpollPoller.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/EventLoop.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/InetAddress.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/Logger.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/Poller.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/Socket.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/Thread.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/Timestamp.o
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/build.make
/home/huan/projects/EZMuduo/lib/libEZmuduo.so: CMakeFiles/EZmuduo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huan/projects/EZMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared library /home/huan/projects/EZMuduo/lib/libEZmuduo.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EZmuduo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EZmuduo.dir/build: /home/huan/projects/EZMuduo/lib/libEZmuduo.so
.PHONY : CMakeFiles/EZmuduo.dir/build

CMakeFiles/EZmuduo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EZmuduo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EZmuduo.dir/clean

CMakeFiles/EZmuduo.dir/depend:
	cd /home/huan/projects/EZMuduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huan/projects/EZMuduo /home/huan/projects/EZMuduo /home/huan/projects/EZMuduo/build /home/huan/projects/EZMuduo/build /home/huan/projects/EZMuduo/build/CMakeFiles/EZmuduo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EZmuduo.dir/depend

