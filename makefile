mycp: mycp.o copy_files.o make_report.o
	gcc mycp.o copy_files.o make_report.o -o mycp

mycp.o: mycp.c copy_files.h make_report.h
	gcc -c -Wall mycp.c

copy_files.o: copy_files.c copy_files.h
	gcc -c -Wall copy_files.c

make_report.o: make_report.c copy_files.h
	gcc -c -Wall make_report.c

clean:
	rm -f *.o mycp
