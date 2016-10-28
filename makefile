test:
	gcc main.c -o test
	touch file.txt
run:
	./test

clear:
	rm file.txt test
