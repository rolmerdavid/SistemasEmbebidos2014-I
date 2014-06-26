/*-------------------------------------------*\
 |	KBD2.C                                   |

 |  Autor: Pedro Mª Jiménez                  |

 |  (c) Microsystems Engineering (Bilbao)    |

\*-------------------------------------------*/



// Funciones para la gestión del teclado de la Trainer PLUS.



// char kbd_getc( )   Devuelve el código ASCII de la tecla pulsada.

//         Si no se pulsó ninguna, devuelve 0.





// Conexiones del teclado.

/* 

            RB0 RB1 RB2 RB3

             ^   ^   ^   ^

             |   |   |   |

           |---|---|---|---|

  RB4 ---> | 1 | 2 | 3 | F |

           |---|---|---|---|

  RB5 ---> | 4 | 5 | 6 | E |

           |---|---|---|---|

  RB6 ---> | 7 | 8 | 9 | D |

           |---|---|---|---|

  RB7 ---> | A | 0 | B | C |

           |---|---|---|---|

*/



// Caracteres ASCII asociados a cada tecla:

char const KEYS[4][4] = {{'1','2','3','F'} ,

                         {'4','5','6','E'} ,

                         {'7','8','9','D'} ,

                         {'A','0','B','C'} };



#byte kbd_port_b = 6





char kbd_getc( )

{

  char tecla=0;

  int f,c,t,i,j;



  port_b_pullups(true);

  set_tris_b(0b00001111); // RB7-RB4 salidas, RB3-RB0 entradas



  for(f=0x10, i=0; i<4; f<<=1, i++)

  {

    for(c=0x01, j=0; j<4; c<<=1, j++)

    {

      kbd_port_b = ~f;

      delay_cycles(1);

      t = kbd_port_b & 0x0F;

      t = ~(t | 0xF0 );

      if(t == c)

      {

        delay_ms(20);

        tecla=KEYS[i ][j ];

        while(t==c)

        {

          restart_wdt( );

          t = kbd_port_b & 0x0F;

          t = ~(t | 0xF0) ;

        }

        break;

      }

    }

    if(tecla)

      break;

  }



  port_b_pullups(false);

  return tecla;

}
