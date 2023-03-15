#include<stdio.h>
void access();
void addition();
void main()
{
	int choice;
	while(1)
	{
		printf("Enter your choice\n1.addition\n2.access\n3.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				addition();
				break;
			case 2:
				access();
				break;
			case 3:
				exit(0);
			default:
				printf("Enter proper choice");
		}
	}
}
void addition()
{	
	FILE* fp = fopen("file_path", "a+");
	char name[50];
	int accountno[50];

	if (!fp) {
		// Error in file opening
		printf("Can't open file\n");
		return 0;
	}

	// Asking user input for the
	// new record to be added
	printf("\nEnter username\n");
	scanf("%s", &name);
	printf("\nEnter Password\n");
	scanf("%s", &accountno);

	// Saving data in file
	fprintf(fp, "%s, %s\n", name,accountno);

	printf("\nNew Account added to record");
	fclose(fp);
}
void access()
{
	FILE* fp = fopen("file_path", "r");

	if (!fp)
		printf("Can't open file\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer,1024, fp)) 
		{
			column = 0;
			// Splitting the data
			char* value = strtok(buffer, ", ");

			while (value) {
				// Column 1
				if (column == 0) {
					printf("Username:");
				}

				// Column 2
				if (column == 1) {
					printf("\tPassword: ");
				}

				printf("%s", value);
				value = strtok(NULL, ", ");
				column++;
			}
			row++;
			printf("\n");
		}

		// Close the file
		fclose(fp);
	}
}


