#include<stdlib.h>
#include<stdio.h>

//Funcion que ocupa el tablero
  void
lim (char **tablero, int tam) 
{
  
  
    
    {
      
	
	{
	  
	
    



//Revisa que no se encuentre ningun otro W 
  int
checarRec (int tam, char **tablero, int a, int b) 
{
  
  
    
    {
      
	
	{
	  
	  
	
    
  



checarDia (int tam, char **tablero, int a, int b) 
{
  
  
    //Para abajo
    for (i = 1; a + i < tam && b - i >= 0; i++)
    
    {
      
	
	{
	  
	
    
  
    //Para arriba
    for (i = 1; a - i >= 0 && b - i >= 0; i++)
    
    {
      
	
	{
	  
	
    
  



//Llena el tablero
  void
desplegar (int tam, char **tablero, int a, int b)
{
  
  
    //Desplegar
    //Liberar la memoria que nos se usa
    for (i = 0; i < tam; ++i)
    
    {
      
	
	{
	  
	    {
	      
	      
	    
	  
	  else if (a == i && b == j)
	    {
	      
	      
	    
	  
	  else
	    {
	      
	      
	    
	
      
    
  
  



//funcion que coloca las reinas
  int
colreinas (int tam, char **tablero, int a, int b, int dama, int sol) 
{
  
  
    
    {
      
      
	
	{
	  
	
      
    
  
  else if (dama == tam && a + 1 != tam && b + 1 != tam)
    
    {
      
      
      
    
  
    
    {
      
      
	   && checarRec (tam, tablero, a, b) == 0)
	
	{
	  
	  
	  
	  
	  
	  
	
      
      else
	
    
  



//Menu principal
  int
main () 
{
  
  
  
  
  
    //Se reserva espacio para el tablero
    tablero = (char **) malloc (tam * sizeof (char *));
  
    
    {
      
    
    //Se limpia el tablero
    lim (tablero, tam);
  
    //Funcion que coloca reinas
    sol = colreinas (tam, tablero, 0, 0, 0, 0);
  
  
  
  


