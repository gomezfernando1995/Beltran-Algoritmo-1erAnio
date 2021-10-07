Algoritmo tp_Integrador_GomezFernando
	
	Definir patente Como Caracter; 
	Definir tipoVehiculo,hora,contadorMoto,contadorTotal Como Entero; 
	Definir precio,recaudacion,porcentajeMoto  Como Real; 
	precio<-0;
	recaudacion<-0;
	contadorMoto<-0;
	contadorTotal <- 0;
	
	Repetir 
		
		Escribir " ------------------------------------------------------------------------";
		Escribir  "      Bienvenido ingrese patente /o para salir ingrese FIN ";
		Leer patente; 
		Escribir " ------------------------------------------------------------------------";
		
		si(patente<>'FIN') 
			Escribir "  Elija -> 1-Auto   2-Moto   3-Camioneta";
			Leer tipoVehiculo; 
			Mientras  (tipoVehiculo<1 o tipoVehiculo>3) 
				Escribir "Reingrese tipo de vehiculo"; 
				Leer tipoVehiculo; 
			FinMientras 
			Escribir " ------------------------------------------------------------------------";
			Escribir "  Ingrese Hora en formato de 24 hs : ";
			Leer hora; Mientras (hora<0 o hora>23 ) 
				Escribir "Reingrese hora:" ;
				Leer hora; 
			FinMientras 
			Escribir " ------------------------------------------------------------------------";
			Segun tipoVehiculo Hacer 
				1: 
					si (hora >=9 y hora<=18) 
						precio<-100+(100*0.5); 
						Escribir " ------------------------------------------------------------------";
						Escribir "|  Patente: ",patente,"  | Tipo: Auto  | Valor de peaje abonado :",precio,"$   |";
						Escribir " ------------------------------------------------------------------";
					SiNo
						precio<-100
						Escribir " ------------------------------------------------------------------";
						Escribir "|  Patente: ",patente,"  | Tipo: Auto  | Valor de peaje abonado:",precio,"$  |";
						Escribir " ------------------------------------------------------------------";
					FinSi 
				2: 
					si (hora >=9 y hora<=18) 
						precio<-50+(50*0.5); 
						Escribir " ------------------------------------------------------------------";
						Escribir "|  Patente: ",patente,"  | Tipo: Moto  | Valor de peaje abonado:",precio,"$    |";
						Escribir " ------------------------------------------------------------------";
					SiNo
						precio<-50
						Escribir " ------------------------------------------------------------------";
						Escribir "|  Patente: ",patente,"  | Tipo: Moto  | Valor de peaje abonado:",precio,"$   |";
						Escribir " ------------------------------------------------------------------";
					FinSi 
					contadorMoto <-contadorMoto+1;
				3:	
					si (hora >=9 y hora<=18) 
						precio<-150+(150*0.5); 
						Escribir " ---------------------------------------------------------------------";
						Escribir "|  Patente: ",patente,"  | Tipo: Camioneta  | Valor de peaje abonado:",precio,"$  |";
						Escribir " ---------------------------------------------------------------------";
					SiNo
						precio<-150;
						Escribir " ------------------------------------------------------------------";
						Escribir "|  Patente: ",patente,"  | Tipo: Camioneta  | Valor de peaje abonado:",precio,"$ |";
						Escribir " ------------------------------------------------------------------";
					FinSi 
			Fin Segun 
			recaudacion <- recaudacion+precio;
			contadorTotal<-contadorTotal+1;
		FinSi
	Hasta Que (patente=='FIN');
	
	si(contadorMoto>0) Entonces
		porcentajeMoto <- (contadorMoto/contadorTotal)*100;
		Escribir "   ---------------------------------------------------";
		Escribir "  |    Porcentaje De Motos ingresadas: ",porcentajeMoto,"%         |";
		Escribir "   ---------------------------------------------------";
	FinSi
	
	SI(precio>1)
		Escribir "     ---------------------------------------------";
		Escribir "    |        Recaudacion total: ",recaudacion,"$              |";
		Escribir "     ---------------------------------------------";
		Escribir "";
		Escribir "  Alumno: Gomez Fernando Gabriel   Curso: 1ro 1ra";
	SiNo
		Escribir "   ------------------------------------------";
		Escribir "  |      No hubo recaudaciones en el dia     |";
		Escribir "   ------------------------------------------";
		Escribir "";
		Escribir " Alumno: Gomez Fernando Gabriel	Curso: 1ro 1ra";
	FinSi
	
FinAlgoritmo



