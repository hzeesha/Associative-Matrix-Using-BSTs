all:
	gcc -o mymatrix datatype.c bstree.c matrix.c main.c
	./mymatrix
clean:
	rm mymatrix
