KDIR = /lib/modules/`uname -r`/build

kbuild:
	gcc -o firewall firewall.c

clean:
	rm -f firewall
