#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

#define MAXSIZE 1024
int main()
{
    char buf[MAXSIZE] = {0};
    FILE *fp = fopen("./dict.txt", "r");
    if (NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    sqlite3 *db = NULL;
    int ret = sqlite3_open("./dict.db", &db);
    if (0 > ret)
    {
        fprintf(stderr, "sqlite3_open:%s\n", sqlite3_errmsg(db));
        fclose(fp);
        return -1;
    }
    char cmd[MAXSIZE] = {0};
    while(0 == feof(fp))
    {
        memset(buf, 0 ,sizeof(buf));
        if (NULL == fgets(buf, sizeof(buf), fp))
            break;
        char *p = buf;
        char *token = NULL;
        token = strsep(&p, " ");
        while(*p == ' ')
            p++;
        memset(cmd, 0, sizeof(cmd));
        sprintf(cmd, "insert into dict values('%s', '%s');", token, p);
        char *errmsg = NULL;
        ret = sqlite3_exec(db, cmd, NULL, NULL, &errmsg);
        if (0 != ret)
        {
            fprintf(stderr, "sqlite3_open:%s\n", sqlite3_errmsg(db));
            goto ERR;
        }
    }

    ERR:
    fclose(fp);
    sqlite3_close(db);
    return ret;
}
