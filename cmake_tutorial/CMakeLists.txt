PROJECT (HELLO)
# 将变量SRC_LIST赋值为要编译的文件
# SET(SRC_LIST IterAdapter.cpp)
# MESSAGE(STATUS "This is BINARY dir" ${HELLO_BINARY_DIR})
# MESSAGE(STATUS "This is SOURCE dir" ${HELLO_SOURCE_DIR})
# ADD_EXECUTABLE(IterAdapter ${SRC_LIST})

# 关联到子目录，子目录也有一个CMakeLists
# 生成的可执行文件会放到bin目录中去
ADD_SUBDIRECTORY(src bin)

# 下面开始安装的用法
INSTALL(FILE COPYRIGHT README ./home/zhangsx/C++prog)
INSTALL(PROGRAMS runhello.sh ./home/zhangsx/C++prog bin)