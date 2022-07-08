#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen +image[i][j].rgbtRed) / 3.00);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void swap(RGBTRIPLE* a, RGBTRIPLE* b);
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            swap(&image[i][j], &image[i][width-1-j]);
        }
    }

    return;
}

void swap(RGBTRIPLE* a, RGBTRIPLE* b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            temp[i][j] = image[i][j];
        }
    }

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                float sum_red = 0;
                float sum_blue = 0;
                float sum_green = 0;
                int counter = 0;

                for(int k = -1; k < 2; k++){
                    for(int l = -1; l < 2; l++){

                        if( i + k < 0 || i + k > height - 1 || j + l < 0 || j + l > width - 1){
                            continue;
                        }
                        else{
                            sum_red += temp[i + k][j + l].rgbtRed;
                            sum_green += temp[i + k][j + l].rgbtGreen;
                            sum_blue += temp[i + k][j + l].rgbtBlue;
                            counter++;
                        }
                    }
                }
                image[i][j].rgbtRed = round(sum_red / counter);
                image[i][j].rgbtGreen = round(sum_green / counter);
                image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create duplicate
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            temp[i][j] = image[i][j];
        }
    }

    //sobel kernel value
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    //loop through each pixel
    for(int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            float sum_Gx_Blue = 0;
            float sum_Gx_Green = 0;
            float sum_Gx_Red = 0;
            float sum_Gy_Blue = 0;
            float sum_Gy_Green = 0;
            float sum_Gy_Red = 0;

            for(int k = -1; k < 2; k++){
                for(int l = -1; l < 2; l++){
                    if(i + k < 0 || i + k > height - 1 || j + l < 0 || j + l > width - 1){
                        continue;
                    }
                    else{
                        sum_Gx_Blue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                        sum_Gy_Blue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                        sum_Gx_Green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        sum_Gy_Green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                        sum_Gx_Red += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                        sum_Gy_Red += temp[i + k][j + l].rgbtRed *Gy[k + 1][l +1];
                    }
                }
            }
            int blue = round(sqrt(sum_Gx_Blue * sum_Gx_Blue + sum_Gy_Blue * sum_Gy_Blue));
            int green = round(sqrt(sum_Gx_Green * sum_Gx_Green + sum_Gy_Green * sum_Gy_Green));
            int red = round(sqrt(sum_Gx_Red * sum_Gx_Red + sum_Gy_Red * sum_Gy_Red));

            // cap at 255 max pixel value
            if(blue > 255){
                blue = 255;
            }
            if(green > 255){
                green = 255;
            }
            if(red > 255){
                red = 255;
            }

            //set final pixel value
            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;
        }
    }


    return;
}
