#include <16f887.h>
#device *=16 adc =10
#FUSES HS, NOWDT, NOPUT, NOLVP
#use delay(clock =8M)
#include <lcd.h>
unsigned int16 GIA_TRI =0;

void main()
{
    set_tris_a(0x00);
    set_tris_d(0x00);
    set_tris_e(0xFF);
	set_tris_b(0x00);
    SETUP_ADC(ADC_CLOCK_INTERNAL);
    SETUP_ADC_PORTS(ALL_ANALOG);
    lcd_init();
    delay_ms(20);
    lcd_gotoxy(1,1);
    printf(lcd_putc,"AD10Bit");
    output_b(0x00);
    
    while(TRUE)
        {
        SET_ADC_CHANNEL(5);
        GIA_TRI=READ_ADC();
        lcd_gotoxy(9,1);
        printf(lcd_putc, "REO: %lu",GIA_TRI);
        if(GIA_TRI>50 && GIA_TRI <=150)
        {
            output_high(pin_b0);
            //printf(lcd_putc, "REO: %lu",GIA_TRI);    
        }
        else if(GIA_TRI>150 &&GIA_TRI<=250)
        {    
            output_b(0x03);
            //printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        else if(GIA_TRI >250 && GIA_TRI <=350)
        {    
            output_b(0x07);
            //printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        else if(GIA_TRI>350 &&GIA_TRI<=450)
        {    
            output_b(0x0F);
			//printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        else if(GIA_TRI>450 &&GIA_TRI<=550)
        {    
            output_b(0x1F);
			//printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        else if(GIA_TRI>550 &&GIA_TRI<=650)
        {    
            output_b(0x3F);
			//printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        else if(GIA_TRI>650 &&GIA_TRI<=750)
        {    
            output_b(0x7F);
			//printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        else if(GIA_TRI <50)
        {
            output_low(pin_b0);
            //printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        else{
            output_b(0xFF);
           // printf(lcd_putc, "REO: %lu",GIA_TRI);
        }
        
        GIA_TRI=GIA_TRI-GIA_TRI;
        SET_ADC_CHANNEL(6);
        GIA_TRI=READ_ADC(); 
        lcd_gotoxy(9,2);
        printf(lcd_putc, "RE1: %lu",GIA_TRI);
    }
}