ZarateJohnS6C2plots.py : datos.txt
	python ZarateJohnS6C2plots.py 
datos.txt:a.out
	./a.out >datos.txt
a.out: ZarateJohnS6C2.cpp
	g++ ZarateJohnS6C2.cpp
