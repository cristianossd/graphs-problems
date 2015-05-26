all:
	gcc -g go_and_come/main.c -o gc.out
	gcc -g energy-transmission/main.c -o et.out
	gcc -g toll_road/main.c -o tr.out
	g++ toll_road/main.cpp -lstdc++ -o tr0.out
	gcc -g monitoring_amazon/main.cpp -o ma.out
	gcc -g lost_elf/main.c -o le.out
	gcc -g optical_network/main.c -o on.out
