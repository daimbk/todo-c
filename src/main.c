int main()
{
    int exit = 0;

    while (!exit)
    {
        print("Welcome to To Do List!\n");

        print("Enter command: \n");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0)
        {
            exit = 1;
        }
    }

    return 0;
}
