#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*
验证NuSMV中的文件读取算法
*/

int main(int argc, char** argv) {
    char* fileName = argv[1];
    printf("file is %s\n", fileName);
    FILE* cmd_file;
    cmd_file = fopen(fileName, "r");
    int op_count = 0;
    // op_count统计行数
    // ^取反的符号，表示读取到\n的符号就终止
    // while(EOF != (fscanf(cmd_file, "%*[^\n]"), fscanf(cmd_file, "%*c")))
    while(EOF != (fscanf(cmd_file, "%*[^\n]"))) {
        // 读取（任意的单个）下一个字符，即把换行符读取掉
        fscanf(cmd_file, "%*c");
        op_count++;
    }       
    printf("op_count = %d\n", op_count);

    fseek(cmd_file, 0, SEEK_SET);
    char** op_string = (char**)malloc(sizeof(char*) * op_count);
    char** op_name = (char**)malloc(sizeof(char*) * op_count);

    for(int i=0; i < op_count; i++) {
        char buf[256];
        char* op_real;
        char* rev_strip;
        if(!fgets(buf, 256, cmd_file))
            break;
        // 返回第一次出现"#"符号的位置，并赋值在op_real中
        
        op_real = strstr(buf, "#");
        printf("op_real: %s\n", op_real);
        if(!op_real)
            op_real = buf;
        else {
            // 去掉#字符，将#符号赋值为\0
            *op_real = '\0';
            ++op_real;
        }
        op_string[i] = (char*)malloc(sizeof(char) * 256);
        op_name[i] = (char*)malloc(sizeof(char) * 256);

        strncpy(op_string[i], op_real, 256);
        // 由于前面已经向buf中写入了\0表示的终结符，因此此时只会拷贝#前面的字符，也就是操作符的名称
        strncpy(op_name[i], buf, 256);
        rev_strip = op_string[i] + (strlen(op_string[i]) - 1);
        
        // 前面已经将op_string的指针赋给了rev_strip，此时对rev_strip操作也就是对op_string操作
        // 去掉op_string后面的换行符和空格
        while(isspace(*rev_strip)) {
            *(rev_strip--) = '\0';
        }
        printf("string: %s, name: %s, rev_strip: %s\n", op_string[i], op_name[i], rev_strip);
    }
    fclose(cmd_file);

    return 0;
}