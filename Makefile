blr: main.c
	gcc main.c -o blr

.PHONY: install

install: main.c
	gcc main.c -o blr
	install blr /usr/bin/.
