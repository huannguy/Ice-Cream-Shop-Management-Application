# Huan Nguyen
# huannguy@pdx.edu

CC = g++

FLAGS = -std=c++17 -g -Wall

TARGETS = a.out

SOURCES = main.cpp hierarchy.cpp tree.cpp
OBJS = main.o hierarchy.o tree.o menu.o

all: $(TARGETS)

# $@ is the target filename
# $* is the basename of the target filename
# $^ is the names of all the prerequisites
# $< is the name of the first dependency
# $? is the names of all prerequisites that are newer than the target

a.out: $(OBJS)
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.cpp menu.h
	$(CC) -c $< $(FLAGS)

menu.o: menu.cpp menu.h tree.h
	$(CC) -c $< $(FLAGS)

tree.o: tree.cpp tree.h hierarchy.h
	$(CC) -c $< $(FLAGS)

hierarchy.o: hierarchy.cpp hierarchy.h
	$(CC) -c $< $(FLAGS)


#Non-build commands
############################################################################## 

.PHONY: clean cls ci git get zip tar

clean cls:
	rm -f *.o $(TARGETS) *.lst *.zip *.tar.gz
	rm -f *~ \#*

ci:
	if [ ! -d RCS ]; then mrdir RCS; fi
	ci -t-none -l -m "Lab0 backup" [Mm]akefile *.[ch] *.asm
	
git get:
	if [ ! -d .git ]; then git init; fi
	git add *.[ch] *.asm ?akefile
	git commit -m "Lab0 backup"

# .zip and .tar files
# ##########################################################################
ASSIGNMENT = program3
ZIP_FILE = $(ASSIGNMENT).zip

zip: 
	rm -f $(ZIP_FILE)
	zip $(ZIP_FILE) *.cpp *.h *.md [Mm]akefile
	unzip -lv $(ZIP_FILE)

TAR_FILE = huannguy_$(ASSIGNMENT).tar.gz

tar:
	rm -f $(TAR_FILE)
	tar cvzf $(TAR_FILE) *.[ch] [Mm]akefile

