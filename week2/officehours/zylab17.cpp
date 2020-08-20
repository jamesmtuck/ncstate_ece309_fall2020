#include <stdio.h>

int main()
{
  // it assumes the input will be less than 1000 characters
  // on a line
  char array[1000];
  char reverse[1000];
  int i=0;
  
  while(1) {
    i = 0;
    
    while ( EOF != scanf("%c",array+i) ) {      
      i++;
      if (array[i-1]=='\n')
	break;
    }
    
    if ( array[0] == 'q' )
      break;

    
    for(int k=0,j=i-2; j>=0; j--,k++)
      reverse[k] = array[j];

    reverse[i-1] = 0;

    printf("%s\n",reverse);
  }
  
  return 0;
}
