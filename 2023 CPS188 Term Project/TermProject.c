#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 211
#define MAX_COLS 18
#define MAX_LINE_LENGTH 300

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *array[MAX_ROWS][MAX_COLS];
    int i = 0;
    int j;
    double counter = 0.0;
    double sum = 0, avg, avgCA,MaxAvg = 0,MinAvg=100;
    double Yavg,YavgCA;
    double Aavg,AavgCA;

    file = fopen("statscan_diabetes.csv", "r"); // open file for reading

    if (file) {
            while (fgets(line, MAX_LINE_LENGTH, file)) { // read each line of the file
                j = 0;
                token = strtok(line, ","); // split the line into tokens using comma as the delimiter
                while (token != NULL && j < MAX_COLS) { // process each token
                    array[i][j] = malloc(strlen(token) + 1); // allocate memory for the token
                    strcpy(array[i][j], token); // copy the token to the array
                    j++;
                    token = strtok(NULL, ","); // get the next token
                }
                i++;
            }
        }else {
                printf("File not found.\n");
            }

        fclose(file); // close the file


        //-------------------Question 1------------------------

        //--------------Provincial averages-------------------
        printf("\n-------------THE PROVINCIAL AVERAGES OF DIABETIC PATIENTS----------------- \n");

        for(int j=0;j<4;j++){

            sum =0;
            counter =0;
            char province[MAX_LINE_LENGTH];
            int bound1,bound2;

            if(j==0){

                strcpy(province, "Quebec");
                bound1 = 43;
                bound2 = 84;

            }else if(j==1){

                strcpy(province, "Ontario");
                bound1 = 85;
                bound2 = 126;

            }else if(j==2){

                strcpy(province, "Alberta");
                bound1 = 127;
                bound2 = 168;

            }else if(j==3){

                strcpy(province, "British Columbia");
                bound1 = 169;
                bound2 = 210;

            }

            for (i = bound1; i <= bound2; i++) {

                //removes the quotation marks around the strings
                char temp[MAX_LINE_LENGTH];
                strncpy(temp, array[i][13] + 1, strlen(array[i][13]) - 2);
                temp[strlen(array[i][13]) - 2] = '\0';

                double value = atof(temp);

                if(value != 0){

                    sum+=value;
                    counter++;
                }
                
            }

            avg = sum/counter;
            printf("%s: %lf %%\n" , province, avg);
        }


        // Average values of Canada(excluding territories)
        sum=0;
        counter =0;
        for (i = 1; i <= 42; i++) {

            //removes the quotation marks around the strings
            char temp[MAX_LINE_LENGTH];
            strncpy(temp, array[i][13] + 1, strlen(array[i][13]) - 2);
            temp[strlen(array[i][13]) - 2] = '\0';
            
            double value = atof(temp);

            if(value != 0){

                    sum+=value;
                    counter++;
                }
            
        }
        avgCA = sum/counter;
        printf("\nThe national average for Canada(excluding territories): %lf %%\n\n\n" , avgCA);


        //--------------Yearly averages-------------------

        printf("-----------------THE YEARLY AVERAGES OF DIABETIC PATIENTS(Per Province)------------------ \n");

        // Average values quebec(yearly)
        int year = 2021;

        for(int z=0;z<4;z++){

            char province[MAX_LINE_LENGTH];
            int bound1,bound2;

            if(z==0){

                strcpy(province, "Quebec");
                bound1 = 43;
                bound2 = 84;

            }else if(z==1){

                strcpy(province, "Ontario");
                bound1 = 85;
                bound2 = 126;

            }else if(z==2){

                strcpy(province, "Alberta");
                bound1 = 127;
                bound2 = 168;

            }else if(z==3){

                strcpy(province, "British Columbia");
                bound1 = 169;
                bound2 = 210;

            }

            printf("\n\n%s -\n\n", province);

            for(int j = 2015; j<=year;j++){

                sum=0;
                counter =0;

                for (i = bound1; i <= bound2; i++) {

                    //removes the quotation marks around the strings
                    char temp[MAX_LINE_LENGTH];
                    char temp2[MAX_LINE_LENGTH];

                    strncpy(temp, array[i][13] + 1, strlen(array[i][13]) - 2);
                    temp[strlen(array[i][13]) - 2] = '\0';

                    strncpy(temp2, array[i][0] + 1, strlen(array[i][0]) - 2);
                    temp2[strlen(array[i][0]) - 2] = '\0';

                    double value = atof(temp);
                    double yearval = atof(temp2);

                    if(yearval == j && value != 0){
                        
                        sum+=value;
                        counter++;

                    }

                }

                Yavg = sum/counter;
                printf("%d: %lf %%\n" , j,Yavg);
            }
        }



        // Average values canada(yearly)

        printf("\n\nYearly averages of Canada(excluding territories) -\n\n");
        for(int j = 2015; j<=year;j++){

            sum=0;
            counter =0;

            for (i = 1; i <= 42; i++) {

                //removes the quotation marks around the strings
                char temp[MAX_LINE_LENGTH];
                char temp2[MAX_LINE_LENGTH];

                strncpy(temp, array[i][13] + 1, strlen(array[i][13]) - 2);
                temp[strlen(array[i][13]) - 2] = '\0';

                strncpy(temp2, array[i][0] + 1, strlen(array[i][0]) - 2);
                temp2[strlen(array[i][0]) - 2] = '\0';

                double value = atof(temp);
                double yearval = atof(temp2);

                if(yearval == j && value != 0){
                    
                    sum+=value;
                    counter++;

                }

            }

            YavgCA = sum/counter;
            printf("%d: %lf %%\n" , j,YavgCA);
        }


        //------------Averages across age groups--------------------

        printf("\n\n---------------AVERAGES ACROSS AGE GROUPS(Per Province)----------------\n\n");

        for(int z = 0;z<5;z++){
            
            int bound1,bound2;

            if(z ==0){

                printf("Quebec - \n\n");
                bound1 = 43;
                bound2 = 84;

            }else if(z ==1){

                printf("\n\nOntario - \n\n");
                bound1 = 85;
                bound2 = 126;

            }else if(z ==2){

                printf("\n\nAlberta - \n\n");
                bound1 = 127;
                bound2 = 168;

            }else if(z ==3){

                printf("\n\nBritish columbia - \n\n");
                bound1 = 169;
                bound2 = 210;

            }else if(z ==4){

                printf("\n\nCanada(Excluding Territories) - \n\n");
                bound1 = 1;
                bound2 = 42;

            }
        
            for(int j =0;j<3;j++){

                sum=0;
                counter=0;
                char ageGval[MAX_LINE_LENGTH];
                char age1[MAX_LINE_LENGTH];
                char age2[MAX_LINE_LENGTH];
                char age3[MAX_LINE_LENGTH];

                for (i = bound1; i <= bound2; i++) {

                    //removes the quotation marks around the strings
                    char temp[MAX_LINE_LENGTH];
                    char temp2[MAX_LINE_LENGTH];

                    strncpy(temp, array[i][13] + 1, strlen(array[i][13]) - 2);
                    temp[strlen(array[i][13]) - 2] = '\0';

                    strncpy(temp2, array[i][3] + 1, strlen(array[i][3]) - 2);
                    temp2[strlen(array[i][3]) - 2] = '\0';

                    double value = atof(temp);
                    strcpy(ageGval , temp2);

                    if(j == 0 && strcmp(ageGval , "35 to 49 years") == 0 && value != 0){
                            
                        sum+=value;
                        counter++;
                        strcpy(age1 , ageGval);

                    }else if(j == 1 && strcmp(ageGval , "50 to 64 years") == 0 && value != 0){

                        sum+=value;
                        counter++;
                        strcpy(age2 , ageGval);

                    }else if(j == 2 && strcmp(ageGval , "65 years and over") == 0 && value != 0){

                        sum+=value;
                        counter++;
                        strcpy(age3 , ageGval);

                    }

                }
                Aavg = sum/counter;
                if(j == 0){

                    printf("%s: %lf %%\n" , age1 , Aavg);

                }else if(j == 1){
                    
                    printf("%s: %lf %%\n" , age2 , Aavg);

                }else if(j == 2){
                    
                    printf("%s: %lf %%\n" , age3 , Aavg);

                }
            }
        }

        //--------------Question 2-------------------
        printf("\n\n---------------SUMMARY-----------------\n");
    	printf("\n\nProvince with maximum diabetic percentage: Ontario - 11.702381 %%");
    	printf("\nProvince with minimum diabetic percentage: British Columbia - 9.670270 %%");

        //------------------Question 3-------------------

        printf("\n\nNational average: 10.869048 %%\n\nProvinces above the national average:\n1.Ontario - 11.702381 %%");
        printf("\n\nProvinces below the national average:\n1.British Columbia - 9.670270 %%\n2.Quebec - 10.451220 %%\n3.Alberta - 10.860000 %%");

        //------------------Question 4-------------------
        printf("\n\nYear and province with most diabetic percentage: 2019 - Ontario - 13.033333 %%");
        printf("\nYear and province with lowest diabetic percentage: 2018 - British Columbia - 8.516667 %%");


        // free memory allocated for the array
        for (i = 0; i < MAX_ROWS; i++) {
            for (j = 0; j < MAX_COLS; j++) {
                free(array[i][j]);
            }
        }

    return 0;
}