all:
	./compile
deb: all
	rm -rf ./deb/bin
	mkdir ./deb/bin
	cp -R ./binary/ ./deb/bin/
	rm ./deb/bin/README
	nano ./deb/DEBIAN/control
	dpkg -b deb
	mv deb.deb sgticket.deb
clean:
	rm -rf build
	rm -rf *.deb
