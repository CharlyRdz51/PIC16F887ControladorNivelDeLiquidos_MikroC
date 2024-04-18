#line 1 "C:/Users/master/Desktop/SeminarioSensores/Practica1.c"
#line 12 "C:/Users/master/Desktop/SeminarioSensores/Practica1.c"
void main () {
set_tris_A(0x2F);
setup_oscillator(OSC_8MHZ);
lcd_init ();
lcd_putc('\f');
lcd_gotoxy (4, 1);
lcd_putc("Tanque");
delay_ms (2000);
lcd_putc('\f');
lcd_gotoxy (3, 1);
lcd_putc("Tanque");
int bandera, bandera2, bandera3;
bandera=1;
bandera2=1;
bandera3=1;
while(TRUE) {
if (input(PIN_A0) ==0) {
lcd_gotoxy (3, 2);
printf (lcd_putc, "Tanque vacio");
}
if (input(PIN_A0) ==1 && bandera==1) {
lcd_gotoxy (3, 2);
printf (lcd_putc, "Tanque Bajo");
}
if(input(PIN_A1) ==1 && bandera2==1) {
bandera=2;
lcd_gotoxy (3, 2);
printf (lcd_putc, "Tanque Medio");
}
else {
bandera=1;
}
if (input(PIN_A2) ==1 && bandera3==1) {
bandera=2;
bandera2=2;
lcd_gotoxy (3, 2);
printf (lcd_putc, "Tanque lleno");
}
else {
bandera2=1;
}
if (input(PIN_A3) ==1 && input(PIN_A4) ==1) {
output_high(pin_a5);
}
else{
output_low(pin_a5);
}
delay_ms (100);
}
}
