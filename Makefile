CC			:= gcc
C_FLAGS 	:= -g

SRC_DIR 	:= src/
BUILD_DIR 	:= build/
INCLUDE_DIR := include/

bin1:
	${CC} ${SRC_DIR}$@.c -o ${BUILD_DIR}$@ ${C_FLAGS} -I${INCLUDE_DIR}

tar:
	${CC} ${SRC_DIR}$@.c -o ${BUILD_DIR}$@ ${C_FLAGS} -I${INCLUDE_DIR}


all:
	make bin1
	make tar

clean:
	rm -rf build/*
