Target	:= compton_liye_1
cc	:= g++

source	:= compton_liye_1.C

cflags 	:= $(shell root-config --cflags)
libs	:= $(shell root-config --libs)
glibs	:= $(shell root-config --glibs)

flags	:= ${cflags} ${libs} ${glibs}

${Target}:${source}
	@echo Making...
	@$(cc) -o ${Target} ${source} ${flags}

clean:
	@rm -rf ${Target}
