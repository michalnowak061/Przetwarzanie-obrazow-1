
__start__: przetwarzanie1
	./przetwarzanie1

przetwarzanie1: main.o obsluga_obrazu.o przetwarzanie_obrazu.o filtrowanie_obrazu.o
	gcc main.o obsluga_obrazu.o przetwarzanie_obrazu.o filtrowanie_obrazu.o -o przetwarzanie1

main.o: main.c obsluga_obrazu.h przetwarzanie_obrazu.h filtrowanie_obrazu.h
	gcc main.c -c -o main.o

obsluga_obrazu.o: obsluga_obrazu.h obsluga_obrazu.c
	gcc obsluga_obrazu.c -c -o obsluga_obrazu.o 

przetwarzanie_obrazu.o: przetwarzanie_obrazu.h przetwarzanie_obrazu.c
	gcc przetwarzanie_obrazu.c -c -o przetwarzanie_obrazu.o

filtrowanie_obrazu.o: filtrowanie_obrazu.h filtrowanie_obrazu.c
	gcc filtrowanie_obrazu.c -c -o filtrowanie_obrazu.o

clean:
	rm -f *.o przetwarzanie1

