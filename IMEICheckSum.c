/*
The last number of the IMEI is a check digit. The Check Digit is calculated according to Luhn formula.

The Check Digit is a function of all other digits in the IMEI. The purpose of the Check Digit is to help guard against the possibility of incorrect entries to the CEIR and EIR equipment.

The check digit is validated in three steps:

Starting from the right, double a digit every two digits (e.g., 5 → 10).
Sum the digits (e.g., 10 → 1+0).
Check if the sum is divisible by 10.
Conversely, one can calculate the IMEI by choosing the check digit that would give a sum divisible by 10.
For example:

IMEI: 35145120840121

(5x2, 4x2, 1x2, 0x2, 4x2, 1x2, 1x2) = (10, 8, 2, 0, 8, 2, 2)
(1+0+8+2+0+8+2+2) + (3+1+5+2+8+0+2 ) = 44
Luhn Digit : 6
IMEI: 351451-20-840121-6
*/

#include <stdio.h>

int computerIMEIChecksum(char *digit)
{
    int         i;
    int         sum1=0,sum2=0,total=0;
    int         temp=0;
    int         checksum = 0;
    for( i=0; i<14; i++ )
    {
        if((i%2)==0)
        {
            sum1 = sum1 + digit[i] - '0';
        }
        else
        {
            temp = (digit[i]-'0')*2;
            if( temp < 10 )
            {
                sum2 = sum2 + temp;
            }
            else
            {
                sum2 = sum2 + 1 + temp - 10;
            }
        }
    }
    total = sum1 + sum2;
    if( (total%10) == 0 )
    {
        checksum = 0;
    }
    else
    {
        checksum =((total/10) * 10) + 10 - total;
    }
    return checksum;
}

int isValidIMEI(char *digit)
{
    if(computerIMEIChecksum(digit) == (digit[14] - '0'))
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
   char testIMEI[15]={'3','5','1','4','5','1','2','0','8','4','0','1','2','1','6'};
   if(isValidIMEI(testIMEI) )
   {
       printf("Valid IMEI\n");
   }
   else
   {
       printf("Invalid IMEI\n");
   }
   return 0;
}
