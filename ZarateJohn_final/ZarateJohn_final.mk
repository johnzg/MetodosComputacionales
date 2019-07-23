#PHONY.all
all: canal.png filtro.pdf
canal.png : ZarateJohn_canal_ionico.py
	python ZarateJohn_canal_ionico.py
    
filtro.pdf : ZarateJohn_Fourier.py
	python ZarateJohn_Fourier.py