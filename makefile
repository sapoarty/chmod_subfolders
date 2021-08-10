all: main.c chmod_files_rec.c
	gcc -o chmod_files.exe main.c chmod_files_rec.c -I
