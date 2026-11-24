/* Smart Waste Collection and Segregation Simulator */
#include <stdio.h>

struct Waste {
    int location;     /* 1 to 4  */
    int type;         /* 1 to 6  */
    float quantity;   /* in kg   */
};

struct Waste records[100];
int count = 0;

char locations[5][15] = {"", "Market", "Hostel", "Hospital", "Canteen"};
char names[7][15]     = {"", "Organic", "Plastic", "Paper", "Metal", "Glass", "Hazardous"};
char bins[7][10]      = {"", "Green", "Blue", "White", "Grey", "Yellow", "Red"};

/* tells which type of waste goes in which bin */
void showAdvice(int type)
{
    switch (type)
    {
        case 1: printf("Put in GREEN bin (wet waste)\n");   break;
        case 2: printf("Put in BLUE bin (recyclable)\n");   break;
        case 3: printf("Put in WHITE bin (recyclable)\n");  break;
        case 4: printf("Put in GREY bin (recyclable)\n");   break;
        case 5: printf("Put in YELLOW bin (recyclable)\n"); break;
        case 6: printf("Put in RED bin (hazardous)\n");     break;
    }
}

void addRecord()
{
    int loc, type;
    float qty;

    printf("Location: 1.Market 2.Hostel 3.Hospital 4.Canteen : ");
    scanf("%d", &loc);
    printf("Type: 1.Organic 2.Plastic 3.Paper 4.Metal 5.Glass 6.Hazardous : ");
    scanf("%d", &type);
    printf("Quantity in kg: ");
    scanf("%f", &qty);

    if (loc < 1 || loc > 4 || type < 1 || type > 6 || qty <= 0)
    {
        printf("Wrong input! Record not saved.\n");
    }
    else
    {
        records[count].location = loc;
        records[count].type = type;
        records[count].quantity = qty;
        count++;
        printf("Record saved. ");
        showAdvice(type);
    }
}

void showRecords()
{
    int i;
    printf("\nNo  Location   Type       Kg      Bin\n");
    for (i = 0; i < count; i++)
    {
        printf("%-3d %-10s %-10s %-7.1f %s\n", i + 1,
               locations[records[i].location],
               names[records[i].type],
               records[i].quantity,
               bins[records[i].type]);
    }
}

void summary()
{
    float total[7] = {0, 0, 0, 0, 0, 0, 0};
    int entries[7] = {0, 0, 0, 0, 0, 0, 0};
    float grand = 0;
    int i, t;

    for (i = 0; i < count; i++)
    {
        total[records[i].type] = total[records[i].type] + records[i].quantity;
        entries[records[i].type]++;
        grand = grand + records[i].quantity;
    }

    printf("\n--- Segregation Summary ---\n");
    printf("Type       Bin    Entries  Total kg  Share\n");
    for (t = 1; t <= 6; t++)
    {
        printf("%-10s %-6s %-8d %-9.1f %.1f%%\n", names[t], bins[t],
               entries[t], total[t], total[t] * 100 / grand);
    }
    printf("Total waste = %.1f kg\n", grand);
}

void showPriority(int type, float qty)
{
    if (type == 6)
        printf("URGENT - special vehicle");
    else if (qty >= 100)
        printf("High - collect daily");
    else if (qty >= 50)
        printf("Medium - alternate days");
    else
        printf("Low - weekly");
}

void collectionPlan()
{
    int loc, t, i, trips;
    float sum, grand = 0;

    printf("\n--- Collection Plan ---\n");
    for (loc = 1; loc <= 4; loc++)
    {
        printf("\nLocation: %s\n", locations[loc]);
        for (t = 1; t <= 6; t++)
        {
            sum = 0;
            for (i = 0; i < count; i++)
            {
                if (records[i].location == loc && records[i].type == t)
                    sum = sum + records[i].quantity;
            }
            if (sum > 0)
            {
                printf("  %-10s %6.1f kg  [%s bin]  Priority: ", names[t], sum, bins[t]);
                showPriority(t, sum);
                printf("\n");
                grand = grand + sum;
            }
        }
    }

    // truck carries 500 kg at a time 
    trips = grand / 500;
    if (grand > trips * 500)
        trips++;
    printf("\nTotal %.1f kg, trips needed = %d\n", grand, trips);
}

void saveToFile()
{
    FILE *fp;
    int i;

    fp = fopen("waste_data.txt", "w");
    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s %.1f\n", locations[records[i].location],
                names[records[i].type], records[i].quantity);
    }
    fclose(fp);
    printf("Records saved in waste_data.txt\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== SMART WASTE SIMULATOR =====\n");
        printf("1. Add record\n2. Show records\n3. Segregation summary\n");
        printf("4. Collection plan\n5. Save to file\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addRecord();     break;
            case 2: showRecords();   break;
            case 3: summary();       break;
            case 4: collectionPlan(); break;
            case 5: saveToFile();    break;
            case 6: printf("Bye!\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
