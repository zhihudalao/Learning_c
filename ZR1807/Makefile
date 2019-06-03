CC=gcc
OBJECT = obj/fruit_func.o obj/FruitLink.o obj/controller.o obj/view.o
FLAG = -I include -g -Wall

bin/fruit: ${OBJECT} src/main.c
	${CC}  ${OBJECT} src/main.c -o bin/fruit ${FLAG}
obj/fruit_func.o:src/fruit_func.c
	gcc -c src/fruit_func.c -o obj/fruit_func.o ${FLAG}
obj/FruitLink.o:src/FruitLink.c
	gcc -c src/FruitLink.c -o obj/FruitLink.o -g ${FLAG}
obj/view.o:src/view.c
	gcc -c src/view.c -o obj/view.o ${FLAG}
obj/controller.o:src/controller.c
	gcc -c src/controller.c -o obj/controller.o ${FLAG}

clean:
	rm obj/*.o
	rm bin/*
