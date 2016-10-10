
#include <stdio.h>
#include <stdlib.h>
#include <QString>
#include <QDebug>
#include <unistd.h>
#include <linux/stat.h>
#include <fcntl.h>
#include <sys/stat.h>



#define FIFO       "/tmp/fifo1"
//#define FIFOw       "/tmp/fifow"




int wrtre_in_fifo(char * t);
QString read_in_fifo();


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Используйте: fifoclient <команда аргумент>\n");
        exit(1);
    }

    wrtre_in_fifo(argv[1]); //Пишем команду



//    unlink(FIFOw);

//    if((mkfifo(FIFOw, O_RDWR)) == -1)

//    {
//        printf("Ошибка создания именого канала");
//        //return;

//    }




   // qDebug()<<read_in_fifo();//читаем ответ




    return(0);
}

int wrtre_in_fifo(char * t)
{
    FILE *fp;


    if ((fp = fopen(FIFO, "w")) == NULL)
    {
        perror("Ошибка открытия именованого канала");
        exit(1);
    }
    fputs(t, fp);
    fclose(fp);
    return 0;
}


//QString read_in_fifo()
//{
//    FILE *fp;
//    char buf[80];


//    fp = fopen(FIFOw, "r");

//    if(fp ==NULL)
//    {
//        return "err fopen";
//    }


//    if(fgets(buf, 80, fp) == NULL)
//    {
//        return "err fgets";
//    };

//    fclose(fp);


//    QString r (buf);
//    return r;
//}


