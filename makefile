



all :  main.o appli.o  etud.o  
	gcc -o prog main.o appli.o etud.o

main.o :
	gcc -c -Wall main.c

appli.o :
	gcc -c -Wall appli.c

etud.o :
	gcc -c -Wall etud.c


clean :
	rm -f prog *.o     


