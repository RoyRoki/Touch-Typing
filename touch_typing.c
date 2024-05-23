#include <stdio.h>
#include <string.h>
#include <time.h>

void rating(int n, double t) {
  int rank = ((n*7)/1000)+(int)(240/t); // considering best=100% with 90WPS  Rank=70% of Accu+30% of WPS
switch(rank) {
    case 0:
        printf("\n10.Typing Novice\n");
        break;
    case 1:
        printf("\n9.Typing Apprentice\n");
        break;
    case 2:
        printf("\n8.Typing Journeyman\n");
        break;
    case 3:
        printf("\n7.Typing Expert\n");
        break;
    case 4:
        printf("\n6.Typing Professional\n");
        break;
    case 5:
        printf("\n5.Typing Master\n");
        break;
    case 6:
        printf("\n4.Typing Grandmaster\n");
        break;
    case 7:
        printf("\n3.Typing Virtuoso\n");
        break;
    case 8:
        printf("\n2.Typing Prodigy\n");
        break;
    case 9:
        printf("\n1.Typing Legend\n");
        break;
    default:
        printf("\n0.Out Of Rank\n");
        break;
}

}
void start(FILE *Row) {
  printf("\n\n");

  int point[10];
  double Time[10];
  char text[500];

     fgets(text, 500, Row);
            for (int i = 1; i <= 10; i++) {
                clock_t start_time = clock();
                printf("\n\n*******</ LEVEL %d />********\n\n",i);
                char textin[50];
                char textout[50];

                memset(textin, 0, sizeof(textin));
                memset(textout, 0, sizeof(textout));

                for (int p = (i - 1) * 50, j = 0; j < 50; p++, j++) {
                    if (text[p] == '\0' || text[p] == '\n') {
                        break;
                    }
                    printf("%c", text[p]);
                    textout[j] = text[p];
                }

                printf("\n\nStart Typing:\n\n");

                int p = 0;
                while (p < 50) {
                    char ch = getchar();
                    if (ch != '\n') {
                        textin[p] = ch;
                        p++;
                    }
                }

                int score = 0;
                for (int i = 0; i < 50; i++) {
                    if (textin[i] == textout[i]) {
                        score++;
                    }
                }
                point[i-1]=score*2;
                clock_t end_time = clock();
                double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                Time[i-1] = duration;
                printf("\n                                         >Your Accuracy = %d \n", score*2);
                printf("                                         >Word Per Minute = %.2f\n",(60*9)/duration);
                printf("                                         >Your Time = %.2f \n", duration);

                printf("Press Enter +level..");
                char c=getchar();
                while (c=getchar()!= '\n') {}
            }
            printf("\n*****congratulation****\n");
            int Total=0;
            double take=0.0;
            printf("[ ");
            for(int i = 0; i<10; i++) {
              Total=Total + point[i];
              take=take + Time[i];
              printf("{%d(%0.2f)}",point[i],Time[i]);
              if(i!=9) printf(", ");
            }
            printf(" ]\n*******Your Rank*******");
            rating(Total,take);
            printf("\nOverAll Word Per Minute = %0.2f",(60*90)/take);
            printf("\nYour Total Time : %0.2f\nOverAll Accuracy :%d\n",take,Total/10);
            printf("\nThankyou-> creator -> Roki Roy");
}


int main() {
    FILE *Row;

    printf("\n\n*******Welcome To Touch-Typing******\nEnter : \n\n");
    printf(" 1 For UpperRow\n 2 For MiddleRow\n 3 For LowerRow \n 12, 23, 13 For Combine Rows\n 123 For AllRows\n 7 For Master Mode\n\n Mode = ");

    int mode;
    scanf("%d", &mode);
    getchar();

    switch (mode) {
        case 1:printf("***** UP ROW ******");
            Row = fopen("upRow.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;

        case 2:printf("***** MID ROW ******");
           Row = fopen("midRow.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;

        case 3:printf("***** LOW ROW ******");
            Row = fopen("lowRow.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;

        case 12:printf("***** UP+MID ROW ******");
             Row = fopen("upmidRow.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;

        case 23:printf("***** MID+LOW ROW ******");
            Row = fopen("midlowRow.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;
         case 13:printf("***** UP+LOW ROW ******");
            Row = fopen("uplowRow.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;
 
        case 123:printf("****</ ALL ROW />*****");
            Row = fopen("allRow.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;
        default:
        printf("****</ MASTER MODE />*****");
            Row = fopen("master.txt", "r");
            if (Row == NULL) {
             printf("Error opening file(s).\n");
             return 1;
           }
           start(Row);
           
            break;
            
    }

    fclose(Row);
    return 0;
}
