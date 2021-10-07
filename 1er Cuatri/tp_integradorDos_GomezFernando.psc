Algoritmo TPIntegrador2
	Definir nota, porcentajeMujer, porcentajeHombre Como Real;
	Definir contadorHombre,contadorMujer Como Entero;
	Definir genero Como Caracter;
	contadorHombre<-0;
	contadorMujer<-0;
	
	Para i<-0 Hasta 9 Con Paso i Hacer
		Escribir "--------------------------------------------------------------------------"
		Escribir "Nota Alumno?";
		Leer nota;
		Mientras (nota<0 o nota>10)
			Escribir "Reingrese nota"
			Leer nota;
		FinMientras
		Escribir "Genero? F para femenino o M para masculino"
		Leer genero
		Mientras (!(genero="F" o genero="M"))
			Escribir "Reingrese genero, F para femenino o M para masculino"
			Leer genero
		FinMientras
		
		si(genero="F" y nota>3)
			contadorMujer<-contadorMujer+1;
		sino
			si(genero="M" y nota>3)
				contadorHombre<-contadorHombre+1;
			FinSi
		FinSi
		i<-i+1
	Fin Para
	
	porcentajeMujer<-(contadorMujer/10)*100;
	porcentajeHombre<-(contadorHombre/10)*100;
	Escribir "-----------------------------------------------------------------------------------"
	Si(contadorMujer>0 y contadorHombre>0)
		Escribir "Femeninos Aprobados ",porcentajeMujer,"% , Masculinos Aprobados ",porcentajeHombre,"%";
	SiNo
		si(contadorMujer>0 Y contadorHombre=0)
			Escribir"Femeninos Aprobados ",porcentajeMujer,"% , No aprobo ningun masculino o no se ingresaron masculinos";
		SiNo
			si(contadorHombre>0 y contadorMujer=0)
				Escribir"Masculinos Aprobados ",porcentajeHombre,"%, No aprobo ningun Femenino  o no se ingresaron Femeninos";
			SiNo
				Escribir "Ningun alumno aprobo"
			FinSi
		FinSi
	FinSi
FinAlgoritmo
