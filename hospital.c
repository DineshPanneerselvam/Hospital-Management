#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct patient
{
    int id,amount,roomno,bedno,status;
    char name[25],record[100];
};
struct room
{
int idnumber;
int roomnumber;
int bednumber;
};
struct login
{
    char user[25],password[25];
};
struct drug
{
    int id,cost;
    char name[25];
};
struct bill
{
    int id,cost;
    char name[25];
};
void main()
{

    FILE *p,*q,*t,*danger;
    struct room r;
    struct drug dg,rg;
    struct login l,o;
    struct bill bi,bir;
    int x=0,temp,y,temproom[25][2],chx,i,j,chr,rt,bt,ti,ru,n,did[10],gg[10],ni;
    char temp1[25],user[25],password[25],name[25];
    char one[100],*c;
    struct patient add,f;
    int ch;

dinesh :
    system("cls");
    printf("\t\t\tHOSPITAL MANAGEMENT\n\n");
    printf("\n1.LOGIN\n\n2.SIGNUP\n\n\nEnter Your Choice:");
    scanf("%d",&ti);
    if(ti==2)
    {
        printf("\nEnter The Department Number:");
        scanf("%d",&ru);
        if(ru==999)
        {
            printf("\nEnter The Username:");
            scanf("%s",&l.user);
            printf("\nEnter The Password:");
            scanf("%s",&l.password);
            danger = fopen("login.dat","a+");
            fwrite(&l,sizeof(l),1,danger);
            fclose(danger);

        }
        if(ru==555)
        {
            printf("\nEnter The Username:");
            scanf("%s",&l.user);
            printf("\nEnter The Password:");
            scanf("%s",&l.password);
            danger = fopen("pharma.dat","a+");
            fwrite(&l,sizeof(l),1,danger);
            fclose(danger);

        }
        goto dinesh;
    }
    if(ti==1)
    {
            printf("\nEnter The Username:");
            scanf("%s",&l.user);
            printf("\nEnter The Password:");
            scanf("%s",&l.password);
            danger = fopen("login.dat","rb");
            while(feof(danger)== NULL){
                fread(&o,sizeof(o),1,danger);
                if(strcmp(l.password,o.password)==0&&strcmp(l.user,o.user)==0)
                {
                    fclose(danger);
                    goto dd;
                }
            }
            fclose(danger);
            danger = fopen("pharma.dat","rb");
            while(feof(danger)== NULL){
                fread(&o,sizeof(o),1,danger);
                if(strcmp(l.password,o.password)==0&&strcmp(l.user,o.user)==0)
                {
                    fclose(danger);
                    goto pharma;
                }
            }
            fclose(danger);
            goto dinesh;



    }

dd:
    while(1)
    {
        system("cls");
        printf("\n\t\t\tHOSPITAL MANAGEMENT\n\n");
        printf("1.ADD PATIENT\n2.REMOVE PATIENT\n3.PAY AMOUNT\n4.PATIENT DETAILS\n5.ROOM DERAILS\n6.MODIFICATION\n7.RETURN");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            q = fopen("room.dat","rb");
            fread(&r,sizeof(r),1,q);
            fclose(q);
            //printf("\n\n\n\%d   %d   %d\n\n\n",r.idnumber,r.bednumber,r.roomnumber);
            p=fopen("record.dat","a+");
            printf("\n1.Enter The Name:");
            scanf("%s",&add.name);
            printf("\n2.Enter The Record Of The patient:");
            scanf("%s",&add.record);
            r.idnumber++;
            add.id=r.idnumber;
            r.bednumber++;
            if(r.bednumber==4){
                r.bednumber=1;
                r.roomnumber+=1;
            }
            add.roomno= r.roomnumber;
            add.bedno= r.bednumber;
            add.status=0;
          //  printf("\n\n\n\%d   %d   %d\n\n\n",r.idnumber,r.bednumber,r.roomnumber);
            //printf("\n\n\n\%d   %d   %d\n\n\n",add.id,add.bedno,add.roomno);
            printf("\n3.Enter The Amount:");
            scanf("%d",&add.amount);
          /*  add.id=1;
            add.roomno= 1;
            add.bedno= 1; */
            fwrite(&add,sizeof(add),1,p);
            fclose(p);
            r.idnumber=add.id;
            r.roomnumber=add.roomno;
            r.bednumber=add.bedno;
            q = fopen("room.dat","wb");
            fwrite(&r,sizeof(r),1,q);
            fclose(q);
            system("cls");
            printf("\n\n\n\n\n\t\t\tADDED SUCESSFULLY");
            getch();
            break;
        case 2:
                printf("Enter The ID Number:");
                scanf("%d",&temp);
                printf("\nEnter The Patient Name:");
                scanf("%s",&temp1);
                p= fopen("record.dat","rb");
                t = fopen("temp.dat","wb");
                while(feof(p)== NULL){
                    fread(&f,sizeof(f),1,p);
                    if(f.id!=temp && strcmp(temp1,f.name)!=0)
                    {
                        fwrite(&f,sizeof(f),1,t);
                    }
                }
                fclose(p);
                fclose(t);
                remove("record.dat");
                rename("temp.dat","record.dat");
                system("cls");
                printf("\n\n\n\n\n\t\t\tREMOVED SUCESSFULLY");
                getch();
                break;
        case 3:
                printf("Enter The ID Number:");
                scanf("%d",&temp);
                printf("\nEnter The Patient Name:");
                scanf("%s",temp1);
                printf("Does The Payment Is Done Press 0...........\n");
                scanf("%d",&y);
                if(y==0)
            {
                p= fopen("record.dat","rb");
                t = fopen("temp.dat","wb");
                while(feof(p)== NULL){
                    fread(&f,sizeof(f),1,p);
                    if(f.id!=temp&&strcmp(temp1,f.name)!=0)
                    {
                        fwrite(&f,sizeof(f),1,t);
                    }
                    else
                    {
                        f.status = 1;
                        fwrite(&f,sizeof(f),1,t);
                    }
                }
                fclose(p);
                fclose(t);
                remove("record.dat");
                rename("temp.dat","record.dat");
                system("cls");
                printf("\n\n\n\n\n\t\t\tPAID SUCESSFULLY");
                getch();
                break;
            }

        case 4:
            printf("\nID\tNAME\tRECORD\tAMOUNT\tROOMNO\tBEDNO\tSTATUS:");
            p=fopen("record.dat","rb");
            x=0;
            while(feof(p)== NULL)
            {
                fread(&f,sizeof(f),1,p);
                if(f.id!=x)
                {
                    printf("\n%d\t%s\t%s\t%d\t%d\t%d\t",f.id,f.name,f.record,f.amount,f.roomno,f.bedno,f.status);
                    if(f.status==0)
                        printf("NOT PAID");
                    else if(f.status==1)
                        printf("SUCCESS");
                    x=f.id;
                }
            }
            fclose(p);
            getch();
            break;

        case 5:
            printf("\nROOMNO\tBEDNO\tSTATUS");
            p=fopen("record.dat","rb");
            x=0;i=0;
            while(feof(p)== NULL)
            {
                fread(&f,sizeof(f),1,p);
                if(f.id!=x)
                {
                    temproom[i][0]=f.roomno;
                    temproom[i][1]=f.bedno;
                    i++;
                    x=f.id;
                }
            }
                   temproom[i][0]=55555;
                    temproom[i][1]=55555;
            fclose(p);
            for(i=1;i<=10;i++)
            {
                for(j=1;j<=3;j++)
                {
                    printf("\n%d\t%d\t",i,j);
                    chx=0;chr=0;
                    while(temproom[chx][0]!=55555&&temproom[chx][1]!=55555)
                    {
                        if(temproom[chx][0]==i&&temproom[chx][j]==j)
                            chr=5;
                        chx++;
                    }
                    if(chr!=5)
                        printf("FREE");
                    else
                        printf("OCCUPIED");

                }
            }
            getch();
            break;
        case 6:
                printf("Enter The ID Number:");
                scanf("%d",&temp);
                printf("\nEnter The Patient Name:");
                scanf("%s",temp1);
                printf("\nEnter The Valid Roomno:");
                scanf("%d",&rt);
                printf("\nEnter The Valid Bedno:");
                scanf("%d",&bt);
                p= fopen("record.dat","rb");
                t = fopen("temp.dat","wb");
                while(feof(p)== NULL){
                    fread(&f,sizeof(f),1,p);
                    if(f.id!=temp&&strcmp(temp1,f.name)!=0)
                    {
                        fwrite(&f,sizeof(f),1,t);
                    }
                    else
                    {
                        f.roomno=rt;
                        f.bedno=bt;
                        fwrite(&f,sizeof(f),1,t);
                    }
                }
                fclose(p);
                fclose(t);
                remove("record.dat");
                rename("temp.dat","record.dat");
                system("cls");
                printf("\n\n\n\n\n\t\t\tMOVED SUCESSFULLY");
                getch();
                break;

        case 7:
            return;

        }
    /*
        r.idnumber=1;
        r.bednumber=1;
        r.roomnumber=1;
    */

    }
