// Banker's Algorithm  
#include <stdio.h>  
int main()  
{  
    int jobs, 
    resources, 
    i, // outer loop variable
    j, // inner loop variable
    k; // temporary outer loop variable 
    int alloc[jobs][resources];  //Resources allocation per Job
    int max[jobs][resources]; // maximum resource allocation per job
    int avail[resources]; // Current Available resources

    printf("Enter number of Jobs: ");
    scanf("%d", &jobs);

    printf("Enter number of Resources: ");
    scanf("%d", &resources);

    printf("Enter number of Available Resources: ");
    scanf("%d", &avail[resources]);

    printf("Enter Allocation per Job \n");
    for (i=0;i<jobs;i++)
    {
        printf("Enter Job-%d: ",i);
        for (j=0;j<resources;j++)
        {
            printf("",i,j);
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter Maximum Allocation per Job \n");
    for (i=0;i<jobs;i++)
    {
        printf("Enter max for P%d: ",i);
        for (j=0;j<resources;j++)
        {
            printf("",i,j);
            scanf("%d",&max[i][j]);
        }
    }


    int f[jobs], // finish array if all jobs are checked
    ans[resources], //array for storing and printing Job sequence if safe
    ind = 0;  //array ans indexing if job is safe and done processing
    for (k = 0; k < jobs; k++)  
    {  
        f[k] = 0;  
    }

    int need[jobs][resources]; // array Job resources need variable 
    for (i = 0; i < jobs; i++)  
    {  
        for (j = 0; j < resources; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    } 

    int y = 0;  // indexing for new rasource available
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < jobs; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  //bolean variable 
                for (j = 0; j < resources; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < resources; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }
  
    int flag = 1;  
    for (int i = 0; i < jobs; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < jobs - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[jobs - 1]);  
    }  
    return (0);  
} 
