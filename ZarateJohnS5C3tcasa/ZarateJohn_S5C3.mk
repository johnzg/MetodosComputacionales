ZarateJohn_S5C3_plots.py : datos.txt
	python ZarateJohn_S5C3_plots.py 
datos.txt:a.out
	./a.out >datos.txt
a.out: ZarateJohn_S5C3_ODEs.cpp
	g++ ZarateJohn_S5C3_ODEs.cpp
