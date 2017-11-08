#include<stdlib.h>
#include<stdio.h>

//Funcion que ocupa el tablero
  void
lim (char **tablero, int tam) 
{
  int i, j;
  for (i = 0; i < tam; i++)
    
    {
      for (j = 0; j < tam; j++)
	
	{
	  tablero[i][j] = '|';
	}
    }
}


//Revisa que no se encuentre ningun otro W 
  int
checarRec (int tam, char **tablero, int a, int b) 
{
  int retornar = 0, i;
  for (i = 0; i < b; ++i)
    
    {
      if (tablero[a][i] == 87)
	
	{
	  retornar = 1;
	  break;
	}
    }
  return retornar;
}

int
checarDia (int tam, char **tablero, int a, int b) 
{
  int retornar = 0, i;
   
    //Para abajo
    for (i = 1; a + i < tam && b - i >= 0; i++)
    
    {
      if (tablero[a + i][b - i] == 87)
	
	{
	  retornar = 1;
	}
    }
  
    //Para arriba
    for (i = 1; a - i >= 0 && b - i >= 0; i++)
    
    {
      if (tablero[a - i][b - i] == 87)
	
	{
	  retornar = 1;
	}
    }
  return retornar;
}


//Llena el tablero
  void
desplegar (int tam, char **tablero, int a, int b)
{
  int i, j;
  
    //Desplegar
    //Liberar la memoria que nos se usa
    for (i = 0; i < tam; ++i)
    
    {
      for (j = 0; j < tam; ++j)
	
	{
	  if (tablero[i][j] == 87)
	    {
	      printf ("%c", tablero[i][j]);
	      printf (" ");
	    }
	  
	  else if (a == i && b == j)
	    {
	      printf ("W");
	      printf (" ");
	    }
	  
	  else
	    {
	      printf ("%c", 220);
	      printf (" ");
	    }
	}
      printf ("\n");
    }
  printf ("\n\n");
  return;
}


//funcion que coloca las reinas
  int
colreinas (int tam, char **tablero, int a, int b, int dama, int sol) 
{
  int i;
  if (dama == tam && a + 1 == tam && b + 1 == tam)
    
    {
      desplegar (tam, tablero, a, b);
      for (i = 0; i < tam; ++i)
	
	{
	  free (tablero[i]);
	}
      free (tablero);
    }
  
  else if (dama == tam && a + 1 != tam && b + 1 != tam)
    
    {
      printf ("Solucion\n");
      sol++;
      desplegar (tam, tablero, a, b);
    }
  if (a < tam && b < tam)
    
    {
      desplegar (tam, tablero, a, b);
      if (checarDia (tam, tablero, a, b) == 0
	   && checarRec (tam, tablero, a, b) == 0)
	
	{
	  tablero[a][b] = 87;
	  dama++;
	  sol = colreinas (tam, tablero, 0, b + 1, dama, sol);
	  dama--;
	  tablero[a][b] = '1';
	  sol = colreinas (tam, tablero, a + 1, b, dama, sol);
	}
      
      else
	sol = colreinas (tam, tablero, a + 1, b, dama, sol);
    }
  return sol;
}

 
//Menu principal
  int
main () 
{
  int i, j, tam, sol = 0;
  char **tablero;
  printf ("Cuantas reinas deseas colocar:");
  scanf ("%i", &tam);
  
    //Se reserva espacio para el tablero
    tablero = (char **) malloc (tam * sizeof (char *));
  for (i = 0; i < tam; i++)
    
    {
      tablero[i] = (char *) malloc (tam * sizeof (char));
    } 
    //Se limpia el tablero
    lim (tablero, tam);
  
    //Funcion que coloca reinas
    sol = colreinas (tam, tablero, 0, 0, 0, 0);
  printf ("\n");
  printf ("\nEl numero de soluciones es:%d", sol);
  system ("pause");
  return 0;
}


