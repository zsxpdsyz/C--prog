# 将文件夹下的文件分别编译为可执行文件
SOURCE := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %, $(SOURCE))


ALL : $(OBJS)
	@echo "Begin compile:"
	@echo $(SOURCE)

# 用百分号表示的通配符，表示将target文件列表中的每个文件单独拿出来编译
# 用星号的话则是在文件夹中查找。
# Makefile只会去编译第一个不含通配符的目标，因此如果没有前面的铺垫直接写后面这2行无法编译成功
% : %.cpp
	g++ $^ -o $@

clean:
	rm FunctionOp

.PHONY: clean