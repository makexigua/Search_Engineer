SRCS:=$(wildcard src/*.cc)  #使用 wildcard 函数获取 src/ 目录下所有 .cc 源文件
OBJS:=$(patsubst src/%.cc,objs/%.o, $(SRCS))  #使用 patsubst 函数将源文件路径转换为目标文件路径
OUT:=page

CC = g++

#使用 g++ 链接所有 .o 文件
$(OUT): $(OBJS)
	$(CC) $(OBJS) -g -o $@   

#编译单个 .cc 文件生成对应的 .o 文件
objs/%.o: src/%.cc  
	@$(CC) -c $^    -o $@   


.PHONY: clean rebuild print 

clean: 
	rm -f $(OBJS)
	
rebuild: clean $(OUT)

print:
	echo $(OBJS)



