Algoritmo PuntoTres
	
	Definir number,bandera,banderaDos,unSoloDigito,esImpar,estaEnAmbosGrupos,noEstaEnNingunGrupo Como Entero;
	unSoloDigito<- 0;
	esImpar<- 0;
	estaEnAmbosGrupos<- 0;
	noEstaEnNingunGrupo<- 0;
	
	Para i<-0 Hasta 9 Con Paso paso Hacer 
		bandera <-0;
		banderaDos<-0;
		i<-i+1;
		Escribir "Ingrese Numero: ";
		Leer number;
		
		Si (number>-10 Y number<10) Entonces
			unSoloDigito<-unSoloDigito+1;
			bandera<-1;
		FinSi
		
		Si (!(number MOD 2=0))Entonces
			esImpar:=esImpar+1;
			banderaDos<-1;
		FinSi
		
		Si(bandera=1 Y banderaDos=1)Entonces
			estaEnAmbosGrupos := estaEnAmbosGrupos+1;
		FinSi
		
		Si((bandera=0 Y banderaDos=0))Entonces
			
			noEstaEnNingunGrupo<-noEstaEnNingunGrupo+1;
		FinSi
		
		
	Fin Para
	
	escribir "UnSoloDigito: ",unSoloDigito,".  EsImpar: ",esImpar," .    EstaEnAmbosGrupos: ",estaEnAmbosGrupos," . NoEstaEnNingunGrupo: ",noEstaEnNingunGrupo;
	
FinAlgoritmo
			