#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE average ;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0) ;

            image[i][j].rgbtBlue = average ;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average ;
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            RGBTRIPLE sepia = image[i][j] ;
            int sepiaRed = round(.393 * sepia.rgbtRed + .769 * sepia.rgbtGreen + .189 * sepia.rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round(.349 * sepia.rgbtRed + .686 * sepia.rgbtGreen + .168 * sepia.rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(.272 * sepia.rgbtRed + .534 * sepia.rgbtGreen + .131 * sepia.rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue ;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed ;


        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            RGBTRIPLE  *ptrr = &image[i][width - j - 1] ;
            RGBTRIPLE  *ptrl = &image[i][j] ;
            RGBTRIPLE  *ptr, pixel ;
            ptr = &pixel;
            if (width % 2 != 0)
            {
                int odd = round(width / 2.0);

                if (j < odd)
                {
                    *ptr = *ptrr ;
                    *ptrr = *ptrl ;
                    *ptrl = *ptr ;
                }
            }
            if (width % 2 == 0)
            {
                int even = (width / 2);

                if (j < even)
                {
                    *ptr = *ptrr ;
                    *ptrr = *ptrl ;
                    *ptrl = *ptr ;
                }

            }
        }
    }
    return;

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int row = 0 ; row < height  ; row++)
    {
        for (int col = 0 ; col < width ; col++)
        {
            int coory [] = {row - 1, row, row + 1};
            int coorx [] = {col - 1, col, col + 1};
            int count = 0 ;
            float totalB = 0, totalG = 0, totalR = 0 ;
            for (int c = 0 ; c < 3 ; c++)
            {
                for (int r = 0 ; r < 3 ; r++)
                {
                    int CurRow = coory [c];
                    int CurCol = coorx [r];
                    if (CurRow  >= 0 && CurRow < height && CurCol >= 0 && CurCol < width)
                    {
                        image[CurRow][CurCol];

                        totalB += image[CurRow][CurCol].rgbtBlue;
                        totalG += image[CurRow][CurCol].rgbtGreen;
                        totalR += image[CurRow][CurCol].rgbtRed;
                        count++;
                    }
                }
            }
            temp[row][col].rgbtBlue = round(totalB / count);
            temp[row][col].rgbtGreen = round(totalG / count);
            temp[row][col].rgbtRed = round(totalR / count);

        }

    }

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
