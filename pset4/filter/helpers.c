//Filter
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int q, int g, RGBTRIPLE image[q][g])
{
    //scan through q
    for (int i = 0; i < q; i++)
    {
        //scan through g
        for (int j = 0; j < g; j++)
        {
            //add up the values for red, green, and blue into a float called total.
            float total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;

            //total divided by 3 and rounded creates an int called greyvalue
            int greyvalue = round(total / 3);

            //assign greyvalue to the red, green, and blue.
            image[i][j].rgbtRed = greyvalue;
            image[i][j].rgbtGreen = greyvalue;
            image[i][j].rgbtBlue = greyvalue;

        }
    }

    return;
}


void sepia(int q, int g, RGBTRIPLE image[q][g])
{
    //scan through q
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < g; j++)
        {
            float redred = 0.393 * image[i][j].rgbtRed;

            float redgreen = 0.769 * image[i][j].rgbtGreen;

            float redblue = 0.189 * image[i][j].rgbtBlue;

            float greenred = 0.349 * image[i][j].rgbtRed;

            float greengreen = 0.686 * image[i][j].rgbtGreen;

            float greenblue = 0.168 * image[i][j].rgbtBlue;

            float bluered = 0.272 * image[i][j].rgbtRed;

            float bluegreen = 0.534 * image[i][j].rgbtGreen;

            float blueblue = 0.131 * image[i][j].rgbtBlue;

            int sepiaRed = round(redred + redgreen + redblue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round(greenred + greengreen + greenblue);

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(bluered + bluegreen + blueblue);

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}
void reflect(int q, int g, RGBTRIPLE image[q][g])
{

    RGBTRIPLE image2[g];

    for (int i = 0; i < q; i++)
    {
        //scan through g
        for (int j = 0; j < g; j++)
        {

            image2[(g - 1) - j] = image[i][j];
        }

        for (int k = 0; k < g; k++)
        {

            image[i][k] = image2[k];
        }

    }

    return;
}


void blur(int q, int g, RGBTRIPLE image[q][g])
{
    RGBTRIPLE image2[q][g];


    for (int i = 1; i < q - 1; i++)
    {
        for (int j = 1; j < g - 1; j++)
        {
            float centerredtotal =
                image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;

            float centergreentotal =
                image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;

            float centerbluetotal =
                image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;

            int centerredblur = (int) round(centerredtotal / 9);
            int centergreenblur = (int) round(centergreentotal / 9);
            int centerblueblur = (int) round(centerbluetotal / 9);

            image2[i][j].rgbtRed = centerredblur;
            image2[i][j].rgbtGreen = centergreenblur;
            image2[i][j].rgbtBlue = centerblueblur;
        }
    }



    for (int i = 1; i < g - 1; i++)
    {
        float northredtotal =
            image[0][i - 1].rgbtRed + image[0][i].rgbtRed + image[0][i + 1].rgbtRed +
            image[1][i - 1].rgbtRed + image[1][i].rgbtRed + image[1][i + 1].rgbtRed;

        float northgreentotal =
            image[0][i - 1].rgbtGreen + image[0][i].rgbtGreen + image[0][i + 1].rgbtGreen +
            image[1][i - 1].rgbtGreen + image[1][i].rgbtGreen + image[1][i + 1].rgbtGreen;

        float northbluetotal =
            image[0][i - 1].rgbtBlue + image[0][i].rgbtBlue + image[0][i + 1].rgbtBlue +
            image[1][i - 1].rgbtBlue + image[1][i].rgbtBlue + image[1][i + 1].rgbtBlue;

        int northredblur = (int) round(northredtotal / 6);
        int northgreenblur = (int) round(northgreentotal / 6);
        int northblueblur = (int) round(northbluetotal / 6);

        image2[0][i].rgbtRed = northredblur;
        image2[0][i].rgbtGreen = northgreenblur;
        image2[0][i].rgbtBlue = northblueblur;
    }



    for (int i = 1; i < g - 1; i++)
    {
        float southredtotal =
            image[q - 2][i - 1].rgbtRed + image[q - 2][i].rgbtRed + image[q - 2][i + 1].rgbtRed +
            image[q - 1][i - 1].rgbtRed + image[q - 1][i].rgbtRed + image[q - 1][i + 1].rgbtRed;

        float southgreentotal =
            image[q - 2][i - 1].rgbtGreen + image[q - 2][i].rgbtGreen + image[q - 2][i + 1].rgbtGreen +
            image[q - 1][i - 1].rgbtGreen + image[q - 1][i].rgbtGreen + image[q - 1][i + 1].rgbtGreen;

        float southbluetotal =
            image[q - 2][i - 1].rgbtBlue + image[q - 2][i].rgbtBlue + image[q - 2][i + 1].rgbtBlue +
            image[q - 1][i - 1].rgbtBlue + image[q - 1][i].rgbtBlue + image[q - 1][i + 1].rgbtBlue;

        int southredblur = (int) round(southredtotal / 6);
        int southgreenblur = (int) round(southgreentotal / 6);
        int southblueblur = (int) round(southbluetotal / 6);

        image2[q - 1][i].rgbtRed = southredblur;
        image2[q - 1][i].rgbtGreen = southgreenblur;
        image2[q - 1][i].rgbtBlue = southblueblur;
    }



    for (int i = 1; i < q - 1; i++)
    {
        //combine the red, green and blue totals of the surrounding pixels
        float westredtotal =
            image[i - 1][0].rgbtRed + image[i - 1][1].rgbtRed +
            image[i][0].rgbtRed + image[i][1].rgbtRed +
            image[i + 1][0].rgbtRed + image[i + 1][1].rgbtRed;

        float westgreentotal =
            image[i - 1][0].rgbtGreen + image[i - 1][1].rgbtGreen +
            image[i][0].rgbtGreen + image[i][1].rgbtGreen +
            image[i + 1][0].rgbtGreen + image[i + 1][1].rgbtGreen;

        float westbluetotal =
            image[i - 1][0].rgbtBlue + image[i - 1][1].rgbtBlue +
            image[i][0].rgbtBlue + image[i][1].rgbtBlue +
            image[i + 1][0].rgbtBlue + image[i + 1][1].rgbtBlue;

        int westredblur = (int) round(westredtotal / 6);
        int westgreenblur = (int) round(westgreentotal / 6);
        int westblueblur = (int) round(westbluetotal / 6);

        //give the new value to the West pixels
        image2[i][0].rgbtRed = westredblur;
        image2[i][0].rgbtGreen = westgreenblur;
        image2[i][0].rgbtBlue = westblueblur;
    }



    for (int i = 1; i < q - 1; i++)
    {
        float eastredtotal =
            image[i - 1][g - 2].rgbtRed + image[i - 1][g - 1].rgbtRed +
            image[i][g - 2].rgbtRed + image[i][g - 1].rgbtRed +
            image[i + 1][g - 2].rgbtRed + image[i + 1][g - 1].rgbtRed;

        float eastgreentotal =
            image[i - 1][g - 2].rgbtGreen + image[i - 1][g - 1].rgbtGreen +
            image[i][g - 2].rgbtGreen + image[i][g - 1].rgbtGreen +
            image[i + 1][g - 2].rgbtGreen + image[i + 1][g - 1].rgbtGreen;

        float eastbluetotal =
            image[i - 1][g - 2].rgbtBlue + image[i - 1][g - 1].rgbtBlue +
            image[i][g - 2].rgbtBlue + image[i][g - 1].rgbtBlue +
            image[i + 1][g - 2].rgbtBlue + image[i + 1][g - 1].rgbtBlue;

        int eastredblur = (int) round(eastredtotal / 6);
        int eastgreenblur = (int) round(eastgreentotal / 6);
        int eastblueblur = (int) round(eastbluetotal / 6);

        image2[i][g - 1].rgbtRed = eastredblur;
        image2[i][g - 1].rgbtGreen = eastgreenblur;
        image2[i][g - 1].rgbtBlue = eastblueblur;
    }


    float topleftredtotal =
        image[0][0].rgbtRed + image[0][1].rgbtRed +
        image[1][0].rgbtRed + image[1][1].rgbtRed;

    float topleftgreentotal =
        image[0][0].rgbtGreen + image[0][1].rgbtGreen +
        image[1][0].rgbtGreen + image[1][1].rgbtGreen;

    float topleftbluetotal =
        image[0][0].rgbtBlue + image[0][1].rgbtBlue +
        image[1][0].rgbtBlue + image[1][1].rgbtBlue;

    int topleftredblur = (int) round(topleftredtotal / 4);
    int topleftgreenblur = (int) round(topleftgreentotal / 4);
    int topleftblueblur = (int) round(topleftbluetotal / 4);

    image2[0][0].rgbtRed = topleftredblur;
    image2[0][0].rgbtGreen = topleftgreenblur;
    image2[0][0].rgbtBlue = topleftblueblur;


    float toprightredtotal =
        image[0][g - 2].rgbtRed + image[0][g - 1].rgbtRed +
        image[1][g - 2].rgbtRed + image[1][g - 1].rgbtRed;

    float toprightgreentotal =
        image[0][g - 2].rgbtGreen + image[0][g - 1].rgbtGreen +
        image[1][g - 2].rgbtGreen + image[1][g - 1].rgbtGreen;

    float toprightbluetotal =
        image[0][g - 2].rgbtBlue + image[0][g - 1].rgbtBlue +
        image[1][g - 2].rgbtBlue + image[1][g - 1].rgbtBlue;

    int toprightredblur = (int) round(toprightredtotal / 4);
    int toprightgreenblur = (int) round(toprightgreentotal / 4);
    int toprightblueblur = (int) round(toprightbluetotal / 4);

    image2[0][g - 1].rgbtRed = toprightredblur;
    image2[0][g - 1].rgbtGreen = toprightgreenblur;
    image2[0][g - 1].rgbtBlue = toprightblueblur;


    float bottomleftredtotal =
        image[q - 2][0].rgbtRed + image[q - 2][1].rgbtRed +
        image[q - 1][0].rgbtRed + image[q - 1][1].rgbtRed;

    float bottomleftgreentotal =
        image[q - 2][0].rgbtGreen + image[q - 2][1].rgbtGreen +
        image[q - 1][0].rgbtGreen + image[q - 1][1].rgbtGreen;

    float bottomleftbluetotal =
        image[q - 2][0].rgbtBlue + image[q - 2][1].rgbtBlue +
        image[q - 1][0].rgbtBlue + image[q - 1][1].rgbtBlue;

    //divide by 4 to get average and round
    int bottomleftredblur = (int) round(bottomleftredtotal / 4);
    int bottomleftgreenblur = (int) round(bottomleftgreentotal / 4);
    int bottomleftblueblur = (int) round(bottomleftbluetotal / 4);

    image2[q - 1][0].rgbtRed = bottomleftredblur;
    image2[q - 1][0].rgbtGreen = bottomleftgreenblur;
    image2[q - 1][0].rgbtBlue = bottomleftblueblur;



    //combine the red, green, and blue totals of the surrounding pixels
    float bottomrightredtotal =
        image[q - 2][g - 2].rgbtRed + image[q - 2][g - 1].rgbtRed +
        image[q - 1][g - 2].rgbtRed + image[q - 1][g - 1].rgbtRed;

    float bottomrightgreentotal =
        image[q - 2][g - 2].rgbtGreen + image[q - 2][g - 1].rgbtGreen +
        image[q - 1][g - 2].rgbtGreen + image[q - 1][g - 1].rgbtGreen;

    float bottomrightbluetotal =
        image[q - 2][g - 2].rgbtBlue + image[q - 2][g - 1].rgbtBlue +
        image[q - 1][g - 2].rgbtBlue + image[q - 1][g - 1].rgbtBlue;

    int bottomrightredblur = (int) round(bottomrightredtotal / 4);
    int bottomrightgreenblur = (int) round(bottomrightgreentotal / 4);
    int bottomrightblueblur = (int) round(bottomrightbluetotal / 4);

    image2[q - 1][g - 1].rgbtRed = bottomrightredblur;
    image2[q - 1][g - 1].rgbtGreen = bottomrightgreenblur;
    image2[q - 1][g - 1].rgbtBlue = bottomrightblueblur;


    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < g; j++)
        {
            //copy values from duplicate to original
            image[i][j] = image2[i][j];
        }
    }

    return;
}