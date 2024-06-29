#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int ch, count = 1;
  FILE *pt; // 文件指针
  // 判断是否输入文件
  if (argc != 3)
  {
    printf("%s", argv[0]);
    exit(1); // 非正常退出
  }
  // 判断能否成功打开文件
  if ((pt = fopen(argv[2], "r")) == NULL)
  { // 将argv[1]赋值给指针pt
    printf("%s", argv[2]);
    exit(1);
  }
  if (strcmp(argv[1], "-c") == 0)
  {
    count = 0;
    while ((ch = getc(pt)) != EOF)
    { // EOF 表示文件结束
      count++;
    }
    printf("%d\n", count);
  }
  else
  {
    while ((ch = getc(pt)) != EOF)
    {
      if ((ch == ' ') || (ch == ','))
        count++;
    }
    printf("%d\n", count);
  }
  fclose(pt);
  return 0;
}
