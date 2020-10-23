#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // take the average of the values of RGB
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // set the value of R, G and B to the average pixel value
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // using the given formulas
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            // if formula gives value > 255 then value = 255

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // changing the original values to sepia values
            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtRed = round(sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tempBlue[width];
    int tempGreen[width];
    int tempRed[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //swap blue pixel data
            tempBlue[j] = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = tempBlue[j];

            //swap green pixel data
            tempGreen[j] = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = tempGreen[j];

            //swap red pixel data
            tempRed[j] = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = tempRed[j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*blur_image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    int sum = 0;
    int num = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // average of blue surrounding pixels
            sum = image[i][j].rgbtBlue;
            num = 1;
            // checking top pixel
            if (i - 1 >= 0)
            {
                sum += image[i - 1][j].rgbtBlue;
                num ++;
            }
            // checking bottom pixel
            if (i + 1 < height)
            {
                sum += image[i + 1][j].rgbtBlue;
                num ++;
            }
            // checking left pixel
            if (j - 1 >= 0)
            {
                sum += image[i][j - 1].rgbtBlue;
                num ++;
            }
            // checking right pixel
            if (j + 1 < width)
            {
                sum += image[i][j + 1].rgbtBlue;
                num ++;
            }
            // checking top-left pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum += image[i - 1][j - 1].rgbtBlue;
                num ++;
            }
            // checking top-right pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                sum += image[i - 1][j + 1].rgbtBlue;
                num ++;
            }
            // checking bottom-left pixel
            if (i + 1 < height && j - 1 >= 0)
            {
                sum += image[i + 1][j - 1].rgbtBlue;
                num ++;
            }
            // checking bottom-right pixel
            if (i + 1 < height && j + 1 < width)
            {
                sum += image[i + 1][j + 1].rgbtBlue;
                num ++;
            }

            blur_image[i][j].rgbtBlue = round((float)sum / (float)num);



            // ==================================
            // average of green surrounding pixels
            // ==================================
            sum = image[i][j].rgbtGreen;
            num = 1;
            // checking top pixel
            if (i - 1 >= 0)
            {
                sum += image[i - 1][j].rgbtGreen;
                num ++;
            }
            // checking bottom pixel
            if (i + 1 < height)
            {
                sum += image[i + 1][j].rgbtGreen;
                num ++;
            }
            // checking left pixel
            if (j - 1 >= 0)
            {
                sum += image[i][j - 1].rgbtGreen;
                num ++;
            }
            // checking right pixel
            if (j + 1 < width)
            {
                sum += image[i][j + 1].rgbtGreen;
                num ++;
            }
            // checking top-left pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum += image[i - 1][j - 1].rgbtGreen;
                num ++;
            }
            // checking top-right pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                sum += image[i - 1][j + 1].rgbtGreen;
                num ++;
            }
            // checking bottom-left pixel
            if (i + 1 < height && j - 1 >= 0)
            {
                sum += image[i + 1][j - 1].rgbtGreen;
                num ++;
            }
            // checking bottom-right pixel
            if (i + 1 < height && j + 1 < width)
            {
                sum += image[i + 1][j + 1].rgbtGreen;
                num ++;
            }

            blur_image[i][j].rgbtGreen = round((float)sum / (float)num);

            // ==================================
            // average of red surrounding pixels
            // ==================================
            sum = image[i][j].rgbtRed;
            num = 1;
            // checking top pixel
            if (i - 1 >= 0)
            {
                sum += image[i - 1][j].rgbtRed;
                num ++;
            }
            // checking bottom pixel
            if (i + 1 < height)
            {
                sum += image[i + 1][j].rgbtRed;
                num ++;
            }
            // checking left pixel
            if (j - 1 >= 0)
            {
                sum += image[i][j - 1].rgbtRed;
                num ++;
            }
            // checking right pixel
            if (j + 1 < width)
            {
                sum += image[i][j + 1].rgbtRed;
                num ++;
            }
            // checking top-left pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum += image[i - 1][j - 1].rgbtRed;
                num ++;
            }
            // checking top-right pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                sum += image[i - 1][j + 1].rgbtRed;
                num ++;
            }
            // checking bottom-left pixel
            if (i + 1 < height && j - 1 >= 0)
            {
                sum += image[i + 1][j - 1].rgbtRed;
                num ++;
            }
            // checking bottom-right pixel
            if (i + 1 < height && j + 1 < width)
            {
                sum += image[i + 1][j + 1].rgbtRed;
                num ++;
            }

            blur_image[i][j].rgbtRed = round((float)sum / (float)num);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = blur_image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = blur_image[i][j].rgbtGreen;
            image[i][j].rgbtRed = blur_image[i][j].rgbtRed;
        }
    }


    return;
}
