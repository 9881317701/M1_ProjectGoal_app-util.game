PROJ_NAME= MyDiary
SRC= main.c src/addrecord.c src/deleterecord.c src/editrecord.c src/record.c src/viewrecord.c

TEST_SRC=test_diary.c unity.c src/addrecord.c src/deleterecord.c src/editrecord.c src/record.c src/viewrecord.c
 
ifdef OS
	RM = del /q
	FixPath = $(subst /,\,$1)
	EXEC = exe 
else
	ifeq ($(shell uname),Linux)
		RM = rm -rf
		FixPath = $1
		EXEC = out
	endif
endif
INC=-ISRC

Build:
	gcc $(SRC) 	$(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm
run:Build
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

Build_test:
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm
run_test:Build_test
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

staticcheck:
	cppcheck --enable=all -iunity .
dynamiccheck: Build
	valgrind ./$(call FixPath,$(PROJ_NAME).$(EXEC))