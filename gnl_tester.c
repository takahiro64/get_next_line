#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// get_next_line関数の宣言
char *get_next_line(int fd);

void test_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    printf("Testing file: %s\n", filename);
    char *line;
    int line_count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", ++line_count, line);
        free(line);
    }
    printf("Total lines read: %d\n\n", line_count);

    close(fd);
}

void test_stdin()
{
    printf("Testing stdin (type 'exit' to finish):\n");
    char *line;
    int line_count = 0;
    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        printf("Line %d: %s", ++line_count, line);
        if (strcmp(line, "exit\n") == 0)
        {
            free(line);
            break;
        }
        free(line);
    }
    printf("Total lines read: %d\n\n", line_count);
}

void test_empty_file()
{
    int fd = open("empty.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    close(fd);

    printf("Testing empty file:\n");
    test_file("empty.txt");
}

void test_large_file()
{
    int fd = open("large.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    for (int i = 0; i < 10000; i++)
    {
        dprintf(fd, "This is line %d\n", i + 1);
    }
    close(fd);

    printf("Testing large file:\n");
    test_file("large.txt");
}

int main()
{
    printf("Testing start\n");
    // テストケース1: 通常のファイル
    test_file("test.txt");

    // テストケース2: 標準入力
    test_stdin();

    // テストケース3: 空のファイル
    test_empty_file();

    // テストケース4: 大きなファイル
    test_large_file();

    // テストケース5: 無効なファイルディスクリプタ
    printf("Testing invalid file descriptor:\n");
    char *line = get_next_line(-1);
    if (line == NULL)
        printf("Correctly returned NULL for invalid fd\n\n");
    else
    {
        printf("Error: did not return NULL for invalid fd\n\n");
        free(line);
    }

    return 0;
}
