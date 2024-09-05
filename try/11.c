#include <cs50.h>
#include <stdio.h>


int main (void)
{
    int number = get_int("enter number : \n");
    for (int counter1 = number ; counter1 >= 0 ; counter1-- )
{
    for (int counter2 = 1; counter2 <= counter1 ; counter2++ )
    {
        printf("%c", '*');
    }
    printf("\n");


}
printf("\n");
}