pharma:
    while(1)
    {
        system("cls");
        printf("\n\t\t\tHOSPITAL MANAGEMENT\n\n\t\t\tPHARMA DEPARTMENT\n\n1.ADD BILL\n2.BILL DETAILS\n3.ADD DRUGS\n4.DRUGS DETAILS\n5.CANCEL BILL\n6.RETURN\n\nEnter Your Choice:");
        scanf("%d",&ti);
        switch(ti)
        {
        case 1:
            bi.cost=0;
            printf("Enter The Patient Name:");
            scanf("%s",&bi.name);
            printf("\nEnter The Number Of Drugs:");
            scanf("%d",&ni);
            p=fopen("bill.dat","rb");
            while(!feof(p))
            {
                fread(&bir,sizeof(bir),1,p);
                bi.id=bir.id;
            }
            bi.id++;
            i=0;
            while(i<ni)
            {
            printf("\nEnter The Drug ID:");
            scanf("%d",&did[i]);
            printf("\nEnter The Quantity:");
            scanf("%d",&gg[i]);
            i++;
            }
            i=0;
            while(i<ni)
            {
            p=fopen("drug.dat","rb");
            x=0;
            while(feof(p)== NULL)
            {
                fread(&rg,sizeof(rg),1,p);
                if(rg.id==did[i])
                {
                    x=rg.cost;

                }
            }
            fclose(p);
            bi.cost+=(x*gg[i]);
            i++;
            }
            p= fopen("bill.dat","a+");
            fwrite(&bi,sizeof(bi),1,p);
            fclose(p);
            system("cls");
            printf("\n\n\n\n\n\t\t\tADD SUCESSFULLY");
            getch();
            break;
        case 4:
            printf("\nDRUG ID\tDRUG NAME\tCOST\n\n");
            p=fopen("drug.dat","rb");
            x=0;
            while(feof(p)== NULL)
            {
                fread(&rg,sizeof(rg),1,p);
                if(rg.id!=x)
                {
                    printf("\n%d\t%s\t\t%d",rg.id,rg.name,rg.cost);
                    x=rg.id;
                }
            }
            fclose(p);getch();
            break;

        case 3:
            printf("\nEnter The Drug Name:");
            scanf("%s",&dg.name);
            printf("\nEnter The Cost:");
            scanf("%d",&dg.cost);
            danger=fopen("drug.dat","rb");
            while(!feof(danger))
            {
                fread(&rg,sizeof(rg),1,danger);
                dg.id=rg.id;
            }
            dg.id++;
            fclose(danger);
            danger=fopen("drug.dat","a+");
            fwrite(&dg,sizeof(dg),1,danger);
            fclose(danger);
            system("cls");
            printf("\n\n\n\n\n\t\t\tADD SUCESSFULLY");
            getch();
            break;
        case 2:
            printf("\nBILL ID\tPATIENT NAME\tCOST");
            p = fopen("bill.dat","rb");
            x=0;
            while(!feof(p))
            {
                fread(&bi,sizeof(bi),1,p);
                if(bi.id!=x)
                    printf("\n%d\t%s\t\t%d",bi.id,bi.name,bi.cost);
                x=bi.id;
            }
            fclose(p);
            getch();
            break;
        case 5:
                printf("Enter The BILL ID:");
                scanf("%d",&temp);
                printf("\nEnter The Patient Name:");
                scanf("%s",&temp1);
                p= fopen("bill.dat","rb");
                t = fopen("temp1.dat","wb");
                while(feof(p)== NULL){
                    fread(&bir,sizeof(bir),1,p);
                    if(bir.id!=temp&&strcmp(temp1,bir.name)!=0)
                    {
                        fwrite(&bir,sizeof(bir),1,t);
                    }

                }
                fclose(p);
                fclose(t);
                system("cls");
                printf("\n\n\n\n\n\t\t\tREMOVED SUCESSFULLY");
                getch();
                remove("bill.dat");
                rename("temp1.dat","bill.dat");
                break;
        case 6:
            return;

        }
    }


}


